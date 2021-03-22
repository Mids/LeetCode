//
// Created by jin on 3/22/2021.
//

#ifndef LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_H
#define LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_H

#include <unordered_map>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int x) : val(x), next(NULL) {}

	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	// 40ms
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		auto a = headA, b = headB;
		int aCount = 0, bCount = 0;

		while (a) {
			a = a->next;
			++aCount;
		}

		while (b) {
			b = b->next;
			++bCount;
		}

		a = headA;
		b = headB;

		if (aCount > bCount)
			while (aCount-- > bCount) a = a->next;
		else
			while (bCount-- > aCount) b = b->next;


		while (a != b) {
			a = a->next;
			b = b->next;
		}

		return a;
	}

	// 56ms
	ListNode *getIntersectionNode2(ListNode *headA, ListNode *headB) {
		unordered_map<ListNode *, bool> addrMap;

		auto curA = headA;

		while (curA) {
			addrMap[curA] = true;
			curA = curA->next;
		}

		auto curB = headB;
		while (curB) {
			if (addrMap.count(curB) > 0)
				return curB;
			curB = curB->next;
		}

		return 0;
	}
};

#endif //LEETCODE_160_INTERSECTION_OF_TWO_LINKED_LISTS_H
