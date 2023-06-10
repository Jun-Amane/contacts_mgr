//
// Created by Jun ASAKA on 08/06/23.
//

#include "phone_book.hpp"

namespace phone_book
{
    phone_book::phone_book ()
    {
      name_table = file_mgr::read_phone_name_table("2.txt");
      phone_table = file_mgr::read_phone_phone_table ("2.txt");
      // TODO: file-reading
    }
    bool phone_book::insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      if(size >= 1000){
          std::cout << "Phone book is full" << std::endl;
          return false;
        }
      name_table->insert(new phone_contact::phone_contact(name, phone_number, origin, qq_id), name);
      phone_table->insert (new phone_contact::phone_contact(name, phone_number, origin, qq_id), phone_number);
        return true;
    }

    void phone_book::modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      name_table->modify (new phone_contact::phone_contact(name, phone_number, origin, qq_id), name); // only changes the first one

    }
    bool phone_book::insert_item (std::string name, std::string phone_number)
    {
      // Not Implemented.
      return false;

    }
    void phone_book::modify_item (std::string name, std::string phone_number)
    {
      // Not Implemented.
    }


} // phone_book