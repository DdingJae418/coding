#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS
{
    enum {CLERK, SENIOR, ASSIST, MANAGER};
}

class NameCard
{
private: 
    char* name;
    char* compName;
    char* phoneNum;
    int position;
public:
    NameCard(const char *nameString, const char *compString, const char *phone, int pos)
    {
        name = new char[strlen(nameString)+1];
        strcpy(name, nameString);
        compName = new char[strlen(compString)+1];
        strcpy(compName, compString);
        phoneNum = new char[strlen(phone)+1];
        strcpy(phoneNum, phone);
        position = pos;
    }
    NameCard(const NameCard &copy) : position(copy.position)
    {
        name = new char[strlen(copy.name)+1];
        strcpy(name, copy.name);
        compName = new char[strlen(copy.compName)+1];
        strcpy(compName, copy.compName);
        phoneNum = new char[strlen(copy.phoneNum)+1];
        strcpy(phoneNum, copy.phoneNum);
    }
    void ShowNameCardInfo() const
    {
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<compName<<endl;
        cout<<"전화번호: "<<phoneNum<<endl;
        cout<<"직급: "<<GetPosName(position)<<endl<<endl;
    }
    ~NameCard()
    {
        delete[] name;
        delete[] compName;
        delete[] phoneNum;
    }
private:
    const char* GetPosName(int pos) const
    {
        switch(pos)
        {
            case 0:
                return "사원";
            case 1:
                return "주임";
            case 2: 
                return "대리";
            case 3: 
                return "과장";
            default:
                return "error";
        }
    }
};

int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard manSENIOR("Lee", "ABCEng", "010-1111-2222", COMP_POS::SENIOR);
    NameCard manAssist("Lee", "ABCEng", "010-1111-2222", COMP_POS::ASSIST);

    manClerk.ShowNameCardInfo();
    manSENIOR.ShowNameCardInfo();
    manAssist.ShowNameCardInfo();
    return 0;
}