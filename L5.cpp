#include <iostream>
#include <vector>
#include "Task1.h";
#include "Task2.h";
using namespace std;

void L1()
{
    vector<string> words{ "поезд", "мяч", "танец", "тест", "красота", "мяч", "драка", "сон", "отдых", "танец" };
    output(words);
    printUnique<string>(words.begin(),words.end());
}

void L2()
{
    cin.unsetf(ios::skipws);

    string txt{ istream_iterator<char>{cin}, {} };

    for (const auto& [qte, sentence] : sentencesLength(txt))
        cout << qte << " слов/а: " << sentence << endl;
}

int main()
{
    setlocale(0, "rus");
    L1();
    L2();
    return 0;
}

