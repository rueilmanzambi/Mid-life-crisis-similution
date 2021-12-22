// Programmer: Rueil Manzambi            Section: 109
// Date: March 10, 2021
// File: functions_def_homework05.cpp
// Description: This is the functions definitions file for the main file main_homework05.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "header_homework05.h"

using namespace std;


// Description: get the minimum distance from the user and returns it 
// Pre: user's input has to be at greater than 0
// Post: returns the minimum distance entered
int get_min_distance()
{
  int min_distance;

  do
  {
    cout << "Please, enter a minimum walking distance: ";
    cin >> min_distance;
  } while (min_distance < 1);

  return min_distance;
}


// Description: get the maximum distance from the user and returns it
// Pre: user's input has to be greater than min_distance
// Post: returns the maximum distance entered
int get_max_distance(const int min_distance)
{
  int max_distance;

  do
  {
    cout << "Please, enter a maximum walking distance: ";
    cin >> max_distance;
  } while (max_distance <= min_distance);

  return max_distance;
}

// Description: handles the walk and calls two functions to compute and print the result
// Pre: min_distance has to be greater than 0 and max_distance has to be greater than min_distance
// Post: calls two functions to compute the probability for each distance and to print the result
void handle_walk(const int min_distance, const int max_distance)
{
  /* variable declaration and initialization */
  int casino;
  int current_position;
  int got_to_casino; // for number of times the adult got to the casino
  int probability_casino; // probability to go to casino
  int rand_int; // random integer
  int trial_walk; // total number of all the steps or moves
  int trial_walk_casino; // total number of all the steps or moves taken by adult and he ended at the casino
  int current_number_block; 
  float run_probability; // probability for each distance [min_distance, max_distance]

  for (int i = min_distance; i <= max_distance; i++) // loop for each distance
  {
    got_to_casino = HOME; // in the beginning, he's not been to casino yet, so 0
    casino = i + START_POSITION;
    trial_walk_casino = HOME;
    current_number_block = i;

    for (int i = 1; i <= NUM_RUN; i++) // loop for 10000 runs
    {
      probability_casino = HIGHEST_PROBABILITY; // for each run, chance to go casino is 100 at the very beginning
      trial_walk = HOME;
      current_position = START_POSITION;

      do
      {
        rand_int = rand() % (HIGHER_BOUND_RAND_NUMBER) + LOWER_BOUND_RAND_NUMBER; // random int between [1,100]

        if (rand_int <= probability_casino)
          current_position++;
        else
          current_position--;

        probability_casino -= PROBABILITY_DECREASE; // decreases by 5 after each move
        trial_walk++;

        if (current_position == casino)
        {
          got_to_casino++; // increment number of time he's been to casino
          trial_walk_casino += trial_walk; // updates with number of trial_walk that led to the casino
        }

      } while (current_position != HOME && current_position != casino && probability_casino != HOME); // until adult is home, at casino or probability to casino is 0
    }
    // these functions are called after each distance (i.e., 10000 runs)
    run_probability = compute_probability(got_to_casino);
    print_casino_probability(current_number_block, trial_walk_casino, run_probability);
  }
  return;
}


// Description: calculate the probability for the adult to get to the casino and returns it
// Pre: got_to_casino has to be positive
// Post: returns the computed probability
float compute_probability(const int got_to_casino)
{
  float probability_to_casino;

  probability_to_casino = (static_cast<float>(got_to_casino) / NUM_RUN) * HIGHEST_PROBABILITY;
  return probability_to_casino;
}


// Description: outputs the probality of an adult to go to the casino as well as the parameters of the experiment
// Pre: current_number_block has to be greater than 0
// Post: outputs the probality of an adult to go to the casino as well as the parameters of the experiment
void print_casino_probability(const int current_number_block, const int trial_walk_casino, const float run_probability)
{
  cout << "\nThe probality for a mid-life adult in crisis to walk " << current_number_block << " blocks to go to the casino based on " << NUM_RUN << " is ";
  cout << run_probability << "%.\nThe total number of successful trials to reach the casino (every step that led to the casino for each of the 10000 runs is " << trial_walk_casino << "." << endl;
  return;
}
