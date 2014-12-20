int main() {
  Rational r1, r2;
  cout << "Input a rational number (num den): ";
  cin >> r1;
  cout << "Input a rational number (num den): ";
  cin >> r2;
  cout << r1 << " + " << r2 << " = " << r1 + r2 << endl;
  cout << r1 << " - " << r2 << " = " << r1 - r2 << endl;

  if (r1 < r2)
    cout << r1 << " is smaller than " << r2 << endl;
  else if (r1 == r2)
    cout << r1 << " is equal to " << r2 << endl;
  else
cout << r1 << " is larger than " << r2 << endl;
  }
