
#include<iostream>
template<typename Object>
struct Node
{
    Object data;
    Node*  next;
    Node(){};
    Node(const Object& d , Node* n = NULL):data(d),next(n){}
    
};
int main(){
    Node<int>* n1 = new Node<int>(1,NULL);
    std::cout<<n1->data<<std::endl;
}