#include<cstdio>
#include<iostream>
#include <Windows.h>
using namespace std;
int kmp(string s1,string s2)
{
    int tot=0;
    int nextt[1000];
    memset(nextt,0,sizeof(nextt));
    int sz1=s1.size(),sz2=s2.size();
	s1="0"+s1;
	s2="0"+s2;
	int j=0;
	for(int i=2;i<=sz2;i++)
	{
		while(j>0&&s2[j+1]!=s2[i])
		{
			j=nextt[j];
		}
		if(s2[j+1]==s2[i]) j++;
		nextt[i]=j;
	}
	j=0;
	for(int i=1;i<=sz1;i++)
	{
		while(j>0&&s2[j+1]!=s1[i])
		{
			j=nextt[j];
		}
		if(s2[j+1]==s1[i]) j++;
		if(j==sz2)
		{
			tot++;
			j=nextt[j];
		}
	}
    return tot;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    SetConsoleOutputCP(65001);
    freopen("subject.jsonlines","r",stdin);
    freopen("a.txt","w",stdout);
    int tot=0;
    string s;
    while(getline(cin,s))
    {
        if(kmp(s,"|开始=")&&((!kmp(s,"|连载杂志=")||kmp(s,"|连载杂志= \\"))))
        {
            bool flag=0;
            for(int i=6;i<=20;i++)
            {
                if(s[i]==':')
                {
                    if(s[i+1]!='1') flag=1;
                    break;
                }
            }
            if(!flag)
            {
                tot++;
                cout<<"https://bgm.tv/subject/";
                for(int i=6;i<=20;i++)
                {
                    if('0'<=s[i]&&s[i]<='9') cout<<s[i];
                    else break;
                }
                cout<<"  \n";
            }
        }
    }
    cout<<"tot="<<tot;
    return 0;
}
