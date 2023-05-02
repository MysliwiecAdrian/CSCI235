//Adrian Mysliwiec
//2/24/23
//Manual.cpp
//Project 2: Inheritance!
#include "Manual.hpp"

/**
    Default constructor.
    Default-initializes all private members.
*/
Manual::Manual(){
    url_ = "";
    device_ = "";
    aid_ = false;
    website_ = false;
}

/**
    Parameterized constructor.
    @param     : The title of the book (a string)
    @param     : The author of the book (a string)
    @param     : The number of pages in the book (a positive integer)
    @param     : The name of the device (a string)
    @param     : A flag indicating whether the book is in digital form
                    with DEFAULT VALUE False (a Boolean)
    @param     : The URL that is in the format
                    'https://www.something.something'
                    or 'http://www.something.something'
                    with the last 'something' being at least 2 characters
                    with DEFAULT VALUE empty string (a string)
    @param     : A Boolean indicating the presence of a visual aid
                    with DEFAULT VALUE False
    @post      : The private members are set to the values of the
                    corresponding parameters.
                    If a URL is provided, the website flag is set to True.
                    If the URL is ill-formatted, the website is set to
                    empty string and the website flag is set to False.
*/
Manual::Manual(const std::string title, const std::string author, const int page_count, const std::string device, const bool is_digital, const std::string url, const bool aid):Book(title, author, page_count, is_digital){
    device_ = device;
    aid_ = aid;
    url_ = url;
    setWebsite(url_);
    if(url_ == "Broken Link"){
        url_ = "";
        website_ = false;
    }
}

/**
  @param  : a reference to a string representing the device
  @post   : sets the private member variable to the value of the parameter
**/
void Manual::setDevice(const std::string &device){
    device_ = device;
}

/**
  @return  : the variable indicating the device the manual is for
**/
std::string Manual::getDevice() const{
    return device_;
}

/**
  @param   : a reference to a website link (string) that is in the format
             'https://www.something.something'
             or 'http://www.something.something'
             with the last 'something' being at least 2 characters
  @return  : has_website_ flag (a boolean)
  @post    : If the link is not correctly formatted,
             store "Broken Link" in the link member variable (see <regex>)
             and either way set the has website flag to True
**/
bool Manual::setWebsite(const std::string &url){
    std::regex pattern(R"(^(https?://)?[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,})(/.*)?$)", std::regex::icase);

    if(std::regex_match(url, pattern)){
        url_ = url;
    }
    else{
        url_ = "Broken Link";
    }

    website_ = true;
    return website_;
}

/**
  @return  : the url for the website
**/
std::string Manual::getWebsite() const{
    return url_;
}

/**
  @param  : a reference to boolean
  @post   : sets the private member variable indicating the presence
            of a visual aid to the value of the parameter
**/
void Manual::setVisualAid(const bool &aid){
    aid_ = aid;
}

/**
  @return  : the visual aid flag
**/
bool Manual::hasVisualAid() const{
    return aid_;
}

/**
  @return  : the has website flag
**/
bool Manual::hasWebsite() const{
    return website_;
}


