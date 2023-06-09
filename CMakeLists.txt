cmake_minimum_required(VERSION 3.25)
project(contacts_mgr)

set(CMAKE_CXX_STANDARD 23)

add_executable(contacts_mgr main.cpp public.hpp hash_table.cpp hash_table.hpp sim_contacts.hpp phone_contact.cpp phone_contact.hpp contact_abstract.hpp phone_book.cpp phone_book.hpp sim_contacts.cpp sim_book.cpp sim_book.hpp contact_abstract.cpp)
