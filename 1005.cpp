#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll dp[32][32][910];

ll solve(ll n, ll m, ll k);

int main()
{
    int t, cs = 0;
    scanf("%d", &t);

    memset(dp, -1, sizeof(dp));

    while(t--) {
        ll n, k;
        scanf("%lld %lld", &n, &k);

        ll ans = solve(n, n, k);

        printf("Case %d: %lld\n", ++cs, ans);
    }

    return 0;
}

ll solve(ll n, ll m, ll k)
{
    if(dp[n][m][k] != -1) {
        return dp[n][m][k];
    }

    else if(k > n || k > m) {
        dp[n][m][k] = 0LL;
        return 0LL;
    }

    else if(k == 0) {
        dp[n][m][k] = 1LL;
        return 1LL;
    }

    else if(m == 1) {
        dp[n][m][k] = n;
        return n;
    }

    dp[n][m][k] = n*solve(n-1, m-1, k-1) + solve(n, m-1, k);

    return dp[n][m][k];
}
