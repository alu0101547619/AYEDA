#include "BigFloat.h"

BigFloat::BigFloat(const BigFloat& number) {
   realpart_ = number.realpart_;
   decimalpart_ = number.decimalpart_;

}

BigFloat::BigFloat(const BigInteger& number1, const BigInteger& number2) {
  realpart_ = number1;
  decimalpart_ = number2;
}

std::ostream& operator<<(std::ostream& os, const BigFloat& number) {
  os << number.realpart_ << "." << number.decimalpart_;
  return os;
}