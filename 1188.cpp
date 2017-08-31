#include <bits/stdc++.h>
using namespace std;

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

#define Max 100010

int ara[Max], cnt[Max];
int BLOCK_SIZE;
int tot;

inline bool mo_cmp(const pair< pair<int, int>, int> &x,
        const pair< pair<int, int>, int> &y)
{
    int block_x = x.first.first / BLOCK_SIZE;
    int block_y = y.first.first / BLOCK_SIZE;
    if(block_x != block_y)
        return block_x < block_y;
    return x.first.second < y.first.second;
}

void add(int idx)
{
    cnt[ara[idx]]++;

    if(cnt[ara[idx]] == 1)
        tot++;
}

void remove(int idx)
{
    cnt[ara[idx]]--;

    if(cnt[ara[idx]] == 0)
        tot--;
}

int main()
{
    int t, cs = 0;
    sf("%d", &t);

    while(t--) {
        clr(ara);
        clr(cnt);

        int n, q;
        sf("%d %d", &n, &q);

        loop(i, n) {
            sf("%d", &ara[i]);
        }

        BLOCK_SIZE = static_cast<int> (sqrt(n));
        pf("Case %d:\n", ++cs);

        pair < pair <int, int>, int> queries[100010];

        loop(i, q) {
            sf("%d %d", &queries[i].first.first, &queries[i].first.second);
            queries[i].second = i;
        }

        sort(queries, queries+q, mo_cmp);

        int mo_left = 0, mo_right = -1;
        tot = 0;

        int ans[Max];

        loop(i, q) {
            int left = queries[i].first.first-1;
            int right = queries[i].first.second-1;
            int id = queries[i].second;

            while(mo_right < right) {
                mo_right++;
                add(mo_right);
            }

            while(mo_right > right) {
                remove(mo_right);
                mo_right--;

            }

            while(mo_left > left) {
                mo_left--;
                add(mo_left);
            }

            while(mo_left < left) {
                remove(mo_left);
                mo_left++;
            }

            ans[id] = tot;
        }

        loop(i, q)
            pf("%d\n", ans[i]);
    }

    return 0;
}

