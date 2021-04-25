// 円周率計算
// 8スレッドで並列計算
//// π/4=
    //   +20arctan(1/7)
    //   -20arctan(1/8)
    //   +24arctan(1/31)
    //   -24arctan(1/57)
    //   +12arctan(1/43)
    //   -12arctan(1/68)
    //   -5arctan(1/70)
    //   +5arctan(1/99)

#include "BigNumber.h"
#include <thread>

class BigNumber ZERO(0), PI(0);
class BigNumber A1(0), B1(0), PI1(0);
class BigNumber A2(0), B2(0), PI2(0);
class BigNumber A3(0), B3(0), PI3(0);
class BigNumber A4(0), B4(0), PI4(0);
class BigNumber A5(0), B5(0), PI5(0);
class BigNumber A6(0), B6(0), PI6(0);
class BigNumber A7(0), B7(0), PI7(0);
class BigNumber A8(0), B8(0), PI8(0);

void func1() {
    unsigned k, h;
    h = 7 * 7;
    k = 1;
    B1.setvalue(4 * 20 * 7);
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
    h = 8 * 8;
    k = 1;
    B2.setvalue(4 * 20 * 8);
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
    h = 31 * 31;
    k = 1;
    B3.setvalue(4 * 24 * 31);
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
    h = 57 * 57;
    k = 1;
    B4.setvalue(4 * 24 * 57);
    do {
        B4.div(&B4, h);
        A4.div(&B4, k);
        if (k & 2) PI4.sub(&PI4, &A4);
        else PI4.add(&PI4, &A4);
        k += 2;
    } while (!A4.equal(&ZERO));
}

void func5() {
    unsigned k, h;
    h = 43 * 43;
    k = 1;
    B5.setvalue(4 * 12 * 43);
    do {
        B5.div(&B5, h);
        A5.div(&B5, k);
        if (k & 2) PI5.sub(&PI5, &A5);
        else PI5.add(&PI5, &A5);
        k += 2;
    } while (!A5.equal(&ZERO));
}

void func6() {
    unsigned k, h;
    h = 68 * 68;
    k = 1;
    B6.setvalue(4 * 12 * 68);
    do {
        B6.div(&B6, h);
        A6.div(&B6, k);
        if (k & 2) PI6.sub(&PI6, &A6);
        else PI6.add(&PI6, &A6);
        k += 2;
    } while (!A6.equal(&ZERO));
}

void func7() {
    unsigned k, h;
    h = 70 * 70;
    k = 1;
    B7.setvalue(4 * 5 * 70);
    do {
        B7.div(&B7, h);
        A7.div(&B7, k);
        if (k & 2) PI7.sub(&PI7, &A7);
        else PI7.add(&PI7, &A7);
        k += 2;
    } while (!A7.equal(&ZERO));
}

void func8() {
    unsigned k, h;
    h = 99 * 99;
    k = 1;
    B8.setvalue(4 * 5 * 99);
    do {
        B8.div(&B8, h);
        A8.div(&B8, k);
        if (k & 2) PI8.sub(&PI8, &A8);
        else PI8.add(&PI8, &A8);
        k += 2;
    } while (!A8.equal(&ZERO));
}

int main()
{
    std::thread th1(func1);
    std::thread th2(func2);
    std::thread th3(func3);
    std::thread th4(func4);
    std::thread th5(func5);
    std::thread th6(func6);
    std::thread th7(func7);
    std::thread th8(func8);
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    PI.sub(&PI1, &PI2);
    PI.add(&PI, &PI3);
    PI.sub(&PI, &PI4);
    PI.add(&PI, &PI5);
    PI.sub(&PI, &PI6);
    PI.sub(&PI, &PI7);
    PI.add(&PI, &PI8);
    PI.prt(1, DIGIT);
}
