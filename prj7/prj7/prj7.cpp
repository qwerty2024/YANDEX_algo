#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    double min_coef = 1.458;
    double max_coef = 1.764;
    double step = 0.000001;

    vector<int> res;

    //double coef = 1.616;// (1 + 2.236067977) / 2;
    //double coef1 = 1.756;//(1 + sqrt(5)) / 2;

    string input;
    getline(cin, input);
    int xx = stoi(input);

    getline(cin, input);
    int yy = stoi(input);

    getline(cin, input);
    int offset = stoi(input);

    //for (double coef = 1; coef <= 1.1; coef += 0.1)
    //for (double coef = min_coef; coef <= max_coef; coef += step)
    
    for (double coef = min_coef; coef <= max_coef; coef += step)
    {
        //cout << coef << endl;//"  " << coef1 << endl;
        int p = 0;
        int x = xx;
        int y = yy;
        //cout << x << "  " << y << "  " << offset << endl;
        int i = 0;

        if (offset >= x && x < y && (y - x + offset) / (double)x > coef)
        {
            //cout << -1 << endl;
            res.push_back(999999999);
            continue;
        }

        while (true)
        {
            i++;

            //cout << i << " : ------" << endl;

            // 1 шаг. Убиваем либо казарму либо врагов.

            bool test = false;
            double kkk = (y + offset) / (double)x;
            if ((y + offset) / (double)x <= coef)
                test = true; // в приоритете лупим казарму

            int free_x = 0;

            if (test)
            {
                // лупим казарму
                if (y > 0 && y >= x)
                {
                    y -= x;
                }
                else if (y < x)
                {
                    free_x = x - y;
                    y = 0;
                    p -= free_x;
                    if (p < 0) p = 0;
                }

            }
            else
            {
                // лупим солдат, потом казарму
                if (p <= x)
                {
                    free_x = x - p;
                    p = 0;
                    y -= free_x;
                }
                else
                {
                    p -= x;
                    //no_chance = true;
                }
            }

            //cout << x << "  " << y << "  " << p << endl;
            // 2 шаг. Враги убивают моих солдат.
            if (p > 0)
                x -= p;

            //cout << x << "  " << y << "  " << p << endl;
            // 3 шаг. Враг спавнит себе солдат.
            if (y > 0)
                p += offset;

            //cout << x << "  " << y << "  " << p << endl;

            //cout << "----------" << endl << endl;
            if (x <= 0)
            {
                i = 999999999;
                break;
            }
            if (y <= 0 && p <= 0) break;
        }
        //if (i == 3) cout << coef << endl;
        //cout << i << endl;
        res.push_back(i);
    }

    int min = res[0];
    for (int i = 1; i < res.size(); i++)
    {
        //cout << res[i] << endl;
        if (res[i] < min) min = res[i];
    }

    if (min == 999999999)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << min << endl;
    }

    return 0;
}
