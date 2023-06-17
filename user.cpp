//
// Created by Jun ASAKA on 2023/6/9.
//

#include "user.hpp"

namespace user
{
    struct termios origAttr;

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

      int media_type = 1;

      std::string name, phone_number, origin, qq_id;
      bool flag = false;

      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr (fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr (fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏
      std::cout << "使用方向键选择:" << std::endl
                << ((media_type == 1) ? "\033[41;36m1. 添加到sim卡。\033[0m\n" : "1. 添加到sim卡。\n")
                << ((media_type == 2) ? "\033[41;36m2. 添加到手机。\033[0m\n" : "2. 添加到手机。\n")
                << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get (ch))
        {
          // 检查读取的字符是否为方向键
          if (ch == '\033')
            {  // 方向键序列的起始字符是 '\033'
              std::cin.get (ch); // 读取方向键的第二个字符

              if (ch == '[')
                {
                  std::cin.get (ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch)
                    {
                      case 'A':
                        if (media_type > 1)
                          media_type--;
                      break;
                      case 'B':
                        if (media_type < 3)
                          media_type++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((media_type == 1) ? "\033[41;36m1. 添加到sim卡。\033[0m\n" : "1. 添加到sim卡。\n")
                            << ((media_type == 2) ? "\033[41;36m2. 添加到手机。\033[0m\n" : "2. 添加到手机。\n")
                            << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n')
            {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr (fd, TCSANOW, &origAttr);

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

          case 3:
            std::cin.sync();
            std::cin.ignore (1024, '\n');
            return;

          default:
            std::cout << "invalid input\n";
          break;
        }

      if (!flag)
        std::cout << "错误" << std::endl;

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }

    void user::delete_contact ()
    {
      std::string phone_number;
      std::cout << "input number: ";
      std::cin >> phone_number;

      phone_book_ptr->delete_item (phone_number);
      sim_book_ptr->delete_item (phone_number);

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }
    void user::modify_contact ()
    {
      int media_type = 1;

      std::string name, phone_number, origin, qq_id;


      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr (fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr (fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      std::cout << "使用方向键选择:" << std::endl
                << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get (ch))
        {
          // 检查读取的字符是否为方向键
          if (ch == '\033')
            {  // 方向键序列的起始字符是 '\033'
              std::cin.get (ch); // 读取方向键的第二个字符

              if (ch == '[')
                {
                  std::cin.get (ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch)
                    {
                      case 'A':
                        if (media_type > 1)
                          media_type--;
                      break;
                      case 'B':
                        if (media_type < 3)
                          media_type++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                            << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                            << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n')
            {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr (fd, TCSANOW, &origAttr);

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

          case 3:
            return;

          default:
            std::cout << "invalid input\n";
          break;
        }

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }
    void user::search_contact ()
    {

      int media_type = 0;

      std::string name;

      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr (fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr (fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      std::cout << "使用方向键选择:" << std::endl
                << ((media_type == 0) ? "\033[41;36m0. 于两者。\033[0m\n" : "0. 于两者。\n")
                << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get (ch))
        {
          // 检查读取的字符是否为方向键
          if (ch == '\033')
            {  // 方向键序列的起始字符是 '\033'
              std::cin.get (ch); // 读取方向键的第二个字符

              if (ch == '[')
                {
                  std::cin.get (ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch)
                    {
                      case 'A':
                        if (media_type > 0)
                          media_type--;
                      break;
                      case 'B':
                        if (media_type < 3)
                          media_type++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((media_type == 0) ? "\033[41;36m0. 于两者。\033[0m\n" : "0. 于两者。\n")
                            << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                            << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                            << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n')
            {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr (fd, TCSANOW, &origAttr);

      switch (media_type)
        {
          case 0:
            std::cout << "input name: ";
          std::cin >> name;
          std::cout << "\033[2J\033[1;1H"; // 清屏
          std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << std::left << std::setw(18) << "Origin" << std::left << std::setw(18) << "QQ ID" << "\033[0m\n";
          sim_book_ptr->query (name);
          phone_book_ptr->query (name);
          break;

          case 1:
            std::cout << "input name: ";
          std::cin >> name;
          std::cout << "\033[2J\033[1;1H"; // 清屏
          std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << "\033[0m\n";
          sim_book_ptr->query (name);
          break;

          case 2:

            std::cout << "input name: ";
          std::cin >> name;
          std::cout << "\033[2J\033[1;1H"; // 清屏
          std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << std::left << std::setw(18) << "Origin" << std::left << std::setw(18) << "QQ ID" << "\033[0m\n";
          phone_book_ptr->query (name);
          break;

          case 3:
            return;

          default:
            std::cout << "invalid input\n";
          break;
        }
      std::cin.sync();
      std::cin.ignore (1024, '\n');
    }
    void user::display_contact ()
    {

      int media_type = 0;


      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr (fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr (fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      std::cout << "使用方向键选择:" << std::endl
                << ((media_type == 0) ? "\033[41;36m0. 所有。\033[0m\n" : "0. 所有。\n")
                << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get (ch))
        {
          // 检查读取的字符是否为方向键
          if (ch == '\033')
            {  // 方向键序列的起始字符是 '\033'
              std::cin.get (ch); // 读取方向键的第二个字符

              if (ch == '[')
                {
                  std::cin.get (ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch)
                    {
                      case 'A':
                        if (media_type > 0)
                          media_type--;
                      break;
                      case 'B':
                        if (media_type < 3)
                          media_type++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((media_type == 0) ? "\033[41;36m0. 所有。\033[0m\n" : "0. 所有。\n")
                            << ((media_type == 1) ? "\033[41;36m1. 于sim卡。\033[0m\n" : "1. 于sim卡。\n")
                            << ((media_type == 2) ? "\033[41;36m2. 于手机。\033[0m\n" : "2. 于手机。\n")
                            << ((media_type == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n')
            {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr (fd, TCSANOW, &origAttr);

      switch (media_type)
        {
          case 0:
            std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << std::left << std::setw(18) << "Origin" << std::left << std::setw(18) << "QQ ID" << "\033[0m\n";
            sim_book_ptr->display ();
          phone_book_ptr->display ();
          break;

          case 1:
            std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << "\033[0m\n";
            sim_book_ptr->display ();
          break;

          case 2:
            std::cout << "\033[47;30m" << std::left << std::setw(18) << "Name" << std::left << std::setw(18) << "Phone Number" << std::left << std::setw(18) << "Origin" << std::left << std::setw(18) << "QQ ID" << "\033[0m\n";
            phone_book_ptr->display ();
          break;

          case 3:
            return;

          default:
            std::cout << "invalid input\n";

          break;
        }

    }

    void user::copy2sim ()
    {
      std::string name;
      bool flag = false;
      std::cout << "键入名字：";
      std::cin >> name;

      if (sim_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
      if (!flag)
        std::cout << "错误" << std::endl;

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }
    void user::copy2phone ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (phone_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name), "", "");
      if (!flag)
        std::cout << "错误" << std::endl;

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }
    void user::move2sim ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (sim_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = sim_book_ptr->insert_item (name, phone_book_ptr->get_phone (name));
      if (flag)
        phone_book_ptr->delete_item (phone_book_ptr->get_phone (name));
      else
        std::cout << "错误" << std::endl;

      std::cin.sync();
      std::cin.ignore (1024, '\n');
    }
    void user::move2phone ()
    {
      bool flag = false;
      std::string name;
      std::cout << "键入名字：";
      std::cin >> name;

      if (phone_book_ptr->search_name (name))
        {
          std::cout << "已存在" << std::endl;
          return;
        }

      flag = phone_book_ptr->insert_item (name, sim_book_ptr->get_phone (name));
      if (flag)
        sim_book_ptr->delete_item (sim_book_ptr->get_phone (name));
      else
        std::cout << "错误" << std::endl;

      std::cin.sync();
      std::cin.ignore (1024, '\n');

    }
    void user::save ()
    {
      sim_book_ptr->save ();
      phone_book_ptr->save ();
    }
} // user