//
// Created by jin on 7/5/2021.
//

#ifndef LEETCODE_227_BASIC_CALCULATOR_II_H
#define LEETCODE_227_BASIC_CALCULATOR_II_H

using namespace std;

class Solution {
public:
	int calculate(string s) {
		s.erase(std::remove(s.begin(), s.end(), ' '), s.end());

		int size = s.size();

		int num = 0;
		vector<int> nums;
		vector<char> ops;

		for (int i = 0; i < size; ++i) {
			if (s[i] < '0') {
				nums.push_back(num);
				ops.push_back(s[i]);
				num = 0;
			} else {
				num = num * 10 - '0' + s[i];
			}
		}
		nums.push_back(num);

		int opNum = ops.size();

		for (int i = 0; i < opNum;) {
			if (ops[i] == '*') {
				nums[i] *= nums[i + 1];
				nums.erase(nums.begin() + i + 1);
				ops.erase(ops.begin() + i);
				--opNum;
			} else if (ops[i] == '/') {
				nums[i] /= nums[i + 1];
				nums.erase(nums.begin() + i + 1);
				ops.erase(ops.begin() + i);
				--opNum;
			} else {
				++i;
			}
		}


		int sum = nums[0];

		for (int i = 0; i < opNum; ++i) {
			if (ops[i] == '-')
				sum -= nums[i + 1];
			else
				sum += nums[i + 1];
		}


		return sum;
	}
};

#endif //LEETCODE_227_BASIC_CALCULATOR_II_H
