#include <iostream>
#include <vector>
#include "155. Min Stack.h"

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

	MinStack* obj = new MinStack();
	obj->push(3);
	obj->push(4);
	obj->pop();
	int param_3 = obj->top();
	int param_4 = obj->getMin();

	cout << param_3 << '\t' << param_4;

//	cout << s.rob(nums);

//	ListNode* head = &a;
//




	return 0;
}