// SaveThePrincess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"
// Stubbed out a general idea for a game loop base on my understanding of the requirements.
// This solution has a general flow for starting up and running levels.
// Here are some point of interests

// Game Class:
//  Everything is contained within the Game class
//  - Updates the game loop.
//  - Holds data to systems that needs to exist for the entirety of the game.
//  - This includes the various gameplay systems, physics, input, etc.
//  - It also contains a state machine to transition between different states of the game.
//  -   I tried this out as an attempt to organize the flow which consists of:
//          - Starting up
//          - Main menu
//          - Loading a level
//          - Running the level
//          - Unloading a level
//          - Exiting the game
//      See GameStateMachine and associated files.
//  -   Looking back, I think the state machine helped make the flow a bit more explicit.
//      But, I think it may be a bit too restrictive in the end. I had shied away
//      from having callbacks all over the place initially.

//  - Starting Up
//  - Here we load in all of the resources. I assume there's some sort of file to load from
//  - These resources are loaded in as different types with IDs. (Resource.h)
//  - We have a ResourceDB that will house all this data.
//  - When we need to load levels, we can ask the db for info.
//  - At this point, I'm going to assume everything is loaded up.
 
//  - AI Pool
//  - We initialize a pool of AI we can init from.
//  - Levels will just grab from this pool on load and release on unload.
//  - This prevents us from need to allocate in the middle of gameplay
//    especially if it's costly.

//  - Levels
//  - A level acts mostly as a container of initialized AIs.
//  - That way, we can loop and update them as needed. 
//  - It also helps in initializing and cleaning up the AIs.

//  - Characters
//  - These are the run time objects that would represent
//    the different characters in the spec.
//    For the moment, they're composed of a set of components. 
//         - Input
//         - Physics
//         - Weapons
//         - Stats
//         - Render
//    They're still set up in a more traditional object oriented style as
//    characters have their own update functions.
//
//    An improvement here might be to move the ownership to the systems themselves.
//    And then the Characters would simple be an ID to tie the components together.
//      

int main()
{
    Game game;
    game.Run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
