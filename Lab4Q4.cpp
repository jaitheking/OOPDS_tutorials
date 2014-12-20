#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class Shape {
 protected:
  double perimeter;
  virtual void calcPerimeter() = 0;
 public:
  Shape() : perimeter(0) {}
  virtual void display()  = 0;
};

class Point : public Shape {
  int x;
  int y;
 public:
  Point(int x = 0, int y = 0) : x(x), y(y) {}
  int getX()  { return x; }
  int getY()  { return y; }
  double distance ( Point& p)  {
    int dx = x - p.x;
    int dy = y - p.y;
    return sqrt (dx*dx + dy*dy);
  }
  virtual void calcPerimeter() { perimeter = 0; }
  void print()  { cout << "(" << x << "," << y << ")"<<endl; }
  virtual void display()  {
    cout << "Point:\n";
    cout << "(" << x << "," << y << ")\n";
    cout << "Perimeter = " << perimeter << endl;
  }
};

class Circle : public Shape {
  Point center;
  double radius;
 public:
 virtual void calcPerimeter(){
    double pi = 3.14;
    perimeter = 2* pi * radius;
    };
 virtual void display()  {
    cout << "Circle:\n";
    center.print();
    cout << "Radius = "<<radius<<endl;
    cout << "Perimeter = " << perimeter << endl;
  };
  Circle(const Point& center, double radius)
  : center(center), radius(radius) {
    calcPerimeter();
  }

};

class Triangle : public Shape {
  Point points[3];
 public:
 virtual void calcPerimeter(){
    double d1, d2, d3;
    d1 = points[0].distance(points[1]);
    d2 = points[1].distance(points[2]);
    d3 = points[2].distance(points[0]);
    perimeter = d1 + d2 + d3;

 };
 virtual void display()  {
    cout << "Triangle:\n";
    points[0].print();
    points[1].print();
    points[2].print();
    cout << "Perimeter = " << perimeter << endl;
  }
  Triangle( const Point& p1,  const Point& p2,  const Point& p3) {
    points[0] = p1;
    points[1] = p2;
    points[2] = p3;
    calcPerimeter();
  }

};

void showShape(Shape& s) {
  cout << "Showing ";
  s.display();
}

int main() {
  Point p(1,1);
  Circle c(Point(1,1), 10); // radius = 10.
  Triangle t(Point(0,0), Point(3,0), Point(3,4));
  showShape(p);
  showShape(c);
  showShape(t);
//For looping multiple shapes
//  Shape *s[] = { new Point(1,1),
//                new Circle(Point(1,1), 10),
//                new Triangle(Point(0,0), Point(3,0), Point(3,4))};
//  for (int i = 0; i < 3; i++) {
//s[i]->display();
//  }
}

