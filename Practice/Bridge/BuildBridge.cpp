#include "..\Common.h"
#include "BuildBridge.h"
#include "City.h"

bool CompareCityByNorthIncreasing(const City a, const City b) {
    return a.north > b.north;
}

int Bridge(vector<City> cities) {
    sort(cities.begin(), cities.end(), CompareCityByNorthIncreasing);
    int length = cities.size();
    vector<int> f(length); // saved results of LIS that ends at i
    int overallMax = -1;
    int overallMaxLocation;


    for (int i = 0; i < length; i++) { // loop through all possible i
        int maxSoFarEndAtI = 1; // minimum length of I is 1
        for (int j = 0; j < i; j++) { // compares subproblems to i
            if (cities[j].south < cities[i].south) {
                if (f[j] + 1 > maxSoFarEndAtI) {
                    maxSoFarEndAtI = f[j] + 1;
                }
            }
        }
        printf("Max so far ending at %d = %d\n", i, maxSoFarEndAtI);
        f[i] = maxSoFarEndAtI; // Update solution array 
        if (maxSoFarEndAtI > overallMax) {
            overallMax = maxSoFarEndAtI;
            overallMaxLocation = i;
        }
    }

    return overallMax;
}
    
void TestBridges() {
	vector<City> cities;
	cities.push_back(City(1, 4));
	cities.push_back(City(2, 6));
    cities.push_back(City(5, 9));
	cities.push_back(City(3, 1));
	cities.push_back(City(4, 5));

    cout << Bridge(cities);
}