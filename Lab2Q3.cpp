
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T find (vector<T>& v, T target) {
  for (T i = 0; i < v.size(); i++)
    if (v[i] == target)
      return i; // Target found at index i.
  return -1; // Target not found.
}
template <typename T>
void print (vector<T>& v) {
  for (T i = 0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
}

int main() {
  int intTarget;
  vector<int> intv;
  intv.push_back (33);
  intv.push_back (55);
  intv.push_back (11);
  print (intv);
  cout << "Enter target: ";
  cin >> intTarget;
  int i = find (intv, intTarget);
  if (i >= 0)
    cout << "Target found at index " << i << ".\n";
  else
    cout << "Target not found.";

  char charTarget;
  vector<char> charv;
  charv.push_back ('C');
  charv.push_back ('A');
  charv.push_back ('B');
  print (charv);
  cout << "Enter target: ";
  cin >> charTarget;
  i = find (charv, charTarget);
  if (i >= 0)
    cout << "Target found at index " << i << ".\n";
  else
    cout << "Target not found.";
}
