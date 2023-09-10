
/*
	You are given a list of N numbers a1, a2, a3,...,an. For each element at position i (1 <= i <= N), 
	we define Left(i) and Right(i) as:
	
	Left(i) = closest index j such that j < i and aj > ai. If no such j exists then Left(i) = 0.
	Right(i) = closest index k such that k > i and ak > ai. If no such k exists then Right(i) = 0.

	We define IndexProduct(i)  = Left(i) * Right(i). You need to find out the maximum IndexProduct(i) among all i.

	E.g. a = [5, 4, 3, 4, 5]

	IndexProduct(1) = 0
	IndexProduct(2) = 1 * 5 = 5
	IndexProduct(3) = 2 * 4 = 8
	IndexProduct(4) = 1 * 5 = 5
	IndexProduct(5) = 0

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

std::vector<long long> NGEonLeft(const std::vector<long long>& arr) {

	std::vector<long long> leftIndex(arr.size() + 1, 0);
	std::stack<long long> stk;

	for (long long i = arr.size() - 1; i >= 0; --i) {

		while (!stk.empty() && arr[i] > arr[stk.top() - 1]) {
			long long r = stk.top();
			stk.pop();
			leftIndex[r - 1] = i + 1;
		}
		stk.push(i + 1);
	}
	return leftIndex;
}

std::vector<long long> NGEonRight(const std::vector<long long>& arr) {

	std::vector<long long> leftIndex(arr.size() + 1, 0);
	std::stack<long long> stk;

	for (long long i = 0; i < arr.size(); ++i) {

		while (!stk.empty() && arr[i] > arr[stk.top() - 1]) {
			long long r = stk.top();
			stk.pop();
			leftIndex[r - 1] = i + 1;
		}
		stk.push(i + 1);
	}
	return leftIndex;
}

long long solve(const std::vector<long long>& arr) {

	std::vector<long long> left = NGEonLeft(arr);
	std::vector<long long> right = NGEonRight(arr);

	long long product = 0;
	for (long long i = 1; i <= arr.size(); ++i) {
		product = std::max(product, left[i] * right[i]);
	}
	return product;
}

int main() {

	std::vector<long long> vec = { 5, 4, 3, 4, 5 };
	//std::vector<int> vec = { 0 };
	//std::vector<int> vec = { 6, 1, 9, 3, 2 };	
	std::cout << "Maximum Index Prodcut : " << solve(vec);

	return 0;
}