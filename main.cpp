#include <iostream>
#include <vector>
#include "46. Permutations.h"

using namespace std;


void print(vector<vector<int>> v){
	for(const auto& a:v){
		for (auto b:a){
			cout << b << '\t';
		}
		cout << endl;
	}
}

int main() {
	Solution s;

	vector<int> a = {1,2,3};
	print(s.permute(a));
	cout << endl;
	a={0,1};
	print(s.permute(a));
	cout << endl;
	a={1};
	print(s.permute(a));

	return 0;
}