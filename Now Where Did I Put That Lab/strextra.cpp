#include "strextra.h"
#include <cstring>

//Finding a single Character in a c-string
int find(const char str[], char ch) {
	if (!str) return -1;
	for (int i = 0; str[i] != '\0'; ++i) {
		if (str[i] == ch) return i;
	}
	return -1;
}

int find(const char str[], const char sub[]) {
	if (!str || !sub) return -1;

	int lenStr = std::strlen(str);
	int lenSub = std::strlen(sub);

	if (lenSub == 0 || lenSub > lenStr) return -1;

	for (int i = 0; i <= lenStr - lenSub; ++i) {
		int j = 0;
		while (j < lenSub && str[i + j] == sub[j]) {
			j++;
		}
		if (j == lenSub) return i;
	}
	return -1;
}