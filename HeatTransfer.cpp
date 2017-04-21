#define _USE_MATH_DEFINES
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include "States.h"
#include "Cylinders.h"
#include <boost/numeric/odeint.hpp>

using namespace boost::numeric::odeint;

// Heat transfer

/*
For convective heat trasnfer:
dQ/d_theta = h_Nu * A * (T - T_inf) / N

h_Nu = k * Nu / L
Nu = 10.4 * pow(Re,0.75)
Re = rho * V * L

Area = Area of the wall + Area of the head + Area of the piston
A = (M_PI * b * y) + (M_PI/2 * b * b)  //assuming flat cylinder head
r = d/2  //crank radius

double sin_sq(double ang) 
{
	double tmp = sin(ang);
	return tmp * tmp;
}

y = r + l - ( pow( (l*l - r*r * sin_sq(theta), 1/2) + r * cos(theta) //exposed cylinder wall height
l is the connecting rod length
b is the width?
*/

//1) Convective heat transfer
double sin_sq(double ang)
{
	double tmp = sin(ang);
	return tmp * tmp;
}

double convective_ht() //parameters to insert from previous calculation
{
	double b = 99.5/1000; //bore (m)
	double l = 131.5/1000; //Rod Lenght (m)
	double L = 79.0/1000; //Stroke length (m)
	double r; //crank radius
	double y; //cylinder wall height
	double A; //Area

	y = r + l - (pow(l*l - r*r * sin_sq(theta), 1 / 2) + r * cos(theta));
	A = (M_PI * b * y) + (M_PI / 2 * b * b);

	double Re, Nu, V, k, h_Nu, rho; 

	Re = rho * V * L;
	Nu = 10.4 * pow(Re, 0.75);
	h_Nu = k * Nu / L;
	
	double N, T, T_inf, dqdtheta;
	dqdtheta = h_Nu * A * (T - T_inf) / N;
}

/*
Weibe function - cumulative heat release of burn fraction xb
xb(theta) = 1 - exp (-a * pow( ((theta - theta_s) / theta_d), n ))
where:
theta is the crank angle
theta_s is the start of heat release
theta_d is the duration of heat release
n is the form factor
a is the efficiency factor

and so the rate of heat release per crank angle is:
dQ/d_theta = Q_hv * dxb/d_theta

dxbd_theta = n * a * (1 - xb) * pow( ((theta - theta_s) / theta_d), n-1 )
*/

//2) Cumulative Heat Release using Weibe function

double xb(double theta, double theta_s, double theta_d, double a, double n)
{
	double xb = 1 - exp(-a * pow(((theta - theta_s) / theta_d), n));
	return xb;
}

/* On main
double theta; //Crank angle
double theta_s; //Start of heat release
double theta_d; //Duration of heat release
double n; //Form factor
double a; //Efficiency factor

xb(theta, theta_s, theta_d, n, a);
*/

//dxbd_theta = n * a * (1 - xb) * pow(((theta - theta_s) / theta_d), n - 1)