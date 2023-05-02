//Adrian Mysliwiec
//2/24/23
//Novel.cpp
//Project 2: Inheritance!
#include "Novel.hpp"

/**
  Default constructor.
  Default-initializes all private members.
*/
Novel::Novel(){
    genre_ = "";
    average_ = 0.0;
    film_ = false;
    list_;
    reviews_;
}

/**
  Parameterized constructor.
  @param     : The title of the book (a string)
  @param     : The author of the book (a string)
  @param     : The number of pages in the book (a positive integer)
  @param     : The genre of the novel (a string)
  @param     : A flag indicating whether the book is in digital form
                with DEFAULT VALUE False (a Boolean)
  @param     : A flag indicating whether there is a film adaptation
                for this novel with DEFAULT VALUE False (a Boolean)
*/
Novel::Novel(const std::string title, const std::string author, const int page_count, const std::string genre, const bool is_digital, const bool film):Book(title, author, page_count, is_digital){
    genre_ = genre;
    average_ = 0.0;
    film_ = film;
    list_;
    reviews_;
}

/**
  @return   : the value of the genre private member
**/
std::string Novel::getGenre() const{
    return genre_;
}

/**
  @param  : a reference to string indicating the genre of the book
  @post   : sets genre_ private member to the
              value of the parameter
**/
void Novel::setGenre(const std::string &genre){
    genre_ = genre;
}

/**
  @return   : the vector containing the list of characters for this novel
**/
std::vector<std::string> Novel::getCharacterList() const{
    return list_;
}

/**
  @return    : a string of all the characters in the
              character_list_ private member, concatenated
              and separated by a space " " .
              For example: "character1 character2 character3"
**/
std::string Novel::getCharacterListString() const{
    std::string character_list = "";
    for(int i = 0; i < list_.size(); i++){
        character_list += list_[i];
        if(i < list_.size() - 1){
          character_list += " ";
        }
    }
    return character_list;
}

/**
  @param  : a reference to string indicating a character
  @post   : inserts the character into the character_list_ vector
**/
void Novel::addCharacter(const std::string &character_){
    list_.push_back(character_);
}

/**
  @return   : the value of the film_adaptation_ private member
**/
bool Novel::hasFilmAdaptation() const{
    return film_;
}

/**
  @post   : sets has_film_adaptation_ private member to true
**/
void Novel::setFilmAdaptation(){
    film_ = true;
}

/**
  @return   : the value of the average rating private member
**/
double Novel::getAverageRating() const{
    return average_;
}

/**
  @param    : a reference to floating point number (double) indicating
              the score of the  review
  @param    : a reference to string indicating the rating of the review
  @return   : creates and returns a review data type with
              score and rating as indicated by the parameters
*/
review Novel::createReview(const double &score, const std::string &theRating){
    review theReview;
    theReview.score_ = score;
    theReview.rating = theRating;
    return theReview;
}

/**
  @param  : a reference to review object
  @post   : inserts the review argument into the reviews_ vector
**/
void Novel::addReview(const review &theReview){
    reviews_.push_back(theReview);
}

/**
  @post   : retrieves all scores from the reviews_ vector and
            computes the average to set value of the average_rating_
            private member
**/ 
void Novel::calculateAverageRating(){
    double avg = 0.0;
    for(int i = 0; i < reviews_.size(); i++){
        avg += reviews_[i].score_;
    }
    average_ = avg / reviews_.size();
}
