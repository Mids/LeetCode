//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_526_BEAUTIFUL_ARRANGEMENT_H
#define LEETCODE_526_BEAUTIFUL_ARRANGEMENT_H


class Solution {
public:
	int result = 0;
	int pArray[16][16] = {0};
	int resultArray[16] = {0};


	int countArrangement(int n) {

		for (int row = 1; row <= n; row++) {

			for (int col = 1; col <= n; col++) {

				if (row % col == 0 || col % row == 0)
					pArray[row][col] = 1;

			}
		}


		for (int i = 1; i <= n; i++)
			resultArray[i] = i;


		perm(1, n);

		return result;
	}


	void perm(int i, int n) {
		if (i > n) {
			result++;
			return;
		}


		for (int j = i; j <= n; j++) {
			if (pArray[i][resultArray[j]] == 0)
				continue;


			swap(i, j);

			perm(i + 1, n);

			swap(i, j);
		}

	}


	void swap(int i, int j) {
		int temp = resultArray[i];
		resultArray[i] = resultArray[j];
		resultArray[j] = temp;
	}
};


#endif //LEETCODE_526_BEAUTIFUL_ARRANGEMENT_H
