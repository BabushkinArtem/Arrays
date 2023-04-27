#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;


string bin_number; //for regex
int dec_number=0;

void set_number() {
	while (!regex_match(bin_number, regex("([1][0-1]{0,32})|[0]"))) {
			getline(cin, bin_number);
		}
}
int to_dec() {
	int length;
	dec_number = 0;
	int i_pow = length = size(bin_number) - 1;
	for (int k = 0; k <= length; k++) {
		string current_number{ bin_number[k] };
		dec_number += stoi(current_number) * pow(2, i_pow);
		i_pow--;
	}
	return dec_number;
}
int to_oct() {
	string str_oct{""};
	while (dec_number != 0) {
		str_oct += to_string(dec_number % 8);
		dec_number /= 8;
	}
	reverse(str_oct.begin(), str_oct.end());
	return stoi(str_oct);
}

int main()
{
	set_number();
	dec_number = to_dec();
	cout << to_oct();
	
	return 0;
}
