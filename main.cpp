#include <iostream>
#include <vector>
#include "127. Word Ladder.h"

using namespace std;

int main() {
	Solution s;

	vector<string> arr = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	vector<string> arr2 = {"hot","dot","dog","lot","log","cog"};

	vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
	vector<int> nums1 = {3, 1, 5};

	vector<vector<int>> board = {{0, 1, 0},
								 {0, 0, 1},
								 {1, 1, 1},
								 {0, 0, 0}};

	vector<vector<int>> board2 = {{1, 2, 3},
								  {4, 5, 6},
								  {7, 8, 9}};

	vector<vector<char>> grid = {{'A', 'B', 'C', 'E'},
								 {'S', 'F', 'C', 'S'},
								 {'A', 'D', 'E', 'E'}};
	vector<vector<char>> grid2 = {{'1', '1', '0', '0', '0'},
								  {'1', '1', '0', '0', '0'},
								  {'0', '0', '1', '0', '0'},
								  {'0', '0', '0', '1', '1'}};


	cout << s.ladderLength("hit", "cog", arr2);

	return 0;
}