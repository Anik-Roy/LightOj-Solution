#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()

int ara[100010];
vector <int> tree[100010*4];

void build(int node, int i, int j)
{
    if(i == j)
    {
        tree[node].push_back(ara[i]);
        return;
    }

    int mid = (i+j) >> 1;
    int left = node << 1;
    int right = left | 1;

    build(left, i, mid);
    build(right, mid+1, j);

    merge(all(tree[left]), all(tree[right]), back_inserter(tree[node]));
    return;

}

int ans = 1e9;

void query(int node, int l, int r, int i, int j)
{
    if(l > j || i > r)
        return;

    if(i <= l && r <= j)
    {
        ans = min(ans, tree[node][0]);
        return;
    }

    int mid = (l+r) >> 1;
    int left = node << 1;
    int right = left | 1;

    query(left, l, mid, i, j);
    query(right, mid+1, r, i, j);
}

int main()
{
    int t, cs = 0;
    scanf("%d", &t);

    while(t--)
    {
        for(int i = 0; i < 400040; i++)
            tree[i].clear();

        memset(ara, 0, sizeof(ara));

        int n, q;
        scanf("%d %d", &n, &q);

        for(int i = 0; i < n; i++)
            scanf("%d", &ara[i+1]);

        build(1, 1, n);

        printf("Case %d:\n", ++cs);

        while(q--)
        {
            int i, j;
            ans = 1e10;

            scanf("%d %d", &i, &j);

            query(1, 1, n, i, j);

            printf("%d\n", ans);
        }
    }

    return 0;
}

