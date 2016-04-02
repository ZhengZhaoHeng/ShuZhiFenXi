#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int n=1;
	float err_1 = 0, err_2 = 0;
	float est = 0;
	do
	{
		if( n % 2 == 1)
		{
			est += 1.0/n;
		} 
		else
		{
			est -= 1.0/n;
		}
		err_2 = abs(0.693147190546 - est);
		n++;
	}
	while(err_2 >= 0.5e-4);
	cout << est << ' ' << n << endl;
	n = 1;
	do
	{
		err_1 = 1.0/(n+1);
		n++;
	}
	while(err_1 >= 0.5e-4);
	cout << n << endl;
}