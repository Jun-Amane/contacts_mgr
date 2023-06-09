//
// Created by Jun ASAKA on 09/06/23.
//

#include "sim_book.hpp"

namespace sim_book
{
    sim_book::sim_book ()
    {
      // TODO: file-reading

    }
    void sim_book::insert_item (std::string name, std::string phone_number)
    {
      if(size >= 1000){
          std::cout << "Sim book is full" << std::endl;
          return;
        }
      name_table->insert(new sim_contacts::sim_contacts(name, phone_number), name);
      phone_table->insert (new sim_contacts::sim_contacts(name, phone_number), phone_number);
    }
    void sim_book::modify_item (std::string name, std::string phone_number)
    {
      name_table->modify (new sim_contacts::sim_contacts(name, phone_number), name); // only changes the first one
    }
    void sim_book::insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      // Not Implemented.
      if(size >= 1000){
          std::cout << "Sim book is full" << std::endl;
          return;
        }
      name_table->insert(new sim_contacts::sim_contacts(name, phone_number), name);
      phone_table->insert (new sim_contacts::sim_contacts(name, phone_number), phone_number);
    }
    void sim_book::modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id)
    {
      // Not Implemented.
      name_table->modify (new sim_contacts::sim_contacts(name, phone_number), name); // only changes the first one
    }


} // sim_book