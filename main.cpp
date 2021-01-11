#include <iostream>
#include <vector>
#include "26. Remove Duplicates from Sorted Array.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {0,0,1,1,1,2,2,3,3,4};

	cout << s.removeDuplicates(arr) << endl;

	return 0;
}