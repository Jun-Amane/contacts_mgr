//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _SIM_CONTACTS_HPP_
#define _SIM_CONTACTS_HPP_

#include "public.hpp"

namespace sim_contacts
{

    class sim_contacts {

     protected:
      std::string name;
      std::string phone_number;

     public:



      sim_contacts (std::string name = "", std::string phone_number = "");

      std::string get_name() const;
      std::string get_phone_number() const;

      void set (std::string para_name, std::string para_phone_number);
      //bool modify (std::string value, fields para_fields);

      virtual std::istream &read (std::istream &is);
      virtual std::ostream &print (std::ostream &os) const;
      virtual std::ostream &readable_print (std::ostream &os) const;

      friend std::ostream &operator<< (std::ostream &os, const sim_contacts &obj);
      friend std::istream &operator>> (std::istream &is, sim_contacts &obj);


    };
}
#endif //_SIM_CONTACTS_HPP_
