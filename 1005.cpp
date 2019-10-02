#include <iostream>
#define M_PI 3.14159265358979323846
using namespace std;

int main()
{
	int n;
	double a, b;
	int* result = NULL;
	cin >> n;
	result = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		result[i] = (int)((a * a + b * b) * M_PI / 100) + 1;
	}
	for (int i = 0; i < n; i++)
	{
		cout << "Property " << i + 1 << ": This property will begin eroding in year " << result[i] << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
	return 0;
}