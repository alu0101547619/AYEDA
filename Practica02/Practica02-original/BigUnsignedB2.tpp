#pragma once

#include "BigUnsigned.h"
#include "BigUnsignedB2.h"

BigUnsigned<2>::BigUnsigned(unsigned n) {  
    std::cout << "Si\n";
    while (n > 0) {
        bits_.push_back(n % 2);
        n /= 2;
    }
    if (bits_.empty()) bits_.push_back(0);
}


BigUnsigned<2>::BigUnsigned(const string& bin) {
    std::cout << "Si\n";
    for (int i = bin.size() - 1; i >= 0; --i) {
        if (bin[i] == '0') {
            bits_.push_back(false);
        } else if (bin[i] == '1') {
            bits_.push_back(true);   
        } else {
            throw invalid_argument("Cadena no válida en base 2");
        }
    }
}
