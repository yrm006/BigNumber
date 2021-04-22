// 円周率計算

#include "BigNumber.h"
#include <thread>

class BigNumber ZERO(0);

void func1(BigNumber* PI){
    static BigNumber A(0), B(0);
    unsigned k, h;
    h = 5 * 5;
    k = 1;
    B.setvalue(16 * 5);
    do {
        B.div(&B, h);
        A.div(&B, k);
        if (k & 2) PI->sub(PI, &A);
        else PI->add(PI, &A);
        k += 2;
    } while (!A.equal(&ZERO));
}

void func2(BigNumber* PI){
    static BigNumber A(0), B(0);
    unsigned k, h;
    h = 239 * 239;
    k = 1;
    B.setvalue(4 * 239);
    do {
        B.div(&B, h);
        A.div(&B, k);
        if (k & 2) PI->add(PI, &A);
        else PI->sub(PI, &A);
        k += 2;
    } while (!A.equal(&ZERO));
}

int main()
{
    static BigNumber PI1(0);
    std::thread th1(func1, &PI1);
    static BigNumber PI2(0);
    std::thread th2(func2, &PI2);
    th1.join();
    th2.join();
    static BigNumber PI(0);
    PI.add(&PI1, &PI2);
    PI.prt(1, DIGIT);
}
