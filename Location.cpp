/*******************************************************************************
* Filename: Location.cpp                                                       *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of an abstract class that represents*
*    different locations that can be explored in a Zork-like adventure game.   *
*                                                                              *
*******************************************************************************/

#include "Location.hpp" // Location::
#include "Item.hpp"     // enum Item
#include <string>       // std::string
#include <iostream>     // std::cout

using std::string;
using std::cout;


/*******************************************************************************
*    Function: Location::Location                                              *
*                                                                              *
* Description: Sets the data-members to default values to aid in debugging.    *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Location::Location()
{
   north = nullptr;
   south = nullptr;
   east  = nullptr;
   west  = nullptr;
   description = "UNSET DESCRIPTION";
}



/*******************************************************************************
*    Function: Location::~Location                                             *
*                                                                              *
* Description: Pure virtual destructor that exists to allow class to be        *
*              abstract.                                                       *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Location::~Location()
{
   north = nullptr;
   south = nullptr;
   east  = nullptr;
   west  = nullptr;
}



/*******************************************************************************
*    Function: Location::printDescription const                                *
*                                                                              *
* Description: Outputs the description data member to the terminal.            *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Location::printDescription() const
{
   cout << description;
}



/*******************************************************************************
*    Function: Location::setNorth/South/East/West                              *
*                                                                              *
* Description: Sets the appropriate data member.                               *
*                                                                              *
*      Inputs: pointHere - Location*                                           *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Location::setNorth(Location* pointHere)
{
   north = pointHere;
}

void Location::setSouth(Location* pointHere)
{
   south = pointHere;
}

void Location::setEast(Location* pointHere)
{
   east = pointHere;
}

void Location::setWest(Location* pointHere)
{
   west = pointHere;
}



/*******************************************************************************
*    Function: Location::getNorth/South/East/West                              *
*                                                                              *
* Description: Gets the appropriate data member.                               *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: Location*                                                       *
*******************************************************************************/
Location* Location::getNorth(void) const
{
   return north;
}

Location* Location::getSouth(void) const
{
   return south;
}

Location* Location::getEast(void) const
{
   return east;
}

Location* Location::getWest(void) const
{
   return west;
}



/*******************************************************************************
*    Function: Location::getItem                                               *
*                                                                              *
* Description: Gets the appropriate data member.                               *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: Item                                                            *
*******************************************************************************/
Item Location::getItem() const
{
   return item;
}



/*******************************************************************************
*    Function: Location::takeItem                                              *
*                                                                              *
* Description: Returns the item at the location and sets the location item to  *
*              NO_ITEM.                                                        *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: Item                                                            *
*******************************************************************************/
Item Location::takeItem()
{
   Item temp = item;
   item = Item::NO_ITEM;
   return temp;
}



LocationType Location::getLocationType() const
{
   return locationType;
}

void Location::setDescription(std::string newDescription)
{
   description = newDescription;
}

void Location::setLocationType(LocationType newType)
{
   locationType = newType;
}