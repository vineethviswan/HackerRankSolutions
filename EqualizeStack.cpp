
/*
You have three stacks of cylinders where each cylinder has the same diameter, but they may vary in height. 
You can change the height of a stack by removing and discarding its topmost cylinder any number of times.

Find the maximum possible height of the stacks such that all of the stacks are exactly the same height. 
This means you must remove zero or more cylinders from the top of zero or more of the three stacks until 
they are all the same height, then return the height.
*/

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

int equalStacks(std::vector<int> h1, std::vector<int> h2, std::vector<int> h3) {

	std::stack<int> s1;
	std::stack<int> s2;
	std::stack<int> s3;
	int sum = 0;

	//Move the first array into the cumulative stack
	for (int i = h1.size() - 1; i >= 0; i--) {
		sum += h1[i];
		s1.push(sum);
	}

	//Move the second array into the cumulative stack
	sum = 0;
	for (int i = h2.size() - 1; i >= 0; i--) {
		sum += h2[i];
		s2.push(sum);
	}

	//Move the third array into the cumulative stack
	sum = 0;
	for (int i = h3.size() - 1; i >= 0; i--) {
		sum += h3[i];
		s3.push(sum);
	}

	while (!s1.empty() && !s2.empty() && !s3.empty()) {

		std::cout << s1.top() << " " << s2.top() << " " << s3.top() << "\n";
		if (s1.top() == s2.top() && s2.top() == s3.top())
			return s1.top();		

		int max_height = std::max({ s1.top(), s2.top(), s3.top() });
		if (max_height == s1.top())
			s1.pop();
		else if (max_height == s2.top())
			s2.pop();
		else if (max_height == s3.top())
			s3.pop();
	}
	return 0;
}


int main() {
	
	std::cout << "Stack Equalizer..!!\n";

	std::vector<int> v1 = { 3, 2, 1, 1, 1 };
	std::vector<int> v2 = { 4, 3, 2 };
	std::vector<int> v3 = { 1, 1, 4, 1 };

	std::cout << "Height of the stacks when they are equalized : " << equalStacks(v1, v2, v3);

}