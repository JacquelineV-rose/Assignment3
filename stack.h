//Jacqueline Vermette

#ifndef STACK_H
#define STACK_H




#include <iostream>
#include <vector>


namespace cop4530{

template <typename T>

class Stack{


public: 
//constuctors
Stack();
~Stack();

Stack(const Stack<T>&);

Stack(Stack<T>&&);

Stack<T>& operator=(const Stack<T>&);

Stack<T>& operator=(Stack<T>&&);


bool empty() const;

void clear();

void push(const T& x);

void push(T && x);

void pop();

T& top();

const T& top() const;

int size() const;

void print(std::ostream& os, char ofc = ' ') const;


std::vector<T> getVector() const;


private:


std::vector<T> v;





};



template <typename T>
std::ostream & operator<<(std::ostream & os, const Stack<T> & a);  

template <typename T>
bool operator==(const Stack<T> & a, const Stack<T> & b); 

template <typename T>
bool operator!=(const Stack<T> & a, const Stack<T> & b); 

template <typename T>
bool operator<=(const Stack<T> & a, const Stack<T> & b);




#include "stack.hpp"





}

#endif
