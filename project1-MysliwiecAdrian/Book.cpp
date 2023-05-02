//Adrian Mysliwiec
//2/4/23
//Book.cpp
//Project 1: Review of OOP


#include "Book.hpp"
#include <iostream>

/**
    Default constructor.
    Default-initializes all private members. Booleans are default-initialized to False.
*/
Book::Book(){
    this->title = "";
    this->author = "";
    this->page_count = 0;
    this->digital = false;
}

/**
    Parameterized constructor.
    @param      : The title of the book (a string)
    @param      : The author of the book (a string)
    @param      : The number of pages in the book (a positive int)
    @param      : A flag indicating whether the book is in digital form (a Boolean)
    @post       : The private members are set to the values of the corresponding parameters.
*/
Book::Book(const std::string &new_title, const std::string &new_author, const int &new_page_count, const bool &new_digital){
    this->title = new_title;
    this->author = new_author;
    this->page_count = new_page_count;
    this->digital = new_digital;
}

/**
    @param  : the title of the Book
    @post   : sets the Book's title to the value of the parameter
*/
void Book::setTitle(const std::string &new_title){
    this->title = new_title;
}

/**
    @return : the title of the Book
*/
std::string Book::getTitle() const{
    return this->title;
}

/**
    @param  : the name of the author of the Book
    @post   : sets the Book's author to the value of the parameter
*/
void Book::setAuthor(const std::string &new_author){
    this->author = new_author;
}

/**
    @return : the author of the Book
*/
std::string Book::getAuthor() const{
    return this->author;
}

/**
    @param  : a positive integer page count
    @pre    : page count > 0 - books cannot have a negative number of pages
    @post   : sets the page count to the value of the parameter
*/
void Book::setPageCount(const int &new_page_count){
    if(new_page_count > 0){
        this->page_count = new_page_count;
    }
}

/**
    @return : the page count
*/
int Book::getPageCount() const{
    return this->page_count;
}

/**
   @post   : sets the digital flag to true
*/
void Book::setDigital(){
    this->digital = true;
}

/**
    @return true if the book is available in digital form, false otherwise

  Note: this is an accessor function and must follow the same convention as all accessor functions even if it is not called getDigital
*/
bool Book::isDigital() const{
    return this->digital;
}