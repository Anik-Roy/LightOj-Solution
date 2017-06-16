#include <bits/stdc++.h>
using namespace std;

#define SizeN 1000010
int status[SizeN / 2 + 5], Prime[79000];

void seive()
{
    int rt = (int)sqrt((double)SizeN)+1;

    for(int i = 3; i <= rt; i += 2) {
        if(status[i>>1] == 0) {
            for(int j = i*i; j <= SizeN; j += i+i) {
                status[j>>1] = 1;
            }
        }
    }
    int indx = 0;
    Prime[indx++] = 2;
    for(int i = 3; i <= SizeN; i += 2) {
        if(status[i>>1] == 0) {
            Prime[indx++] = i;
        }
    }
}

int divisor(long long n)
{
    int rt = int( sqrt((double) n)) + 1;
    int total = 1; // it holds the total number of divisors
    int total_prime = 0;
    for(int i = 0; Prime[i] < rt; i++) {
        if(n % Prime[i] == 0) {
            int cnt = 0;
            while(n % Prime[i] == 0) {
                n /= Prime[i];
                cnt++;
            }
            total *= (cnt+1);
            rt = sqrt((double)n)+1;
        }
    }
    if(n > 1) {
        total *= 2;
    }
    return total;
}

int main()
{
    seive();

    int t;

    scanf("%d", &t);

    int cs = 0;

    while(t--) {

        long long n;
        scanf("%lld", &n);

        printf("Case %d: %d\n", ++cs, divisor(n)-1);
    }
    return 0;
}

