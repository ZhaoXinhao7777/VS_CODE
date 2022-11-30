#include<iostream>
#include<math.h>
using namespace std;

int count(int W,int H)
{
    int count = 0;
        if (W % 4 == 1) {
            count = (H / 4) * ((W / 4) * 2 * 4 + 2);
            if (H % 4 ==1){
                count = count + (W / 4) * 2 + 1;
            } else if (H % 4 == 2) {
                count = count + ((W / 4) * 2 + 1) * 2;
            } else if (H % 4 == 3) {
                count = count + ((W / 4) * 2 + 1) * 2 + (W / 4) * 2;
            }
        } else if (W % 4 == 2) {
            count = (H / 4) * ((W / 4) * 2 * 4 + 4);
            if (H % 4 ==1){
                count = count + (W / 4) * 2 + 2;
            } else if (H % 4 == 2) {
                count = count + ((W / 4) * 2 + 2) * 2;
            } else if (H % 4 == 3) {
                count = count + ((W / 4) * 2 + 2) * 2 + (W / 4) * 2;
            }
        } else if (W % 4 == 3) {
            count = (H / 4) * ((W / 4) * 2 * 4 + 6);
            if (H % 4 ==1){
                count = count + (W / 4) * 2 + 2;
            } else if (H % 4 == 2) {
                count = count + ((W / 4) * 2 + 2) * 2;
            } else if (H % 4 == 3) {
                count = count + ((W / 4) * 2 + 2) * 2 + (W / 4) * 2 + 1;
            }
        } else {
            count = (H / 4) * ((W / 2) * 4) + (H % 4) * (W / 2);
        }
        return count;

}
int main()
{
    int W,H;//W--行数，H--列数
    cin>>W>>H;
    cout<<count(W,H)<<endl;
    

    system("pause");
    return 0;
}