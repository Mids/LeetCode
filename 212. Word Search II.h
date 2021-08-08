//
// Created by jin on 8/8/2021.
//

#ifndef LEETCODE_212_WORD_SEARCH_II_H
#define LEETCODE_212_WORD_SEARCH_II_H

using namespace std;

class Solution {
public:
	int rowSize, colSize;
	int map[26] = {0};

	vector<string> findWords(vector<vector<char>> &board, vector<string> &words) {
		rowSize = board.size();
		colSize = board[0].size();

		vector<string> result;
		result.reserve(words.size());

		for (auto &row : board) {
			for (auto &c : row) {
				++map[c - 'a'];
			}
		}

		for (auto &word : words) {
			bool isFound = false;
			int wordMap[26] = {0};
			for (auto &c:word) {
				if (++wordMap[c - 'a'] > map[c - 'a']) {
					isFound = true;
					break;
				}
			}
			if (isFound)
				continue;

			isFound = false;


			for (int i = 0; !isFound && i < rowSize; ++i) {
				for (int j = 0; !isFound && j < colSize; ++j) {
					if (findChar(board, word, 0, i, j)) {
						isFound = true;
						result.emplace_back(word);
					}
				}
			}
		}

		return result;
	}

	bool findChar(vector<vector<char>> &board, string &word, int index, int i, int j) {
		if (board[i][j] != word[index])
			return false;

		if (word.size() == index + 1)
			return true;

		board[i][j] = 0;

		int ni = i + 1;
		int nj = j;

		if (ni < rowSize) {
			if (findChar(board, word, index + 1, ni, nj)) {
				board[i][j] = word[index];
				return true;
			}
		}

		ni = i - 1;
		if (ni >= 0) {
			if (findChar(board, word, index + 1, ni, nj)) {
				board[i][j] = word[index];
				return true;
			}
		}

		ni = i, nj = j + 1;
		if (nj < colSize)
			if (findChar(board, word, index + 1, ni, nj)) {
				board[i][j] = word[index];
				return true;
			}

		nj = j - 1;
		if (nj >= 0) {
			if (findChar(board, word, index + 1, ni, nj)) {
				board[i][j] = word[index];
				return true;
			}
		}

		board[i][j] = word[index];
		return false;
	}
};

#endif //LEETCODE_212_WORD_SEARCH_II_H
