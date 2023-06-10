//
// Created by Jun ASAKA on 2023/6/9.
//

#include "user.hpp"

namespace user
{
    user::user ()
    {
      phone_book_ptr = new phone_book::phone_book ();
      sim_book_ptr = new sim_book::sim_book ();
    }

    user::~user ()
    {
      delete phone_book_ptr;
      delete sim_book_ptr;
    }

    void user::add_contact ()
    {
      int media_type;

      std::string name, phone_number, origin, qq_id;
      bool flag = false;
      while (true)
        {
          std::cout << "键入操作位置：1 for sim, 2 for phone:";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          switch (media_type)
            {
              case 1:

                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "input phone: ";
              std::cin >> phone_number;
              flag = sim_book_ptr->insert_item (name, phone_number);

              break;

              case 2:
                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "input phone: ";
              std::cin >> phone_number;
              std::cout << "input origin: ";
              std::cin >> origin;
              std::cout << "input qq id: ";
              std::cin >> qq_id;
              flag = phone_book_ptr->insert_item (name, phone_number, origin, qq_id);
              break;

              default:
                std::cout << "invalid input\n";
              continue;
            }
          break;
        }

        if(!flag)
          std::cout << "错误" << std::endl;

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
      int media_type;

      std::string name, phone_number, origin, qq_id;
      while (true)
        {
          std::cout << "键入操作位置：1 for sim, 2 for phone:";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          switch (media_type)
            {
              case 1:
                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "input phone: ";
              std::cin >> phone_number;
              sim_book_ptr->modify_item (name, phone_number);
              break;

              case 2:
                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "input phone: ";
              std::cin >> phone_number;
              std::cout << "input origin: ";
              std::cin >> origin;
              std::cout << "input qq id: ";
              std::cin >> qq_id;
              phone_book_ptr->modify_item (name, phone_number, origin, qq_id);
              break;

              default:
                std::cout << "invalid input\n";
              continue;
            }
          break;
        }

    }
    void user::search_contact ()
    {

      int media_type;

      std::string name;
      while (true)
        {
          std::cout << "键入操作位置：1 for sim, 2 for phone, 0 for all:";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          switch (media_type)
            {
              case 0:
                std::cout << "input name: ";
              std::cin >> name;
              sim_book_ptr->query (name);
              phone_book_ptr->query (name);
              break;

              case 1:
                std::cout << "input name: ";
              std::cin >> name;
              sim_book_ptr->query (name);
              break;

              case 2:

                std::cout << "input name: ";
              std::cin >> name;
              phone_book_ptr->query (name);
              break;

              default:
                std::cout << "invalid input\n";
              continue;
            }
          break;
        }

    }
    void user::display_contact ()
    {

      int media_type;

      while (true)
        {
          std::cout << "键入操作位置：1 for sim, 2 for phone, 0 for all:";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          switch (media_type)
            {
              case 0:
                sim_book_ptr->display ();
                phone_book_ptr->display ();
              break;

              case 1:
                sim_book_ptr->display ();
              break;

              case 2:
                phone_book_ptr->display ();
              break;

              default:
                std::cout << "invalid input\n";
              continue;
            }
          break;
        }

    }


    void user::copy2sim ()
    {
      std::string name;
      bool flag = false;
      std::cout << "键入名字：";
      std::cin >> name;

      if(sim_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
      if(!flag)
        std::cout << "错误" << std::endl;

    }
    void user::copy2phone ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if(phone_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name), "", "");
      if(!flag)
        std::cout << "错误" << std::endl;

    }
    void user::move2sim ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if(sim_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
      if (flag)
        phone_book_ptr->delete_item (phone_book_ptr->get_phone (name));
      else
        std::cout << "错误" << std::endl;
    }
    void user::move2phone ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if(phone_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name));
      if (flag)
        sim_book_ptr->delete_item (sim_book_ptr->get_phone (name));
      else
        std::cout << "错误" << std::endl;

    }
} // user