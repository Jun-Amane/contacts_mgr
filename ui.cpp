//
// Created by Jun ASAKA on 2023/6/16.
//

#include "ui.hpp"

namespace ui
{
    struct termios origAttr;

    bool ui::display (user::user* user_ptr)
    {

      int function_number = 1;

      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr(fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      std::cout << "Welcome to use this phone book!" << std::endl;
      std::cout << "使用方向键选择:" << std::endl
                << ((function_number == 1) ? "\033[41;36m1. 添加联系人。\033[0m\n" : "1. 添加联系人。\n")
                << ((function_number == 2) ? "\033[41;36m2. 删除联系人（根据手机号）。\033[0m\n" : "2. 删除联系人（根据手机号）。\n")
                << ((function_number == 3) ? "\033[41;36m3. 修改联系人（根据名字）。\033[0m\n" : "3. 修改联系人（根据名字）。\n")
                << ((function_number == 4) ? "\033[41;36m4. 查找联系人（根据名字）。\033[0m\n" : "4. 查找联系人（根据名字）。\n")
                << ((function_number == 5) ? "\033[41;36m5. 显示所有联系人。\033[0m\n" : "5. 显示所有联系人。\n")
                << ((function_number == 6) ? "\033[41;36m6. 复制联系人。\033[0m\n" : "6. 复制联系人。\n")
                << ((function_number == 7) ? "\033[41;36m7. 移动联系人。\033[0m\n" : "7. 移动联系人。\n")
                << ((function_number == 8) ? "\033[41;36m8. 保存。\033[0m\n" : "8. 保存。\n")
                << ((function_number == 9) ? "\033[41;36m0. 保存并退出。\033[0m\n" : "0. 保存并退出。\n");



        // 读取字符
        char ch;
        while (std::cin.get(ch)) {
            // 检查读取的字符是否为方向键
            if (ch == '\033') {  // 方向键序列的起始字符是 '\033'
                std::cin.get(ch); // 读取方向键的第二个字符

                if (ch == '[') {
                    std::cin.get(ch); // 读取方向键的最后一个字符

                    // 根据最后一个字符判断方向
                    switch (ch) {
                        case 'A':
                          if(function_number > 1)
                            function_number--;
                        break;
                        case 'B':
                            if(function_number < 9)
                                function_number++;
                        break;
                        default:
                          break;
                      }
                    std::cout << "\033[H\033[2J\033[3J";
                    std::cout << "Welcome to use this phone book!" << std::endl;
                    std::cout << "使用方向键选择:" << std::endl
                              << ((function_number == 1) ? "\033[41;36m1. 添加联系人。\033[0m\n" : "1. 添加联系人。\n")
                              << ((function_number == 2) ? "\033[41;36m2. 删除联系人（根据手机号）。\033[0m\n" : "2. 删除联系人（根据手机号）。\n")
                              << ((function_number == 3) ? "\033[41;36m3. 修改联系人（根据名字）。\033[0m\n" : "3. 修改联系人（根据名字）。\n")
                              << ((function_number == 4) ? "\033[41;36m4. 查找联系人（根据名字）。\033[0m\n" : "4. 查找联系人（根据名字）。\n")
                              << ((function_number == 5) ? "\033[41;36m5. 显示所有联系人。\033[0m\n" : "5. 显示所有联系人。\n")
                              << ((function_number == 6) ? "\033[41;36m6. 复制联系人。\033[0m\n" : "6. 复制联系人。\n")
                              << ((function_number == 7) ? "\033[41;36m7. 移动联系人。\033[0m\n" : "7. 移动联系人。\n")
                              << ((function_number == 8) ? "\033[41;36m8. 保存。\033[0m\n" : "8. 保存。\n")
                              << ((function_number == 9) ? "\033[41;36m0. 保存并退出。\033[0m\n" : "0. 保存并退出。\n");

                  }
              }

            // 检查是否遇到换行字符，退出循环
            if (ch == '\n') {
                break;
              }
          }

        // 恢复终端原始属性
        tcsetattr(fd, TCSANOW, &origAttr);




//      std::cin >> function_number;


      switch (function_number)
        {
            case 1: user_ptr->add_contact(); break;
            case 2: user_ptr->delete_contact(); break;
            case 3: user_ptr->modify_contact(); break;
            case 4: user_ptr->search_contact(); this->pause(); break;
            case 5: user_ptr->display_contact(); this->pause(); break;
            case 6: this->submenu_copy (user_ptr); break;
            case 7: this->submenu_move (user_ptr); break;
            case 8: user_ptr->save(); break;

            case 9:
              user_ptr->save();
              return true;
          default:
            std::cout << "invalid input\n";
            break;
        }

        return false;

    }

    void ui::submenu_copy (user::user* user_ptr)
    {
      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr(fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      int function_number = 1;

      std::cout << "使用方向键选择:" << std::endl
                << ((function_number == 1) ? "\033[41;36m1. 复制到sim卡。\033[0m\n" : "1. 复制到sim卡。\n")
                << ((function_number == 2) ? "\033[41;36m2. 复制到手机。\033[0m\n" : "2. 复制到手机。\n")
                << ((function_number == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get(ch)) {
          // 检查读取的字符是否为方向键
          if (ch == '\033') {  // 方向键序列的起始字符是 '\033'
              std::cin.get(ch); // 读取方向键的第二个字符

              if (ch == '[') {
                  std::cin.get(ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch) {
                      case 'A':
                        if(function_number > 1)
                          function_number--;
                      break;
                      case 'B':
                        if(function_number < 3)
                          function_number++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((function_number == 1) ? "\033[41;36m1. 复制到sim卡。\033[0m\n" : "1. 复制到sim卡。\n")
                            << ((function_number == 2) ? "\033[41;36m2. 复制到手机。\033[0m\n" : "2. 复制到手机。\n")
                            << ((function_number == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n') {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr(fd, TCSANOW, &origAttr);

      switch (function_number)
        {
            case 1: user_ptr->copy2sim(); break;
            case 2: user_ptr->copy2phone(); break;
                case 0: break;
            default:
                std::cout << "invalid input\n";
                break;
        }

        return;

    }

    void ui::submenu_move (user::user* user_ptr)
    {

      // 获取终端的文件描述符
      int fd = STDIN_FILENO;

      // 保存终端原始属性
      tcgetattr(fd, &origAttr);

      // 修改终端属性，禁用标准输入的行缓冲和回显
      struct termios newAttr = origAttr;
      newAttr.c_lflag &= ~(ICANON | ECHO);
      tcsetattr(fd, TCSANOW, &newAttr);

      std::cout << "\033[2J\033[1;1H"; // 清屏

      int function_number = 1;

      std::cout << "使用方向键选择:" << std::endl
                << ((function_number == 1) ? "\033[41;36m1. 移动到sim卡。\033[0m\n" : "1. 移动到sim卡。\n")
                << ((function_number == 2) ? "\033[41;36m2. 移动到手机。\033[0m\n" : "2. 移动到手机。\n")
                << ((function_number == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

      // 读取字符
      char ch;
      while (std::cin.get(ch)) {
          // 检查读取的字符是否为方向键
          if (ch == '\033') {  // 方向键序列的起始字符是 '\033'
              std::cin.get(ch); // 读取方向键的第二个字符

              if (ch == '[') {
                  std::cin.get(ch); // 读取方向键的最后一个字符

                  // 根据最后一个字符判断方向
                  switch (ch) {
                      case 'A':
                        if(function_number > 1)
                          function_number--;
                      break;
                      case 'B':
                        if(function_number < 3)
                          function_number++;
                      break;
                      default:
                        break;
                    }
                  std::cout << "\033[H\033[2J\033[3J";
                  std::cout << "使用方向键选择:" << std::endl
                            << ((function_number == 1) ? "\033[41;36m1. 移动到sim卡。\033[0m\n" : "1. 移动到sim卡。\n")
                            << ((function_number == 2) ? "\033[41;36m2. 移动到手机。\033[0m\n" : "2. 移动到手机。\n")
                            << ((function_number == 3) ? "\033[41;36m3. 返回。\033[0m\n" : "3. 返回。\n");

                }
            }

          // 检查是否遇到换行字符，退出循环
          if (ch == '\n') {
              break;
            }
        }

      // 恢复终端原始属性
      tcsetattr(fd, TCSANOW, &origAttr);

      switch (function_number)
        {
          case 1: user_ptr->move2sim(); break;
          case 2: user_ptr->move2phone(); break;
          case 0: break;
          default:
            std::cout << "invalid input\n";
          break;
        }

      return;

    }

    void ui::pause ()
    {
      std::cout << "Press any key to continue..." << std::endl;
      std::cin.get();
    }
} // ui