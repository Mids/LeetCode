#include <iostream>
#include <vector>
#include "3. Longest Substring Without Repeating Characters.h"

using namespace std;

int main() {
	Solution s;

	cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
	cout << s.lengthOfLongestSubstring("dvdf") << endl;

	return 0;
}