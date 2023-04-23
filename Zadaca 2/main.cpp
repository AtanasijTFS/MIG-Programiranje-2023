#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<pair<int, pair<string, string>>> pq;

    string ime, prezime;
    int a, b, c;
    for(int i=0; i<n; i++)
    {
        cin >> ime >> prezime >> a >> b >> c;
        int priority = a*4 + b*2 +c;
        pq.push({priority, {ime, prezime}});
    }

    while(!pq.empty())
    {
        auto sleden = pq.top();
        pq.pop();
        int priority = sleden.first;
        cout << sleden.second.first << " " << sleden.second.second << endl;

        if(priority >= 4)
            priority -= 4;
        else if(priority >= 2)
            priority -= 2;
        else if(priority >= 1)
            priority--;

        if(priority != 0)
            pq.push({priority, {sleden.second.first, sleden.second.second}});
    }
    return 0;
}
