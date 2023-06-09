//
// Created by Jun ASAKA on 2023/6/9.
//

#ifndef _FILE_MGR_H_
#define _FILE_MGR_H_

#include "public.hpp"
#include <fstream>
#include <sstream>
#include "hash_table.hpp"
#include "phone_contact.hpp"

namespace file_mgr {

    hash_table * read_sim_name_table(std::string file_name);
    hash_table * read_sim_phone_table(std::string file_name);
    hash_table * read_phone_name_table(std::string file_name);
    hash_table * read_phone_phone_table(std::string file_name);
    bool write_sim_book(std::string file_name, hash_table * name_table); // 一者二用

}

#endif //_FILE_MGR_H_
