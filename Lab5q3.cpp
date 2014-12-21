#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
  string s; // input as string.
  int n;  // input as int.
  cout << "Enter a positive integer or 0: ";
  cin >> s;

try {
  if (!(istringstream (s) >> n))
   throw s;

  else if (n < 0)
    throw n;
  else {
    long long result = 1;
    for (int i = 1; i <= n; i++)
      result *= i;
    cout << "Factorial(" << n << ") = " << result << endl;
  }
  }

  catch (string s){
            cout << "Error: You input string \"" << s << "\".\n"
                    << "Input must have positive integer or 0 only.\n";
         }
  catch (int n){
        cout << "Error: You input negative integer " << n << ".\n"
         << "Input must have positive integer or 0 only.\n";

  }

}
