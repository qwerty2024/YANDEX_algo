﻿#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <algorithm>

using namespace std;


int main()
{
    string input;
    multimap<pair<int, int>, pair<int, int>> map1; // первый рисунок
    multimap<pair<int, int>, pair<int, int>> map2; // второй рисунок
    
    ifstream in("input.txt");

    getline(in, input);
    int N = stoi(input);

    vector<int> tmp;
    tmp.resize(4);

    if (in.is_open())
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                getline(in, input, ' ');
                tmp[j] = stoi(input);
            }
            getline(in, input);
            tmp[3] = stoi(input);

            // записать в мапу
            pair<int, int> vec(tmp[2] - tmp[0], tmp[3] - tmp[1]);
            pair<int, int> sm(tmp[2] - (tmp[2] - tmp[0]), tmp[3] - (tmp[3] - tmp[1]));
            
            pair<int, int> vec1(tmp[0] - tmp[2], tmp[1] - tmp[3]);
            pair<int, int> sm1(tmp[0] - (tmp[0] - tmp[2]), tmp[1] - (tmp[1] - tmp[3]));

            map1.insert(make_pair(vec, sm));  // ключ = вектор. значение = сдвиг этого вектора
            map1.insert(make_pair(vec1, sm1));  // ключ = вектор. значение = сдвиг этого вектора
        }
        
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                getline(in, input, ' ');
                tmp[j] = stoi(input);
            }
            getline(in, input);
            tmp[3] = stoi(input);

            // записать в мапу
            pair<int, int> vec(tmp[2] - tmp[0], tmp[3] - tmp[1]);
            pair<int, int> sm(tmp[2] - (tmp[2] - tmp[0]), tmp[3] - (tmp[3] - tmp[1]));

            pair<int, int> vec1(tmp[0] - tmp[2], tmp[1] - tmp[3]);
            pair<int, int> sm1(tmp[0] - (tmp[0] - tmp[2]), tmp[1] - (tmp[1] - tmp[3]));

            map2.insert(make_pair(vec, sm));  // ключ = вектор. значение = сдвиг этого вектора
            map2.insert(make_pair(vec1, sm1));  // ключ = вектор. значение = сдвиг этого вектора   
        }
    }
    in.close();


    //заполняем мультисет смещений
    set<pair<int, int>> smesh;
    map<pair<int, int>, int> counter;

    for (auto item1 : map1)
    {
        for (auto item2 : map2)
        {
            if (item1.first == item2.first)
            {
                pair<int, int> temp = make_pair(item2.second.first - item1.second.first, item2.second.second - item1.second.second);
                if (smesh.find(temp) != smesh.end())
                {
                    counter[temp]++;
                }
                else
                {
                    smesh.insert(temp);
                    counter[temp] = 1;
                }
            }
        }
    }


    using pair_type = decltype(counter)::value_type;

    auto pr = max_element
    (
        begin(counter), end(counter),
        [](const pair_type& p1, const pair_type& p2) {
            return p1.second < p2.second;
        }
    );

    
    if (counter.size() == 0)
    {
        cout << N << endl;
    }
    else
    {
        cout << N - pr->second / 2 << endl;
    }


    return 0;
}

/*
5
0 0 1 2
1 0 0 2
2 0 2 2
4 0 3 2
4 0 5 2
9 -1 10 1
10 1 9 3
8 1 10 1
8 1 9 -1
8 1 9 3
3

1
3 4 7 9
-1 3 3 8
0

1
-4 5 2 -3
-12 4 -2 4
1





*/

/*

    //vector<vector<int>> vec1;
    //vector<vector<int>> vec2;
    //vec1.resize(N);
    //vec2.resize(N);
    //int type = 0;
    //int xd = 0, yd = 0;
    //int count_ = 0, count = 0;
    //int x1_1 = 0, y1_1 = 0;
    //int x2_1 = 0, y2_1 = 0;
    //int x1_2 = 0, y1_2 = 0;
    //int x2_2 = 0, y2_2 = 0;
    //
    //for (int i = 0; i < N; i++)
    //{
    //    vec1[i].resize(4);
    //    vec2[i].resize(4);
    //}

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        getline(cin, input, ' ');
    //        vec1[i][j] = stoi(input);
    //    }
    //    getline(cin, input);
    //    vec1[i][3] = stoi(input);
    //}
    //
    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < 3; j++)
    //    {
    //        getline(cin, input, ' ');
    //        vec2[i][j] = stoi(input);
    //    }
    //    getline(cin, input);
    //    vec2[i][3] = stoi(input);
    //}

*/

