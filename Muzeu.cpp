#include <iostream>
#include <fstream>
#include <queue>
 
using namespace std;
 
ifstream fin("muzeu.in");
ofstream fout("muzeu.out");
 
int n;
int b[255][255];
char a[255][255];
queue < pair < int, int > > Q;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
 
void citire()
{
    fin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            b[i][j] = -1;
            fin >> a[i][j];
            if(a[i][j] == 'P')
            {
                Q.push(make_pair(i,j));
                b[i][j] = 0;
            }
            if(a[i][j] == '#')
            {
                b[i][j] = -2;
            }
        }
    }
}
 
bool ok(int i, int j)
{
    return(b[i][j] == -1 && 1 <= i && i <= n && 1 <= j && j <= n);
}
 
void lee()
{
    while(!Q.empty())
    {
        int i = Q.front().first;
        int j = Q.front().second;
        Q.pop();
        for(int dir = 0; dir < 4; dir++)
        {
            int i_next = i + dx[dir];
            int j_next = j + dy[dir];
            if(ok(i_next,j_next) && a[i_next][j_next] == '.')
            {
                b[i_next][j_next] = 1 + b[i][j];
                Q.push(make_pair(i_next,j_next));
            }
        }
    }
}
 
void afisare()
{
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            fout << b[i][j] << " ";
        }
        fout << "\n";
    }
}
 
int main()
{
    citire();
    lee();
    afisare();
    return 0;
}