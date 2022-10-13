#pragma once
#include <unordered_set>

using namespace std;

template<typename Type, typename Iterator>
void printUnique(const Iterator& begin, const Iterator& end)
{
	unordered_set<Type> elements;
	copy(begin, end, inserter(elements, elements.end()));
	copy(elements.begin(), elements.end(), ostream_iterator<Type>(cout, ", "));
	cout << endl;
}

template <typename Output>
void output(Output& output)
{
	for (auto numbers : output)
		cout << numbers << " ";
	cout << endl;
}