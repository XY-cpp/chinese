#include<bits/stdc++.h>
using namespace std;
int n=30;
string word[24]={"ā","á","ǎ","à","ē","é","ě","è","ī","í","ǐ","ì","ō","ó","ǒ","ò","ū","ú","ǔ","ù","ǖ","ǘ","ǚ","ǜ"};
void init(int i)
{
    string t="txt"+to_string(i)+".html";
    freopen(t.c_str(),"r",stdin);
    t="day"+to_string(i)+".html";
    freopen(t.c_str(),"w",stdout);
    printf( "<!DOCTYPE html>\n"
            "<html>\n"
            "\n"
            "<head>\n"
            "    <title>读音：第%d天</title>\n"
            "    <meta charset=\"utf-8\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
            "    <link rel=\"stylesheet\" href=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css\">\n"
            "    <script src=\"https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js\"></script>\n"
            "    <script src=\"../js/pronun_main.js\"></script>\n"
            "    <style>\n"
            "        .char {\n"
            "            display: inline-block;\n"
            "            position: relative;\n"
            "        }\n"
            "\n"
            "        .char::before {\n"
            "            content: '.';\n"
            "            display: inline-block;\n"
            "\n"
            "            position: absolute;\n"
            "            bottom: -0.5em;\n"
            "            left: 0;\n"
            "\n"
            "            text-align: center;\n"
            "            width: 100%%;\n"
            "\n"
            "        }\n"
            "    </style>\n"
            "</head>\n",i);
    printf( "<body>\n"
            "    <div id=\"dg\" style=\"z-index: 9999; position: fixed ! important; right: 0px; top: 0px;\">\n"
            "        <table width=\"\"100%% style=\"position: absolute; width:260px; right: 0px; top: 0px;\">\n"
            "            <button type=\"button\" class=\"btn btn-warning\" onclick=\"window.location.href = '../pronun.html'\">返回</button>\n"
            "        </table>"
            "    </div>"
            "    <div class=\"container\">\n"
            "       <h2>读音：第%d天</h2>\n",i);
}
int main()
{
    for(int i=1;i<=n;i++)
    {
        cin.clear();
        init(i);
        string s;
        int j=1;
        while(getline(cin,s))
        {
            printf( "        <div class=\"border\">\n"
                    "            <font size=5>%d.</font>",j);
            int k=0;
            for(k=0;k<s.length();k+=3)
            {
                bool flag=false;
                for(int l=0;l<24;l++)
                    if(s.find(word[l])==k)
                        flag=true;
                if(isalpha(s[k])) flag=true;
                if(flag) break;
                if(s[k]=='/') printf("<font size=5>/</font>"),k++;
                if(s[k+3]=='.')
                {
                    printf("<font size=5 class=\"char\">%s</font>",s.substr(k,3).c_str());
                    k++;
                }
                else printf("<font size=5>%s</font>",s.substr(k,3).c_str());
            }
            puts("\n            <br></br>");
            puts("            <div class=\"btn-grp\" data-toggle=\"buttons\">");
            string t=s.substr(k);
            int cnt=0;
            for(int it=0;it<24;it++)
            {
                int x=t.find(word[it]);
                if(x!=t.npos)
                {
                    for(int l=1;l<=4;l++)
                    {
                        string tmp=t.substr(0,x)+word[it/4*4+l-1]+t.substr(min((int)t.length(),x+2));
                        if(it/4*4+l-1==it) cerr<<l<<" ";
                        printf(  "                <label class=\"btn btn-info mr-4\">\n"
                                "                    <input type=\"radio\" name=\"d%d_t%d\" autocomplete=\"off\" value=\"%d\">%s\n"
                                "                </label>\n",i,j,++cnt,tmp.c_str());
                    }
                    break;//remain to develop
                }
            }
            printf("            </div>\n");
            printf("        </div>\n");

            j++;
        }
        printf( "        <br></br>\n"
                "        <button type=\"button\" class=\"btn btn-primary btn-lg btn-block\" onclick=submit(%d)>提交</button>\n"
                "        <button type=\"button\" class=\"btn btn-danger btn-lg btn-block\" onclick=remove(%d)>清除记录</button>\n"
                "        </div>\n"
                "        <br></br>\n"
                "        <script>fill(%d)</script>"
                "        <br></br>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "    </div>\n"
                "</body>\n"
                "</html>\n",i,i,i);
        for(int tmp=j;tmp<=30;tmp++)
            cerr<<0<<" ";
        cerr<<endl;
    }
    fclose(stdout);
}