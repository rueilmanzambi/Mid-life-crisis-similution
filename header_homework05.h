// Programmer: Rueil Manzambi           Section: 109
// Date: March 10, 2021
// File: header_homework05.h
// Purpose: This is the header file for the main file main_homework05.cpp

#ifndef HEADER_HOMEWORK05_H
#define HEADER_HOMEWORK05_H
 
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/* Constants initialization */
const int NUM_RUN = 10000; 
const int PROBABILITY_DECREASE = 5; // every move decreases chance to go to casino by 5
const int HIGHEST_PROBABILITY = 100;
const int LOWER_BOUND_RAND_NUMBER = 1; 
const int HIGHER_BOUND_RAND_NUMBER = 100;
const int START_POSITION = 1; // adult always starts at 1
const int HOME = 0; // home is always at block 0

/* Functions prototypes */
int get_min_distance();
int get_max_distance(const int min_distance);
float compute_probability(const int got_to_casino);
void print_casino_probability(const int current_number_block, const int trial_walk_casino, const float run_probability);
void handle_walk(const int min_distance, const int max_distance);


#endif 
