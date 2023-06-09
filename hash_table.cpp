//
// Created by Jun ASAKA on 08/06/23.
//

#include "hash_table.hpp"

int hash_table::hashFunction (const std::string &key)
{

    std::hash<std::string> hasher;
    std::size_t hashValue = hasher(key);
    return hashValue % TABLE_SIZE;

}
hash_table::hash_table ()
{
  table = new Node*[TABLE_SIZE];
  for (int i = 0; i < TABLE_SIZE; ++i) {
      table[i] = nullptr;
    }

}
hash_table::~hash_table ()
{
  for (int i = 0; i < TABLE_SIZE; ++i) {
      Node* current = table[i];
      while (current != nullptr) {
          Node* next = current->next;
          delete current;
          current = next;
        }
    }
  delete[] table;
}
void hash_table::insert (const sim_contacts::sim_contacts* item, const std::string &key)
{
  int index = hashFunction(key);
  Node* newNode = new Node(item);

  if (table[index] == nullptr) {
      table[index] = newNode;
    } else {
      Node* current = table[index];
      while (current->next != nullptr) {
          current = current->next;
        }
      current->next = newNode;
    }

}
bool hash_table::search_phone (const std::string &key)
{
  int index = hashFunction(key);
  Node* current = table[index];

  while (current != nullptr) {
      if (current->data->get_phone_number() == key) {
          return true; // 找到了
        }
      current = current->next;
    }
  return false; // 未找到

}
void hash_table::remove (const std::string &key) // phone number oried.
{
  int index = hashFunction(key);
  Node* current = table[index];
  Node* previous = nullptr;

  while (current != nullptr) {
      if (current->data->get_phone_number() == key) {
          if (previous == nullptr) {
              table[index] = current->next;
            } else {
              previous->next = current->next;
            }
          delete current;
          return;
        }
      previous = current;
      current = current->next;
    }

}
void hash_table::remove_by_name (const std::string &key)
{
  int index = hashFunction(key);
  Node* current = table[index];
  Node* previous = nullptr;

  while (current != nullptr) {
      if (current->data->get_name() == key) {
          if (previous == nullptr) {
              table[index] = current->next;
            } else {
              previous->next = current->next;
            }
          delete current;
          return;
        }
      previous = current;
      current = current->next;
    }

}
std::string hash_table::get_name_by_phone (const std::string &key)
{
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->data->get_phone_number() == key) {
            return current->data->get_name();
            }
        current = current->next;
        }
        //TODO: throw exception
    return "";
}
void hash_table::display_all ()
{
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node* current = table[i];
        while (current != nullptr) {
            std::cout << *current->data << std::endl;
            current = current->next;
            }
        }

}
void hash_table::modify (const sim_contacts::sim_contacts *item, const std::string &key)
{
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->data->get_name() == key) {
          delete current->data;
            current->data = item;
            return;
            }
        current = current->next;
        }
}
void hash_table::search_name (const std::string &key)
{
    int index = hashFunction(key);
    Node* current = table[index];

    while (current != nullptr) {
        if (current->data->get_name() == key)
            std::cout << *current->data << std::endl;
        current = current->next;
        }
}


