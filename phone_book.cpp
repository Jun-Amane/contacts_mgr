/*
 * phone_book.cpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：电话本类。
 *
 */

#include "phone_book.hpp"

namespace phone_book
{

    phone_book::phone_book ()
    {
      name_table = file_mgr::read_phone_name_table (PHONE_BOOK_FILE); // 读取文件并构建哈希表。
      phone_table = file_mgr::read_phone_phone_table (PHONE_BOOK_FILE);
    }

    phone_book::~phone_book ()
    {
      this->write_to_file (PHONE_BOOK_FILE);  // 写入文件。
      delete name_table;  // 释放内存。
      delete phone_table;
      std::cout << "[DEBUG] phone_book destructor called" << std::endl;
    }

    bool phone_book::insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      if (size >= 1000) // 判断是否已满
        {
          std::cout << "Phone book is full" << std::endl;
          return false;
        }

      // 插入哈希表
      name_table->insert (new phone_contact::phone_contact (name, phone_number, origin, qq_id), name);
      phone_table->insert (new phone_contact::phone_contact (name, phone_number, origin, qq_id), phone_number);
      return true;
    }

    void phone_book::modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      name_table->modify (new phone_contact::phone_contact (name, phone_number, origin, qq_id), name);

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

    void phone_book::save ()
    {

      this->write_to_file (PHONE_BOOK_FILE);  // 写入文件。

    }

} // phone_book