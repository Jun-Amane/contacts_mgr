//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _PHONE_BOOK_HPP_
#define _PHONE_BOOK_HPP_

#include "public.hpp"
#include "contact_abstract.hpp"
#include "hash_table.hpp"
#include "phone_contact.hpp"

namespace phone_book
{

    class phone_book : public contact_abstract{

     public:

      phone_book();

      void insert_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      void insert_item(std::string name, std::string phone_number) override;
      void modify_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      void modify_item(std::string name, std::string phone_number) override;


    };

} // phone_book

#endif //_PHONE_BOOK_HPP_
