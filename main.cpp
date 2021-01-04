#include <iostream>
#include <vector>
#include "1476. Subrectangle Queries.h"

using namespace std;

int main() {
	vector<vector<int>> rectangle = {{1, 2, 1},
									 {4, 3, 4},
									 {3, 2, 1},
									 {1, 1, 1}};

	SubrectangleQueries s(rectangle);

	s.print();

	cout << "s.getValue(0,2) : " << s.getValue(0, 2) << endl;

	s.updateSubrectangle(0, 0, 3, 2, 5);

	s.print();

	cout << "s.getValue(0,2) : " << s.getValue(0, 2) << endl;
	cout << "s.getValue(3,1) : " << s.getValue(3, 1) << endl;

	s.updateSubrectangle(3, 0, 3, 2, 10);

	s.print();
	cout << "s.getValue(3,1) : " << s.getValue(3, 1) << endl;
	cout << "s.getValue(0,2) : " << s.getValue(0, 2) << endl;

	return 0;
}
