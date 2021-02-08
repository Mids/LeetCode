//
// Created by jin on 2/8/2021.
//

#ifndef LEETCODE_141_LINKED_LIST_CYCLE_H
#define LEETCODE_141_LINKED_LIST_CYCLE_H

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}
};

// walker faster algorithm
class Solution {
public:
	bool hasCycle(ListNode *head) {
		if (head == nullptr) return false;

		ListNode *cur = head;
		ListNode *fast = head;

		while (fast->next != nullptr && fast->next->next != nullptr) {
			cur = cur->next;
			fast = fast->next->next;
			if (cur == fast) return true;
		}

		return false;
	}
};


// the least space solution
//class Solution {
//public:
//	bool hasCycle(ListNode *head) {
//		int n = 0;
//
//		while (head != nullptr) {
//			if (++n > 10000) return true;
//			head = head->next;
//		}
//
//		return false;
//	}
//};


// Constant Solution rough
//class Solution {
//public:
//	int map[200000] = {0};
//
//	bool hasCycle(ListNode *head) {
//		ListNode * cur = head;
//
//		while (cur != nullptr) {
//			int key = cur-head + 100000;
//
//			if(map[key] == 1)
//				return true;
//			map[key] = 1;
//			cur = cur->next;
//		}
//
//		return false;
//	}
//};

#endif //LEETCODE_141_LINKED_LIST_CYCLE_H
