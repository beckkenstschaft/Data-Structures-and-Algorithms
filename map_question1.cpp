// find the character in a string with the maximum frequency.
#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

int find_frequency(string s)
{

    unordered_map<char, int> map;
    int n = s.length();
    int max = 0;
    char key;

    for (int i = 0; i < n; i++)
    {
        map[s[i]]++;
    }

    for (auto i : map)
    {
        if (i.second > max)
        {
            max = i.second;
            key = i.first;
        }
    }

    return key;
}

int main()
{
    string s;
    cout<<"ENTER STRING : ";
    
    cin>>s;
    cout<<endl;
    
    int result = find_frequency(s);
    cout<<endl<<"MOST FREQUENCT IS OF : "<<char(result)<<endl;
    
    return 0;
}