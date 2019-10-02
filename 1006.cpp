#include <iostream>
using namespace std;

int fun(int p, int e, int i)
{
	int cycle1 = 23, cycle2 = 28, cycle3 = 33;
	int temp = i + cycle3;
	while (true)
	{
		if ((temp - e) % cycle2 == 0)
			if ((temp - p) % cycle1 == 0)
				break;
		temp += cycle3;
	}
	// p %= cycle1;
	// e %= cycle2;
	// i %= cycle3;
	// int m = p * e * i;
	// int temp = (cycle1 + cycle2 + cycle3) % m;
	return temp;
}

int main()
{
	int n = 0, a, b, c, d;
	int *out = NULL;
	out = new int[100000];
	while (true)
	{
		cin >> a >> b >> c >> d;
		if (a == -1)
			break;
		out[n] = fun(a, b, c) - d;
		if (out[n] == 0)
			out[n] = fun(d, d, d) - d;
		if (out[n] > 21252)
			out[n] -= 21252;
		if (out[n] < 0)
			out[n] += 21252;
		n++;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Case " << i + 1 << ": the next triple peak occurs in " << out[i] << " days." << endl;
	}
	return 0;
}