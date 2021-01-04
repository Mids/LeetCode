#include <iostream>
#include <vector>
#include "1689. Partitioning Into Minimum Number Of Deci-Binary Numbers.h"

using namespace std;

int main() {
	Solution s;

	cout << s.minPartitions("32") << endl;
	cout << s.minPartitions("82734") << endl;
	cout << s.minPartitions("27346209830709182346") << endl;

	return 0;
}
