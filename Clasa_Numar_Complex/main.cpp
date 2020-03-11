#include <iostream>
#include <Complex.h>
#include <cmath>
using namespace std;


int main()
{
    /*Complex c1(2,3);
    c1.show();
    Complex c2=c1;
    Complex c3=Complex(3,4);
    c2.show();
    c3.show();
    cout<<"ADUNARI"<<endl;
    Complex c4=c1+c3;
    c4.show();
    double r=3.1;
    Complex c5=r+c1;
    c5.show();
    Complex c6=c1+r;
    c6.show();
    cout<<"SCADERI"<<endl;
    c6=c3-c1;
    c6.show();
    c6=c3-r;
    c6.show();
    c6=r-c3;
    c6.show();*/
    cout<<"INMULTIRI"<<endl;
    Complex c1(3,2);
    Complex c3(4,3);
    Complex c7=c1*c3;
    c7.show();
    cout<<abs(c3);
    Complex c2(-9,0);
    sqrt(c2);
    c2+=c1;
    c2.show();
    c2+=c3;
    c2.show();
    c3/=c1;
    c3.show();
    Complex c4=c1^6;
    c4.show();
    //cout<<c4;
    //c7.show();
    //c7=-c7;
    //c7.show();
    //c3=-c3;
    //c3.show();
    //Complex c2(1,1);
    //c3=c1+c2;
    //c3.show();
    //c1=c1+c1;
    //c1.show();
    //c1+=c2;
    //c1.show();
    //c2.show();
    /*cout<<"IMPARTIRI"<<endl;
    Complex c8;
    Complex c1(4,6);
    Complex c2(5,5);
    c8=c1/c2;
    c8.show();
    c8=c1/2;
    c8.show();
    c8=10/c2;
    c8.show();*/
    //cin.get();
    return 0;

}
