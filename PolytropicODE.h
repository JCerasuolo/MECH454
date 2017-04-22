#ifndef POLYTROPICODE_H
#define POLYTROPICODE_H

void rhs(const double p, double &dpdv, const double v);
void write_cout(const double &p, const double v);
int integration(double p, double v1, double v2, double step);

#endif