
/* 
Jesse loves cookies and wants the sweetness of some cookies to be greater than value .
To do this, two cookies with the least sweetness are repeatedly mixed. This creates a special combined cookie with:
sweetness = (1 * Least sweet cookie + 2 * 2nd least sweet cookie).

This occurs until all the cookies have a sweetness.
Given the sweetness of a number of cookies, determine the minimum number of operations required. If it is not possible, return.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int cookies(int k, std::vector<int> A) {
	
	long int op_count = 0;
	long int lowest_elt = 0;
	long int second_lowest_elt = 0;

	std::priority_queue<long int, std::vector<long int>, std::greater<long int>> pq(A.begin(), A.end());	

	while(pq.top() < k) {

		if (!pq.size() || pq.size() == 1)
			return -1;
		
		lowest_elt = pq.top(); pq.pop();
		second_lowest_elt = pq.top(); pq.pop();
		
		long int new_elt = lowest_elt + 2 * second_lowest_elt;
		pq.push(new_elt);
		op_count++;
	}
	return op_count;
}

int main() {

	int k = 200;
	std::vector<int> vec = { 5, 6, 7 };
	std::cout << "No. of operations required to increase sweetness : " << cookies(k, vec);

	return 0;
}
