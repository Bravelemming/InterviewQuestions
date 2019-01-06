//find substrings of size k, with k distinct characters.

//current status: broken!

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> subStringsKDist(string inputStr, int num)
{

	//return object
	vector<string> subStrings;

	//temp string minus stuff
	string tempString = inputStr; \

		//temp string to add to vector
		string tempStringAdd;

	//iterate for every unique character
	for (char x : tempString) {

		//check for duplicates
		//TODO:

		tempStringAdd.push_back(x);

		//stop after string is 'num' long 
		if (tempStringAdd.size() == num) {
			subStrings.push_back(tempStringAdd);
			break;
		}


	}


	if (!subStrings.empty()) {
		//return subStrings, our vector of strings.
		return subStrings;
	}

	else {
		//if no string exists that has k distinct characters, 
		//output an empty list
		vector <string> emptyList;
		return emptyList;
	};


}


int main() {

	//start conditions
	vector<string> outputs;
	
	//outputs
	outputs = subStringsKDist( "abcd", 3);

	
	
	//output and check
	for (string x : outputs) {
		cout << x << endl;
	};

	//pause for VS console
	int wait;
	cin >> wait;

	return 0;
}


