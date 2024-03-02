#include <iostream>
#include <string>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    int n = stoi(input);

    unsigned long long res = 0;

    for (int i = 0; i < n; i++)
    {
        std::getline(std::cin, input);
        int tmp = stoi(input);

        res += tmp / 4 + tmp % 4 + ((tmp % 4) == 3 ? -1 : 0);
    }

    std::cout << res << std::endl;

    return 0;
}
