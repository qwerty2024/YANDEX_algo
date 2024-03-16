#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <map>

using namespace std;

struct Gamer
{
    string name = "";
    int total_goal = 0;
    //int total_matches = 0;
    multiset<int> time; // все минуты, на которых забивал игрок
    int firstly = 0; // забили гол первыми в матче
};

struct Command
{
    string name = "";
    int total_goal = 0;
    int total_matches = 0;
    int firstly = 0; // забили гол первыми в матче
};

vector<string>& split(const string& s, char delim, vector<string>& elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim))
    {
        elems.push_back(item);
    }
    return elems;
}

void parce_match(const string &line, string &name1, string &name2, int &goal1, int &goal2)
{
    //"Juventus AAA" - "Milan" 3:1
    vector<string> tmp;
    tmp = split(line, '-', tmp);
    
    //"Juventus AAA"_
    //_"Milan aaa"_3:1
    tmp[0].pop_back();
    name1 = tmp[0];

    vector<string> tmp1;
    tmp1 = split(tmp[1], ' ', tmp1);
    //"" - тут будет пустая строка
    //"Milan"
    //3:1
    for (int i = 1; i < tmp1.size() - 2; i++)
    {
        name2 += tmp1[i] + " ";
    }
    name2 += tmp1[tmp1.size() - 2];

    vector<string> tmp2;
    tmp2 = split(tmp1[tmp1.size() - 1], ':', tmp2);
    //3
    //1
    goal1 = stoi(tmp2[0]);
    goal2 = stoi(tmp2[1]);
}

void parce_goal(const string &line, string &name, int &minute)
{
    //Del Piero 67'
    vector<string> tmp;
    tmp = split(line, ' ', tmp);

    tmp[tmp.size() - 1].pop_back();
    minute = stoi(tmp[tmp.size() - 1]);

    name = "\"";
    for (int i = 0; i < tmp.size() - 2; i++)
    {
        name += tmp[i] + " ";
    }
    name += tmp[tmp.size() - 2];
    name += "\"";
}

