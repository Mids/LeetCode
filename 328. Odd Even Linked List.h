//
// Created by jin on 3/22/2021.
//

#ifndef LEETCODE_328_ODD_EVEN_LINKED_LIST_H
#define LEETCODE_328_ODD_EVEN_LINKED_LIST_H

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
	ListNode *oddEvenList(ListNode *head) {
		if (head == nullptr || head->next == nullptr || head->next->next == nullptr) return head;
		ListNode *even = head->next;
		ListNode *evenCur = even;
		ListNode *oddCur = head;

		while (oddCur) {
			auto temp = oddCur->next;

			if (temp == nullptr) {
				oddCur->next = even;
				evenCur->next = temp;
				break;
			}
			oddCur->next = oddCur->next->next;
			evenCur->next = temp;

			if (oddCur->next == nullptr) {
				oddCur->next = even;
				break;
			}

			oddCur = oddCur->next;
			evenCur = evenCur->next;
		}

		return head;
	}
};


#endif //LEETCODE_328_ODD_EVEN_LINKED_LIST_H
