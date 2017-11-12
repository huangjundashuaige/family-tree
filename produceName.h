#ifndef __NAME_H__  
#define __NAME_H__  

#include<string>
using namespace std;
class CName  
{  
public:  
    CName();      
   
    virtual ~CName();  
   
    string GetName();  
    char m_szName[ 7 ];
   
    void InitSurname();  
   
    void InitName();  
   
    char* m_pSurname_OneDimensional;  
    char** m_ppSurname;     // 姓  
   
    char* m_pName_OneDimensional;  
    char** m_ppName;        // 名  
   
    // 3 个中文占 6 个字符  
      
};  
   
   
#endif  