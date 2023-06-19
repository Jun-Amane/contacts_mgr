/*
 * phone_contact.hpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：手机通讯录条目。
 *
 */

#ifndef _PHONE_CONTACT_HPP_
#define _PHONE_CONTACT_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"

namespace phone_contact
{

    /*
     * @brief 手机中的联系人条目。继承自sim_contacts（手机卡联系人条目），相对于其多了籍贯和QQ两个字段。
     */
    class phone_contact : public sim_contacts::sim_contacts {

     protected:
      std::string origin; // 籍贯
      std::string qq_id;  // QQ号码

     public:

//      // 用于标识联系人字段的枚举类型，实际上没用到。
//      enum fields {
//          field_name,
//          field_phone_number,
//          field_origin,
//          field_qq_id
//      };

      /*
       * @brief 构造函数。
       * @details 默认值为空字符串。
       * @param 姓名、电话号码、籍贯、QQ号码。
       * @return 无。
       */
      phone_contact (std::string name = "", std::string phone_number = "", std::string origin = "", std::string qq_id = "")
          : sim_contacts::sim_contacts (name, phone_number), origin (origin), qq_id (qq_id)
      {};

      /*
       * @brief 获取某字段
       * @details 用于获取protected状态的字段。
       * @param 无。
       * @return 字段字符串。
       * @note 实际上没用到。
       */
      std::string get_origin () const;
      std::string get_qq_id () const;

      /*
       * @brief 完全赋值函数
       * @details 根据参数直接为成员字段赋值。
       * @param 姓名、电话号码、籍贯、QQ号码。
       * @return 无。
       * @note 实际上没用到，用到的是哈希表类中的修改函数。
       */
      void set (std::string para_name, std::string para_phone_number, std::string para_origin, std::string para_qq_id);

      /*
       * @brief 输入输出函数
       * @details 重载的输入输出流函数，用于从文件中读取和写入，按照CSV格式。
       * @param I/O流。
       * @return I/O流。
       * @note 输入输出运算符的重载为此二者的封装。
       */
      std::istream &read (std::istream &is) override;
      std::ostream &print (std::ostream &os) const override;

      /*
       * @brief 格式化输出函数
       * @details 输出时格式化，方便阅读。
       * @param 输出流。
       * @return 输出流。
       */
      std::ostream &readable_print (std::ostream &os) const override;

    };

} // phone_contact

#endif //_PHONE_CONTACT_HPP_
