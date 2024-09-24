#ifndef LOGGING_H
#define LOGGING_H
#include <iostream>
#include <string>

#define DEBUG 1

#ifdef DEBUG
#define LOG(x) (std::cout << std::string(x) << std::endl)
#else
#define LOG(x)
#endif

#endif