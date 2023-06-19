/*
 * ui.hpp
 * Created by Jun ASAKA on 16/06/23.
 *
 * 用途：终端用户界面（TUI）。
 *
 * 注：使用了部分VT100控制码，可能不适用于所有终端；在Windows 10以下的Windows系统中运行可能会出现无法预料的问题。
 *
 */

#ifndef _UI_HPP_
#define _UI_HPP_

#include "public.hpp"
#include "user.hpp"

namespace ui
{

    class ui {

     public:

      /*
       * @brief 主菜单。
       * @details 显示菜单并处理输入输出。
       * @param user类指针。
       * @return true为退出主程式，false为继续。
       */
      bool display (user::user *user_ptr);

      /*
       * @brief 处理复制功能的二级菜单
       * @param user类指针。
       * @return 无。
       */
      void submenu_copy (user::user *user_ptr);

      /*
       * @brief 处理移动功能的二级菜单
       * @param user类指针。
       * @return 无。
       */
      void submenu_move (user::user *user_ptr);

      /*
       * @brief 暂停
       * @details 暂停程序，按下任意键后继续。
       * @param 无。
       * @return 无。
       * @note 为兼容Unix，故不使用system("pause")。
       */
      static void pause ();

    };

} // ui

#endif //_UI_HPP_
