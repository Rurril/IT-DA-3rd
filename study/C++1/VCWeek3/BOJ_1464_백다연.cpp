#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <stack>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
//1464

string s;
string ans;
int main()
{
    cin >> s;
    ans += s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] <= ans[0])
            ans = s[i] + ans; //현재탐색하는 값이 더 크면 뒤에 붙임
        else
            ans += s[i]; //ans[0] 변경
    }
    cout << ans;
}

/*
int main()
{
    string s;
    cin >> s;

    vector <pair<int,int>> v;
    string value ="";

    for(int i = 0; i < s.size(); i++)
    {
        int num = s[i] -'A';
        v.push_back(make_pair(num,i));
    }

    cout << v[0].first << endl;

    sort(v.begin(), v.end());
   
    for(int i= 0; v.size(); i++)
    {
        value += s[v[i].second];
  
    }

    cout << value << endl;


    return 0;



}*/