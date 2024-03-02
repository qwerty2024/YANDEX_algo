#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input, ' ');
    int n = stoi(input);

    std::getline(std::cin, input, ' ');
    int k = stoi(input);

    std::getline(std::cin, input);
    int d = stoi(input);

    //std::cout << n << " " << k << " " << d << std::endl;

    bool test = false;
    int nn = n * 10;
    int save = 0;
    for (int i = 0; i < 10; i++) 
    {
        if (i != 0) nn += 1;
        if (nn % k == 0)
        {
            save = i;
            test = true;
            break;
        }
    }

    if (test)
    {
        input = std::to_string(nn);
        for (int i = 0; i < d - 1; i++)
            input += "0";

        std::cout << input << std::endl;
    }
    else std::cout << -1 << std::endl;

    return 0;
}
