#include <iostream>
#include <vector>

using namespace std;

//find the sum of digits, recursively call until no more digits are left.  
// EX: 16 ->  1 + 6 = 7.

int digital_root(int n) {

	vector <int> digits;
	//add all digits to the vector
	while (n != 0) {
		// store last digit
		int temp = n % 10;
		//save digit
		digits.push_back(temp);
		// kill digit
		n = n / 10;
	}

	int total = 0;
	//add digits together
	for (int x : digits) {
		total = x + total;
	}
	//recursively call if above 10
	if (total >= 10) { digital_root(total); }
	else { return total; }
}

int main() {
	
	cout << digital_root(17);

	//int wait;
	//cin >> wait;

	return 0;
}
