//
// Created by Ari Trachtenberg on 3/15/17.
//

#ifndef BLOOMFILTER_MYBLOOM_H
#define BLOOMFILTER_MYBLOOM_H

#include "Bloom.h"
#include <cstring>

/**
 * A trivial implementation of the Bloom class
 */
class myBloom : Bloom {
public:
    myBloom(int mm);
    myBloom(std::string filter);
    void insert(std::string item);
    bool exists(std::string item);
    std::string output();
    ~myBloom();
private:
    char *filter;
    int count=0;
};

#endif //BLOOMFILTER_MYBLOOM_H
