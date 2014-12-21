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
struct Node {
  T info;
  Node<T> *next;
};

template <typename T>
void print (Node<T> *start) {
  if (start == NULL) {        // cout a meesage if the list is empty.
cout << "List is empty.\n";
return;
  }
  Node<T> *ptr = start;
  while (ptr != NULL) {       // while not at the end of list.
    cout << ptr->info << " "; // cout the current node’s info.
    ptr = ptr->next;          // move to next node.
  }
  cout << endl;
}

template <typename T>
void insertFront (Node<T>*& start, T element)
{
    Node<T>* ptr = new Node<T>;
    ptr->info = element;
    ptr->next = start;
    start = ptr;

}

template <typename T>
void insertBack (Node<T>*& start, T element){
    Node<T>* ptr = new Node<T>;
    ptr->info = element;
    ptr->next =NULL;
    if (start!=NULL){
        Node<T>* current = start;
        while(current->next !=NULL)
            current = current->next;
        current->next=ptr;
    }
    else {
        start = ptr;
    }
}

template <typename T>
void removeFront (Node<T>*& start)
{
    if(start !=NULL){
     Node<T> *ptr = start;
     start = start->next;
     delete ptr;

    }
    else{
        cout <<"List is empty."<<endl;
    }
}

template <typename T>
void removeBack (Node<T>*& start){
    if(start !=NULL){
        Node<T> *ptr = start;

        while(ptr->next->next !=NULL)
            ptr=ptr->next;
        Node<T> *ptr2 = ptr->next;
        ptr->next=NULL;
        delete ptr2;
    }
    else {

        cout<<"List is empty";
    }




}


int main() {
  int seed = 0;         // seed for automatic value of x and y.
  Node<Point> *start = NULL;
  int choice; // user choice.
  Point newPoint;
  do {
    print(start);
    cout << "Choice:\n"
         << "1: Insert new point at the front\n"
         << "2: Insert new point at the back\n"
         << "3: Remove point at the front\n"
         << "4: Remove point at the back\n"
         << "Others: Exit\n";
    cin >> choice;
    switch (choice) {
      case 1 : newPoint = Point(++seed);
               insertFront(start, newPoint);
               break;

      case 2 : newPoint = Point(++seed);
               insertBack(start, newPoint);
               break;
      case 3 : removeFront(start);
               break;
      case 4 : removeBack(start);
               break;
    }
  } while (choice >= 1 && choice <= 4);
  // Add codes.
}
