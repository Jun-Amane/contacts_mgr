/*
 * user.cpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：用户类。
 *
 */
#include "user.hpp"

namespace user
{
    user::user ()
    {
      // 初始化两个通讯录。
      phone_book_ptr = new phone_book::phone_book ();
      sim_book_ptr = new sim_book::sim_book ();
    }

    user::~user ()
    {
      // 释放两个通讯录。
      delete phone_book_ptr;
      delete sim_book_ptr;
    }

    void user::add_contact ()
    {
      int media_type; // 1为sim卡，2为手机。

      std::string name, phone_number, origin, qq_id;  // 字段
      bool flag = false;  // 标记是否成功新建。
      while (true)
        {
          std::cout << "键入操作位置：1为sim卡，2为手机：";
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
              flag = sim_book_ptr->insert_item (name, phone_number);  // 调用sim_book的API，新建联系人。

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
                std::cout << "\033[41;37minvalid input\033[0m\n";
              continue;
            }
          break;  // 跳出死循环。
        }

      if (!flag)
        std::cout << "错误" << std::endl;

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }

    void user::delete_contact ()
    {
      std::string phone_number;
      std::cout << "input number: ";
      std::cin >> phone_number;

      phone_book_ptr->delete_item (phone_number); // 调用phone_book的API，删除指定手机号的联系人。
      sim_book_ptr->delete_item (phone_number);

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }
    void user::modify_contact ()
    {
      int media_type;

      std::string name, phone_number, origin, qq_id;
      while (true)
        {
          std::cout << "键入操作位置：1为sim卡，2为手机：";
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
              sim_book_ptr->modify_item (name, phone_number); // 调用sim_book的API，修改联系人。
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
                std::cout << "\033[41;37minvalid input\033[0m\n";
              continue;
            }
          break;  // 跳出死循环。
        }

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }
    void user::search_contact ()
    {

      int media_type;

      std::string name;
      while (true)
        {
          std::cout << "键入操作位置：1为sim卡，2为手机，3为所有：";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          switch (media_type)
            {
              case 1:
                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "\033[2J\033[1;1H";  // 清屏。
              std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                        << "Phone Number" << "\033[0m\n"; // 利用VT100控制码输出highlight的表头。
              if(!sim_book_ptr->query (name)) // 调用API查询，如果没查询到则输出提示。
                {
                  std::cout << "\033[41;37mnot found\033[0m\n";
                }
              break;

              case 2:

                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "\033[2J\033[1;1H";
              std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                        << "Phone Number" << std::left << std::setw (18) << "Origin" << std::left << std::setw (18)
                        << "QQ ID" << "\033[0m\n";
              if(!phone_book_ptr->query (name))
                {
                  std::cout << "\033[41;37mnot found\033[0m\n";
                }
              break;

              case 3:
                std::cout << "input name: ";
              std::cin >> name;
              std::cout << "\033[2J\033[1;1H";
              std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                        << "Phone Number" << std::left << std::setw (18) << "Origin" << std::left << std::setw (18)
                        << "QQ ID" << "\033[0m\n";
              sim_book_ptr->query (name);
              phone_book_ptr->query (name);
              break;

              default:
                std::cout << "\033[41;37minvalid input\033[0m\n";
              continue;
            }
          break;
        }

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }
    void user::display_contact ()
    {

      int media_type;

      while (true)
        {
          std::cout << "键入操作位置：1为sim卡，2为手机，3为所有：";
          std::cin >> media_type;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 防止错误输入字符残留在cin缓冲区导致死循环。
          std::cout << "\033[2J\033[1;1H";  // 清屏。
          switch (media_type)
            {
              case 1:
                std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                          << "Phone Number" << "\033[0m\n"; // 利用VT100控制码输出highlight的表头。
              sim_book_ptr->display (); // 调用sim_book的API，显示联系人。
              break;

              case 2:
                std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                          << "Phone Number" << std::left << std::setw (18) << "Origin" << std::left << std::setw (18)
                          << "QQ ID" << "\033[0m\n";
              phone_book_ptr->display ();
              break;
              case 3:
                std::cout << "\033[47;30m" << std::left << std::setw (18) << "Name" << std::left << std::setw (18)
                          << "Phone Number" << std::left << std::setw (18) << "Origin" << std::left << std::setw (18)
                          << "QQ ID" << "\033[0m\n";
              sim_book_ptr->display ();
              phone_book_ptr->display ();
              break;

              default:
                std::cout << "\033[41;37minvalid input\033[0m\n";
              continue;
            }
          break;
        }

    }

    void user::copy2sim ()
    {
      std::string name;
      bool flag = false;  // 用于判断是否成功。
      std::cout << "键入名字：";
      std::cin >> name;

      if (sim_book_ptr->search_name (name))
        {
          std::cout << "\033[41;37m已存在\033[0m\n" << std::endl;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
          return;
        }

      try // 可能存在姓名错误的问题，用try-catch语句捕获异常。
        {
          flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
        }
      catch (const char *msg)
        {
          std::cout << msg << std::endl;
        }

      if (!flag)
        std::cout << "[DEBUG] 错误" << std::endl;

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }
    void user::copy2phone ()
    {
      bool flag = false;  // 用于判断是否成功。
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (phone_book_ptr->search_name (name))
        {
          std::cout << "\033[41;37m已存在\033[0m\n" << std::endl;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
          return;
        }

      try // 可能存在姓名错误的问题，用try-catch语句捕获异常。
        {
          flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name), "", "");
        }
      catch (const char *msg)
        {
          std::cout << msg << std::endl;
        }

      if (!flag)
        std::cout << "[DEBUG] 错误" << std::endl;

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
    }
    void user::move2sim ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (sim_book_ptr->search_name (name))
        {
          std::cout << "\033[41;37m已存在\033[0m\n" << std::endl;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
          return;
        }

      try // 可能存在姓名错误的问题，用try-catch语句捕获异常。
        {
          flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
        }
      catch (const char *msg)
        {
          std::cout << msg << std::endl;
          flag = false;
        }
      if (flag) // 如果成功，再删除原来的联系人。
        phone_book_ptr->delete_item (phone_book_ptr->get_phone (name));
      else
        std::cout << "[DEBUG] 错误" << std::endl;

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
    }

    void user::move2phone ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (phone_book_ptr->search_name (name))
        {
          std::cout << "\033[41;37m已存在\033[0m\n" << std::endl;
          std::cin.clear ();
          std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。
          return;
        }

      try // 可能存在姓名错误的问题，用try-catch语句捕获异常。
        {
          flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name), "", "");
        }
      catch (const char *msg)
        {
          std::cout << msg << std::endl;
          flag = false;
        }

      if (flag) // 如果成功，再删除原来的联系人。
        sim_book_ptr->delete_item (sim_book_ptr->get_phone (name));
      else
        std::cout << "[DEBUG] 错误" << std::endl;

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空std::cin缓冲区（里面有一个换行符），防止对pause函数造成干扰。

    }

    void user::save ()
    {
      // 保存到文件。
      sim_book_ptr->save ();
      phone_book_ptr->save ();

      std::cin.clear ();
      std::cin.ignore (1024, '\n'); // 清空输入缓冲区
    }
} // user