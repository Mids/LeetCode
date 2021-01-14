//
// Created by jin on 1/14/2021.
//

#ifndef LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
#define LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int size = prices.size();
		int prev = prices[0];
		int result = 0;

		for (int i = 1; i < size; ++i) {
			int gap = prices[i] - prev;

			if (gap > 0) {
				result += gap;
			}

			prev = prices[i];
		}

		return result;
	}
};


#endif //LEETCODE_122_BEST_TIME_TO_BUY_AND_SELL_STOCK_II_H
