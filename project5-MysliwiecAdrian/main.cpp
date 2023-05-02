#include "DoublyLinkedList.hpp"
#include "CardShop.cpp"
#include "YGOCard.hpp"
#include <iostream>

int main()
{
    DoublyLinkedList<int> list;
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(2, 3);
    list.insert(3, 4);
    list.insert(4, 5);
    list.swap(1, 2);
    list.display();
    list.swap(1, 3);
    list.display();

    CardShop *shop = new CardShop("cards.csv");

    
    shop->mergeSort(std::greater<int>{}, "def");
    shop->display();
}