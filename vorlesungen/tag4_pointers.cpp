//program5 function pointers:
#include <iostream>
using namespace std;

int add(int a, int b) {return a + b;}
int sub(int a, int b) {return a - b;}
int mul(int a, int b) {return a * b;}


//-------- function which get a fucntion pointer ------
int apply(int (*g)(int, int) , int x, int y){
    cout << "apply: calling g(" << x << ", " << y << ")" << endl;
    return g(x,y);
}


int main(){
  int (*f)(int, int); // 1.declare: f can point to any function

  f = add; // f is pointing to add
  cout << f(7,  3) << endl;

  f = mul; // f points to mul
  cout << f(7 , 3) << endl;

  cout << "A function geting an function pointer" << endl;
  

  cout << apply(add, 3, 7) << endl;
  cout << apply(mul, 3 ,7) << endl;

}
