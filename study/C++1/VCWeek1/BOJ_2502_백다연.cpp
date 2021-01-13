#include <iostream>
#include <queue>
#include <vector>
#include <math.h>
#include <string.h>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
//2502 
int fib(int num)
{
    int value = 1;
    if(num == 1 || num == 2)
      return value;

    int x = 1; 
    int y = 1;
    for(int i = 3; i <= num; i++)
    {
      value = x + y;
      x = y;
      y = value;
    }
    return value;
     
}


int main()
{
  int d, k;
  int a = 1;
  int b = 0;
  int cnt = 0;

  cin >> d >> k;

  int x = fib(d-2); //a계수
  int y = fib(d-1); //b계수

  while(true)
  {
    cnt = 0;
    cnt += x * a;
    b = 1;

    while(true)
    {
      cnt += y * b;
      if(cnt > k) //a를 증가
          break;
      if(cnt == k)
      {
        cout << a << endl;
        cout << b << endl;
        return 0;
      }
      cnt -= y * b;
      b++;
    }
    a++;

  }


}