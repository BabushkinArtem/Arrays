#include <iostream>
#include <string>
#include <regex>

using namespace std;
const int n = 12;
double m[n];
double average;

void set_array() {
string tmp_array; //for stoi()
	for (int i = 0; i <= n-1; i++) {
		tmp_array = ("");
		while (!regex_match(tmp_array, regex("([1-9][0-9]{1,16})|([1-9])|([0])"))) {
			cout << "\nEnter a array element # "<<i+1<<": ";
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
double count_av() {
	double sum = 0;
	for (int i = 0; i <= n - 1; i++) {
		sum += m[i];
	}
	double av=sum/n; //average
	return av;
}

void replace_array() {
	double rep_array[n];
	copy_n(m,n,rep_array);
	rep_array[4] = count_av();
	copy_n(rep_array, n, m);
}

void show_array() {
	cout << "\n\nReplaced array:\n";
	for (int i = 0; i <= n - 1; i++) {
			cout << "# " << i+1 << ": " << m[i] << "\n";
		}
}

int main()
{
	set_array();
	replace_array();
	show_array();
	return 0;

}

