#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string s; cin >> s;

	if (s == "::")
	{
		cout << "0000:0000:0000:0000:0000:0000:0000:0000"; return 0;
	}
	vector<string> answer;
	string temp = ""; int idx = -1; bool flag = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ':')
		{
			if(!temp.empty())
			{
				while (temp.length() < 4)
					temp = "0" + temp;
				answer.push_back(temp);

				temp = "";
			}
			if (s[i + 1] == ':')
			{
				idx = answer.size();
				flag = true;
			}
		}
		else
			temp += s[i];
	}
	if (flag)
	{
		while (answer.size() < 7)
			answer.insert(answer.begin() + idx++, "0000");
	}
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << ":";
	if (!temp.empty())
	{
		while (temp.length() < 4)
			temp = "0" + temp;
		cout << temp;
	}
	else if (answer.size() < 8)
		cout << "0000";

	return 0;
}
