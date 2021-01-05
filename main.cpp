#include <iostream>
#include <vector>
#include "82. Remove Duplicates from Sorted List II.h"

using namespace std;

int main() {
	Solution s;

	ListNode g(5);
	ListNode f(4, &g);
	ListNode e(4, &f);
	ListNode d(3, &e);
	ListNode c(3, &d);
	ListNode b(2, &c);
	ListNode a(1, &b);
	s.print(s.deleteDuplicates(&a));

	return 0;
}