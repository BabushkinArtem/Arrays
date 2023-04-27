#include <iostream>
#include <string>
#include <regex>
using namespace std;

const int n = 12;
int m[n];

void set_array() {
	string tmp_array; //for stoi()
	for (int i = 0; i <= n - 1; i++) {
		tmp_array = ("");
		while (!regex_match(tmp_array, regex("(([1-9][0-9]{1,16})|([1-9])|([0]))([.][0-9]{0,16}[1-9]){0,1}"))) {
			cout << "\nEnter a array element # " << i + 1 << ": ";
			getline(cin, tmp_array);
			try {
				m[i] = stod(tmp_array); //element is entered as a string, converted to int
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
		cout << "# " << i + 1 << ":	" << m[i] << "\n";
	}
}

int main()
{
	set_array();
	int index_1, index_2;
	for (int k = 0; k <= n - 1; k++) {
		for (int i = k; i <= n - 1; i++) {
			if (m[k] == m[i+1]) {
				cout << m[i+1] << " " << m[k] << "\n";
			}
		}
	}
    
}