/******************************************************************
 * Section 13 Challenge
 * Movies.h
 * 
 * Models a collection of Movies as a std::vector
 * 
 * ***************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
#include "Movies.h"

 /*************************************************************************
    Movies no-args constructor
**************************************************************************/
Movies::Movies() {
}

/*************************************************************************
    Movies destructor
**************************************************************************/
Movies::~Movies() {
}

  /*************************************************************************
    add_movie expects the name of the move, rating and watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    
    If it does then return false since the movie already exists
    Otherwise, create a movie object from the provided information
    and add that movie object to the movies vector and return true
    *********************************************************************/
bool Movies::add_movie(std::string name, std::string rating, int watched) {
    // you implement this method
    if (movies.empty()) {
        movies.emplace_back(name, rating, watched);  // add the movie
        std::cout << "Added into an empty vec" << std::endl;
        return true;
    }
    
    bool found = false;
    for (auto &e : movies) {
        if (e.get_name() == name) {
            found = true;
            break;
        } else {
            found = false;
        }
    } 
    
    if (found) {
        //std::cout << "Movies::add_movie() - Error, cannot add movie, the movie has already existed!" << std::endl;
        return false;
    } else {
        movies.emplace_back(name, rating, watched);  // add the movie
        //std::cout << "The movie: " << name << " has been successfully added!" << std::endl;
        return true;
    }
}

 /*************************************************************************
    increment_watched expects the name of the move to increment the
    watched count
    
    It will search the movies vector to see if a movie object already exists
    with the same name. 
    If it does then increment that objects watched by 1 and return true.

    Otherwise, return false since then no movies object with the movie name
    provided exists to increment
    *********************************************************************/
bool Movies::increment_watched(std::string name) {
   // you implement this method
   if (movies.empty()) { // if moview list is empty, return false
       return false;
   }

   for (auto &e: movies) {
       if (e.get_name() == name) {
           e.increment_watched();
           return true;
       }
       else {
           ;  // do nothing, keep going on
       }
   }
   // if not found the movie, return false

   return false;
}

/*************************************************************************
    display
    
    display all the movie objects in the movies vector.
    for each movie call the movie.display method so the movie
    object displays itself
    *********************************************************************/
void Movies::display() const {
   // You implement this method
   if (movies.empty()) {
       std::cout << "Cannot display empty movies list" << std::endl;
       return;
   }

   std::cout << "----Display the current movie that has been watched----" << std::endl;
   for (auto &e: movies) {
       e.display();
   }
   std::cout << "------------------Display Ends ------------------" << std::endl;
}