#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define MY_PI 3.141592653589793
#define RAD_CONST 0.0174532925199433

int main()
{
    string input;
    getline(cin, input, ' ');
    double L = stod(input);

    getline(cin, input, ' ');
    double y0_1 = stod(input);

    getline(cin, input, ' ');
    double k1 = stod(input);

    getline(cin, input, ' ');
    double y0_2 = stod(input);

    getline(cin, input);
    double k2 = stod(input);

    if (k1 == 0 && k2 == 0 && y0_1 != y0_2)
    {
        cout << "NO" << endl;
        return 0;
    }
    else if (k1 == 0 && k2 == 0 && y0_1 == y0_2)
    {
        printf("YES\n0.0000000000");
        return 0;
    }

    if (k1 == k2 && y0_1 == y0_2)
    {
        printf("YES\n0.0000000000");
        return 0;
    }
    else if (k1 == k2)
    {
        (y0_1 > L / 2) ? y0_1 -= L : NULL;
        (y0_2 > (double)L / 2) ? y0_2 -= L : NULL;

        if (k1 > 0 && y0_1 == L / 2) y0_1 -= L;
        if (k1 < 0 && y0_1 == L / 2) y0_1 += L;
        
        if (k2 > 0 && y0_2 == L / 2) y0_2 -= L;
        if (k2 < 0 && y0_2 == L / 2) y0_2 += L;

        double xx = (-1) * (y0_1 + y0_2) / (2 * k1);
        //cout.precision(10);
        //cout << xx << endl;
        printf("YES\n%#.11lg", xx);
        return 0;
    }

    double D = L / MY_PI;
    double R = D / 2;

    double f0_1 = (2 * MY_PI * y0_1) / L;
    double f0_2 = (2 * MY_PI * y0_2) / L;

    double w_1 = k1 / R;
    double w_2 = k2 / R;

    double t1 = 0.0;
    double t2 = 0.0;
    vector<double> aaa;
    double res = 99999999999999;

    for (int i = -5; i < 6; i++)
    {
        double t1 = (2 * i * MY_PI - f0_1 - f0_2) / (w_2 + w_1);
        double t2 = (2 * i * MY_PI + f0_1 - f0_2) / (w_2 - w_1);

        aaa.push_back(t1);
        aaa.push_back(t2);
    }

    for (int i = 0; i < aaa.size(); i++)
    {
        if (res > aaa[i] && aaa[i] >= 0) res = aaa[i];
    }
    
    //cout.precision(10);
    //cout << res << endl;
    //printf("YES\n%f\n", res);
    printf("YES\n%#.11lg", res);

    //82 42 -354891707 42 -354891707
    //72 20 -38121735 66 288888467   0.0000000795
    //6 1 1 4 1              0.5 
    //6 3 1 1 1              1.0 
    //12 8 10 5 20       0.3000000000
    //5 0 0 1 2          2.0000000000
    //10 7 -3 1 4         0.8571428571
    //615143346 79387687 -80123649 306422480 -80123649       2.4075923389
    //948744004 861724643 848773505 584154450 730556189      0.2859497398
    //977345779 636176199 0 165786447 815181433              0.2151461330
    //94 76 0 76 0      0.0000000000
    //78118007 46215547 -5 57496922 9   4774045.1428571429
    //55444931 17419156 0 53245822 -398046024      0.0382369025
    //1000000000 10 1000000000 11 0
 
    //(y0_1 > L / 2) ? y0_1 = L - y0_1 : NULL;
    //(y0_2 > L / 2) ? y0_2 = L - y0_2 : NULL;
    //
    //double D = L / MY_PI;
    //double R = D / 2;
    //
    //double f0_1 = 0.0;
    //double f0_2 = 0.0;
    //
    //if (y0_1 == L / 2)
    //{
    //    f0_1 = D;
    //}
    //else
    //{
    //    double alpha = ((360 * y0_1) / L) * RAD_CONST;
    //    double betha = (MY_PI - alpha) / 2;
    //    f0_1 = (R * sin(betha)) / tan(betha);
    //}
    //
    //if (y0_2 == L / 2)
    //{
    //    f0_2 = D;
    //}
    //else
    //{
    //    double alpha = ((360 * y0_2) / L) * RAD_CONST;
    //    double betha = (MY_PI - alpha) / 2;
    //    f0_2 = (R * sin(betha)) / tan(betha);
    //}
    //
    //double w_1 = k1 / R;
    //double w_2 = k2 / R;
    //
    //double t = (f0_2 - f0_1) / (w_1 - w_2);
    //
    //printf("YES\n%#.11lg", t);

    //72 20 -38121735 66 288888467
//6 1 1 4 1              0.5 
// 6 3 1 1 1         1.0
// 
// 12 8 10 5 20       0.3000000000
// 5 0 0 1 2          2.0000000000
// 10 7 -3 1 4         0.8571428571
//    615143346 79387687 -80123649 306422480 -80123649          3.39... а должен быть 2.4075923389
//    Сам тест : 948744004 861724643 848773505 584154450 730556189, ответ : YES, 0.2859497398.


    // урвнения прямых:
    // 0 = k1*x - y + b0_1;
    // 0 = k2*x - y + b0_2;
    // вектора нормали к ним будут (k1, -1) и (k2, -1) 
    // еденичный вектор нормали к первой прямой (k1 / sqrt(k1 * k1 + y0_1 * y0_1); -1 / sqrt(k1 * k1 + y0_1 * y0_1))
    // еденичный вектор нормали к первой прямой (k2 / sqrt(k2 * k2 + y0_2 * y0_2); -1 / sqrt(k2 * k2 + y0_2 * y0_2))
    //n1 - n2 - направление биссектрисы
    //double nx = (k1 / sqrt(k1 * k1 + 1)) + (k2 / sqrt(k2 * k2 + 1));
    //double ny = (-1 / sqrt(k1 * k1 + 1)) + (-1 / sqrt(k2 * k2 + 1));
    //
    //cout << nx << " " << ny << endl;
    //
    //// нормируем полученный ветокр
    //nx = nx / sqrt(nx * nx + ny * ny);
    //ny = ny / sqrt(nx * nx + ny * ny);
    //
    //// координаты точки пересечения исходных прямых
    //double x0 = (y0_2 - y0_1) / (k1 - k2);
    //double y0 = k1* x0 + y0_1;
    //
    //// уравнение биссектриссы (x - x0) / nx = (y - y0) / ny
    //double res = (nx * y0) / ny + x0;
    //cout << res << endl;
    // находим пересечение биссектриссы с осью Ох
    // уравнение биссектрисы острого угла будет таким:
    // (k1*x+y0_1*y + C1) / sqrt(k1*k1 + y0_1*y0_1) = (k2*x+y0_2*y + C2) / sqrt(k2*k2 + y0_2*y0_2)
    // из уравнения биссекрисы (y = kx + b) нам нужен k 

    //double x = (y0_2 - y0_1) / (k1 - k2);
    //
    //while (true)
    //{
    //    if (abs(k2) > abs(k1))
    //    {
    //        while (true)
    //        {
    //            if (x < 0)
    //            {
    //                (k2 >= 0) ? y0_2 -= L : y0_2 += L;
    //                x = (y0_2 - y0_1) / (k1 - k2);
    //            }
    //            else break;
    //        }
    //
    //        if (abs(k1 * x + y0_1) > L / 2) // проверка на y
    //        {
    //            (k2 >= 0) ? y0_1 += L : y0_2 -= L;
    //            x = (y0_2 - y0_1) / (k1 - k2);
    //        }
    //        else break;
    //    }
    //    else
    //    {
    //        while (true)
    //        {
    //            if (x < 0)
    //            {
    //                (k1 >= 0) ? y0_1 -= L : y0_1 += L;
    //                x = (y0_2 - y0_1) / (k1 - k2);
    //            }
    //            else break;
    //        }
    //
    //        if (abs(k1 * x + y0_1) > L / 2) // проверка на y
    //        {
    //            if (k2 >= 0)
    //            {
    //                y0_2 -= L;
    //            }
    //            else
    //            {
    //                y0_1 += L;
    //            }
    //
    //            x = (y0_2 - y0_1) / (k1 - k2);
    //        }
    //        else break;
    //
    //
    //    }
        /*
        if (k1 > 0 && k2 > 0)
        {
            if (k2 > k1)
            {
                while (true)
                {
                    if (x < 0)
                    {
                        y0_2 -= L;
                        x = (y0_2 - y0_1) / (k1 - k2);
                    }
                    else break;
                }

                if (k1 * x + y0_1 > L / 2) // проверка на y
                {
                    y0_1 -= L;
                }
                else break;
            }
            else
            {
                while (true)
                {
                    if (x < 0)
                    {
                        y0_1 -= L;
                        x = (y0_2 - y0_1) / (k1 - k2);
                    }
                    else break;
                }

                if (k1 * x + y0_1 > L / 2) // проверка на y
                {
                    y0_2 -= L;
                }
                else break;
            }
        }
        else if (k1 < 0 && k2 < 0)
        {
            if (k2 < k1)
            {
                while (true)
                {
                    if (x < 0)
                    {
                        y0_2 += L;
                        x = (y0_2 - y0_1) / (k1 - k2);
                    }
                    else break;
                }

                if (k1 * x + y0_1 < L / (- 2)) // проверка на y
                {
                    y0_1 += L;
                }
                else break;
            }
            else
            {
                while (true)
                {
                    if (x < 0)
                    {
                        y0_1 += L;
                        x = (y0_2 - y0_1) / (k1 - k2);
                    }
                    else break;
                }

                if (k1 * x + y0_1 < L / (-2)) // проверка на y
                {
                    y0_2 += L;
                }
                else break;
            }
        }
        else
        {
            if (abs(k1) > abs(k2))
            {
                while (true)
                {
                    if (x < 0)
                    {
                        y0_2 += L;
                        x = (y0_2 - y0_1) / (k1 - k2);
                    }
                    else break;
                }
            }
        }
        */
    //    
    //}
    
    //printf("YES\n%#.11lg", x);

    //72 20 -38121735 66 288888467
    //6 1 1 4 1              0.5 
    // 6 3 1 1 1         1.0
    // 
    // 12 8 10 5 20       0.3000000000
    // 5 0 0 1 2          2.0000000000
    // 10 7 -3 1 4         0.8571428571
    //    615143346 79387687 -80123649 306422480 -80123649          3.39... а должен быть 2.4075923389
    //    Сам тест : 948744004 861724643 848773505 584154450 730556189, ответ : YES, 0.2859497398.


    //10 9 8 0 7


    return 0;
}
