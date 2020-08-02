#include <iostream>
#include <fstream>
#include <queue>
 
using namespace std;
 
ifstream fin("alee.in");
ofstream fout("alee.out");
 
int n, m, x1, y1, x2, y2;
int a[180][180];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
queue < pair < int, int > > Q;
 
void citire()
{
    int x, y;
    fin >> n >> m;
    for(int i = 1; i <= m; i++)
    {
        fin >> x >> y;
        a[x][y] = -1;
    }
    fin >> x1 >> y1 >> x2 >> y2;
}
 
bool ok(int i, int j)
{
    return(1 <= i && i <= n && 1 <= j && j <= n && a[i][j] != -1);
}
 
void lee()
{
    a[x1][y1] = 1;
    Q.push(make_pair(x1,y1));
    while(!Q.empty())
    {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int i_next = i + dx[dir];
            int j_next = j + dy[dir];
            if(ok(i_next,j_next) && a[i_next][j_next] < 1)
            {
                a[i_next][j_next] = 1 + a[i][j];
                Q.push(make_pair(i_next,j_next));
            }
        }
    }
    fout << a[x2][y2];
}
 
int main()
{
    citire();
    lee();
    return 0;
}