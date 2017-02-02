// MECH454Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "IsentropicProcess.cpp"

using namespace std;

class State
{
private:
	double Pr; //Pressure (Pa)
	double Tmp; //Temperature (K)

public:
	State(double pretzle, double tetzle)
	{
		Pr = pretzle;
		Tmp = tetzle;
	}
};

int main()
{

	Cyli c1;

	State s1(300,100000);
	State s2(isenCompressionT(), isenCompressionP());
	State s3(thermalAddT(), thermalAddP());
	State s4(isenExpansionT(), isenExpansionP());
	State returnus(thermalSubT(), thermalSubP());

	qin = 2000; //(kJ/kg)

	cout << s1.Tmp << ", " << s1.Pr << endl;
	cout << s2.Tmp << ", " << s2.Pr << endl;
	cout << s3.Tmp << ", " << s3.Pr << endl;
	cout << s4.Tmp << ", " << s4.Pr << endl;
	cout << returnus.Tmp << ", " << returnus.Pr << endl;

	return 0;
}

