#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int i, t, n, a;
    long sum;
    cin >> t;
    for(i = 1; i <= t; i++) {
        sum = 0;
        cin >> n;
        while(n--) {
            cin >> a;
            if(a > 0) {
                sum += a;
            }
        }
        printf("Case %d: %ld\n", i, sum);
    }
    return 0;
}
