#include <iostream>
#include <vector>
#include "44. Wildcard Matching.h"

using namespace std;

int main() {
	Solution s;

	cout << 1 << s.isMatch("bbbab", "*??a?") << endl;
	cout << 0 << s.isMatch("", "ab*") << endl;
	cout << 0 << s.isMatch("aa", "a") << endl;
	cout << 1 << s.isMatch("aa", "*") << endl;
	cout << 0 << s.isMatch("cb", "?a") << endl;
	cout << 1 << s.isMatch("adceb", "*a*b") << endl;
	cout << 0 << s.isMatch("acdcb", "a*c?b") << endl;
	cout << 1 << s.isMatch("aabaac", "*a?c") << endl;
	cout << 1 << s.isMatch("aabaab", "*aab") << endl;
	cout << 1 << s.isMatch("aacaab", "***aab***") << endl;
	cout << 1 << s.isMatch("ab", "?*") << endl;
	cout << 1 << s.isMatch("ab", "??") << endl;


	return 0;
}