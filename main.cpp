#include <iostream>
#include <vector>
#include "217. Contains Duplicate.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {1, 1, 1, 3, 3, 4, 3, 2, 4, 2};
	vector<int> arr2 = {-1, -100, 3, 99};

	cout << s.containsDuplicate(arr);


	return 0;
}