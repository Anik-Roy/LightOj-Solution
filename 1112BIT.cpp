#include <bits/stdc++.h>
using namespace std;

#define Max 100010

typedef long long ll;

ll ara[Max], tree[Max];

ll query(ll idx)
{
    ll sum = 0;

    while(idx > 0) {
        sum += tree[idx];
        idx -= (idx & -idx);
    }

    return sum;
}

void update(ll idx, ll x, ll n) {// n is the number of element
    while(idx <= n) {
        tree[idx] += x;
        idx += (idx & -idx);
    }
}

int main()
{
    ll t, n, q;
    scanf("%lld", &t);

    for(ll cs = 1; cs <= t; cs++)
    {
        memset(ara, 0, sizeof(ara));
        memset(tree, 0, sizeof(tree));

        scanf("%lld %lld", &n, &q);

        for(ll i = 1; i <= n; i++) {
            scanf("%lld", &ara[i]);

            update(i, ara[i], n);
        }

        printf("Case %lld:\n", cs);

        for(ll i = 1; i <= q; i++)
        {
            ll type;
            scanf("%lld", &type);

            if(type == 1)
            {
                ll u;
                scanf("%lld", &u);

                printf("%lld\n", ara[u+1]);

                update(u+1, -ara[u+1], n);

                ara[u+1] = 0;

            }

            else if(type == 2)
            {
                ll u, v;
                scanf("%lld %lld", &u, &v);

                ara[u+1] += v;

                update(u+1, v, n);
            }

            else if(type == 3)
            {
                ll u, v;
                scanf("%lld %lld", &u, &v);

                ll res1 = query(u);
                ll res2 = query(v+1);
                printf("%lld\n", res2-res1);
            }
        }
    }

    return 0;
}
