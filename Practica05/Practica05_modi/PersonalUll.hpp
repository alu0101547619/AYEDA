#pragma once

#include <iostream>
#include <cstdlib> 
#include <ctime>   

class PersonalUll {
  public:
    PersonalUll();
    PersonalUll(std::string id);
    PersonalUll(std::string id, std::string nombre, std::string apellido1, std::string apellido2);
    std::string getId() const { return id_;} ;
    operator long() const;
    bool operator==(const PersonalUll& other) const;
    bool operator!=(const PersonalUll& other) const;
    bool operator<(const PersonalUll& other) const;
    bool operator>(const PersonalUll& other) const;
    bool operator<=(const PersonalUll& other) const;
    bool operator>=(const PersonalUll& other) const;

  private:
    std::string id_;
    std::string nombre_;
    std::string apellido1_;
    std::string apellido2_;

};