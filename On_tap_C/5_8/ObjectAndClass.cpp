#include<iostream>
#include<string>
using namespace std;
// Nội dung ôn tập về Object and Class
// Khái niệm public, private, protect trong Class
// Khai báo một class
/*class SinhVien
{   
    private:
    int MSSV;
    char Ten[100];
    char ChuyenNganh[100];
    //Hàm tạo
    public:
    SinhVien()
    {
        cout<<"Toi la sinh vien"<<endl;
    }
    //Hàm Hủy
    ~SinhVien()
    {
        cout<<" Good bye!"<<endl;
    }

};
int main()
{   cout<<"Hello world"<<endl;
    SinhVien sinhv1;
    return 0;
} */
// Khái niệm hàm tạo, hàm hủy
/* class SinhVien
{
    private:
    int MSSV;
    string Ten;
    string ChuyenNganh;
    //Hàm tạo
    public:
    SinhVien( const string &ten,const string &chuyennganh,int mssv=0);
    //Khai báo bên ngoài thì cần gán giá trị
        // truyền vào một địa chỉ
    // {
    //     MSSV=mssv;
    //     Ten=ten;
    //     ChuyenNganh=chuyennganh;
        
    // }
    SinhVien()
    {   
        cout<<"Toi la sinh vien"<<endl;
    }
    void showData()
    {
        cout<<"MSSV:"<<MSSV<<endl;
        cout<<"Ten:"<<Ten<<endl;
        cout<<"Chuyen Nganh:"<<ChuyenNganh<<endl;
    }
    //Hàm Hủy
    ~SinhVien()
    {
        cout<<" Good bye!"<<endl;
    }    
};
SinhVien::SinhVien(const string &ten, const string &chuyennganh,int mssv)
{
        MSSV=mssv;
        Ten=ten;
        ChuyenNganh=chuyennganh;

}
int main()
{   
    int mssv=20172402;
    SinhVien sinhv1("Hoang Anh","DTVT"); // Giá trị khởi tạo mặc định sẽ là 0
    SinhVien sinhv2("Do Na","CNSH",20174959); // Khai báo đầy đủ
    sinhv1.showData();
    sinhv2.showData();
    
} //=> xảy ra lỗi nhưng tôi chưa tìm được ra nguyên nhân, tôi đã tìm được lỗi. 
// Cú pháp khai báo khi có giá trị khởi tạo
// Khai báo để compiler biết giá trị, tham khảo CSC 125
 */
/* class Stock
{
    private:
    string company;
    int shares;
    double share_val;
    double total_val;
    void set_tot(){total_val=shares*share_val;}
    public:
    Stock();
    Stock(const string &co, long n=0, double pr=0.0);
    ~Stock();
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show () const;
    const Stock & topval( const Stock & s) const;
};
Stock::Stock()
{
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
} 

Stock:: Stock(const string &co, long n, double pr)
{
   company=co;
   if(n<0)
   {
       cout<<"Number of sharess can't be negative\n";
       shares=0;
   }
   else
   shares=n;
   share_val=pr;
   set_tot();
} 
int main()
{

} */
// Sử dùng hàm trong class
/* class SinhVien
{   private:
    int MSSV;
    double totalMark;
    string Ten;
    string Nganh;

    public:
    //Hàm construct 
    SinhVien();
    SinhVien(const string &ten, const string &nganh,int mssv,double mark);
    double getMark()
    {
        return totalMark;
    }
    string getName()
    {
        return Ten;
    }
    void showData();
    void updateMark(double totalmark);
    ~SinhVien()
    {}
};
SinhVien::SinhVien()
{
    int MSSV=0;
    double totalMark=0.0;
    string Ten=NULL;
    string Nganh=NULL;
}
SinhVien:: SinhVien(const string &ten, const string &nganh,int mssv,double mark)
{
    MSSV=mssv;
    totalMark=mark;
    Ten=ten;
    Nganh=nganh;
}
void SinhVien::showData()
{
cout<<"MSSV:"<<MSSV<<endl;
cout<<"totalMark:"<<totalMark<<endl;
cout<<"Ten:"<<Ten<<endl;
cout<<"Nganh:"<<Nganh<<endl;
}
void SinhVien::updateMark(double mark)
{
    totalMark=mark;
}
void soSanh(SinhVien sv1,SinhVien sv2)
{
    sv1.getMark()>sv2.getMark()?cout<<"Diem ban "<<sv1.getName()<<" Lon Hon":cout<<"Diem ban "<<sv2.getName()<<" Lon Hon";
}
int main()
{
    SinhVien sinhv1();
       SinhVien sinhv2("Hoang Anh","DTVT",20172405,3.17);
       sinhv2.showData();
          SinhVien sinhv3("Do Na","CNSH",20174959,3.16);
          soSanh(sinhv2,sinhv3);
}
 */
