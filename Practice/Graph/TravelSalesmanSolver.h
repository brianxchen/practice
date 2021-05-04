#pragma once
#include "..\Common.h"

class TravelSalesmanSolver {
public:
	vector<bool> visitedCities;
	vector<vector<int>> AdjacentMatrix;
	vector<string> cityNames;
	vector<int> bestPath;
	vector<int> path;
	int numCities;
	int minCost;
	TravelSalesmanSolver(vector<vector<int>> AdjacentMatrix) {
		this->AdjacentMatrix = AdjacentMatrix;
		this->numCities = AdjacentMatrix.size();
		for (int i = 0; i < numCities; i++) {
			visitedCities.push_back(false);
		}
		this->minCost = 999999;
		cityNames.push_back("SEA");
		cityNames.push_back("SF");
		cityNames.push_back("LA");
		cityNames.push_back("CHI");
		cityNames.push_back("STL");
		cityNames.push_back("NYC");
		cityNames.push_back("ATL");
	}
	void PrintPath(int c, vector<int>& p) {
		printf("%d: %s", c, cityNames[0].c_str());
		for (int i = 0; i < numCities; i++) {
			printf(" -> %s", cityNames[p[i]].c_str());
		}
		printf("\n");
	}
	void Travel(int currCity, int numCitiesVisited, int totalCost) {
		// end condition if we have visited every city AND the last city is SEA
		if (numCitiesVisited == numCities && currCity == 0) {
			if (totalCost < minCost) {
				minCost = totalCost;
				bestPath = path;
			}
			PrintPath(totalCost, path);
			return;
		}

		for (int i = 0; i < AdjacentMatrix[currCity].size(); i++) {
			// check adjacency matrix - move is valid if path != 0 and we haven't visited the city yet
			if (AdjacentMatrix[currCity][i] != 0 && !visitedCities[i]) {
				// don't check city 0 unless we're at the last step
				if (i == 0 && numCitiesVisited != numCities - 1) {
					continue;
				}
				visitedCities[i] = true;
				path.push_back(i);
				// recurse with incremented values
				Travel(i, numCitiesVisited + 1, totalCost + AdjacentMatrix[currCity][i]);
				path.pop_back();
				visitedCities[i] = false;
			}
		}
	}
	void Solve() {
		Travel(0, 0, 0);
		printf("min cost = %d\n", minCost);
		PrintPath(minCost, bestPath);
	}
};

void TestTravelSalesman() {
	TravelSalesmanSolver t({
		{0, 137, 0, 157, 0, 237, 0},
		{137, 0, 98, 179, 274, 0, 0},
		{0, 98, 0, 0, 206, 0, 130},
		{157, 179, 0, 0, 206, 111, 0},
		{0, 274, 206, 206, 0, 197, 157},
		{237, 0, 0, 111, 197, 0, 83},
		{0, 0, 130, 0, 157, 83, 0}
		});
	t.Solve();

}