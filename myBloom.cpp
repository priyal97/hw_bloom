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

/*
void given(string item,int len)
{
	int givenhash=item[0]%len;
	return givenhash;
}
*/

//first hash
int hash1(string item, int len)
{
int hashvalue1=0;
for(int i=0;i<item.length();i++)
{
	hashvalue1=hashvalue1*33+item[i];
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

//fourth hash
int hash4(string item, int len)
{
int hashvalue4=0;
for(int i=0;i<item.length();i++)
{
	hashvalue4 ^=(hashvalue4 << 4)+(hashvalue4 >> 28)+(int)item[i];
}
hashvalue4 %= len;
return hashvalue4;
}


void myBloom::insert(std::string item) 
{ 
//	int givenhash=given(item,length);
//	filter[givenhash] = 'X';
	int hashvalue1=hash1(item,length);   
	int hashvalue2=hash2(item,length); 
	int hashvalue3=hash3(item,length); 
    int hashvalue4=hash4(item,length);          
   switch (filter[hashvalue1]) {
                case '_':
                filter[hashvalue1] = 'A';
                break;
                case 'B':
                filter[hashvalue1] = 'E';
                break;
                case 'C':
                filter[hashvalue1] = 'F';
                break;
                case 'D':
                filter[hashvalue1] = 'G';
                break;
                case 'H':
                filter[hashvalue1] = 'K';
                break;
                case 'I':
                filter[hashvalue1] = 'L';
                break;
                case 'J':
                filter[hashvalue1] = 'M';
                break;
                case 'N':
                filter[hashvalue1] = 'O';
                break;
                default:
                break;
        }
         switch (filter[hashvalue2]) {
                case '_':
                filter[hashvalue2] = 'B';
                break;
                case 'A':
                filter[hashvalue2] = 'E';
                break;
                case 'C':
                filter[hashvalue2] = 'H';
                break;
                case 'D':
                filter[hashvalue2] = 'I';
                break;
                case 'F':
                filter[hashvalue2] = 'K';
                break;
                case 'G':
                filter[hashvalue2] = 'L';
                break;
                case 'J':
                filter[hashvalue2] = 'N';
                break;
                case 'M':
                filter[hashvalue2] = 'O';
                break;
  
                default:
                break;
        }
         switch (filter[hashvalue3]) {
                case '_':
                filter[hashvalue3] = 'C';
                break;
                case 'A':
                filter[hashvalue3] = 'F';
                break;
                case 'B':
                filter[hashvalue3] = 'H';
                break;
                case 'D':
                filter[hashvalue3] = 'J';
                break;
                case 'E':
                filter[hashvalue3] = 'K';
                break;
                case 'G':
                filter[hashvalue3] = 'M';
                break;
                case 'I':
                filter[hashvalue3] = 'N';
                break;
                case 'L':
                filter[hashvalue3] = 'O';
                break;
                default:
                break;
        }
        switch (filter[hashvalue4]) {
                case '_':
                filter[hashvalue4] = 'D';
                break;
                case 'A':
                filter[hashvalue4] = 'G';
                break;
                case 'B':
                filter[hashvalue4] = 'I';
                break;
                case 'C':
                filter[hashvalue4] = 'J';
                break;
                case 'E':
                filter[hashvalue4] = 'L';
                break;
                case 'F':
                filter[hashvalue4] = 'M';
                break;
                case 'H':
                filter[hashvalue4] = 'N';
                break;
                case 'K':
                filter[hashvalue4] = 'O';
                break;
                default:
                break;
        }
     
}

bool myBloom::exists(std::string item) 
{
//	int givenhash=given(item,length);
	int hashvalue1=hash1(item,length);   
	int hashvalue2=hash2(item,length); 
	int hashvalue3=hash3(item,length);  
	int hashvalue4=hash4(item,length); 
//   if( filter[givenhash]!='X')
//    	return false;
   if (filter[hashvalue1] == '_' || filter[hashvalue1] == 'B' || filter[hashvalue1] == 'C' || filter[hashvalue1] == 'D'|| filter[hashvalue1] == 'H'|| filter[hashvalue1] == 'I'|| filter[hashvalue1] == 'J'|| filter[hashvalue1] == 'N')
        return false;
    if (filter[hashvalue2] == '_' || filter[hashvalue2] == 'A' || filter[hashvalue2] == 'C' || filter[hashvalue2] == 'D'|| filter[hashvalue2] == 'F'|| filter[hashvalue2] == 'G'|| filter[hashvalue2] == 'J'|| filter[hashvalue2] == 'M')
        return false;
    if (filter[hashvalue3] == '_' || filter[hashvalue3] == 'A' || filter[hashvalue3] == 'B' || filter[hashvalue3] == 'D'|| filter[hashvalue3] == 'E'|| filter[hashvalue3] == 'G'|| filter[hashvalue3] == 'I'|| filter[hashvalue3] == 'L')
        return false;
    if (filter[hashvalue4] == '_' || filter[hashvalue4] == 'A' || filter[hashvalue4] == 'B' || filter[hashvalue4] == 'C'|| filter[hashvalue4] == 'E'|| filter[hashvalue4] == 'F'|| filter[hashvalue4] == 'H'|| filter[hashvalue4] == 'K')
        return false;
   
   
return true;
}

std::string myBloom::output() { return std::string(filter, length); }

myBloom::~myBloom() { delete[] filter; }
