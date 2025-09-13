#ifndef AUTH_H
#define AUTH_H

#include <string>

bool login();
bool signup();
bool existUser(const std::string &username);

#endif
