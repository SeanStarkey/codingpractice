
#include <queue>
#include <string>
#include <sstream>
#include <iostream>

struct Interval
{
    char c;
    int count;
};

std::string lookandsee(std::string str)
{
    if (str.length() == 0)
        return "";

    std::queue<Interval> tokens;

    for (int i=0; i<str.size(); i++)
    {
        if (tokens.empty())
        {
            Interval in;
            in.count = 1;
            in.c = str[0];
            tokens.push(in);
        }
        else
        {
            if (tokens.back().c == str[i])
            {
                tokens.back().count++;
            }
            else
            {
                Interval in;
                in.count = 1;
                in.c = str[i];
                tokens.push(in);            }
        }
    }

    std::stringstream result;
    while (!tokens.empty())
    {
        Interval in = tokens.front();
        tokens.pop();
        result << in.count;
        result << in.c;
    }

    return result.str();
}


int main()
{
    std::string str("1");
    std::cout << str << std::endl;
    for (int x=0; x<15; x++)
    {
        str = lookandsee(str);
        std::cout << str << std::endl;
    }
}
