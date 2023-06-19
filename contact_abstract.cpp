/*
 * contact_abstract.cpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：用于实现电话簿的抽象类源文件。
 *
 */

#include "contact_abstract.hpp"

contact_abstract::contact_abstract ()
{
  size = 0;
  name_table = nullptr; // 子类中初始化。
  phone_table = nullptr;
}

void contact_abstract::delete_item (const std::string &phone_number)
{
  while (phone_table->search_phone (phone_number)) // 循环删除所有条目。
    {
      std::string name = phone_table->get_name_by_phone (phone_number); // 从phone_table中找到名字。
      phone_table->remove (phone_number);
      name_table->remove_by_name (name);
      std::cout << "[DEBUG] removed : " << name << std::endl;
    }
}

void contact_abstract::display ()
{
  name_table->display_all ();
}

bool contact_abstract::query (const std::string &name)
{
  auto *ptr = name_table->query_name (name);
  if (ptr == nullptr)
    {
      // std::cout << "not found" << std::endl;
      return false;
    }
  else
    {
      ptr->readable_print (std::cout); // 格式化输出到stdcout。
      std::cout << std::endl;
      return true;
    }
}

std::string contact_abstract::get_phone (const std::string &name) const
{
  auto *ptr = name_table->query_name (name);
  if (ptr == nullptr)
    {
      std::cout << "\033[41;37mnot found\033[0m\n" << std::endl;
      throw "contact_abstract::get_phone: not found"; // 抛出异常，在调用处接收。
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

