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
////////////////////////// Khái niệm ghi đè trong class//////////////////////////////////
////////////////////////// Khái niệm operator trong class///////////////////////////////
////////////////////////// Khái niệm hàm friend trong class/////////////////////////////
//////////////////////// Khai niệm enumeration//////////////////////////////////////////
// enum eggs{small, medium, large};
// enum T_shirt{small, medium, large};
//=> bọn chúng sẽ bị xung đột
//..=> suy ra khai niệm
