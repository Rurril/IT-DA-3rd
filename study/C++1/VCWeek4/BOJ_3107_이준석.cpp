#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main() {
	string str, str_temp;
	cin >> str;
	int cnt = 0;
	vector<string>vec;
	vector<string>result;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ':')
		{
			str_temp += str[i];
			if (i==str.length()-1&&str_temp != "")
			{
				vec.push_back(str_temp);
				cnt++;
				str_temp = "";
			}
		}
		else if (str[i] == ':')
		{
			if (str_temp != "")
			{
				vec.push_back(str_temp);
				cnt++;
				str_temp = "";
			}
			vec.push_back("-1");
		}
	}
	vec.push_back("0");
	for (int i = 0; i < vec.size()-1; i++) {
		if (vec[i] != "-1")
		{
			if (vec[i].length() == 4)
				result.push_back(vec[i]);
			else if (vec[i].length() == 3)
				result.push_back("0" + vec[i]);
			else if (vec[i].length() == 2)
				result.push_back("00" + vec[i]);
			else if (vec[i].length() == 1)
				result.push_back("000" + vec[i]);
		}
		else if (vec[i] == "-1")
		{
			if (vec[i + 1] == "-1")
			{
				for (int j = 0; j < 8 - cnt; j++)
					result.push_back("0000");
			}
		}
	}
	for (int i = 0; i < result.size()-1; i++)
		cout << result[i] << ":";
	cout << result[result.size() - 1];
	
	
}