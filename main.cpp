#include <iostream>
#include <vector>
#include "350. Intersection of Two Arrays II.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {1, 2, 2, 1};
	vector<int> arr2 = {2, 2};

	auto a = s.intersect(arr, arr2);

	for (auto v : a) {
		cout << v << ' ';
	}


	return 0;
}