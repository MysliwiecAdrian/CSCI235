//Adrian Mysliwiec
//2/24/23
//Textbook.cpp
//Project 2: Inheritance!
#include "Textbook.hpp"

/**
  Default constructor.
  Default-initializes all private members.
*/
Textbook::Textbook(){
    subject_ = "";
    grade_level_ = NONE;
    review_ = false;
}

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
Textbook::Textbook(const std::string title, const std::string author, const int page_count, const std::string subject, const bool is_digital, const grade_level level, const bool review):Book(title, author, page_count, is_digital){
    subject_ = subject;
    grade_level_ = level;
    review_ = review;
}

/**
  @param  : a reference to a string representing the the subject of the book
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setSubject(const std::string &subject){
    subject_ = subject;
}

/**
  @return  : the subject of the textbook
**/
std::string Textbook::getSubject() const{
    return subject_;
}

/**
  @param  : a reference to a grade_level
  @post   : sets the private member variable to the value of the parameter
**/
void Textbook::setGradeLevel(const grade_level &level){
    if(level < 0 || level > 4){
      grade_level_ = NONE;
    }
    else{
      grade_level_ = level;
    }
}

/**
  @return  : a string representative of the grade_level
            (e.g. if the grade level is JUNIOR_HIGH,
            it returns "JUNIOR HIGH")
**/
std::string Textbook::getGradeLevel() const{
    if(grade_level_ == ELEMENTARY){
        return "ELEMENTARY";
    }
    else if(grade_level_ == JUNIOR_HIGH){
        return "JUNIOR HIGH";
    }
    else if(grade_level_ == HIGH_SCHOOL){
        return "HIGH SCHOOL";
    }
    else if(grade_level_ == COLLEGE){
        return "COLLEGE";
    }
    else{
        return "NONE";
    }
}

/**
  @post   : sets the review question flag to True
**/
void Textbook::setReviewQuestions(){
    review_ = true;
}

/**
  @return  : the flag indicating if the texbook has review questions
**/
bool Textbook::checkReviewQuestions() const{
    return review_;
}

