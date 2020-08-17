#include <iostream>
#include <fstream>
#include <stack>
 
using namespace std;
 
ifstream fin("par.in");
ofstream fout("par.out");
 
int n, cont;
char x;
stack <char> st;
 
void rezolva()
{
    fin >> n;
    if(n % 2 != 0)
    {
        fout << -1 << "\n";
    }
    else
    {
        for(int i = 1; i <= n; i++)
        {
            fin >> x;
            if(x == '(')
            {
                st.push(x);
            }
            else if(x == ')' && !st.empty())
            {
                st.pop();
            }
            else if(x == ')' && st.empty())
            {
                st.push('(');
                cont++;
            }
        }
    }
    fout << st.size() / 2 + cont;
}
 
int main()
{
    rezolva();
    return 0;
}