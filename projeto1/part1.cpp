#include <iostream>
#include <vector>
#include <istream>
#include <bits/stdc++.h>
using namespace std;

typedef vector<int> sequence;
typedef vector<vector<int>> list_sequences;

void parse_input(sequence &s, list_sequences &ls)
{
    uint n;
    int value = 0;
    cin >> n;
    if (n == 1)
    {
        s = vector<int>(0);
        while (cin >> value)
        {
            s.push_back(value);
            if (cin.get() == '\n')
            {
                break;
            }
        }
    }
}

int main()
{
    sequence s;
    list_sequences ls;
    parse_input(s, ls);
    for (int i : s)
    {
        cout << i << endl;
    }
    return 0;
}
