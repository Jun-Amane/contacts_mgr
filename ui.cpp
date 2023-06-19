/*
 * ui.cpp
 * Created by Jun ASAKA on 16/06/23.
 *
 * 用途：终端用户界面（TUI）。
 *
 * 注：使用了部分VT100控制码，可能不适用于所有终端；在Windows 10以下的Windows系统中运行可能会出现无法预料的问题。
 *
 */

#include "ui.hpp"

namespace ui
{

    bool ui::display (user::user *user_ptr)
    {

      int function_number = -1; // 功能序号。

      std::cout << "\033[2J\033[1;1H"; // 使用VT100控制码清屏。

      std::cout << "\033[47;30mWelcome to use this phone book!\033[0m\n"  // 使用VT100控制码设置颜色为白底黑字，用于突出。
                << "\033[40;32m键入编号以选择操作对象：\033[0m\n"
                << "1. 添加联系人。" << std::endl
                << "2. 删除联系人（根据手机号）。" << std::endl
                << "3. 修改联系人（根据名字）。" << std::endl
                << "4. 查找联系人（根据名字）。" << std::endl
                << "5. 显示所有联系人。" << std::endl
                << "6. 复制联系人。" << std::endl
                << "7. 移动联系人。" << std::endl
                << "8. 保存。" << std::endl
                << "9. 保存并退出。" << std::endl;

      std::cout << "User$ ";  // 提示符。

      std::cin >> function_number;  // 输入功能序号。

      switch (function_number)
        {
          case 1:
            user_ptr->add_contact (); // 添加
          this->pause (); // 暂停
          break;
          case 2:
            user_ptr->delete_contact ();  // 删除
          this->pause ();
          break;
          case 3:
            user_ptr->modify_contact ();  // 修改
          this->pause ();
          break;
          case 4:
            user_ptr->search_contact ();  // 查找
          this->pause ();
          break;
          case 5:
            user_ptr->display_contact (); // 显示所有
          this->pause ();
          break;
          case 6:
            this->submenu_copy (user_ptr);  // 复制功能的二级菜单
          this->pause ();
          break;
          case 7:
            this->submenu_move (user_ptr);  // 移动功能的二级菜单
          this->pause ();
          break;
          case 8:
            user_ptr->save ();  // 保存
          this->pause ();
          break;

          case 9:
            user_ptr->save ();  // 保存
          return true;  // 退出
          default:
            std::cout << "\033[41;37minvalid input\033[0m\n"; // 无效输入
            std::cin.clear ();
            std::cin.ignore (1024, '\n'); // 清空输入缓冲区
            this->pause();
          break;
        }

      return false;

    }

    void ui::submenu_copy (user::user *user_ptr)
    {

      std::cout << "\033[2J\033[1;1H"; // 清屏

      int function_number = -1;

      std::cout << "\033[40;32m键入编号以选择操作对象：\033[0m\n"
                << "1. 复制到sim卡。" << std::endl
                << "2. 复制到手机。" << std::endl
                << "3. 返回。" << std::endl;

      std::cout << "User$ ";  // 提示符。

      std::cin >> function_number;  // 输入功能序号。

      switch (function_number)
        {
          case 1:
            user_ptr->copy2sim ();  // 复制到sim卡
          break;
          case 2:
            user_ptr->copy2phone ();  // 复制到手机
          break;
          case 3:
            break;  // 返回
          default:
            std::cout << "\033[41;37minvalid input\033[0m\n"; // 无效输入
          break;
        }

      return;

    }

    void ui::submenu_move (user::user *user_ptr)
    {

      std::cout << "\033[2J\033[1;1H"; // 清屏

      int function_number = -1;

      std::cout << "\033[40;32m键入编号以选择操作对象：\033[0m\n"
                << "1. 移动到sim卡。" << std::endl
                << "2. 移动到手机。" << std::endl
                << "3. 返回。" << std::endl;

      std::cout << "User$ ";  // 提示符。

      std::cin >> function_number;  // 输入功能序号。

      switch (function_number)
        {
          case 1:
            user_ptr->move2sim ();  // 移动到sim卡
          break;
          case 2:
            user_ptr->move2phone ();  // 移动到手机
          break;
          case 3:
            break;  // 返回
          default:
            std::cout << "\033[41;37minvalid input\033[0m\n";  // 无效输入
          break;
        }

      return;

    }

    void ui::pause ()
    {
      // 运行之前须清空输入缓冲区，否则会失效。
      std::cout << "\033[40;34mPress any key to continue...\033[0m"<< std::endl;
      std::cin.get ();  // 输入任意字符后继续
    }
} // ui