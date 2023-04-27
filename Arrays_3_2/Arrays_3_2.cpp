#include <iostream>
#include <string>
#include <regex>
#include <math.h>
using namespace std;


string bin_number; //for regex


void set_number() {
	while (!regex_match(bin_number, regex("([1][0-1]{0,32})|[0]"))) {
			getline(cin, bin_number);
		}
}


int main()
{
	set_number();
	int dec_number=0, length;
	int i_pow = length = size(bin_number)-1;
	
	for (int k = 0; k <= length; k++) {
		string current_number{ bin_number[k] };
		dec_number += stoi(current_number)*pow(2, i_pow);
		i_pow--;
	} 
	cout << dec_number;

	return 0;
}
