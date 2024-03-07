#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input);

    vector<vector<int>> coord;
    coord.resize(N);
    for (int i = 0; i < N; i++)
        coord[i].resize(2, 0);


    for (int i = 0; i < N; i++)
    {
         getline(cin, input, ' ');
         coord[i][0] = stoi(input);
         getline(cin, input);
         coord[i][1] = stoi(input);
    }

    vector<vector<bool>> field;
    field.resize(10);
    for (int i = 0; i < 10; i++)
        field[i].resize(10, false);

    vector<vector<int>> offset;
    offset.resize(4);
    for (int i = 0; i < 4; i++)
        offset[i].resize(2);

    offset = { { 0, 1 }, { 0, -1 }, { 1, 0 }, { -1, 0 } };

    int res = 0;

    for (int i = 0; i < N; i++)
    {
        field[coord[i][0]][coord[i][1]] = true;

        int tmp = 0;
        for (int j = 0; j < 4; j+=1)
            if (field[coord[i][0] + offset[j][0]][coord[i][1] + offset[j][1]]) tmp += 1;

        if (tmp == 0) res += 4;
        if (tmp == 1) res += 2;
        if (tmp == 3) res -= 2;
    }

    cout << res << endl;

/*
3
1 1
1 2
2 1
8


1
8 8
4


5
1 1
1 2
2 1
1 3
2 3
12


6
1 1
1 2
2 1
1 3
2 3
2 2    
10


*/

    return 0;
}