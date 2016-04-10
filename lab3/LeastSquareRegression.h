#pragma once

#include <vector>

#include "GaussEquation.h"

class LeastSquareRegression
{
public:
	LeastSquareRegression();
	~LeastSquareRegression();

	void regress(std::vector<double> &x, std::vector<double> &y, int k, std::vector<double> &res);  // k�ζ���ʽ�ع����
};

