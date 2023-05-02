//Adrian Mysliwiec
//3/29/23
//CardShop.cpp
//Project 5: The Next King of Sorting!

#include "CardShop.hpp"
#include "Node.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


/**
  @pre  : the input file is in csv format: "name,type,level_rank,race,attribute,atk,def"
  @param: the name of the input file
  @post:  Reads the input file and adds pointers to YGOCard objects 
          instantiated with the information read from the file. 
    */
CardShop::CardShop(std::string input_file_name) 
{
  std::ifstream fin(input_file_name);
  if (fin.fail())
  {
    std::cerr << "File cannot be opened for reading. \n";
    exit(1); // exit if failed to open the file
  }
  //we don't use the first line
  std::string ignore;
  getline(fin, ignore);

  //the columns of the csv associated with the data members
  std::string name, type, race, attribute;
  int level_rank, atk, def;

  std::string temp_string;
  int temp_int;
  int item_counter = 0;
  while (getline(fin, temp_string, ','))
  {
    name = temp_string;

    getline(fin, type, ',');
  
    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    level_rank = temp_int;

    getline(fin, race, ',');

    getline(fin, attribute, ',');

    getline(fin, temp_string, ',');
    std::istringstream(temp_string) >> temp_int;
    atk = temp_int;

    getline(fin, temp_string);
    std::istringstream(temp_string) >> temp_int;
    def = temp_int;

    //create new card
    YGOCard *card_ptr = new YGOCard(name, type, level_rank, race, attribute, atk, def);

    //add to linked list and increment counter
    insert(item_counter++, card_ptr);
  }
}

//@post: removes all cards from the shop
//Deallocate and delete items
void CardShop::clear()
{
  for (int i = 0; i < item_count_; i++)
  {
    YGOCard *ptr = getItem(i);
    delete ptr;
    ptr = nullptr;
  }
  DoublyLinkedList::clear();
}

//destructor
CardShop::~CardShop()
{
  clear();
}

//@post: displays information of all cards in the shop, one per line
void CardShop::display()
{
  for (int i = 0; i < item_count_; i++)
  {
    getItem(i)->display();
  }
}

  //@param: the index of the first card to be displayed
  //@param: the index of the last card to be displayed
  //@post: displays the names of all cards in the shop with startRange and endRange, 
  //       inclusive, one per line
void CardShop::displayName(int startRange, int endRange)
{
  for (int i = startRange; i <= endRange; i++)
  {
    getItem(i)->displayName();
    if (i != endRange)
    {
      std::cout << ", ";
    }
    else
    {
      std::cout << std::endl;
    }
  }
}


//@return:  true if all the cards in rhs are equal to the cards in the shop, false otherwise
bool CardShop::operator==(const CardShop &rhs) const
{
  if (getLength() != rhs.getLength())
  {
    return false;
  }
  for (int i = 0; i < getLength(); i++)
  {
    if (*(getPointerTo(i)->getItem()) == *(rhs.getPointerTo(i)->getItem()))
    {
    }
    else
    {
      return false;
    }
  }
  return true;
}

//@return:  the number of swaps performed by the sort
template<typename Comparator>
int CardShop::bubbleSort(Comparator comp, std::string key){
  int size = getLength();
  int swaps = 0;
  bool swapped = true;
  int pass = 1;
  while(swapped && (pass < size)){
    swapped = false;
    for(int i = 0; i < size - pass; i++){
      if(key == "atk"){
        if(comp(getPointerTo(i+1)->getItem()->getAtk(), getPointerTo(i)->getItem()->getAtk())){
          swap(i, i+1);
          swapped = true;
          swaps++;
        }
      }
      if(key == "def"){
        if(comp(getPointerTo(i+1)->getItem()->getDef(), getPointerTo(i)->getItem()->getDef())){
          swap(i, i+1);
          swapped = true;
          swaps++;
        }
      }
    }
  }
  return swaps;
}

//@return:  the number of swaps performed by the sort
template<typename Comparator>
int CardShop::insertionSort(Comparator comp, std::string key){
  int swaps = 0;
  for(int unsorted = 1; unsorted < getLength(); unsorted++){
    int current = unsorted;
    if(key == "atk"){
      while((current > 0) && comp(getPointerTo(current)->getItem()->getAtk(), getPointerTo(current - 1)->getItem()->getAtk())){
        swap(current, current - 1);
        swaps++;
        current--;
      }
    }
    if(key == "def"){
      while((current > 0) && comp(getPointerTo(current)->getItem()->getDef(), getPointerTo(current - 1)->getItem()->getDef())){
        swap(current, current - 1);
        swaps++;
        current--;
      }
    }
  }
  return swaps;
}

