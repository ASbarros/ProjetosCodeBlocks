#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double raio;
    cin >> raio;
    cout << fixed << setprecision(3) << "VOLUME = " << (4/3.0)*3.14159*raio*raio*raio << endl;

    return 0;
}
