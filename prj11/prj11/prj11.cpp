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
    vector<int> y;

    for (int i = 0; i < N; i++)
    {
        getline(cin, input, ' ');
        x.push_back(stoi(input));

        getline(cin, input);
        y.push_back(stoi(input));
    }

    // найти минимум и максимум по x и y
    int min_x = x[0];
    int max_x = x[0];
    int min_y = y[0];
    int max_y = y[0];

    for (int i = 1; i < N; i++)
    {
        if (min_x > x[i]) min_x = x[i];
        if (max_x < x[i]) max_x = x[i];

        if (min_y > y[i]) min_y = y[i];
        if (max_y < y[i]) max_y = y[i];
    }

    cout << min_x << " " << min_y << " " << max_x << " " << max_y << endl;

    return 0;
}

