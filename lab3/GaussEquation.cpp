#include "GaussEquation.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <utility>
#include <cstring>

double mat[50][50];

using namespace std;


GaussEquation::GaussEquation(int deg)
{
	_deg = deg;
	_solution = new double[_deg];
}

GaussEquation::~GaussEquation()
{
	delete _solution;
}

bool GaussEquation::solve()
{
	int max_r = 0;
	for (int i = 0; i < _deg; i++)
	{
		max_r = i;
		for (int j = i + 1; j < _deg; j++)
		{
			if (abs(mat[j][i]) > abs(mat[i][i]))
			{
				max_r = j;
			}	
		}
		
		if (max_r != i)
		{
			for (int j = 0; j <= _deg; j++)
			{
				swap(mat[i][j], mat[max_r][j]);
			}
		}
		
		if (mat[i][i] != 0)
		{
			for (int j = i + 1; j < _deg; j++)
			{
				if (mat[j][i] == 0) continue;
				double k = abs(mat[j][i]) * abs(mat[i][i]);
				double ka = abs(k / mat[i][i]);
				double kb = abs(k / mat[j][i]);
				//cout << k << ' ' << ka << ' ' << kb << endl;
				if (mat[j][i] * mat[i][i] < 0) kb = -kb; 
				for (int k = i; k < _deg + 1; k++)
				{
					mat[j][k] = mat[j][k] * kb - mat[i][k] * ka;
				}				
			}
		}
	}
	
	memset(_solution, 0, _deg * sizeof(double));
	for (int i = _deg - 1; i >= 0; i--)
	{
		double sum = mat[i][_deg];
		for (int j = i + 1; j < _deg; j++)
		{
			sum -= _solution[j] * mat[i][j];	
		}
		if (sum != 0 && mat[i][i] == 0) 
		{
			/*double pppp = mat[i][i];
			for (int i1 = 0; i1 < 3; i1++)
			{
				for (int j1 = 0; j1 < 4;j1++)
				{
					std::cout << mat[i1][j1] << ' ';
				}
				std::cout << std::endl;
			}*/
			return false;
		}
		if (mat[i][i] == 0)
		{
			_solution[i] = 1;
			continue;
		}
		_solution[i] = sum / mat[i][i];
	}
	return true;
}

double* GaussEquation::get_solution()
{
	return _solution;
}