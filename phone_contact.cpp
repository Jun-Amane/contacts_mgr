//
// Created by Jun ASAKA on 08/06/23.
//

#include "phone_contact.hpp"

namespace phone_contact
{

    void
    phone_contact::set (std::string para_name, std::string para_phone_number, std::string para_origin, std::string para_qq_id)
    {
      this->name = para_name;
      this->phone_number = para_phone_number;
      this->origin = para_origin;
      this->qq_id = para_qq_id;
    }

    bool phone_contact::modify (std::string value, phone_contact::phone_contact::fields para_fields)
    {
      switch (para_fields)
        {
          case field_name:
            this->name = value;
          return true;
          case field_phone_number:
            this->phone_number = value;
          return true;
          case field_origin:
            this->origin = value;
          return true;
          case field_qq_id:
            this->qq_id = value;
          return true;
          default:
            return false;
        }
    }
    std::istream &phone_contact::read (std::istream &is)
    {
      std::getline(is, this->name, ',');
      std::getline(is, this->phone_number, ',');
      std::getline(is, this->origin, ',');
      std::getline(is, this->qq_id, '\n');
      return is;
    }
    std::ostream &phone_contact::print (std::ostream &os) const
    {
      os << this->name << "," << this->phone_number << "," << this->origin << "," << this->qq_id;
      return os;
    }
    std::string phone_contact::get_origin () const
    {
      return this->origin;
    }
    std::string phone_contact::get_qq_id () const
    {
      return this->qq_id;
    }

} // phone_contact