#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int h1, m1, h2, m2;
    set<pair<int, bool>> s;
    for(int i = 0; i < n; i++)
    {
        cin >> h1 >> m1 >> h2 >> m2;
        s.insert({h1*60 + m1, 1});
        s.insert({h2*60 + m2, 0});
    }
    int temp = 0;
    int rez = 0;
    for(auto vreme:s)
    {
        if(vreme.second)
            temp++;
        else
            temp--;
        rez = max(rez, temp);
    }
    cout << rez;
    return 0;
}
