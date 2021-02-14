#include<bits/stdc++.h>
using namespace std;
int n=30;
string word[24]={"ā","á","ǎ","à","ē","é","ě","è","ī","í","ǐ","ì","ō","ó","ǒ","ò","ū","ú","ǔ","ù","ǖ","ǘ","ǚ","ǜ"};
void init(int i)
{
    string t="txt"+to_string(i)+".html";
    freopen(t.c_str(),"r",stdin);
    t="day"+to_string(i)+"_ans.html";
    freopen(t.c_str(),"w",stdout);
    printf( "<!DOCTYPE html>\n"
            "<html>\n"
            "\n"
            "<head>\n"
            "    <title>读音：第%d天答案</title>\n"
            "    <meta charset=\"utf-8\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
            "    <link rel=\"stylesheet\" href=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css\">\n"
            "    <script src=\"https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js\"></script>\n"
            "    <script src=\"../js/pronun_main.js\"></script>\n"
            "    <style>\n"
            "       span.WA {color: #FF0000;font-size: 25px}\n"
            "		span.AC {color: #1cad4d;font-size: 25px}\n"
            "		span.AL {color: #000000;font-size: 25px}\n"
            "    </style>\n"
            "</head>\n",i);
    printf( "<body>\n"
            "    <div class=\"container\">\n"
            "       <h2>读音：第%d天答案</h2>\n",i);
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
                    "            <span class=\"AL\">%d.</span>",j);
            int k=0;
            for(k=0;k<s.length();k+=3)
            {
                bool flag=false;
                for(int l=0;l<24;l++)
                    if(s.find(word[l])==k)
                        flag=true;
                if(isalpha(s[k])) flag=true;
                if(flag) break;
                if(s[k]=='/') printf("<span class=\"AL\">/</span>"),k++;
                if(s[k+3]=='.')
                {
                    printf("<span id=\"%d\" class=\"AC\">%s</span>",j,s.substr(k,3).c_str());
                    k++;
                }
                else printf("<span class=\"AL\">%s</span>",s.substr(k,3).c_str());
            }
            printf("<span class=\"AL\">%s</span>",(" "+s.substr(k)).c_str());
            printf("\n        </div>\n");
            j++;
        }
        printf( "        <br></br>\n"
                "        <button type=\"button\" class=\"btn btn-primary btn-lg btn-block\" onclick=back(%d)>返回</button>\n"
                "        </div>\n"
                "        <br></br>\n"
                "        <script>judge(%d)</script>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "        <br></br>\n"
                "    </div>\n"
                "</body>\n"
                "</html>\n",i,i);
        cerr<<endl;
    }
    fclose(stdout);
}