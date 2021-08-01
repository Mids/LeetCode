#include <iostream>
#include <vector>
#include "315. Count of Smaller Numbers After Self.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
	vector<string> arr2 = {"hot", "dot", "dog", "lot", "log", "cog"};

	vector<int> nums = {6,1,5,2,6,1};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{2, 1},
								 {2, 0}};

	vector<vector<int>> board2 = {{9, 9, 4},
								  {6, 6, 8},
								  {2, 1, 1}};

	vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
								 {'X', 'O', 'O', 'X'},
								 {'X', 'X', 'O', 'X'},
								 {'X', 'O', 'X', 'X'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};


	auto r = s.countSmaller(nums);

	for (auto aa: r) {
		cout << aa << " ";
	}


	return 0;
}