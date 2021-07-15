//
// Created by jin on 7/15/2021.
//

#ifndef LEETCODE_148_SORT_LIST_H
#define LEETCODE_148_SORT_LIST_H

#include <queue>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode() : val(0), next(nullptr) {}

	ListNode(int x) : val(x), next(nullptr) {}

	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// O(n) Space. O(1) solution is too dirty and inefficient.
class Solution {
public:
	bool operator()(ListNode *l, ListNode *r) {
		return l->val > r->val;
	}

	ListNode *sortList(ListNode *head) {
		priority_queue<ListNode *, vector<ListNode *>, Solution> pq;

		while (head) {
			pq.push(head);
			head = head->next;
		}

		ListNode result;
		ListNode *cur;
		cur = &result;

		while (!pq.empty()) {
			cur->next = pq.top();
			cur = cur->next;
			cur->next = nullptr;
			pq.pop();
		}

		return result.next;
	}
};

#endif //LEETCODE_148_SORT_LIST_H
