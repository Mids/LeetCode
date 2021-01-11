#include <iostream>
#include <vector>
#include "88. Merge Sorted Array.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {2, 0};
	vector<int> arr2 = {1};

	s.merge(arr, 1, arr2, 1);

	for (auto a : arr)
		cout << a << '\t';

	return 0;
}