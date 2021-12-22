// Programmer: Rueil Manzambi              Section: 109
// Date: March 10, 2021
// File: main_homework05.cpp
// Purpose: This file has a program that simulates a mid-life crisis in which an adult is making decision to either go to the casino
//          or go home. The decision making to go the casino is based on a random number generation that reflects the probability,
//          which starts from 100% and decreases for every move


#include <iostream>
#include <cstdlib>
#include <ctime>

#include "header_homework05.h"

using namespace std;

int main()
{
  // variable declaration
  int min_distance, max_distance;

  srand(time(0));

  cout << "\n\t\t\tWelcome to the Mid-life Crisis walk simulator" << endl;
  cout << "\t\t\t---------------------------------------------\n" << endl;

  min_distance = get_min_distance();
  max_distance = get_max_distance(min_distance);
  handle_walk(min_distance, max_distance); // calls function to handle the walk

  cout << "\nThank You for using the simulator, bye...\n" << endl;
  return 0;
}
