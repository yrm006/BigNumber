#define DIGIT 1000000 //計算したい桁数
#define ARRAYSIZE ((DIGIT+7)/8+2)
// #define ROUND
class BigNumber
{
	unsigned long long value[ARRAYSIZE];
	static unsigned long long tempvalue[];
public:
	BigNumber(unsigned int n);
	BigNumber(unsigned int n, unsigned int p);
	~BigNumber(void);
	void setvalue(unsigned int n);
	void setvalue(unsigned int n,unsigned p);
	unsigned long long retvalue(unsigned int p);
	void as(BigNumber *a);
	bool equal(BigNumber *a);
	void add(BigNumber *a, BigNumber *b);
	void sub(BigNumber *a, BigNumber *b);
	void div(BigNumber *a, unsigned int n);
	void mul(BigNumber *a, unsigned int n);
	void mul2(BigNumber *a, BigNumber *b);
	void prt(int dp, int deg);
	friend void round(BigNumber *a);
};
void prt8(unsigned long long n, int k);
