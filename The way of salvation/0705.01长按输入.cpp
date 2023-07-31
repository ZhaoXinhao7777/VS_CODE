class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int len1 = name.size(), len2 = typed.size();
        int i = 0, j = 0;
        while (i <= len1 && j < len2)
        {
            if (name[i] == typed[j])
            {
                ++i;
                ++j;
            }
            else if (j > 0 && typed[j] == typed[j - 1])
            {
                ++j;
            }
            else
                return false;
        }
        return i == len1;
    }
};