#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N; cin >> N;
	vector<string> daegun,yeongsik;
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		daegun.push_back(s);
	}
	for (int i = 0; i < N; i++)
	{
		string s; cin >> s;
		yeongsik.push_back(s);
	}

	int answer = 0;
	while (!yeongsik.empty())
	{
		int idx = find(daegun.begin(),daegun.end(),yeongsik.front())-daegun.begin();

		if (idx != 0)
		{
			answer++;
			daegun.erase(daegun.begin() + idx);
			yeongsik.erase(yeongsik.begin());
		}
		else
		{
			daegun.erase(daegun.begin());
			yeongsik.erase(yeongsik.begin());
		}
	}

	cout << answer;

	return 0;
}
