#include <iostream>
#include <vector>
#include "1. Two Sum.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {2,7,11,15};
	vector<int> arr2 = {2, 2};

	auto a = s.twoSum(arr, 9);

	for (auto v : a) {
		cout << v << ' ';
	}


	return 0;
}