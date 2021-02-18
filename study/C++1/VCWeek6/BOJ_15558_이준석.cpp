#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stdio.h>
using namespace std;
int arr1[100001] = { 0 };
int arr2[100001] = { 0 };
int dx[2] = { -1,1 };
int main() {
	int N, K;
	bool result = false;
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		scanf_s("%1d", &arr1[i]);
	for (int i = 1; i <= N; i++)
		scanf_s("%1d", &arr2[i]);
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(1, 1), 1));
	while (!q.empty()) {
		int num = q.front().first.first;
		int idx = q.front().first.second;
		int time = q.front().second;
		q.pop();
		if (idx >= N)
		{
			result = true;
			break;
		}
	
		for (int i = 0; i < 2; i++)
		{
			if (i == 1 && idx + dx[i] < time)
				continue;
			else {
				if (num == 1 && arr1[idx + dx[i]] != 0)
					q.push(make_pair(make_pair(num, idx+dx[i]), time++));
				
				else if(num == 2 && arr2[idx + dx[i]] != 0)
				{
					q.push(make_pair(make_pair(num, idx+dx[i]), time++));
				}
			}
		}
		if (num == 1 && (arr2[idx+K]!=0 || idx + K > N))
		{
			q.push(make_pair(make_pair(2, idx + K), time++));
		}
		else if(num == 2 && (arr2[idx + K] != 0 || idx + K > N))
			q.push(make_pair(make_pair(1, idx + K), time++));
	}
	cout << result;
}