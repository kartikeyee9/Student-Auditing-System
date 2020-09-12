#ifndef LIST_H
#define LIST_H

#include "Course.h"

template <typename A>
class List
{
public:
	class Node {
	public:
		A data;
		Node* next;
	};

	List() {
		head = nullptr;
		tail = nullptr;
	}



	~List() {
		Node *current = head;
		while(current != nullptr) {
			Node *temp = current->next;
			delete current->data;
			delete current;
			current = temp;
		}
	}


	List& operator+=(A c) {
		Node* newNode = new Node;
		newNode->data = c;
		newNode->next = nullptr;

		if(head == nullptr) {
			head = newNode;
			tail = newNode;
		} else if(!head->data->lessThan(c)) {
			newNode->next = head;
			head = newNode;
		} else {
			Node* prev = head;
			Node* current = head->next;
			while(current!= nullptr && current->data->lessThan(c)) {
				prev = current;
				current = current->next;
			}

			newNode->next = current;
			prev->next = newNode;

			if(newNode->next == nullptr)
				tail = newNode;
		}

		return *this;
	}


	void print() {
		Node* current = head;
	
		while(current!= nullptr) {
			current->data->print();
			current = current->next;
		}

	}

	

protected:
	Node* head;
	Node* tail;

};

class CourseList: public List<Course*> {

public:
	float computeGPA() {
		Node* current = head;

		float sum = 0;
		int count = 0;
		
		while(current!= nullptr) {
			int grade = current->data->getGrade();
			if(grade != -1) {
				sum += grade;
				count++;
			}


			current = current->next;
		}

		return count == 0 ? 0 : sum/count;
	}


	int computeNumFW() {
		Node* current = head;

		int count = 0;
		
		while(current!= nullptr) {
			int grade = current->data->getGrade();
			if(grade == -1 || grade == 0) {
				count++;
			}


			current = current->next;
		}

		return count;
	}
};




#endif
