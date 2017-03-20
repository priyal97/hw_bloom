//
// Created by Ari Trachtenberg on 3/15/17.
//

#include "myBloom.h"
#include <cstring>
#include <iostream>
#include <string>

myBloom::myBloom(int mm) : Bloom(mm) { filter = new char[length]; memset(filter, '_', length);}

myBloom::myBloom(std::string newFilter) : myBloom(newFilter.length()) { strncpy(filter,newFilter.c_str(),length); }

void myBloom::insert(std::string item) { filter[count++] = item[0]; }

bool myBloom::exists(std::string item) {
    for (int ii = 0; ii < length; ii++)
        if (filter[ii] == item[0])
            return true;
    return false;
}

std::string myBloom::output() { return std::string(filter, length); }

myBloom::~myBloom() { delete[] filter; }
