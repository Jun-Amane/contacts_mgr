//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _PHONE_CONTACT_HPP_
#define _PHONE_CONTACT_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"


namespace phone_contact
{

    class phone_contact : public sim_contacts::sim_contacts{

     protected:
      std::string origin;
      std::string qq_id;


     public:

//      enum fields {
//          field_name,
//          field_phone_number,
//          field_origin,
//          field_qq_id
//      };
      phone_contact (std::string name = "", std::string phone_number = "", std::string origin = "", std::string qq_id = "" ) : sim_contacts::sim_contacts(name, phone_number), origin(origin), qq_id(qq_id) {};

      std::string get_origin() const;
      std::string get_qq_id() const;

      void set (std::string para_name, std::string para_phone_number, std::string para_origin, std::string para_qq_id);
//      bool modify (std::string value, fields para_fields);

      std::istream &read (std::istream &is) override;
      std::ostream &print (std::ostream &os) const override;


    };

} // phone_contact

#endif //_PHONE_CONTACT_HPP_
