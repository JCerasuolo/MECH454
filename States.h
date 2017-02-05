#ifndef STATES_H
#define STATES_H

class State
{
public:
	double Pr; //Pressure (Pa)
	double Tmp; //Temperature (K)

	State(double tetzle, double pretzle)
	{
		Pr = pretzle;
		Tmp = tetzle;
	}

	State()
	{
		Pr = 0;
		Tmp = 0;
	}
};
#endif // !STATES_H
