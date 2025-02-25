#include "BigRational.h"


template <unsigned char Base>
BigInteger<Base> BigRational<Base>::getNum() const {
    return num_;
}

template <unsigned char Base>
BigUnsigned<Base> BigRational<Base>::getDen() const {
    return den_;
}

template <unsigned char Base>
BigRational<Base>::BigRational(const BigInteger<Base>& numerador, const BigUnsigned<Base>& denominador) {
    num_ = numerador;
    den_ = denominador;
}

template <unsigned char Base>
std::istream& operator>>(std::istream& is, BigRational<Base>& number) {
    std::string input;
    is >> input;

    size_t slashPos = input.find('/');

    std::string numStr = input.substr(0, slashPos);
    std::string denStr = input.substr(slashPos + 1);

    // Convertir std::string a const unsigned char*
    const unsigned char* numCStr = reinterpret_cast<const unsigned char*>(numStr.c_str());
    const unsigned char* denCStr = reinterpret_cast<const unsigned char*>(denStr.c_str());

    // Construir BigInteger y BigUnsigned usando los constructores existentes
    BigInteger<Base> numerador(numCStr);
    BigUnsigned<Base> denominador(denCStr);

    number = BigRational<Base>(numerador, denominador);
    return is;
}


template <unsigned char Base>
std::ostream& operator<<(std::ostream& os, const BigRational<Base>& number) {
    os << number.getNum() << "/" << number.getDen();
    return os;
}

template <unsigned char Base>
BigRational<Base>& BigRational<Base>::operator=(const BigRational<Base>& number) {
    num_ = number.getNum();
    den_ = number.getDen();
    return *this;
}

template <unsigned char Base>
bool BigRational<Base>::operator==(const BigRational<Base>& number) const {
    return num_ == number.getNum() && den_ == number.getDen();
}

template <unsigned char Base>
bool BigRational<Base>::operator<(const BigRational<Base>&) const {
   
}

template <unsigned char Base>
BigRational<10> BigRational<Base>::convertirDecimal() const {
  BigRational<10> result;
  BigInteger<10> num = num_.convertirDecimal();
  BigUnsigned<10> den = den_.convertirDecimal();
  result = BigRational<10>(num, den);
  return result;
}