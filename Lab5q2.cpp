#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Point{
    int x,y;
    public:
    Point(int x=0,int y=0):x(x),y(y){};
    int getX(){ return x;};
    int getY(){return y;};
    friend ostream& operator<< (ostream& os, Point& p);
    friend istream& operator>> (istream& is, Point& p);
    friend bool operator== (Point p1, Point p2);

};
istream& operator>> (istream& is, Point& p){
    is>>p.x>>p.y;
    return is;
}

ostream& operator<< (ostream& os, Point& p){
    os<<"("<<p.getX()<<","<<p.getY()<<")";
    return os;
}
bool operator== (Point p1,Point p2){
    return p1.x==p2.x && p1.y ==p2.y;
}

class SortByXY{
    public:
    bool operator()( Point p1, Point p2)
    {
        if (p1.getX() == p2.getX()){
            return p1.getY()<p2.getY();
        }
        else{
            return p1.getX() < p2.getX();
        }
    }

};

class SortByYX{
    public:
    bool operator()(Point p1,Point p2)
    {
        if (p1.getY() == p2.getY()){
            return p1.getX()<p2.getX();
        }
        else{
            return p1.getY() < p2.getY();
        }
    }

};

int main() {
  vector<Point> v;
  Point p;
  do {
    cout << "Input a Point (0 0 to end): ";
    cin >> p;
    if (p == Point(0,0)) break;
    v.push_back (p);
  } while (true);

  cout << "Sort points by x then y:\n";
  sort (v.begin(), v.end(), SortByXY());
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;

  cout << "Sort points by y then x:\n";
  sort (v.begin(), v.end(), SortByYX());
  for (int i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}
