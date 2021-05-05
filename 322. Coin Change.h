//
// Created by Jin on 5/5/2021.
//

#ifndef LEETCODE_322_COIN_CHANGE_H
#define LEETCODE_322_COIN_CHANGE_H

#include <climits>

using namespace std;

class Solution {
public:
	int coinChange(vector<int> &coins, int amount) {
		if (amount == 0) return 0;

		vector<int> result(amount + 1, INT_MAX);
		vector<int> newCoins;

		for (auto &c:coins) {
			if (c < amount && result[c] != 1) {
				result[c] = 1;
				newCoins.push_back(c);
			} else if (c == amount) {
				return 1;
			}
		}

		for (int i = 2; i <= amount; ++i) {
			for (auto &c : newCoins) {
				if (i - c > 0 && result[i - c] < INT_MAX) {
					result[i] = min(result[i], result[i - c] + 1);
				}
			}
		}

		return result[amount] < INT_MAX ? result[amount] : -1;
	}
};

#endif //LEETCODE_322_COIN_CHANGE_H
