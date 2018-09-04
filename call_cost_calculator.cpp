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
#include <iomanip>

using namespace std; 
using std::setw;

double get_tax_rate(double n_relays){ 
  /*** 
   1. Calculating the tax_rate on a call.
        a. if  relays is 0 <= relays <= 5 then, --> tax_rate = 1%
        b. if  relays is 6 <= relays <= 11 then, --> tax_rate = 3%
        c. if  relays is 12 <= relays <= 20 then, --> tax_rate = 5%
        d. if  relays is 21 <= relays <= 50 then, --> tax_rate = 8%
        e. if  relays > 50 then, tax_rate = 12%
  ***/

  double tax_rate;
  if (n_relays >= 0 && n_relays <= 5){ 
    tax_rate = 0.01;
  }
  else if (n_relays >= 6 && n_relays <= 11){ 
    tax_rate = 0.03;
  }
  else if (n_relays >= 12 && n_relays <= 20){ 
    tax_rate = 0.05;
  }
  else if (n_relays >= 21 && n_relays <= 50){ 
    tax_rate = 0.08;
  }
  else if (n_relays > 50){ 
    tax_rate = 0.12;
  }
  else { 
    cout << "Please enter a whole integer number for the number of relays! \n ";
  }
  return tax_rate;
}




double get_net_cost(double n_relays, double call_len){ 
  /***
    2. Calculating Net Cost (net_cost) of a call.
      a. net_cost = (relays / (50 * 0.40 * call_length))
  ***/
  // cout << n_relays << call_length;
  double net;
  if (n_relays != 0 || call_len != 0){ 
    net = (n_relays / (50 * 0.40 * call_len));
    return net;
  }
  else {
   net = 0;
   return net;
  }
  
}


double get_total_tax(double net, double rate){ 
  /***
   3. Calculating the total tax on a call (call_tax).
      a. call_tax = net_cost * tax_rate / 100
      b. Drop the "/100" portion if the rate is not a percentage 
  ***/
  double call_tax = (net * rate);
  return call_tax;
}

void fancy_print(double cnum, double rel, double clen, double netc, double tax, double totalc){ 
  cout << setw(20) << "Field" << setw(20) << "Format" << endl;
  cout << "==========================" << endl;
  cout << setw(20) << "Cell Phone" << setw(20) << cnum << endl;
  cout << setw(20) << "Number of Relay Stations" << setw(20) << rel << endl;
  cout << setw(20) << "Minutes Used" << setw(20) << clen << endl;
  cout << setw(20) << "Net Cost" << setw(20) << netc << endl;
  cout << setw(20) << "Call Tax" << setw(20) << tax << endl;
  cout << setw(20) << "Total Cost of Call" << setw(20) << totalc << endl;
}


int call_cost(){ 
    // printf('Call Cost!\n');
    double cell_num, relays, call_length;

    // Get user input and save to the var's above
    cout << "Please enter your cell number.\n";
    cin >> cell_num; 
    cout << "Please enter the number of relays on the call..\n";
    cin >> relays;
    cout << "Please enter the total amount of minutes spent on the call!\n";
    cin >> call_length;
    //// end of user input //// 

    // Lets first calculate the tax_rate    
    double tax_rate = get_tax_rate(relays);
    
    // Now lets calculate the net cost of the call
    double net_cost = get_net_cost(relays,call_length);
    // cout << net_cost << endl;

    // Now lets calculate the total tax on a call 
    double call_tax = get_total_tax(net_cost, tax_rate);

    // Finally, calculate the total cost of the call
    double call_total = net_cost + call_tax; 

    // Set the preicision of the output stream 
    // std::cout << std::setprecision(2) << "The total of the call was: " << call_total << endl;

   // Now, lets print everything out in that
   // futile formatting you're insisting we use..
   
    fancy_print(cell_num, relays, call_length, net_cost, call_tax, call_total);
    
    return 0;
}


int main(){ 
    string user_response = "y";
    while (user_response == "y" || user_response == "Y"){ 
        call_cost();
        // cout << "Would you like to do another calculation? (Y or N): \n";
        cin >> user_response;
    }
    return 0;
}