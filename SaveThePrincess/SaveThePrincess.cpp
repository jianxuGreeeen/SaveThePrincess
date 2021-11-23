// SaveThePrincess.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Game.h"

// NOTES:
// Player must travel through levels to save the princess
// Each level may contain player, enemies, princess
// 
// Data on entities:
// Character    Health      Armor       Weapon          Movement
// Player       100         100         Shotgun         Ground
// Princess     80          0           None            Ground
// Boss         500         100         Fireball/Axe    Ground/Air
// Squab        50          0           Bomb            Air
// Turtle       60          50          Shell Rock      Ground
// Puffer       60          20          Poison Touch    Water

// Brainstorm
//
// Game loop -
//  The loop needs to handle various systems. The core would be:
//  Frame Time
//      Some kind of way to retrieve the diff between current and previous frame time.
//  Input
//      Buffers for current and previous
//  Render
//      Particle
//      Sprites
//      Text
//  Gameplay system Updates
//      UI 
//      Physics
//      AI/Entity Movement
//      Some sort of Game State
//          - Go between levels
//          - Need to load different levels
//      
//
// I think ideally, a lot of these should be multi threaded but I'm going to keep things simpel for now and revisit if there's a chance to do so.
// The render system for example, should be on another thread and we would simply push what we want to render to it so it can run as fast as possible.
//

//  
//  Probably want to suppose input mapping and turn keys into defined actions
//  We'd have a potentially different mapping depending on what we're doing:
//  Ex:    menu vs game - b button maps to back in the menu vs some gameplay action 
   
int main()
{
    Game game;
    game.Run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
