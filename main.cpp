#include <iostream>
#include <vector>
#include "116. Populating Next Right Pointers in Each Node.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"flower", "flow", "flight"};
	vector<string> arr2 = {"ab", "a", "ba", "b"};

	vector<int> nums = {1, 3, 5};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  0,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	Node a7(7);
	Node a6(6);
	Node a5(5);
	Node a4(4);
	Node a3(3, &a6, &a7, nullptr);
	Node a2(2, &a4, &a5, nullptr);
	Node a1(1, &a2, &a3, nullptr);

	auto aa = s.connect(&a1);

	while(aa){
		cout << aa->val << ' ';
		if(aa -> next == nullptr)
		{
			aa = aa->left;
			cout << endl;
		}
		else
			aa = aa->next;
	}

	return 0;
}