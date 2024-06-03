#ifndef DEFINES_HPP
#define DEFINES_HPP

//-------------------------------------  COLORS  -------------------------------------
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
//-------------------------------------  MESSAGES  -----------------------------------
#define WRONG_ARGS "Wrong arguments\n Try: ./[exec] [argument]"
#define WRONG_TYPE "Invalid argument type"
#define BAD_SERIALIZATION "Serialization and deserialization failed"
//-------------------------------------  MACROS  -------------------------------------
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

#endif
