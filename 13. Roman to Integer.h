//
// Created by jin on 2/22/2021.
//

#ifndef LEETCODE_13_ROMAN_TO_INTEGER_H
#define LEETCODE_13_ROMAN_TO_INTEGER_H

using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		int size = s.size();
		int result = 0;

		bool cUp = false, xUp = false, iUp = false;

		for (int i = 0; i < size; ++i) {

			if (s[i] == 'M') {
				result += 1000;
				if (cUp) result -= 200;
			}

			if (s[i] == 'D') {
				result += 500;
				if (cUp) result -= 200;
			}

			if (s[i] == 'C') {
				cUp = true;
				result += 100;
				if (xUp) result -= 20;
			}

			if (s[i] == 'L') {
				result += 50;
				if (xUp) result -= 20;
			}

			if (s[i] == 'X') {
				xUp = true;
				result += 10;
				if (iUp) result -= 2;
			}

			if (s[i] == 'V') {
				result += 5;
				if (iUp) result -= 2;
			}

			if (s[i] == 'I') {
				iUp = true;
				result += 1;
			}
		}

		return result;
	}
};

#endif //LEETCODE_13_ROMAN_TO_INTEGER_H
