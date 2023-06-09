//
// Created by Jun ASAKA on 09/06/23.
//

#include "contact_abstract.hpp"

contact_abstract::contact_abstract ()
{
  size = 0;
  name_table = new hash_table();
  phone_table = new hash_table();
}

void contact_abstract::delete_item (std::string phone_number)
{
  while(phone_table->search_phone(phone_number)){
      std::string name = phone_table->get_name_by_phone(phone_number);
      phone_table->remove(phone_number);
      name_table->remove_by_name(name);
      std::cout << "removed : " << name << std::endl; //TODO: this is DEBUG, remove this line.
    }
}
void contact_abstract::display ()
{
  name_table->display_all();
}
void contact_abstract::query (const std::string& name)
{
  name_table->search_name (name);
}

