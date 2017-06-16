#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;

#define fi                    first
#define se                    second
#define mp                    make_pair
#define pb                    push_back
#define clr(ara)              memset(ara, 0, sizeof(ara))
#define dp(ara)            memset(ara, -1, sizeof(ara))
#define White                 0
#define Grey                  1
#define Black                 2

#define sf                    scanf
#define pf                    printf

#define Test_Case(a)             for(int cs = 1; cs <= t; cs++)
#define REP(i, a, b)      for(int i=a;i<b;i++)
#define loop(i,n)       for(int i=0;i<n;i++)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);

int fx[] = { -1, 1, 0, 0 };
int fy[] = { 0, 0, -1, 1 };

int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int kx[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; // Knight Moves.
int ky[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

typedef  long long            ll;

typedef  map <int,int>	           mii;
typedef  map <int,string>	       mis;
typedef  map <ll, ll>              mll;
typedef  map <char,int>            mci;
typedef  map <string,int>          msi;
typedef  map <string, string>      mss;

typedef  pair <int,int> 	       pii;
typedef  pair <ll, ll>             pll;
typedef  pair <char,int>           pci;
typedef  pair <string,int>         psi;
typedef  pair <string, string>     pss;

typedef  vector<int> 	           vi;
typedef  vector<string> 	       vs;
typedef  vector<char>	           vc;
typedef  vector<bool>              vb;
typedef  vector < pii>             vii;

bool cmp(const pii &a, const pii &b)
{
    return a.fi < b.fi;
}


void init(int node, int b, int e, int ara[], int treeMin[], int treeMax[])
{
    if(b == e)
    {
        treeMin[node] = ara[b];
        treeMax[node] = ara[b];
        return;
    }

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    init(left, b, mid, ara, treeMin, treeMax);
    init(right, mid+1, e, ara, treeMin, treeMax);

    treeMin[node] = min(treeMin[left], treeMin[right]);
    treeMax[node] = max(treeMax[left], treeMax[right]);
}

int queryMin(int node, int b, int e, int i, int j, int treeMin[])
{
    if(i > e || j < b) // outside of current node
        return 1e9;

    else if(b >= i && e <= j)
        return treeMin[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int p1 = queryMin(left, b, mid, i, j, treeMin);
    int p2 = queryMin(right, mid+1, e, i, j, treeMin);

    return min(p1, p2);
}

int queryMax(int node, int b, int e, int i, int j, int treeMax[])
{
    if(i > e || j < b) // outside of current node
        return -1;

    else if(b >= i && e <= j)
        return treeMax[node];

    int left = node*2;
    int right = node*2+1;
    int mid = (b+e)/2;

    int p1 = queryMax(left, b, mid, i, j, treeMax);
    int p2 = queryMax(right, mid+1, e, i, j, treeMax);

    return max(p1, p2);
}

int main()
{
    int t;
    sf("%d", &t);

    Test_Case(t)
    {
        int n, d;
        sf("%d %d", &n, &d);

        int ara[100010];
        int treeMin[300010], treeMax[300010];

        for(int i = 1; i <= n; i++)
            sf("%d", &ara[i]);

        init(1, 1, n, ara, treeMin, treeMax);
        int ans = 0;

        for(int i = 1; i <= n-d+1; i++) {
            int mini = queryMin(1, 1, n, i, i+d-1, treeMin);
            int maxi = queryMax(1, 1, n, i, i+d-1, treeMax);

            ans = max(ans, abs(maxi - mini));
        }

        pf("Case %d: %d\n", cs, ans);
    }

    return 0;
}
