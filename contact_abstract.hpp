//
// Created by Jun ASAKA on 08/06/23.
//

#ifndef _CONTACT_ABSTRACT_HPP_
#define _CONTACT_ABSTRACT_HPP_

#include "public.hpp"
#include "sim_contacts.hpp"
#include "hash_table.hpp"

class contact_abstract {

 protected:
  hash_table* name_table;
  hash_table* phone_table;
  uint size;

 public:

  contact_abstract();

  virtual bool insert_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) = 0;
  virtual bool insert_item(std::string name, std::string phone_number) = 0;
  void delete_item(std::string phone_number);
  void display();
  virtual void modify_item(std::string name, std::string phone_number, std::string origin, std::string qq_id) = 0;
  virtual void modify_item(std::string name, std::string phone_number) = 0;
  void query(const std::string& name);

  bool search_phone(const std::string &key); // if exist
  bool search_name(const std::string &key); // if exist

  std::string get_phone(const std::string& name) const;

};

#endif //_CONTACT_ABSTRACT_HPP_
