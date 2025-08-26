#include <iostream>
#include <string>
#include "strextra.h"

using namespace std;

int main() {
	string input;
	string search;

	cout << "Enter a string: ";
	getline(cin, input);

	cout << "Enter a character or string to search for: ";
	getline(cin, search);

	const char* c_input = input.c_str();

	int index;
	if (search.size() == 1) {
		index = find(c_input, search[0]);
	}
	else {
		index = find(c_input, search.c_str());
	}

	if (index == -1) {
		cout << "Not Found." << endl;
	}
	else {
		cout << "Found at position: " << index << endl;
	}

	return 0;
}