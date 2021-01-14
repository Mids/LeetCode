#include <iostream>
#include <vector>
#include "881. Boats to Save People.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {3,2,2,1};
	vector<int> arr2 = {2, 2};

//	auto a = s.numRescueBoats(arr, 3);

	cout << s.numRescueBoats(arr,3);


//	for (auto v : a) {
//		cout << v << ' ';
//	}


	return 0;
}