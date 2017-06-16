#include <bits/stdc++.h>
using namespace std;

#define mp                    make_pair
#define pb                    push_back

#define clr(ara)              memset(ara, 0, sizeof(ara))

const int fx[] = { -1, 1, 0, 0 };
const int fy[] = { 0, 0, -1, 1 };

typedef  pair<int,int>            pii;

#define SF                    scanf
#define PF                    printf

#define SF1(a)                scanf("%d", &a)
#define SF2(a,b)              scanf("%d %d",&a, &b)
#define SF3(a,b,c)            scanf("%d %d %d", &a, &b, &c)

int r, c;

char ara[210][210];
int level[210][210];
bool visited[210][210];

vector < pair <int, int> > v;

bool is_valid(int x, int y)
{
    if(x >= 0 && x < r && y >= 0 && y < c)
        return true;
    return false;
}

void dfs1(int i, int j)
{
    for(int k = 0; k < 4; k++)
    {
        int x = i+fx[k];
        int y = j+fy[k];

        if(is_valid(x, y) && ara[x][y] == '.' && level[x][y] > level[i][j] + 1)
        {
            level[x][y] = level[i][j] + 1;
            dfs1(x, y);
        }
    }
}

long long mini;
bool flag = false;

int indx1, indx2;

long long dfs2(int i, int j)
{
    if(i == 0 || i == r-1 || j == 0 || j == c-1)
    {
        if(mini > level[i][j])
            mini = level[i][j];

        flag = true;
        //return mini;
    }

    else for(int k = 0; k < 4; k++)
    {
        int x = i+fx[k];
        int y = j+fy[k];

        if(is_valid(x, y) && ara[x][y] == '.' && level[x][y] > level[i][j]+1)
        {
            level[x][y] = level[i][j] + 1;
            dfs2(x, y);
        }
    }

    if(flag)
        return mini;

    return -1;
}

int main()
{
    int t;

    SF1(t);

    for(int cs = 1; cs <= t; cs++)
    {

        flag = false;
        mini = 100000000;

        v.clear();

        SF2(r, c);

        int jr = 0, jc = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin >> ara[i][j];
                level[i][j] = 1000000;
                visited[i][j] = false;

                if(ara[i][j] == 'J')
                    jr = i, jc = j;
                else if(ara[i][j] == 'F')
                {
                    v.pb(mp(i, j));
                }
            }
        }

        for(int i = 0; i < (int)v.size(); i++)
        {
            level[v[i].first][v[i].second] = 0;
            dfs1(v[i].first, v[i].second);
        }

        level[jr][jc] = 0;

        memset(visited, false, sizeof(visited));

        long long res = dfs2(jr, jc);

        if(res == -1)
            PF("Case %d: IMPOSSIBLE\n", cs);

        else
            PF("Case %d: %lld\n", cs, res+1);
    }
    return 0;
}
