//#include <iostream>
//#include<math.h>
//#include<algorithm>
//#include<stdlib.h>
//using namespace std;
//int sticker[2][100001];
//int t, n;
//int cnt;
//int sum[10];
//int direct[4][2] = { 1,0,0,1,-1,0,0,-1 };
//
//void func(int y, int x) { //위아래양옆 스티커 초기화
//	for (int i = 0; i < 4; i++) {
//		int ny = y + direct[i][0];
//		int nx = x + direct[i][1];
//		if (nx < 0 || nx>(n-1) || ny < 0 || ny>1) {
//			continue;
//		} 
//		else if (sticker[ny][nx] == 0) { continue; }
//		else {
//			sticker[ny][nx] = 0;
//		}
//	}
//}
//
//int max() { //가장 큰 값 구하기
//	int max = 0;
//	int x=0, y=0;
//	for (int i = 0; i < 2; i++) {
//		for (int j = 0; j < n; j++) {
//			if (sticker[i][j] == 0)continue;
//			if (max < sticker[i][j]) {
//				max = sticker[i][j];
//				y = i; x = j;
//			}
//		}
//	}
//	sticker[y][x] = 0;
//	cnt += max;
//	func(y, x);
//	return max;
//}
//
//int main(void) {
//	cin >> t;
//	while(t-- > 0) {
//		cin >> n;
//		for (int i = 0; i < 2; i++) {
//			for (int j = 0; j < n; j++) {
//				cin >> sticker[i][j];
//			}
//		}
//		cnt = 0;
//		while (max()) {
//		}
//		cout << cnt<<endl;
//	}
//}