// MECH454Project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include "States.h"
#include "IsoProcesses.h"
#include "IsoIntegral.h"

using namespace std;

int main()
{
	double qin = 2000; // Heat Addition(kJ/kg)
	double Cv = 1.00; //Cv of air
	double Cp = 0.718; //Cp of air
	double Index = Cv / Cp; //Adiabatic Index

	State s1(300, 100000);
	
	State s2;
	s2.Tmp = isenCompressionT(s1.Tmp, Index);
	s2.Pr = isenCompressionP(s1.Pr, s2.Tmp, s1.Tmp);

	State s3;
	s3.Tmp = thermalAddT(qin, s2.Tmp, Cv);
	s3.Pr = thermalAddP(s3.Tmp, s2.Pr, s2.Tmp);

	State s4;
	s4.Tmp = isenExpansionT(s3.Tmp, Index);
	s4.Pr = isenExpansionP(s4.Tmp, s3.Pr, s3.Tmp);


	cout << "T1: " << s1.Tmp << " K, P1: " << s1.Pr << " Pa" << endl;
	cout << "T2: " << s2.Tmp << " K, P2: " << s2.Pr << " Pa" << endl;
	cout << "T3: " << s3.Tmp << " K, P3: " << s3.Pr << " Pa" << endl;
	cout << "T4: " << s4.Tmp << " K, P4: " << s4.Pr << " Pa" << endl;

	double win = Cv*(s1.Tmp - s2.Tmp); //Compression work in (kJ/kg)
	double wout = Cv*(s3.Tmp - s4.Tmp); //Expansion work out (kJ/kg)
	double qout = Cv*(s1.Tmp - s4.Tmp); //Heat Removal (kJ/kg)

	cout << "\nWin: " << win << " kj/kg" << endl;
	cout << "Qin: " << qin << " kj/kg" << endl;
	cout << "Wout: " << wout << " kj/kg" << endl;
	cout << "Qout: " << qout << " kj/kg" << endl;

	cout << "\nTotal Power: " << qin + qout - win - wout << endl; //Checking to make sure all power in and out cancels
	cout << "Net cycle work: " << wout + win << " kj/kg" << endl;
	cout << "Thermal Efficieny: " << (wout + win) / qin << " kj/kg" << endl;

	cout << "\nComparing the isentropic relations analytically," << endl;
	cout << "The difference between isentropic relations of states 1 and 2: " << analyticalSoln(s1.Pr, s2.Pr, Index) << endl;
	cout << "The difference between isentropic relations of states 3 and 4: " << analyticalSoln(s4.Pr, s3.Pr, Index) << endl;



	_getch();

	return 0;
}

