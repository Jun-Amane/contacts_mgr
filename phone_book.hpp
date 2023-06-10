//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _PHONE_BOOK_HPP_
#define _PHONE_BOOK_HPP_

#include "public.hpp"
#include "contact_abstract.hpp"
#include "hash_table.hpp"
#include "phone_contact.hpp"
#include "file_mgr.hpp"

namespace phone_book
{

    class phone_book : public contact_abstract{

     public:

      phone_book();
//      ~phone_book(); // TODO: 析构函数，文件写入

      bool insert_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      bool insert_item(std::string name, std::string phone_number) override;
      void modify_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      void modify_item(std::string name, std::string phone_number) override;


    };

} // phone_book

#endif //_PHONE_BOOK_HPP_
