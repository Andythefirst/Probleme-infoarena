#include <iostream>
#include <fstream>
#include <queue>
 
using namespace std;
 
ifstream fin("rj.in");
ofstream fout("rj.out");
 
int a[105][105], distr[105][105], distj[105][105];
int n, m, xr, yr, xj, yj;
int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
queue < pair < int,int > > Q;
 
void citire()
{
    char s[155];
    fin >> n >> m;
    fin.get();
    for(int i = 1; i <= n; i++)
    {
        fin.getline(s + 1,150);
        for(int j = 1; j <= m; j++)
        {
            if(s[j] == ' ')
            {
                a[i][j] = 0;
            }
            else if(s[j] == 'R')
            {
                xr = i;
                yr = j;
            }
            else if(s[j] == 'J')
            {
                xj = i;
                yj = j;
            }
            else
            {
                a[i][j] = -1;
            }
        }
    }
}
 
bool ok(int i, int j)
{
    return(1 <= i && i <= n && 1 <= j && j <= m && a[i][j] != -1);
}
 
void lee(int xstart,int ystart,int d[105][105])
{
    d[xstart][ystart] = 1;
    Q.push(make_pair(xstart,ystart));
    while(!Q.empty())
    {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        for(int dir = 0; dir < 8; dir++)
        {
            int i_next = i + dx[dir];
            int j_next = j + dy[dir];
            if(ok(i_next,j_next) && (d[i_next][j_next] == 0 || d[i_next][j_next] > d[i][j] + 1))
            {
                d[i_next][j_next] = d[i][j] + 1;
                Q.push(make_pair(i_next,j_next));
            }
        }
    }
}
 
void solve()
{
    lee(xj,yj,distj);
    lee(xr,yr,distr);
    int minn = 9999999;
    int xsol, ysol;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(distr[i][j] == distj[i][j] && minn > distr[i][j] && distr[i][j] != 0)
            {
                minn = distr[i][j];
                xsol = i;
                ysol = j;
            }
        }
    }
    fout << minn << " " << xsol << " " << ysol << "\n";
}
 
int main()
{
    citire();
    solve();
    return 0;
}