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

/**
//given hash
void given(string item,int len)
{
	filter[item[0]%len] = 'X';
}
*/
//first hash
int hash1(string item, int len)
{
int hashvalue1=0;
for(int i=0;i<item.length();i++)
{
	hashvalue1=hashvalue1*57+item[i]*3;
}
hashvalue1 %= len;
return hashvalue1;
}


//second hash
int hash2(string item, int len)
{
int hashvalue2=0;
for(int i=0;i<item.length();i++)
{
	hashvalue2 = (hashvalue2*37)^ int(item[i]);
}
hashvalue2 %= len;
return hashvalue2;
}




//third hash
int hash3(string item, int len)
{
int hashvalue3=0;
for(int i=0;i<item.length();i++)
{
	hashvalue3 += item[i];
}
hashvalue3 %= len;
return hashvalue3;
}



void myBloom::insert(std::string item) 
{ 
	given(item,length);
	int hashvalue1=hash1(item,length);   
	int hashvalue2=hash2(item,length); 
	int hashvalue3=hash3(item,length);            
   switch (filter[hashvalue1]) {
                case '_':
                filter[hashvalue1] = 'A';
                break;
                case 'B':
                filter[hashvalue1] = 'D';
                break;
                case 'C':
                filter[hashvalue1] = 'E';
                break;
                case 'F':
                filter[hashvalue1] = 'G';
                break;
                
                default:
                break;
        }
         switch (filter[hashvalue2]) {
                case '_':
                filter[hashvalue2] = 'B';
                break;
                case 'A':
                filter[hashvalue2] = 'D';
                break;
                case 'C':
                filter[hashvalue2] = 'F';
                break;
                case 'E':
                filter[hashvalue2] = 'G';
                break;
                
                default:
                break;
        }
         switch (filter[hashvalue3]) {
                case '_':
                filter[hashvalue3] = 'C';
                break;
                case 'A':
                filter[hashvalue3] = 'E';
                break;
                case 'B':
                filter[hashvalue3] = 'F';
                break;
                case 'D':
                filter[hashvalue3] = 'G';
                break;
                
                default:
                break;
        }
     
}

bool myBloom::exists(std::string item) 
{
	int hashvalue1=hash1(item,length);   
	int hashvalue2=hash2(item,length); 
	int hashvalue3=hash3(item,length);  
//   if( filter[item[0]%length]!='X')
 //   	return false;
   if (filter[hashvalue1] == '_' || filter[hashvalue1] == 'B' || filter[hashvalue1] == 'C' || filter[hashvalue1] == 'F')
        return false;
   if (filter[hashvalue2] == '_' || filter[hashvalue2] == 'A' || filter[hashvalue2] == 'C' || filter[hashvalue2] == 'E')
        return false;
   if (filter[hashvalue3] == '_' || filter[hashvalue3] == 'A' || filter[hashvalue3] == 'B' || filter[hashvalue3] == 'D')
        return false;
   
return true;
}

std::string myBloom::output() { return std::string(filter, length); }

myBloom::~myBloom() { delete[] filter; }
