#include <iostream>
#include <string>

using namespace std;

int transition(int state, char input)
{
    switch (state)
    {
    case 0:
        return (input == 'n') ? 1 : 0;
    case 1:
        return (input == 'a') ? 2 : 0;
    case 2:
        return (input == 't') ? 3 : 0;
    case 3:
        return (input == 'h') ? 4 : 0;
    case 4:
        return (input == 'a') ? 5 : 0;
    case 5:
        return (input == 'n') ? 6 : 0;
    case 6:
        return (input == 'v') ? 7 : 6;
    case 7:
        return (input == 'e') ? 8 : 7;
    case 8:
        return (input == 'n') ? 9 : 7;
    case 9:
        return (input == 'i') ? 10 : 7;
    case 10:
        return (input == 'e') ? 11 : 7;
    case 11:
        return (input == 'r') ? 12 : 7;
    case 12:
        return 12;
    default:
        return 0;
    }
}

bool dfa(string input)
{
    int state = 0;
    for (char c : input)
    {
        state = transition(state, c);
    }
    return (state == 12);
}

int main()
{
    string testCases[] = {
        "abcxyz123nathangibberishvenier567",
        "nathanvenier",
        "nathan123venier",
        "veniernathan",
        "nathxxxxven",
        "123456",
        "venier"};

    for (const string &test : testCases)
    {
        if (dfa(test))
        {
            cout << "\"" << test << "\" is accepted." << endl;
        }
        else
        {
            cout << "\"" << test << "\" is rejected." << endl;
        }
    }

    return 0;
}
