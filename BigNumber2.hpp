#include <stddef.h>
#include <stdint.h>
#include <iostream>



template <size_t DIGIT>
class BigNumber2{
public:
    BigNumber2(uint32_t n){
        this->value[0] = n;
        for (size_t i = 1; i < ARRAYSIZE; ++i){
            this->value[i] = 0;
        }
    }

    ~BigNumber2(){}

    bool operator ==(BigNumber2& r) {
        for (size_t i = 0; i < ARRAYSIZE; ++i){
            if (this->value[i] != r.value[i]) return false;
        }
        return true;
    }

    BigNumber2& operator =(uint32_t n) {
        this->value[0] = n;
        for (int i = 1; i < ARRAYSIZE; ++i) this->value[i] = 0;
        return *this;
    }

    BigNumber2& operator +=(BigNumber2& r) {
        uint8_t c = 0;
        for (size_t i = ARRAYSIZE-1; i > 0; --i) {
            this->value[i] += r.value[i] + c;
            if (this->value[i] >= 100000000) {
                this->value[i] -= 100000000;
                c = 1;
            }
            else c = 0;
        }

        this->value[0] += r.value[0] + c;
        return *this;
    }

    BigNumber2& operator -=(BigNumber2& r) {
        uint8_t c = 0;
        for (size_t i = ARRAYSIZE - 1; i > 0; --i) {
            this->value[i] -= r.value[i] + c;
            if ((int64_t)this->value[i] < 0) {
                this->value[i] += 100000000;
                c = 1;
            }
            else c = 0;
        }

        this->value[0] -= r.value[0] + c;
        return *this;
    }

    BigNumber2& operator /=(uint32_t n) {
        size_t i;
        uint64_t r = this->value[0];
        for (i = 0; i < ARRAYSIZE - 1; ++i) {
            if (r) {
                this->value[i] = r / n;
                r = (r % n) * 100000000 + this->value[i + 1];
            }
            else r = this->value[i + 1];
        }
        this->value[i] = r / n;
        return *this;
    }

    friend
    std::ostream& operator<<(std::ostream& os, const BigNumber2& r)
    {
        r.prt(os, 1, DIGIT);
        return os;
    }

private:
    static const size_t ARRAYSIZE = (DIGIT+7)/8+2;
    uint64_t value[ARRAYSIZE];

    void prt(std::ostream& os, size_t dp, size_t deg) const {
        size_t i = 0;
        if (dp == 0) os << "0";
        else {
            while (this->value[i] == 0 && i < dp - 1) ++i;
            os << this->value[i++];
            while (i < dp) prt8(os, this->value[i++], 8);
        }
        if (dp > ARRAYSIZE - 2) return;
        if (deg == 0) return;
        os << ".";
        while (deg >0 && i <= ARRAYSIZE - 2) {
            prt8(os, this->value[i++], deg);
            deg -= 8;
        }
    }

    void prt8(std::ostream& os, uint64_t n, uint8_t k) const {
        n %= 100000000;
        os << n / 10000000;
        if (k == 1) return;
        n %= 10000000;
        os << n / 1000000;
        if (k == 2) return;
        n %= 1000000;
        os << n / 100000;
        if (k == 3) return;
        n %= 100000;
        os << n / 10000;
        if (k == 4) return;
        n %= 10000;
        os << n / 1000;
        if (k == 5) return;
        n %= 1000;
        os << n / 100;
        if (k == 6) return;
        n %= 100;
        os << n / 10;
        if (k == 7) return;
        os << n % 10;
    }
};


