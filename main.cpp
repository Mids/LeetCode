#include <iostream>
#include <vector>
#include "378. Kth Smallest Element in a Sorted Matrix.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"oath", "pea", "eat", "rain", "thfi"};
	vector<string> arr2 = {"hot", "dot", "dog", "lot", "log", "cog"};

	vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{1,3,5},
								 {6,7,12},
								 {11,14,14}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	vector<vector<char>> grid = {{'o', 'a', 'a', 'n'},
								 {'e', 't', 'a', 'e'},
								 {'i', 'h', 'k', 'r'},
								 {'i', 'f', 'l', 'v'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};


	cout << s.kthSmallest(board, 3);


	return 0;
}