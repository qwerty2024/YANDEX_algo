#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input);

    vector<int> x;

    for (int i = 0; i < N; i++)
    {
        if (i != N - 1)
        {
            getline(cin, input, ' ');
            x.push_back(stoi(input));
        }
        else
        {
            getline(cin, input);
            x.push_back(stoi(input));
        }
    }

    int max = x[0];
    int sum = x[0];
    int res = 0;

    for (int i = 1; i < N; i++)
    {
        if (max < x[i]) max = x[i];
        sum += x[i];
    }

    if (sum - max >= max)
    {
        cout << sum << endl;
    }
    else
    {
        sum -= max;
        cout << max - sum << endl;
    }
    
/*
4
1 5 2 1

4
5 12 4 3

4
1 1 1 1

4
1 1 1 7

4
1 1 1 5

4
1 4 1 1

4
1 3 1 1

*/
    return 0;
}