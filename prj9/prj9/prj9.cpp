﻿#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<int> vec_leap_year = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
vector<int> vec_no_leap_year = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int start = 0; // потому что мне лень
vector<int> vec_all_day_in_weak = { 0, 0, 0, 0, 0, 0, 0 }; // потому что мне лень х2
vector<int> vec_wonder_day_in_weak = { 0, 0, 0, 0, 0, 0, 0 }; // потому что мне лень х3

vector<string>& split(const string& s, char delim, vector<string>& elems) {
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

string int_day_to_string(const int& i)
{
    if (i == 0) return "Monday";
    if (i == 1) return "Tuesday";
    if (i == 2) return "Wednesday";
    if (i == 3) return "Thursday";
    if (i == 4) return "Friday";
    if (i == 5) return "Saturday";
    if (i == 6) return "Sunday";
}

string int_month_to_string(const int& i)
{
    if (i == 0) return "January";
    if (i == 1) return "February";
    if (i == 2) return "March";
    if (i == 3) return "April";
    if (i == 4) return "May";
    if (i == 5) return "June";
    if (i == 6) return "July";
    if (i == 7) return "August";
    if (i == 8) return "September";
    if (i == 9) return "October";
    if (i == 10) return "November";
    if (i == 11) return "December";
}

int name_month_to_int(const string& name)
{
    if (name == "January")   return 0;
    if (name == "February")  return 1;
    if (name == "March")     return 2;
    if (name == "April")     return 3;
    if (name == "May")       return 4;
    if (name == "June")      return 5;
    if (name == "July")      return 6;
    if (name == "August")    return 7;
    if (name == "September") return 8;
    if (name == "October")   return 9;
    if (name == "November")  return 10;
    if (name == "December")  return 11;
}

int name_day_to_int(const string& name)
{
    if (name == "Monday") return 0;
    if (name == "Tuesday") return 1;
    if (name == "Wednesday") return 2;
    if (name == "Thursday") return 3;
    if (name == "Friday") return 4;
    if (name == "Saturday") return 5;
    if (name == "Sunday") return 6;
}

struct day
{
    day(string _name, int _number_in_month, int _number_in_weak) : name(_name), number_in_month(_number_in_month), number_in_weak(_number_in_weak) {}

    void setWonder()
    {
        wonder = true;
    }

    bool isWonder()
    {
        return wonder;
    }

    string name;
    int number_in_month;
    int number_in_weak;
    bool wonder = false;
};

struct month
{
    vector<day> days;
    int day_size_in_month = 0;
    int offset = 0;

    month(int number, bool leap)
    {
        offset = start;
        leap ? day_size_in_month = vec_leap_year[number] : day_size_in_month = vec_no_leap_year[number];

        for (int i = 0; i < start; i++)
        {
            day tmp("none", -1, -1);
            days.push_back(tmp);
        }

        int count = 0;
        for (int i = start; i < day_size_in_month + start; i++)
        {
            vec_all_day_in_weak[i % 7]++; // заполняем глобальный массив всех дней в неделе
            day tmp(int_day_to_string(i % 7), count, i % 7);
            days.push_back(tmp);
            count++;
        }

        start = (day_size_in_month + start) % 7;
    }

    void print()
    {
        for (int i = 0; i < days.size(); i++)
        {
            if (i % 7 == 0 && i != 0) cout << endl;
            if (days[i].number_in_month != -1 && days[i].isWonder())
            {
                printf("%*d*", 3, days[i].number_in_month);
            }
            else if (days[i].number_in_month != -1)
            {
                printf("%*d ", 3, days[i].number_in_month);
            }
            else cout << "    ";
        }
        cout << endl;
    }
};

struct year
{
    int my_year = -1;
    bool leap_yaer = false;
    int day_size_in_year = -1;
    int N = -1;
    int day_of_week = -1;
    vector<month> months;

    year(const int _my_year, const int _N, const vector<string> &_data, const string &_dow)
    {
        my_year = _my_year;
        N = _N;
        Leap(my_year);
        day_of_week = name_day_to_int(_dow);

        start = day_of_week;

        // создаем месяцы
        for (int i = 0; i < 12; i++)
        {
            month tmp(i, leap_yaer);
            months.push_back(tmp);
        }

        // добавить праздники
        for (int i = 0; i < N; i++)
        {
            vector<string> elems;
            split(_data[i], ' ', elems); 
            months[name_month_to_int(elems[1])].days[stoi(elems[0]) - 1 + months[name_month_to_int(elems[1])].offset].setWonder();
            int test = months[name_month_to_int(elems[1])].days[stoi(elems[0]) - 1 + months[name_month_to_int(elems[1])].offset].number_in_weak;
            vec_wonder_day_in_weak[months[name_month_to_int(elems[1])].days[stoi(elems[0]) - 1 + months[name_month_to_int(elems[1])].offset].number_in_weak]++; // заполняем глобальный массив всех дней в неделе
        }

        // подсчитать количество всех праздников по дням недели

    };

    bool isLeap()
    {
        return leap_yaer;
    }

    void Leap(int data)
    {
        //Год является високосным, если он кратен 400, либо кратен 4 и не кратен 100.
        if (data % 400 == 0 || (data % 4 == 0 && data % 100 != 0))
        {
            leap_yaer = true;
            day_size_in_year = 366;
        }
        else
        {
            leap_yaer = false;
            day_size_in_year = 365;
        }

    }

    void print()
    {
        for (int i = 0; i < 12; i++)
        {
            cout << "          " << int_month_to_string(i) << endl;
            months[i].print();
            cout << endl;
        }
    }
};

int main()
{
    string input;
    getline(cin, input);
    int N = stoi(input);

    getline(cin, input);
    int year_data = stoi(input);

    vector<string> tmp;
    for (int i = 0; i < N; i++)
    {
        getline(cin, input);
        tmp.push_back(input);
    }

    getline(cin, input);
    string dow = input;

    year my_year(year_data, N, tmp, dow);

//    my_year.print();

    cout << "DAYS: ";
    for (int i = 0; i < 7; i++)
    {
        cout << vec_all_day_in_weak[i] << " ";
    }
    cout << endl;
    
    cout << "WONDER DAYS: ";
    for (int i = 0; i < 7; i++)
    {
        cout << vec_wonder_day_in_weak[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 7; i++)
    {
        vec_all_day_in_weak[i] -= vec_wonder_day_in_weak[i];
    }

    int min = vec_all_day_in_weak[0];
    int max = vec_all_day_in_weak[0];

    int i_min = 0;    
    int i_max = 0;

    for (int i = 1; i < 7; i++)
    {
        if (vec_all_day_in_weak[i] <= min)
        {
            min = vec_all_day_in_weak[i];
            i_min = i;
        }
        if (vec_all_day_in_weak[i] >= max)
        {
            max = vec_all_day_in_weak[i];
            i_max = i;
        }
    }

    string a = int_day_to_string(i_max);
    string b = int_day_to_string(i_min);
    cout << a << " " << b << endl;
/*
168
1890
28 December
24 December
23 December
21 December
20 December
17 December
16 December
14 December
13 December
12 December
9 December
7 December
5 December
2 December
29 November
28 November
27 November
26 November
24 November
22 November
21 November
20 November
19 November
17 November
13 November
8 November
7 November
4 November
2 November
1 November
31 October
28 October
27 October
24 October
19 October
18 October
15 October
11 October
10 October
9 October
5 October
3 October
2 October
30 September
29 September
25 September
23 September
20 September
18 September
16 September
14 September
13 September
4 September
2 September
30 August
29 August
24 August
19 August
17 August
15 August
14 August
11 August
9 August
3 August
31 July
29 July
27 July
22 July
19 July
17 July
15 July
14 July
13 July
10 July
9 July
3 July
1 July
29 June
27 June
26 June
23 June
20 June
19 June
18 June
17 June
16 June
15 June
14 June
12 June
10 June
9 June
8 June
31 May
29 May
28 May
26 May
24 May
22 May
21 May
20 May
19 May
18 May
17 May
16 May
13 May
12 May
11 May
9 May
4 May
2 May
1 May
30 April
29 April
25 April
22 April
21 April
19 April
18 April
13 April
12 April
11 April
10 April
8 April
7 April
6 April
5 April
4 April
30 March
29 March
27 March
23 March
20 March
15 March
14 March
13 March
9 March
7 March
6 March
4 March
2 March
26 February
25 February
24 February
21 February
19 February
16 February
15 February
14 February
11 February
8 February
7 February
5 February
3 February
2 February
23 January
21 January
20 January
19 January
18 January
16 January
11 January
10 January
9 January
7 January
6 January
3 January
2 January
1 January
Wednesday

3
2013
1 July
8 July
15 July
Tuesday


170
1904
31 December
27 December
23 December
22 December
20 December
19 December
16 December
15 December
13 December
12 December
11 December
8 December
6 December
4 December
1 December
28 November
27 November
26 November
25 November
23 November
21 November
20 November
19 November
18 November
16 November
12 November
7 November
6 November
3 November
1 November
31 October
30 October
27 October
26 October
23 October
18 October
17 October
14 October
10 October
9 October
8 October
4 October
2 October
1 October
29 September
28 September
24 September
22 September
19 September
17 September
15 September
13 September
12 September
3 September
1 September
29 August
28 August
23 August
18 August
16 August
14 August
13 August
10 August
8 August
2 August
30 July
28 July
26 July
21 July
18 July
16 July
14 July
13 July
12 July
9 July
8 July
2 July
30 June
28 June
26 June
25 June
22 June
19 June
18 June
17 June
16 June
15 June
14 June
13 June
11 June
9 June
8 June
7 June
30 May
28 May
27 May
25 May
23 May
21 May
20 May
19 May
18 May
17 May
16 May
15 May
12 May
11 May
10 May
8 May
3 May
1 May
30 April
29 April
28 April
24 April
21 April
20 April
18 April
17 April
12 April
11 April
10 April
9 April
7 April
6 April
5 April
4 April
3 April
29 March
28 March
26 March
22 March
19 March
14 March
13 March
12 March
8 March
6 March
5 March
3 March
1 March
29 February
26 February
25 February
24 February
21 February
19 February
16 February
15 February
14 February
11 February
8 February
7 February
5 February
3 February
2 February
23 January
21 January
20 January
19 January
18 January
16 January
11 January
10 January
9 January
7 January
6 January
3 January
2 January
1 January
Friday

*/
    return 0;
}
