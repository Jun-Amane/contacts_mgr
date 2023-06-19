/*
 * phone_book.hpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：储存于sim卡的电话簿类。
 *
 */

#include "sim_book.hpp"

namespace sim_book
{
    sim_book::sim_book ()
    {

      name_table = file_mgr::read_sim_name_table (SIM_BOOK_FILE); // 读取文件中的联系人信息（file_mgr中的读取函数自会分配内存）。
      phone_table = file_mgr::read_sim_phone_table (SIM_BOOK_FILE);

    }

    sim_book::~sim_book ()
    {
      this->write_to_file (SIM_BOOK_FILE);  // 写入文件。
      delete name_table;  // 释放内存。
      delete phone_table;
      std::cout << "[DEBUG] sim_book destructor called" << std::endl;
    }

    bool sim_book::insert_item (std::string name, std::string phone_number)
    {
      if (size >= 1000) // 判断是否已满
        {
          std::cout << "Sim book is full" << std::endl;
          return false;
        }

      // 插入哈希表
      name_table->insert (new sim_contacts::sim_contacts (name, phone_number), name);
      phone_table->insert (new sim_contacts::sim_contacts (name, phone_number), phone_number);
      return true;
    }

    void sim_book::modify_item (std::string name, std::string phone_number)
    {
      name_table->modify (new sim_contacts::sim_contacts (name, phone_number), name); // only changes the first one
    }

    bool sim_book::insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      // Not Implemented.
      return false;

    }

    void sim_book::modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      // Not Implemented.
    }

    void sim_book::save ()
    {

      this->write_to_file (SIM_BOOK_FILE);  // 写入文件。

    }

} // sim_book