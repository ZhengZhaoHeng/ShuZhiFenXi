#ifndef _GAUSS_EQUATION_H__
#define _GAUSS_EQUATION_H__

//#define EPS 1e-10

class GaussEquation
{
public:
	GaussEquation(int deg);
	~GaussEquation();
	bool solve();
	double* get_solution();
private:
	int _deg;
	double *_solution;
};

const int max_deg = 50;
extern double mat[50][50];

#endif