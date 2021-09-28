#pragma once
template<typename Object>
struct Node
{
    Object data;
    Node*  next;
    Node(){};
    Node(const Object& d , Node* n = NULL):data(d),next(n){}
    
};

template<typename Object>
class List{
private:
    int size;
    Node* head;
    void init();
public:
    class const_iterator{

    };
    class iterator:public const_iterator{

    };
    List();
    List(const List& rhs);
    List& operator=(const List& rhs);
    ~List();

    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const ;

    Object& first();
    const Object& front() const;
    Object& back();
    const Object& back() const;

    void push_front(const Object& x);
    void push_front(Object&& x);
    void push_back(const Object& x);
    void push_back(Object&& x);
    void pop_front();
    void pop_back();

    iterator insert(iterator itr, const Object& x)
    
    int size() const ;

    bool isEmpty() const;

    void clear;
    

};
