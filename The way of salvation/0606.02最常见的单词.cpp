class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> &banned)
    {
        // 给定一个段落和一个禁用单词表，返回出现次数最多的单词，同时保证不在禁用单词表中
        // 禁用表中都是小写字母，且答案返回小写字母
        // 利用哈希表实现
        string word;
        int len = paragraph.size(), max = 1;

        unordered_map<string, int> mp;
        for (int i = 0; i < len; i++)
        {
            if (paragraph[i] >= 'A' && paragraph[i] <= 'Z')
                word += paragraph[i] + 'a' - 'A';
            else if (paragraph[i] >= 'a' && paragraph[i] <= 'z')
                word += paragraph[i];
            // else if(paragraph[i]==' ')//若为空格 考虑不周，若为其他标点符号，则出错
            // a,a,a,a,b,b,b,c,c->b,b,b,c
            else if (word != "")
            {
                // 如果当前单词不在禁用表中，则将出现次数=1//mp[word]+1
                if (find(banned.begin(), banned.end(), word) == banned.end())
                    mp[word] += 1;

                word = "";
            }
        }
        for (auto &a : mp)
        {
            if (max <= a.second)
            {
                max = a.second;
                word = a.first;
            }
        }
        return word;
    }
};