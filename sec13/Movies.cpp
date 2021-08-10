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
    //auto it = std::find(movies.cbegin(), movies.cend(), name);  // search the name
    if (movies.empty()) {
        movies.emplace_back(name, rating, watched);  // add the movie
        std::cout << "Added into an empty vec" << std::endl;
        return true;
    }
    for (auto &e : movies) {
        if (e.get_name() == name) {
            std::cout << "Movies::add_movie() - Error, cannot add movie, the movie has already existed!" << std::endl;
            return false;
        } else {
            movies.emplace_back(name, rating, watched);  // add the movie
            std::cout << "The movie: " << name << " has been successfully added!" << std::endl;
            return true;
        }
    } 
    return false;
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
}