#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <utility>
#include <iomanip>
#include <sstream>
#include <cstdlib>
#include <iterator>
#include <algorithm>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <math.h>
#include <ctime>
#include <cmath>
#include <cstring>
#include <climits>
#include <stdbool.h>


using namespace std;

#define PI                    3.141592653589793
#define ff                    first
#define ss                    second
#define EPS                   1e-9
#define mp                    make_pair
#define pb                    push_back
#define eb                    emplace_back
#define all(x)                (x).begin(), (x).end()
#define clr(ara)              memset(ara, 0, sizeof(ara))
#define setdp(ara)            memset(ara, -1, sizeof(ara))
#define White                 0
#define Grey                  1
#define Black                 2
#define Test_Case(a)             for(int i = 1; i <= t; i++)
#define REP(i, a, b)      for(int i=a;i<b;i++)
#define loop(i,n)       for(int i=0;i<n;i++)

/*
template <class T> T gcd(T a,T b){ if(b == 0) return a; return gcd( b,a % b ); }
template <class T> T lcm(T a, T b ){ return ( a * b ) / gcd( a,b ); }
template<class T> string ToString(const T &x){ stringstream s; s << x; return s.str(); }
template<class T> int ToInteger(const T &x){ stringstream s; s << x; int r; s >> r; return r; }
*/

const int fx[] = { -1, 1, 0, 0 }; /// 4 side moves.
const int fy[] = { 0, 0, -1, 1 };
const int dx[] = { 1, 1, 0, -1, -1, -1, 0, 1 }; /// 8 side moves.
const int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
const int kx[] = { 1, 1, -1, -1, 2, 2, -2, -2 }; /// Knight Moves.
const int ky[] = { 2, -2, 2, -2, 1, -1, 1, -1 };

typedef  long long int            ll;
typedef  map<string,int>          msi;
typedef  map<string, string>      mss;
typedef  map<int,int>	          mii;
typedef  map<ll, ll>              mll;
typedef  map<char,int>            mci;
typedef  map<int,string>	      mis;
typedef  pair<int,int> 	          pii;
typedef  pair<string, int>        psi;
typedef  pair<string, string>     pss;
typedef  vector<int> 	          vi;
typedef  vector<string> 	      vs;
typedef  vector<char>	          vc;
typedef  vector<bool>             vb;
typedef  vector< pii >             vii;

template<class T1> void print(T1 e1)
{
    cout << e1 << endl;
}
template<class T1,class T2> void print(T1 e1, T2 e2)
{
    cout << e1 << " " << e2 << endl;
}
template<class T1,class T2,class T3> void print(T1 e1, T2 e2, T3 e3)
{
    cout << e1 << " " << e2 << " " << e3 << endl;
}

#define SF                    scanf
#define PF                    printf

#define SF1(a)                scanf("%d", &a)
#define SF2(a,b)              scanf("%d %d",&a, &b)
#define SF3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

#define SF1ll(a)              scanf("%I64d", &a)
#define SF2ll(a,b)            scanf("%I64d %I64d", &a, &b)
#define SF3ll(a,b,c)          scanf("%I64d %I64d %I64d", &a, &b, &c)

#define READ                  freopen("input.txt", "r", stdin);
#define WRITE                 freopen("output.txt", "w", stdout);

int dp[110][110];
string s;

int interval_dp(int low, int high)
{
    if(low >= high)
        return 0;

    if(dp[low][high] != -1)
        return dp[low][high];

    if(s[low] != s[high])
        return dp[low][high] = 1 + min(interval_dp(low+1, high), interval_dp(low, high-1));
    else
        return dp[low][high] = interval_dp(low+1, high-1);
}

int main()
{
    int t, cs = 0;

    SF1(t);

    Test_Case(t) {
        cs++;

        setdp(dp);

        cin >> s;

        int len = s.size();

        int res = interval_dp(0, len-1);

        PF("Case %d: %d\n", cs, res);
    }
    return 0;
}

