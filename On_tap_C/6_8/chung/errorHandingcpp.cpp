/////////////////////////////////////Error Handing/////////////////////////////////////////
// Friends-> class friend
/* #include<iostream>
using namespace std;
class Tv
{ 
    public:
    friend class Remote;
    enum  {Off,On};
    enum  {MinVal,MaxVal=20};
    enum  {Antenna, Cable};
    enum  {TV, DVD};
    // Khai bao hàm khởi tạo
    Tv (int s=Off, int mc=125):state(s), volume(5),maxchannel(mc), channel(2), mode(Cable),input(TV){}
    void onoff()
    {
        state=(state==On)?Off:On;        
    }
    bool ison() const { return state==On;}
    bool volup();
    bool voldown();
    void chanup();
    void chandown();
    void set_mode()
    {mode=(mode==Antenna)?Antenna:Cable;}
    void set_input()
    {
        input=(input==TV)?TV:DVD;
    }
    void settings()const;
    private:
    int state; // on or off
    int volume;
    int maxchannel;
    int channel;
    int mode;
    int input;
};
class Remote{
    private:
    int mode;
    public:
    Remote(int m=Tv::TV): mode(m){}
    bool volup(Tv &t){return t.volup();}
    bool voldown(Tv &t){return t.voldown();}
    void onoff(Tv &t){t.onoff();}
    void chanup(Tv&t){t.chanup();}
    void chandown(Tv&t){t.chandown();}
    void set_chan(Tv&t,int c){t.channel=c;}
    void set_mode(Tv&t){t.set_mode();}
    void set_input(Tv&t){t.set_input();}
};
bool Tv::volup()
{
    if(volume<MaxVal)
    {
        volume++;
        return true;
    }
    else
    return false;
}
bool Tv::voldown()
{
    if(volume>MinVal)
    {
        volume--;
        return true;
    }
    else
    return false;
}
void Tv::chanup()
{
    if(channel<maxchannel)
    {
        channel++;
    }
    else
    channel=1;
}
void Tv::chandown()
{
    if(channel>1)
    {
        channel--;
    }
    else
    channel=maxchannel;
}
void Tv::settings()const
{
    cout<<"TV is "<< (state==Off?"Off":"On")<<endl;
    if(state==On)
    {
        cout<<"Volume setting = "<<volume<<endl;
        cout<<"Channel setting = "<<channel<<endl;
        cout<< "mode = "
        <<(mode== Antenna?"antenna":"cable")<<endl;
        cout<<"Input = "
        <<(input==TV?"TV":"DVD")<<endl;
    }
}
int main()
{
    Tv s42;
    cout<<"Initial setting for 42\" TV:\n";
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout<<"\nAdjusted settings for 42\" TV:\n";
    s42.settings();
    Remote grey;
} */
//Friend Member functions

///////////////////////////////////// Exception///////////////////////////////////////////
// Gặp vấn đề khi chạy nhưng vẫn phải tiếp túc.
// Ví dụ mở một file không tồn tại
//Hàm about()
//
// Runtime type identification
// Type Cast Operator