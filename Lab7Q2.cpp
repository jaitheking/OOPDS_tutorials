//#include <iostream>
//#include <vector>
//
//
//using namespace std;
//
//
//
//int main (){
//
//vector<int> t;
//for (int i=1;i<=20;i++){
//
//    t.push_back(i);
//    cout<<"This is the size of the vector,T :"<<t.size()<<endl;
//    cout<<"This is the capacity of the vector,T :"<<t.capacity()<<endl;
//
//}
//cout<<"+++++++++++++++++++++++++++++++++++++++++++++"<<endl;
//
//for (int j=0;j<=19;j++){
//
//    t.pop_back();
//    cout<<"This is the size of the vector,T :"<<t.size()<<endl;
//    cout<<"This is the capacity of the vector,T :"<<t.capacity()<<endl;
//
//}
//
//return 0;
//}

//Question 1
/*
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // system("PAUSE");
using namespace std;

int main() {
  vector<int> v1;
  cout << "Adding 20 items to vector.\n";
  cout << "vector automatically doubles the capacity of its internal dynamic array when it is full.\n";
  cout << "Size\tCapacity\n";
  cout << v1.size() << "\t" << v1.capacity() << endl;
  for (int i = 0; i < 20; i++) {
    v1.push_back (i);
    cout << v1.size() << "\t" << v1.capacity() << endl;
  }

  system("PAUSE");

  cout << "Removing the items in vector.\n";
  cout << "vector never automatically reduces its array capacity.\n";
  cout << "Size\tCapacity\n";
  while (!v1.empty()) {
    v1.erase (v1.begin());
    cout << v1.size() << "\t" << v1.capacity() << endl;
  }
}
*/
//Question 2

#include <iostream>
#include <string>
using namespace std;

class Point {
  int x;
  int y;
 public:
  Point (int x = 0, int y = 0) : x(x), y(y) {}
  friend ostream& operator<< (ostream& os, Point& p) {

    os<<"("<<p.x<<","<<p.y<<")";
    return os;

  }
  friend istream& operator>> (istream& is, Point& p) {
    cout << "Input x y: ";
   is>>p.x>>p.y;
   return is;
  }
  friend bool operator== (Point& left, Point& right) {
     return (left.x == right.x && left.y == right.y);
}
};

template <typename T>
struct Node {
  T info;
  Node<T> *next;
};

template <typename T>
class LinkedList {
  Node<T> *start;
public:
  LinkedList() {
    start = NULL;
  }

  ~LinkedList() {
    makeEmpty();
  }

  void insertFront (T& newElement) {

    Node <T> *newNode = new Node <T>;
    newNode->info = newElement;
    newNode->next = start;
    start = newNode;
  }

  void insertBack (T& newElement) {
   Node <T> *newNode = new Node <T>;
   newNode->info = newElement;
   newNode->next=NULL;
   if (start==NULL)
   start=newNode;

   else {
   Node <T> *ptr = start;
   while(ptr->next != NULL)
   ptr = ptr->next;
   ptr->next = newNode;

    }

  }

  bool insertAfter (T& target, T& newElement) {
        Node<T> *ptr= start;
        while (ptr!=NULL){

        if (ptr->info ==target){
        Node<T> *newNode = new Node <T>;
        newNode->info=newElement;
        newNode->next=ptr->next;
        ptr->next =newNode;
        return true;

        }
        ptr= ptr->next;
        }
    }
  bool search (T& target) {
    Node <T> *ptr = start;
    while(ptr->next !=NULL){
    ptr->next;
    if (ptr->info==target)
    return true;
     ptr= ptr->next;
    }
    return false;
  }

  void makeEmpty () {
     while (start!=NULL){
    Node <T> *ptr = start;
       start=start->next;
       delete ptr;
     }

  }

  friend ostream& operator<< (ostream& os, LinkedList<T>& list) {
    os<<"start ---> ";
    Node <T> *ptr = list.start;
    while (ptr != NULL){
    os << ptr->info<<"--->";
    ptr = ptr->next;
    }
    os <<" NULL";

  return os;
  }
};

int main() {
  int seed = 0;         // seed for automatic value of x and y.
  LinkedList<Point> list;
  int choice; // user choice.
  bool found;
  Point newPoint, target;
  do {
    cout << "Choice:\n"
         << "1: Display points\n"
         << "2: Insert new point at the front\n"
         << "3: Insert new point at the end\n"
         << "4: Insert new point after a target\n"
         << "5: Search a point\n"
         << "6: Empty the list\n"
         << "Others: Exit\n";
    cin >> choice;
    switch (choice) {
      case 1 : cout << list << endl;
               break;
      case 2 : newPoint = Point(++seed, seed);
               list.insertFront (newPoint);
               break;
      case 3 : newPoint = Point(++seed, seed);
               list.insertBack (newPoint);
               break;
      case 4 : cin >> target;
               newPoint = Point(++seed, seed);
               found = list.insertAfter (target, newPoint);
               if (!found) cout << "Target not found\n";
               break;
      case 5 : cin >> target;
               found = list.search (target);
               if (!found) cout << "Target not found\n";
               else       cout << "Target found\n";
               break;
      case 6 : list.makeEmpty();
               cout << "List is emptied\n\n";
               break;
    }
  } while (choice >= 1 && choice <= 6);
}

