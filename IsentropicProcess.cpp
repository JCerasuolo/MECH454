#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "States.h"
#include "Cylinders.h"

//Isentropic relations as per the powerpoint slides (lecture 8) using the same old relations

Cylinder c1;

double isenCompressionT(double T1, double Index)
{
	double T2 = T1 * pow(c1.Ratio, (Index - 1));
	return T2;
}

double isenCompressionP(double P1, double T2, double T1)
{
	double P2 = (P1 * T2 * c1.Ve) / (T1 * c1.Vc);
	return P2;
}

double thermalAddT(double qin, double T2, double Cv)
{
	double T3 = T2 + (qin / Cv);
	return T3;
}

double thermalAddP(double T3, double P2, double T2)
{
	double P3 = T3*P2 / T2;
	return P3;
}

double isenExpansionT(double T3, double Index)
{
	double T4 = T3 / (pow(c1.Ratio, Index - 1));
	return T4;
}

double isenExpansionP(double T4, double P3, double T3)
{
	double P4 = (T4 * c1.Vc * P3) / (T3 * c1.Ve);
	return P4;
}

double thermalSubT(double Cv, double T1, double T4)
{
	double qout = Cv*(T1 - T4);
	return qout;
}