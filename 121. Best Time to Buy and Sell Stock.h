//
// Created by jin on 2/15/2021.
//

#ifndef LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
#define LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H

using namespace std;

class Solution {
public:
	int maxProfit(vector<int> &prices) {
		int low = prices[0], size = prices.size();
		int result = 0;

		for (int i = 1; i < size; ++i) {
			low = min(low, prices[i]);
			result = max(result, prices[i] - low);
		}

		return result;
	}
};

#endif //LEETCODE_121_BEST_TIME_TO_BUY_AND_SELL_STOCK_H
