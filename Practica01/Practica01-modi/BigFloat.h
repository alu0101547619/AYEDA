#pragma once

#include "BigInteger.h"

class BigFloat {
 public:
  BigFloat(const BigFloat& number);
  BigFloat(const BigInteger&, const BigInteger&);
  friend std::ostream& operator<<(std::ostream& os, const BigFloat& number);
 private:
  BigInteger realpart_;
  BigInteger decimalpart_;
};