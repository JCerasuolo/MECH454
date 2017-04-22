#include "stdafx.h"
#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <boost/array.hpp>
#include <conio.h>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;
using namespace boost::numeric::odeint;

	void rhs(const double p, double &dpdv, const double v) // 1.35 is the index in this scenario REMEMBER TO CHANGE THIS IF YOU CHANGE THE INDEX
	{
		dpdv = -1.35*p / v;
	}

	void write_cout(const double &p, const double v)
	{
		//cout << v << '\t' << p << endl;
	}

	// state_type = double
	typedef runge_kutta_dopri5< double > stepper_type;

	int integration(double p, double v1, double v2, double step) //original step size of 0.1
	{
		// double p = 100000.0;
		integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()),
			rhs, p, v1, v2, step, write_cout);
		return p;
	}
