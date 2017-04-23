
#define _USE_MATH_DEFINES
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "States.h"
#include "Cylinders.h"
#include <boost/numeric/odeint.hpp>
#include <boost/array.hpp>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace boost::numeric::odeint;

Cylinder cylinderProps;

// Heat transfer
//1) Convective heat transfer
double convective_ht(double theta, double T) //Piston temp (T)
{
	double b = 99.5/1000; //bore (m)
	double l = 131.5/1000; //Rod Length (m)
	double L = 79.0/1000; //Stroke length (m)
	double r = L - l; //crank radius
	double y; //cylinder wall height
	double A; //Area

	y = r + l - (pow(l*l - r*r * sin(M_PI*theta / 180)*sin(M_PI*theta / 180), 1 / 2) + r * cos(theta));
	A = (M_PI * b * y) + (M_PI / 2 * b * b);

	double Re, Nu, h_Nu;
	double k = 0.0663; //Thermal conductivity of the working fluid
	double rho = 1.82; //Fluid density
	double U = 2*L*cylinderProps.N/60; //Characteristic Velocity (Mean piston speed)
	double mu = 0.0001795; // Dynamic Viscosity of the mixture

	Re = rho * U * L / mu;
	Nu = 10.4 * pow(Re, 0.75);
	h_Nu = k * Nu / L;
	//double T; //Using T2 as mean temp of piston wall temperature
	//double N; // Engine speed
	double T_inf = 23; //Assuming standard room temperature for the sake of calculation

	double dqdtheta = h_Nu * A * (T - T_inf) / cylinderProps.N; //N in rads/s not rpm

	return dqdtheta;
}

//2) Cumulative Heat Release using Weibe function

double xb(double theta, double theta_s, double theta_d, double a, double n)
{
	double xb = 1 - exp(-a * pow(((theta - theta_s) / theta_d), n));
	return xb;
}

double Wiebe(double theta)
{
	double Q_hv = 473000000; //Heating value of fuel (J)
	double n = 3; // Form Factor
	double a = 5; // Efficiency Factor
	double theta_s = -20; // Start of heat release (in degrees) with TDC as 0
	double theta_d = 40; //End of heat release (values found in textbook)
	double Xb = xb(theta, theta_s,theta_d,a,n);

	double dXb_dTheta = n * a * (1 - Xb) * pow(((theta - theta_s) / theta_d), n - 1);
	double dQ_dTheta = Q_hv * dXb_dTheta;

	return dQ_dTheta;
}

double compressiveHeat(double theta)
{
	double R = 2*131.5/79; //2*ConRodL/stroke

	double dV_dTheta = sin(theta*M_PI / 180)*(1 + cos(theta*M_PI / 180) / (sqrt((R*R) - (sin(theta*M_PI / 180)*sin(theta*M_PI / 180)))));

	return dV_dTheta;
}

void rhs2(const double p, double &dpdtheta, const double theta) // 1.35 is the index in this scenario REMEMBER TO CHANGE THIS IF YOU CHANGE THE INDEX
{
	dpdtheta = Wiebe(theta)*(1.234-1)/2.73 - compressiveHeat(theta)*p*1.234/2.73 - convective_ht(theta,514.187);

}

void write_cout2(const double &p, const double theta)
{
	cout << theta << '\t' << p << endl;
}

// state_type = double
typedef runge_kutta_dopri5< double > stepper_type;

double firstLawIntegration(double p, double theta_s, double theta_d) //original step size of 0.1
{
	// double p = 100000.0;
	integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()), rhs2, p, theta_s, theta_d, 0.1, write_cout2);
	return p;
}