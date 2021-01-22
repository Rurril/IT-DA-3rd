#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
char a[100];
int dat[91];

int main() {
    cin >> a;
    for (int i = 0; i < strlen(a); i++) {
        dat[a[i]]++;
    }
    for (int i = 65; i < 91; i++) {
        if (dat[i] > 0) {
            for (int j = 0; j < dat[i]; j++) {
                cout <<(char)i;
            }
        }
    }
}