// funkcja znajdujaca NWD pary liczb calkowitych
#include <iostream>
#include <cstdarg>
using namespace std;
int power(int x, int pow)
{
    int val = 1;
    for (int i = 0; i < pow; i++)
        val *= x;
    return val;
}
int gcd(int a, int b)
{
    if (a < 0)
        a *= -1;
    if (b < 0)
        b *= -1;
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}
// szukanie NWD calego wielomianu
int polyGCD(int *arr, int size)
{
    int result = arr[0];
    for (int i = 1; i < size; i++)
    {
        result = gcd(arr[i], result);
        if (result == 1)
            return 1;
    }
    if (result < 0)
        result *= -1;
    return result;
}
class POLYNOMIAL
{
public:
    int *coeffs;
    int degree;
    static int overloaded;

    POLYNOMIAL()
    {
        this->coeffs = new int[1];
        this->coeffs[0] = 0;
        this->degree = 0;
    }

    POLYNOMIAL(int n, ...)
    {
        this->degree = n;
        va_list arguments;
        n++;
        va_start(arguments, n);
        this->coeffs = new int[degree + 1];
        for (int i = 0; i < n; i++)
        {
            this->coeffs[i] = va_arg(arguments, int);
        }
        va_end(arguments);
        this->normalizePolynomial();
    }
    POLYNOMIAL(const POLYNOMIAL &p)
    {
        this->degree = p.degree;
        this->coeffs = new int[degree + 1];
        for (int i = 0; i < p.degree + 1; i++)
        {
            this->coeffs[i] = p.coeffs[i];
        }
    }
    ~POLYNOMIAL()
    {
        // delete[] this->coeffs;
    }
    // metoda zapewniajaca wzgledna pierwszosc wielomianu
    void normalizePolynomial()
    {
        this->decreaseDegree();
        int gcd = polyGCD(this->coeffs, this->degree + 1);
        if (gcd == 0)
            return;
        for (int i = 0; i < this->degree + 1; i++)
        {
            this->coeffs[i] /= gcd;
        }
    }
    // metoda obnizajaca stopien wielomianu
    void decreaseDegree()
    {
        if (this->degree == 0)
            return;
        int prevDegree = this->degree;
        for (int i = this->degree; i >= 0; i--)
        {
            if (this->coeffs[i] != 0 || this->degree == 0)
                break;
            else
                this->degree--;
        }
        if (prevDegree == this->degree)
            return;
        int *copyArray = new int[this->degree + 1];
        for (int i = 0; i < this->degree + 1; i++)
            copyArray[i] = this->coeffs[i];
        delete[] this->coeffs;
        this->coeffs = copyArray;
    }
    // OPERATORY ARYTMETYCZNE
    //---------------
    // przypisanie
    POLYNOMIAL &operator=(const POLYNOMIAL &p)
    {
        if (this == &p)
            return *this;
        this->degree = p.degree;
        this->coeffs = new int[p.degree + 1];
        for (int i = 0; i < p.degree + 1; i++)
            this->coeffs[i] = p.coeffs[i];
        return *this;
    }
    // dodawanie
    POLYNOMIAL operator+(const POLYNOMIAL &p)
    {
        int maxDegree = this->degree > p.degree ? this->degree : p.degree;
        int minDegree = this->degree < p.degree ? this->degree : p.degree;
        POLYNOMIAL result = POLYNOMIAL();
        delete[] result.coeffs;
        result.degree = maxDegree;
        result.coeffs = new int[maxDegree + 1];
        for (int i = 0; i < maxDegree + 1; i++)
            result.coeffs[i] = 0;
        for (int i = 0; i < minDegree + 1; i++)
        {
            result.coeffs[i] = this->coeffs[i] + p.coeffs[i];
        }
        for (int i = minDegree + 1; i < maxDegree + 1; i++)
        {
            if (this->degree > p.degree)
                result.coeffs[i] = this->coeffs[i];
            else
                result.coeffs[i] = p.coeffs[i];
        }
        result.normalizePolynomial();
        return result;
    }
    // odejmowanie
    POLYNOMIAL operator-(const POLYNOMIAL &p)
    {
        int maxDegree = this->degree > p.degree ? this->degree : p.degree;
        int minDegree = this->degree < p.degree ? this->degree : p.degree;
        POLYNOMIAL result = POLYNOMIAL();
        delete[] result.coeffs;
        result.degree = maxDegree;
        result.coeffs = new int[maxDegree + 1];
        for (int i = 0; i < maxDegree + 1; i++)
            result.coeffs[i] = 0;
        for (int i = 0; i < minDegree + 1; i++)
        {
            result.coeffs[i] = this->coeffs[i] - p.coeffs[i];
        }
        for (int i = minDegree + 1; i < maxDegree + 1; i++)
        {
            if (this->degree > p.degree)
                result.coeffs[i] = this->coeffs[i];
            else
                result.coeffs[i] = -p.coeffs[i];
        }
        result.normalizePolynomial();
        return result;
    }
    // mnozenie
    POLYNOMIAL operator*(const POLYNOMIAL &p)
    {
        int resultDegree = this->degree + p.degree;
        POLYNOMIAL result = POLYNOMIAL();
        delete[] result.coeffs;
        result.degree = resultDegree;
        result.coeffs = new int[resultDegree + 1];
        for (int i = 0; i < resultDegree + 1; i++)
            result.coeffs[i] = 0;
        for (int i = 0; i < this->degree + 1; i++)
            for (int j = 0; j < p.degree + 1; j++)
                result.coeffs[i + j] += this->coeffs[i] * p.coeffs[j];

        result.normalizePolynomial();
        return result;
    }
    // dzielenie
    POLYNOMIAL operator/(const POLYNOMIAL &p)
    {
        if (p.degree > this->degree || (p.degree == 0 && p.coeffs[0] == 0) || (this->degree == 0 && this->coeffs[0] == 0))
            return POLYNOMIAL();
        int resultDegree = this->degree - p.degree;
        bool wasNegative = p.coeffs[p.degree] < 0;
        bool wasOdd = (this->degree - p.degree) % 2 == 1;
        POLYNOMIAL quotient;
        POLYNOMIAL remainder(*this);
        quotient.degree = resultDegree;
        delete[] quotient.coeffs;
        quotient.coeffs = new int[quotient.degree + 1];
        for (int i = 0; i < quotient.degree + 1; i++)
            quotient.coeffs[i] = 0;
        int divisorCoeff = p.coeffs[p.degree];
        int prevDegree = this->degree;
        while (this->degree >= p.degree)
        {
            quotient.coeffs[this->degree - p.degree] = remainder.coeffs[this->degree];
            for (int i = p.degree; i > 0; i--)
                remainder.coeffs[this->degree - i] = remainder.coeffs[this->degree - i] * divisorCoeff - quotient.coeffs[this->degree - p.degree] * p.coeffs[p.degree - i];
            for (int i = 0; i < this->degree - p.degree; i++)
                remainder.coeffs[i] *= divisorCoeff;
            for (int i = quotient.degree; i >= this->degree - p.degree; i--)
                quotient.coeffs[i] *= divisorCoeff;
            this->degree--;
        }
        if (wasOdd && wasNegative)
            for (int i = 0; i < quotient.degree + 1; i++)
                quotient.coeffs[i] *= -1;
        this->degree = prevDegree;
        quotient.normalizePolynomial();
        return quotient;
    }
    // modulo
    POLYNOMIAL operator%(const POLYNOMIAL &p)
    {
        if (p.degree > this->degree)
            return *this;
        if (p.degree == 0 || this->degree == 0)
            return POLYNOMIAL();
        int resultDegree = this->degree - p.degree;
        int remainderDegree = p.degree - 1;
        POLYNOMIAL quotient;
        POLYNOMIAL remainder(*this);
        quotient.degree = resultDegree;
        delete[] quotient.coeffs;
        quotient.coeffs = new int[quotient.degree + 1];
        for (int i = 0; i < quotient.degree + 1; i++)
            quotient.coeffs[i] = 0;
        int divisorCoeff = p.coeffs[p.degree];
        int prevDegree = this->degree;
        while (this->degree >= p.degree)
        {
            quotient.coeffs[this->degree - p.degree] = remainder.coeffs[this->degree];
            for (int i = p.degree; i > 0; i--)
                remainder.coeffs[this->degree - i] = remainder.coeffs[this->degree - i] * divisorCoeff - quotient.coeffs[this->degree - p.degree] * p.coeffs[p.degree - i];
            for (int i = 0; i < this->degree - p.degree; i++)
                remainder.coeffs[i] *= divisorCoeff;
            for (int i = quotient.degree; i >= this->degree - p.degree; i--)
                quotient.coeffs[i] *= divisorCoeff;
            this->degree--;
        }
        this->degree = prevDegree;
        remainder.degree = remainderDegree;
        int *remainderCoeffs = new int[remainder.degree + 1];
        for (int i = 0; i < remainder.degree + 1; i++)
            remainderCoeffs[i] = remainder.coeffs[i];
        delete[] remainder.coeffs;
        remainder.coeffs = remainderCoeffs;
        if ((this->degree - p.degree) % 2 == 0 && p.coeffs[p.degree] < 0)
            remainder = -remainder;
        remainder.normalizePolynomial();
        return remainder;
    }
    // shift right
    POLYNOMIAL operator>>(int n)
    {
        POLYNOMIAL result(*this);
        if (n < 0)
            return POLYNOMIAL();
        if (result.degree == 0 && result.coeffs[0] == 0 || n == 0)
            return result;
        for (int i = 0; i < n; i++)
        {
            int *copyArray = new int[result.degree + 1];
            for (int j = 0; j < result.degree + 1; j++)
                copyArray[j] = result.coeffs[j];
            delete[] result.coeffs;
            result.degree++;
            result.coeffs = new int[result.degree + 1];
            result.coeffs[0] = 0;
            for (int j = result.degree; j > 0; j--)
                result.coeffs[j] = copyArray[j - 1];
            delete[] copyArray;
        }
        result.normalizePolynomial();
        return result;
    }
    // shift left
    POLYNOMIAL operator<<(int n)
    {
        POLYNOMIAL result(*this);
        if (n == 0)
            return result;
        else if (result.degree == 0 && n != 0 || n < 0)
            return POLYNOMIAL();
        for (int i = 0; i < n; i++)
        {
            if (result.degree == 0)
            {
                result.coeffs[0] = 0;
                break;
            }
            int *copyArray = new int[result.degree + 1];
            for (int j = 0; j < result.degree + 1; j++)
                copyArray[j] = result.coeffs[j];
            delete[] result.coeffs;
            result.degree--;
            result.coeffs = new int[result.degree + 1];
            for (int j = 0; j < result.degree + 1; j++)
                result.coeffs[j] = copyArray[j + 1];
            delete[] copyArray;
        }
        result.normalizePolynomial();
        return result;
    }
    // minus unarny
    POLYNOMIAL operator-()
    {
        POLYNOMIAL result(*this);
        for (int i = 0; i < result.degree + 1; i++)
            result.coeffs[i] *= -1;
        return result;
    }
    // OPERATORY ARYTMETYCZNE KOMPOZYCYJNE
    //--------------
    // dodawanie
    POLYNOMIAL operator+=(const POLYNOMIAL &p)
    {

        *this = *this + p;
        return *this;
    }
    // odejmowanie
    POLYNOMIAL operator-=(const POLYNOMIAL &p)
    {
        *this = *this - p;
        return *this;
    }
    // mnozenie
    POLYNOMIAL operator*=(const POLYNOMIAL &p)
    {
        *this = *this * p;
        return *this;
    }
    // dzielenie
    POLYNOMIAL operator/=(const POLYNOMIAL &p)
    {
        *this = *this / p;
        return *this;
    }
    // modulo
    POLYNOMIAL operator%=(const POLYNOMIAL &p)
    {
        *this = *this % p;
        return *this;
    }
    // shift right
    POLYNOMIAL &operator>>=(int n)
    {
        *this = *this >> n;
        return *this;
    }
    // shift left
    POLYNOMIAL &operator<<=(int n)
    {
        *this = *this << n;
        return *this;
    }
    // OPERATORY INKREMENTACYJNE/DEKREMENTACYJNE
    //--------------
    // inkrementacja
    // post
    POLYNOMIAL operator++(int)
    {
        POLYNOMIAL polyCopy(*this);
        for (int i = 0; i < this->degree + 1; i++)
            this->coeffs[i]++;
        this->normalizePolynomial();
        return polyCopy;
    }
    // pre
    POLYNOMIAL &operator++()
    {
        for (int i = 0; i < this->degree + 1; i++)
            this->coeffs[i]++;
        this->normalizePolynomial();
        return *this;
    }
    // dekrementacja
    // post
    POLYNOMIAL operator--(int)
    {
        POLYNOMIAL polyCopy(*this);
        for (int i = 0; i < this->degree + 1; i++)
            this->coeffs[i]--;
        this->normalizePolynomial();
        return polyCopy;
    }
    // pre
    POLYNOMIAL &operator--()
    {
        for (int i = 0; i < this->degree + 1; i++)
            this->coeffs[i]--;
        this->normalizePolynomial();
        return *this;
    }
    // OPERATORY PAMIECI DYNAMICZNEJ
    //---------------
    // new
    void *operator new(size_t amount)
    {
        overloaded++;
        return ::new char[amount];
    }
    // delete
    void operator delete(void *ptr)
    {
        overloaded--;
        ::delete ptr;
    }
};
// PRZELADOWANIA GLOBALNE
//------------------
// OPERATORY IN/OUT
// przeladowanie wejscia
istream &operator>>(istream &in, POLYNOMIAL &p)
{
    in >> p.degree;
    delete[] p.coeffs;
    p.coeffs = new int[p.degree + 1];
    for (int i = 0; i < p.degree + 1; i++)
        in >> p.coeffs[i];
    p.normalizePolynomial();
    return in;
}
// przeladowanie wyjscia
ostream &operator<<(ostream &out, const POLYNOMIAL &p)
{
    out << "( ";
    for (int i = 0; i < p.degree + 1; i++)
    {
        out << p.coeffs[i];
        if (i + 1 != p.degree + 1)
            out << ", ";
        else
            out << " ";
    }
    out << ")";
    return out;
}
// OPERATORY LOGICZNE/RELACYJNE
bool operator==(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    if (p.degree != q.degree)
        return false;
    for (int i = p.degree; i >= 0; i--)
        if (p.coeffs[i] != q.coeffs[i])
            return false;
    return true;
}
bool operator!=(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    return !(p == q);
}
bool operator<(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    if (p.degree < q.degree)
        return true;
    else if (p.degree == q.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (p.coeffs[i] < q.coeffs[i])
                return true;
            else if (p.coeffs[i] > q.coeffs[i])
                return false;
        }
    }
    return false;
}
bool operator>(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    if (p.degree > q.degree)
        return true;
    else if (p.degree == q.degree)
    {
        for (int i = p.degree; i >= 0; i--)
        {
            if (p.coeffs[i] > q.coeffs[i])
                return true;
            else if (p.coeffs[i] < q.coeffs[i])
                return false;
        }
    }
    return false;
}
bool operator<=(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    return (p < q || p == q);
}
bool operator>=(const POLYNOMIAL &p, const POLYNOMIAL &q)
{
    return (p > q || p == q);
}
// int POLYNOMIAL::overloaded = 0;
// #define output cout << endl
// int main()
// {

