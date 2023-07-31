#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// string addBinary(string a, string b) {
//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
//     if (a.size() < b.size())
//         swap(a, b);
//     vector<char> res;
//     for (int i = 0; i < b.size(); i++)
//     {
//         res.push_back(a[i] - '0' + b[i]);
//     }
//     for (int i = b.size(); i < a.size(); ++i)
//     {
//         res.push_back(a[i]);
//     }
//
//     //注意边界，处理结果集
//     //就是从左往右进行处理，因为已经反转过了
//     for (int i = 0; i < a.size() - 1; i++)
//     {
//         if (res[i] >= '2')
//         {
//             res[i + 1] = res[i + 1] + (res[i] - '0') / 2;
//             res[i] = '0' + (res[i] - '0') % 2;
//         }
//     }
//     for(auto &it:res)
//         cout << it << " ";
//     cout << endl;
//     string result;
//     for (auto& a : res)
//     {
//         result += a;
//     }
//     reverse(result.begin(), result.end());
//     cout << result << endl;
//     if (result[0] > '1')
//     {
//         result[0] = result[0] - 2;
//         result = result + '1';
//     }
//     return result;
// }
string addBinary(string a, string b)
{
	// 不能保证a,b长度相等，所以进行反转，将字符串尾对齐。
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	if (a.size() < b.size())
		swap(a, b);

	vector<char> res;
	int len = b.size();
	// 将a[i]与b[i]进行求和 将结果集保存在res中
	for (int i = 0; i < len; ++i)
	{
		res.push_back(b[i] - '0' + a[i]);
	}
	// cout << res << endl;
	for (int i = len; i < a.size(); ++i)
		res.push_back(a[i]);

	/*reverse(res.begin(), res.end());
	cout << res << endl;*/
	// for (auto a : res)
	//	cout << a;
	// cout << endl;
	// 注意边界 处理结果集
	for (int i = 0; i < a.size() - 1; ++i)
	{
		if (res[i] >= '2')
		{
			res[i + 1] = res[i + 1] + (res[i] - '0') / 2;
			res[i] = '0' + (res[i] - '0') % 2;
		}

		// for (auto a : res)
		//	cout << a;
		// cout << endl;
	}
	// cout << res << endl;
	string result;
	for (auto &a : res)
		result += a;

	// cout << result << endl;

	// 再次反转结果集
	cout << result << endl;
	reverse(result.begin(), result.end());
	// 判断首位情况
	if (result[0] > '1')
	{
		result[0] = result[0] - 2;

		// 注意'1+'的位置
		// result='1'+result;与result=result+'1';结果不一样
		result = '1' + result;
	}

	// cout << res << endl;
	// while (res[0] > '1') {
	//	res[0] = res[0] - 2;
	//	res = '1' + res;
	// }
	// reverse(res.begin(), res.end());
	return result;
}

int main()
{
	string a = "11";
	string b = "1";
	cout << addBinary(a, b) << endl;

	system("pause");
	return 0;
}