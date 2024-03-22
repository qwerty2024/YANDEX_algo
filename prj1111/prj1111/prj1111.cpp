#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int bin_search_right_index(vector<int> &arr, int l, int r, int key)
{
    int mid = arr[0];

    while (l < r) 
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] > key) 
            r = mid; // проверяем, какую часть нужно отбросить с поиска
        else 
            l = mid + 1;
    }

    return --r;
}

int bin_search_left_index(vector<int>& arr, int l, int r, int key)
{
    int mid = arr[0];

    while (l < r)
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (arr[mid] >= key)
            r = mid; // проверяем, какую часть нужно отбросить с поиска
        else
            l = mid + 1;
    }

    return --r;
}

int main()
{
    vector<int> vec;
    vector<pair<int, int>> zapros;

    string input;
    getline(cin, input);
    int N = stoi(input);

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
    }

    getline(cin, input);
    int K = stoi(input);

    zapros.resize(K);

    for (int i = 0; i < K; i++)
    {
        getline(cin, input, ' ');
        zapros[i].first = stoi(input);

        getline(cin, input);
        zapros[i].second = stoi(input);
    }

    sort(vec.begin(), vec.end());

    for (int i = 0; i < K; i++)
    {
        int max = bin_search_right_index(vec, 0, N, zapros[i].second);
        int min = bin_search_left_index(vec, 0, N, zapros[i].first);

        cout << max - min << " ";
    }

    cout << endl;

    //cout << bin_search_right_index(vec, 0, N, 1) << endl;
    //cout << bin_search_right_index(vec, 0, N, 10) << endl;
    //cout << bin_search_right_index(vec, 0, N, 2) << endl;
    //cout << bin_search_right_index(vec, 0, N, 3) << endl;
    //cout << bin_search_right_index(vec, 0, N, 4) << endl;
    //cout << bin_search_right_index(vec, 0, N, -4) << endl;
    //cout << bin_search_right_index(vec, 0, N, 40) << endl;
    //cout << bin_search_right_index(vec, 0, N, 8) << endl;
    //
    //cout << endl;
    //
    //cout << bin_search_left_index(vec, 0, N, 1) << endl;
    //cout << bin_search_left_index(vec, 0, N, 10) << endl;
    //cout << bin_search_left_index(vec, 0, N, 2) << endl;
    //cout << bin_search_left_index(vec, 0, N, 3) << endl;
    //cout << bin_search_left_index(vec, 0, N, 4) << endl;
    //cout << bin_search_left_index(vec, 0, N, -4) << endl;
    //cout << bin_search_left_index(vec, 0, N, 40) << endl;
    //cout << bin_search_left_index(vec, 0, N, 8) << endl;
/*
 
13
-2 -1 -1 -1 1 3 3 3 3 4 10 10 10 
10
1 10
2 9
3 4
2 2
-100 100
-1 -1
-2 3
-1 4
-1 100
100 100

13
-1 10 -2 -1 -1 10 1 10 3 4 3 3 3
4
1 10
2 9
3 4
2 2



8
10 1 10 3 4 3 3 3
4
1 10
2 9
3 4
2 2


5
10 1 10 3 4
4
1 10
2 9
3 4
2 2 
    
*/
   
    return 0;
}
