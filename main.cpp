#include <iostream>
#include <vector>
#include "236. Lowest Common Ancestor of a Binary Tree.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"si", "go", "se", "cm", "so", "ph", "mt", "db", "mb", "sb", "kr", "ln", "tm", "le", "av", "sm", "ar", "ci", "ca", "br", "ti", "ba", "to", "ra", "fa", "yo", "ow", "sn", "ya", "cr", "po", "fe", "ho", "ma", "re", "or", "rn", "au", "ur", "rh", "sr", "tc", "lt", "lo", "as", "fr", "nb", "yb", "if", "pb", "ge", "th", "pm", "rb", "sh", "co", "ga", "li", "ha", "hz", "no", "bi", "di", "hi", "qa", "pi", "os", "uh", "wm", "an", "me", "mo", "na", "la", "st", "er", "sc", "ne", "mn", "mi", "am", "ex", "pt", "io", "be", "fm", "ta", "tb", "ni", "mr", "pa", "he", "lr", "sq", "ye"};
	vector<string> arr2 = {"hot", "dot", "dog", "lot", "log", "cog"};

	vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{0, 1, 0},
								 {0, 0, 1},
								 {1, 1, 1},
								 {0, 0, 0}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	vector<vector<char>> grid = {{'X', 'X', 'X', 'X'},
								 {'X', 'O', 'O', 'X'},
								 {'X', 'X', 'O', 'X'},
								 {'X', 'O', 'X', 'X'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};


	TreeNode n6(6);
	TreeNode n0(0);
	TreeNode n8(8);
	TreeNode n7(7);
	TreeNode n4(4);

	TreeNode n2(2, &n7, &n4);

	TreeNode n5(5, &n6, &n2);
	TreeNode n1(1, &n0, &n8);

	TreeNode n3(3, &n5, &n1);

	auto r = s.lowestCommonAncestor(&n3, &n5, &n4);

	cout << r->val;


	return 0;
}