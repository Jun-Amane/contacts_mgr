/*
 * 主函数所在文件
 */

#include "public.hpp"

#include "ui.hpp"
#include "user.hpp"

#include <locale> // For POSIX, unused in Windows.

int main ()
{

#ifdef _WIN32
  system ("CHCP 65001"); // For Windows.
#else
  setlocale (LC_ALL, "zh_CN.UTF-8"); // For POSIX.
#endif

  auto *main_user = new user::user ();
  auto *main_ui = new ui::ui ();

  while (!main_ui->display (main_user));

  return 0;
}
