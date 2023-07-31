class Solution
{
public:
    // 使用哈希表 x=B[i]+temp;在A中查找A[i]==rec.count(x);
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {
        int sumA = accumulate(A.begin(), A.end(), 0);
        int sumB = accumulate(B.begin(), B.end(), 0);
        int temp = (sumA - sumB) / 2;
        unordered_set<int> rec(A.begin(), A.end());
        for (auto &y : B)
        {
            int x = y + temp;
            if (rec.count(x))
            {
                return {x, y};
            }
        }
        return vector<int>();
    }
    // //双指针法 必然存在至少一对{A[i],B[j]},使得等式满足
    //     vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    //         int sumA=accumulate(A.begin(),A.end(),0);
    //         int sumB=accumulate(B.begin(),B.end(),0);
    //         int temp=(sumA-sumB)/2;

    //         sort(A.begin(),A.end());
    //         sort(B.begin(),B.end());
    //         int i=0,j=0;
    //         while(i<A.size()&&j<B.size())
    //         {
    //             int cur=A[i]-B[j];
    //             if(cur==temp)
    //                 return {A[i],B[j]};
    //             else if(cur>temp)
    //                 j++;
    //             else
    //                 i++;
    //         }
    //         return vector<int>();

    //     }
};