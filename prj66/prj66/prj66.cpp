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

    getline(cin, input, ' ');
    int a = stoi(input);

    getline(cin, input, ' ');
    int b = stoi(input);

    getline(cin, input);
    int k = stoi(input);

    int max = 0;

    if (a == b)
    {
        int count = ((a - 1) / k) % N;

        int ind_left = (count == 0) ? count : N - count;
        int ind_right = count;

        if (x[ind_left] > x[ind_right])
        {
            if (max < x[ind_left]) max = x[ind_left];
        }
        else
        {
            if (max < x[ind_right]) max = x[ind_right];
        }

        cout << max << endl;
        return 0;
    }

    unsigned long long test = (b + 1) < ((unsigned long long)a + (unsigned long long)N * k + 1) ? (b + 1) : (unsigned long long)a + (unsigned long long)N * k + 1;
    for (unsigned long long i = a; i < test; i+=k)
    {
        int count = ((i - 1) / k) % N;

        int ind_left = (count == 0) ? count : N - count;
        int ind_right = count;

        if (x[ind_left] > x[ind_right])
        {
            if (max < x[ind_left]) max = x[ind_left];
        }
        else
        {
            if (max < x[ind_right]) max = x[ind_right];
        }
    }

    cout << max << endl;



/*
5
1 2 3 4 5
15 15 2
4

5
1 2 3 4 5
3 5 2
5

5
1 2 3 4 5
15 15 2
4

5
5 4 3 2 1
2 5 2
5

тест 33
58
333 449 275 983 821 564 286 70 626 890 69 576 718 162 822 953 825 702 627 408 627 390 482 60 543 1 715 860 940 714 484 51 565 909 889 631 640 221 871 21 764 667 967 770 139 165 808 576 191 216 93 899 601 803 870 591 300 611
29344426 290942786 4844415
983

тест 38
95
467 82 925 465 738 918 810 693 167 434 327 624 440 514 383 420 821 488 74 78 538 316 986 77 201 967 370 930 177 925 476 17 287 761 805 101 439 474 806 185 351 3 786 731 872 569 159 251 66 341 243 769 124 465 893 573 900 807 428 512 785 333 440 328 426 229 907 408 858 417 571 46 803 908 912 373 684 627 852 547 209 266 652 189 141 835 274 767 903 449 523 864 742 10 500
43023377 192443105 1697952
986

тест 35
4
208 794 866 717
258262581 998614008 740351427
794

тест 41
30
463 335 183 289 230 679 930 897 389 972 762 15 134 465 94 239 104 662 287 808 122 797 519 582 778 788 577 418 214 324
225708351 711102211 1
972


*/
    return 0;
}
