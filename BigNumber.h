#define DIGIT 10000 //計算したい桁数
#define ARRAYSIZE (DIGIT/4+2)
// #define ROUND
class BigNumber
{
	unsigned int value[ARRAYSIZE];
	static unsigned int tempvalue[ARRAYSIZE * 2];
public:
	BigNumber(unsigned int n);
	BigNumber(unsigned int n, unsigned int p);
	~BigNumber(void);
	void setvalue(unsigned int n);
	void setvalue(unsigned int n,unsigned p);
	unsigned int retvalue(unsigned int p);
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
void prt4(unsigned int n, int k);
