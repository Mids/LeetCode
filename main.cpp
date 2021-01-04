#include <iostream>
#include <vector>
#include "42. Trapping Rain Water.h"

using namespace std;

int main() {
	Solution s;

	vector<int> input = {4,2,0,3,2,5};
	vector<int> input2 = {0,1,0,2,1,0,1,3,2,1,2,1};
	vector<int> input3 = {1};

	cout << s.trap(input) << endl;
	cout << s.trap(input2) << endl;
	cout << s.trap(input3) << endl;

	return 0;
}