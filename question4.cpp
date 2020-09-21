#include <iostream>
#include <time.h>
#include <chrono>

// Node class for Linked List class
class Node{
public:
  int val;

  Node* next = nullptr;
  Node(int num):val(num){}
};

// Class to handle linked list
class LinkedList{
private:
  int size = 0;
public:
  Node* head = nullptr;
  Node* tail = nullptr;

  // Add to linked list from the front of the list
  void addFront(int val){
    Node* temp = new Node(val);
    if(head == nullptr){
      head = temp;
      tail = temp;
    }else{
      temp->next = head;
      head = temp;
    }
  }
  // Add to linked list from the back of the list
  void addBack(int val){
    if(head == nullptr){
      addFront(val);
    }else{
      Node* temp = new Node(val);
      tail->next = temp;
      tail = temp;
    }
  }
  // Print linked list to console
  void printLL(){
    Node* current = head;
    while(current != nullptr){
      std::cout << current->val << " ";
      current = current->next;
    }
    std::cout << std::endl;
  }
};
// Bubble sort linked list
void BubSortList(LinkedList& list){
  Node* current;
  bool sorted = false;
  while(sorted != true){
    current = list.head;
    sorted = true;
    while(current->next != nullptr){
      if(current->val > current->next->val){
        int temp = current->next->val;
        current->next->val = current->val;
        current->val = temp;
        sorted = false;
      }
      current = current->next;
    }
  }
}
// Bubble sort Array
void BubSortArray(int* array, int size){
  bool sorted = false;
  while(sorted != true){
    sorted = true;
    for(int i=0;i<size-1;i++){
      if(*(array+i) > *(array+i+1)){
        int temp = *(array+i);
        *(array+i) = *(array+i+1);
        *(array+i+1) = temp;
        sorted = false;
      }
    }
  }
}
// Print Array to console
void printArray(int* array, int size){
  for(int i=0;i<size;i++){
    std::cout << *(array+i) << " ";
  }
  std::cout << std::endl;
}


int main(){
  // Variables needed to populate array and/or linked list
  srand(time(NULL));
  int size = 10000;
  // Array to be filled
  int* array = new int[size];
  LinkedList list;
  // Fill array and linked list with random numbers
  for(int i =0;i<size;i++){
    *(array+i) = rand() % size+1;
    list.addBack(rand() % size+1);
  }


  //list.printLL();
  std::cout << std::endl;
  // Time linked list bubble sort
  auto begin = std::chrono::steady_clock::now();
  BubSortList(list);
  auto end = std::chrono::steady_clock::now();
  auto length = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  std::cout << length << std::endl;
  std::cout << std::endl;

  //list.printLL();
  std::cout << std::endl;

  //printArray(array, size);
  std::cout << std::endl;
  // Time array bubble sort
  begin = std::chrono::steady_clock::now();
  BubSortArray(array,size);
  end = std::chrono::steady_clock::now();
  length = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count();
  std::cout << length << std::endl;
  std::cout << std::endl;

  //printArray(array, size);
  std::cout << std::endl;

  return 0;
}
