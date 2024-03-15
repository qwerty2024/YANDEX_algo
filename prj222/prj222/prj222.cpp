#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


int main()
{
    string word1;
    string word2;
    multiset<char> msword1;
    multiset<char> msword2;
    multiset<char> Tmp;

    getline(cin, word1);
    getline(cin, word2);

    if (word1.size() == word2.size())
    {
        for (int i = 0; i < word1.size(); i++)
        {

            msword1.insert(word1[i]);
            msword2.insert(word2[i]);

        }

        set_difference(msword1.begin(), msword1.end(),
            msword2.begin(), msword2.end(),
            inserter(Tmp, Tmp.begin()));

        if (Tmp.size() == 0)
        {
            cout << "YES" << endl;
        }
        else cout << "NO";

    }
    else
    {
        cout << "NO";
    }


    return 0;
}

/*
dusty
study

dustyu
studyy




*/