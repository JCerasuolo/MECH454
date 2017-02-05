#ifndef CYLINDERS_H
#define CYLINDERS_H

class Cylinder
{
public:
	int Ratio; //Compression ratio
	double Vd; //Total Displacement volume (L)
	double Ve; //Total Compressed Volume (L)
	double Vc; //Total Expanded Volume(L)

	Cylinder()
	{
		Ratio = 8;
		Vd = 1;
		Vc = 0.143;
		Ve = 1.143;
	}

	~Cylinder(){}
};
#endif