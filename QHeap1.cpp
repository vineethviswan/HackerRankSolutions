
/*
There are  types of query:

"1 v" - Add an element  to the heap.
"2 v" - Delete the element  from the heap.
"3"   - Print the minimum of all the elements in the heap.

NOTE: It is guaranteed that the element to be deleted will be there in the heap. Also, at any instant, only distinct elements will be in the heap.
*/

#include <iostream>
#include <vector>
#include <algorithm>

class QHeap {
public:
	QHeap() : m_minimumValue(INT_MAX){}

	void InsertValue(int value) {
		m_data.push_back(value);

		if (value < m_minimumValue)
			m_minimumValue = value;
	}

	void DeleteValue(int value) {
		auto itr = std::find(m_data.begin(), m_data.end(), value);
		m_data.erase(itr);

		if (value == m_minimumValue ) {
			if (m_data.size())
				m_minimumValue = *(std::min_element(m_data.begin(), m_data.end()));
			else
				m_minimumValue = INT_MAX;
		}
	}

	void PrintMinimum() {
		std::cout << m_minimumValue << "\n";
	}

private:
	std::vector<int> m_data;
	int m_minimumValue;
};
//
//int main() {
//
//	std::cout << "Q Heap\n";
//	QHeap qh;
//
//	/*std::vector<std::pair<int, int>> input = {
//		{1, 286789035},
//		{1, 255653921},
//		{1, 274310529},
//		{1, 494521015},
//		{3, 0},
//		{2, 255653921},
//		{2, 286789035},
//		{3, 0},
//		{1, 236295092},
//		{1, 254828111},
//		{2, 254828111},
//		{1, 465995753},
//		{1, 85886315},
//		{1, 7959587},
//		{1, 20842598},
//		{2, 7959587},
//		{3, 0},
//		{1, -51159108},
//		{3, 0},
//		{2,  -51159108},
//		{3, 0},
//		{1, 789534713}
//	};*/
//
//	std::vector<std::pair<int, int>> input = {
//		{1, 3},
//		{1, 65},
//		{2, 65},
//		{3, 0},
//		{2, 3},
//		{1, 7},
//		{3, 0},		
//		{1, -1},
//		{3, 0},
//		{2, -1},
//		{3, 0},
//		{2, 7}
//	};
//
//	int nQuestions = 12;
//	
//	int action = 0;
//	int value = 0;
//	
//	for (int i = 0; i < nQuestions; ++i) {
//		action = input[i].first;
//		if (action == 1) {
//			value = input[i].second;
//			qh.InsertValue(value);
//		}
//		else if (action == 2) {
//			value = input[i].second;
//			qh.DeleteValue(value);
//		}
//		else if (action == 3)
//			qh.PrintMinimum();
//	}
//	
//	return 0;
//}