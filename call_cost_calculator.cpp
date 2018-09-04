/*** 
Kevin Da Silva      Total Points: 100
Due Date: 08/30/18 
Course: COP3014
Assignment: Assignment #1 "Call Cost Calculator"
Professor: Dr. Lofton Bullard


Description: Program will calculate the net cost of a call (net_cost), the tax on a call (call_tax) and the total cost of the 
call(total_cost).

    - Outputs: net_cost, call_tax, and total_cost. 
    - Inputs: cell_num, relays, call_length from user.

    1. Calculating the tax_rate on a call.
        a. if  relays is 0 <= relays <= 5 then, --> tax_rate = 1%
        b. if  relays is 6 <= relays <= 11 then, --> tax_rate = 3%
        c. if  relays is 12 <= relays <= 20 then, --> tax_rate = 5%
        d. if  relays is 21 <= relays <= 50 then, --> tax_rate = 8%
        e. if  relays > 50 then, tax_rate = 12%

    2. Calculating Net Cost (net_cost) of a call.
        a. net_cost = (relays / (50 * 0.40 * call_length))
    
    3. Calculating the total tax on a call (call_tax).
        a. call_tax = net_cost * tax_rate / 100

    4. Calculating the total cost of a call (total_cost).
        a. total_cost = net_cost + call_tax

    5. Format the code to the output below: 
        
    
***/ 

#include <iostream>
#include <string> 

using namespace std; 

int call_cost(){ 
    printf('Call Cost!\n');
    cout << "Call Cost whoo!\n!";
}


int main(){ 
    string user_response = "y";
    while (user_response == "y" || user_response = "Y"){ 
        call_cost();
        cout << "Would you like to do another calculation? (Y or N): \n";
        cin >> user_response;
    }
    return 0;
}