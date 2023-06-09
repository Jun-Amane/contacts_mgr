//
// Created by Jun ASAKA on 08/06/23.
//

#include "sim_contacts.hpp"

namespace sim_contacts
{
    sim_contacts::sim_contacts (std::string name, std::string phone_number)
    {
      this->name = name;
      this->phone_number = phone_number;
    }

    void sim_contacts::set (std::string para_name, std::string para_phone_number)
    {

      this->name = para_name;
      this->phone_number = para_phone_number;

      return;
    }
//    bool sim_contacts::modify (std::string value, enum fields para_fields)
//    {
//      switch (para_fields)
//        {
//          case field_name:
//            this->name = value;
//          return true;
//          case field_phone_number:
//            this->phone_number = value;
//          return true;
//          default:
//            return false;
//        }
//
//    }


    std::istream &sim_contacts::read (std::istream &is)
    {
      std::getline(is, this->name, ',');
      std::getline(is, this->phone_number, '\n');
      return is;
    }
    std::ostream &sim_contacts::print (std::ostream &os) const
    {
      os << this->name << "," << this->phone_number;
      return os;
    }


    std::ostream &operator<< (std::ostream &os, const sim_contacts &obj)
    {
      return obj.print (os);
    }
    std::istream &operator>> (std::istream &is, sim_contacts &obj)
    {
      return obj.read (is);
    }
    std::string sim_contacts::get_name () const
    {
      return this->name;
    }
    std::string sim_contacts::get_phone_number () const
    {
      return this->phone_number;
    }

}