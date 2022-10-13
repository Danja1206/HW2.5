#pragma once
#include <string>
#include <map>

using namespace std;

string specialCharacters(const string& str)
{
	string blackList(" \n\t\r");
	auto begin = str.find_first_not_of(blackList);
	auto end = str.find_last_not_of(blackList);
	return (begin != string::npos) ? str.substr(begin, end - begin + 1) : string{};
}

multimap<int, string> sentencesLength(string& str)
{
	multimap<int, string> output;
	auto textIterator_begin = begin(str);
	auto textIterator_end = end(str);
	auto textIterator_interminate = find(textIterator_begin, textIterator_end, '.');
	while (textIterator_begin != textIterator_end && distance(textIterator_begin, textIterator_interminate))
	{
		string txt = specialCharacters({ textIterator_begin, textIterator_interminate });
		int qte = count(txt.begin(), txt.end(), ' ') + 1;
		output.insert(make_pair(qte, move(txt)));
		textIterator_begin = next(textIterator_interminate, 1);
		textIterator_interminate = find(textIterator_begin, textIterator_end, '.');
		if (textIterator_interminate == textIterator_end)
			break;
	}
	return output;
}