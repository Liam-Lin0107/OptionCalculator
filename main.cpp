#include <iostream>
#include "src/Simulation/Simulator/PathIndependentSimulation/SimpleMCSimulation.h"
//#include "PayOff/EuropeanCall.h"
//#include "PayOff/EuropeanPut.h"
#include "src/Discount/Discount.h"
#include "src/Statics/SummaryStatistics.h"
#include "src/PayOff/HW1_Option.h"

// Hyper-parameters <----
int N = 1000000; // size in one batch
int n = 20; // batch size
double S = 100, r = 0.05, q = 0.02, T = 0.4, sigma = 0.3;
double K = 100; // strike price
double K1, K2, K3, K4;

bool userInput();

int main() {

    bool continueCondition = true;
    while (continueCondition) {

        // user input data
        bool rightInput = userInput();

        // deal with wrong data input
        while (!rightInput){
            return 0;
        }

        // simulator
        SimpleMCSimulation* ptr_simulator = new SimpleMCSimulation(N, n, S, r, q, T, sigma);

        // choose call function and setting the strike price
        HW1_Option* ptr_optionPayoff  = new HW1_Option(K1, K2, K3, K4);

        // calculate the payoffMatrix
        (*ptr_optionPayoff)(ptr_simulator);

        // constantDiscount it, then get n value in values vector
        vector<long double> optionValues = constantDiscount(*ptr_optionPayoff, r, T);


        // Summary
        cout << "Option Summary: " << endl;
        Summary::summary(optionValues);
        cout << endl;

        char userInput;
        cout << "Exit ? (y/N):";
        cin >> userInput;
        continueCondition = (userInput != 'y');

    }
    cout << "See you~" << endl;

    return 0;
}


bool userInput(){

    cout << "Please, enter the following parameters" << endl;
    cout << "Stock price: ";
    cin >> S;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        cin.clear();
        return false;
    }


    cout << "Risk-free rate: ";
    cin >> r;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Dividend yield: ";
    cin >> q;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Time to maturity day: ";
    cin >> T;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Volatility: ";
    cin >> sigma;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }


    cout << "Please, enter K1, K2, K3, K4 (need press enter for each parameter)" << endl;
    cin >> K1;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cin >> K2;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cin >> K3;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cin >> K4;
    if (cin.fail()) {
        cerr << "Wrong Type input" << endl;
        return false;
    }

    cout << "Computing........" << endl << endl;
    return true;
}