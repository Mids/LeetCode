#include <iostream>
#include <vector>
#include "278. First Bad Version.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a"};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  4,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};


	cout << s.firstBadVersion(5);

//	ListNode* head = &a;
//
//	while (head != nullptr) {
//		cout << head->val << '\t';
//		head = head->next;
//	}


	return 0;
}