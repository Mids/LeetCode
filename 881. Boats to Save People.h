//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_881_BOATS_TO_SAVE_PEOPLE_H
#define LEETCODE_881_BOATS_TO_SAVE_PEOPLE_H

#include <algorithm>

using namespace std;

class Solution {
public:
	int numRescueBoats(vector<int> &people, int limit) {
		int size = people.size();

		sort(people.begin(), people.end());

		int i = size - 1;
		for (int j = 0; i >= j; --i) {
			if (people[i] + people[j] <= limit)
				++j;
		}

		return size - i - 1;
	}
};

#endif //LEETCODE_881_BOATS_TO_SAVE_PEOPLE_H
