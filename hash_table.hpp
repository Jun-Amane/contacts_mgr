//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _HASH_TABLE_HPP_
#define _HASH_TABLE_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"
#include <vector>

const int TABLE_SIZE = 100;

class Node {
 public:
  const sim_contacts::sim_contacts *data;
  Node *next;

  Node (const sim_contacts::sim_contacts *value) : data (value), next (nullptr)
  {}
};

class hash_table {
 private:
  Node **table;

  static int hashFunction (const std::string &key);

 public:
  hash_table ();

  ~hash_table ();

  void insert (const sim_contacts::sim_contacts *item, const std::string &key);

  std::string get_name_by_phone (const std::string &key);

  bool search_phone (const std::string &key); // if exist
  bool search_name (const std::string &key); // if exist

  const sim_contacts::sim_contacts *query_name (const std::string &key);

  void remove (const std::string &key);
  void remove_by_name (const std::string &key);

  void display_all ();

  void modify (const sim_contacts::sim_contacts *item, const std::string &key);

  std::vector<const sim_contacts::sim_contacts *> to_vector () const;
};

#endif //_HASH_TABLE_HPP_
