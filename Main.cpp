#include <iostream>
#include <string>
#include <vector>
#include "E:/Dev-Cpp/myInclude/hr.h"
#include <stack>

using namespace std;

char getRandomChar() {
	return rand() % ('z' - 'a') + 'a';
}

void q1p2() {
	hr("q1p2");
	
	int num;
	cin >> num;
	if (!cin) {
		cin.clear();
		return;
	}
	cin.get();
	char** arr;
	arr = new char*[num];
	cout << "    ";
	for (int i = 0; i < num; ++i) {
		cout.width(2);
		cout << left << i;
	}
	cout << endl;
	for (int i = 0; i < num; ++i) {
		cout.width(4);
		cout <<left<< i ;
		arr[i] = new char[num];
		for (int j = 0; j < num; ++j) {
			arr[i][j] = getRandomChar();
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}

	string value;
	cin >> value;
	cin.get();

	for (int i = 0; i < num; ++i) {
		for (int j = 0; j < num; ++j) {
			//左
			int temp[8]={};//8个方向
			for (int k = 0; k < value.size(); ++k) {
				if (j - k >= 0) {
					if (arr[i][j - k] == value[k]) {
						++temp[0];//左
					}
					if (i - k >= 0) {
						if (arr[i - k][j - k] == value[k]) {
							++temp[4];
						}
					}
					if (i + k < num) {
						if (arr[i + k][j - k] == value[k]) {
							++temp[5];
						}
					}
				}
				if (j + k < num) {
					if (arr[i][j + k] == value[k]) {
						++temp[1];//右
					}
					if (i - k >= 0) {
						if (arr[i - k][j + k] == value[k]) {
							++temp[6];
						}
					}
					if (i + k < num) {
						if (arr[i + k][j + k] == value[k]) {
							++temp[7];
						}
					}
				}
				if (i - k >= 0) {
					if (arr[i - k][j] == value[k]) {
						++temp[2];
					}
				}
				if (i + k < num) {
					if (arr[i + k][j] == value[k]) {
						++temp[3];
					}
				}
			}
			for (int k = 0; k < 8; ++k) {
				if (temp[k] == value.size()) {
					cout << "true  " << i << "  " << j<<endl;
				}
			}
		}
	}

	for (int i = 0; i < num; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	arr = nullptr;

}

void dealInt(int value) {
	if (value >= 10||value<=-10) {
		dealInt(value / 10);
		
	}
	cout << value%10;
}

void q1p3() {
	hr("q1p3");
	int value;
	cin >> value;
	if (!cin) {
		cin.clear();
		return;
	}
	cin.get();

	dealInt(value);
	cout << endl;
}

int q1p5Func(int value) {
	static int num = 0;
	if (value == 0) {
		return 0;
	}
	if (value % 2) {
		num+=(q1p5Func(value / 2) + 1);
	}
	else {
		q1p5Func(value / 2);
	}

	return num;
}
void q1p5() {
	hr("q1p5");
	int value;
	cin >> value;
	if (!cin) {
		cin.clear();
	}
	cout<<q1p5Func(value)<<endl;
}

void q1() {
	hr("q1");
		q1p2();
		q1p3();
		q1p5();
		cin.get();
	
}

int maxSumFunc(vector<int>& a, int left, int right) {
	if (left == right) {
		if (a[left] > 0) {
			return a[left];
		}
		else {
			return 0;
		}
	}
	int center = (left + right) / 2;
	int maxLeftSum = maxSumFunc(a, left, center);
	int maxRightSum = maxSumFunc(a, center + 1, right);

	int maxLeftBorderSum = 0, leftBorderSum = 0;
	for (int i = center; i >= left; --i) {
		leftBorderSum += a[i];
		if (leftBorderSum > maxLeftBorderSum) {
			maxLeftBorderSum = leftBorderSum;
		}
	}

	int maxRightBorderSum = 0, rightBorderSum = 0;
	for (int i = center + 1; i <= right; ++i) {
		rightBorderSum += a[i];
		if (rightBorderSum > maxRightBorderSum) {
			maxRightBorderSum = rightBorderSum;
		}
	}

	int maxCenter = maxLeftBorderSum + maxRightBorderSum;

	return maxLeftSum > maxRightSum ? (maxLeftSum > maxCenter ? maxLeftSum : maxCenter) : (maxRightSum > maxCenter ? maxRightSum : maxCenter);
}

void maxSum() {
	hr("maxSum");
	vector<int> v;
	int value;
	while (cin >> value) {
		v.push_back(value);
	}
	cin.clear();
	cin.get();
	cout<<maxSumFunc(v, 0, v.size()-1)<<endl;
}

void maxSum4() {
	hr("maxSum4");
	vector<int> v;
	int value;
	while (cin >> value) {
		v.push_back(value);
	}
	cin.clear();
	cin.get();
	
	int maxSum = 0, thisSum = 0;
	for (int j = 0; j < v.size(); ++j) {
		thisSum += v[j];
		if (thisSum > maxSum) {
			maxSum = thisSum;
		}
		else if (thisSum < 0) {
			thisSum = 0;
		}
	}
	cout << maxSum << endl;
}

void Ojld() {
	hr("Ojld");
	int value1, value2;
	cin >> value1 >> value2;
	cin.get();
	while (value2) {
		int temp = value1 % value2;
		value1 = value2;
		value2 = temp;
	}
	cout << value1 << endl;
}

long long powFunc(int m, int n) {
	if (n == 0) {
		return 1;
	}
	else if (n == 1) {
		return m;
	}
	else if (m % 2) {
		return powFunc(m * m, n / 2) * m;
	}
	else {
		return powFunc(m * m, n / 2);
	}


}

void testPow() {
	int value,m;
	cin >> value>>m;
	cin.get();

	cout<<powFunc(value,m)<<endl;

}

#include "Vector.h"
void testVector() {
	hr("testVector");
	Vector<int> v;
	for (int i = 0; i < 10; ++i) {
		v.push_back(i);
	}
	for (auto i : v) {
		cout << i << ' ';
	}
	cout << endl;
}

void testStack() {
	hr("testStack");
	stack<char> st;
	char ch;
	while (cin >> ch) {
		if (ch == '}') {
			if (st.empty()) {
				cout << "false" << endl;
				return;
			}
			else if (st.top() == '{') {
				st.pop();
			}
		}
		else if(ch=='{') {
			st.push(ch);
		}
	}
	cin.clear();

	cout << boolalpha << st.empty() << endl;

}

void caDeal(stack<int>& clu,int opt){
	if (opt == '(') {
		return;
	}
	int temp1 = clu.top();
	clu.pop();
	int temp2 = clu.top();
	clu.pop();
	switch (opt) {
	case '+':
		clu.push(temp1 + temp2);
		break;
	case '-':
		clu.push(temp1 - temp2);
		break;
	case '*':
		clu.push(temp1 * temp2);
		break;
	case '/':
		clu.push(temp1 / temp2);
		break;
	}
}

void calculate() {
	hr("calculate");
	char value;
	stack<int> opt;
	stack<int> clu;
	while (cin >> value) {
		if (isdigit(value)) {
			value = value - '0';
			while (isdigit(cin.peek())) {
				value = value * 10 + cin.get() - '0';
			}
			clu.push(value);
		}
		else {
			if (value == '(') {
				opt.push(value);
			}
			else if (value == ')') {
				while (opt.top() != '(') {
					//caDeal(clu, opt.top());
					opt.pop();
				}
				opt.pop();
			}
			else if (opt.empty()) {
				opt.push(value);
			}
			else {
				if (opt.top() == '*' || opt.top() == '/') {
					caDeal(clu, opt.top());
					opt.pop();
					opt.push(value);
				}
				else {
					if (value == '+' || value == '-') {
						caDeal(clu, opt.top());
						opt.pop();
						opt.push(value);
					}
					else {
						opt.push(value);
					}
				}
			}
		}
	}
	while (!opt.empty()) {
		caDeal(clu, opt.top());
		opt.pop();
	}

	cout << "原式 = " << clu.top() << endl;
	cin.clear();
}

int main() {
	srand((unsigned)time(nullptr));
	//q1();
	//wmaxSum();
	//maxSum4();
	//Ojld();
	//testPow();
	testVector();
	//testStack();
	calculate();


	return 0;
}