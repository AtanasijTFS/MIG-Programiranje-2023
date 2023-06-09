#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string findstring(string s)
{
    int n = s.size();
    unordered_map<string, int> freq;
    int maxFreq = 0;
    string maxSubstring;

    for (int i=0; i<n; i++)
    {
        for (int j=1; j<=n-i; j++)
        {
            string substring = s.substr(i, j);
            freq[substring]++;
            if (freq[substring] > maxFreq)
            {
                maxFreq = freq[substring];
                maxSubstring = substring;
            }
            else if (freq[substring] == maxFreq && substring.length() > maxSubstring.length())
            {
                maxSubstring = substring;
            }
            else if (freq[substring] == maxFreq && substring.length() == maxSubstring.length() && substring < maxSubstring)
            {
                maxSubstring = substring;
            }
        }
    }

    return maxSubstring;
}

int main()
{
    string s;
    cin >> s;
    string sfinal = findstring(s);
    cout << sfinal << endl;

    return 0;
}
