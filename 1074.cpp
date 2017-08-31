#include <bits/stdc++.h>
using namespace std;


#define INF 2000000
#define fi                    first
#define se                    second
#define mp                    make_pair
#define pb                    push_back
#define clr(ara)              memset(ara, 0, sizeof(ara))
#define dp(ara)               memset(ara, -1, sizeof(ara))
#define White                 0
#define Grey                  1
#define Black                 2

#define sf                    scanf
#define pf                    printf

#define test_case(a)          for(int cs = 1; cs <= t; cs++)
#define rep(i, a, b)          for(int i=a;i<b;i++)
#define loop(i,n)             for(int i=0;i<n;i++)

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

struct data
{
    int u, v, w;

    data() {}
    data(int _u, int _v, int _w) : u(_u), v(_v), w(_w) {}
};

int business[210];
int n, m;
data edges[100010];
int dist[210];

int cube(int x)
{
    return x*x*x;
}

void bellman_ford(int src)
{
    for(int i = 1; i <= n+2; i++)
        dist[i] = INF;

    dist[src] = 0;

    for(int i = 1; i <= n-1; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(dist[edges[j].v] > dist[edges[j].u] + edges[j].w)
            {
                dist[edges[j].v] = dist[edges[j].u] + edges[j].w;
            }
        }
    }

    while(1)
    {
        int j;

        for(j = 1; j <= m; j++)
        {
            if(dist[edges[j].v] == -INF)
                continue;

            if(dist[edges[j].u] < INF && dist[edges[j].v] > dist[edges[j].u] + edges[j].w && !cycle[edges[j].u])
            {
                dist[edges[j].v] = -INF;
                break;
            }
        }

        if(j > m)
            break;
    }
}

int main()
{
    int t, cs = 0;
    sf("%d", &t);

    while(t--)
    {
        int q;
        sf("%d", &n);

        clr(dist);
        clr(dist);
        clr(business);

        loop(i, n)
        {
            sf("%d", &business[i+1]);
        }

        sf("%d", &m);

        loop(i, m)
        {
            int a, b;
            sf("%d %d", &a, &b);

            edges[i+1] = data(a, b, cube(business[b]-business[a]));
        }

        int src = 1;

        bellman_ford(src);

        pf("Case %d:\n", ++cs);

        sf("%d", &q);

        while(q--)
        {
            int destination;
            sf("%d", &destination);

            if(dist[destination] < 3 || dist[destination] > 200000)
                pf("?\n");
            else
                pf("%d\n", dist[destination]);
        }
    }

    return 0;
}

