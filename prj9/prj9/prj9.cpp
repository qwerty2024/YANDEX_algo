#include <iostream>
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

//    cout << "DAYS: ";
//    for (int i = 0; i < 7; i++)
//    {
//        cout << vec_all_day_in_weak[i] << " ";
//    }
//    cout << endl;
//    
//    cout << "WONDER DAYS: ";
//    for (int i = 0; i < 7; i++)
//    {
//        cout << vec_wonder_day_in_weak[i] << " ";
//    }
//    cout << endl;

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
3
2013
1 July
8 July
15 July
Tuesday
*/
    return 0;
}
