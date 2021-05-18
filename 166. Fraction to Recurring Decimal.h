//
// Created by jin on 5/18/2021.
//

#ifndef LEETCODE_166_FRACTION_TO_RECURRING_DECIMAL_H
#define LEETCODE_166_FRACTION_TO_RECURRING_DECIMAL_H

using namespace std;

#include <unordered_map>

struct pair_hash {
	template<class T1, class T2>
	std::size_t operator()(std::pair<T1, T2> const &pair) const {
		std::size_t h1 = std::hash<T1>()(pair.first);
		std::size_t h2 = std::hash<T2>()(pair.second);

		return h1 ^ h2;
	}
};

class Solution {
public:
	string fractionToDecimal(long long numerator, long long denominator) {
		if (numerator == 0) return "0";
		char s[10000] = {0};
		int decimalPoint = 1;

		bool neg = (numerator < 0) ^(denominator < 0);
		numerator = numerator < 0 ? -numerator : numerator;
		denominator = denominator < 0 ? -denominator : denominator;

		long long newD = denominator * 10;

		while (numerator > newD) {
			newD *= 10;
			decimalPoint += 1;
		}
		denominator = newD / 10;


		bool isCounting = false;
		vector<int> vec;
		unordered_map<pair<int, int>, int, pair_hash> map;

		int countingIdx = -1;
		int loopIdx = -1;

		int i = 0;
		if (neg) {
			s[i++] = '-';
			++decimalPoint;
		}

		for (; i < 10000; ++i) {
			if (i == decimalPoint) {
				s[i] = '.';
				isCounting = true;
				countingIdx = i + 1;
				continue;
			}

			auto q = numerator / denominator;
			if (isCounting) {
				vec.push_back(q);
				if (map.count({q, numerator}) > 0) {
					loopIdx = map[{q, numerator}];
					break;
				}
				map[{q, numerator}] = i;
			} else {
				s[i] = '0' + q;
			}
			if (numerator >= denominator) {
				numerator %= denominator;
			}
			if (numerator == 0 && i >= decimalPoint - 1) break;
			numerator *= 10;
		}

		int j = 0;
		if (countingIdx > 0) {
			if (loopIdx > 0) {
				for (; j < loopIdx - countingIdx; ++j) {
					s[countingIdx + j] = '0' + vec[j];
				}
			} else {
				for (auto val : vec) {
					s[countingIdx + j++] = '0' + val;
				}
			}
		}

		if (loopIdx > 0) {
			s[loopIdx] = '(';
			for (; j < map.size(); ++j) {
				s[countingIdx + j + 1] = '0' + vec[j];
			}
			s[i + 1] = ')';
		}

		return s;
	}
};

#endif //LEETCODE_166_FRACTION_TO_RECURRING_DECIMAL_H
