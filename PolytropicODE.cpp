#include "stdafx.h"
#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <boost/array.hpp>
#include <conio.h>
#include <fstream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace boost::numeric::odeint;

ofstream fout;

	void rhs(const double p, double &dpdv, const double v) // 1.35 is the index in this scenario REMEMBER TO CHANGE THIS IF YOU CHANGE THE INDEX
	{
		dpdv = -1.234*p / v;
	}

	void write_cout(const double &p, const double v)
	{
		fout << v << "," << p << endl;
	}

	// state_type = double
	typedef runge_kutta_dopri5< double > stepper_type;

	int integration(double p, double v1, double v2, double step) //original step size of 0.1
	{
		// double p = 100000.0;
		fout.open("data.csv", std::fstream::in | std::fstream::out | std::fstream::app);
		integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()),
			rhs, p, v1, v2, step, write_cout);
		fout.close();
		return p;
	}
