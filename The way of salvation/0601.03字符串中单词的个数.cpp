// class Solution
// {
// public:
//     int countSegments(string s)
//     {
//         int cut = 0;
//         string word;
//         for (auto &a : s)
//         {
//             if (a == ' ' && word != "")
//             {
//                 cut++;
//                 // cout << word << endl;
//                 word = "";
//             }
//             else if (a == ' ' && word == "")
//                 continue;
//             else
//             {
//                 word += a;
//             }
//         }
//         // 少计算一个
//         if (word != "")
//             cut++;
//         return cut;
//     }
// };

int countSegments(string s)
{
    int count = 0;
    int size = s.length();
    if (size == 0)
        return 0;
    for (int i = 0; i < size - 1; i++)
    {
        while (s[i] != ' ' && i < size - 1)
        {
            if (s[i + 1] == ' ')
                count++;
            i++;
        }
    }
    return count;
}