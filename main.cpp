#include <iostream>
#include <vector>
#include "344. Reverse String.h"

using namespace std;

int main() {
	Solution s;

	vector<char> arr = {'h','e','l','l','o'};
	vector<int> arr2 = {2, 2};

	vector<vector<int>> board = {{5,  1,  9,  11},
								 {2,  4,  8,  10},
								 {13, 3,  6,  7},
								 {15, 14, 12, 16}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

//	auto a = s.numRescueBoats(arr, 3);

	s.	reverseString(arr);
	for (auto c : arr) {
		cout << c << ' ';
	}


//	for (auto v : a) {
//		cout << v << ' ';
//	}

//	for (auto vv : board2) {
//		for (auto v : vv) {
//			cout << v << ' ';
//		}
//		cout << endl;
//	}


	return 0;
}