//
// Created by Ari Trachtenberg on 3/15/17.
//

#include "myBloom.h"
#include <cstring>
#include <iostream>
#include <string>
using namespace std;

myBloom::myBloom(int mm) : Bloom(mm) { filter = new char[length]; memset(filter, '_', length);}

myBloom::myBloom(std::string newFilter) : myBloom(newFilter.length()) { strncpy(filter,newFilter.c_str(),length); }


//given hash
void given(String item,int len)
{
	filter[item[0]%len] = 'X';
}

//first hash
int hash1(string item, int len)
{
int hashvalue1=0;
for(int i=0;i<item.length();i++)
{
	hashvalue1=hashvalue1*57+key[i]*3;
}
hashvalue1 %= len;
return hashvalue1;
}


//second hash
/**
int hash2(string item, int len)
{



//return hashvalue2;
}
*/

//third hash





void myBloom::insert(std::string item) 
{ 
	given(item,length);
	int hashvalue1=hash1(item,length);              
    filter[hashvalue1] = 'A';
//	int hashvalue2=hash2(item,length);
//	int hashvalue3=hash3(item,length);
}

bool myBloom::exists(std::string item) 
{
    if( filter[item[0]%length]=='X' && filter[hashvalue1] = 'A')
    return true;
return false;
}

std::string myBloom::output() { return std::string(filter, length); }

myBloom::~myBloom() { delete[] filter; }

