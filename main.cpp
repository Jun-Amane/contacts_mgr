#include "public.hpp"

#include "phone_book.hpp"
#include "sim_book.hpp"

#include "file_mgr.hpp"
#include "user.hpp"

int main() {


  auto* book = new sim_book::sim_book();

  book->modify_item ("alpha", "abcdefg");
  book->delete_item ("789");

  book->query ("alpha");
  std::cout << "******************************************\n";
  book->display();

  auto* phone = new phone_book::phone_book();
  phone->modify_item ("alpha", "abcdefg","nn", "xx");
  phone->delete_item ("789");
  phone->query ("alpha");
  std::cout << "******************************************\n";
  phone->display();






  return 0;
}
