#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MyClass {
public:
	int A, C, G, T;
	int value;
	string str;
	MyClass() {
		A = C = T = G = value = 0;
	}
	void push(char ch) {
		str += ch;
		switch (ch)
		{
		case 'A':
			A++;
			value += (C + G + T);
			break;
		case 'C':
			C++;
			value += (G + T);
			break;
		case 'G':
			G++;
			value += T;
			break;
		case 'T':
			T++;
			break;
		}
	}
	static bool Comp(const MyClass& other1, const MyClass& other2) {
		return other1.value < other2.value;
	}
	void operator=(const MyClass& other) {
		// A = other.A;
		// C = other.C;
		// T = other.T;
		// G = other.G;
		value = other.value;
		str = other.str;
	}
	void clear() {
		A = C = T = G = value = 0;
		str.clear();
	}
	void display() {
		cout << str << endl;
	}
};

int main() {
	vector<MyClass> array;
	MyClass temp;
	int n, m;
	char ch;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		temp.clear();
		for (int j = 0; j < n; j++) {
			cin >> ch;
			temp.push(ch);
		}
		array.push_back(temp);
	}
	sort(array.begin(), array.end(),MyClass::Comp);
	for (int i = 0; i < m; i++)
		array[i].display();
	return 0;
}