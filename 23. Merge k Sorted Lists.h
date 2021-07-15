//
// Created by jin on 7/15/2021.
//

#ifndef LEETCODE_23_MERGE_K_SORTED_LISTS_H
#define LEETCODE_23_MERGE_K_SORTED_LISTS_H


#include <queue>

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
	bool operator()(ListNode* l, ListNode* r){
		return l->val > r->val;
	}

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head, *cur;
		cur = &head;
		std::priority_queue<ListNode*, vector<ListNode*>, Solution> pq;

		for (auto &l : lists) {
			while (l) {
				pq.push(l);
				l = l->next;
			}
		}

		while(!pq.empty()){
			cur->next = pq.top();
			cur = cur->next;
			cur->next = nullptr;
			pq.pop();
		}

		return head.next;
	}
};

// 484 ms
class Solution1 {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode head, *cur;
		cur = &head;
		int size = lists.size();

		while (true) {
			int min = INT_MAX;
			int minIndex = 0;

			for (int i = 0; i < size; ++i) {
				auto& l = lists[i];
				if (l == nullptr) continue;
				if (l->val < min) {
					min = l->val;
					minIndex = i;
				}
			}

			if(min == INT_MAX) break;

			cur->next = lists[minIndex];
			cur = cur->next;
			lists[minIndex] = cur->next;
		}

		return head.next;
	}
};

#endif //LEETCODE_23_MERGE_K_SORTED_LISTS_H
