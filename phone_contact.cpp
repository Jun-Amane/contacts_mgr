/*
 * phone_contact.cpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：手机通讯录条目。
 *
 */

#include "phone_contact.hpp"

namespace phone_contact
{

    void
    phone_contact::set (std::string para_name, std::string para_phone_number, std::string para_origin, std::string para_qq_id)
    {
      this->name = para_name; // 直接赋值
      this->phone_number = para_phone_number;
      this->origin = para_origin;
      this->qq_id = para_qq_id;
    }

    std::istream &phone_contact::read (std::istream &is)
    {
      // 从输入流中读取一行，用逗号分隔字段。
      std::getline (is, this->name, ',');
      std::getline (is, this->phone_number, ',');
      std::getline (is, this->origin, ',');
      std::getline (is, this->qq_id, '\n');
      return is;
    }

    std::ostream &phone_contact::print (std::ostream &os) const
    {
      // 用逗号分隔字段，实现CSV格式输出。
      os << this->name << "," << this->phone_number << "," << this->origin << "," << this->qq_id;
      return os;
    }

    std::ostream &phone_contact::readable_print (std::ostream &os) const
    {
      // 格式化输出。
      os << std::left << std::setw (18) << this->name << std::left << std::setw (18) << this->phone_number << std::left
         << std::setw (18) << this->origin << std::left << std::setw (18) << this->qq_id;
      return os;
    }

    std::string phone_contact::get_origin () const
    {
      return this->origin;  // 直接返回对应字段。
    }
    std::string phone_contact::get_qq_id () const
    {
      return this->qq_id; // 直接返回对应字段。
    }

} // phone_contact