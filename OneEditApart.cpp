//
// Facebook's Practice Interview Question #3
//

#include <string>
#include <iostream>

using namespace std;

bool OneEditApart(string s1, string s2)
{
    bool difference = false;
    string str1;
    string str2;
    if (s2.size() < s1.size())
    {
        str1 = s2;
        str2 = s1;
    }
    else
    {
        str1 = s1;
        str2 = s2;
    }
    if (s1.size() < s2.size()-1)
        return false;

    int str1Index = 0;
    int str2Index = 0;
    while (str1Index < str1.size())
    {
        if (str1[str1Index] != str2[str2Index])
        {
            if (difference)
            {
                return false;
            }
            else
            {
                if (str1[str1Index+1] != str2[str2Index+1])
                {
                    str2Index++;
                }
                else
                {
                    str1Index++;
                    str2Index++;
                }
                difference = true;
            }
        }
        else
        {
            str1Index++;
            str2Index++;
        }
    }
    return true;
}

int main()
{
    cout << OneEditApart("cat", "dog") << "  " << 0 << endl;
    cout << OneEditApart("cat", "cats") << "  " << 1 << endl;
    cout << OneEditApart("cat", "dogs") << "  " << 0 << endl;
    cout << OneEditApart("cat", "cut") << "  " << 1 << endl;
    cout << OneEditApart("cat", "cast") << "  " << 1 << endl;
    cout << OneEditApart("cat", "at") << "  " << 1 << endl;
    cout << OneEditApart("cat", "act") << "  " << 0 << endl;
    cout << OneEditApart("cat", "og") << "  " << 0 << endl;
}
