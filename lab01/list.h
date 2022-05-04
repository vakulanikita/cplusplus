#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <string.h>
using namespace std;

class element
{
	private:
  public:
    double value;
    element *next;
    element *prev;
    element(double v = 0); 						//конструктор
  	element(const element& other); 		//конструктор копирования
  	void print(); 										//вывести значение элемента
};

class list
{
	private:
		element *head; 																//указатель на начало списка
		element *tail;                                //указатель на конец списка
	public:
		int size = 0;
		bool empty();
		int get_size();
		bool check_range(int index, string source);
		element* search_pointer(int index);
    list(); 																			//конструктор
    void push_back(const element& elem); 					//добавить новый элемент в конец списка
		void push_front(const element& elem); 				//добавить новый элемент в начало списка
		void insert(int index, const element& elem); 	//добавить новый элемент после элемента с индексом index
		void pop_back(); 															//удалить элемент с конца списка
		void pop_front(); 														//удалить элемент с начала списка
		void erase(int index); 												//удалить элемент с индексом index
    void swap(int indexA, int indexB); 						//поменять местами два элемента с индесами indexA и indexB
		void print(); 																//вывести список в прямом порядке
		void inverted_print(); 												//вывести список в обратном порядке
};

#endif