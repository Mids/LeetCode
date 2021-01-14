#include <iostream>
#include <vector>
#include "36. Valid Sudoku.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {3, 2, 2, 1};
	vector<int> arr2 = {2, 2};

	vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
								  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
								  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
								  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
								  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
								  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
								  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
								  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
								  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

//	auto a = s.numRescueBoats(arr, 3);

	cout << s.isValidSudoku(board);


//	for (auto v : a) {
//		cout << v << ' ';
//	}


	return 0;
}