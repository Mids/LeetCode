//
// Created by Jin on 8/1/2021.
//

#ifndef LEETCODE_210_COURSE_SCHEDULE_II_H
#define LEETCODE_210_COURSE_SCHEDULE_II_H

#include <unordered_set>

using namespace std;

class Solution {
public:
	vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> pre(numCourses);
		vector<vector<int>> post(numCourses);
		vector<int> done(numCourses);
		vector<int> result;

		unordered_set<int> set;

		for (auto &pair : prerequisites) {
			pre[pair[0]].push_back(pair[1]);
			post[pair[1]].push_back(pair[0]);
		}

		for (int i = 0; i < pre.size(); ++i) {
			if (pre[i].empty()) {
				set.insert(i);
			}
		}

		while (!set.empty()) {
			auto it = begin(set);
			auto c = *it;
			set.erase(it);
			result.push_back(c);
			done[c] = 1;

			for (int i = 0; i < post[c].size(); ++i) {
				auto v = post[c][i];
				if (done[v]) continue;

				bool ready = true;
				for (auto prev : pre[v]) {
					if (done[prev] == 0) {
						ready = false;
						break;
					}
				}

				if (ready) {
					set.insert(v);
				}
			}
		}

		for (auto v : done) {
			if (v == 0) {
				vector<int> emptyResult;
				return emptyResult;
			}
		}

		return result;
	}
};

#endif //LEETCODE_210_COURSE_SCHEDULE_II_H
