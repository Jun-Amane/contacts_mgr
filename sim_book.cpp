//
// Created by Jun ASAKA on 09/06/23.
//

#include "sim_book.hpp"

namespace sim_book
{
    sim_book::sim_book ()
    {

      name_table = file_mgr::read_sim_name_table ("1.txt");
      phone_table = file_mgr::read_sim_phone_table ("1.txt");
      // TODO: file-reading

    }
    bool sim_book::insert_item (std::string name, std::string phone_number)
    {
      if(size >= 1000){
          std::cout << "Sim book is full" << std::endl;
          return false;
        }
      name_table->insert(new sim_contacts::sim_contacts(name, phone_number), name);
      phone_table->insert (new sim_contacts::sim_contacts(name, phone_number), phone_number);
      return true;
    }
    void sim_book::modify_item (std::string name, std::string phone_number)
    {
      name_table->modify (new sim_contacts::sim_contacts(name, phone_number), name); // only changes the first one
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


} // sim_book