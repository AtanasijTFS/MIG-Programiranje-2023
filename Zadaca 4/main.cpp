#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    unordered_map<string, string> login_user;
    string username, password;
    for(int i = 0; i < n; i++)
    {
        cin >> username >> password;
        login_user[username] = password;
    }
    vector<string> v;
    while(cin >> username && username != "KRAJ")
    {
        cin >> password;
        if(login_user[username] == password)
        {
            v.push_back("Najaven");
            break;
        }
        else
        {
            v.push_back("Nenajaven");
        }
    }
    for(string s:v)
        cout << s << endl;
    return 0;
}
