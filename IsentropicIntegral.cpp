#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "States.h"
#include "Cylinders.h"

using namespace std;

//Isentropic integral of PV^k compared to the numerical equation PV^k = C

Cylinder c2;

double analyticalSoln(double P1or4, double P2or3, double Index)
{
	double first = P1or4*pow(c2.Ve, Index); //One of the expanded states
	double second = P2or3*pow(c2.Vc, Index); //The corresponding compressed state
	return first - second;
}

double integralSoln()
{

}