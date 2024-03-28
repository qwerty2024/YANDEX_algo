#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <deque>

using namespace std;

//#define ULL unsigned long long

struct Item
{
    Item(int _key, int _min, int _max) : key(_key), min(_min), max(_max) {  }
    int key = 0;
    int max = 0;
    int min = 0;
};

bool test_variant2(int N, int W, int H, int k, map<int, pair<int, int>>& col, map<int, pair<int, int>>& row)
{
    int min_row = 1'000'000'000;
    int max_row = 0;
    auto it = col.begin();

    deque<Item> window;
    window.push_back(Item(it->first, it->second.first, it->second.second));

    for (int i = 1; i < k; i++) // добавили в деку первые к элементов
    {
        if (it->first < window.front().key + k)
        {
            window.push_back(Item(it->first, it->second.first, it->second.second));
            if (++it != col.end()) break;
        }
        else
            break;
    }


    if (window.size() >= N) return true;


    // пройти по всем столбцам и найти min и max глобальные без первого выреза столбцов!!! (к столбцов)
    for (auto item = it; item != col.end(); item++)
    {
        if (min_row > item->second.first)
            min_row = item->second.first;

        if (max_row < item->second.second)
            max_row = item->second.second;
    }

    // проверка макс - мин
    if (max_row - min_row + 1 <= k) return true;


    for (auto iter = it; iter != col.end(); iter++)
    {
        int size = window.size();
        // определить, сколько элементов из деки удалить
        for (int i = 0; i < size; i++) // удалить все элементы, которые не подходят по индексу
        {
            if (window.front().key <= iter->first - k) // удаляем из деки или нет?
            {
                // удаление из максимальной деки первого элемента
                if (window.front().max > max_row)
                {
                    max_row = window.front().max;
                }

                // удаление из минимальной деки первого элемента
                if (window.front().min < min_row)
                {
                    min_row = window.front().min;
                }

                window.pop_front();
            }
            else
            {
                break;
            }
        }

        // добавление 
        window.push_back(Item(iter->first, iter->second.first, iter->second.second));

        // когда добавили, нужно проверить не выбили ли мы максимум
        if (max_row == iter->second.second) // если мы в деку добавляем максимум, то надо проверить, не единственный ли он, если единственный, то нужно взять следующий максимум
        {
            int l = row[max_row].first; // границы максимума
            int r = row[max_row].second;

            if (iter->first == r && l > r - k)
            {
                // то нужно обновить максимум
                auto tmp_it = row.find(max_row); // нам нужен предыдущий, если он не лежит на отрезке нашей деки...
                while (true) // пока не найдем подходящий
                {
                    tmp_it--;
                    int ll = tmp_it->second.first;
                    int rr = tmp_it->second.second;

                    if (rr > r || ll <= r - k) // если подходит, то заменяем максимум и брейкаем
                    {
                        max_row = tmp_it->first;
                        break;
                    }
                }
            }
        }

        // та же шляпа, но для минимума
        if (min_row == iter->second.first) // если мы в деку добавляем максимум, то надо проверить, не единственный ли он, если единственный, то нужно взять следующий максимум
        {
            int l = row[min_row].first; // границы максимума
            int r = row[min_row].second;

            if (iter->first == r && l > r - k)
            {
                // то нужно обновить максимум
                auto tmp_it = row.find(min_row); // нам нужен предыдущий, если он не лежит на отрезке нашей деки...
                while (true) // пока не найдем подходящий
                {
                    tmp_it++;
                    int ll = tmp_it->second.first;
                    int rr = tmp_it->second.second;

                    if (rr > r || ll <= r - k) // если подходит, то заменяем минимум и брейкаем
                    {
                        min_row = tmp_it->first;
                        break;
                    }
                }
            }
        }


        // проверка макс - мин
        if (max_row - min_row + 1 <= k) return true;

    }

    return false;
}

bool test(int N, int W, int H, int k, unordered_map<int, pair<int, int>> &col)
{
    
    for (int i = 0; i < W - k; i++)
    {
        int max = 0;
        int min = 1'000'000'000;

        for (auto item : col)
        {
            if (item.first < i || item.first >= k + i) // не заходим на нашу вертикальную дорожку
            {
                if (col.contains(item.first))
                {
                    // обновляем минимум и максимум
                    if (min > col[item.first].first)
                        min = col[item.first].first;
                    if (max < col[item.first].second)
                        max = col[item.first].second;
                }
            }
        }

        if (max - min < k) return true;
    }

    return false;
}

