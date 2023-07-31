class Solution
{
public:
    vector<int> multiply(const vector<int> &A)
    {
        // vector<int> res(A.size(),0);
        // for(int i=0;i<A.size();i++)
        // {
        //     int temp=1;
        //     for(int j=0;j<A.size();j++)
        //     {
        //         if(j!=i)
        //         {
        //             temp*=A[j];
        //         }
        //     }
        //     cout<<temp<<" ";
        //     //res.push_back(temp);
        //     res[i]=temp;
        //     cout<<res[i]<<endl;
        // }
        // return res;

        // 类似一个对象线为1的矩阵，使用前缀后缀乘积
        vector<int> res(A.size(), 0);
        int temp = 1;
        for (int i = 0; i < A.size(); i++)
        {
            res[i] = temp;
            temp *= A[i];
        }
        temp = 1;
        for (int i = A.size() - 1; i >= 0; i--)
        {
            res[i] *= temp;
            temp *= A[i];
        }
        return res;
    }
};  