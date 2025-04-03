#include "PersonalUll.hpp"

PersonalUll::PersonalUll() : id_(""), nombre_(""), apellido1_(""), apellido2_("")  {}

PersonalUll::PersonalUll(std::string id ) : id_(id)  {}

PersonalUll::PersonalUll(std::string id, std::string nombre, std::string apellido1, std::string apellido2 ) 
: id_(id),  nombre_(nombre), apellido1_(apellido1), apellido2_(apellido2) {}

PersonalUll::operator long() const { 
  std::string numero = "";
  std::string letras_ascii = "";
  for (char c : id_) {
    if (std::isdigit(c)) {
      numero += c;  
    } else if (std::isalpha(c)) {
      letras_ascii += std::to_string(static_cast<int>(c)); 
    }
  }
  std::string resultado_str = letras_ascii + numero;
  return std::stol(resultado_str);
}

bool PersonalUll::operator==(const PersonalUll& other) const { return id_ == other.id_ && nombre_ == other.nombre_ && apellido1_ == other.apellido1_ && apellido2_ == other.apellido2_;  }
bool PersonalUll::operator!=(const PersonalUll& other) const { return id_ != other.id_ && nombre_ != other.nombre_ && apellido1_ != other.apellido1_ && apellido2_ != other.apellido2_; }
bool PersonalUll::operator<(const PersonalUll& other) const { return id_ < other.id_; }
bool PersonalUll::operator>(const PersonalUll& other) const { return id_ > other.id_; }
bool PersonalUll::operator<=(const PersonalUll& other) const { return id_ <= other.id_; }
bool PersonalUll::operator>=(const PersonalUll& other) const { return id_ >= other.id_; }