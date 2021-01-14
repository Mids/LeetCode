#include <iostream>
#include <vector>
#include "136. Single Number.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {4,1,2,1,2};
	vector<int> arr2 = {-1, -100, 3, 99};

	cout << s.singleNumber(arr);


	return 0;
}