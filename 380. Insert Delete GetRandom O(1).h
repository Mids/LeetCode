//
// Created by Jin on 5/9/2021.
//

#ifndef LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H
#define LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H

#include <unordered_map>
#include <unordered_set>
#include <random>
#include <vector>

using namespace std;

// 32 ms
class RandomizedSet {
public:
	unordered_map<int, int> set;
	vector<int> vec;

	/** Initialize your data structure here. */
	RandomizedSet() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (set.count(val)) {
			return false;
		} else {
			vec.push_back(val);
			set[val] = vec.size() - 1;
			return true;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (set.count(val)) {
			auto idx = set[val];
			vec[idx] = vec.back();
			vec.pop_back();
			set[vec[idx]] = idx;
			set.erase(val);
			return true;
		} else {
			return false;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		return vec[rand() % vec.size()];
	}
};

// 68 ms
class RandomizedSet2 {
public:
	unordered_set<int> set;

	/** Initialize your data structure here. */
	RandomizedSet2() {

	}

	/** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
	bool insert(int val) {
		if (set.count(val)) {
			return false;
		} else {
			set.insert(val);
			return true;
		}
	}

	/** Removes a value from the set. Returns true if the set contained the specified element. */
	bool remove(int val) {
		if (set.count(val)) {
			set.erase(val);
			return true;
		} else {
			return false;
		}
	}

	/** Get a random element from the set. */
	int getRandom() {
		int size = set.size();
		int randomValue = rand() % size;

		auto it = set.begin();
		for (int i = 0; i < randomValue; ++i) {
			++it;
		}

		return *it;
	}
};


#endif //LEETCODE_380_INSERT_DELETE_GETRANDOM_O_1_H
