#include<bits/stdc++.h>
using namespace std;
int n=30;
void init(int i)
{
    string t="txt"+to_string(i)+".html";
    freopen(t.c_str(),"r",stdin);
    t="day"+to_string(i)+".html";
    freopen(t.c_str(),"w",stdout);
    //declare something
    printf( "<!DOCTYPE html>\n"
            "<html>\n"
            "\n"
            "<head>\n"
            "    <title>字形：第%d天</title>\n"
            "    <meta charset=\"utf-8\">\n"
            "    <meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">\n"
            "    <link rel=\"stylesheet\" href=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/css/bootstrap.min.css\">\n"
            "    <script src=\"https://cdn.staticfile.org/jquery/3.2.1/jquery.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/popper.js/1.15.0/umd/popper.min.js\"></script>\n"
            "    <script src=\"https://cdn.staticfile.org/twitter-bootstrap/4.3.1/js/bootstrap.min.js\"></script>\n"
            "    <script src=\"../js/font_main.js\"></script>\n"
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
    //body
    printf( "<body>\n"
            "        <div id=\"dg\" style=\"z-index: 9999; position: fixed ! important; right: 0px; top: 0px;\">\n"
            "            <table width=\"100%%\" style=\"position: absolute; width:260px; right: 0px; top: 0px;\">\n"
            "                <button type=\"button\" class=\"btn btn-warning\" onclick=\"window.location.href = '../font.html'\">返回</button>\n"
            "            </table>\n"
            "        </div>\n"
            "    <div class=\"container\">\n"
            "        <h2>字形：第%d天</h2>\n",i);
}
int main()
{
    for(int i=1;i<=n;i++)
    {
        cin.clear();
        init(i);
        string s;
        int j=1;
        srand(i+1);
        while(getline(cin,s))
        {
            printf( "        <div class=\"border\">\n"
                    "            <font size=5>%d.</font>",j);
            int p1,p2;
            for(int k=0;k<s.length();k+=3)
            {
                if(s[k+3]=='.') 
                {
                    printf("            <font size=5 >(&nbsp&nbsp&nbsp)</font>");
                    p1=k;
                    k++;
                }
                else if(s[k]=='(')
                {
                    p2=k+1;
                    break;
                }
                else printf("            <font size=5>%s</font>",s.substr(k,3).c_str());
            }
            puts("\n            <br></br>");
            puts("            <div class=\"btn-grp\" data-toggle=\"buttons\">");
            if(rand()%2) swap(p2,p1);
            printf( "                <label class=\"btn btn-info mr-2\">\n"
                    "                    <input type=\"radio\" name=\"d%d_t1\" autocomplete=\"off\" value=\"1\">%s\n"
                    "                </label>\n",i,s.substr(p1,3).c_str());
            printf( "                <label class=\"btn btn-info mr-2\">\n"
                    "                    <input type=\"radio\" name=\"d%d_t2\" autocomplete=\"off\" value=\"2\">%s\n"
                    "                </label>\n",i,s.substr(p2,3).c_str()); 
            cerr<<(p1<p2)+1;
            printf("            </div>\n");
            printf("        </div>\n");

            j++;
        }
        printf( "       <br></br>\n"
                "       <button type=\"button\" class=\"btn btn-primary btn-lg btn-block\" onclick=submit(%d)>提交</button>\n"
                "       <button type=\"button\" class=\"btn btn-danger btn-lg btn-block\" onclick=remove(%d)>清除记录</button>\n"
                "   </div>\n"
                "   <br></br>\n"
                "   <script>fill(%d)</script>"
                "   <br></br>\n"
                "   <br></br>\n"
                "   <br></br>\n"
                "   </div>\n"
                "</body>\n"
                "</html>\n",i,i,i);
        cerr<<endl;
    }
    fclose(stdout);
}