int bin_search(int N, int W, int H, map<int, pair<int, int>>& col, map<int, pair<int, int>>& row)
{
    int mid = 0;
    int l = 1;
    int r = min(W, H);

    while (l < r)
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (test_variant2(N, W, H, mid, col, row))
            r = mid; // проверяем, какую часть нужно отбросить с поиска
        else
            l = mid + 1;
    }

    return l;
}

// 3 - 432
// 9 - 50
// 13 - 1716
// 22 - 1500
// 45 - 99997774

//#define INPUT_FILE in  // потому что заебало

int main()
{
#ifdef INPUT_FILE
    ifstream in("input45.txt");
#endif

    string input;

#ifdef INPUT_FILE
    getline(in, input, ' ');
#else
    getline(cin, input, ' ');
#endif

    int W = stoi(input);

#ifdef INPUT_FILE
    getline(in, input, ' ');
#else
    getline(cin, input, ' ');
#endif

    int H = stoi(input);

#ifdef INPUT_FILE
    getline(in, input);
#else
    getline(cin, input);
#endif

    int N = stoi(input);

    vector<pair<int, int>> vec;
    vec.resize(N);

    for (int i = 0; i < N; i++)
    {
#ifdef INPUT_FILE
        getline(in, input, ' ');
#else
        getline(cin, input, ' ');
#endif

        vec[i].second = stoi(input);

#ifdef INPUT_FILE
        getline(in, input);
#else
        getline(cin, input);
#endif
        vec[i].first = stoi(input);
    }



    // по столбцам положим все координаты строк
    map<int, pair<int, int>> tmp_col;

    for (int i = 0; i < N; i++)
    {
        //vec[i].first; // номер строки
        //vec[i].second; // номер столбца

        if (tmp_col.contains(vec[i].second))
        {
            // если в этой строке уже есть какие-то индексы, то обновим их мин и макс
            if (tmp_col[vec[i].second].first > vec[i].first)
                tmp_col[vec[i].second].first = vec[i].first;

            if (tmp_col[vec[i].second].second < vec[i].first)
                tmp_col[vec[i].second].second = vec[i].first;
        }
        else
        {
            tmp_col[vec[i].second] = make_pair(vec[i].first, vec[i].first); // если для этой строки еще не записывали максимум и минимум, то создаем его
        }
    }

    map<int, pair<int, int>> tmp_row;

    for (int i = 0; i < N; i++)
    {
        //vec[i].first; // номер строки
        //vec[i].second; // номер столбца

        if (tmp_row.contains(vec[i].first))
        {
            // если в этой строке уже есть какие-то индексы, то обновим их мин и макс
            if (tmp_row[vec[i].first].first > vec[i].second)
                tmp_row[vec[i].first].first = vec[i].second;

            if (tmp_row[vec[i].first].second < vec[i].second)
                tmp_row[vec[i].first].second = vec[i].second;
        }
        else
        {
            tmp_row[vec[i].first] = make_pair(vec[i].second, vec[i].second); // если для этой строки еще не записывали максимум и минимум, то создаем его
        }
    }
    
    
    //cout << test_variant2(N, W, H, 432, tmp_col, tmp_row) << endl;
    //cout << test_variant2(N, W, H, 51, tmp_col, tmp_row) << endl;
    cout << bin_search(N, W, H, tmp_col, tmp_row) << endl;



    //cout << test(N, W, H, 1, tmp_col) << endl;
    //cout << test(N, W, H, 2, tmp_col) << endl;
    //cout << test(N, W, H, 430, tmp_col) << endl;
    //cout << test(N, W, H, 431, tmp_col) << endl;
    //cout << test(N, W, H, 432, tmp_col) << endl;
    //cout << test(N, W, H, 433, tmp_col) << endl;

    //sort(vec.begin(), vec.end());

    //cout << test(vec, N, 2) << endl;
    //cout << test(vec, N, 3) << endl;



/*


100 100 9
2 2
3 3
4 4
2 3
2 4
3 2
3 4
4 2
4 3
3


8 8 10
5 4
2 2
2 7
1 6
4 2
4 7
8 5
8 7
5 5
1 8
4


8 8 7
2 2
2 7
1 6
4 2
4 7
8 5
8 7
3

4 3 4
1 1
4 3
4 1
1 3
3

8 8 8
1 1
8 8
2 7
3 7
4 7
5 7
6 7
7 7
2

8 8 2
1 1
8 8
1

8 8 5
2 7
3 6
4 5
1 1
8 8
4

8 8 3
2 7
3 6
4 5
2

3 3 4
1 1
3 3
3 1
1 3
3

5 6 5
5 4
2 6
4 1
2 3
1 4
3

5 6 5
5 4
2 6
1 3
2 3
1 4
2

*/

    return 0;
}
