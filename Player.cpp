/*******************************************************************************
* Filename: Player.cpp                                                         *
* Author:   Daniel Wilson                                                      *
* E-Mail:   wilsond3@oregonstate.edu                                           *
* Date:     10 June 2017                                                       *
*                                                                              *
* Description: Provides the implementation of the player class which is able to*
*    control the player and its movements/interactions in the game.            *
*                                                                              *
*******************************************************************************/

#include "Player.hpp"   // Player::, PlayerActions
#include "Location.hpp" // Location
#include "ioutil.hpp"   // Menu
#include "Item.hpp"     // enum Item
#include <string>       // std::string
#include <vector>       // std::vector
#include <iostream>     // std::cout
#include "map.hpp"

using std::string;
using std::vector;
using std::cout;
using std::endl;

PlayerActions actionToEnum(const vector<string>& actions, int actionSelection);
void doAction(PlayerActions doThis);
string enumToString(Item item);

/*******************************************************************************
*    Function: Player::Player                                                  *
*                                                                              *
* Description: Initializes the player's current location to the arguement.     *
*                                                                              *
*      Inputs: startingLocation - Location*                                    *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Player::Player(Location* startingLocation)
{
   currentLocation = startingLocation;
}



/*******************************************************************************
*    Function: Player::~Player                                                 *
*                                                                              *
* Description: Sets current location to nullptr.                               *
*                                                                              *
*      Inputs: startingLocation - Location*                                    *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
Player::~Player()
{
   currentLocation = nullptr;
   inventory.clear();
}



/*******************************************************************************
*    Function: Player::takeAction                                              *
*                                                                              *
* Description: Displays a list of actions the player can take based on their   *
*              current location and their inventory items.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: bool - returns true if the player has won the game.             *
*******************************************************************************/
bool Player::chooseAction()
{
   string title  = "Available Actions\n";
          title += "=================";

   vector<string> availableOptions;

   if (currentLocation->getNorth() != nullptr)
      availableOptions.push_back("Move North");
   if (currentLocation->getEast() != nullptr)
      availableOptions.push_back("Move East");
   if (currentLocation->getSouth()        != nullptr &&
       currentLocation->getLocationType() != LocationType::LAKESHORE)
      availableOptions.push_back("Move South");
   if (currentLocation->getWest() != nullptr)
      availableOptions.push_back("Move West");
   if (currentLocation->getItem() == Item::KAYAK)
      availableOptions.push_back("Take Kayak");
   if (currentLocation->getItem() == Item::HOSE)
      availableOptions.push_back("Take Garden Hose");
   if (currentLocation->getItem() == Item::CAN)
      availableOptions.push_back("Take Gas Can");
   if (currentLocation->getItem() == Item::GAS && hasCan() && hasHose())
      availableOptions.push_back("Siphon Gas");
   if (currentLocation->getItem() == Item::TAPE)
      availableOptions.push_back("Take Duct Tape");
   if (currentLocation->getLocationType() == LocationType::LAKESHORE &&
       hasKayak())
      availableOptions.push_back("Kayak out to middle of lake");
   if (currentLocation->getLocationType() == LocationType::CAR &&
       hasTape())
          availableOptions.push_back("Patch car with duct tape");
   if (currentLocation->getLocationType() == LocationType::TAPED_CAR &&
       hasGas())
          availableOptions.push_back("Gas up the car and get out of here!");

   availableOptions.push_back("Show Inventory");

   string prompt = "Take action: ";
   Menu actionMenu(title, availableOptions, prompt);

   int actionSelection;
   cout << "\n\n";
   actionMenu.print();
   actionSelection = actionMenu.getSelection();
   PlayerActions choice;

   if (actionSelection != -1)
   {
      choice = actionToEnum(availableOptions, actionSelection);
      return doAction(choice);
   }
   return false;
}



/*******************************************************************************
*    Function: actionToEnum                                                    *
*                                                                              *
* Description: Converts the action selected by the user to the PlayerActions   *
*              type.                                                           *
*                                                                              *
*      Inputs:         actions - vector<string>&                               *
*              actionSelection - int                                           *
*                                                                              *
*     Outputs: PlayerActions                                                   *
*******************************************************************************/
enum PlayerActions actionToEnum(const vector<string>& actions, 
                                int actionSelection)
{
   string actionName = actions.at(actionSelection - 1);

   if (actionName == "Move North")
      return PlayerActions::MOVE_NORTH;
   else if (actionName == "Move East")
      return PlayerActions::MOVE_EAST;
   else if (actionName == "Move South")
      return PlayerActions::MOVE_SOUTH;
   else if (actionName == "Move West")
      return PlayerActions::MOVE_WEST;
   else if (actionName == "Show Inventory")
      return PlayerActions::SHOW_INVENTORY;
   else if (actionName == "Take Kayak")
      return PlayerActions::TAKE_ITEM;
   else if (actionName == "Take Garden Hose")
      return PlayerActions::TAKE_ITEM;
   else if (actionName == "Take Gas Can")
      return PlayerActions::TAKE_ITEM;
   else if (actionName == "Siphon Gas")
      return PlayerActions::TAKE_ITEM;
   else if (actionName == "Take Duct Tape")
      return PlayerActions::TAKE_ITEM;
   else if (actionName == "Kayak out to middle of lake")
      return PlayerActions::MOVE_SOUTH;
   else if (actionName == "Patch car with duct tape")
      return PlayerActions::USE_TAPE;
   else if (actionName == "Gas up the car and get out of here!")
      return PlayerActions::ESCAPE;
   else
      return PlayerActions::DO_NOTHING;
}



