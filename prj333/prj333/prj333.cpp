#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;


int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input); //  размер массива
    multiset<int, greater<int>> arr;
    int count = 0;
    int res = 0;
    vector<int> vec;
    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            getline(cin, input, ' ');
            vec[i] = stoi(input);
        }
        else
        {
            getline(cin, input);
            vec[i] = stoi(input);
        }
        arr.insert(vec[i]);
    }

    auto result = arr.begin();
    res = *result;

    for (int i = 0; i <= res; i++)
    {
        if (arr.count(i) == 0) continue;
        if (i > 0) {
            if ((arr.count(i - 1) + arr.count(i)) > count)
                count = arr.count(i - 1) + arr.count(i);
        }
    }
    cout << arr.size() - count;
    return 0;
}

/*
5
1 2 3 4 5
3

10
1 1 2 3 5 5 2 2 1 5
4

10
5 5 5 5 5 5 5 5 5 6
0

10
5 5 5 5 5 5 5 5 5 7
1



*/