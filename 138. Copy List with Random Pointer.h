//
// Created by jin on 7/15/2021.
//

#ifndef LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER_H
#define LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER_H

using namespace std;

#include <unordered_map>

class Node {
public:
	int val;
	Node *next;
	Node *random;

	Node(int _val, Node *next, Node *random) : val(_val), next(next), random(random) {

	};

	Node(int _val, Node *next) : val(_val), next(next) {

	};

	Node(int _val) {
		val = _val;
		next = NULL;
		random = NULL;
	}
};

class Solution {
public:
	Node *copyRandomList(Node *head) {
		if (head == nullptr) return head;

		Node *cur = head;
		while (cur) {
			Node *newNode = new Node(cur->val, cur->next, cur->random);
			cur->next = newNode;
			cur = cur->next->next;
		}

		cur = head->next;
		while (cur) {
			if (cur->random)
				cur->random = cur->random->next;

			if (cur->next)
				cur = cur->next->next;
			else
				break;
		}

		cur = head;
		Node *newHead = cur->next;
		while (cur) {
			Node *newNode = cur->next;
			cur->next = newNode->next;
			if(cur->next)
				newNode->next = cur->next->next;

			cur = cur->next;
		}

		return newHead;
	}
};

// using more space
class Solution1 {
public:
	Node *copyRandomList(Node *head) {
		if (head == nullptr) return head;
		vector<Node *> v;
		unordered_map < Node * , int > map;

		Node *cur = head;
		int size = 0;
		while (cur) {
			Node *newNode = new Node(cur->val, nullptr, cur->random);
			v.push_back(newNode);
			map[cur] = size++;
			cur = cur->next;
		}

		for (auto i = 0; i < size; ++i) {
			if (i + 1 < size) {
				v[i]->next = v[i + 1];
			}
			if (v[i]->random != nullptr)
				v[i]->random = v[map[v[i]->random]];
		}

		return v[0];
	}
};

#endif //LEETCODE_138_COPY_LIST_WITH_RANDOM_POINTER_H
