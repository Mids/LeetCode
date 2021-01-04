//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_46_PERMUTATIONS_H
#define LEETCODE_46_PERMUTATIONS_H
using namespace std;

class Solution {
public:
	int size;
	vector<int> *input;
	vector<vector<int>> result;

	vector<vector<int>> permute(vector<int> &nums) {
		input = &nums;

		size = input->size();
		perm(0);

		return result;
	}

	void perm(int i) {
		if (i == size) {
			result.push_back(*new vector<int>(*input));
		}

		for (int j = i; j < size; j++) {
			swap(i, j);
			perm(i + 1);
			swap(i, j);
		}
	}

	void swap(int i, int j) {
		int temp = (*input)[i];
		(*input)[i] = (*input)[j];
		(*input)[j] = temp;
	}
};


#endif //LEETCODE_46_PERMUTATIONS_H
