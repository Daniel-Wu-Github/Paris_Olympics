/******************************************************************************

File: main.cpp
Author: Prof. Lupoli & Andrew Nemec
Date: 2/16/2021
Section: 
E-mail: slupoli@tamu.edu
Description:
This file contains C++  code that will simulate data collected from a track 
event with 9 lanes. The code will sort the order, then display the results

Updates
Author: J. Michael Moore & Paul Taele
Author: J. Michael Moore

Input information format
<Time (double)> <Abbreviated Country (String)> <Uniform number (int)> <Lastname (String)>
32.7 USA 12 Moore
36.5 RUS 35 Polsley
45.8 ENG 73 Teale
52.34 CHN 14 Nemec
76.45 ITY 23 Lupoli     

*******************************************************************************/

#include <iostream>
#include <cstring>
#include "parallel_tracks.h"

using std::cin; using std::cout; using std::endl;

int main()
{
    // TODO: create arrays needed
	double time[SIZE];
    char country[SIZE][51];
    unsigned int jerseyNumber[SIZE];
    char lastName[SIZE][51];
    unsigned int rank[SIZE];

    // TODO: prep all arrays
    prep_double_array(time);
    prep_string_array(country);
    prep_unsigned_int_array(jerseyNumber);
    prep_string_array(lastName);
    prep_unsigned_int_array(rank);
	
    // TODO: load the runner's data into the array
    // if unable to load runner data
    //   1) output "Bad input" to standard out
    //   2) exit program by returning 1
    if (!get_runner_data(time, country, jerseyNumber, lastName)){
        cout << "Bad input" << endl;
        return 1;
    }
    // TODO: determine ranking, notice the rank array receives the results
    get_ranking(time,rank);
    // TODO: Output results
    print_results(time, country, lastName, rank);
    // this is not required in C++ but many people still explitly add it
    return 0; 
}

