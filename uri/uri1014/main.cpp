#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a;
    double b,c;
    cin >>a;
    cin>>b;
    c = a/b;
    cout<< fixed << setprecision(3)  << c <<" km/l\n";
    return 0;
}
