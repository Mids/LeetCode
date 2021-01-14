#include <iostream>
#include <vector>
#include "283. Move Zeroes.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {0,1,0,3,12};
	vector<int> arr2 = {2, 2};

	s.moveZeroes(arr);

	for (auto v : arr) {
		cout << v << ' ';
	}


	return 0;
}