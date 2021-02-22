//
// Created by jin on 2/22/2021.
//

#ifndef LEETCODE_155_MIN_STACK_H
#define LEETCODE_155_MIN_STACK_H

#include <stack>

using namespace std;

class MinStack {
private:
	stack<int> stack;
	std::stack<int> minStack;
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		stack.push(x);
		if (minStack.empty() || minStack.top() > x)
			minStack.push(x);
		else
			minStack.push(minStack.top());
	}

	void pop() {
		stack.pop();
		minStack.pop();
	}

	int top() {
		return stack.top();
	}

	int getMin() {
		return minStack.top();
	}
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

#endif //LEETCODE_155_MIN_STACK_H
