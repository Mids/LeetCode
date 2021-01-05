//
// Created by jin on 1/5/2021.
//

#ifndef LEETCODE_688_KNIGHT_PROBABILITY_IN_CHESSBOARD_H
#define LEETCODE_688_KNIGHT_PROBABILITY_IN_CHESSBOARD_H

using namespace std;

class Solution {
public:
	int size;
	double P[101][25][25] = {0};

	double knightProbability(int N, int K, int r, int c) {
		size = N;

		P[0][r][c] = 1;

		for (int i = 1; i <= K; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					P[i][j][k] = getP(i, j, k);
				}
			}
		}

		double result = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				result += P[K][i][j];
			}
		}

		return result;

	}

	double getP(int i, int x, int y) {
		return getPrevP(i, x - 2, y - 1)
			   + getPrevP(i, x - 1, y - 2)
			   + getPrevP(i, x - 2, y + 1)
			   + getPrevP(i, x - 1, y + 2)
			   + getPrevP(i, x + 1, y + 2)
			   + getPrevP(i, x + 2, y + 1)
			   + getPrevP(i, x + 1, y - 2)
			   + getPrevP(i, x + 2, y - 1);
	}

	double getPrevP(int i, int x, int y) {
		if (isOn(x, y)) {
			return P[i - 1][x][y] / 8;
		}
		return 0;
	}

	bool isOn(int x, int y) {
		if (x >= 0 && x < size && y >= 0 && y < size)
			return true;
		return false;
	}
};


#endif //LEETCODE_688_KNIGHT_PROBABILITY_IN_CHESSBOARD_H
