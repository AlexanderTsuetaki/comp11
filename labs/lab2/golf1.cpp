/*
 * Comp 11
 * Lab 1
 * 
 * golf.cpp
 *
 * purpose: practice using booleans, conditionals, and constants
 *
 *          Program reads data about temperature, day, time, wind,
 *          whether it's raining, then prints out the price of
 *          admission to Minnie's Mini Golf for those conditions.
 *
 * modified by:  Mark A. Sheldon
 * on:           Fall 2018
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
const int       RAIN_YES              = 1;
const int       WIND_GRANULARITY      = 15;
const double    WIND_PENALTY          = 1.50;


int main() 
{
        // -- define vars for input and a value used in the tests below
        int     tempF, dayOweek, hour, rainP, windMPH;
        double  price;

        //
        // Avoid unused variable warnings
        //
        (void) MON; 
        (void) TUE; 
        (void) WED; 
        (void) THR; 
        (void) FRI;

        // -- set the precision 
        cout << setiosflags(ios::fixed) << setprecision(2);
        
        // -- Get data from user
        cout << "Temperature (fahrenheit)? ";
        cin  >> tempF;

        cout << "Day of week (0 = Sun, 1 = Mon, ..., 6 = Sat)? " ;
        cin  >> dayOweek;
        
        cout << "Hour of day (0..23)? ";
        cin  >> hour;

        cout << "Is it raining (0 = no, 1 = yes)? ";
        cin  >> rainP;

        cout << "Wind speed (MPH)? ";
        cin  >> windMPH;

        // -- compute price based on these values

        price = BASE_PRICE;             // start here then adjust

        //
        // Adjust for temperature
        //
        if (tempF > HIGH_TEMP_CUTOFF) {
                int degrees_too_high = tempF - HIGH_TEMP_CUTOFF;
                price -= PER_DEGREE_PENALTY * degrees_too_high;
        } else if (tempF < LOW_TEMP_CUTOFF) {
                int degrees_too_low = LOW_TEMP_CUTOFF - tempF;
                price -= PER_DEGREE_PENALTY * degrees_too_low;
        }
        
        //
        // Adjust for peak time periods
        //
        if ((dayOweek == SAT) or (dayOweek == SUN) or (hour > EVENING_START))
                price += WEEKEND_EVE_SURCHARGE;
        
        //
        // Adjust for rain
        //
        if (rainP == RAIN_YES)
                price -= RAIN_PENALTY;

        //
        // Adjust for wind:  subtract for each WIND_GRANULARITY unit,
        //                   but NOT each fraction thereof.
        //                   I. e., if WIND_GRANULARITY is 15, then
        //                   20 MPH of wind only gets 1 WIND_PENALTY.
        //
        price -= (windMPH / WIND_GRANULARITY) * WIND_PENALTY;

        // -- report price to user

        cout << "Price: " << price << endl;

        return 0;
}
