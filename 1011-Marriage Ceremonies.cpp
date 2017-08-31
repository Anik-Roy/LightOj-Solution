#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int priority[17][17];
ll dp[17][1 << 17];
int N;

bool check(int n, int pos) {
    return (bool)(n & (1 << pos));
}

int _set(int n, int pos) {
    return n = n | (1 << pos);
}

ll bitmask_dp(int jamai, int mask)
{
    ll sum = -1;

    if(jamai == N) {
        return 0LL;
    }

    if(dp[jamai][mask] != -1) {
        return dp[jamai][mask];
    }

    else {
        for(int bou = 0; bou < N; bou++) {
            if(check(mask, bou))
                continue;

            sum = max(sum, priority[jamai][bou] + bitmask_dp(jamai+1, _set(mask, bou)));
        }

        dp[jamai][mask] = sum;
        return sum;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;

    while(t--) {
        memset(dp, -1, sizeof(dp));
        cin >> N;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> priority[i][j];
            }
        }

        ll ans = bitmask_dp(0, 0);

        cout << "Case " << ++cs << ": " << ans << endl;
    }

    return 0;
}

