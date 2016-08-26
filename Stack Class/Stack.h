#define STACK_CAPACITY 1000
#include <iostream>

class Stack {
	public:
		Stack() {size = 0;} //Constructor for a stack
		
		void push(char c) {
			if (size == STACK_CAPACITY) {
			std::cout << "Cannot add to array because it is full" << std::endl;
			} else {
				array[size] = c; size++; 
			}
		} //adds c to the top of stack

		char pop() { char removed = array[size-1]; size--; return removed; } //removes top element
		char top() { return array[size-1]; } //returns the top element
		bool isEmpty() { return size == 0; } //returns true iff the stack is empty
		bool isFull() { return size == STACK_CAPACITY; } //returns true iff the stack is full
	
	private: 
		char array[STACK_CAPACITY];
		int size;
};


