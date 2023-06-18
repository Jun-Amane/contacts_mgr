#include "public.hpp"

#include "ui.hpp"
#include "user.hpp"
#include <stdlib.h>

int main() {

//
//  auto* book = new sim_book::sim_book();
//
//  book->modify_item ("alpha", "abcdefg");
//  book->delete_item ("789");
//
//  book->query ("alpha");
//  std::cout << "******************************************\n";
//  book->display();
//  delete book;
//  std::cout << "******************************************\n";
//
//  auto* phone = new phone_book::phone_book();
//  phone->modify_item ("alpha", "abcdefg","nn", "xx");
//  phone->delete_item ("789");
//  phone->query ("alpha");
//  std::cout << "******************************************\n";
//  phone->display();
//  delete phone;

  system("CHCP 65001"); // For Windows.

  auto* main_user = new user::user();
  auto* main_ui = new ui::ui();

  while(!main_ui->display(main_user));

  return 0;
}
