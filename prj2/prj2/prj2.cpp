#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input, ':');
    int a = stoi(input);

    std::getline(std::cin, input);
    int b = stoi(input);
    
    std::getline(std::cin, input, ':');
    int c = stoi(input);
    
    std::getline(std::cin, input);
    int d = stoi(input);
    
    std::getline(std::cin, input);
    int match = stoi(input);

    //std::cout << std::endl << a << " " << b << " " << c << " " << d << " " << e << std::endl;

    int count1 = a + c;
    int count2 = b + d;

    if (count1 > count2)
    {
        std::cout << 0;
    }
    else if (count1 < count2)
    {
        int offset = count2 - count1;
        c += offset;
        if (match == 1)
        {
            if (c > b)
            {
                std::cout << offset;
            }
            else
            {
                std::cout << offset + 1;
            }
        }
        else if (match == 2)
        {
            if (a > d)
            {
                std::cout << offset;
            }
            else
            {
                std::cout << offset + 1;
            }
        }
    }
    else // count1 = count2
    {
        if (match == 1)
        {
            if (c > b)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
        }
        else if (match == 2)
        {
            if (a > d)
            {
                std::cout << 0;
            }
            else
            {
                std::cout << 1;
            }
        }
        else std::cout << "error" << std::endl;
    }
}
