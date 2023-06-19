/*
 * sim_contact.hpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：sim卡通讯录条目。
 *
 */

#ifndef _SIM_CONTACTS_HPP_
#define _SIM_CONTACTS_HPP_

#include "public.hpp"

namespace sim_contacts
{

    /*
     * @brief sim卡中的联系人条目。
     */
    class sim_contacts {

     protected:
      std::string name; // 姓名
      std::string phone_number; // 电话号码

     public:

      /*
       * @brief 构造函数。
       * @details 默认值为空字符串。
       * @param 姓名、电话号码。
       * @return 无。
       */
      sim_contacts (std::string name = "", std::string phone_number = "");

      /*
       * @brief 获取某字段
       * @details 用于获取protected状态的字段。
       * @param 无。
       * @return 字段字符串。
       */
      std::string get_name () const;
      std::string get_phone_number () const;

      /*
       * @brief 完全赋值函数
       * @details 根据参数直接为成员字段赋值。
       * @param 姓名、电话号码。
       * @return 无。
       * @note 实际上没用到，用到的是哈希表类中的修改函数。
       */
      void set (std::string para_name, std::string para_phone_number);

      /*
       * @brief 输入输出函数
       * @details 重载的输入输出流函数，用于从文件中读取和写入，按照CSV格式。
       * @param I/O流。
       * @return I/O流。
       * @note 输入输出运算符的重载为此二者的封装。
       */
      virtual std::istream &read (std::istream &is);
      virtual std::ostream &print (std::ostream &os) const;

      /*
       * @brief 格式化输出函数
       * @details 输出时格式化，方便阅读。
       * @param 输出流。
       * @return 输出流。
       */
      virtual std::ostream &readable_print (std::ostream &os) const;

      /*
       * @brief 输入输出运算符的重载
       * @details 将read、print函数封装。
       * @param I/O流，对象。
       * @return I/O流。
       */
      friend std::ostream &operator<< (std::ostream &os, const sim_contacts &obj);
      friend std::istream &operator>> (std::istream &is, sim_contacts &obj);

    };
}
#endif //_SIM_CONTACTS_HPP_
