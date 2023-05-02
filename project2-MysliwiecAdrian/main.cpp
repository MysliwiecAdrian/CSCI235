#include<iostream>
#include<cassert>
#include "Book.hpp"
#include "Manual.hpp"
#include "Textbook.hpp"
#include "Novel.hpp"

int main()
{
    // --------------Test 1 Class Manual------------------
    std::cout << "---------Starting Test 1 for Manual Class-----------" << std::endl;
    // Create a manual
    Manual manual("The Manual", "John Doe", 100, "Computer", true, "https://www.example.com", true);

    // Check the title
    std::string expected_title = "The Manual";
    std::string actual_title = manual.getTitle();
    std::cout << "Expected title: " << expected_title << std::endl;
    std::cout << "Actual title: " << actual_title << std::endl;

    // Check the author
    std::string expected_author = "John Doe";
    std::string actual_author = manual.getAuthor();
    std::cout << "Expected author: " << expected_author << std::endl;
    std::cout << "Actual author: " << actual_author << std::endl;

    // Check the page count
    int expected_page_count = 100;
    int actual_page_count = manual.getPageCount();
    std::cout << "Expected page count: " << expected_page_count << std::endl;
    std::cout << "Actual page count: " << actual_page_count << std::endl;

    // Check the device
    std::string expected_device = "Computer";
    std::string actual_device = manual.getDevice();
    std::cout << "Expected device: " << expected_device << std::endl;
    std::cout << "Actual device: " << actual_device << std::endl;

    // Check if the manual is digital
    bool expected_is_digital = true;
    bool actual_is_digital = manual.isDigital();
    std::cout << "Expected is digital: " << expected_is_digital << std::endl;
    std::cout << "Actual is digital: " << actual_is_digital << std::endl;

    // Check if the manual has a website
    bool expected_has_website = true;
    bool actual_has_website = manual.hasWebsite();
    std::cout << "Expected has website: " << expected_has_website << std::endl;
    std::cout << "Actual has website: " << actual_has_website << std::endl;

    // Check the website URL
    std::string expected_url = "https://www.example.com";
    std::string actual_url = manual.getWebsite();
    std::cout << "Expected URL: " << expected_url << std::endl;
    std::cout << "Actual URL: " << actual_url << std::endl;

    // Check if the manual has a visual aid
    bool expected_has_visual_aid = true;
    bool actual_has_visual_aid = manual.hasVisualAid();
    std::cout << "Expected has visual aid: " << expected_has_visual_aid << std::endl;
    std::cout << "Actual has visual aid: " << actual_has_visual_aid << std::endl;

    // Change the device
    manual.setDevice("Laptop");
    std::string expected_new_device = "Laptop";
    std::string actual_new_device = manual.getDevice();
    std::cout << "Expected new device: " << expected_new_device << std::endl;
    std::cout << "Actual new device: " << actual_new_device << std::endl;

    // Change the website URL
    manual.setWebsite("https://www.idk.com");
    std::string expected_new_url = "https://www.idk.com";
    std::string actual_new_url = manual.getWebsite();
    std::cout << "Expected new URL: " << expected_new_url << std::endl;
    std::cout << "Actual new device: " << actual_new_url << std::endl;

    // --------------Test 2 Class Textbook------------------
    std::cout << "---------Starting Test 2 for Novel Class-----------" << std::endl;

    // Create a textbook with some properties
    Textbook t("Intro to Physics", "John Smith", 300, "Physics", true, grade_level::HIGH_SCHOOL, false);

    // Test getSubject method
    std::cout << "Subject of textbook: " << t.getSubject() << std::endl;

    // Test setSubject method
    t.setSubject("Chemistry");
    std::cout << "New subject of textbook: " << t.getSubject() << std::endl;

    // Test getGradeLevel method
    std::cout << "Grade level of textbook: " << t.getGradeLevel() << std::endl;

    // Test setGradeLevel method
    t.setGradeLevel(grade_level::ELEMENTARY);
    std::cout << "New grade level of textbook: " << t.getGradeLevel() << std::endl;

    // Test checkReviewQuestions method

    std::cout << "Textbook has review questions: " << t.checkReviewQuestions() << std::endl;

    // Test setReviewQuestions method
    t.setReviewQuestions();
    std::cout << "Textbook has review questions: " << t.checkReviewQuestions() << std::endl;

    // --------------Test 3 Class Novel------------------
    std::cout << "---------Starting Test 3 for Novel Class-----------" << std::endl;
    Novel novel("The Great Gatsby", "F. Scott Fitzgerald", 180, "Classic", false, false);

    // Test setting and getting the genre
    std::string new_genre = "Drama";
    novel.setGenre(new_genre);
    std::cout << "Genre should be Drama: " << novel.getGenre() << std::endl;

    // Test adding a character
    std::string character_name = "Jay Gatsby";
    novel.addCharacter(character_name);
    std::cout << "Character list should include Jay Gatsby: " << novel.getCharacterListString() << std::endl;

    // Test setting and getting film adaptation
    novel.setFilmAdaptation();
    std::cout << "Novel should have a film adaptation: " << novel.hasFilmAdaptation() << std::endl;

    // Test adding a review and getting the average rating
    review new_review = novel.createReview(4.5, "Excellent");
    novel.addReview(new_review);
    novel.calculateAverageRating();
    std::cout << "Average rating should be 4.5: " << novel.getAverageRating() << std::endl;

    // Test adding multiple reviews and getting the updated average rating
    review new_review_2 = novel.createReview(3.0, "Average");
    novel.addReview(new_review_2);
    novel.calculateAverageRating();
    std::cout << "Average rating should be 3.75: " << novel.getAverageRating() << std::endl;
}