#include <iostream>
#include <string>
using namespace std;

class Point {
  int x;
  int y;
 public:
  Point(int seed = 0) : x(seed), y(seed) {
    cout << "Overloaded constructor called.\n";
  }
  ~Point() { cout << "Destructor called.\n"; }
  int getX() { return x; }
  int getY() { return y; }
};

ostream& operator<< (ostream& os, Point& p) {
  os << "(" << p.getX() << "," << p.getY() << ")";
  return os;
}

template <typename T>
void print (T *array, int size) {
  if (size == 0) {
cout << "Array is empty.\n";
return;
  }
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}
template <typename T>
void insertFront(T* &array, int &size, T newElement){
    Point* new_array = new T[size +1];
    for (int i=0;i <size;i++)
        new_array[i+1] = array[i];
    new_array[0] = newElement;
    size++;
    array = new_array;

}

template <typename T>
void insertBack(T* &array, int &size, T new_element)
{
T* new_array = new T[size + 1];
for (int i = 0; i < size; i++)
new_array[i] = array[i];
new_array[size] = new_element;
size++;
delete [] array;
array = new_array;
}
template <typename T>
void removeFront(T* array, int &size)
{
T* new_array = new T[size - 1];
for (int i = 0; i < size - 1; i++)
new_array[i] = array[i + 1];
size--;
array = new_array;
}
template <typename T>
void removeBack(T* array, int &size)
{
T* new_array = new T[size - 1];
for (int i = 0; i < size - 1; i++)
new_array[i] = array[i];
size--;
array = new_array;
}

int main() {
  int seed = 0;         // seed for automatic value of x and y.
  int size = 0;         // array size.
  Point *points = NULL; // dynamic array.
  int choice; // user choice.
  Point newPoint;
  do {
    print (points, size);
    cout << "Choice:\n"
         << "1: Insert new point at the front\n"
         << "2: Insert new point at the back\n"
         << "3: Remove point at the front\n"
         << "4: Remove point at the back\n"
         << "Others: Exit\n";
    cin >> choice;
    switch (choice) {
      case 1 : newPoint = Point(++seed);
               insertFront (points, size, newPoint); break;
      case 2 : newPoint = Point(++seed);
               insertBack (points, size, newPoint); break;
      case 3 : removeFront (points, size); break;
      case 4 : removeBack (points, size); break;
    }
  } while (choice >= 1 && choice <= 4);
  print (points, size);
  if (size > 0)
    delete [] points;
}
