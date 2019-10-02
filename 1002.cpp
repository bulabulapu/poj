#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int toNum(char* inputNum)
{
	int numbers = 0;
	char ch;
	for (int i = 0; inputNum[i] != '\0'; i++)
	{
		ch = inputNum[i];
		if (ch >= '0' && ch <= '9')
			numbers = numbers * 10 + ch - '0';
		else if (ch >= 'A' && ch <= 'O')
			numbers = numbers * 10 + (ch - 'A') / 3 + 2;
		else if (ch == 'P')
			numbers = numbers * 10 + 7;
		else if (ch >= 'R' && ch <= 'Y')
			numbers = numbers * 10 + (ch - 'A' + 2) / 3 + 1;
	}
	return numbers;
}
void display(int numbers)
{
	printf("%03d-%04d ", numbers / 10000, numbers % 10000);
}

int main()
{
	int n;
	char str[50];
	cin >> n;
	int* d;
	d = new int[n];
	getchar();
	for (int i = 0; i < n; i++)
	{
		gets_s(str);
		d[i] = toNum(str);
	}
	sort(d,d+n);
	bool flag = false;
	for (int i = 0,count = 1; i < n; i++)
	{
		count = 1;
		while (d[i]==d[i+1])
		{
			i++;
			count++;
		}
		if (count > 1)
		{
			flag = true;
			display(d[i]);
			printf("%d\n", count);
		}
	}
	if (!flag) cout << "No duplicates." << endl;
	return 0;
}