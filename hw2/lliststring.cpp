#include "lliststring.h"
#include <cstdlib>
#include <stdexcept> // See the comment directly below.
#include <iostream>

using namespace std;
/**
 * This implementation uses exceptions in both versions of 'get'. 
 * You do not need to change the if-statements that use exceptions, 
 * nor do you need to test for exceptions. 
 *
 * In case you are interested, you can find more information here:
 * http://www.cplusplus.com/doc/tutorial/exceptions/
 * 
 * We will cover exceptions later this semester. 
 */

LListString::LListString()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

LListString::~LListString()
{
  clear();
}

bool LListString::empty() const
{
  return (size_ == 0);
}

int LListString::size() const
{
  return size_;
}

void LListString::insert(int pos, const string& val) ///ADD BACK std::string& val
{
  if(pos<0 || pos>size()){
    return;
  }
  Item* newItem = new Item;
  newItem->val = val;
  cout<<"inside insert"<<endl;
  if(size_ == 0)
  {
    head_ = newItem;
    tail_ = newItem;
  }
  else if(pos==0){
    newItem->next = head_;
    head_ = newItem;
    newItem->prev = NULL;
    newItem->next->prev = newItem;
  }
  else if(pos==size()){
    newItem->prev = tail_;
    newItem->prev->next = newItem;
    tail_ = newItem;
    newItem->next = NULL;
  }
  else{
    Item* prevNode =getNodeAt(pos-1);
    Item* nextNode = getNodeAt(pos);
    newItem->next = nextNode;
    newItem->prev = prevNode;
    prevNode->next = newItem;
    nextNode->prev = newItem;
  }
  cout<<"size is: "<<size_<<endl;
  size_++;
  /*if(size_ == 1)
  {
    newItem->prev = tail_;
    newItem->prev->next = newItem;
    newItem -> next = NULL;
    tail_ = newItem;
  }*/
}

void LListString::remove(int pos)
{
  // TODO: complete the remove function.
  Item* curr = getNodeAt(pos);
  if(size_==0){
    return;
  }
  if(size_==1){
    head_ = NULL;
    tail_ = NULL;
    delete curr;
  }
  if(pos==0){
    head_ = getNodeAt(pos+1);
    getNodeAt(pos+1)->prev = NULL;
    delete curr;
  }
  if(pos==size()){
    tail_ = getNodeAt(pos-1);
    getNodeAt(pos-1)->next = NULL;
    delete curr;
  }
  getNodeAt(pos-1)->next = getNodeAt(pos+1);
  getNodeAt(pos-1)->next->prev = getNodeAt(pos-1);
  delete curr;

}

void LListString::set(int pos, const std::string& val)
{
  if(pos >= 0 && pos < size_) {
  	Item *temp = getNodeAt(pos);
    temp->val = val;	
  }
}

std::string& LListString::get(int pos)
{
  if(pos < 0 || pos >= size_) {
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(pos);
  return temp->val;
}

std::string const & LListString::get(int pos) const
{
  if(pos < 0 || pos >= size_) {
    throw std::invalid_argument("bad location");
  }
  Item *temp = getNodeAt(pos);
  return temp->val;
}

void LListString::clear()
{
  while(head_ != NULL) {
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}

LListString::Item* LListString::getNodeAt(int pos) const
{
  // TODO: complete the getNodeAt function.
  if(pos<0 || pos>size()){
    return NULL;
  }
  if (head_ == NULL){
    return NULL;
  }
    int counter = 0;
    Item* curr;
    curr = head_;
    while(curr!=NULL){
      if(counter == pos){
        break;
      }
      counter++;
      curr = curr->next;
    }
  return curr; 
}

int main()
{
    LListString* list = new LListString();
   std::cout<<"here"<<std::endl;

   if (list->empty()) {
    cout << "SUCCESS: List is empty initially." << endl;
  } else {
    cout << "FAIL: List is not empty initially when it should be." << endl;
  }

// Insert an item at the head.
  list->insert(0, "Gandalf");
  //list->insert(1, "Devin");

  // Check if the list is still empty.
  if (!list->empty()) {
    cout << "SUCCESS: List is not empty after one insertion." << endl;
  } else {
    cout << "FAIL: List is empty after one insertion." << endl;
  }

 if (list->size() == 1) {
    cout << "SUCCESS: List has size 1 after one insertion." << endl;
  } else {
    cout << "FAIL: List has size " << list->size() << " after one insertion.";
    cout << endl;
  }

  // Check if the value is correct.
  if (list->get(0) == "Gandalf") {
    cout << "SUCCESS: 3 is at the 0th index of the list." << endl;
  } else {
    cout << "FAIL: 3 is not at the 0th index of the list, " << list->get(0);
    cout << " is instead." << endl;
  }

  // TODO: Continue adding tests for your program, or start your own file with your
  // own tests. Remember to submit a file that is named correctly!

  // Clean up memory.
  delete list;
  return 0;
}