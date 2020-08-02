#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("teren.in");
ofstream fout("teren.out");
 
int s[305][305];
int n, m, sol, x;
 
void read()
{
    fin >> n >> m >> x;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            fin >> s[i][j];
            s[i][j] += s[i-1][j];
        }
    }
}
 
void solve()
{
    int sum;
    for(int i1 = 1; i1 <= n; i1++)
    {
        for(int i2 = i1; i2 <= n; i2++)
        {
            sum = 0;
            int st = 1;
            for(int dr = 1; dr <= m; dr++)
            {
                sum += (s[i2][dr] - s[i1-1][dr]);
                while(sum > x)
                {
                    sum -= (s[i2][st] - s[i1-1][st]);
                    st++;
                }
                if(st <= dr && (i2 - i1 + 1) * (dr - st + 1) > sol)
                {
                    sol = (i2 - i1 + 1) * (dr - st + 1);
                }
            }
        }
    }
    fout << sol;
}
 
int main()
{
    read();
    solve();
    return 0;
}