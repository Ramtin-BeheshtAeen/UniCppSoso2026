#include <iostream>
#include <utility>

using namespace std;

class Tree{
  // in java we write like that, bc there the variables of class type are references(addresses),so Tree just stores addresses but here we use pointer, and Tree left will embed a whole tree inside a Tree (infiniter size, incompatible size), so it does not compile:
  //when class is reference we can still have them in body although it is not compiled and they have a fixed sizes.
  //Tree left, right;
  Tree* left = nullptr;
  Tree* right = nullptr;
  int value;
  /*   pointer (8 bytes)            the Tree object (4048 bytes)
┌──────────────────┐        ┌───────────────────────────────┐
│ 0x00005581a2b0   │──────▶ │ values[0..999]  ...           │
└──────────────────┘        │ name                          │
                            │ left, right                   │
                            └───────────────────────────────┘
  */
private:
  static void indent(ostream& s,int depth=0) {
    for(int tab = 0; tab < depth; tab++){
      s << "    ";
    }
  }

public:
  //copy constructor:
  //A constructor is a copy constructor if its only parameter is a reference to the same class
  Tree(const Tree &t) : left(nullptr), right(nullptr), value(t.value) {
    cout << "copy constructor!" << endl;
    if (t.left)
      left = new Tree(*t.left);
    if (t.right)
      right = new Tree(*t.right);
  }

  //move:
  Tree(Tree &&t): left(move(t.left)) , right (move(t.right)), value(t.value) {
      t.left = nullptr;   // old object gives up ownership
      t.right = nullptr;
  }
  
  //Tree() : left(nullptr), right(nullptr) {cout << "Tree is initialized" <<endl;}
  Tree(int value = 0, Tree* left = nullptr, Tree* right = nullptr) : left (left) , right(right), value(value) {}
  
  ~Tree(void){
    delete right;
    delete left;
  }
  
  ostream  &draw(ostream &s) const {
   s << '[' << value;
   if( left || right) {
     if(!left)
       s << "[]";
     else
       // punkt is stronger than star:
       //we must derefrencieren
       (*left).draw(s);
       //or using the shortcut: left-> draw;
     s << ',' ;
     if(!right)
       s << "[]";
     else
       // punkt is stronger than star:
       //we must derefrencieren
       right->draw(s);
       //or using the shortcut: left-> draw;
    }
   s << ']';
   return s;
  }
    
  ostream &draw_with_tabs(ostream &s, int depth = 0) const {
    indent(s, depth);
    s << value << endl;
    if(!left){indent(s,depth + 1); s << "." << endl;}
    else left -> draw_with_tabs(s, depth + 1);
    if(!right){indent(s,depth + 1); s << "." << endl;}
    else right -> draw_with_tabs(s, depth + 1);
    return s;
  }
};

ostream &operator<<(ostream &os, const Tree &t){
  return t.draw_with_tabs(os);
}

Tree operator+(const Tree &left, const Tree&right){
  //Tree c(a);   // a is a Tree and c is a copy of a
  return Tree(-1, new Tree(left), new Tree(right));
}

int main(){
  Tree t(42, new Tree(5, new Tree(-17), new Tree(22)), new Tree), q; //it will be in stack
  cout << t + q << endl;

  Tree kombiniert(move(t+q));
  cout << kombiniert << endl;
}
