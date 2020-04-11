#include<iostream>
#include<limits>
using namespace std;


int main() {
	int input;
	unsigned long long sum = 0;	//f(n)
	unsigned long long sum_1 = 1;	//f(n-2)
	unsigned long long sum_2 = 1;	//f(n-1)
	bool finished = false;


	while (!finished) {	//Keep running until finished == true
		cout << "Please input the number of term of Fibonacci sequence you want:";
		cin >> input;

		if (cin.fail()) {	//Check if cin is an integer
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "INTEGERS ONLY!!!" << endl << endl;
			continue;
		}

		if (input > 0) {
			switch (input) {
			case 1:	//If input == 1 then print "F(1)=1"
				cout << "F(" << input << ")" << "=" << sum_1 << endl << endl;
				finished = true;
				break;
			case 2:	//If input == 2 then print "F(2)=1"
				cout << "F(" << input << ")" << "=" << sum_2 << endl << endl;
				finished = true;
				break;
			default:	//If input >= 3
				for (int i = 0; i < (input - 2); i++) {	//The result of the first calculation is F(3)
					sum = sum_1 + sum_2;
					sum_1 = sum_2;
					sum_2 = sum;
				}
				cout << "F(" << input << ")" << "=" << sum << endl << endl;
				finished = true;
			}
		}
		else {	//input <= 0
			cout << "More than 0 please!!" << endl << endl;
			continue;
		}
	}
	system ("pause");
	return 0;
}