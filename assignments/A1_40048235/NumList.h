#ifndef NUMLIST_H
#define NUMLIST_H

class NumList {
  private:
    int size;
    int capacity;
    int *elements;
    void resize();
    
  public:
    NumList();
    ~NumList();
    explicit NumList(const NumList &);
    void operator=(const NumList &);
    
    bool isEmpty() const;
    bool checkExist(int) const;
    void append(int);
    int getElementAt(int) const;
    void setElementAt(int, int);
    int getSize() const;
    int getCapacity() const;
    const int* getElements() const;
};

#endif