int main()
{
    
    std::ofstream out;          // поток для записи
    out.open("output.txt");      // открываем файл для записи
    if (out.is_open())
    {
    }

    //std::cout << "File has been written" << std::endl;


    map<string, Command> commands;
    map<string, Gamer> gamers;
    map<string, string> gamer_from_command;
    string line;
    ifstream in("input.txt");
    
    int count = 0;

    if (in.is_open())
    {
        while (getline(in, line))
        {
            // парсим строку
            vector<string> tmp;
            tmp = split(line, ' ', tmp);

            if (tmp[0][0] == '"')
            {
                // парсим название команды
                string name1 = "";
                string name2 = "";
                int goal1 = 0;
                int goal2 = 0;
                parce_match(line, name1, name2, goal1, goal2);

                // создаем две команды, если не созданы
                commands[name1];
                commands[name2];
                
                vector<pair<string, int>> goals;
                goals.resize(goal1 + goal2);
                // Далее читаем голы игроков по количеству goal1 / goal2 
                for (int i = 0; i < goal1 + goal2; i++)
                {
                    getline(in, line);
                    string name = "";
                    int minute = 0;
                    // распарсить гол
                    parce_goal(line, name, minute);
                    goals[i].first = name;
                    goals[i].second = minute;
                    
                    // добавим игрока, если такого еще нет
                    gamers[name];

                    if (i < goal1)
                    {
                        gamer_from_command[name] = name1;
                    }
                    else
                    {
                        gamer_from_command[name] = name2;
                    }
                }

                // определяем какая команда первая забила и какой игрок
                if (goals.size())
                {
                    bool first_comm = goal1 > 0 ? false : true; // false первая, true вторая
                    string first_name = goals[0].first;
                    int min_time = goals[0].second;

                    for (int i = 1; i < goal1 + goal2; i++)
                    {
                        if (min_time > goals[i].second)
                        {
                            min_time = goals[i].second;
                            first_name = goals[i].first;

                            first_comm = i < goal1 ? false : true;
                        }
                    }

                    // Заполним первую комманду
                    commands[name1].total_goal += goal1;
                    commands[name1].total_matches++;
                    if (!first_comm) commands[name1].firstly++;

                    // Заполним вторую комманду
                    commands[name2].total_goal += goal2;
                    commands[name2].total_matches++;
                    if (first_comm) commands[name2].firstly++;

                    // создадим всех игроков и запишем им их голы и минуты этого гола
                    for (int i = 0; i < goal1 + goal2; i++)
                    {
                        gamers[goals[i].first].total_goal++;
                        gamers[goals[i].first].time.insert(goals[i].second);
                    }

                    // самому первому забившему игроку в матче запихнем плюшку
                    gamers[first_name].firstly++;
                }
                else
                {
                    // если никто ничего не забил просто у комманд увеличим счетчик игр
                    commands[name1].total_matches++;
                    commands[name2].total_matches++;
                }
            }

            if (tmp[0] == "Total")
            {
                if (tmp[2] == "for")
                {
                    string name_tmp = "";
                    for (int i = 3; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];

                    out << commands[name_tmp].total_goal << endl;
                }

                if (tmp[2] == "by")
                {
                    string name_tmp = "\"";
                    for (int i = 3; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    out << gamers[name_tmp].total_goal << endl;
                }
            }

            if (tmp[0] == "Mean")
            {
                if (tmp[4] == "for")
                {
                    string name_tmp = "";
                    for (int i = 5; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];

                    out.setf(ios::fixed, ios::floatfield);
                    out.precision(3);
                    out << (double)commands[name_tmp].total_goal / commands[name_tmp].total_matches << endl;
                }

                if (tmp[4] == "by")
                {
                    string name_tmp = "\"";
                    for (int i = 5; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    out.setf(ios::fixed, ios::floatfield);
                    out.precision(3);
                    out << (double)gamers[name_tmp].total_goal / commands[gamer_from_command[name_tmp]].total_matches << endl;
                }
            }

            if (tmp[0] == "Goals")
            {
                if (tmp[2] == "minute")
                {
                    int minute = stoi(tmp[3]);
                    string name_tmp = "\"";
                    for (int i = 5; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    out << gamers[name_tmp].time.count(minute) << endl;
                }

                if (tmp[2] == "first")
                {
                    int minute = stoi(tmp[3]);
                    string name_tmp = "\"";
                    for (int i = 6; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    int counter = 0;
                    for (int i = 0; i <= minute; i++)
                    {
                        if (gamers[name_tmp].time.find(i) != gamers[name_tmp].time.end())
                        {
                            counter += gamers[name_tmp].time.count(i);
                        }
                    }

                    out << counter << endl;
                }

                if (tmp[2] == "last")
                {
                    int minute = 91 - stoi(tmp[3]);
                    string name_tmp = "\"";
                    for (int i = 6; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    int counter = 0;
                    for (int i = minute; i <= 90; i++)
                    {
                        if (gamers[name_tmp].time.find(i) != gamers[name_tmp].time.end())
                        {
                            counter += gamers[name_tmp].time.count(i);
                        }
                    }

                    out << counter << endl;
                }
            }

            if (tmp[0] == "Score")
            {
                if (tmp[3][0] == '"')
                {
                    // выводим рекорд команды
                    string name_tmp = "";
                    for (int i = 3; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];

                    out << commands[name_tmp].firstly << endl;
                }
                else
                {
                    // выводим рекорд игрока
                    string name_tmp = "\"";
                    for (int i = 3; i < tmp.size() - 1; i++)
                    {
                        name_tmp += tmp[i] + " ";
                    }
                    name_tmp += tmp[tmp.size() - 1];
                    name_tmp += "\"";

                    out << gamers[name_tmp].firstly << endl;
                }
                
            }
        }
    }
    in.close();
    out.close();

    return 0;
}