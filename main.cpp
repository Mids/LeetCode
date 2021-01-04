#include <iostream>
#include <vector>
#include "21. Merge Two Sorted Lists.h"

using namespace std;

void print(ListNode *listNode) {
	auto node = listNode;
	while (true) {
		cout << node->val << '\t';

		if (node->next == nullptr)
			break;

		node = node->next;
	}

	cout << endl;
}

int main() {
	Solution s;

	ListNode l1(1, new ListNode(2, new ListNode(4)));
	ListNode l2(1, new ListNode(3, new ListNode(4)));

	print(&l1);
	print(&l2);

	print(s.mergeTwoLists(&l1, &l2));


	return 0;
}