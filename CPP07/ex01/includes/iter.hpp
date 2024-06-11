#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <stdexcept>
#include <cmath>
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define CYAN "\e[0;36m"
#define YELLOW "\e[0;33m"
#define BLACK "\033[0;30m"
#define RESET "\033[0m"
#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

template <typename T>
void print(T a) {
    std::cout  << a << std::endl;
}

template <typename T, typename F>
void iter(T *arr, unsigned int size, F f)
{
    for (unsigned int i = 0; i < size; i++) {
        f(arr[i]);
    }
}

#endif