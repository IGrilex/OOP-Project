#ifndef USER
#define USER

using namespace std;

class User{
protected:
    string firstName;
    string lastName;
    string city;
    int debt;
public:
    User(string firstName,string lastName,string city,int debt);
    User();

    //virtual void populate()=0;

    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setCity(string city);
    void setDebt(int debt);

    string getFirstName();
    string getLastName();
    string getCity();
    int getDebt();

    void virtual print()=0;
};

#endif // USER
