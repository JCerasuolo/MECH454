#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "States.h"
#include "Cylinders.h"

using namespace std;

//Isentropic integral of PV^k compared to the numerical equation PV^k = C

Cylinder c2;

double analyticalComp(double P1, double Index)
{
	double P2 = P1*pow(c2.Ve, Index)/(pow(c2.Vc,Index)); //From expanded State 1 to compressed state 2
	return P2;
}

double analyticalExp(double P3, double Index)
{
	double P4 = P3*pow(c2.Vc, Index) / (pow(c2.Ve, Index)); //From compressed state 3 to expanded state 4
	return P4;
}
