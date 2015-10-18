#include <iostream>
using namespace std;

#define MAXN 1000
double temp[MAXN];
double ans[MAXN];
double f[MAXN] = {2.41450, 2.63632, 1.49603, -1.44131, 8.82423};
double x[MAXN] = {1.615, 1.634, 1.702, 1.828, 1.921};
int n;

void gettemp(int i, double x)
{
	double t[MAXN];
	for (int j = 0; j < n; ++j)
		t[j] = -temp[j] * x;
	for (int j = i; j >= 0; --j)
		temp[j + 1] = temp[j];
	temp[0] = 0;
	for (int j = 0; j < n; ++j)
		temp[j] += t[j];
	//for (int j = n - 1; j >= 0; --j)
	//	cout << temp[j] << ' ';
	//cout << endl;
}

int main()
{
	cout << "input n:";
	cin >> n;
    cout << "input xi, yi for " << n << "time(s):" << endl;
	for (int i = 0; i < n; ++i)
		cin >> x[i] >> f[i];
	//n = 5;
	ans[0] = f[0];
	temp[0] = 1;
	for (int i = 0; i < n - 1; ++i)
	{
		gettemp(i, x[i]);
		for (int j = 0; j < n; ++j)
			ans[j] += temp[j] * f[i + 1];
	}
	cout << "The coefficients of x^" << n - 1 << " to x^0 is: " << endl;
    
	for (int i = n - 1; i >= 0; --i)
		cout << ans[i] << ' ';
	cout << endl;
    /*
	double k, answer = 0;
	cin >> k;
	for (int i = n - 1; i >= 0; --i)
		answer = answer * k + ans[i];
	cout << answer << endl;
    */
	return 0;
}
