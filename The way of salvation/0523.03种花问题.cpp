class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0, len = 1;
        // len 0连续的个数 0 0 0 
        for (auto &i : flowerbed)
        {
            if (i)
            {
                count += (len - 1) >> 1;
                len = 0;
            }
            else
                len++;
        }
        count += (len) >> 1;
        return count >= n;
        // if(flowerbed[0]==0&&flowerbed[1]==0)
        // {
        //     flowerbed[0]=1;
        //     n--;
        // }
        // for(int i=1;i<=flowerbed.size()-2;i++)
        // {
        //     if(flowerbed[i]!=0) continue;

        //     if(flowerbed[i-1]==0&&flowerbed[i+1]==0)
        //     {
        //         flowerbed[i]=1;
        //         n--;
        //     }
        // }
        // if(flowerbed[flowerbed.size()-1]==0&&flowerbed[flowerbed.size()-2]==0)
        // {
        //     flowerbed[flowerbed.size()-1]=1;
        //     n--;
        // }
        // if(n>0) return false;
        // return true;
    }
};