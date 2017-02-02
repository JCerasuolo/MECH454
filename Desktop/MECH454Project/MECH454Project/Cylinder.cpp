#include "stdafx.h"
#include <iostream>

class Cyli
{
private:
	int compRatio; //Compression ratio
	double Vd; //Displacement volume (L)
	double Ve; //Compressed Volume (L)
	double Vc; //Expanded Volume(L)
	double index; //Adiabatic Index

public:
	Cyli()
	{
		compRatio = 8;
		Vd = 1;
		Vc = 0.143;
		Ve = 1.143;
		index = 1.35;
	}

	~Cyli(){}
};