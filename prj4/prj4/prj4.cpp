#include <iostream>
#include <string>

#define N (int)8 // размер поля

void rm(const std::string &input, int** tmp, int n)
{
    int count = 0;
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == '*')
        {
            tmp[n][count] = 0;
            count++;
        }
        else if (input[i] == 'B')
        {
            tmp[n][count] = 1;
            count++;
        }
        else if (input[i] == 'R')
        {
            tmp[n][count] = 2;
            count++;
        }
        
        if (count == N) break;
    }
}

int main()
{
    int** tmp = new int* [N];
    for (int i = 0; i < N; i++)
        tmp[i] = new int[N];

    for (int i = 0; i < N; i++)
    {
        std::string input;
        std::getline(std::cin, input);
        rm(input, tmp, i);
    }

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        std::cout << tmp[i][j];
    //    std::cout << std::endl;
    //}

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            bool point = true;

            if (tmp[i][j] == 1 || tmp[i][j] == 2) point = false;
            
            // исследуем ячейку по горизонтали
            if (point)
            {
                for (int k = j; k >= 0; k--) // в левую сторону
                {
                    if (tmp[i][k] == 2)
                    {
                        tmp[i][j] = 7;
                        break;
                    }
                    else if (tmp[i][k] == 1) break;
                }
                for (int k = j; k < N; k++) // в правую сторону
                {
                    if (tmp[i][k] == 2)
                    {
                        tmp[i][j] = 7;
                        point = false;
                        break;
                    }
                    else if (tmp[i][k] == 1) break;
                }
            }
            else continue;

            // исследуем ячейку по вертикали
            if (point)
            {
                for (int k = i; k >= 0; k--) // вверх
                {
                    if (tmp[k][j] == 2)
                    {
                        tmp[i][j] = 7;
                        point = false;
                        break;
                    }
                    else if (tmp[k][j] == 1) break;
                }
                for (int k = i; k < N; k++) // вниз
                {
                    if (tmp[k][j] == 2)
                    {
                        tmp[i][j] = 7;
                        point = false;
                        break;
                    }
                    else if (tmp[k][j] == 1) break;
                }
            }
            else continue;

            // исследуем ячейку по главной диагонали
            if (point)
            {
                int counter = 1;
                for (;;) // в левую сторону
                {
                    if (i - counter >= 0 && j - counter >= 0)
                    {
                        if (tmp[i - counter][j - counter] == 1)
                        {
                            tmp[i][j] = 7;
                            point = false;
                            break;
                        }
                        else if (tmp[i - counter][j - counter] == 2) break;
                    }
                    else break;
                    counter++;
                }

                counter = 1;
                for (;;) // в правую сторону
                {
                    if (i + counter < N && j + counter < N)
                    {
                        if (tmp[i + counter][j + counter] == 1)
                        {
                            tmp[i][j] = 7;
                            point = false;
                            break;
                        }
                        else if (tmp[i + counter][j + counter] == 2) break;
                    }
                    else break;
                    counter++;
                }
            }
            else continue;

            // исследуем ячейку по побочной дигонали
            if (point)
            {
                int counter = 1;
                for (;;) // в правую сторону
                {
                    if (i - counter >= 0 && j + counter < N)
                    {
                        if (tmp[i - counter][j + counter] == 1)
                        {
                            tmp[i][j] = 7;
                            point = false;
                            break;
                        }
                        else if (tmp[i - counter][j + counter] == 2) break;
                    }
                    else break;
                    counter++;
                }

                counter = 1;
                for (;;) // в левую сторону
                {
                    if (i + counter < N && j - counter >= 0)
                    {
                        if (tmp[i + counter][j - counter] == 1)
                        {
                            tmp[i][j] = 7;
                            point = false;
                            break;
                        }
                        else if (tmp[i + counter][j - counter] == 2) break;
                    }
                    else break;
                    counter++;
                }
            }
            else continue;
        }
    }

    // подсчет нулевых ячеек
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (tmp[i][j] == 0) res++;
        
    }

    std::cout << res << std::endl;

    //for (int i = 0; i < N; i++)
    //{
    //    for (int j = 0; j < N; j++)
    //        std::cout << tmp[i][j] << " ";
    //    std::cout << std::endl;
    //}


    for (int i = 0; i < N; i++)
        delete[] tmp[i];
    delete[] tmp;

    return 0;
}
