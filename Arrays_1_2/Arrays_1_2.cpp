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
		while (!regex_match(tmp_array, regex("[-]{0,1}([1-9][0-9]{1,16})|([1-9])|([0])"))) {
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


	
	


void show_array() {
	cout << "\n\nReplaced array:\n";
	for (int i = 0; i <= n - 1; i++) {
			cout << "# " << i+1 << ": " << m[i] << "\n";
		}
}

int main()
{
	set_array();
	m[4] = count_av(); //replaces the 5th element of array with the average
	show_array();
	return 0;

}

