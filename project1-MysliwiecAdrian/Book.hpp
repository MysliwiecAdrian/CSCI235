//Adrian Mysliwiec
//2/4/23
//Book.hpp
//Project 1: Review of OOP


#ifndef BOOK_HPP
#define BOOK_HPP

#include <string>
#include <iostream>

class Book{
    private:
        std::string title;
        std::string author;
        int page_count;
        bool digital;

    public:
        Book(); //default contructor
        Book(const std::string &new_title, const std::string &new_author, const int &new_page_count, const bool &new_digital = false); //parameterized constructor with 4 params
        void setTitle(const std::string &new_title); //sets a new title to the variable
        std::string getTitle() const; //returns the title
        void setAuthor(const std::string &new_author); //sets a new author
        std::string getAuthor() const; //returns the author
        void setPageCount(const int &new_page_count); //sets a new page count
        int getPageCount() const; //returns the page count
        void setDigital(); //sets the digital variable to true
        bool isDigital() const; //returns the digital variable

};

#endif