//@return:  the number of swaps performed by the sort
template<typename Comparator>
int CardShop::quickSort(Comparator comp, std::string key){
  int size = getLength();
  int swaps = 0;
  int first = 0;
  int last = size - 1;
  quickSortHelper(comp, key, first, last, swaps);
  return swaps;
}

//calls partition and quickSortHelper to sort using recursion 
template<typename Comparator>
void CardShop::quickSortHelper(Comparator comp, std::string key, int first, int last, int &swaps){
  if(first < last){
    int pivot = partition(comp, key, first, last, swaps);
    quickSortHelper(comp, key, first, pivot - 1, swaps);
    quickSortHelper(comp, key, pivot + 1, last, swaps);
  }
}

//grabs the index of the pivot and swaps the values
template<typename Comparator>
int CardShop::partition(Comparator comp, std::string key, int first, int last, int &swaps){
  int pivotIndex;
  if(key == "atk"){
    pivotIndex = getPointerTo(last)->getItem()->getAtk();
  }
  else if(key == "def"){
    pivotIndex = getPointerTo(last)->getItem()->getDef();
  }
  int index = first;
  for(int j = first; j < last; j++){
    if(key == "atk"){
      if(comp(getPointerTo(j)->getItem()->getAtk(), pivotIndex)){
        swap(index, j);
        index++;
        swaps++;
      }
    }
    if(key == "def"){
      if(comp(getPointerTo(j)->getItem()->getDef(), pivotIndex)){
        swap(index, j);
        index++;
        swaps++;
      }
    }
  }
  if(key == "atk"){
    swap(index, last);
    swaps++;
  }
  if(key == "def"){
    swap(index, last);
    swaps++;
  }
  return index;
}

//@return:  the number of swaps performed by the sort
template<typename Comparator>
int CardShop::mergeSort(Comparator comp, std::string key){
  int size = getLength();
  int swaps = 0;
  int first = 0;
  int last = size - 1;
  mergeSortHelper(comp, key, first, last, swaps);
  return swaps;
}

//calls merge and mergeSortHelper to sort using recursion
template<typename Comparator>
void CardShop::mergeSortHelper(Comparator comp, std::string key, int first, int last, int &swaps){
  if(first < last){
    int mid = (first + last) / 2;
    mergeSortHelper(comp, key, first, mid, swaps);
    mergeSortHelper(comp, key, mid + 1, last, swaps);
    merge(comp, key, first, mid, last, swaps);
  }
}

//merges the values
template<typename Comparator>
void CardShop::merge(Comparator comp, std::string key, int first, int mid, int last, int &swaps){
  swaps++;  
  int size = last - first + 1;
  int temp[size];
  int index1 = first;
  int index2 = mid + 1;
  int index = 0;
  while(index1 <= mid && index2 <= last){
    if(key == "atk"){
      if(comp(getPointerTo(index1)->getItem()->getAtk(), getPointerTo(index2)->getItem()->getAtk())){
        temp[index] = getPointerTo(index1)->getItem()->getAtk();
        index1++;
      }
      else{
        temp[index] = getPointerTo(index2)->getItem()->getAtk();
        index2++;
      }
    }
    if(key == "def"){
      if(comp(getPointerTo(index1)->getItem()->getDef(), getPointerTo(index2)->getItem()->getDef())){
        temp[index] = getPointerTo(index1)->getItem()->getDef();
        index1++;
      }
      else{
        temp[index] = getPointerTo(index2)->getItem()->getDef();
        index2++;
      }
    }
    index++;
  }
  while(index1 <= mid){
    if(key == "atk"){
      temp[index] = getPointerTo(index1)->getItem()->getAtk();
    }
    if(key == "def"){
      temp[index] = getPointerTo(index1)->getItem()->getDef();
    }
    index1++;
    index++;
  }
  while(index2 <= last){
    if(key == "atk"){
      temp[index] = getPointerTo(index2)->getItem()->getAtk();
    }
    if(key == "def"){
      temp[index] = getPointerTo(index2)->getItem()->getDef();
    }
    index2++;
    index++;
  }
  for(index = first; index <= last; index++){
    if(key == "atk"){
      getPointerTo(index)->getItem()->setAtk(temp[index - first]);
    }
    if(key == "def"){
      getPointerTo(index)->getItem()->setDef(temp[index - first]);
    }
  }
}