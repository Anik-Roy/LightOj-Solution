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

int solve(ll num, ll digit)
{
    int ans = 1;

    if(digit % num == 0) {
        return ans;
    }

    ll mod = digit % num;

    while(mod) {
        mod = (mod * 10 + digit) % num;
        ans++;
    }

    return ans;
}

int main()
{
    //qsort (values, 6, sizeof(int), compare); for stl qsort
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, cs = 0;
    cin >> t;

    while(t--) {
        ll num, digit;
        cin >> num >> digit;

        int ans = solve(num, digit);

        cout << "Case " << ++cs << ": " << ans << endl;
    }

    return 0;
}
