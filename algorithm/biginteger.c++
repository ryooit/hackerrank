#include <iostream>
#include <deque>
#include <string>
#include <cmath>

using namespace std;
typedef long long LL;
typedef deque<LL> bigint;
const LL base = 9;
const LL base10 = pow(10, base);

class BigInteger
{
public:
    static void print(bigint a)
    {
        for (LL i = 0; i < a.size(); ++i)
        {
            int ndigits = a[i] > 0 ? (int) log10 ((double) a[i]) + 1 : 1;
            if (ndigits < base && i != 0) {
                for (int j = 0; j < base - ndigits; ++j)
                    cout << 0;
            }
            cout << a[i];
        }
        cout << endl;
    }


    static bigint mul(bigint a, bigint b)
    {
        LL cnt = 0;
        bigint res;
        for (LL i = b.size() - 1; i >= 0; --i) {
            bigint r = mul(a, b[i]);

            for (LL i = 0; i < cnt; ++i)
              r.push_back(0);

            res = add(res, r);
            cnt++;
        }

        return res;
    }

    static bigint mul(bigint a, LL b)
    {
        bigint res;
        LL mem = 0;
        for (LL i = a.size() - 1; i >= 0; --i) {
            LL r = a[i] * b + mem;
            res.push_front(r % base10);
            mem = (r - r % base10) / base10;
        }
        if (mem != 0) res.push_front(mem);

        return res;
    }

    static bigint add(bigint a, bigint b)
    {
        if (a.size() < b.size())
          while (a.size() != b.size())
            a.push_front(0);

        else if (a.size() > b.size())
          while (a.size() != b.size())
            b.push_front(0);

        bigint res;
        LL mem = 0;
        for (LL i = a.size() - 1; i >= 0; --i) {
            LL r = a[i] + b[i] + mem;
            res.push_front(r % base10);
            mem = (r - r % base10) / base10;
        }
        if (mem != 0)
          res.push_front(mem);

        return res;
    }
};

bigint modified_fib(bigint a, bigint b, LL n)
{
    for (int i = 0; i < n - 2; ++i) {
        bigint r = BigInteger::add(BigInteger::mul(b, b), a);
        a = b;
        b = r;
    }

    return b;
}

int main()
{
    LL a, b;
    bigint biga, bigb;
    cin >> a >> b;
    biga.push_back(a);
    bigb.push_back(b);

    LL N;
    cin >> N;

    bigint res = modified_fib(biga, bigb, N);

    BigInteger::print(res);

    return 0;
}
