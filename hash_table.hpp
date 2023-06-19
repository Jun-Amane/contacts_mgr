/*
 * hash_table.hpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：哈希表类。
 *
 */

#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"
#include <vector> // 为了方便遍历哈希表，定义API函数将其转换为std::vector。

const int TABLE_SIZE = 100; // 哈希表大小

/*
 * @brief 链表节点类，为解决哈希冲突而使用链表。
 */
class Node {
 public:
  const sim_contacts::sim_contacts *data; // 数据
  Node *next; // 指向下一个节点的指针

  /*
   * @brief 构造函数。
   * @details 创建节点，将数据存入节点，next指针默认为nullptr。
   * @param 数据
   * @return 无。
   */
  Node (const sim_contacts::sim_contacts *value) : data (value), next (nullptr)
  {}
};

/*
 * @brief 哈希表类。
 * @details 使用标准库中的std::hash函数，计算std::string的哈希值并缩放到合适范围内。
 */
class hash_table {
 private:
  Node **table; // 本质上是*Node的数组的指针。

  /*
   * @brief 哈希函数。
   * @details 使用标准库中的std::hash函数，计算std::string的哈希值并缩放到合适范围内。
   * @param 键
   * @return 哈希值
   */
  static int hashFunction (const std::string &key);

 public:

  /*
   * @brief 构造函数。
   * @details 创建哈希表，将所有指针初始化为nullptr。
   * @param 无。
   * @return 无。
   */
  hash_table ();

  /*
   * @brief 析构函数。
   * @details 释放哈希表中所有节点的内存。
   * @param 无。
   * @return 无。
   */
  ~hash_table ();

  /*
   * @brief 插入函数。
   * @details 将数据插入哈希表中，插入到对应链表末尾。
   * @param 数据对象，键
   * @return 无。
   */
  void insert (const sim_contacts::sim_contacts *item, const std::string &key);


  /*
   * @brief 查找电话
   * @details 给定电话为键进行查找
   * @param 键
   * @return 是否存在
   */
  bool search_phone (const std::string &key); // if exist

  /*
   * @brief 查找姓名
   * @details 给定姓名为键进行查找
   * @param 键
   * @return 是否存在
   */
  bool search_name (const std::string &key); // if exist

  /*
   * @brief 默认删除函数（根据电话）。
   * @details 给定电话为键，删除对应节点。
   * @param 键
   * @return 无。
   */
  void remove (const std::string &key);

  /*
   * @brief 删除函数（根据姓名）。
   * @details 给定姓名为键，删除对应节点。
   * @param 键
   * @return 无。
   */
  void remove_by_name (const std::string &key);

  /*
   * @brief 根据姓名找到对应对象。
   * @details 给定姓名为键，返回对应节点地址。
   * @param 键
   * @return 节点指针
   */
  const sim_contacts::sim_contacts *query_name (const std::string &key);

  /*
   * @brief 根据姓名查找电话（用于以姓名为键的哈希表对象中）
   * @details 给定姓名为键，返回电话
   * @param 键
   * @return 电话字符串
   */
  std::string get_name_by_phone (const std::string &key);

  /*
   * @brief 格式化输出所有联系人信息。
   * @param 无。
   * @return 无。
   */
  void display_all ();

  /*
   * @brief 修改函数。
   * @details 给定姓名为键，修改对应节点。
   * @param 数据对象，键
   * @return 无。
   * @note 倘若存在重名，仅会修改表中第一个元素。
   */
  void modify (const sim_contacts::sim_contacts *item, const std::string &key);

  /*
   * @brief 转换为std::vector。
   * @details 将哈希表中转换为std::vector，便于使用迭代器遍历。
   * @param 无。
   * @return std::vector<const sim_contacts::sim_contacts *>。
   */
  std::vector<const sim_contacts::sim_contacts *> to_vector () const;
};

#endif //_HASH_TABLE_HPP_