////////////////////////// Khái niệm operator trong class///////////////////////////////
// what is it ? một class là một kiểu dữ liệu, nó thể hiện cho một đối tượng.
// các member function thể hiện hành vi của nó, operator là cho phép bạn định nghĩa cách thức 
// thực hiện của class với các toán tử.
/* class Time
{
    private:

    int hours;
    int minutes;

    public:
    Time();
    Time(int h,int m=0);
    void AddMin( int m);
    void AddHr(int h);
    void Reset(int h=0, int m=0);
    // Time operator+(const Time & t);
    Time operator+(const Time & t) const;
    void Show() const;
};
Time::Time()
{
    hours=minutes=0;
}

Time::Time(int h, int m)
{
    hours=h;
    minutes=m;
}
void Time::AddHr(int h)
{
   hours+=h;
}
void Time::AddMin(int m)
{
   minutes+=m;
    hours+= minutes/60;
    minutes%=60;  
}
void Time::Reset(int h, int m)
{
    hours=h;
    minutes=m;
}
Time Time::operator+ (const Time & t) const
{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hours=hours+t.hours+sum.minutes;
    sum.minutes %=60;
    return sum;
}
void Time::Show()const
{
    cout<<hours<<" hours"<<minutes<<" minutes"<<endl;
}
int main()
{
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;
    cout<<"planning time = ";
    planning.Show();
    cout<<endl;
    cout<< "coding time = ";
    coding.Show();
    cout<<endl;
    cout<<" fixing time = ";
    fixing.Show();
    cout<<endl;
   // total=coding.operator+(fixing);// cách1 sử dụng toán tử
   total=coding+fixing;// cách 2 sử dụng toán tử
    cout<<" coding + fixing= ";
    total.Show();
    cout<<endl;
} */
////////////////////////// Khái niệm ghi đè trong class//////////////////////////////////


////////////////////////// Khái niệm hàm friend trong class/////////////////////////////
// what is it?
// How does it work ?
// why might they nê
class Time
{
    private:

    int hours;
    int minutes;

    public:
    Time();
    Time(int h,int m=0);
    void AddMin( int m);
    void AddHr(int h);
    void Reset(int h=0, int m=0);
    // Time operator+(const Time & t);
    Time operator+(const Time & t) const;
    Time operator *(double m) const
    {
        Time result;
        long totalminutes=hours *m * 60+ minutes*m;
        result.hours=totalminutes/60;
        result.minutes=totalminutes%60;
        return result;
    }
    friend Time operator * (double m,Time &t)// cái này thì được
    // friend Time operator * (const Time &t,double m)  // cái này thì không được
    {
        return t*m;
    }
    friend ostream & operator <<(ostream &os,const Time &t)
    {
        os<<t.hours<<" hours, "<<t.minutes<<" minutes, ";
        return os;
    }
    void Show() const;
};
Time::Time()
{
    hours=minutes=0;
}

Time::Time(int h, int m)
{
    hours=h;
    minutes=m;
}
void Time::AddHr(int h)
{
   hours+=h;
}
void Time::AddMin(int m)
{
   minutes+=m;
    hours+= minutes/60;
    minutes%=60;  
}
void Time::Reset(int h, int m)
{
    hours=h;
    minutes=m;
}
Time Time::operator+ (const Time & t) const
{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hours=hours+t.hours+sum.minutes;
    sum.minutes %=60;
    return sum;
}
void Time::Show()const
{
    cout<<hours<<" hours"<<minutes<<" minutes"<<endl;
}
int main()
{
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;
    cout<<"planning time = ";
    planning.Show();
    cout<<endl;
    cout<< "coding time = ";
    coding.Show();
    cout<<endl;
    cout<<" fixing time = ";
    fixing.Show();
    cout<<endl;
   // total=coding.operator+(fixing);// cách1 sử dụng toán tử
   total=coding+fixing;// cách 2 sử dụng toán tử
    cout<<" coding + fixing= ";
    total.Show();
    cout<<endl;
    // Time tmp=coding*2;
    // Time tmp1=2*coding;
    // cout<<" coding*2=tmp= "<<tmp<<endl;
    // cout<<" coding*2=tmp1="<<tmp<<endl;

} 
//////////////////////// Khai niệm enumeration//////////////////////////////////////////
// enum eggs{small, medium, large};
// enum T_shirt{small, medium, large};
//=> bọn chúng sẽ bị xung đột
//..=> suy ra khai niệm
