#include <iostream>
using namespace std;

int r, c;
int** p = NULL, ** q = NULL;

int fun(int i, int j) {
	int max = 0, temp;
	if (q[i][j] > 0) return q[i][j];
	if (i - 1 >= 0 && p[i - 1][j] < p[i][j]) {
		temp = fun(i - 1, j) + 1;
		max = max > temp ? max : temp;
	}
	if (i + 1 < r && p[i + 1][j] < p[i][j]) {
		temp = fun(i + 1, j) + 1;
		max = max > temp ? max : temp;
	}
	if (j - 1 >= 0 && p[i][j - 1] < p[i][j]) {
		temp = fun(i, j - 1) + 1;
		max = max > temp ? max : temp;
	}
	if (j + 1 < c && p[i][j + 1] < p[i][j]) {
		temp = fun(i, j + 1) + 1;
		max = max > temp ? max : temp;
	}
	if (max == 0) max = 1;
	q[i][j] = max;
	return max;
}

int main() {
	int max = 0;
	cin >> r >> c;
	p = new int* [r];
	q = new int* [r];
	for (int i = 0; i < r; i++) {
		p[i] = new int[c];
		q[i] = new int[c];
	}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			cin >> p[i][j];
			q[i][j] = 0;
		}
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			max = max > fun(i, j) ? max : fun(i, j);
	cout << max;
	return 0;
}

// 动态规划,存储递归过程,减少递归重复计算