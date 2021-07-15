#include <iostream>
#include <vector>
#include "148. Sort List.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1,8,6,2,5,4,8,3,7};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{0, 1, 0},
								 {0, 0, 1},
								 {1, 1, 1},
								 {0, 0, 0}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	vector<vector<char>> grid = {{'A', 'B', 'C', 'E'},
								 {'S', 'F', 'C', 'S'},
								 {'A', 'D', 'E', 'E'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};

	ListNode* h = new ListNode(6);
	ListNode* g = new ListNode(2, h);

	ListNode* f = new ListNode(-1);
	ListNode* e = new ListNode(-2, f);

	ListNode* d = new ListNode(3);
	ListNode* c = new ListNode(1, d);
	ListNode* b = new ListNode(2, c);
	ListNode* a = new ListNode(4, b);

	auto r = s.sortList(a);

	while (r) {
		cout << r->val << ' ';
		r = r->next;
	}

	return 0;
}