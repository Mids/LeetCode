#include <iostream>
#include <vector>
#include "189. Rotate Array.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {1, 2, 3, 4, 5, 6};
	vector<int> arr2 = {-1, -100, 3, 99};

	s.rotate(arr, 4);

	for (auto a:arr) {
		cout << a << '\t';
	}

	return 0;
}