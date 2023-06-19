/*
 * file_mgr.cpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：文件管理，用于读写文件。
 *
 */

#include "file_mgr.hpp"

namespace file_mgr
{

    hash_table *read_sim_name_table (const std::string &file_name)
    {
      auto *name_table = new hash_table (); // 创建哈希表。
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          sim_contacts::sim_contacts contact; // 栈中创建临时对象。
          while (file >> contact)
            {
              auto *item = new sim_contacts::sim_contacts (contact);  // 堆中创建对象，并得到地址。
              name_table->insert (item, item->get_name ()); // 将对象地址插入哈希表，以名字为键。
            }
          file.close ();
          std::cout << "[DEBUG] read succeed" << std::endl;
        }
      else
        {
          std::cout << "[DEBUG] read failed" << std::endl;
        }

      return name_table;
    }

    hash_table *read_sim_phone_table (const std::string &file_name)
    {
      auto *phone_table = new hash_table ();  // 创建哈希表。
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          sim_contacts::sim_contacts contact; // 栈中创建临时对象。
          while (file >> contact)
            {
              auto *item = new sim_contacts::sim_contacts (contact);  // 堆中创建对象，并得到地址。
              phone_table->insert (item, item->get_phone_number ());  // 将对象地址插入哈希表，以电话为键。
            }
          file.close ();
          std::cout << "[DEBUG] read succeed" << std::endl;
        }
      else
        {
          std::cout << "[DEBUG] read failed" << std::endl;
        }

      return phone_table;
    }

    hash_table *read_phone_name_table (const std::string &file_name)
    {
      auto *name_table = new hash_table (); // 创建哈希表。
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          phone_contact::phone_contact contact; // 栈中创建临时对象。
          while (file >> contact)
            {
              auto *item = new phone_contact::phone_contact (contact);  // 堆中创建对象，并得到地址。
              name_table->insert (item, item->get_name ()); // 将对象地址插入哈希表，以名字为键。
            }
          file.close ();
          std::cout << "[DEBUG] read succeed" << std::endl;
        }
      else
        {
          std::cout << "[DEBUG] read failed" << std::endl;
        }

      return name_table;
    }

    hash_table *read_phone_phone_table (const std::string &file_name)
    {
      auto *phone_table = new hash_table ();  // 创建哈希表。
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          phone_contact::phone_contact contact; // 栈中创建临时对象。
          while (file >> contact)
            {
              auto *item = new phone_contact::phone_contact (contact);  // 堆中创建对象，并得到地址。
              phone_table->insert (item, item->get_phone_number ());  // 将对象地址插入哈希表，以电话为键。
            }
          file.close ();
          std::cout << "[DEBUG] read succeed" << std::endl;
        }
      else
        {
          std::cout << "[DEBUG] read failed" << std::endl;
        }

      return phone_table;
    }

    bool write_sim_book (const std::string &file_name, hash_table *name_table)
    {
      std::ofstream file (file_name); // 打开文件。
      if (file.is_open ())
        {
          for (const auto &item: name_table->to_vector ())  // 使用哈希表API将其转换为std::vector对象，并通过迭代器遍历。
            {
              file << *item << std::endl; // 通过重载过的运算符写入文件。
            }
          file.close ();
          std::cout << "[DEBUG] write succeed" << std::endl;
          return true;
        }
      else
        {
          std::cout << "[DEBUG] write failed" << std::endl;
          return false;
        }

    }

}
