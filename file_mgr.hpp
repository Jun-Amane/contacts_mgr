/*
 * file_mgr.hpp
 * Created by Jun ASAKA on 09/06/23.
 *
 * 用途：文件管理，用于读写文件。
 *
 */


#ifndef _FILE_MGR_HPP_
#define _FILE_MGR_HPP_

#include "public.hpp"
#include <fstream>
#include <sstream>
#include "hash_table.hpp"
#include "phone_contact.hpp"

namespace file_mgr
{
    /*
     * @brief 读取手机卡文件，并以名字为键构建哈希表。
     * @param 文件名。
     * @return 储存sim卡内容的，以名字为键的哈希表。
     */
    hash_table *read_sim_name_table (const std::string &file_name);

    /*
     * @brief 读取手机卡文件，并以电话为键构建哈希表。
     * @param 文件名。
     * @return 储存sim卡内容的，以电话为键的哈希表。
     */
    hash_table *read_sim_phone_table (const std::string &file_name);

    /*
     * @brief 读取电话簿文件，并以名字为键构建哈希表。
     * @param 文件名。
     * @return 储存电话簿内容的，以名字为键的哈希表。
     */
    hash_table *read_phone_name_table (const std::string &file_name);

    /*
     * @brief 读取电话簿文件，并以电话为键构建哈希表。
     * @param 文件名。
     * @return 储存电话簿内容的，以电话为键的哈希表。
     */
    hash_table *read_phone_phone_table (const std::string &file_name);

    /*
     * @brief 将电话簿写入文件。
     * @details 利用两类通讯录的运算符重载，自动写入文件，不需要特别区分。
     * @param 文件名，电话簿哈希表。
     * @return 是否成功。
     */
    bool write_sim_book (const std::string &file_name, hash_table *name_table); // 一者二用

}

#endif //_FILE_MGR_H_
