#include <iostream>
#include <iomanip>
#include <cstring>
#include "parallel_tracks.h"

using std::cin, std::cout, std::endl;

//-------------------------------------------------------
// Name: prep_double_array
// PreCondition:  an array of doubles is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_double_array(double ary[])
// making sure all values within the array are set to 0.0;
{
  //TODO
  for (unsigned int i = 0; i<SIZE; i++){
	ary[i] = 0.0;
  }
}

//-------------------------------------------------------
// Name: prep_unsigned_int_array
// PreCondition:  an array of unsigned ints is passed in
// PostCondition: data in the array is 'zeroed' out
//---------------------------------------------------------
void prep_unsigned_int_array(unsigned int ary[])
// making sure all values within the array are set to 0;
{
  //TODO
  for (unsigned int i = 0; i<SIZE; i++){
	ary[i] = 0;
  }
}

//-------------------------------------------------------
// Name: prep_string_array
// PreCondition:  an array of strings is passed in
// PostCondition: each element in the array is set to "N/A"
//---------------------------------------------------------
void prep_string_array(char ary[][STRING_SIZE])
// making sure all values within the array are set to "N/A";
{
	//TODO
	for(unsigned int i = 0; i<SIZE; i++){
	strcpy(ary[i], "N/A");
  }
}

//-------------------------------------------------------
// Name: trim
// PreCondition:  the cstring
// PostCondition: whitespace has been removed from beginning and end of string
//---------------------------------------------------------
void trim(char str[STRING_SIZE]) {
	// TODO
	for (unsigned int i = 0; i < strlen(str); i++){
		if(isspace(str[i])) {
			continue;
		}
		else {
			if (i > 0) {
			    int terminatingIndex = 0;
				for (unsigned int i2 = 0; i2 < strlen(str)-i; i2++)
				{
					str[i2] = str[i+i2];
					terminatingIndex = i2;
				}
				str[terminatingIndex+1] = '\0';
			}
		}
		break;
	}
	for (int j = strlen(str) - 1; j >= 0; --j) {
    if (isspace(str[j])) {
        str[j] = '\0';
    } else {
        break;
    }
}
}

//-------------------------------------------------------
// Name: get_runner_data
// PreCondition:  the prepped parallel arrays
// PostCondition: all arrays contain data from standard in
//---------------------------------------------------------
bool get_runner_data(double timeArray[], char countryArray[][STRING_SIZE], 
		unsigned int numberArray[], char lastnameArray[][STRING_SIZE]) 
{
  //TODO
  for (unsigned int i = 0; i<SIZE; i++){
	cin >> timeArray[i] >> countryArray[i] >> numberArray[i] >> lastnameArray[i];
	if (timeArray[i] < 0.0){
		return false;
	}
	if (countryArray[i][0] == '\0'){
		return false;
	}
	if (strlen(countryArray[i]) != 3){
		return false;
	}
	for (unsigned int j = 0; j<3; j++){
			if (!isalpha(countryArray[i][j])||!isupper(countryArray[i][j])){
				return false;
			}
    }
	if (numberArray[i] > 99){
		return false;
	}
	trim(lastnameArray[i]);
	if (lastnameArray[i][0] == '\0'||strlen(lastnameArray[i])<=1){
		return false;
	}
	for (unsigned int j = 0; j<strlen(lastnameArray[i]); j++){
		if (!isalpha(lastnameArray[i][j])&&lastnameArray[i][j] != ' '){
			return false;
		}
	}
  }
  return true;// set so it will compile
}

//-------------------------------------------------------
// Name: get_ranking
// PreCondition:  just the time array is passed in, and has valid data
// PostCondition: after a very inefficient nested loop to determine the placements 
// and places the ranks in a new array. That new array is returned
//---------------------------------------------------------
void get_ranking(const double timeArray[], unsigned int rankArray[])
{
	//TODO
	double bar = 0;
	unsigned int actualRank = 1;
	while (actualRank <= SIZE){
		double lowest = 10000000;
		for (unsigned int i = 0; i<SIZE; i++){
			if (timeArray[i]>bar && timeArray[i]<lowest){
				lowest = timeArray[i];
				rankArray[i] = actualRank;
			}
		}
		bar = lowest;
		actualRank = actualRank+1;
	}
}


//-------------------------------------------------------
// Name: print_results
// PreCondition:  all parallel arrays are passed in and have valid data
// PostCondition: after a very inefficient nested loop to determine the ranks
// it then displays them along with a delta in time from the start
//---------------------------------------------------------
void print_results(const double timeArray[], const char countryArray[][STRING_SIZE],
		const char lastnameArray[][STRING_SIZE], const unsigned int rankArray[])
{

	std::cout << "Final results!!";
	std::cout << std::setprecision(2) << std::showpoint << std::fixed << std::endl;
	double best_time = 0.0;
		
	// print the results, based on rank, but measure the time difference_type
	for(unsigned int j = 1; j <= SIZE; j++)
	{
		
		// go thru each array, find who places in "i" spot
		for(unsigned int i = 0; i < SIZE; i++)
		{
			if(rankArray[i] == 1) // has to be a better way, but need the starting time
			{
				best_time = timeArray[i];
			}
			
			
			if(rankArray[i] == j) // then display this person's data
			{
				// this needs precision display
				std::cout << "[" << j << "]  " << timeArray[i] << " " << std::setw(15) << std::left << lastnameArray[i] << "\t" << "(" << countryArray[i] << ")  +" << (timeArray[i] - best_time) << std::endl; 
			}
			
		}
	}	
}