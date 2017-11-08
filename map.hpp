/*******************************************************************************
* Filename: map.hpp                                                            *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides function prototypes that are used in the creation of   *
*    the game map.                                                             *
*                                                                              *
*******************************************************************************/

#ifndef MAP_HPP
#define MAP_HPP

#include "Location.hpp"

Location* createMap();
void destroyMap(Location*);


#endif // MAP_HPP
