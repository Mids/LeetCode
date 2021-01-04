#include <iostream>
#include <vector>
#include "1402. Reducing Dishes.h"

using namespace std;

int main() {
	Solution s;

	vector<int> grid = {-1, -8, 0, 5, -9};

	cout << s.maxSatisfaction(grid) << endl;

	return 0;
}