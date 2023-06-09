//
// Created by Jun ASAKA on 2023/6/9.
//

#ifndef _USER_H_
#define _USER_H_

#include "public.hpp"
#include "phone_book.hpp"
#include "sim_book.hpp"

namespace user
{

    class user {

     protected:

        phone_book::phone_book * phone_book_ptr;
        sim_book::sim_book * sim_book_ptr;

        contact_abstract * book_ptr;

     public:

        user();
        ~user();

        enum media {
            sim,
            phone
        };

        void add_contact();
        void delete_contact();
        void modify_contact();
        void search_contact();




    };

} // user

#endif //_USER_H_
