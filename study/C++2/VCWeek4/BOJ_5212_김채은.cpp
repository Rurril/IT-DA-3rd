#include <iostream>

using namespace std;

int R, C;
string now[11];
char future[11][11];

void Input()
{
	cin >> R >> C;

	int i = 0;
	string input;
	while (i < R)
	{
		cin >> input;
		now[i++] = input;
	}
}

int CntOcean(int x, int y)
{
	if(now[x][y] == '.') return -1;

	int cnt = 0;
	if (now[x-1][y] == '.' || x == 0)	cnt++;
	if (now[x+1][y] == '.' || x == R-1)	cnt++;
	if (now[x][y-1] == '.' || y == 0)	cnt++;
	if (now[x][y+1] == '.' || y == C-1)	cnt++;

	if (cnt >= 3)
		return -1;
	return 1;
}

void DrawMap()
{
	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			if(CntOcean(i, j) == 1)
				future[i][j] = 'X';
			else
				future[i][j] = '.';
		}
	}
}

void PrintMap()
{
	int startR = R-1;
	int startC = C-1;
	int endR = 0;
	int endC = 0;

	for (int i=0; i<R; i++)
	{
		for (int j=0; j<C; j++)
		{
			if (future[i][j] == 'X')
			{
				startR = startR > i ? i : startR;
				startC = startC > j ? j : startC;
				endR = endR < i ? i : endR;
				endC = endC < j ? j : endC;
			}
		}
	}

	for (int k = startR; k <= endR; k++) {
		for (int l = startC; l <= endC; l++)
			cout << future[k][l];
		cout << endl;
	}
}

int main()
{
	Input();

	DrawMap();

	PrintMap();

	return 0;
}

