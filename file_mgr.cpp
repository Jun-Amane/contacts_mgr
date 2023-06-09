//
// Created by Jun ASAKA on 2023/6/9.
//

#include "file_mgr.hpp"

namespace file_mgr
{

    hash_table *read_sim_name_table (std::string file_name)
    {
      auto *name_table = new hash_table ();
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          sim_contacts::sim_contacts contact;
          while (file >> contact)
            {
              sim_contacts::sim_contacts *item = new sim_contacts::sim_contacts (contact);
              name_table->insert (item, item->get_name ());
            }
          file.close ();
          std::cout << "read succeed" << std::endl;
        }
      else
        {
          std::cout << "read failed" << std::endl;
        }

      return name_table;
    }

    hash_table *read_sim_phone_table (std::string file_name)
    {
      auto *phone_table = new hash_table ();
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          sim_contacts::sim_contacts contact;
          while (file >> contact)
            {
              sim_contacts::sim_contacts *item = new sim_contacts::sim_contacts (contact);
              phone_table->insert (item, item->get_phone_number ());
            }
          file.close ();
          std::cout << "read succeed" << std::endl;
        }
      else
        {
          std::cout << "read failed" << std::endl;
        }

      return phone_table;
    }

    hash_table *read_phone_name_table (std::string file_name)
    {
      auto *name_table = new hash_table ();
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          phone_contact::phone_contact contact;
          while (file >> contact)
            {
              phone_contact::phone_contact *item = new phone_contact::phone_contact (contact);
              name_table->insert (item, item->get_name ());
            }
          file.close ();
          std::cout << "read succeed" << std::endl;
        }
      else
        {
          std::cout << "read failed" << std::endl;
        }

      return name_table;
    }
    hash_table *read_phone_phone_table (std::string file_name)
    {
      auto *phone_table = new hash_table ();
      std::ifstream file (file_name);

      if (file.is_open ())
        {
          phone_contact::phone_contact contact;
          while (file >> contact)
            {
              phone_contact::phone_contact *item = new phone_contact::phone_contact (contact);
              phone_table->insert (item, item->get_phone_number ());
            }
          file.close ();
          std::cout << "read succeed" << std::endl;
        }
      else
        {
          std::cout << "read failed" << std::endl;
        }

      return phone_table;
    }

    bool write_sim_book (std::string file_name, hash_table *name_table)
    {
      std::ofstream file (file_name);
      if (file.is_open ())
        {
          for (const auto &item: name_table->to_vector ())
            {
              file << *item << std::endl;
            }
          file.close ();
          std::cout << "write succeed" << std::endl;
          return true;
        }
      else
        {
          std::cout << "write failed" << std::endl;
          return false;
        }

    }

}
