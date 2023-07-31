#include <iostream>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
int main()
{
    string a("add dda ddada dad");
    cout << sizeof(a) << endl;
    cout << strlen(a.c_str()) << endl;

    system("pause");
    return 0;
}