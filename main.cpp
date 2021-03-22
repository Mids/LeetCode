#include <iostream>
#include <vector>
#include "328. Odd Even Linked List.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1, 3, 5, 0, 0, 0};
	vector<int> nums1 = {2, 4, 6};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  0,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	ListNode c(6);
	ListNode b(4);
	ListNode a(2,&b);
	ListNode f(4, &a);
	ListNode e(6,&f);
	ListNode d(5,&e);

	auto aa=  s.oddEvenList(&d);

	while(aa){
		cout << aa->val << '\t';
		aa = aa->next;
	}

	return 0;
}