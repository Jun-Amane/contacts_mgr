//
// Created by Jun ASAKA on 2023/6/9.
//

#include "user.hpp"

namespace user
{
    user::user ()
    {
        phone_book_ptr = new phone_book::phone_book();
        sim_book_ptr = new sim_book::sim_book();
    }

    user::~user ()
    {
        delete phone_book_ptr;
        delete sim_book_ptr;
        delete book_ptr;
    }

    void user::add_contact ()
    {
      int media_type;
      std::cout << "键入操作位置：1 for sim, 2 for phone";
      std::cin >> media_type;


      std::string name, phone_number, origin, qq_id;

      std::cout << "input name: ";
      std::cin >> name;
      std::cout << "input phone: ";
      std::cin >> phone_number;

      switch(media_type) {
          case 1:
            sim_book_ptr->insert_item (name, phone_number);
            break;
          case 2:
            std::cout << "input origin: ";
            std::cin >> origin;
            std::cout << "input qq id: ";
            std::cin >> qq_id;
            phone_book_ptr->insert_item (name, phone_number, origin, qq_id);
            break;
      }
    }
    void user::delete_contact ()
    {
      std::string phone_number;
      std::cout << "input number: ";
      std::cin >> phone_number;

      phone_book_ptr->delete_item (phone_number);
      sim_book_ptr->delete_item (phone_number);

    }
    void user::modify_contact ()
    {

    }
    void user::search_contact ()
    {

    }
} // user