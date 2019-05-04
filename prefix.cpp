#include "prefix.h"

int* prefix(string input) {
	int n = input.length();
	auto sub_size = new int[n];
	for (size_t i = 0; i < n; i++) {
		sub_size[i] = 0;
	}
	for (size_t i = 1; i < n; i++) {
		int j = sub_size[i - 1];
		while ((j > 0) && (input[i] != input[j])) {
			j = sub_size[j - 1];
		}
		if (input[i] == input[j]) {
			j++;
		}
		sub_size[i] = j;
	}
	return sub_size;
}