// 円周率計算

#include "BigNumber.h"

class BigNumber A(0), B(0), PI(0), ZERO(0);
int main()
{
    unsigned k, h;
    h = 5 * 5;
    k = 1;
    B.setvalue(16 * 5);
    do {
        B.div(&B, h);
        A.div(&B, k);
        if (k & 2) PI.sub(&PI, &A);
        else PI.add(&PI, &A);
        k += 2;
    } while (!A.equal(&ZERO));
    h = 239 * 239;
    k = 1;
    B.setvalue(4 * 239);
    do {
        B.div(&B, h);
        A.div(&B, k);
        if (k & 2) PI.add(&PI, &A);
        else PI.sub(&PI, &A);
        k += 2;
    } while (!A.equal(&ZERO));
    PI.prt(1, DIGIT);
}
