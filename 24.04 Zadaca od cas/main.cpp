#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> G[100];

void DFS(int pocetok)
{
    stack<pair<int, int>> s;
    s.push({pocetok, INT_MAX});
    int MIN = INT_MAX;
    auto node = s.top();
    while(!s.empty())
    {
        node = s.top();
        s.pop();
        if(G[node.first].size())
        {
            s.push(G[node.first][0]);
            if(G[node.first][0].second < MIN)
                MIN = G[node.first][0].second;
        }
    }
    cout << pocetok << " " << node.first << " " << MIN << endl;
}
int main()
{
    int n, p;
    cin >> n >> p;
    bool vlez[n+1];
    memset(vlez, 0, sizeof(vlez));
    for(int i=0; i<p; i++)
    {
        int pocetok, kraj, dijametar;
        cin >> pocetok >> kraj >> dijametar;
        G[pocetok].push_back({kraj, dijametar});
        vlez[kraj] = true;
    }
    for(int i=1; i<=n; i++)
    {
        if(!vlez[i])
            DFS(i);
    }
    return 0;
}
