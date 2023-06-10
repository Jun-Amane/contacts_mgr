//
// Created by Jun ASAKA on 09/06/23.
//

#ifndef _SIM_BOOK_HPP_
#define _SIM_BOOK_HPP_

#include "public.hpp"
#include "contact_abstract.hpp"
#include "hash_table.hpp"
#include "sim_contacts.hpp"
#include "file_mgr.hpp"

namespace sim_book
{

    class sim_book : public contact_abstract{

     public:

      sim_book();
//      ~sim_book(); // TODO: 析构函数，文件写入

      bool insert_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      bool insert_item(std::string name, std::string phone_number) override;
      void modify_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) override;
      void modify_item(std::string name, std::string phone_number) override;
    };

} // sim_book

#endif //_SIM_BOOK_HPP_
