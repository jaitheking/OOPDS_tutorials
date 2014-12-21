#include <iostream>

using namespace std;

class Rational {
        int num,den;
        public:
        Rational(int num=0, int den=1):num(num),den(den){};
        int getnum(){ return num; };
        int getden(){ return den; };
        void print(){
        cout << num<<"/"<<den<<endl;
        }
        friend istream& operator>>(istream& is, Rational& r);
        friend ostream& operator<<(ostream& os, Rational& r);
        friend Rational operator+ (Rational&, Rational&);
        friend Rational operator- (Rational&, Rational&);
        friend bool operator==(Rational& r1, Rational& r2);
        friend bool operator<(Rational& r1, Rational& r2);

};

istream& operator>> (istream& is, Rational& r) {
    is>>r.num>>r.den;
    return is;

}

ostream& operator<< (ostream& os, Rational& r){
    os << r.getnum() <<"/"<<r.getden();
    return os;

}

Rational operator+ (Rational& r1, Rational& r2){
    int n = (r1.num*r2.den) + (r2.num*r1.den);
    int d = r1.den * r2.den;
    return Rational (n,d);

}

Rational operator- (Rational& r1, Rational& r2){
    int n= (r1.num*r2.den) - (r2.num*r1.den);
    int d= r1.den * r2.den;
    return Rational(n,d);

}

bool operator==(Rational& r1, Rational& r2){
    return r1.num*r2.den == r2.num*r1.den;

}

bool operator<(Rational& r1, Rational& r2){
    return r1.num*r2.den < r2.num*r1.den;

}


int main() {
  Rational r1, r2,r3,r4;
  cout << "Input a rational number (num den): ";
  cin >> r1;
  cout << "Input a rational number (num den): ";
  cin >> r2;
  r3 = r1 +r2;
  cout << r1<< " - " << r2<< " = " << r3 << endl;
  r4 = r1 - r2;
  cout << r1<< " - " << r2<< " = " << r4 << endl;

  if (r1 < r2)
    cout << r1 << " is smaller than " << r2 << endl;
  else if (r1 == r2)
    cout << r1 << " is equal to " << r2 << endl;
  else
cout << r1 << " is larger than " << r2 << endl;
  }
