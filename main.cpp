#include "public.hpp"

#include "phone_book.hpp"
#include "sim_book.hpp"

// write
//  std::ofstream file(filename);
//  if (file.is_open()) {
//      for (const auto& pair : contacts) {
//          file << pair.second << std::endl;
//        }
//      file.close();
//      std::cout << "Contacts written to file successfully." << std::endl;
//    } else {
//      std::cout << "Unable to open file for writing." << std::endl;
//    }


// read
//  contacts_tabel;
//  std::ifstream file(filename);
//  if (file.is_open()) {
//      Contact contact;
//      while (file >> contact) {
//          contacts[contact.name] = contact;
//        }
//      file.close();
//      std::cout << "Contacts read from file successfully." << std::endl;
//    } else {
//      std::cout << "Unable to open file for reading." << std::endl;
//    }
//  return contacts_table;



int main() {

  auto * ph = new phone_book::phone_book();
  auto * sim = new sim_book::sim_book();

  ph->insert_item ("alpha", "1", "a", "11");
  ph->insert_item ("alpha", "2","b","22");
  ph->insert_item ("beta", "1", "a", "11");


  ph->modify_item ("alpha", "3", "c", "33");
  ph->display();




    std::unordered_map<std::string, Contact> contacts;
    contacts["John"] = Contact("John", "1234567890");
    contacts["Alice"] = Contact("Alice", "9876543210");

    std::string filename = "contacts.txt";

    // 写入通讯录到文件
    writeContactsToFile(contacts, filename);

    // 从文件中读取通讯录
    std::unordered_map<std::string, Contact> contactsFromFile = readContactsFromFile(filename);

    // 打印从文件中读取的通讯录
    for (const auto& pair : contactsFromFile) {
        std::cout << "Name: " << pair.second.name << ", Phone: " << pair.second.phoneNumber << std::endl;
      }




  return 0;
}
