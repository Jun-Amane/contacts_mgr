/*
 * phone_book.hpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：储存于sim卡的电话簿类，用于管理、控制sim_contacts类。
 *
 */

#ifndef _SIM_BOOK_HPP_
#define _SIM_BOOK_HPP_

#include "public.hpp"
#include "contact_abstract.hpp"
#include "hash_table.hpp"
#include "sim_contacts.hpp"
#include "file_mgr.hpp"

namespace sim_book
{

    /*
     * @brief 储存于sim卡中的电话簿类。继承自contact_abstract。
     */
    class sim_book : public contact_abstract {

     public:

      /*
       * @brief 构造函数。
       * @details 读取文件中的联系人信息（file_mgr中的读取函数自会分配内存）。
       * @param 无。
       * @return 无。
       */
      sim_book ();

      /*
       * @brief 析构函数。
       * @details 将联系人信息写入文件并释放内存。
       * @param 无。
       * @return 无。
       */
      ~sim_book ();

      /*
       * @brief 针对sim卡的插入函数
       * @details 将联系人信息插入两张哈希表中。
       * @param 姓名，电话号码。
       * @return bool: 是否成功。
       */
      bool insert_item (std::string name, std::string phone_number) override;
      // 手机用，此处不实现具体功能。
      bool insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id) override;

      /*
       * @brief 针对sim卡的修改函数。
       * @details 调用哈希表的修改函数。
       * @param 姓名，电话号码，籍贯，QQ号码。
       * @return 无。
       */
      void modify_item (std::string name, std::string phone_number) override;
        // 手机用，此处不实现具体功能。
      void modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id) override;

      /*
       * @brief 保存
       * @details 调用file_mgr中的保存函数，写入SIM_BOOK_FILE（一个文件名的宏）。
       * @param 无。
       * @return 无。
       */
      void save () override;
    };

} // sim_book

#endif //_SIM_BOOK_HPP_
