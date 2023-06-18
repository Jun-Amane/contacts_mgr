//
// Created by Jun ASAKA on 2023/6/16.
//

#ifndef _UI_H_
#define _UI_H_

#include "public.hpp"
#include "user.hpp"

namespace ui
{

    class ui {

     public:

      bool display (user::user *user_ptr); // 返回值：true为退出主程式，false为继续。
      void submenu_copy (user::user *user_ptr);
      void submenu_move (user::user *user_ptr);

      void pause ();

    };

} // ui

#endif //_UI_H_
