//
// Created by Ari Trachtenberg on 3/15/17.
//

#include "myBloom.h"

myBloom::myBloom(int mm) : Bloom(mm) { filter = new char[length]; }

void myBloom::insert(std::string item) { filter[count++] = item[0]; }

bool myBloom::exists(std::string item) {
    for (int ii = 0; ii < length; ii++)
        if (filter[ii] == item[0])
            return true;
    return false;
}

std::string myBloom::output() { return filter; }

myBloom::~myBloom() { delete[] filter; }
