#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, cs = 0;
    double digit[1000010];

    for(int i = 1; i <= 1000000; i++)
        digit[i] = digit[i-1] + log(i);

    scanf("%d", &t);

    while(t--) {
        int n, b;
        scanf("%d %d", &n, &b);


        printf("Case %d: %d\n", ++cs, (int)(digit[n] / log(b)) + 1);
    }

    return 0;
}

