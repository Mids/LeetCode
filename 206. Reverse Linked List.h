//
// Created by jin on 2/8/2021.
//

#ifndef LEETCODE_206_REVERSE_LINKED_LIST_H
#define LEETCODE_206_REVERSE_LINKED_LIST_H

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
	ListNode *reverseList(ListNode *head) {
		return reverseListRecursive(head, nullptr);
	}

	ListNode *reverseListRecursive(ListNode *cur, ListNode *target) {
		if (cur == nullptr) return target;

		auto head = reverseListRecursive(cur->next, cur);
		cur->next = target;
		return head;
	}

	ListNode *reverseListIterative(ListNode *head) {
		if (head == nullptr) return head;

		ListNode *prev = nullptr;
		ListNode *cur = head;
		ListNode *next = head->next;


		while (true) {
			cur->next = prev;

			if (next == nullptr) return cur;

			prev = cur;
			cur = next;
			next = next->next;
		}

		return cur;
	}
};


#endif //LEETCODE_206_REVERSE_LINKED_LIST_H
