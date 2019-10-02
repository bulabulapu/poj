#include <iostream>
using namespace std;

int main()
{
	double salarys[12];
	double average = 0;
	for (int i = 0; i < 12; i++)
	{
		cin >> salarys[i];
		average += salarys[i];
	}
	average /= 12;
	cout << "$" << average << endl;
	return 0;
}