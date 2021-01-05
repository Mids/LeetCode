//
// Created by jin on 1/5/2021.
//

#ifndef LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
#define LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H

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
	ListNode *deleteDuplicates(ListNode *head) {
		if (head == nullptr || head->next == nullptr)
			return head;

		ListNode HEAD(0, head);
		ListNode *prev = &HEAD;
		ListNode *cur = head;

		int dup = -111;

		while (cur != nullptr) {
			if (dup == cur->val) {
				prev->next = cur->next;
				cur = cur->next;
				continue;
			} else {
				dup = -111;
			}

			if (cur->next == nullptr) {
				break;
			}

			if (cur->val == cur->next->val) {
				dup = cur->val;
				prev->next = cur->next;
				cur = cur->next;
				continue;
			}


			prev = cur;
			cur = cur->next;
		}

		return HEAD.next;
	}


	void print(ListNode *listNode) {
		while (listNode != nullptr) {
			cout << listNode->val << '\t';
			listNode = listNode->next;
		}
		cout << endl;
	}
};


#endif //LEETCODE_82_REMOVE_DUPLICATES_FROM_SORTED_LIST_II_H
