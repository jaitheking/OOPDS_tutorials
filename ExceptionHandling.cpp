#include <iostream>

using namespace std;

double divide (double a,double b){
if (b==0)
throw b;
 return a/b;


}

int main(){
    double x,y;
    cin >>x >>y ;
    try {
    double result=divide(x,y);
    cout<<"Result ="<<result;
    return 0;
    }
    catch (double a){
    cout << "Cannot divide by zero \n";
    return -1;

    }


}
