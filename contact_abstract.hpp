/*
 * contact_abstract.hpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：用于实现电话簿的抽象类头文件。
 *
 */

#ifndef _CONTACT_ABSTRACT_HPP_
#define _CONTACT_ABSTRACT_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"
#include "hash_table.hpp"
#include "file_mgr.hpp"

/*
 * @brief 电话簿抽象类。需要被子类继承并实现某些虚函数。
 */
class contact_abstract {

 protected:
  hash_table *name_table; // 以姓名为键的哈希表。子类中初始化。
  hash_table *phone_table;  // 以电话号码为键的哈希表。
  int size; // 记录当前电话簿中的联系人数目。

 public:

  /*
   * @brief 构造函数。
   * @details 初始化电话簿，哈希表指针置为nullptr。
   * @param 无。
   * @return 无。
   */
  contact_abstract ();

  /*
   * @brief 针对手机的插入函数
   * @param 姓名，电话号码，籍贯，QQ号码。
   * @return bool: 是否成功。
   */
  virtual bool insert_item (std::string name, std::string phone_number, std::string origin, std::string qq_id) = 0;

  /*
   * @brief 针对电话卡的插入函数
   * @param 姓名，电话号码。
   * @return bool: 是否成功。
   */
  virtual bool insert_item (std::string name, std::string phone_number) = 0;

  /*
   * @brief 删除联系人。
   * @details 按照电话从phone_table中查询姓名，并从两张哈希表中删除条目。
   * @param 电话号码。
   * @return 无。
   */
  void delete_item (const std::string &phone_number);

  /*
   * @brief 显示全部联系人
   * @details 调用哈希表中的display_all函数。
   * @param 无。
   * @return 无。
   */
  void display ();

  /*
   * @brief 针对手机的修改函数
   * @param 姓名，电话号码，籍贯，QQ号码。
   * @return 无。
   */
  virtual void modify_item (std::string name, std::string phone_number, std::string origin, std::string qq_id) = 0;

  /*
   * @brief 针对Sim卡的修改函数
   * @param 姓名，电话号码。
   * @return 无。
   */
  virtual void modify_item (std::string name, std::string phone_number) = 0;

  /*
   * @brief 查询函数（针对姓名）
   * @details 调用哈希表中的query_name函数，并格式化输出到stdout。
   * @param 姓名。
   * @return 是否找到。
   */
  bool query (const std::string &name);

  /*
   * @brief 通过姓名查询电话。
   * @details 从name_table中查询电话号码。
   * @param 姓名。
   * @return 电话。
   * @note 倘若不存在则抛出异常，调用处用try-catch接收。
   */
  std::string get_phone (const std::string &name) const;

  /*
   * @brief 查询电话是否存在。
   * @details 调用哈希表类中的search_phone函数。
   * @param 电话。
   * @return 是否存在。
   * @note 似乎没用。
   */
  bool search_phone (const std::string &key);

  /*
   * @brief 查询姓名是否存在。
   * @details 调用哈希表类中的search_name函数。
   * @param 姓名。
   * @return 是否存在。
   */
  bool search_name (const std::string &key);

  /*
   * @brief写入到文件
   * @details 调用file_mgr中的write_sim_book函数，将name_table中的所有条目写入到文件。
   * @param 文件路径
   * @return 无。
   * @note 基于运算符重载实现，两种子类通用。
   */
  void write_to_file (const std::string &file_name);

  /*
   * @brief 保存
   * @details 对write_to_file的封装，根据不同子类，将数据写入到不同的文件。
   * @param 无。
   * @return 无。
   */
  virtual void save () = 0;

};

#endif //_CONTACT_ABSTRACT_HPP_
