#include <iostream>
#include <vector>
#include "1539. Kth Missing Positive Number.h"

using namespace std;

int main() {
	Solution s;

	vector<int> arr = {2,3,4,7,11};
	cout << s.findKthPositive(arr,5);

	return 0;
}