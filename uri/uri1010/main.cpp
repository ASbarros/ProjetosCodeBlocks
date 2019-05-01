#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
        int cod1,cod2,num1,num2;
        float val1,val2, total;
        scanf("%d %d %f \n", &cod1,&num1,&val1);
        scanf("%d %d %f \n", &cod2,&num2,&val2);
        total = num1*val1 + num2*val2;
        cout << "VALOR A PAGAR: R$ "<< total;
    return 0;
}
