#include <iostream>
#include <vector>
#include "84. Largest Rectangle in Histogram.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"cat", "cats", "and", "sand", "dog"};
	vector<string> arr2 = {"hot", "dot", "dog", "lot", "log", "cog"};

	vector<int> nums = {2,1,5,6,2,3};
	vector<int> nums1 = {2, 2,2};

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


	auto a = s.largestRectangleArea(nums);

		cout << a << endl;



	return 0;
}