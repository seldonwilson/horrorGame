/*******************************************************************************
* Filename: Location.hpp                                                       *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the interface to an abstract class which represents    *
*    different locations that can be explored in a Zork-like adventure game.   *
*    Also, provides the interface to each derived class of Location.
*                                                                              *
*******************************************************************************/

#ifndef LOCATION_HPP
#define LOCATION_HPP

#include <string>   // std::string
#include <vector>   // std::vector
#include "Item.hpp" // enum Item

enum LocationType {BOAT, CABIN, CAR, CLIFFWALL, FOREST, GARDEN, JUNKPILE,
                   LAKESHORE, SHED, TAPED_CAR};


   // Abstract class that each Location sub-class will inherit from
class Location
{
   protected:
      Location* north;
      Location* south;
      Location* east;
      Location* west;
      Item item;
      std::string description;
      LocationType locationType;

   public:
      Location();
      virtual ~Location() = 0;

      void printDescription() const;
      void setNorth(Location* pointHere);
      void setSouth(Location* pointHere);
      void setEast(Location* pointHere);
      void setWest(Location* pointHere);
      void setDescription(std::string newDescription);
      void setLocationType(LocationType newType);

      Location* getNorth() const;
      Location* getSouth() const;
      Location* getEast() const;
      Location* getWest() const;
      Item getItem() const;
      LocationType getLocationType() const;

      Item takeItem();
};



   // Represents the starting point in the game
class Cabin : public Location
{
   public:
      Cabin();
};



   // Represents the escape zone for the game
class Car : public Location
{
   public:
      Car();
};



   // Represents the junkpile on the side of the house
class Junkpile : public Location
{
   public:
      Junkpile();
};



   // Represents the garden on the side of the house
class Garden : public Location
{
   public:
      Garden();
};



   // Represents the forest which is used as a hub to other locations
class Forest : public Location
{
   public:
      Forest();
};



   // Represents a deadend which is also used as a red-herring
class Cliffwall : public Location
{
   public:
      Cliffwall();
};



   // Represents a shed full of potentiall useful supplies 
class Shed : public Location
{
   public:
      Shed();
};



   // Represents a shed full of potentiall useful supplies 
class Lakeshore : public Location
{
   public:
      Lakeshore();
};



   // Represents the boat in the middle of the lake
class Boat : public Location
{
   public:
      Boat();
};

#endif // LOCATION_HPP
