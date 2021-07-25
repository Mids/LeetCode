//
// Created by jin on 7/25/2021.
//

#ifndef LEETCODE_207_COURSE_SCHEDULE_H
#define LEETCODE_207_COURSE_SCHEDULE_H

#include <algorithm>
#include <unordered_set>

using namespace std;

// 16ms 94.17%
class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<vector<int>> pre(numCourses);
		vector<vector<int>> post(numCourses);
		vector<int> done(numCourses);

		unordered_set<int> set;

		for (auto &pair : prerequisites) {
			pre[pair[0]].push_back(pair[1]);
			post[pair[1]].push_back(pair[0]);
		}

		for (int i = 0; i < pre.size(); ++i) {
			if (pre[i].empty()) {
				set.insert(i);
				done[i] = 1;
			}
		}

		while (!set.empty()) {
			auto it = begin(set);
			auto c = *it;
			set.erase(it);

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
					done[v] = 1;
				}
			}
		}

		for (auto v : done) {
			if (v == 0)
				return false;
		}

		return true;
	}
};

// 32ms 24.55%
class Solution1 {
	struct Course {
		vector<Course *> pre;
		vector<Course *> post;
	};
public:
	bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
		vector<Course> courses(numCourses);

		for (auto pair : prerequisites) {
			courses[pair[0]].pre.push_back(&courses[pair[1]]);
			courses[pair[1]].post.push_back(&courses[pair[0]]);
		}

		bool repeat = true;
		while (repeat) {
			repeat = false;
			for (auto &course : courses) {
				if (!course.pre.empty()) continue;

				for (auto post : course.post) {
					auto &pre = post->pre;
					pre.erase(remove(pre.begin(), pre.end(), &course), pre.end());
					repeat = true;
				}
				course.post.clear();
			}
		}


		for (const auto &course : courses) {
			if (!course.pre.empty()) {
				return false;
			}
		}

		return true;
	}
};

#endif //LEETCODE_207_COURSE_SCHEDULE_H
