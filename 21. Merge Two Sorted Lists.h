//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
#define LEETCODE_21_MERGE_TWO_SORTED_LISTS_H

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
	ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;

		auto i = l1;
		auto j = l2;

		auto head = new ListNode();
		auto result = head;

		while (i != nullptr || j != nullptr) {
			if (i == nullptr) {
				result->next = j;
				j = j->next;
				result = result->next;
				continue;
			}

			if (j == nullptr || i->val < j->val) {
				result->next = i;
				i = i->next;
				result = result->next;
				continue;
			}

			result->next = j;
			j = j->next;
			result = result->next;
		}

		return head->next;
	}
};

#endif //LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
