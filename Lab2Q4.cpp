#include <iostream>

using namespace std;

template<typename T,typename U, typename V>
class Box {
  T a;
  U b;
  V c;
 public:
  Box (T a, U b, V c) : a(a), b(b), c(c) {}
  T getA() { return a; }
  U getB() { return b; }
  V getC() { return c; }
};

int main() {
  Box<int,char,string> p1 (1, 'A', "Apple");
  cout << p1.getA() << " " << p1.getB() << " "
       << p1.getC() << endl;
  Box<int,string,char> *p2 = new Box<int,string,char>(2, "Boy", 'B');
  cout << p2->getA() << " " << p2->getB() << " "
       << p2->getC() << endl;
  delete p2;
}
