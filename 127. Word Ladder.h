//
// Created by jin on 7/21/2021.
//

#ifndef LEETCODE_127_WORD_LADDER_H
#define LEETCODE_127_WORD_LADDER_H

#include <unordered_map>

using namespace std;

class Solution {
	struct WordNode {
		bool isUsedInFront;
		bool isUsedInBack;
		vector<int> candidates;
		int depth;
	};

public:
	unordered_map<string, WordNode *> wordMap;
	vector<WordNode> nodes;
	vector<WordNode *> frontQueue;
	vector<WordNode *> backQueue;

	int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
		bool hasBegin = false;
		for (auto &word : wordList) {
			if (word == beginWord) {
				hasBegin = true;
				break;
			}
		}

		if (!hasBegin)
			wordList.push_back(beginWord);

		int size = wordList.size();
		nodes.resize(size);

		for (int i = 0; i < size; ++i) {
			auto &word = wordList[i];
			wordMap[word] = &nodes[i];
		}
		if (wordMap.count(endWord) == 0)
			return 0;

		for (int i = 0; i < size; ++i) {
			for (int j = i + 1; j < size; ++j) {
				auto &front = wordList[i];
				auto &back = wordList[j];
				if (isCandidate(front, back) == 1) {
					wordMap[front]->candidates.push_back(j);
					wordMap[back]->candidates.push_back(i);
				}
			}
		}

		frontQueue.push_back(wordMap[beginWord]);
		frontQueue[0]->depth = 1;
		frontQueue[0]->isUsedInFront = true;
		backQueue.push_back(wordMap[endWord]);
		backQueue[0]->depth = 1;
		backQueue[0]->isUsedInBack = true;

		for (int index = 0; index < min(frontQueue.size(), backQueue.size()); ++index) {

			auto node = frontQueue[index];
			for (auto c : node->candidates) {
				auto n = wordMap[wordList[c]];
				if (n->isUsedInBack)
					return node->depth + n->depth;

				if (n->isUsedInFront) continue;
				n->isUsedInFront = true;
				n->depth = node->depth + 1;
				frontQueue.push_back(n);
			}

			node = backQueue[index];
			for (auto c : node->candidates) {
				auto n = wordMap[wordList[c]];
				if (n->isUsedInFront)
					return node->depth + n->depth;

				if (n->isUsedInBack) continue;
				n->isUsedInBack = true;
				n->depth = node->depth + 1;
				backQueue.push_back(n);
			}
		}

		return 0;
	}

	int isCandidate(string &a, string &b) {
		int diff = 0;
		int size = a.size();
		for (int i = 0; i < size; ++i) {
			if (a[i] != b[i]) {
				++diff;
			}
		}

		return diff;
	}
};

#endif //LEETCODE_127_WORD_LADDER_H
