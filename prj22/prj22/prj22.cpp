#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input, ' ');
    int N = stoi(input);

    getline(cin, input);
    int K = stoi(input);

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



    int res = -1;
    int min = x[0];
    int max = x[0];
    int imax = 0;
    int imin = 0;
    int il = 0;
    
    for (int i = 1; i < N + K - 1; i++)
    {
        if (imax <= il && i < N)
        {
            max = x[il];
            imax = il;
            for (int j = il + 1; j < i; j++)
            {
                if (max <= x[j])
                {
                    max = x[j];
                    imax = j;
                }
            }
        }
        else if (i > N - 1 && imax < i - K)
        {
            imax = N - 1;
            max = x[N-1];
        }

        if (i < N)
            if (max <= x[i])
            {
                max = x[i];
                imax = i;
            }

        if (res < max - min && imin < imax) res = max - min;

        if (i > K - 1) il++;
        
        if (imin < il)
        {
            imin = il;
            min = x[il];
        }
    }


    if (res <= 0) 
        cout << "0" << endl; 
    else
        cout << res << endl;

/*
11 4
1 3 7 2 1 5 9 2 1 8 3
8

10 4
10 9 8 7 6 5 4 3 2 1
0

10 4
1 2 3 4 5 6 7 8 9 10

10 4
1 2 3 4 5 6 7 8 0 10

2 4
1 2

2 4
2 1

10 0
1 2 3 4 5 6 7 8 9 10

2 1
1 2

2 1
0 9999

10 5
0 0 0 0 0 0 0 0 0 0

10 7
9 4 9 3 8 10 9 4 5 5

10 4
8 10 1 9 3 9 10 5 7 5

*/

    return 0;
}