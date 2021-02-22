//
// Created by jin on 2/22/2021.
//

#ifndef LEETCODE_204_COUNT_PRIMES_H
#define LEETCODE_204_COUNT_PRIMES_H

using namespace std;

class Solution {
public:
	int countPrimes(int n) {
		vector<bool> primes(n, true);
		int result = 0;

		if (n < 3) return 0;
		int size = min(n / 2 + 1, 2237);

		for (int i = 2; i < size; ++i) {
			if (primes[i]) {
				for (int j = i * i; j < n; j += i) {
					primes[j] = false;
				}
			}
		}

		for (int i = 2; i < n; ++i) {
			if (primes[i]) ++result;
		}

		return result;
	}

	// 156ms
	int countPrimes2(int n) {
		vector<int> primes;
		bool prime;
		if (n < 3) return 0;

		for (int i = 3; i < n; i += 2) {
			prime = true;

			for (auto p : primes) {
				if (p * p > i)
					break;
				if (i % p == 0) {
					prime = false;
					break;
				}
			}

			if (prime) {
				primes.push_back(i);
			}
		}

		return primes.size() + 1;
	}
};

#endif //LEETCODE_204_COUNT_PRIMES_H
