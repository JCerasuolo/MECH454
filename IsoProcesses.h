#ifndef ISOPROCESSES_H
#define ISOPROCESSES_H

double isenCompressionT(double T1, double Index);
double isenCompressionP(double P1, double T2, double T1);
double thermalAddT(double qin, double T2, double Cv);
double thermalAddP(double T3, double P2, double T2);
double isenExpansionT(double T3, double Index);
double isenExpansionP(double T4, double P3, double T3);
double thermalSubT(double Cv, double T1, double T4);

#endif