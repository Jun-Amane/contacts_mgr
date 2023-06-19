/*
 * user.hpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：用户类。
 *
 */

#ifndef _USER_HPP_
#define _USER_HPP_

#include "public.hpp"
#include "phone_book.hpp"
#include "sim_book.hpp"

namespace user
{

    /*
     * @brief 用户类。
     * @details 用于封装两个通讯录和与之相关的API，提供完整的命令行界面。
     */
    class user {

     protected:

      phone_book::phone_book *phone_book_ptr; // 手机通讯录
      sim_book::sim_book *sim_book_ptr; // sim卡通讯录

     public:

      /*
       * @brief 构造函数。
       * @details 初始化两个通讯录。
       * @param 无。
       * @return 无。
       */
      user ();

      /*
       * @brief 析构函数。
       * @details 释放两个通讯录。
       * @param 无。
       * @return 无。
       */
      ~user ();

      // 标记通讯录类型的枚举类，实际上没用到。
      enum media {
          sim,
          phone
      };

      /*
       * @brief 增、删、改、查、显示的函数
       * @details 调用电话簿的API，提供命令行界面。
       * @param 无。
       * @return 无。
       */
      void add_contact ();  // 增
      void delete_contact (); // 删，根据手机号。
      void modify_contact (); // 改，根据名字。若重复，则仅修改表内第一个。
      void search_contact (); // 查，根据名字。
      void display_contact ();  // 显示所有

      /*
       * @brief 复制、移动的函数
       * @details 调用电话簿的API，提供命令行界面。
       * @param 无。
       * @return 无。
       */
      void copy2sim ();    // 复制到sim卡，根据名字，重名则复制表内第一个。
      void copy2phone (); // 复制到手机。
      void move2sim (); // 移动到sim卡。
      void move2phone (); // 移动到手机。

      /*
       * @brief 保存函数。
       * @details 调用两个电话簿API的save函数。
       * @param 无。
       * @return 无。
       */
      void save ();

    };

} // user

#endif //_USER_HPP_
