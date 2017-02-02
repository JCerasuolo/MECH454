#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "ProjectMain.cpp"
#include "Cylinder.cpp"

double isenCompressionT()
{
	double T2 = s1.Tmp*(pow(c1.compRatio, (c1.index - 1)));
	return T2;
}

double isenCompressionP()
{
	double P2 = (s1.Pr * s2.Tmp * c1.Ve) / (s1.Tmp * c1.Vc);
	return P2;
}

double thermalAddT()
{

}

double thermalAddP()
{

}

double isenExpansionT()
{
	double T4 = s3.Tmp / (pow(c1.compRatio, (c1.index - 1)));
	return T4;
}

double isenExpansionP()
{
	double P4 = (s4.Tmp * c1.Vc * s3.Pr) / (s3.Tmp * c1.Ve);
	return P4;
}

double thermalSubT()
{

}

double thermalSubP()
{

}