//     output << (POLYNOMIAL() / POLYNOMIAL(0, 1));

//     output << (POLYNOMIAL(2, 1, -2, 1) / POLYNOMIAL(2, 1, -2, 1));

//     output << (POLYNOMIAL(0, 1) / POLYNOMIAL(0, 1));

//     output << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(0, 1));

//     output << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, 1, 1));

//     output << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, -1, -1));

//     output << (POLYNOMIAL(4, 2, 3, 5, 7, 11) / POLYNOMIAL(1, 0, 1));

//     output << (POLYNOMIAL(2, 1, 1, -2) / POLYNOMIAL(1, -1, 1));

//     output << (POLYNOMIAL(2, 1, 1, -2) / POLYNOMIAL(0, -1));

//     output << (POLYNOMIAL(2, 1, 1, 2) / POLYNOMIAL(1, -1, 1));

//     output << (POLYNOMIAL(2, 1, 4, 2) / POLYNOMIAL(1, 1, 1));

//     output << (POLYNOMIAL(2, 2, 3, 5) / POLYNOMIAL(1, 1, 7));

//     output << (POLYNOMIAL() / POLYNOMIAL(2, 4, -4, 1));

//     output << (POLYNOMIAL(1, 1, 2) / POLYNOMIAL(2, 4, -4, 1));

