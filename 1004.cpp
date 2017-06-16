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

int main()
{
    int t;
    sf("%d", &t);

    Test_Case(t) {
        int n;
        sf("%d", &n);

        int ara[210][210], ans[210][210];

        memset(ara, 0, sizeof(ara));
        memset(ans, 0, sizeof(ans));

        loop(i, n) {
            loop(j, i+1)
                sf("%d", &ara[i][j]);
        }

        REP(i, n, 2*n-1) {
            loop(j, 2*n-i-1) {
                sf("%d", &ara[i][j]);
            }
        }

        ans[0][0] = ara[0][0];

        loop(i, n) {
            loop(j, i+1) {
                if(j == 0)
                    ans[i][j] = ans[i-1][j] + ara[i][j];

                else
                    ans[i][j] = max(ans[i-1][j-1], ans[i-1][j]) + ara[i][j];
            }
        }

        REP(i, n, 2*n-1) {
            loop(j, i+1) {
                ans[i][j] = max(ans[i-1][j], ans[i-1][j+1]) + ara[i][j];
            }
        }

        pf("Case %d: %d\n", cs, ans[2*n-2][0]);
    }

    return 0;
}
