#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("font","r",stdin);
    for(int i=0;i<600;i++)
    {
        if(i%20==0)
        {
            int x=i/20+1;   
            string t="txt"+to_string(x)+".html";
            freopen(t.c_str(),"w",stdout);
        }
        string s;
        getline(cin,s);
        cout<<s.substr(4,s.length())<<endl;
        if(i%20==19)
        {
            fclose(stdout);
        }
    }
    return 0;
}