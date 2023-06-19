/*
 * sim_contact.cpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：sim卡通讯录条目。
 *
 */

#include "sim_contacts.hpp"

namespace sim_contacts
{
    sim_contacts::sim_contacts (std::string name, std::string phone_number)
    {
      this->name = name;  // 姓名
      this->phone_number = phone_number;  // 电话号码
    }

    void sim_contacts::set (std::string para_name, std::string para_phone_number)
    {

      this->name = para_name; // 直接赋值
      this->phone_number = para_phone_number;

      return;
    }

    std::istream &sim_contacts::read (std::istream &is)
    {
      // 从输入流中读取一行，用逗号分隔字段。
      std::getline (is, this->name, ',');
      std::getline (is, this->phone_number, '\n');

      return is;
    }
    std::ostream &sim_contacts::print (std::ostream &os) const
    {
      // 用逗号分隔字段，实现CSV格式输出。
      os << this->name << "," << this->phone_number;
      return os;
    }

    std::ostream &sim_contacts::readable_print (std::ostream &os) const
    {
      // 格式化输出，方便阅读。
      os << std::left << std::setw (18) << this->name << std::left << std::setw (18) << this->phone_number;
      return os;
    }

    std::string sim_contacts::get_name () const
    {
      return this->name;  // 直接返回对应字段。
    }

    std::string sim_contacts::get_phone_number () const
    {
      return this->phone_number;  // 直接返回对应字段。
    }

    std::ostream &operator<< (std::ostream &os, const sim_contacts &obj)
    {
      return obj.print (os);  // 动态地调用print方法。
    }

    std::istream &operator>> (std::istream &is, sim_contacts &obj)
    {
      return obj.read (is); // 动态地调用read方法。
    }

}