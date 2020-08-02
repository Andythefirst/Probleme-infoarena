#include <iostream>
#include <fstream>
 
using namespace std;
 
ifstream fin("trompeta.in");
ofstream fout("trompeta.out");
 
int n, m, top;
char sir[1000005], sol[1000005];
 
int main()
{
    fin >> n >> m >> sir;
    sol[++top] = sir[0];
    for(int i = 1; i < n; i++)
    {
        while(top > 0 && sir[i] > sol[top] && top + n - i - 1 >= m)
        {
            top--;
        }
        if(top < m)
        {
            sol[++top] = sir[i];
        }
    }
    fout << (sol + 1);
    return 0;
}