#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define LN2 0.693147190546
#define EPS 0.5E-4

int main()
{
	float x = 0;
	int n = 0;
	while (fabs(x - LN2) >= EPS)
	{
		n++;
		if (n % 2 == 1)
		{
			x += (float)1 / n;
		}
		else
		{
			x -= (float)1 / n;
		}
	}
	cout << n << endl;
	system("pause");
	return 0;
}