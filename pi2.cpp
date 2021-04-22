// 円周率計算

#include "BigNumber2.hpp"

BigNumber2<1000> A(0), B(0), PI(0), ZERO(0);
int main()
{
    unsigned k, h;
    h = 5 * 5;
    k = 1;
    B = (16 * 5);
    do {
        B /= h;
        A = B; A /= k;
        if (k & 2) PI -= A;
        else PI += A;
        k += 2;
    } while (! (A==ZERO) );
    h = 239 * 239;
    k = 1;
    B = (4 * 239);
    do {
        B /= h;
        A = B; A /= k;
        if (k & 2) PI += A;
        else PI -= A;
        k += 2;
    } while (! (A==ZERO) );
    std::cout << PI;
}
