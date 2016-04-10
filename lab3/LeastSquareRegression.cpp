#include "LeastSquareRegression.h"



LeastSquareRegression::LeastSquareRegression()
{
}


LeastSquareRegression::~LeastSquareRegression()
{
}

void LeastSquareRegression::regress(std::vector<double>& x, std::vector<double>& y, int k, std::vector<double>& res)
{
	k++;
	res.clear();
	GaussEquation equ(k);
	for (int i = 0; i < k; i++)
	{
		for (int j = i; j < k; j++)
		{
			mat[i][j] = 0;
			for (int l = 0; l < x.size(); l++)
			{
				mat[i][j] += pow(x[l], i + j);
			}
			mat[j][i] = mat[i][j];
		}
		
		mat[i][k] = 0;
		for (int j = 0; j < x.size(); j++)
		{
			mat[i][k] += pow(x[j], i) * y[j];
		}
	}

	equ.solve();
	double* ptr = equ.get_solution();
	for (int i = 0; i < k; i++)
	{
		res.push_back(ptr[i]);
	}
}
