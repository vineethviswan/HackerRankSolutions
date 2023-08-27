
/*

    There are a number of plants in a garden. Each of the plants has been treated with some amount of pesticide. 
    After each day, if any plant has more pesticide than the plant on its left, being weaker than the left one, it dies.

    You are given the initial values of the pesticide in each of the plants. 
    Determine the number of days after which no plant dies, i.e. the time after which there is no plant with 
    more pesticide content than the plant to its left.

    Example

    p = [3, 6, 2, 7, 5] // pesticide levels

    Use a 1-indexed array. On day 1, plants 2 and 4 die leaving p^ = [3, 2, 5]. 
    On day 2, plant 3 in p^ dies leaving p^^ = [3, 2]. There is no plant with a higher concentration of 
    pesticide than the one to its left, so plants stop dying after day 2.

*/

#include <iostream>
#include <stack>
#include <vector>

/*  For every position find out, "How many times it will be hit from right side", hits[i]. 
    Maximum among all hits[i] will be the desired answer.To find this, keep track of values 
    in stack and try to eliminate all values in current stack which are greater than p(i) from each points

*/

int poisonousPlants(std::vector<int> p) {

    std::stack<int>stk;
    int n = p.size();

    p.push_back(INT_MIN);
    std::vector<int>hits(n, 0);

    stk.push(n);
    int days = 0;
    for (int i = n - 1; i >= 0; --i) {
        int cnt = 0;
        while (!stk.empty() && p[stk.top()] > p[i]) {
            cnt = std::max(cnt + 1, hits[stk.top()]);
            stk.pop();
        }
        days = std::max(days, cnt);
        hits[i] = cnt;
        stk.push(i);
    }
    return days;
}


int main() {
	
	std::vector<int> p = { 6, 5, 8, 4, 7, 10, 9 };
	int result = poisonousPlants(p);

	std::cout << result << "\n";

return 0;
}