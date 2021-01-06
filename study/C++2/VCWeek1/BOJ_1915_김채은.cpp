#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 1000;

int N, M, ans;
string arr[MAX+1];
int dp[MAX+1][MAX+1];

void Input() {
  cin >> N >> M;
  for(int i=0; i<N; ++i)
    cin >> arr[i];
}

void Solution() {
  for(int i=0; i<N; ++i){
    for(int j=0; j<M; ++j){
        if(arr[i][j]=='1'){
            if(i==0 || j==0) dp[i][j] = 1;
            else            
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            ans = max(ans, dp[i][j]);
        }
    }
  }
}
  
int main(){

  Input();
  
  Solution();

  cout << ans*ans << '\n';
  return 0;
}
