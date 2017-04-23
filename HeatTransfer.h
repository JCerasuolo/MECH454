#ifndef HEATTRANSFER_H
#define HEATTRANSFER_H

double convective_ht(double theta, double T, double N);
double xb(double theta, double theta_s, double theta_d, double a, double n);
double Wiebe(double theta);
double compressiveHeat(double theta);
void rhs2(const double p, double &dpdtheta, const double theta);
void write_cout2(const double &p, const double theta);
double firstLawIntegration(double p, double theta_s, double theta_d);

#endif