//     output << (POLYNOMIAL(3, -1, 4, -5, 2) / POLYNOMIAL(1, -1, 1));

//     output << (POLYNOMIAL(3, -4, -4, 1, 1) / POLYNOMIAL(1, 1, 1));

//     output << (POLYNOMIAL(2, 7, 7, 5) / POLYNOMIAL(1, 2, -4));

//     output << (POLYNOMIAL(2, 1, 2, -1) / POLYNOMIAL(2, 2, -6, 4));

//     output << (POLYNOMIAL(3, -7, 5, -3, 7) / POLYNOMIAL(3, 7, 6, 4, -2));

//     output << (POLYNOMIAL(4, 4, 2, 5, -2, 1) / POLYNOMIAL(2, 3, -3, -4));

//     output << (POLYNOMIAL(5, 1, -1, -4, -5, 0, -7) / POLYNOMIAL(1, 2, 4));

//     output << (POLYNOMIAL(5, 4, -4, -5, 2, -7, -7) / POLYNOMIAL(1, -4, 3));

//     output << (POLYNOMIAL(6, 0, -5, -4, 6, 1, -4, 6) / POLYNOMIAL(3, 2, -5, 6, 7));

//     output << (POLYNOMIAL(6, -1, 0, 2, 1, 3, 0, -1) / POLYNOMIAL(5, -4, 3, 1, 4, -7, 5));

//     output << (POLYNOMIAL(3, -4, -4, 1, 1) / POLYNOMIAL(2, -4, 0, 1));

//     POLYNOMIAL p1 = POLYNOMIAL(2, 0, 1, 2);
//     POLYNOMIAL p2 = POLYNOMIAL(0, 4);
//     output << p1 / p2;
// }
