class Solution {
public:
//遍历：分类讨论，将每一种情况展示出来
    int romanToInt(string s) {
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='M')
            {
                count+=1000;
            }else if(s[i]=='D')
            {
                count+=500;
            }
            else if(s[i]=='C')
            {
                if(s[i+1]=='D'||s[i+1]=='M')
                {
                    count=count-100;
                }else
                    count+=100;
            }else if(s[i]=='L')
            {
                count+=50;
            }else if(s[i]=='X')
            {
                if(s[i+1]=='C'||s[i+1]=='L')
                    count-=10;
                else
                    count+=10;
            }else if(s[i]=='V')
            {
                    count+=5;
            }
            else
            {
                if(s[i+1]=='V'||s[i+1]=='X')
                    count--;
                else
                    count++;
            }
        }
        return count;
    }
};