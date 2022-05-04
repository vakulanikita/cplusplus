#include "list.h"
#include <iostream>
#include <string>
using namespace std;

element::element(double v)
{
  value = v;
  next = nullptr;
  prev = nullptr;
}

element::element(const element& other)
{
  value = other.value;
  next = other.next;
  prev = other.prev;
}

void element::print()
{
  cout << value << endl;
}

list::list()
{
  head = nullptr;
  tail = nullptr;
}

bool list::empty()
{
  return head == nullptr; // 1 - да, пустой
}

int list::get_size()
{
  return size;
}

bool list::check_range(int index, string source)
{
  if(index > (size - 1) || index < 0) {
    cout << source <<  "() ошибка: индекс " << index << " выходит за пределы списка" << endl;
    return 1;
  }
  return 0;
}

element* list::search_pointer(int index)
{
  if (empty()) return nullptr;
  element* p = head;
  int counter = 0;
  while (p) {
    if(counter == index) {
      return p;
    }
    counter++;
    p = p->next;
  }
}

void list::push_back(const element& elem)
{
  element* p = new element(elem);
  size++;
  
  if (empty()) {
    head = p;
    tail = p;
    // cout << head << " " << tail << endl;
    return;
  }
  // лист с элементами
  tail->next = p;
  p->prev = tail;
  tail = p;
}

void list::push_front(const element& elem)
{
  element* p = new element(elem);
  size++;
  
  if (empty()) {
    head = p;
    tail = p;
    return;
  }
  // лист с элементами
  head->prev = p;
  p->next = head;
  head = p;
}

void list::insert(int index, const element& elem)
{
  if(check_range(index, "insert")) {
    return;
  }
  
  if(index == 0) {
    push_front(*(new element(elem)));
    return;
  }
  
  element* p = search_pointer(index);
  element* newNode = new element(elem);
  element* prev = p->prev;
  
  prev->next = newNode;
  newNode->prev = prev;
  newNode->next = p;
  p->prev = newNode;
  size++;
}

void list::pop_back()
{
  if (empty()) return;
  
  element* p = tail;
  tail = p->prev;
  tail->next = nullptr;
  size--;
}

void list::pop_front()
{
  if (empty()) return;
  
  element* p = head;
  head = p->next;
  head->prev = nullptr;
  size--;
}

void list::erase(int index)
{
  if (empty()) return;
  if(check_range(index, "erase"))
  {
    return;
  }
  
  element* p = search_pointer(index);
  
  if(index == 0) {
    pop_front();
    return;
  }
  if(index == (size - 1)) {
    pop_back();
    return;
  }
  
  size--;
  element* prev = p->prev;
  element* next = p->next;
  
  prev->next = next;
  next->prev = prev;
}

void list::print()
{
  if (empty()) return;
  element* p = head;
  int counter = 0;
  cout << "№\t" << "value\t" << "p\t\t" << "prev\t\t" << "next" << endl;
  while (p) {
    cout << counter << "\t" << p->value << "\t" << p << "\t" << p->prev << "\t" << p->next << endl;
    p = p->next;
    counter++;
  }
  // cout << endl;
}

void list::inverted_print()
{
  if (empty()) return;
  element* p = tail;
  int counter = 0;
  cout << "№\t" << "value\t" << "p\t\t" << "prev\t\t" << "next" << endl;
  while (p) {
    cout << counter << "\t" << p->value << "\t" << p << "\t" << p->prev << "\t" << p->next << endl;
    p = p->prev;
    counter++;
  }
}

void list::swap(int indexA, int indexB)
{
  element* p1 = search_pointer(indexA < indexB ? indexA : indexB);
  element* p2 = search_pointer(indexA < indexB ? indexB : indexA);
  
  if(indexA < indexB) {
    erase(indexA);
    insert(indexA, p2->value);
    
    erase(indexB);
    if(indexB == size) {
      push_back(p1->value);
    } else {
      insert(indexB, p1->value);
    }
  } else {
    erase(indexA);
    if(indexA == size) {
      push_back(p1->value);
    } else {
      insert(indexA, p1->value);
    }
    
    erase(indexB);
    insert(indexB, p2->value);
  }
}

int main () {
  // element Node(5);
  // Node.print();
  
  list List;
  List.push_back(1);
  List.push_back(2);
  List.push_back(3);
  List.push_front(0);
  // List.insert(2, 7);
  // cout << List.get_size() << endl;
  // List.pop_front();
  // List.pop_back();
  // List.erase(2);
  List.swap(0, 3);
  
  List.print();
  
  
  return 0;
}