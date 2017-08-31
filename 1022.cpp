#include <bits/stdc++.h>
using namespace std;

#define INF 10000000000
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
    return a.fi > b.fi;
}

/*
int values[] = { 40, 10, 100, 90, 20, 25 }; for stl qsort

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}
*/

int main()
{
    //qsort (values, 6, sizeof(int), compare); for stl qsort

    int t, cs = 0;
    sf("%d", &t);

    while(t--) {
        double r;
        sf("%lf", &r);

        double SqArea = pow((2*r), 2);
        double ciArea = 2*acos(0.0) * r * r;
        double ans = fabs(SqArea-ciArea) + (double)1e-9;

        pf("Case %d: %.2lf\n", ++cs, ans);
    }

    return 0;
}
