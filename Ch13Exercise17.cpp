// Kristoffer Carlino
// C++ 300
// Dr. Robert Flowers
// Module 11 - Chapter 13 Exercise 17.cpp
// 11/21/2025

#include <iostream>
#include <random>
#include <vector>
#include <stdexcept>
using namespace std;

// Custom exception type
class ThresholdException : public exception {
public:
    const char* what() const noexcept override {
        return "Too many random numbers fell inside the danger zone!";
    }
};

// Function to generate 25 random real numbers
vector<double> generateNumbers() {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dist(10.0, 100.0);

    vector<double> nums;
    for (int i = 0; i < 25; i++) {
        nums.push_back(dist(gen));
    }
    return nums;
}

int main() {

    cout << "This program generates 25 random numbers between 10 and 100.\n";
    cout << "Enter a range limit (example: 50 means numbers < 50 are counted): ";
    double limit;
    cin >> limit;

    cout << "How many numbers inside the range should trigger an exception? ";
    int threshold;
    cin >> threshold;

    try {
        vector<double> values = generateNumbers();

        int countInDangerZone = 0;

        cout << "\nGenerated values:\n";
        for (double v : values) {
            cout << v << endl;

            if (v < limit) {
                countInDangerZone++;
            }

            // Throw exception if threshold exceeded
            if (countInDangerZone > threshold) {
                throw ThresholdException();
            }
        }

        cout << "\nProgram completed without hitting the threshold.\n";
    }
    catch (const ThresholdException& e) {
        cout << "\nEXCEPTION OCCURRED: " << e.what() << endl;
    }
    catch (...) {
        cout << "\nAn unknown error occurred.\n";
    }

    return 0;
}

