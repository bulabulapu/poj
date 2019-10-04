#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;

class BigDouble {
public:
	vector<int> num;
	BigDouble() {
	}
	BigDouble(string str) {
		int i, j = 0;
		for (i = 1; i < 6; i++) // 小数点位置
			if (str[i] == '.')
				break;
		while (j < i && str[j] == '0') { // 数前有0
			str[j] = '.';
			j++;
		}
		if (i == 6) num.insert(num.begin(), 0); // 整数
		else {
			j = 5;
			while (str[j] == '0') { // 小数末尾有0
				str[j] = '.';
				j--;
			}
			num.insert(num.begin(), j - i);
			if (str[0] == '0') str[0] = '.'; // 小数小于1
		}
		for (i = 0; i < str.length(); i++)
			if (str[i] != '.')
				num.push_back(str[i] - '0');
	}
	BigDouble(const BigDouble& other) {
		num = other.num;
	}
	BigDouble operator*(const BigDouble other) {
		BigDouble result;
		unsigned int i, j, digdit;
		for (i = other.num.size() - 1; i > 0; i--) { // 每位相乘并相加
			for (j = num.size() - 1; j > 0; j--) {
				digdit = other.num.size() - 1 - i + num.size() - 1 - j;
				if (digdit >= result.num.size()) {
					result.num.push_back(num[j] * other.num[i]);
				}
				else {
					result.num[digdit] += (num[j] * other.num[i]);
				}
			}
		}
		for (i = 0, digdit = 0; i < result.num.size(); i++) {// 进位
			digdit += result.num[i];
			result.num[i] = digdit % 10;
			digdit /= 10;
		}
		while (digdit != 0) {
			result.num.push_back(digdit % 10);
			digdit /= 10;
		}
		result.num.push_back(num[0] + other.num[0]);
		for (i = 0, j = result.num.size() - 1; j > i; i++, j--) {
			digdit = result.num[i];
			result.num[i] = result.num[j];
			result.num[j] = digdit;
		}
		return result;
	}
	void display() {
		int l;
			while (num[0] >= num.size()) { // 形如0.0000001,在第一位非0前添加0
				num.insert(num.begin() + 1, 0);
			}
			l = num.size() - 1;
			while (num[0] != 0 && num[l] == 0) { // 消除小数点末尾0
				l--;
			}
			for (int i = 1; i <= l; i++) {
				if (num.size() - num[0] == i)
					cout << '.';
				cout << num[i];
			}
		cout << endl;
	}
};

int main() {
	int j, n = 0, input_n;
	string input_num;
	vector<BigDouble> BD_array;
	BigDouble tmp;
	while (cin >> input_num >> input_n) {
		n++;
		tmp = BigDouble(input_num);
		BD_array.push_back(tmp);
		if (input_n == 1) {
			BD_array[n - 1].display();
			continue;
		}
		for (j = 0; j < (int)log2(input_n); j++) {
			BD_array[n - 1] = BD_array[n - 1] * BD_array[n - 1];
		}
		input_n -= pow(2, (int)log2(input_n));
		for (j = 0; j < input_n; j++) {
			BD_array[n - 1] = BD_array[n - 1] * tmp;
		}
		BD_array[n - 1].display();
	}
	return 0;
}