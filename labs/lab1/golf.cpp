/*
 * golf.cpp
 * purpose:      practice using booleans and constants
 * modified by: Alexander Tsuetaki
 * on date: 9/12/18
 */

#include <iostream>
#include <iomanip>

using namespace std;

// days of the week
const int SUN = 0, MON = 1, TUE = 2, WED = 3, THR = 4, FRI = 5, SAT = 6;

// constants for rules
const double    BASE_PRICE            = 9.0;
const int       HIGH_TEMP_CUTOFF      = 80;
const int       LOW_TEMP_CUTOFF       = 65;
const double    PER_DEGREE_PENALTY    = 0.10;
const int       EVENING_START         = 17;
const double    WEEKEND_EVE_SURCHARGE = 1.00;
const double    RAIN_PENALTY          = 2.00;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;

int main() 
{
        // -- define vars for input
        int     tempF, dayOweek, hour, rainP, windMPH;

        // -- a place to hold the price,
        // -- to be initialized and updated
        // -- based on the conditions below
        double  price;

        // -- set the precision used to output floating point numbers
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from user
        cout << "Temperature (degrees fahrenheit)? ";
        cin  >> tempF;

        cout << "Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? " ;
        cin  >> dayOweek;
        
        cout << "Hour of day (0..23)? ";
        cin  >> hour;

        cout << "Is it raining (0 = no, 1 = yes)? ";
        cin  >> rainP;

        cout << "Wind speed (MPH)? ";
        cin  >> windMPH;

        // -- compute price based on input values

        price = BASE_PRICE;             // start here then adjust
        //just what you think it is
	//checks if the temp is higher or lower than the thresholds
	//which cause a change in pricing and lowers the price accordingly
	if(tempF >HIGH_TEMP_CUTOFF){
		price -= (tempF-80)*PER_DEGREE_PENALTY;
	}                               
        if(tempF <LOW_TEMP_CUTOFF){
		price -= (65-tempF)*PER_DEGREE_PENALTY;
	}                                
 	

	// just what you think, checks if the day is sunday or saturday
	// or is past 5 pm
	// I Did not know if you wanted the weekend and evening
	// to compount, I asked the TA and he said that they did not
        if(dayOweek == SUN or dayOweek == SAT or hour > EVENING_START){
	        price +=WEEKEND_EVE_SURCHARGE;
	}

	// detects if raining then if raining takes out the rain penalty(2.00)
	if(rainP>=1){
		price -= RAIN_PENALTY;
	}

        // -- report price to user

        cout << "Price: " << price << endl;
        return 0;
}
