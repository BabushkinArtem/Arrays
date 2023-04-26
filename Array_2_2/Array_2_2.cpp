#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;
const int n = 8;
int m[n];

void set_array() {
	string tmp_array; //for stoi()
	for (int i = 0; i <= n - 1; i++) {
		tmp_array = ("");
		while (!regex_match(tmp_array, regex("[-]{0,1}[1-9][0-9]"))) {
			cout << "\nEnter a array element # " << i + 1 << ": ";
			getline(cin, tmp_array);
			try {
				m[i] = stoi(tmp_array); //element is entered as a string, converted to int
			}
			catch (invalid_argument) {
				cout << "Please, enter an integer\n";
			}
		}
	}
}

void show_array() {
	cout << "\n\nReplaced array:\n";
	for (int i = 0; i <= n - 1; i++) {
		cout << "# " << i + 1 << ": " << m[i] << "\n";
	}
}

void modification_array() {
	int mod_array[n];
		copy_n(m, n, mod_array);
		for (int i = 0; i <= n-1; i++) {
			mod_array[i] =mod_array[i]%10;
			mod_array[i]=fabs(mod_array[i]);
		}
		copy_n(mod_array, n, m);
}

int main()
{
	set_array();
	modification_array();
	show_array();
	return 0;
}