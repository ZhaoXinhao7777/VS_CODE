// string minNumber(vector<int>& nums) {

//     vector<string> temp;
//     for (auto num : nums) {
//         temp.push_back(to_string(num));
//     }
//     //C++11 lambda表达式
//     sort(temp.begin(), temp.end(), [](const string& a, const string& b) { return a + b < b + a; });
//     string result;
//     for (auto& t : temp) {
//         result += t;
//     }
//     return result;
// }

class Solution
{
public:
    // sort中的compare函数为静态成员函数或者全局函数,不能作为普通成员函数
    // 因为非静态成员函数是依赖于具体对象的，有this指针，而std::sort这类函数，是全局的
    // 因此，无法在sort中调用非静态成员函数。
    // 非静态成员函数是不依赖于具体对象，可以独立访问。
    static bool compare(int a, int b)
    {
        string str1 = "", str2 = "";
        str1 += to_string(a);
        str1 += to_string(b);
        str2 += to_string(b);
        str2 += to_string(a);
        return str1 < str2;
    }
    string PrintMinNumber(vector<int> num)
    {
        string str;
        sort(num.begin(), num.end(), compare);

        auto it = num.begin();
        while (it != num.end())
        {
            str += to_string(*it);
            it++;
        }
        return str;
    }
};
