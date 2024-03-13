#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <fstream>

using namespace std;

struct spisok
{
    spisok(int _val, int _row, int _col) : val(_val), row(_row), col(_col) {}

    int val = 0;
    int row = 0;
    int col = 0;
};

int main()
{
    string input;
    getline(cin, input, ' ');
    int N = stoi(input); // ширина символа
    getline(cin, input);
    int M = stoi(input); // ширина символа

    vector<vector<int>> vec;
    vec.resize(N);

    //ifstream in("input.txt");
    //if (in.is_open())
    //{
    //    for (int i = 0; i < N; i++)
    //    {
    //        vec[i].resize(M);
    //
    //        for (int j = 0; j < M - 1; j++)
    //        {
    //            getline(in, input, ' ');
    //            vec[i][j] = stoi(input); // ширина символа
    //        }
    //        getline(in, input);
    //        vec[i][M - 1] = stoi(input); // ширина символа
    //    }
    //}
    //in.close();

    for (int i = 0; i < N; i++)
    {
        vec[i].resize(M);
    
        for (int j = 0; j < M - 1; j++)
        {
            getline(cin, input, ' ');
            vec[i][j] = stoi(input); // ширина символа
    
        }
    
        getline(cin, input);
        vec[i][M - 1] = stoi(input); // ширина символа
    }

    //cout << "Start" << endl;


    //vector<spisok> sp1;
    //vector<spisok> sp;
    //int maximum = 0;
    //int imaximum = 0;
    //int jmaximum = 0;

    // ищем максимум в бесконечном цикле
    // проверяем, есть ли у нас хотя бы два максимума не в одном столбце или строке
    //while (true)
    //{
    //    maximum = 0;
    //    imaximum = 0;
    //    jmaximum = 0;
    //
    //    for (int i = 0; i < N; i++)
    //    {
    //        for (int j = 0; j < M; j++)
    //        {
    //            bool go_next = true;
    //            for (int k = 0; k < sp.size(); k++)
    //                if (sp[k].val == vec[i][j]) go_next = false;
    //
    //            if (go_next)
    //                if (vec[i][j] > maximum)
    //                {
    //                    sp1.clear();
    //                    maximum = vec[i][j];
    //                    imaximum = i;
    //                    jmaximum = j;
    //
    //                    spisok tmp(maximum, i, j);
    //                    sp1.push_back(tmp);
    //                }
    //                else if (vec[i][j] == maximum)
    //                {
    //                    spisok tmp(maximum, i, j);
    //                    sp1.push_back(tmp);
    //                }
    //        }
    //    }
    //
    //
    //    for (int i = 0; i < sp1.size(); i++)
    //        sp.push_back(sp1[i]);
    //
    //    sp1.clear();
    //
    //
    //    // проверка на выход из цикла
    //    bool for_break = false;
    //
    //    for (int i = 0; i < sp.size(); i++)
    //    {
    //        for (int j = 1; j < sp.size(); j++)
    //        {
    //            if (sp[i].row != sp[j].row && sp[i].col != sp[j].col) for_break = true;
    //        }
    //    }
    //
    //    if (for_break) break;
    //}

    //vector<spisok> sp1;
    //int maximum = 0;
    //int imaximum = 0;
    //int jmaximum = 0;
    //int count1 = 0;

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (vec[i][j] > maximum)
    //        {
    //            sp1.clear();
    //            //count1 = 1;
    //            maximum = vec[i][j];
    //            imaximum = i;
    //            jmaximum = j;
    //
    //            spisok tmp(maximum, i, j);
    //            sp1.push_back(tmp);
    //        }
    //        else if (vec[i][j] == maximum)
    //        {
    //            spisok tmp(maximum, i, j);
    //            sp1.push_back(tmp);
    //            //count1++;
    //        }
    //    }
    //}


    // проход по максимуму

    //vector<spisok> sp2;
    //int maximum2 = 0;
    //int imaximum2 = 0;
    //int jmaximum2 = 0;
    //int count2 = 0;

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (vec[i][j] != maximum)
    //            if (vec[i][j] > maximum2)
    //            {
    //                sp2.clear();
    //                maximum2 = vec[i][j];
    //                imaximum2 = i;
    //                jmaximum2 = j;
    //
    //                spisok tmp(maximum2, i, j);
    //                sp2.push_back(tmp);
    //            }
    //            else if (vec[i][j] == maximum2)
    //            {
    //                spisok tmp(maximum2, i, j);
    //                sp2.push_back(tmp);
    //            }
    //    }
    //}
    //
    //for (int i = 0; i < sp2.size(); i++)
    //    sp1.push_back(sp2[i]);


    // теперь надо определить что выгоднее imaximum jmaximum2 или imaximum2 jmaximum
    //int res = 99999999999;
    //int ires = 0;
    //int jres = 0;
    //
    //int maxi = 0;
    //int imaxi = 0;
    //int jmaxi = 0;
    //
    //for (int r = 0; r < sp.size(); r++)
    //{
    //    for (int c = 1; c < sp.size(); c++)
    //    {
    //        if (r != c)
    //        {
    //            int row = sp[r].row;
    //            int col = sp[c].col;
    //
    //            maxi = 0;
    //
    //            for (int i = 0; i < N; i++)
    //            {
    //                for (int j = 0; j < M; j++)
    //                {
    //                    if (!(i == row || j == col))
    //                        if (maxi < vec[i][j])
    //                        {
    //                            maxi = vec[i][j];
    //                            imaxi = i;
    //                            jmaxi = j;
    //                        }
    //                }
    //            }
    //
    //            if (res > maxi)
    //            {
    //                res = maxi;
    //                ires = row;
    //                jres = col;
    //            }
    //
    //            maxi = 0;
    //
    //            row = sp[c].row;
    //            col = sp[r].col;
    //
    //            for (int i = 0; i < N; i++)
    //            {
    //                for (int j = 0; j < M; j++)
    //                {
    //                    if (!(i == row || j == col))
    //                        if (maxi < vec[i][j])
    //                        {
    //                            maxi = vec[i][j];
    //                            imaxi = i;
    //                            jmaxi = j;
    //                        }
    //                }
    //            }
    //
    //            if (res > maxi)
    //            {
    //                res = maxi;
    //                ires = row;
    //                jres = col;
    //            }
    //        }
    //    }
    //}
    
    //int maximum = 0;
    //int imaximum = 0;
    //int jmaximum = 0;
    //
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (i != imaximum || j != jmaximum2)
    //            if (vec[i][j] < res)
    //            {
    //                res = vec[i][j];
    //                ires = i;
    //                jres = j;
    //            }
    //    }
    //}
    
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (i != imaximum2 || j != jmaximum)
    //            if (vec[i][j] < res)
    //            {
    //                res = vec[i][j];
    //                ires = i;
    //                jres = j;
    //            }
    //    }
    //}

    //cout << ires + 1 << " " << jres + 1 << endl;

    //cout << "end" << endl;

    //vector<int> row;
    //row.resize(N);
    //vector<int> col;
    //col.resize(M);

    int maximum = 0;
    int imaximum = 0;
    int jmaximum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (vec[i][j] > maximum)
            {
                maximum = vec[i][j];
                imaximum = i;
                jmaximum = j;
            }
        }
    }



    int maxi = 0;
    int imaxi = 0;
    int jmaxi = 0;

    for (int i = 0; i < N; i++) // нашли максимум если выбили столбец
    {
        for (int j = 0; j < M; j++)
        {
            if (j != jmaximum)
                if (vec[i][j] > maxi)
                {
                    maxi = vec[i][j];
                    imaxi = i;
                    jmaxi = j;
                }
        }
    }
    

    int maxi2 = 0;
    int imaxi2 = 0;
    int jmaxi2 = 0;

    for (int i = 0; i < N; i++) // нашли максимум если выбили строчку
    {
        for (int j = 0; j < M; j++)
        {
            if (i != imaximum)
                if (vec[i][j] > maxi2)
                {
                    maxi2 = vec[i][j];
                    imaxi2 = i;
                    jmaxi2 = j;
                }
        }
    }


    maxi = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!(i == imaxi || j == jmaximum))
                if (vec[i][j] > maxi)
                {
                    maxi = vec[i][j];
                }
        }
    }
    

    int res = 2000000000;
    int ires = 0;
    int jres = 0;

    if (res > maxi)
    {
        res = maxi;
        ires = imaxi;
        jres = jmaximum;
    }


    maxi = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!(i == imaximum || j == jmaxi2))
                if (vec[i][j] > maxi)
                {
                    maxi = vec[i][j];
                }
        }
    }

    if (res > maxi)
    {
        res = maxi;
        ires = imaximum;
        jres = jmaxi2;
    }

    cout << ires + 1 << " " << jres + 1 << endl;


    //for (int row = 0; row < N; row++)
    //{
    //    for (int col = 0; col < M; col++)
    //    {
    //        max[row][col] = -1;
    //        if (row == imaximum || col == jmaximum)
    //        {
    //            for (int i = 0; i < N; i++)
    //            {
    //                for (int j = 0; j < M; j++)
    //                {
    //                    if (i != row && j != col)
    //                        if (vec[i][j] > max[row][col])
    //                        {
    //                            max[row][col] = vec[i][j];
    //                        }
    //                }
    //            }
    //        }
    //    }
    //}

    //int min = max[imaximum][jmaximum];
    //int imin = imaximum;
    //int jmin = jmaximum;
    //
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (min > max[i][j] && max[i][j] > -1)
    //        {
    //            min = max[i][j];
    //            imin = i;
    //            jmin = j;
    //        }
    //    }
    //}

    //cout << ires + 1 << " " << jres + 1 << endl;


    //int max2 = 0;
    //int min_is_max = 0;
    //int ii = 0;

    //for (int k = 0; k < M; k++)
    //{
    //    max2 = 0;
    //    for (int i = 0; i < N; i++) // если запретили строку, то нужно найти столбец, при вычеркивании которого максимум будет минимальным
    //    {
    //        for (int j = 0; j < M; j++)
    //        {
    //            if (i != imax && k != j)
    //            {
    //                if (vec[i][j] > max2)
    //                {
    //                    max2 = vec[i][j];
    //                }
    //            }
    //        }
    //    }

    //    if (min_is_max > max)
    //    {
    //        min_is_max = max;
    //        ii = k;
    //    }
    //}

    //int max3 = 0;
    //int imax3 = 0;
    //int jmax3 = 0;

    //for (int i = 0; i < N; i++) // если запретили столбец, нужно найти строку, при вычеркивании которой минимум будет минимальным
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (j != jmax)
    //        {
    //            if (vec[i][j] > max3)
    //            {
    //                max3 = vec[i][j];
    //                imax3 = i;
    //                jmax3 = j;
    //            }
    //        }
    //    }
    //}

    //if (max2 > max3)
    //{
    //    cout << imax + 1 << " " << jmax2 + 1 << endl;
    //}
    //else
    //{
    //    cout << imax3 + 1 << " " << jmax + 1 << endl;
    //}

    //system("pause");

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < M; j++)
    //    {
    //        if (vec[i][j] > max_el) {
    //            max_el = vec[i][j];
    //        }
    //    }
    //}

    //int max_ost = 0;

    //vector<spisok> res;

    //for (int r = 0; r < N; r++)
    //{
    //    for (int c = 0; c < M; c++)
    //    {
    //        spisok tmp;

    //        if (vec[r][c] == max_el)
    //        {
    //            row = r;
    //            col = c;

    //            max_el2 = 0;
    //            for (int i = 0; i < N; i++)
    //            {
    //                if (i != row && vec[i][col] > max_el2)
    //                {
    //                    max_el2 = vec[i][col];
    //                }
    //            }

    //            max_el3 = 0;
    //            for (int j = 0; j < M; j++)
    //            {
    //                if (j != col && vec[row][j] > max_el3) {
    //                    max_el3 = vec[row][j];
    //                }
    //            }

    //            max_el = 0;
    //            if (max_el2 > max_el3)
    //            {
    //                for (int j = 0; j < M; j++)
    //                {
    //                    for (int i = 0; i < N; i++)
    //                    {
    //                        if (vec[i][j] > max_el && j != col) {
    //                            max_el = vec[i][j];
    //                            row = i;
    //                        }
    //                    }
    //                }
    //            }
    //            else {
    //                for (int j = 0; j < M; j++)
    //                {
    //                    for (int i = 0; i < N; i++)
    //                    {
    //                        if (vec[i][j] > max_el && i != row) {
    //                            max_el = vec[i][j];
    //                            col = j;
    //                        }
    //                    }
    //                }
    //            }

    //            tmp.row = row;
    //            tmp.col = col;

    //            res.push_back(tmp);
    //        }

    //    }
    //}

    ////max_el = 0;
    //for (int r = 0; r < N; r++)
    //{
    //    for (int c = 0; c < M; c++)
    //    {
    //        for (int k = 0; k < res.size(); k++)
    //        {
    //            if (res[k].row != r && res[k].col != c)
    //            {
    //                if (vec[r][c] > res[k].max_ost)
    //                {
    //                    res[k].max_ost = vec[r][c];
    //                }
    //            }
    //        }
    //    }
    //}

    //for (int r = 0; r < N; r++)
    //{
    //    for (int c = 0; c < M; c++)
    //    {
    //        for (int k = 0; k < res.size(); k++)
    //        {
    //            if (res[k].row != r && res[k].col != c)
    //            {
    //                if (vec[r][c] == res[k].max_ost)
    //                {
    //                    res[k].num++;
    //                }
    //            }
    //        }
    //    }
    //}


    //int maxl = max_el;
    //int imin = -1;
    //int num = res.size();
    //for (int i = 0; i < res.size(); i++)
    //{
    //    if (maxl >= res[i].max_ost && res[i].num < num)
    //    {
    //        num = res[i].num;
    //        imin = i;
    //        maxl = res[i].max_ost;
    //    }
    //}

    //cout << res[imin].row + 1 << " " << res[imin].col + 1 << endl;

/*

3 3
1 2 1
2 1 1
2 1 3
3 3
1 3

4 3
6 7 2
2 8 6
9 1 8
5 8 6
3 2

6 4
1 6 4 9
3 2 7 5
3 7 5 2
8 5 1 9
7 5 3 1
4 3 7 6
4 4


4 5
999999997 1 2 3 4
10 2 1000000000 1 7
3 9 999999999 5 10
1 7 3 999999998 6
4 3


3 4
1 3 5 7
9 11 2 4
6 8 10 12
3 2



6 4
5 6 4 9
3 2 7 5
3 7 5 2
8 5 9 5
7 5 3 1
4 3 7 6
4 4


3 3
1 2 1
2 1 1
2 1 2




3 3
1 2 1
1 1 2
2 1 2


    */


    return 0;
}
