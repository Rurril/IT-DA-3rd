#include<iostream>
#include<vector>
#include<string>

using namespace std;

int K;

vector<int> wheel[4];
vector<pair<int, int>> cmd;


void Input()
{
    for (int i = 0; i < 4; i++)
    {
        string inp;
        cin >> inp;
        for (int j = 0; j < inp.length(); j++)
        {
            int tmp = inp[j] - '0';
            wheel[i].push_back(tmp);
        }
    }

    cin >> K;
    for (int i = 0; i < K; i++)
    {
        int num, dir;
        cin >> num >> dir;
        num--;
        cmd.push_back(make_pair(num, dir));
    }
}

void UpdateWheel(int n, int d)
{
    if (d == 1)
    {
        int tmp = wheel[n].at(7);
        for (int i = 7; i > 0; i--)
        {
            wheel[n].at(i) = wheel[n].at(i - 1);
        }
        wheel[n].at(0) = tmp;
    }
    else if (d == -1)
    {
        int Tmp = wheel[n].at(0);
        for (int i = 0; i < 7; i++)
        {
            wheel[n].at(i) = wheel[n].at(i + 1);
        }
        wheel[n].at(7) = Tmp;
    }
}

void Turn(int n, int d)
{
    if (n == 0)
    {
        if (wheel[n].at(2) != wheel[n + 1].at(6))
        {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6))
            {
                if (wheel[n + 2].at(2) != wheel[n + 3].at(6))
                {
                	UpdateWheel(n, d);
                	UpdateWheel(n + 1, d * -1);
                	UpdateWheel(n + 2, d);
                	UpdateWheel(n + 3, d * -1);
                }
                else
                {
                	UpdateWheel(n, d);
                	UpdateWheel(n + 1, d * -1);
                	UpdateWheel(n + 2, d);
                }
            }
            else
            {
            	UpdateWheel(n, d);
            	UpdateWheel(n + 1, d * -1);
            }
        }
        else
        {
        	UpdateWheel(n, d);
        }
    }
    else if (n == 1)
    {
        if (wheel[n].at(6) != wheel[n-1].at(2))
        {
        	UpdateWheel(n - 1, d * -1);
        }

        if (wheel[n].at(2) != wheel[n + 1].at(6))
        {
            if (wheel[n + 1].at(2) != wheel[n + 2].at(6))
            {
            	UpdateWheel(n, d);
            	UpdateWheel(n + 1, d * -1);
            	UpdateWheel(n + 2, d);
            }
            else
            {
            	UpdateWheel(n, d);
            	UpdateWheel(n + 1, d * -1);
            }
        }
        else
        {
        	UpdateWheel(n, d);
        }
    }
   //2,3 동일하게
}

void Solution()
{
    for (int i = 0; i < cmd.size(); i++)
    {
        int N = cmd[i].first;
        int D = cmd[i].second;

        Turn(N, D);
    }

    int Answer = 0;
    if (wheel[0].at(0) == 1) Answer += 1;
    if (wheel[1].at(0) == 1) Answer += 2;
    if (wheel[2].at(0) == 1) Answer += 4;
    if (wheel[3].at(0) == 1) Answer += 8;

    cout << Answer << endl;
}

int main(void)
{

	Input();
    Solution();

    return 0;
}



