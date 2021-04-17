// ネイピア数e計算

#include "BigNumber.h"

class BigNumber A(1), N(1), ZERO(0);
int main()
{
	for (unsigned int k = 1; !A.equal(&ZERO); k++) {
		A.div(&A, k);
		N.add(&N, &A);
	}
	N.prt(1, DIGIT);
}
