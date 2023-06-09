#include "public.hpp"

#include "phone_book.hpp"
#include "sim_book.hpp"

int main() {

  auto * ph = new phone_book::phone_book();
  auto * sim = new sim_book::sim_book();

  ph->insert_item ("alpha", "1", "a", "11");
  ph->insert_item ("alpha", "2","b","22");
  ph->insert_item ("beta", "1", "a", "11");


  ph->modify_item ("alpha", "3", "c", "33");
  ph->display();


  return 0;
}
