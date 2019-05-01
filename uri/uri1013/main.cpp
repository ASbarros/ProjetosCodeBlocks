#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    scanf("%d", &a);

    scanf("%d", &b);

    scanf("%d", &c);

    int r = (a + b + abs(a - b)) / 2;
    int s = (r + c + abs(r - c)) / 2;

    cout << s << " eh o maior\n";
    return 0;
}
