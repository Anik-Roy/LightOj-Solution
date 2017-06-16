#include <bits/stdc++.h>
using namespace std;

#define SIZE_N 10000

int status[SIZE_N/2+10], prime[SIZE_N/2];

void seive()
{
    for(int i = 2; i <= SIZE_N >> 1; i++)
        status[i] = 0;

    int rt = (int)sqrt((double)SIZE_N) + 1;

    for(int i = 3; i <= rt; i += 2) {

        if(status[i>>1] == 0) {
            for(int j = i*i; j <= SIZE_N; j += i+i)
                status[j>>1] = 1;
        }
    }

    int indx = 0;

    prime[indx++] = 2;

    for(int i = 3; i <= SIZE_N; i += 2) {
        if(status[i>>1] == 0) {
            prime[indx++] = i;
        }
    }
}


int main()
{
    seive();

    int t, cs = 0;

    scanf("%d", &t);

    vector < pair <int, int> > store; // used to store prime divisors and its frequency

    while(t--) {
        int n, total = 0;
        scanf("%d", &n);

        for(int i = 0; prime[i] <= n; i++) {
            int upper = log(n) / log(prime[i]);

            for(int j = 1; j <= upper; j++) {
                total += n / (pow(prime[i], j));
            }

            store.push_back(make_pair(prime[i], total));

            total = 0;
        }

        printf("Case %d: %d = ", ++cs, n);

        for(int i = 0; i < store.size(); i++) {
            printf("%d (%d)", store[i].first, store[i].second);

            if(i != store.size()-1)
                printf(" * ");
        }

        printf("\n");

        store.clear();
    }

    return 0;
}

