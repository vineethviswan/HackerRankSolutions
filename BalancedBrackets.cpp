
/*
	A bracket is considered to be any one of the following characters: (, ), {, }, [, or ].

	Two brackets are considered to be a matched pair if the an opening bracket (i.e., (, [, or {) 
	occurs to the left of a closing bracket (i.e., ), ], or }) of the exact same type. 
	There are three types of matched pairs of brackets: [], {}, and ().

	A matching pair of brackets is not balanced if the set of brackets it encloses are not matched. 
	For example, {[(])} is not balanced because the contents in between { and } are not balanced. 
	The pair of square brackets encloses a single, unbalanced opening bracket, (, and the pair of parentheses encloses a single, unbalanced closing square bracket, ].

	By this logic, we say a sequence of brackets is balanced if the following conditions are met:

		*	It contains no unmatched brackets.
		*	The subset of brackets enclosed within the confines of a matched pair of brackets is also a matched pair of brackets.
		
	Given "n" strings of brackets, determine whether each sequence of brackets is balanced. If a string is balanced, return YES. Otherwise, return NO.

*/

#include <iostream>
#include <string>
#include <stack>
#include <vector>

bool checkIfOpeningBrace(char pSymbol) {

	if (pSymbol == '(' || pSymbol == '[' || pSymbol == '{')
		return true;
	else
		return false;
}

char getClosingBrace(char pOpenBrace) {

	if (pOpenBrace == '(')
		return ')';
	else if (pOpenBrace == '[')
		return ']';
	else if (pOpenBrace == '{')
		return '}';
	else
		return '*';

}

std::string isBalanced(std::string s) {

    std::stack<char> evaluator;
    char top = ' ';

	for (int i = 0; i < s.length(); i++) {
		if (checkIfOpeningBrace(s[i])) {
			evaluator.push(s[i]);
		}
		else {
			if (evaluator.empty())
				return "NO";

			top = evaluator.top();
			evaluator.pop();
			if (getClosingBrace(top) != s[i])
				return "NO";
		}
	}

	if (evaluator.empty())
		return "YES";
	else
		return "NO";
}


int main()
{

    std::vector<std::string> expressions = {"{[()]}", "{[(])}", "{{[[(())]]}}"};

    for (auto& elt : expressions) {
        std::cout << isBalanced(elt) << "\n";
    }

    return 0;

}