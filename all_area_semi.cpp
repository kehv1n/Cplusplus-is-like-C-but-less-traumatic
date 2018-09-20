/***
Kevin Da Silva                   Z#: z23290034
Total Points: 100
Due Date: 09/20/18
Course: COP3014
Assignment: Program Assignment #4  all_area_semi_.cpp
Professor: Dr. Lofton Bullard


Description:
  In this assignment a program called all_area_semi_.cpp will help calculate the area & semi-perimeter of any arbitrary triangle,
  granted that they pass the triangle inequality rule. The program asks the user for 3 inputs (doubles) and outputs them to the screen.
***/


#include <iostream>
#include <string>
// lets get fancyYYYYYy with this math library bihhhhh
#include <math.h>

using namespace std;


// function proto's
void Calculate(double side_a, double side_b, double side_c, double  &the_area, double &the_semi);


// round my answers to the NEAREST hundreths place ie 1.845 => 1.85
double roundToHundredths(double x){
    cout << x << endl;
    x /=100;
    cout << x << endl;
    return floor(x + 0.5) * 100;
}

// print to the screen so the user knows they're not crazy
void output( double a, double b, double c, double semiPerimeter, double area){

    // just round dem boio's
    double rounded_area = roundf(area * 100) / 100;
    double rounded_semi = roundf(semiPerimeter * 100) / 100;

    cout << "THE SIDES ENTERED" << endl;
    cout << "===========================" << endl;
    cout << "A: " << a << endl;
    cout << "B: " << b << endl;
    cout << "C: " << c << endl;
    cout << endl;
    cout << "THE AREA AND SEMI-PERIMETER" << endl;
    cout << "===========================" << endl;
    cout << "AREA: " << rounded_area << endl;
    cout << "SEMI-PER: " << rounded_semi << endl;
    cout << endl;

}



double get_area(double semiPerimeter, double a, double b, double c) {
    double eval = semiPerimeter * ((semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
    double the_area = sqrt(eval);
    return the_area;

}

bool get_triangleInequality(double a, double b, double c){
    if (a + b > c && a + c > b && b + c > a) {
        // These are valid sides;
        return true;
    } else {
        // These are NOT valid sides;
        cout << "Please remember that: the sum of any 2 sides of a triangle must be greater "
                "than the measure of the third side. Note: This rule must be satisfied for all 3 conditions "
                "of the sides." << endl;
        return false;
    }

}


/*******************************************************************
// Name: Calculate
// Instructions:  Include a void function call “Compute” that computes the area and perimeter
//  of a triangle based on the length of the sides. The function should use five
//  parameters –three call by value parameters (a, b, c) that provide the lengths
//  of the edges and two call by reference parameters (area, semiperimeter) that
//  stores the computed area and perimeter. Make your function robust.  The function
//  “Compute”should be called from your main program.

// Precondition: Before the function is called, make sure there are 3 sides initialized within main and the user has successfully
// assigned the 3 values of the triangle (A, B, C).
// Postcondition: After Calculate() has been called, 3 helper functions have been called to calculate check for appropriate sides,
// calculating the semi-perimeter, calculating the area, and outputting it. The values of area and semi perimeter passed in from main() have been changed.
// Purpose: Calculate the AREA and SEMIPERIMETER
// Parameters:
EXAMPLES:
    double side_a = 7;
    double side_b = 7;
    double side_c = 11;

    double the_area = 23.82;
    double the_semi = 12.5;


********************************************************************/

void Calculate(double side_a,double side_b, double side_c, double &ar, double &semi){


// Only if the user enters the right params of a triangle
if (get_triangleInequality(side_a, side_b, side_c) == true) {

    // Lets calculate the semi-perimeter that needs to be used in our Area equation later on
    semi = (side_a + side_b + side_c) / 2;

    // Now lets calculate the area
    ar = get_area(semi, side_a, side_b, side_c);


    // Display it to our user in a friendly manner
    output(side_a, side_b, side_c, semi, ar);
}




}


int main() {
    string user_response = "y";

    // These are the call by value parameters, they will be inputted into Calculate.
    // They will remain these constant values below within the scope of "this" main function.

    double a;
    double b;
    double c;


    // These are the call by reference parameters, they will be inputted into Calculate.
    // They will be inputted via reference, and their memory addresses will be sent so they will change
    // once Calculate is called as their "new" value will be written over the original, old inputted value.

    double area = 1;
    double semiPerimeter = 1;




    while (user_response == "y" || user_response == "Y"){

        cout << " Please enter 3 sides of a triangle to calculate its area and semi-perimeter I guess... \n";
        cout << " Please enter side A \n";
        cin >> a;
        cout << " Please enter side B \n";
        cin >> b;
        cout << " Please enter side C (note, it must be the longest side)! \n";
        cin >> c;

        Calculate(a, b, c, area, semiPerimeter);

        cout << "Would you like to do another calculation? (Y or N): \n";
        cin >> user_response;

    }
    return 0;
}