/*


    // типы положений: 1 - |    2 - /   3 - <
    //                 4 - _    5 - \   6 - >
    for (int i = 0; i < N; i++)
    {
        if (vec1[i][0] == vec1[i][2]) type = 1;
        if (vec1[i][1] == vec1[i][3]) type = 4;

        if ((vec1[i][2] - vec1[i][0]) == 2 && (vec1[i][3] - vec1[i][1]) > 0) type = 3;
        if ((vec1[i][2] - vec1[i][0]) == -2 && (vec1[i][3] - vec1[i][1]) < 0) type = 3;
        if ((vec1[i][2] - vec1[i][0]) == 2 && (vec1[i][3] - vec1[i][1]) < 0) type = 6;
        if ((vec1[i][2] - vec1[i][0]) == -2 && (vec1[i][3] - vec1[i][1]) > 0) type = 6;
        if ((vec1[i][2] - vec1[i][0]) == 1 && (vec1[i][3] - vec1[i][1]) > 0) type = 2;
        if ((vec1[i][2] - vec1[i][0]) == -1 && (vec1[i][3] - vec1[i][1]) < 0) type = 2;
        if ((vec1[i][2] - vec1[i][0]) == 1 && (vec1[i][3] - vec1[i][1]) < 0) type = 5;
        if ((vec1[i][2] - vec1[i][0]) == -1 && (vec1[i][3] - vec1[i][1]) > 0) type = 5;
        match1[i] = type;
    }

    for (int i = 0; i < N; i++)
    {
        if (vec2[i][0] == vec2[i][2]) type = 1;
        if (vec2[i][1] == vec2[i][3]) type = 4;

        if ((vec2[i][2] - vec2[i][0]) == 2 && (vec2[i][3] - vec2[i][1]) > 0) type = 3;
        if ((vec2[i][2] - vec2[i][0]) == -2 && (vec2[i][3] - vec2[i][1]) < 0) type = 3;
        if ((vec2[i][2] - vec2[i][0]) == 2 && (vec2[i][3] - vec2[i][1]) < 0) type = 6;
        if ((vec2[i][2] - vec2[i][0]) == -2 && (vec2[i][3] - vec2[i][1]) > 0) type = 6;
        if ((vec2[i][2] - vec2[i][0]) == 1 && (vec2[i][3] - vec2[i][1]) > 0) type = 2;
        if ((vec2[i][2] - vec2[i][0]) == -1 && (vec2[i][3] - vec2[i][1]) < 0) type = 2;
        if ((vec2[i][2] - vec2[i][0]) == 1 && (vec2[i][3] - vec2[i][1]) < 0) type = 5;
        if ((vec2[i][2] - vec2[i][0]) == -1 && (vec2[i][3] - vec2[i][1]) > 0) type = 5;
        match2[i] = type;
    }

    for (int i = 0; i < N; i++) // по исходному рисунку
    {
        for (int j = 0; j < N; j++)  // по рисунку-результату
        {
            if (match1[i] == match2[j])
            {

                x1_1 = (vec1[i][0] > vec1[i][2]) ? vec1[i][0] : vec1[i][2];
                y1_1 = (vec1[i][1] > vec1[i][3]) ? vec1[i][1] : vec1[i][3];
                x1_2 = (vec2[j][0] > vec2[j][2]) ? vec2[j][0] : vec2[j][2];
                y1_2 = (vec2[j][1] > vec2[j][3]) ? vec2[j][1] : vec2[j][3];
                xd = abs(x1_1 - x1_2);
                yd = abs(y1_1 - y1_2);

                //cout<<xd<<' '<<yd<<endl;
                count_ = 0;
                for (int k = 0; k < N; k++) // по исходному
                {
                    for (int s = 0; s < N; s++) // по результату
                    {
                        x1_1 = (vec1[k][0] > vec1[k][2]) ? vec1[k][0] : vec1[k][2];
                        y1_2 = (vec1[k][1] > vec1[k][3]) ? vec1[k][1] : vec1[k][3];
                        x1_2 = (vec2[s][0] > vec2[s][2]) ? vec2[s][0] : vec2[s][2];
                        y1_2 = (vec2[s][1] > vec2[s][3]) ? vec2[s][1] : vec2[s][3];
                        x2_1 = (vec1[k][0] < vec1[k][2]) ? vec1[k][0] : vec1[k][2];
                        y2_1 = (vec1[k][1] < vec1[k][3]) ? vec1[k][1] : vec1[k][3];
                        x2_2 = (vec2[s][0] < vec2[s][2]) ? vec2[s][0] : vec2[s][2];
                        y2_2 = (vec2[s][1] < vec2[s][3]) ? vec2[s][1] : vec2[s][3];

                        if (x1_1 > x1_2)
                        {
                            if (x1_1 - xd == x1_2 && y1_1 - yd == y1_2 && x2_1 - xd == x2_2 && y2_1 - yd == y2_2)
                                //cout<< x1_1 - xd << ' '<<  x1_2 << ' '<< y1_1 - yd << ' '<<  y1_2 <<' '<< x2_1 - xd << ' '<<  x2_2 << ' '<< y2_1 - yd << ' '<< y2_2<<endl;
                                count_++;
                        }
                        else
                        {
                            //cout<< x1_2 - xd << ' '<<  x1_1 << ' '<< y1_2 - yd << ' '<<  y1_1 <<' '<< x2_2 - xd << ' '<<  x2_1 << ' '<< y2_2 - yd << ' '<< y2_1<<endl;
                            if (x1_2 - xd == x1_1 && y1_2 - yd == y1_1 && x2_2 - xd == x2_1 && y2_2 - yd == y2_1)
                                count_++;
                        }
                    }
                }
                count = (count < count_) ? count_ : count;
            }
        }
    }


*/