/*******************************************************************************
*    Function: Player::doAction                                                *
*                                                                              *
* Description: Cause the player to take an action based on their previous      *
*              action selection.                                               *
*                                                                              *
*      Inputs: doThis - PlayerActions                                          *
*                                                                              *
*     Outputs: bool - returns true if the player has won the game.             *
*******************************************************************************/
bool Player::doAction(PlayerActions doThis)
{
   if (doThis == PlayerActions::MOVE_NORTH)
      currentLocation = currentLocation->getNorth();
   else if (doThis == PlayerActions::MOVE_EAST)
      currentLocation = currentLocation->getEast();
   else if (doThis == PlayerActions::MOVE_SOUTH)
      currentLocation = currentLocation->getSouth();
   else if (doThis == PlayerActions::MOVE_WEST)
      currentLocation = currentLocation->getWest();
   else if (doThis == PlayerActions::SHOW_INVENTORY)
      printInventory();
   else if (doThis == PlayerActions::TAKE_ITEM)
      inventory.push_back(currentLocation->takeItem());
   else if (doThis == PlayerActions::USE_TAPE)
   {
      string description;
      description  = "There's nothing duct tape can't fix! Now all this car ";
      description += "needs is some gasoline and a whole lot of luck!";
      currentLocation->setDescription(description);

      currentLocation->setLocationType(LocationType::TAPED_CAR);
   }
   else if (doThis == PlayerActions::ESCAPE)
   {
      return true;
   }
   return false;
}



/*******************************************************************************
*    Function: Player::printLocationDescription() const                        *
*                                                                              *
* Description: Wrapper to the current location's printDescription menthod.     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Player::printLocationDescription() const
{
   currentLocation->printDescription();
}



/*******************************************************************************
*    Function: Player::printInventory() const                                  *
*                                                                              *
* Description: Prints all of the player's inventory items.                     *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: void                                                            *
*******************************************************************************/
void Player::printInventory() const
{
   ValidatedInput input;
   terminalClear();

   if (inventory.size() == 0)
      cout << "Your pack is empty. Things are not looking good.";
   else
   {
      for (unsigned int i = 0; i < inventory.size(); ++i)
         cout << i + 1 << ". " << enumToString(inventory.at(i)) << endl;
   }

   cout << "\n\nPress ENTER to return";
   input.fromKeyboard();
}



/*******************************************************************************
*    Function: enumToString                                                    *
*                                                                              *
* Description: Takes an enum of an item and converts it to a string.           *
*                                                                              *
*      Inputs: item - Item (enum)                                              *
*                                                                              *
*     Outputs: string                                                          *
*******************************************************************************/
string enumToString(Item item)
{
   if (item == Item::KAYAK)
      return "kayak";
   else if (item == Item::HOSE)
      return "garden hose";
   else if (item == Item::CAN)
      return "gas can";
   else if (item == Item::GAS)
      return "gas (in can)";
   else if (item == Item::TAPE)
      return "duct tape";
   else
      return "invalid item";
}



/*******************************************************************************
*    Function: Player::hasCan/Gas/Hose/Tape/Kayak const                        *
*                                                                              *
* Description: Returns if the player has a particular item in their inventory. *
*                                                                              *
*      Inputs: void                                                            *
*                                                                              *
*     Outputs: bool - returns true if the user has the named item.             *
*******************************************************************************/
bool Player::hasCan() const
{
   for (unsigned int i = 0; i < inventory.size(); ++i)
      if (inventory.at(i) == Item::CAN)
         return true;

   return false;
}

bool Player::hasGas() const
{
   for (unsigned int i = 0; i < inventory.size(); ++i)
      if (inventory.at(i) == Item::GAS)
         return true;

   return false;
}

bool Player::hasHose() const
{
   for (unsigned int i = 0; i < inventory.size(); ++i)
      if (inventory.at(i) == Item::HOSE)
         return true;

   return false;
}

bool Player::hasTape() const
{
   for (unsigned int i = 0; i < inventory.size(); ++i)
      if (inventory.at(i) == Item::TAPE)
         return true;

   return false;
}

bool Player::hasKayak() const
{
   for (unsigned int i = 0; i < inventory.size(); ++i)
      if (inventory.at(i) == Item::KAYAK)
         return true;

   return false;
}
