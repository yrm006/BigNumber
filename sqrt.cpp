#include "BigNumber.h"
#include <iostream>
using namespace std;

#define N 2 //•½•ûª‚ğ‹‚ß‚½‚¢”

class BigNumber A(0), B(0), C(0), D(3*N);
int main()
{
    unsigned k = 1;
    while (k * k <= N) k++;
    k--;
    A.setvalue(k);
    do {
        C.as(&A);
        B.mul2(&A, &A);
        B.sub(&D, &B);
        B.div(&B, N * 2);
        A.mul2(&A, &B);
    } while (!A.equal(&C));

    A.prt(1, DIGIT);

// ŒŸZ—p
//    cout << endl;
//    A.mul2(&A, &A);
//    A.prt(1, DIGIT);
}
