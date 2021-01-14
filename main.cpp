#include <iostream>
#include <vector>
#include "122. Best Time to Buy and Sell Stock II.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {7, 1, 5, 3, 6, 4};
	vector<int> arr2 = {1};

	cout << s.maxProfit(arr) << endl;

	return 0;
}