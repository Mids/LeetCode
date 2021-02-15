#include <iostream>
#include <vector>
#include "121. Best Time to Buy and Sell Stock.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a"};

	vector<int> nums = {7, 1, 5, 3, 6, 4};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  4,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};


	cout << s.maxProfit(nums);

//	ListNode* head = &a;
//




	return 0;
}