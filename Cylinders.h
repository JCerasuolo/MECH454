#ifndef CYLINDERS_H
#define CYLINDERS_H

class Cylinder
{
public:
	int Ratio; //Compression ratio
	double Vd; //Total Displacement volume (L)
	double Ve; //Total Compressed Volume (L)
	double Vc; //Total Expanded Volume(L)
	double rodLength; //Connecting Rod Length (m) l
	double bore; // Bore (m) b
	double stroke; // Stroke length (m) L
	int AF; // Air Fuel Ratio
	int N; //Engine speed (RPM)

	Cylinder() // Values are per engine (4 Cylinders in this case)
	{
		Ratio = 10;
		Vd = 2.457;
		Vc = 0.273;
		Ve = 2.73;
		rodLength = 0.1315;
		stroke = 0.079;
		AF = 13;
		N = 4000;
	}

	~Cylinder(){}
};


#endif