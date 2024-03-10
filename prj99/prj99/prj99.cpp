#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input); // ширина символа

    vector<vector<int>> coord;
    coord.resize(N);
    int sum_k = 0; // сумма индексов k,i
    int steps = 0;
    int steps_k1 = 0, steps_k2 = 0;
    int ships = 0;
    for (int i = 0; i < N; i++)
    {
        coord[i].resize(2);

        getline(cin, input, ' ');
        coord[i][0] = stoi(input); // ширина символа

        getline(cin, input);
        coord[i][1] = stoi(input); // ширина символа

        sum_k += coord[i][1];
    }
    sum_k = sum_k / N;

    // количество ходов, чтобы разместить корабли каждый в свою строку

    for (int j = 1; j <= N; j++) // по строкам
    {
        for (int i = 0; i < N; i++) // по кораблям
        {
            if (coord[i][0] == j) ships++;
        }
        if (ships <= 0) { steps += abs(ships) + 1; }
        if (ships > 0) { steps += ships - 1; }
        ships -= 1;
    }

    // количество ходов, чтобы разместить корабли в один столбец
    for (int j = -N / 10; j <= N / 10; j++) // по столбцам
    {
        if ((sum_k + j) < 0 || (sum_k + j) > N) continue;
        steps_k2 = 0;
        for (int i = 0; i < N; i++) // по кораблям
        {
            steps_k2 += abs(coord[i][1] - (sum_k + j));
        }
        if (steps_k1 == 0) steps_k1 = steps_k2;
        steps_k1 = min(steps_k1, steps_k2);
    }

    steps = steps + steps_k1;

    cout << steps << endl;

    return 0;
}