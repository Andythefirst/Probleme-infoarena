#include <iostream>
#include <fstream>
#include <stack>
 
using namespace std;
 
ifstream fin("parantezare.in");
ofstream fout("parantezare.out");
 
const int NMAX = 100005;
char s[NMAX];
int m;
int sol[NMAX];
stack <int> st;
 
void rezolva()
{
    for(int i = 0; s[i] != 0; i++)
    {
        if(s[i] == '(')
        {
            st.push(i);
        }
        else if(s[i] == ')')
        {
            int x = st.top();
            st.pop();
            sol[x] = i;
        }
    }
}
 
int main()
{
    int x;
    fin >> s;
    fin >> m;
    rezolva();
    while(m--)
    {
        fin >> x;
        fout << sol[x] << " ";
    }
    return 0;
}