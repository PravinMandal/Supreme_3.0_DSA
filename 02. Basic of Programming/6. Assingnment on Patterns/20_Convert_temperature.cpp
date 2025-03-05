//leetcode: 2469. Convert the Temperature
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        vector<double> ans;

        double kelvin = celsius + 273.15;
        double fahrenheit = celsius * 1.80 + 32.00;

        ans.push_back(kelvin);
        ans.push_back(fahrenheit);
        return ans;
    }
};

int main() {
    Solution sol;
    double celsius = 36.50; // Example input: 36.50°C
    vector<double> result = sol.convertTemperature(celsius);
    
    cout << "Kelvin: " << result[0] << ", Fahrenheit: " << result[1] << endl;
    
    return 0;
}
