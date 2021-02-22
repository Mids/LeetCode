#include <iostream>
#include <vector>
#include "384. Shuffle an Array.h"

using namespace std;

int main() {
//	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a"};

	vector<int> nums = {1,2,3};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  4,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	Solution* obj = new Solution(nums);

	vector<int> param_1 = obj->reset();

	for (auto i : param_1) {
		cout << i << '\t';
	}
	cout << '\n';
	vector<int> param_2 = obj->shuffle();

	for (auto i : param_2) {
		cout << i << '\t';
	}
	cout << '\n';

//	cout << s.rob(nums);

//	ListNode* head = &a;
//




	return 0;
}