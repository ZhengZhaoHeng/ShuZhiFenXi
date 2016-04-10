#include <iostream>
#include <fstream>
#include <cstdio>

#include "LeastSquareRegression.h"

using namespace std;

int main()
{
	LeastSquareRegression lsq;

	vector<double> x, y, a;
	int n, k;

	ifstream fin("input.txt");
	fin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		double tempx, tempy;
		fin >> tempx >> tempy;
		x.push_back(tempx);
		y.push_back(tempy);
	}

	lsq.regress(x, y, k, a);

	ofstream fout("output.txt");
	ofstream plot("plotlist.txt");
	for (auto& it : x)
	{
		fout << it << ' ';
	}

	fout << endl;

	for (auto& it : y)
	{
		fout << it << ' ';
	}
	
	fout << endl;

	double var = -3.0;
	double step = 0.01;
	while (var <= 3.0)
	{
		double ans = 0;
		for (int i = 0; i < a.size(); i++)
		{
			ans += a[i] * pow(var, i);
		}
		plot << var << ' ' << ans << endl;
		var += step;
	}

	for (auto& it : a)
	{
		cout << it << ' ';
	}
	system("pause");
	return 0;
}