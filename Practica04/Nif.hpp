#pragma  once

#include <iostream>
#include <cstdlib> 
#include <ctime>   

class Nif {
  public:
    Nif();
    Nif(long number);
    operator long() const;
    bool operator==(const Nif& other) const;
    bool operator!=(const Nif& other) const;
    bool operator<(const Nif& other) const;
    bool operator>(const Nif& other) const;
    bool operator<=(const Nif& other) const;
    bool operator>=(const Nif& other) const;

  private:
    long number_;

};