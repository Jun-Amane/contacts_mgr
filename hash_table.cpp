/*
 * hash_table.cpp
 * Created by Jun ASAKA on 08/06/23.
 *
 * 用途：哈希表类。
 *
 */

#include "hash_table.hpp"

int hash_table::hashFunction (const std::string &key)
{

  std::hash<std::string> hasher;  // std::hash是标准库中的哈希对象。
  std::size_t hashValue = hasher (key); // 计算哈希值。
  return hashValue % TABLE_SIZE;  // 缩放到合适范围内。

}

hash_table::hash_table ()
{
  table = new Node *[TABLE_SIZE]; // 分配内存
  for (int i = 0; i < TABLE_SIZE; i++)
    {
      table[i] = nullptr; // 将所有指针初始化为nullptr
    }

}

hash_table::~hash_table ()
{
  for (int i = 0; i < TABLE_SIZE; i++)
    {
      Node *current = table[i]; // 遍历链表每个节点
      while (current != nullptr)
        {
          Node *next = current->next; // 保存下一个节点的指针
          delete current; // 删除当前节点
          current = next;
        }
    }
  delete[] table; // 释放内存
}

void hash_table::insert (const sim_contacts::sim_contacts *item, const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *newNode = new Node (item);  // 创建新节点

  if (table[index] == nullptr)  // 判断是否产生哈希冲突（该位置是否为空）
    {
      table[index] = newNode;
    }
  else
    { // 产生哈希冲突，则添加到链表结尾
      Node *current = table[index];
      while (current->next != nullptr)
        {
          current = current->next;
        }
      current->next = newNode;
    }

}

bool hash_table::search_phone (const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_phone_number () == key)
        {
          return true; // 找到了
        }
      current = current->next;
    }
  return false; // 未找到

}

bool hash_table::search_name (const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_name () == key)
        return true;
      current = current->next;
    }

  return false;
}

void hash_table::remove (const std::string &key) // 根据电话号码删除
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置
  Node *previous = nullptr; // 用于保存前一个节点的指针（初始化为nullptr）

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_phone_number () == key)
        {
          if (previous == nullptr)  // 如果是第一个节点
            {
              table[index] = current->next;
            }
          else
            {
              previous->next = current->next;
            }
          delete current; // 释放内存
          return;
        }
      previous = current;
      current = current->next;
    }

}

void hash_table::remove_by_name (const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置
  Node *previous = nullptr; // 用于保存前一个节点的指针（初始化为nullptr）

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_name () == key)
        {
          if (previous == nullptr)  // 如果是第一个节点
            {
              table[index] = current->next;
            }
          else
            {
              previous->next = current->next;
            }
          delete current; // 释放内存
          return;
        }
      previous = current;
      current = current->next;
    }

}

const sim_contacts::sim_contacts *hash_table::query_name (const std::string &key) // 根据姓名找到对象。
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_name () == key)
        return current->data; // 找到了，返回对象指针。
      current = current->next;
    }
  return nullptr; // 未找到，返回nullptr。
}

std::string hash_table::get_name_by_phone (const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_phone_number () == key)
        {
          return current->data->get_name ();  // 找到了，返回姓名。
        }
      current = current->next;
    }

  throw "hash_table::get_name_by_phone: No such phone number.";  // 抛出异常；实际上并没有什么作用，因为调用前会保证号码一定存在。
}

void hash_table::display_all ()
{
  for (int i = 0; i < TABLE_SIZE; i++)  // 遍历哈希表
    {
      Node *current = table[i];
      while (current != nullptr)
        {
          current->data->readable_print (std::cout);  // 调用格式化输出API（格式不同于输出运算符的重载）。
          std::cout << std::endl; // 换行
          current = current->next;
        }
    }

}

void hash_table::modify (const sim_contacts::sim_contacts *item, const std::string &key)
{
  int index = hashFunction (key); // 计算哈希值
  Node *current = table[index]; // 找到表中对应位置

  while (current != nullptr)  // 遍历链表
    {
      if (current->data->get_name () == key)
        {
          delete current->data; // 删除原有对象
          current->data = item; // 将新对象赋值给当前节点
          return; // 结束
        }
      current = current->next;
    }
}

std::vector<const sim_contacts::sim_contacts *> hash_table::to_vector () const
{
  std::vector<const sim_contacts::sim_contacts *> vec;  // 创建std::vector对象
  for (int i = 0; i < TABLE_SIZE; i++)  // 遍历哈希表
    {
      Node *current = table[i];
      while (current != nullptr)  // 遍历链表
        {
          vec.push_back (current->data);    // 将对象添加到std::vector中
          current = current->next;
        }
    }
  return vec;
}


