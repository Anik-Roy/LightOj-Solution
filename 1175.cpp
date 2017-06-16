#include <bits/stdc++.h>
using namespace std;

#define mp                    make_pair
#define pb                    push_back

const int fx[] = { -1, 1, 0, 0 };
const int fy[] = { 0, 0, -1, 1 };

int r, c;

char ara[202][202];
int level[202][202];
bool visited[202][202];

vector < pair <int, int> > v;

bool is_valid(int x, int y)
{
    if(x >= 0 && x < r && y >= 0 && y < c)
        return true;
    return false;
}

void bfs1()
{
    queue < pair <int, int> > q;

    for(int i = 0; i < v.size(); i++) {
        q.push(make_pair(v[i].first, v[i].second));
        visited[v[i].first][v[i].second] = true;
        level[v[i].first][v[i].second] = 0;
    }

    while(!q.empty()) {
        pair <int, int> pii = q.front();
        q.pop();


        for(int k = 0; k < 4; k++) {
            int x = pii.first + fx[k];
            int y = pii.second + fy[k];

            if(is_valid(x, y) && !visited[x][y] && ara[x][y] == '.') {
                q.push(make_pair(x, y));
                visited[x][y] = true;
                level[x][y] = level[pii.first][pii.second] + 1;
            }
        }
    }
}

long long bfs2(int i, int j)
{
    queue < pair <int, int> > q;

    q.push(make_pair(i, j));
    level[i][j] = 0;
    visited[i][j] = true;

    while(!q.empty()) {

        pair <int, int> pii = q.front();
        q.pop();

        if(pii.first == 0 || pii.first == r-1 || pii.second == 0 || pii.second == c-1)
            return level[pii.first][pii.second];

        for(int k = 0; k < 4; k++) {
            int x = pii.first + fx[k];
            int y = pii.second + fy[k];

            if( is_valid(x, y) && !visited[x][y] && ara[x][y] == '.' && level[x][y] > level[pii.first][pii.second] + 1) {
                visited[x][y] = true;
                level[x][y] = level[pii.first][pii.second] + 1;

                q.push(make_pair(x, y));
            }
        }
    }
    return -1;
}

int main()
{
    int t;

    scanf("%d", &t);

    for(int cs = 1; cs <= t; cs++)
    {
        v.clear();

        scanf("%d %d", &r, &c);

        int jr = 0, jc = 0;

        for(int i = 0; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                cin >> ara[i][j];

                visited[i][j] = false;
                level[i][j] = 100000;

                if(ara[i][j] == 'J')
                    jr = i, jc = j;
                else if(ara[i][j] == 'F')
                {
                    v.pb(mp(i, j));
                }
            }
        }

        bfs1();

        memset(visited, false, sizeof(visited));

        long long res = bfs2(jr, jc);

        if(res == -1)
            printf("Case %d: IMPOSSIBLE\n", cs);

        else
            printf("Case %d: %d\n", cs, res+1);

    }
    return 0;
}
