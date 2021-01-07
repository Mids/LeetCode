//
// Created by jin on 1/6/2021.
//

#ifndef LEETCODE_1539_KTH_MISSING_POSITIVE_NUMBER_H
#define LEETCODE_1539_KTH_MISSING_POSITIVE_NUMBER_H

using namespace std;

class Solution {
public:
	int findKthPositive(vector<int>& arr, int k) {
		int arrIndex = 0;
		int resultIndex = 0;
		int size = arr.size();

		for(int i=1;i<1001;i++)
		{
			if (arrIndex < size && arr[arrIndex] == i) {
				arrIndex++;
			} else{
				resultIndex++;
			}

			if (resultIndex == k) {
				return i;
			}
		}

		return 0;
	}
};


#endif //LEETCODE_1539_KTH_MISSING_POSITIVE_NUMBER_H
