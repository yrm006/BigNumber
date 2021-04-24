// 円周率計算
// 4スレッドで並列計算
// π/4=44arctan(1/68)+12arctan(1/117)-5arctan(1/239)+20arctan(1/382)+20arctan(1/4557)

#include "BigNumber.h"
#include <thread>

class BigNumber ZERO(0), PI(0);
class BigNumber A1(0), B1(0), PI1(0);
class BigNumber A2(0), B2(0), PI2(0);
class BigNumber A3(0), B3(0), PI3(0);
class BigNumber A4(0), B4(0), PI4(0);

void func1() {
    unsigned k, h;
    h = 68 * 68;
    k = 1;
    B1.setvalue(4 * 44 * 68);
    do {
        B1.div(&B1, h);
        A1.div(&B1, k);
        if (k & 2) PI1.sub(&PI1, &A1);
        else PI1.add(&PI1, &A1);
        k += 2;
    } while (!A1.equal(&ZERO));
}

void func2() {
    unsigned k, h;
    h = 117 * 117;
    k = 1;
    B2.setvalue(4 * 12 * 117);
    do {
        B2.div(&B2, h);
        A2.div(&B2, k);
        if (k & 2) PI2.sub(&PI2, &A2);
        else PI2.add(&PI2, &A2);
        k += 2;
    } while (!A2.equal(&ZERO));
}

void func3() {
    unsigned k, h;
    h = 382 * 382;
    k = 1;
    B3.setvalue(4 * 20 * 382);
    do {
        B3.div(&B3, h);
        A3.div(&B3, k);
        if (k & 2) PI3.sub(&PI3, &A3);
        else PI3.add(&PI3, &A3);
        k += 2;
    } while (!A3.equal(&ZERO));

    h = 4557 * 4557;
    k = 1;
    B3.setvalue(4 * 20 * 4557);
    do {
        B3.div(&B3, h);
        A3.div(&B3, k);
        if (k & 2) PI3.sub(&PI3, &A3);
        else PI3.add(&PI3, &A3);
        k += 2;
    } while (!A3.equal(&ZERO));
}

void func4() {
    unsigned k, h;
    h = 239 * 239;
    k = 1;
    B4.setvalue(4 * 5 * 239);
    do {
        B4.div(&B4, h);
        A4.div(&B4, k);
        if (k & 2) PI4.sub(&PI4, &A4);
        else PI4.add(&PI4, &A4);
        k += 2;
    } while (!A4.equal(&ZERO));
}

int main()
{
    std::thread th1(func1);
    std::thread th2(func2);
    std::thread th3(func3);
    std::thread th4(func4);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    PI.add(&PI1, &PI2);
    PI.add(&PI, &PI3);
    PI.sub(&PI, &PI4);
    PI.prt(1, DIGIT);
}