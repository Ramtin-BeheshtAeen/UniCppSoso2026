#include <iostream>

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
  //Tree() : left(nullptr), right(nullptr) {cout << "Tree is initialized" <<endl;}
  Tree(Tree* left = nullptr, Tree* right = nullptr) : left (left) , right(right), value(0) {}
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

int main(){
  Tree t(new Tree(new Tree, new Tree), new Tree); //it will be in stack
  cout << t << endl;
}
