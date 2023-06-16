//
// Created by Jun ASAKA on 2023/6/16.
//

#include "ui.hpp"

namespace ui
{
    bool ui::display (user::user* user_ptr)
    {

      int function_number = -1;

      // TODO: 终端清屏。
      std::cout << "Welcome to use this phone book!" << std::endl;
      std::cout << "Please choose the function you want to use:" << std::endl
                << "1. 添加联系人。" << std::endl
                << "2. 删除联系人（根据手机号）。" << std::endl
                << "3. 修改联系人（根据名字）。" << std::endl
                << "4. 查找联系人（根据名字）。" << std::endl
                << "5. 显示所有联系人。" << std::endl
                << "6. 复制联系人。" << std::endl
                << "7. 移动联系人。" << std::endl
                << "8. 保存。" << std::endl
                << "0. 保存并退出。" << std::endl;

      std::cout << "User$";

      std::cin >> function_number;

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

            case 0:
              return true;
          default:
            std::cout << "invalid input\n";
            break;
        }

        return false;

    }
    void ui::submenu_copy (user::user* user_ptr)
    {
      // TODO: 终端清屏。

      int function_number = -1;

      std::cout << "Please choose the function you want to use:" << std::endl
                    << "1. 复制到sim卡。" << std::endl
                    << "2. 复制到手机。" << std::endl
                    << "0. 返回。" << std::endl;

      std::cout << "User$";

      std::cin >> function_number;
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

      // TODO: 终端清屏。

      int function_number = -1;

      std::cout << "Please choose the function you want to use:" << std::endl
                << "1. 复制到sim卡。" << std::endl
                << "2. 复制到手机。" << std::endl
                << "0. 返回。" << std::endl;

      std::cout << "User$";

      std::cin >> function_number;
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
        std::cout << "Press any key to continue...";
        std::cin.get();
    }
} // ui