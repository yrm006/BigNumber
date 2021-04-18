// 多倍長数演算ライブラリ

#include <iostream>
#include "BigNumber.h"
using namespace std;
unsigned long long BigNumber::tempvalue[ARRAYSIZE * 2];

BigNumber::BigNumber(unsigned int n) {
	value[0] = n;
	for (int i = 1; i < ARRAYSIZE; i++) value[i] = 0;
}
BigNumber::BigNumber(unsigned int n,unsigned int p) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (i == p) value[i] = n;
		else value[i] = 0;
	}
}
BigNumber::~BigNumber(void) {

}
void BigNumber::setvalue(unsigned int n) {
	value[0] = n;
	for (int i = 1; i < ARRAYSIZE; i++) value[i] = 0;
}
void BigNumber::setvalue(unsigned int n, unsigned p) {
	for (int i = 0; i < ARRAYSIZE; i++) {
		if (i == p) value[i] = n;
		else value[i] = 0;
	}
}
unsigned long long BigNumber::retvalue(unsigned int p) {
	return value[p];
}
void BigNumber::as(BigNumber *a) {
	for (int i = 0; i < ARRAYSIZE; i++) value[i] = a->value[i];
}
bool BigNumber::equal(BigNumber *a) {
	for (int i = 0; i < ARRAYSIZE; i++)
		if (value[i] != a->value[i]) return false;
	return true;
}
void BigNumber::add(BigNumber *a, BigNumber *b) {
	int c = 0;
	for (int i = ARRAYSIZE-1; i >= 0; i--) {
		value[i] = a->value[i] + b->value[i] + c;
		if (i>0 && value[i] >= 100000000) {
			value[i] = value[i] - 100000000;
			c = 1;
		}
		else c = 0;
	}
#ifdef ROUND
	round(this);
#endif
}
void BigNumber::sub(BigNumber *a, BigNumber *b) {
	int c = 0;
	for (int i = ARRAYSIZE - 1; i >= 0; i--) {
		value[i] = a->value[i] - b->value[i] - c;
		if (i > 0 && (long long)value[i] <0) {
			value[i] = value[i] + 100000000;
			c = 1;
		}
		else c = 0;
	}
#ifdef ROUND
	round(this);
#endif
}
void BigNumber::div(BigNumber *a, unsigned int n) {
	unsigned long long r;
	int i;
	for (i = 0; i < ARRAYSIZE; i++) value[i] = a->value[i];
	r = value[0];
	for (i = 0; i < ARRAYSIZE - 1; i++) {
		if (r) {
			value[i] = r / n;
			r = (r % n) * 100000000 + value[i + 1];
		}
		else r = value[i + 1];
	}
	value[i] = r / n;
#ifdef ROUND
	round(this);
#endif
}
void BigNumber::mul(BigNumber *a, unsigned int n) {
	unsigned long long c = 0;
	for (int i = ARRAYSIZE - 1; i >= 0; i--) {
		value[i] = a->value[i] * n + c;
		if (value[i] > 100000000 && i>0) {
			c = value[i] / 100000000;
			value[i] %= 100000000;
		}
		else c = 0;
	}
#ifdef ROUND
	round(this);
#endif
}
void BigNumber::mul2(BigNumber *a, BigNumber *b) {
	unsigned long long c,d;
	for (int i = 0; i < ARRAYSIZE * 2 - 1; i++) tempvalue[i] = 0;
	for (int i = ARRAYSIZE - 1; i >= 0; i--) {
		c = 0;
		for (int j = ARRAYSIZE - 1; j >= 0; j--) {
			d = tempvalue[i + j] + a->value[i] * b->value[j] + c;
			if (d >= 100000000) {
				c = d / 100000000;
				tempvalue[i + j] = d % 100000000;
			}
			else {
				c = 0;
				tempvalue[i + j] = d;
			}
		}
		if (i > 0) tempvalue[i - 1] += c;
		else tempvalue[0] += c * 100000000;
	}
	for (int i = 0; i < ARRAYSIZE; i++) value[i] = tempvalue[i];
#ifdef ROUND
	round(this);
#endif
}
void BigNumber::prt(int dp, int deg) {
	int i = 0;
	if (dp == 0) cout << "0";
	else {
		while (value[i] == 0 && i < dp - 1) i++;
		cout << value[i++];
		while (i < dp) prt8(value[i++], 8);
	}
	if (dp > ARRAYSIZE - 2) return;
	if (deg == 0) return;
	cout << ".";
	while (deg >0 && i <= ARRAYSIZE - 2) {
		prt8(value[i++], deg);
		deg -= 8;
	}
}
void round(BigNumber *a) {
	int i = ARRAYSIZE - 1;
	if (a->value[i] < 99999990) return;
	do {
		a->value[i--] = 0;
		a->value[i]++;
	} while (a->value[i] >= 100000000 && i > 0);
}
void prt8(unsigned long long n,int k) {
	n %= 100000000;
	cout << n / 10000000;
	if (k == 1) return;
	n %= 10000000;
	cout << n / 1000000;
	if (k == 2) return;
	n %= 1000000;
	cout << n / 100000;
	if (k == 3) return;
	n %= 100000;
	cout << n / 10000;
	if (k == 4) return;
	n %= 10000;
	cout << n / 1000;
	if (k == 5) return;
	n %= 1000;
	cout << n / 100;
	if (k == 6) return;
	n %= 100;
	cout << n / 10;
	if (k == 7) return;
	cout << n % 10;
}
