//
// Created by Jun ASAKA on 09/06/23.
//

#include "contact_abstract.hpp"

contact_abstract::contact_abstract ()
{
  size = 0;
  name_table = nullptr; // 子类中初始化。
  phone_table = nullptr;
}

void contact_abstract::delete_item (const std::string &phone_number)
{
  while (phone_table->search_phone (phone_number))
    {
      std::string name = phone_table->get_name_by_phone (phone_number);
      phone_table->remove (phone_number);
      name_table->remove_by_name (name);
      std::cout << "removed : " << name << std::endl; //TODO: this is DEBUG, remove this line.
    }
}
void contact_abstract::display ()
{
  name_table->display_all ();
}
void contact_abstract::query (const std::string &name)
{
  auto *ptr = name_table->query_name (name);
  if (ptr == nullptr)
    {
      std::cout << "not found" << std::endl;
    }
  else
    {
      ptr->readable_print (std::cout);
      std::cout << std::endl;
    }
}
std::string contact_abstract::get_phone (const std::string &name) const
{
  auto *ptr = name_table->query_name (name);
  if (ptr == nullptr)
    {
      std::cout << "not found" << std::endl;
      throw "contact_abstract::get_phone: not found";
    }
  else
    {
      return ptr->get_phone_number ();
    }

}
bool contact_abstract::search_phone (const std::string &key)
{
  return phone_table->search_phone (key);
}
bool contact_abstract::search_name (const std::string &key)
{
  return name_table->search_name (key);
}
void contact_abstract::write_to_file (const std::string &file_name)
{
  file_mgr::write_sim_book (file_name, this->name_table);
}

