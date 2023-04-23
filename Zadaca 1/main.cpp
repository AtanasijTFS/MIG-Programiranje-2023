#include <bits/stdc++.h>

using namespace std;

int main()
{
    char c = 'x';
    stack<int> s;
    while(c != '=')
    {
        cin >> c;
        if(c=='=')
            break;
        if(c == '+' || c == '-' || c == '*')
        {
            int rez = s.top();
            s.pop();
            if(c == '+')
            {
                rez += s.top();
                s.pop();
                s.push(rez);
            }
            else if(c == '-')
            {
                rez = s.top()-rez;
                s.pop();
                s.push(rez);
            }
            else if(c == '*')
            {
                rez *= s.top();
                s.pop();
                s.push(rez);
            }
        }
        else
        {
            s.push(c-'0');
        }
    }
    int rez = 0;
    while(!s.empty())
    {
        rez += s.top();
        s.pop();
    }
    cout<<rez;

    return 0;
}
