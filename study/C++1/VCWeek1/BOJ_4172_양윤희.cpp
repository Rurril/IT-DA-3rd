#include<cstdio>
#include<cmath>

int x[1000001] = { 1 };

int main() {
    for (int i = 1;i <= 1000000;++i) {
        x[i] = x[(int)(i - sqrt(i))];
        x[i] = (x[i] + x[(int)log(i)]) % 1000000;
        x[i] = (x[i] + x[(int)(i * sin(i) * sin(i))]) % 1000000;
    }
    while (true) {
        int n;
        scanf("%d", &n);
        if (n == -1) break;
        printf("%d\n", x[n]);
    }
    return 0;
}