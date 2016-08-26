#ifndef PICTURE_H_
#define PICTURE_H_
#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"
using namespace std;

class ListNode
{
public:
	Shape *shape;

	ListNode *next;

	ListNode();

	ListNode(Shape *newShape, ListNode *newNext)
		: shape(newShape), next(newNext) {}

	~ListNode(){}
};

class Picture
{
public:
	Picture() {
		head = NULL;
	}

	void add(Shape *sp) {
		head = new ListNode(sp, head);
	}
//		ListNode obj(sp, NULL);
//		if (head == NULL) {
//			head = &obj;
//			cout << head << endl;
//			return;
//		}
//		ListNode *temp = head;
//		while (temp->next != NULL) {
//			temp = temp->next;
//			cout << temp <<endl;
//		}
//		temp->next = &obj;
//		cout << &obj <<endl;

	void drawAll(){
		ListNode *temp = head;
		while(temp->next != NULL) {
			temp->shape->draw();
			temp = temp->next;
		}
			temp->shape->draw();
	}

	double totalArea() {
		double total = 0;
		ListNode *temp = head;
		while(temp->next != NULL) {
			total += temp->shape->area();
			temp = temp->next;
		}
		total += temp->shape->area();
		return total;
	}
//		double total = 0;
//		ListNode *temp = head;
//		cout << "HERE:" << head->shape->area()<< endl;
//		head = head->next;
//		cout << head->shape->area()<< endl;
//		cout << "HERE:" << temp->shape->area()<< endl;
//		while (temp->next != NULL) {
//			cout << "HERE:" << temp->shape->area()<< endl;
//			total += temp->shape->area();
//			temp = temp->next;
//		}
//		total += temp->shape->area();
//		return total;
//	}

	~Picture() {
		ListNode *temp;
		ListNode *traverse = head;
		while (traverse != NULL) {
			temp = traverse;
			traverse = traverse->next;
			delete temp;
		}
	}

private:
	ListNode *head;
};


#endif /* PICTURE_H_ */
