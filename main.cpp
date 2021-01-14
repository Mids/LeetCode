#include <iostream>
#include <vector>
#include "66. Plus One.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {1, 2, 2, 1};
	vector<int> arr2 = {2, 2};

	auto a = s.plusOne(arr);

	for (auto v : a) {
		cout << v << ' ';
	}


	return 0;
}