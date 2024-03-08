#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input);

    vector<int> sizes;
    sizes.resize(N);

    vector<vector<int>> x;
    x.resize(N);

    for (int i = 0; i < N; i++)
    {
        getline(cin, input);
        sizes[i] = stoi(input);

        x[i].resize(sizes[i]);

        for (int j = 0; j < sizes[i]; j++)
        {
            if (j != sizes[i] - 1)
            {
                getline(cin, input, ' ');
                x[i][j] = stoi(input);
            }
            else
            {
                getline(cin, input);
                x[i][j] = stoi(input);
            }
        }
    }


    for (int i = 0; i < N; i++)
    {
        vector<int> tmp;
        int min = x[i][0];
        int count = 1;

        if (sizes[i] == 1)
        {
            cout << "1\n" << "1" << endl;
            continue;
        }

        for (int j = 1; j < sizes[i]; j++)
        {
            if (min <= count)
            {
                // stop
                tmp.push_back(count);
                count = 1;
                min = x[i][j];
                if (j == sizes[i] - 1)
                {
                    tmp.push_back(count);
                }
            }
            else if (x[i][j] <= count)
            {
                // stop 
                tmp.push_back(count);
                count = 1;
                min = x[i][j];
                if (j == sizes[i] - 1)
                {
                    tmp.push_back(count);
                }
            }
            else
            {
                if (min > x[i][j]) min = x[i][j];
                count++;
                if (j == sizes[i] - 1)
                {
                    tmp.push_back(count);
                }
            }
        }

        cout << tmp.size() << endl;
        for (int j = 0; j < tmp.size(); j++)
        {
            cout << tmp[j] << " ";
        }
        cout << endl;
    }



/*
1
4
2 4 3 1

1
10
9 2 1 4 1 9 8 3 1 1

1
7
4 1 6 4 7 1 7


5
5
1 1 1 1 1
10
123 123 123 123 123 123 123 123 123 123
3
1 1 1
4
1 2 3 4
8
10 10 10 2 1 4 5 6

 
1
5
1 3 3 3 2
 
1
8
2 3 4 2 1 5 6 7
 
3
5
1 3 3 3 2
16
1 9 8 7 6 7 8 9 9 9 9 9 9 9 9 9
7
7 2 3 4 3 2 7




10
9
1 1 9 2 9 9 9 5 8
10
10 9 9 10 3 4 1 8 2 7
10
10 10 10 1 5 8 4 8 9 8
10
1 3 10 4 6 4 3 7 6 10
10
4 3 8 3 7 1 10 5 1 4
10
5 2 5 5 10 10 10 1 6 3
10
9 2 1 4 1 9 8 3 1 1
7
4 1 6 4 7 1 7
2
2 2
2
1 2


10
2
2 2
10
3 3 3 3 3 3 3 3 3 3
10
4 4 4 4 4 4 4 4 4 4
10
1 1 1 1 1 1 1 1 1 1
10
9 9 9 9 9 9 9 9 9 9
1
1
10
5 5 5 5 5 5 5 5 5 5
6
6 6 6 6 6 6
7
1 1 1 1 1 1 1
9
4 4 4 4 4 4 4 4 4




20
4
2 4 3 1
20
6 1 13 20 9 3 1 12 8 20 14 19 10 20 1 10 3 5 8 5
7
4 3 5 2 7 5 4
1
1
20
5 20 7 16 15 6 14 14 10 12 1 3 2 3 18 13 20 17 14 5
19
14 7 2 18 11 18 13 9 2 11 6 10 14 14 13 5 3 17 7
1
1
4
3 2 4 4
20
14 13 18 17 11 16 10 2 6 10 1 5 1 16 19 14 3 20 17 12
3
3 3 1
20
3 12 8 18 9 6 1 2 19 2 14 3 17 9 4 4 4 1 20 16
7
1 6 2 2 1 7 3
20
18 7 15 12 12 5 12 8 8 17 1 12 14 16 17 6 18 12 4 18
20
9 8 1 1 2 15 16 15 2 17 7 4 12 13 20 17 19 20 19 4
20
12 3 5 14 7 6 16 17 20 20 3 4 3 2 16 6 3 17 20 6
20
14 9 13 2 16 19 6 9 9 16 19 2 14 11 10 1 10 10 1 4
20
20 1 11 10 13 8 6 19 19 12 13 1 2 9 12 10 19 9 12 2
20
8 12 17 13 7 4 9 13 4 16 7 19 9 11 11 13 13 11 18 7
20
16 12 2 14 3 19 9 17 15 14 6 2 4 10 15 16 5 20 3 2
20
9 6 16 10 18 20 1 1 9 9 10 17 18 19 11 9 5 18 1 17
*/



    return 0;
}