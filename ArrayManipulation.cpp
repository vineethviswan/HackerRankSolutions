
/*
	Starting with a 1-indexed array of zeros and a list of operations, for each operation add a value to each the array element 
	between two given indices, inclusive. Once all operations have been performed, return the maximum value in the array.

	Example
	n = 10
	queries = [[1, 5, 3],[4, 8, 7],[6, 9, 1]]

	Queries are interpreted as follows:
		a b k
		1 5 3
		4 8 7
		6 9 1
	Add the values of k between the indices a and b inclusive:

	index->	 1 2 3  4  5 6 7 8 9 10
			[0,0,0, 0, 0,0,0,0,0, 0]
			[3,3,3, 3, 3,0,0,0,0, 0]
			[3,3,3,10,10,7,7,7,0, 0]
			[3,3,3,10,10,8,8,8,1, 0]

	The largest value is 10 after all operations are performed.
*/

#include <iostream>
#include <vector>
#include <algorithm>

long long GetMax(std::vector<long long>& output)
{
	long long max = INT_MIN;
	long long sum = 0;
	for (size_t i = 0; i < output.size(); ++i)
	{
		sum += output[i];
		if (sum > max)
			max = sum;
	}
	return max;
}

long long arrayManipulation(int n, std::vector<std::vector<int>> queries) 
{	
	std::vector<long long> output(n + 2, 0);
	for (size_t i = 0; i < queries.size(); ++i)
	{		
		long a = queries[i][0];
		long b = queries[i][1];
		long k = queries[i][2];
		output[a] += k;
		output[b + 1] -= k;

		for (auto& itr : output)
			std::cout << itr << " ";
		std::cout << "\n";
	}	
	return GetMax(output);
}

int main() {

	int n = 4;	

	std::vector<std::vector<int>> queries;

	queries.push_back({ 2, 3, 603 });
	queries.push_back({ 1, 1, 286 });
	queries.push_back({ 4, 4, 882 });
	
	std::cout << arrayManipulation(n, queries) << "\n";

	return 0;
} 