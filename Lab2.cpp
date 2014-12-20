#include <iostream>
#include <cmath>

using namespace std;

class Point {
  int x;
  int y;
 public:
  Point(int x=0 , int y =0 ):x(x),y(y){};

  void setX (int x);
  void setY (int y);
  int getX();
  int getY();
  double distance (Point& p);
};


void Point::setX(int x){
    this->x = x;
}

void Point::setY(int y){
    this->y = y;
}

int Point::getX(){
    return x;

}

int Point::getY(){
    return y;

}

double Point::distance(Point &p){
    int dx = x - p.x;
    int dy = y - p.y;
    return sqrt (dx*dx + dy*dy);

}

class Triangle {
    Point p[3];
    double perimeter;
    void calcPerimeter();
 public:
    Triangle (Point&, Point&, Point&);
    void set3Points();
    void display();

};
Triangle:: Triangle (Point&, Point&, Point&){


};

void Triangle::calcPerimeter(){
    double d1,d2,d3;
    d1 = p[0].distance(p[1]);
    d2 = p[1].distance(p[2]);
    d3 = p[2].distance(p[0]);
    perimeter = d1+ d2 +d3;
}

void Triangle::set3Points(){
    int x,y;
    for (int i=0;i<3;i++){
    cout<< "\nEnter a point: ";
    cin >>x>>y;
    p[i].setX(x);
    p[i].setY(y);


    }
    calcPerimeter();
}
void Triangle::display(){
    cout<<"Points:";
    for (int i=0; i<3;i++){
    cout<<"("<<p[i].getX()<<","<<p[i].getY()<<")";
    }
    cout<<"\nPerimeter:"<<perimeter;

    }


int main() {
  Point p[] = { Point(), Point(1), Point(2,3) };
  for (int i = 0; i < 3; i++)
    cout << "(" << p[i].getX() << "," << p[i].getY() << ")\n";

  cout << "\nTriangle ";
  Triangle t;
  t.display();
}
