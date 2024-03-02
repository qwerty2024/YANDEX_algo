#include <iostream>

int main()
{
    int p{0}, v{ 0 }, q{ 0 }, m{ 0 };
    std::cin >> p >> v >> q >> m;

    if (v < 0) v = 0;
    if (m < 0) m = 0;

    //std::cout << p << " " << v << " " << q << " " << m << std::endl;
    
    int l1 = p - v;
    int r1 = p + v;
    int l2 = q - m;
    int r2 = q + m;

    if ((r1 - l1) == 0 && (r2 - l2) == 0)
    {
        std::cout << 0 << std::endl;
        return 0;
    }

    if (l1 < l2)
    {
        if (r1 >= l2)
        {
            if (r1 > r2)
            {
                std::cout << r1 - l1 + 1 << std::endl;
            }
            else
            {
                std::cout << r2 - l1 + 1 << std::endl;
            }
        }
        else
        {
            std::cout << r1 - l1 + r2 - l2 + 2 << std::endl;
        }
    }
    else
    {
        if (r2 >= l1)
        {
            if (r2 > r1)
            {
                std::cout << r2 - l2 + 1 << std::endl;
            }
            else
            {
                std::cout << r1 - l2 + 1 << std::endl;
            }
        }
        else
        {
            std::cout << r2 - l2 + r1 - l1 + 2 << std::endl;
        }
    }

    return 0;
}

