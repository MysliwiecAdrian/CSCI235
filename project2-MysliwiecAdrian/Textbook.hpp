//Adrian Mysliwiec
//2/24/23
//Textbook.hpp
//Project 2: Inheritance!
#ifndef TEXTBOOK_HPP
#define TEXTBOOK_HPP
#include "Book.hpp"
#include <iostream>
#include <string>

enum grade_level{
    NONE, 
    ELEMENTARY, 
    JUNIOR_HIGH, 
    HIGH_SCHOOL, 
    COLLEGE
};

class Textbook: public Book{
    private:
        std::string subject_;
        grade_level grade_level_;
        bool review_;
    public:
        /**
            Default constructor.
            Default-initializes all private members.
        */
        Textbook();

        /**
            Parameterized constructor.
            @param     : The title of the book (a string)
            @param     : The author of the book (a string)
            @param     : The number of pages in the book (a positive integer)
            @param     : The subject of the book (a string)
            @param     : A flag indicating whether the book is in digital form
                            with DEFAULT VALUE False (a Boolean)
            @param     : The grade level of the book (of type grade_level)
                            with DEFAULT VALUE NONE
            @param     : A boolean to indicate whether the book has review
                            questions with DEFAULT VALUE False
            @post      : The private members are set to the values of the
                            corresponding parameters.
        */
        Textbook(const std::string title, const std::string author, const int page_count, const std::string subject, const bool is_digital = false, const grade_level level = NONE, const bool review = false);

        /**
            @param  : a reference to a string representing the the subject of the book
            @post   : sets the private member variable to the value of the parameter
        **/
        void setSubject(const std::string &subject);

        /**
            @return  : the subject of the textbook
        **/
        std::string getSubject() const;

        /**
            @param  : a reference to a grade_level
            @post   : sets the private member variable to the value of the parameter
        **/
        void setGradeLevel(const grade_level &level);

        /**
            @return  : a string representative of the grade_level
                        (e.g. if the grade level is JUNIOR_HIGH,
                        it returns "JUNIOR HIGH")
        **/
        std::string getGradeLevel() const;

        /**
            @post   : sets the review question flag to True
        **/
        void setReviewQuestions();

        /**
            @return  : the flag indicating if the texbook has review questions
        **/
       bool checkReviewQuestions() const;


};

#endif