//
// Created by jin on 2/8/2021.
//

#ifndef LEETCODE_234_PALINDROME_LINKED_LIST_H
#define LEETCODE_234_PALINDROME_LINKED_LIST_H

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
	int size = 2;
	int half = 1;
	bool isOdd = false;

	bool isPalindrome(ListNode *head) {
		if (head == nullptr || head->next == nullptr) return true;
		if (head->next->next == nullptr) return head->val == head->next->val;

		ListNode *cur = head->next;
		while (cur->next != nullptr) {
			++size;
			cur = cur->next;
		}
		if (size % 2 == 1) isOdd = true;
		half = size / 2;

		if (IsPalindromeRecursive(head, 2) && head->val == head->next->val) {
			return true;
		}

		return false;
	}

	bool IsPalindromeRecursive(ListNode *head, int cur) {
		if (cur * 2 >= size) {
			if (isOdd) {
				head->next = head->next->next;
				return true;
			} else {
				if (head->next->val == head->next->next->val) {
					head->next = head->next->next->next;
					return true;
				} else {
					return false;
				}
			}
		}

		if (!IsPalindromeRecursive(head->next, cur + 1))
			return false;

		if (head->next->val == head->next->next->val) {
			head->next = head->next->next->next;
			return true;
		}

		return false;
	}
};


#endif //LEETCODE_234_PALINDROME_LINKED_LIST_H
