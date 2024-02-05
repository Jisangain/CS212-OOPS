#include<iostream>
#include<string.h>
using namespace std;

class String
{
    char *str;
    int length;
     
public:
    String()
    {
        length = 0;
        str = new char [length + 1] ;
    }
    String(const char *s)
    {
        length = strlen(s);
        str = new char[length+1];
        strcpy(str, s);
    }
    void concat(String &s){
        length += s.length;
        strcat(str,s.str);
    }
    void display(){
        cout<<str<<endl;
    }
    void size(){
        cout<<length<<endl;
    }
};


int main()
{
    String s1;
    String s2("Well ");
    String s3("done!");
    s1.concat(s2);
    s1.concat(s3);
    s1.display();
    s1.size();
    return 0;
}