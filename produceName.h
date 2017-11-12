#ifndef __NAME_H__  
#define __NAME_H__  
   
class CName  
{  
public:  
    CName();      
   
    virtual ~CName();  
   
    const char* GetName();  
protected:  
   
    void InitSurname();  
   
    void InitName();  
   
    char* m_pSurname_OneDimensional;  
    char** m_ppSurname;     // 姓  
   
    char* m_pName_OneDimensional;  
    char** m_ppName;        // 名  
   
    // 3 个中文占 6 个字符  
    char m_szName[ 7 ];  
};  
   
   
#endif  