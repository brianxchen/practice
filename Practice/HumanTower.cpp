#include "Common.h"
#include "HumanTower.h"
#include "Human.h"

bool CompareHumanFunctionWeightDominant(Human a, Human b) {
    if (a.weight == b.weight) {
        return a.height < b.height;
    }
    return a.weight < b.weight;
}
bool CompareHumanFunctionHeightDominant(Human a, Human b) {
    if (a.height == b.height) {
        return a.weight < b.weight;
    }
    return a.height < b.height;
}

void PrintArray(vector<Human>& a) {
    for (auto x : a) {
        cout << "Weight = " << x.weight << ", Height = " << x.height << "\n";
    }
}

int HumanTower(vector<Human> humans) {
    sort(humans.begin(), humans.end(), CompareHumanFunctionWeightDominant);
    PrintArray(humans);
    int length = humans.size();
    vector<int> f(length); // saved results of LIS that ends at i
    vector<int> backtrack(length);
    int overallMax = -1;
    int overallMaxLocation;


    for (int i = 0; i < length; i++) { // loop through all possible i
        int maxSoFarEndAtI = 1; // minimum length of I is 1
        backtrack[i] = -1;
        for (int j = 0; j < i; j++) { // compares subproblems to i
            if (humans[j].height < humans[i].height && humans[j].weight < humans[i].weight) { 
                if (f[j] + 1 > maxSoFarEndAtI) {
                    maxSoFarEndAtI = f[j] + 1;
                    backtrack[i] = j;
                }
            }
        }
        printf("Max so far ending at %d = %d, backtrack = %d\n", i, maxSoFarEndAtI, backtrack[i]);
        f[i] = maxSoFarEndAtI; // Update solution array 
        if (maxSoFarEndAtI > overallMax) {
            overallMax = maxSoFarEndAtI;
            overallMaxLocation = i;
        }
    }
    
    int curr = overallMaxLocation;
    while (curr != -1) {
        cout << humans[curr].ToString() << "\n";
        curr = backtrack[curr];
    }

    return overallMax;
}


void TestHumanTower() {
    vector<Human> humans;
    humans.push_back(Human(1, 100, "a"));
    humans.push_back(Human(50, 65, "b"));
    humans.push_back(Human(98, 5, "c"));
    humans.push_back(Human(95, 96, "d"));
    humans.push_back(Human(53, 78, "e"));
    humans.push_back(Human(2, 98, "f"));

    cout << "Max human tower = " << HumanTower(humans) << "\n";

}