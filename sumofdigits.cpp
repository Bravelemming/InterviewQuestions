/*
A digital root is the recursive sum of all the digits in a number. 
Given n, take the sum of the digits of n. If that value has two digits, 
continue reducing in this way until a single-digit number is produced. 
This is only applicable to the natural numbers.
*/

#include "stdafx.h"

#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h> 
using namespace std;

int digital_root(int n)
{
	//convert to string 
	string hold_str;
	hold_str = to_string(n);  
	//add all digits to the vector
	vector <int> digits;
	for (char x : hold_str) {
		int hold_int = 0;
		//magic; cast to ASCII, minus 0 to get the int.
		hold_int = (int)x - '0';
		digits.push_back(hold_int);
	}

	int total = 0;
	//add all digits together
	for (int y : digits) {
		total = total + y;
	}

	//recursively call if above 10
	if (total >= 10) { return digital_root(total); }
	else { return total; }

	return total;
}