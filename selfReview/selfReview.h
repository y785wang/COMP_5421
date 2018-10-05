#ifndef T_H
#define T_H



class Node {
  public:
    int key;
    Node* left;
    Node* right;
    Node(int, Node *, Node *);
    ~Node();
};

class Foo {
  public:
    Foo();
    Foo(int x);
    Foo(char *c);
    Foo(const Foo &);
    Foo& operator=(const Foo &);
    Foo& operator=(const int);
};

class Vec {
  private:
    int *elements;
    int dim;
  public:
    explicit Vec(int = 5);
    
};

#endif
