//
// Created by jin on 5/17/2021.
//

#ifndef LEETCODE_171_EXCEL_SHEET_COLUMN_NUMBER_H
#define LEETCODE_171_EXCEL_SHEET_COLUMN_NUMBER_H

using namespace std;

class Solution {
public:
	int titleToNumber(string columnTitle) {
		int result = 0;
		for (auto c : columnTitle) {
			result *= 26;
			result += c - 'A' + 1;
		}

		return result;
	}
};

#endif //LEETCODE_171_EXCEL_SHEET_COLUMN_NUMBER_H
