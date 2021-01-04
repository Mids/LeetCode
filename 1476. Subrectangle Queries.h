//
// Created by jin on 1/4/2021.
//

#ifndef LEETCODE_1476_SUBRECTANGLE_QUERIES_H
#define LEETCODE_1476_SUBRECTANGLE_QUERIES_H

using namespace std;

class SubrectangleQueries {
public:
	vector<vector<int>> rect;

	SubrectangleQueries(vector<vector<int>> &rectangle) {
		rect = rectangle;
	}

	void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {

		for (int i = row1; i <= row2; i++) {
			for (int j = col1; j <= col2; j++) {
				rect[i][j] = newValue;
			}
		}
	}

	int getValue(int row, int col) {
		return rect[row][col];
	}

	void print() {
		for (int i = 0; i < rect.size(); i++) {

			for (int j = 0; j < rect[i].size(); j++) {
				cout << rect[i][j] << "\t";
			}
			cout << endl;
		}
	}
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */



#endif //LEETCODE_1476_SUBRECTANGLE_QUERIES_H
