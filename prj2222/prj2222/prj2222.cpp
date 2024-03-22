#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

#define ULL unsigned long long 

bool test(int K, ULL N)
{
    bool test = true;
    
    ULL res = 1;
    ULL tmp = 0;

    for (ULL i = 2; i <= K; i++)
    {
        tmp = i; // количество пробелов
        tmp += ((1 + i) * i) / 2; // сумма арифметической прогрессии

        res += tmp; 
    }

    //cout << "[" << K << "] " << res << endl;
    if (res <= N) test = false;

    return test;
}


int bin_search(int l, int r, ULL N)
{
    int mid = 0;

    while (l < r)
    {
        mid = (l + r) / 2; // считываем срединный индекс отрезка [l,r]

        if (test(mid, N))
            r = mid; // проверяем, какую часть нужно отбросить с поиска
        else
            l = mid + 1;
    }

    return --r;
}

int main()
{
    string input;
    getline(cin, input);
    ULL N = stoull(input);
    
    if (N == 0)
    {
        cout << "0" << endl;
        return 0;
    }
    else if (N < 6)
    {
        cout << "1" << endl;
        return 0;
    }
    
    //if (N > (ULL)6'000'000'000'000'000)
    //{
    //    cout << "99999999" << endl;
    //    return 0;
    //}

    cout << bin_search(0, 10'000'000, N) << endl;

    //test(2, 10000);
    //test(3, 10000);
    //test(4, 10000);
    //test(5, 10000);
    //test(6, 10000);

    //test(2000, 10000);
    //test(3000, 10000);
    //test(5000, 10000);
    //test(10000, 10000);
    //test(100000, 10000);
    //test(7, 10000);
    //test(8, 10000);
    //test(9, 10000);
    //test(10, 10000);

    //for (int i = 2; i < 162614; i++)
    //    test(i, 10000);
/*

1000'000'000'000'000'000
1000000000000000000

100'000'000'000'000'000

5999999999999999
6000000000000000 после этого числа и до 10^18 будет ответ 99'999'999
6'000'000'000'000'000
716'701'926'703'764

1200000000000000000

10000000

716701926703764
7740265087636
716701926703764
37649527 мой ответ
162614 бота ответ
7740265087636



3709467965631
28127

*/

    return 0;
}
