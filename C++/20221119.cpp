#include<iostream>
using namespace std;

class Data
{
public:
    Data(int year=1900,int month=1,int day=1)
    :_year(year)
    ,_month(month)
    ,_day(day)
    {}
    void Print()
    {
        cout<<_a<<endl;
    }
private:
    int _year;
    int _month;
    int _day;
    static int _a;
};
int Data::_a=100;
int main()
{
    Data d1(2022,11,19);
    
    system("pause");
    return 0;
}