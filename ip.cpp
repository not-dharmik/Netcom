#include <bits/stdc++.h>
using namespace std;

// Function to check if the given string S is IPv4 or not
bool checkIPv4(string s)
{
	
	int dot = 0;

	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '.')
			dot++;
	}

	if (dot != 3)
		return false;

	vector <string> tokens;

	// stringstream class check1
	stringstream check1(s);
	string intermediate;

	// Tokenizing w.r.t. '.'
	while (getline(check1, intermediate, '.')) {
		tokens.push_back(intermediate);
	}

	if (tokens.size() != 4)
		return false;

	// Check if all the tokenized strings lies in the range [0, 255]
	for (int i = 0; i < tokens.size(); i++) {
		int num = 0;

		// Base Case
		if (tokens[i] == "0")
			continue;

		if (tokens[i].size() == 0)
			return false;

		for (int j = 0; j < tokens[i].size(); j++) {
			if (tokens[i][j] > '9' || tokens[i][j] < '0')
				return false;

			num *= 10;
			num += tokens[i][j] - '0';

			if (num == 0)
				return false;
		}

		if (num > 255 || num < 0)
			return false;
	}

	return true;
}


bool checkHex(string s)
{
	// Size of string s
	int n = s.length();

	// Iterate over string
	for (int i = 0; i < n; i++) {
		char ch = s[i];

		// Check if the character
		// is invalid
		if ((ch < '0' || ch > '9')
			&& (ch < 'A' || ch > 'F')
			&& (ch < 'a' || ch > 'f')) {
			return false;
		}
	}

	return true;
}

// Function to check if the given
// string S is IPv6 or not
bool checkIPv6(string s)
{
	
	int dot = 0;

	for (int i = 0; i < s.size();i++) {
		if (s[i] == ':')
			dot++;
	}

	if (dot != 7)
		return false;

	vector <string> tokens;

	stringstream check1(s);
	string intermediate;

	while (getline(check1,intermediate, ':')) {
		tokens.push_back(intermediate);
	}

	if (tokens.size() != 8)
		return false;

	
	for (int i = 0;
		i < tokens.size(); i++) {

		int len = tokens[i].size();

		if (!checkHex(tokens[i])
			|| len > 4 || len < 1) {
			return false;
		}
	}
	return true;
}

void checkIP(string s)
{
	if (checkIPv4(s))
		cout << "IPv4";

	else if (checkIPv6(s))
		cout << "IPv6";

	else
		cout << "0";
}

int main()
{
	string S;
	cin >> S;
	checkIP(S);
	return 0;
}
