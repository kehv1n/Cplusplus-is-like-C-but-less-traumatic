/*** 
Kevin Da Silva                   Z#: z23290034
Total Points: 100
Due Date: 09/13/18
Course: COP3014
Assignment: Program Assignment #3  call_stats.cpp
Professor: Dr. Lofton Bullard


Description: 
  In this assignment a program called call_stats.cpp will help process customer call records.
  The program uses 3 main functions (input, process, and output) and 4 worker functions (get_tax_rate, tax_rate,
  get_net_costs, get_total_tax) This program also uses input/output streaming
***/ 


#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std; 
using std::setw;


/***********************************************************************************
 * Following is the decleration of a call record
 *************************************************************************************/
class call_record {
public:
    string cell_number;
    int relays;
    int call_length;
    double net_cost;
    double tax_rate;
    double call_tax;
    double total_cost;

};



// Function Prototypes:
// Declaration of function without its body to give compiler information about user-defined function.
void Input(ifstream &, call_record &);
//void Process(const call_record &);
//void Output(const call_record &);


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
      a. net_cost = ((relays / 50) * 0.40 * call_length)
  ***/
  // cout << n_relays << call_length;
  double net;
  if (n_relays != 0 || call_len != 0){ 
    net = ((n_relays / 50) * 0.40 * call_len);
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



// void Output(const string cell_num, const double relays, const int call_len, const double & net_cost, cost double & call_tax, const double & call_total);

int main(){

    call_record my_record; // Create a record called my_record of type (Class) call_record

    ifstream my_input; // declaring an input filestream call "my_input"
    my_input.open("call_data.txt"); // open a file called "call_data.txt"

    if (my_input.fail()) { // if the file failed to open
        cout << "Input file did not open correctly, please try again later.";

    } else {


        // as long as the end of the file HAS NOT been reached
        while(!my_inpt.eof()){
            Input(my_input, my_record);
        }


    }



    return 0;
}

// *******************************************************************
// Name: Input 
// Precondition: Before input is called, you must have the three inputs to the  input function created (string cell number,double # of relays,double call length).
// Postcondition: The user has now assigned & initialized new values to the 3 parameters passed in initially.
// Description: Function inputs 3 parameters: string of cell phone number, the amount of relays as a double, and the call length as a double.
// Purpose: To give users the ability to input their cell number, relays, and call length and later output the total cost of the call 
// Parameters: 
  /** EXAMPLES:
    string cell_num = "954-888-8888"; OR "9548888888";
    double relays: 12;
    double call_len = 12;
  **/
// ********************************************************************* 
void Input(ifstream & in, call_record & customer_record){
  // Get user input and save to the var's above
    in >> customer_record.cell_number;
    in >> customer_record.relays;
    in >> customer_record.call_length;

    printf(customer_record);
}






//
//
//// *******************************************************************
//// Name: Process
//// Precondition: Before the function is called, relays and call_len must be initialized and passed in as read-only parameters and the net_cost, call_tax and call_total must be initialized and passed in as reference parameters.
//// Postcondition: After the function is called, net_cost, call_tax and call_total will be changed and re-assigned new values based on what the user entered and what the functions returned before.
//// Description: Responsible for calling the functions that re-assign, net_cost, tax on the call and the total tax. It also sets the tax rate from another funtion.
//// Purpose: Process the net_cost, the tax on a specific call, and the total cost.
//// Parameters:
//  /** EXAMPLES:
//    double relays: 12;
//    double call_len = 12;
//    double net_cost = 12.01;
//    double call_tax = 5;
//    double call_total = 0;
//  **/
//// *********************************************************************
//void Process(
//      const double relays,
//      const double call_len,
//      double & net_cost,
//      double & call_tax,
//      double & call_total
//  ){
//
//    // Lets first calculate the tax_rate
//    double tax_rate = get_tax_rate(relays);
//    // cout << tax_rate << "<--- Tax Rate";
//
//    // Now lets calculate the net cost of the call
//    net_cost = get_net_cost(relays, call_len);
//    // cout << net_cost <<"<====The net cost" <<endl;
//
//    // Now lets calculate the total tax on a call
//    call_tax = get_total_tax(net_cost, tax_rate);
//    // cout << call_tax <<"<====The call_tax" <<endl;
//
//     // Finally, calculate the total cost of the call
//    call_total = net_cost + call_tax;
//    // cout << call_total << "<---- the total" << endl;
//
//}
//
//
//// *******************************************************************
//// Name: Output
//// Precondition: Before the fucntion is called, cell_num, relays, call_len, net_cost, call_tax, and call_total are all initialized and re-assigned by the user and the Process function below
//// Postcondition: After the function is called, the user will see a formatted output of the parameters and their results on the screen.
//// Description: Function prints out formatted inputs
//// Purpose: Print out formatted inputs to users screen.
//// Parameters:
//  /** EXAMPLES:
//    string cell_num = 954-999-9999;
//    double relays: 12;
//    double call_len = 12;
//    double net_cost = 12.01;
//    double call_tax = 5;
//
//  **/
//// *********************************************************************
//
//void Output(
//  const string cell_num,
//  const double relays,
//  const double call_len,
//  const double & net_cost,
//  const double & call_tax,
//  const double & call_total
//  ){
//
//
// cout << "*****************************************************" << endl;
// cout << "Cell Phone Number: " << cell_num << endl;
// cout << "*****************************************************" << endl << endl;
// cout << "Number of Relay Stations:  " << setw(6) << relays << endl << endl;
// cout << "Length of Call in Minutes: " << setw(6) << call_len << endl << endl;
// // "magic formula"
// cout.setf(ios::showpoint);
// cout.precision(2);
// cout.setf(ios::fixed);
//
// cout << "Net Cost of Call:         " << setw(10) << net_cost << endl << endl;
// cout << "Tax of Call:                " << setw(8) << call_tax << endl << endl;
// cout << "Total Cost of Call:       " << setw(10) << call_total << endl << endl;
//}