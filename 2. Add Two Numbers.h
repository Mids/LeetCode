//
// Created by jin on 3/22/2021.
//

#ifndef LEETCODE_2_ADD_TWO_NUMBERS_H
#define LEETCODE_2_ADD_TWO_NUMBERS_H

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		ListNode HEAD;
		ListNode *cur = &HEAD;
		int carry = 0;

		while (cur) {
			auto val = l1->val + l2->val + carry;
			carry = val > 9 ? val -= 10, 1 : 0;

			l1->val = val;

			cur->next = l1;
			cur = l1;

			if (l1->next == nullptr && l2->next == nullptr) {
				break;
			} else if (l1->next == nullptr) {
				l1 = l2->next;
				l2->next = nullptr;
				l2->val = 0;
			} else if (l2->next == nullptr) {
				l1 = l1->next;
				l2->val = 0;
			} else {
				l1 = l1->next;
				l2 = l2->next;
			}
		}

		if (carry) {
			auto *data = new ListNode(1);
			cur->next = data;
		}

		return HEAD.next;
	}
};

#endif //LEETCODE_2_ADD_TWO_NUMBERS_H
