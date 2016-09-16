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
    cout<<"invalid_argument"<<endl;
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
  //cout<<"size is: "<<size_<<endl;
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
  cout<<"inside remove"<<endl;
  Item* curr = getNodeAt(pos);
  if(size_==0){
    cout<<"invalid_argument"<<endl;
    return;
  }
  if(pos>=size()){
    cout<<"invalid_argument"<<endl;
    return;
  }
  if(size_==1){
    head_ = NULL;
    tail_ = NULL;
    delete curr;
    size_--;
    return;
  }
  else if(pos==0){
    cout<<"position = 0"<<endl;
    head_ = curr->next;
     //head_ = curr+1;
    //getNodeAt(pos+1)->prev = NULL;
     head_->prev = NULL;
    delete curr;
    cout<<"did i delete curr in pos==0??"<<endl;
  }
  else if(pos==size()-1){
    tail_ = getNodeAt(pos-1);
    getNodeAt(pos-1)->next = NULL;
    delete curr;
  }
  else{
  getNodeAt(pos-1)->next = getNodeAt(pos+1);
  getNodeAt(pos-1)->next->prev = getNodeAt(pos-1);
  delete curr;
  }
  size_--;
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
    cout<<"invalid_argument"<<endl;
    return NULL;
  }
  if (head_ == NULL){
    cout<<"invalid_argument"<<endl;
    return NULL;
  }
  if(tail_ == NULL){
    cout<<"invalid_argument"<<endl;
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
