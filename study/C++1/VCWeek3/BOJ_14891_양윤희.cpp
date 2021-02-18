#include<iostream>
using namespace std;
char one[8], two[8],three[8],four[8];
int cnt, num, clock;
bool chck;
void run(char tooth[8], int clock) {
	if (clock == 1) {
		char temp = tooth[7];
		memmove(tooth + 1, tooth, sizeof(int) * 8);//오른쪽으로 배열 시프트 처리
		tooth[0] = temp;
	}
	if (clock == -1) {
		char temp = tooth[0];
		memmove(tooth, tooth+1, sizeof(int) * 8);//왼쪽으로 배열 시프트 처리
		tooth[7] = temp;
		
	}
}

void check(char a, int b) {
	if (a == b)chck = false;
	else chck = true;
}

int main (void) {
	cin >> one >> two >> three >> four;
	cin >> cnt;
	while (cnt-- > 0) {
		cin >> num >> clock;
		chck = true;
		while (chck) {
			if (num == 1) {
				run(one, clock);
				check(one[2], two[6]);
			}
			else if (num == 2) {
				run(two, clock);
				check(one[2], two[6]);
				check(two[2], three[6]);
			}
			else if (num == 3) {
				run(three, clock);
				check(two[2], three[6]);
				check(three[2], four[6]);
			}
			else if (num == 4) {
				run(four, clock);
				check(three[2], four[6]);
			}
		}
	}
	cout << (one[0] * 1) + (two[0] * 2) + (three[0] * 4) + (four[0] * 8);
}

//C언어 표준 라이브러리 함수 가이드
//void *memmove(void *dest,const void *source, size_t n); 메모리를 이동하는 함수
//배열에서 n-1 개의 원소를 한 칸씩 뒤로 이동, 원래 자리는 0으로 설정
