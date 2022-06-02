#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <memory>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <numeric>

using namespace std;

int main()
{
    // cin.tie(nullptr);
    // cout.tie(NULL);
    // ios_base::sync_with_stdio(false);

    deque<int> deques;

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        vector<char> commands;
        string commandLine;
        getline(cin, commandLine);
        istringstream cmd{commandLine};
        char c;
        while (cmd >> c)
        {
            commands.push_back(c);
        }
        int count;
        cin >> count;
        cin.ignore();
        deque<int> numbers(count);

        string inputs;
        getline(cin, inputs);
        vector<string> parsing;
        istringstream number{inputs};
        if (count > 1)
        {
            string buffer;
            while (getline(number, buffer, ','))
            {
                parsing.push_back(buffer);
            }

            string first = parsing[0];
            parsing[0] = first.substr(1);
            string last = parsing[parsing.size() - 1];
            parsing[parsing.size() - 1] = last.substr(0, last.length() - 1);
        }
        else if (count == 1)
        {
            parsing.push_back(inputs.substr(1, inputs.length() - 2));
        }

        int frontOrBack = 1;
        int index = 0;
        if (count > 0)
        {
            for (auto p : parsing)
            {
                // cout << p << ' ';
                numbers[index] = stoi(p);
                index++;
            }
        }

        // for (auto p : numbers)
        // {
        //     cout << p << '\n';
        // }

        int error = 0;
        for (auto c : commands)
        {
            if (c == 'R')
            {
                frontOrBack *= -1;
            }
            else if (c == 'D')
            {
                if (numbers.size() == 0)
                {
                    cout << "error" << '\n';
                    error = 1;
                    break;
                }
                else
                {

                    if (frontOrBack > 0)
                    {
                        numbers.pop_front();
                    }
                    else
                    {
                        numbers.pop_back();
                    }
                }
            }
            else
            {
                cout << "error" << '\n';
                error = 1;
                break;
            }
        }

        if (!error)
        {
            cout << '[';
            if (numbers.size() > 0)
            {
                if (frontOrBack > 0)
                {
                    for (int i = 0; i < numbers.size() - 1; i++)
                    {
                        cout << numbers[i] << ',';
                    }
                    cout << numbers[numbers.size() - 1];
                }
                else
                {
                    for (int i = numbers.size() - 1; i > 0; i--)
                    {
                        cout << numbers[i] << ',';
                    }
                    cout << numbers[0];
                }
            }
            cout << ']' << '\n';
        }
    }
}
