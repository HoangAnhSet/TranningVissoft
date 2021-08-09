// Nội dung chương 13-14  sách Cpp primer plus 6th
///////////////////////////////// Class Inheritance///////////////////////////////////
// Kế thừa
/* #include<iostream>
#include<string>
using namespace std;
class TableTennisPlayer
{
    private:
        string FirstName;
        string LastName;
        bool hasTable;
    public:
        TableTennisPlayer(const string & fn="none", const string & ln="none", bool ht=false);
        void Name() const;
        bool HasTable() const {return hasTable;}
        void ResetTable(bool v){ hasTable=v;}

};
class RatedPlayer:public TableTennisPlayer
{
    private:
        unsigned int rating;
    public:
        RatedPlayer(unsigned int r, const string & fn="none",const string &ln="none",bool ht=true);
        RatedPlayer(unsigned int r,   const TableTennisPlayer &tp);
        unsigned int Rating() const {return rating;}
        void ResetRating (unsigned int r){rating=r;}
};
TableTennisPlayer::TableTennisPlayer(const string & fn,const string &ln,bool ht):FirstName(fn),
LastName(ln),hasTable(ht){}
void TableTennisPlayer::Name() const{ cout<<LastName<<" , "<<FirstName;}
RatedPlayer::RatedPlayer(unsigned int r, const string &fn, const string &ln, bool ht):TableTennisPlayer(fn,ln,ht){
    rating=r;
}
RatedPlayer::RatedPlayer(unsigned int r, const TableTennisPlayer & tp):TableTennisPlayer(tp), rating(r)
{

}
int main()
{
    RatedPlayer rateplayer1(11,"Hoang","Anh",true) ;  
    TableTennisPlayer tableplayer1("Do","Na",true);
    RatedPlayer rateplayer2(112,tableplayer1);
    rateplayer1.Name();
}  */
// Tính protected access
////////////////////////////////////// Hàm ảo///////////////////////////////////////
//=> tại sao cần virtual destructor
/* #include<iostream>
using namespace std;
class base
{
    public:
    base()
    {
        cout<<"Constructor base\n";
    }
    virtual ~base()
    {
        cout<<"Deconstructor base\n";
    }
};
class derive:public base
{
    public:
    derive()
    {
        cout<<"Constructor derive\n";
    }
    ~derive()
    {
          cout<<"Deconstructor derive\n";
    }
};
class derive1:public base
{
    public:
    derive1()
    {
        cout<<"Constructor derive1\n";
    }
    ~derive1()
    {
          cout<<"Deconstructor derive1\n";
    } 
};
int main()
{
    base *de=new derive();
    base *de1=new derive1();
    delete de;
    delete de1;

} */
// Tính đa hình
// #include<iostream>
// using namespace std;
// #include<string>

// class Brass
// {
//     private:
//         string fullname;
//         long accNum;
//         double balance;
//     public:

//         Brass(const string &fn="NULL", long an=-1,double bl=0.0)
//         {

//         }
//         void Deposit(double amt);
//         virtual void Withdraw(double amt);
//         double Balance() const;
//         virtual void ViewAcct() const;
//         virtual ~Brass(){}
// };
// class BrassPlus:public Brass{
//     private:
//         double maxLoan;
//         double rate;
//         double owesBank;
//     public:

// }
/* // luyện tập hacker rank
// 
/* #include <cmath>

#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person
{
public:
   string name;
   int age;

public:
   virtual void getdata()
   {
      cin >> this->name >> this->age;
   }
   virtual void putdata()
   {
      cout << this->name << this->age;
   }
};
class Professor : public Person
{
    private:
        int publications;

    public:
        static int id;
        int cur_id;

    public:
        Professor()
   {
      this->cur_id=++id;
      
   }
      void getdata() //input from user
      {
         cin >> this->name >> this->age >> this->publications;
      }
      void putdata() //print name, age, publications,cur_id
      {
         cout << this->name << " " << this->age << " " << this->publications << " " << this->cur_id << endl;
      }
   };
   int Professor::id = 0;

   class Student : public Person
   {
   public:
      int mark[6];

   public:
       static int id;
      int cur_id;
      Student()
      {
         this->cur_id=++id;
      }
      void getdata() //get input from the user:name,age,the mark in 6 subject
      {
         string theName;
         int theAge;
         cin >> this->name >> this->age;
         for (int i = 0; i < 6; i++)
         {
            cin >> this->mark[i];
         }
      }
      int sumMarks()
      {
         int sum = 0;
         for (int i = 0; i < 6; i++)
         {
            sum = sum + mark[i];
         }
         return sum;
      }
      void putdata() //print the name, age, sum of the marks cur_id of the student
      {
         cout << this->name << " " << this->age << " " << sumMarks() << " " << this->cur_id << endl;
      }
   };
   int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

 */ 
////////////////////////////// static dynamic binding
//

/* #include<iostream>
using namespace std;

class Base
{
    public:
         Base()
        {
            cout<<"This is constructor Base"<<endl;
        }
        virtual void showData()
        {
            cout<<"This is function showData Base"<<endl;
        }
        virtual ~Base()// xóa bố xóa của con
        {
            cout<<"This is deconstructor Base"<<endl;
        }
};

class Derive:public Base{
     public:
        Derive()
        {
            cout<<"This is constructor Derive"<<endl;
        }
        void showData()
        {
            cout<<"This is function showData Derive"<<endl;
        }
        ~Derive()
        {
            cout<<"This is deconstructor Derive"<<endl;
        }
};

int main()
{
    /* Base *b;
    Derive ptr;
    b=&ptr;
    b->showData();
    delete b; *///=> kết quả
// This is constructor Base        
// This is constructor Derive      
// This is function showData Derive
// This is deconstructor Derive    
// This is deconstructor Base      
// This is deconstructor Derive    
// This is deconstructor Base    */// chưa giải thích tại sao lại có hai lần deconstructor
//     Base base();
//     cout<<"Khai Bao con tro\n";
//     // Khai Báo con trỏ
//     Base *ptrBase;
//     ptrBase=new Base();
//     delete ptrBase;
//     Derive *ptr;
//     ptr=new Derive();
//     delete ptr;
// }
// Khai Bao con tro
// This is constructor Base
// This is deconstructor Base
// This is constructor Base
// This is constructor Derive
// This is deconstructor Derive
// This is deconstructor Base */