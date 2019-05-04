#include "KMP.h"
#include "prefix.h"

int doubleNum(int a) {
	return a * 2;
}

string KMP(string P, string T) {
	string positions;
	stringstream output;
	int size = P.length();
	P += "@";
	P += T;
	auto result = prefix(P);
	for (int i = 0; i < P.length(); i++) {
		if (result[i] == size) {
			output << i - 2 * size << ",";

		}
	}
	positions = output.str();
	if (positions.length() == 0) {
		positions += "-1";
	}
	else {
		positions = positions.substr(0, positions.length() - 1);
		positions;
	}
	return positions;
}