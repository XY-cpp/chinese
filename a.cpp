#include<bits/stdc++.h>
using namespace std;
int main()
{
    for(int i=1;i<=30;i++)
    {
        freopen("nul","w",stdout);
        printf(  "        <br></br>\n"
                "        <button type=\"button\" class=\"btn btn-primary btn-lg btn-block\" onclick=submit(%d)>提交</button>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "    </div>\n"
                "</body>\n"
                "</html>\n",i);
        fclose(stdout);
        string s="cat nul >> main/pronun/day"+to_string(i)+".html";
        system(s.c_str());
    }
    return 0;
}