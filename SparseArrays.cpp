
#include <vector>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

std::vector<int> matchingStrings(std::vector<std::string> stringList, std::vector<std::string> queries) {

	std::map<std::string, int> strLookup;
	for (auto& elt : stringList) {
		int count = std::count(stringList.begin(), stringList.end(), elt);
		strLookup.insert(std::make_pair(elt, count));
	}

	std::vector<int> result;
	for (auto& elt : queries) {
		auto count = strLookup.find(elt);
		if (count != strLookup.end())
			result.push_back(count->second);
		else
			result.push_back(0);
	}
	return result;
}

int main() {
	
	std::vector<std::string> stringList = { "aba", "baba", "aba", "xzxb" };
	std::vector<std::string> queries = { "aba", "xzxb", "ab" };

	std::vector<int> res = matchingStrings(stringList, queries);
	for (auto elt : res)
		std::cout << elt << " ";

	return 0;
}
