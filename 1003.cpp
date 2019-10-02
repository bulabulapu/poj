#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<double> input;
	vector<int> turn; //输入的排序表
	double temp;
	do
	{
		cin >> temp;
		input.push_back(temp);
	} while (temp != 0);
	bool* flag = new bool[input.size()]();
	int* output = new int[input.size()]();
	for (unsigned int i = 0; i < input.size(); i++)
	{
		int pos = input.size() - 1;
		for (unsigned int j = 0; j < input.size(); j++)
		{
			if (input[j] > input[pos] && !flag[j])
			{
				pos = j;
			}
		}
		turn.push_back(pos);
		flag[pos] = true;
	}
	delete[] flag;
	temp = 0;
	int i = input.size() - 1;
	double j = 2;
	do
	{
		temp += 1 / j;
		while (i >= 0 && temp >= input[turn[i]])
		{
			output[turn[i]] = (int)j - 1;
			i--;
		}
		j++;
	} while (i >= 0);
	for (unsigned int i = 0; i < input.size() - 1; i++)
	{
		cout << output[i] << " card(s)" << endl;
	}
	return 0;
}