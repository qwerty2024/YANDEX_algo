﻿#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    string input;
    getline(cin, input);
    int n = stoi(input);
    vector<int> vec;
    vec.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            getline(cin, input, ' ');
        else
            getline(cin, input);
        vec[i] = stoi(input);
    }

    //cout << endl << n << endl;
    //for (int i = 0; i < n; i++)
    //{
    //    cout << vec[i] << endl;
    //}

    string res = "";

    bool test = false;
    int i = 0;

    for (i = 0; i < n; i++)
    {
        if (vec[i] == 0)
        {
            res += 43;
        }
        else
        {
            if (vec[i] % 2 == 0)
                test = true;
            else
                test = false; 
            
            i++;
            break;
        }
    }
    //cout << "i " << i << endl;

    for (i; i < n; i++)
    {
        if (vec[i] == 0)
        {
            res += 43;
        }
        else if (test)
        {
            if (vec[i] % 2 == 0)
            {
                res += 43;
            }
            else
            {
                res += 43;
                test = false;
            }
        }
        else
        {
            if (vec[i] % 2 == 0)
            {
                res += 43; // +
            }
            else
            {
                res += 120; // x
            }
        }
    }

    cout << res << endl;

    return 0;
}









int flag = IsOdd(numbers[0]);

for (int i = 1; i < n; i++) {
    if (flag == 0) {
        if (IsOdd(numbers[i]) == 0) {
            Console.Write('x');
        }
        else {
            flag = 1;
            Console.Write('+');
        }
    }
    else if (flag == 1) {
        if (IsOdd(numbers[i]) == 1) {
            Console.Write('x');
        }
        else {
            flag = 2;
            Console.Write('+');
        }
    }
    else if (flag == 2) {
        Console.Write('x');
    }
}