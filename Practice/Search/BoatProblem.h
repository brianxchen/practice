#pragma once
#include "..\Common.h"

class BoatProblem {
	public:
		// Every time you're initializing array, if and only if the  
		// entire array is the default value, you can just set the first one.
		bool OnLeft[3] = { true, true, true };

		bool done = false;
		map<string, bool> seen;
		vector<string> solution;
		BoatProblem() {
		
		}
		string GetKey(bool HumanIsOnLeft) {
			string key = to_string(HumanIsOnLeft);
			for (int i = 0; i < 3; i++) {
				key = key + to_string(OnLeft[i]);
			}
			return key;
		}


		bool IsValid(bool HumanIsOnLeft) {
			if (OnLeft[0] == true && OnLeft[1] == true && !HumanIsOnLeft) {
				return false;
			}
			if (OnLeft[1] == true && OnLeft[2] == true && !HumanIsOnLeft) {
				return false;
			}
			if (OnLeft[0] == false && OnLeft[1] == false && HumanIsOnLeft) {
				return false;
			}
			if (OnLeft[1] == false && OnLeft[2] == false && HumanIsOnLeft) {
				return false;
			}
			string key = GetKey(HumanIsOnLeft);
			if (seen.count(key) == 1) {
				return false;
			}
			return true;
		}
		void Move(int step) {
			bool HumanIsOnLeft = (step % 2 == 0);

			cout << step << "," << GetKey(HumanIsOnLeft) <<  endl;

			seen[GetKey(HumanIsOnLeft)] = true;

			if (OnLeft[0] == false && OnLeft[1] == false && OnLeft[2] == false && !HumanIsOnLeft) {
				for (auto x : solution) {
					cout << x;
				}
				cout << "------------------\n";
				seen[GetKey(HumanIsOnLeft)] = false;
				return;
			}


			//Just move human
			if (IsValid(!HumanIsOnLeft)) {
				if (HumanIsOnLeft) {
					solution.push_back("step " + to_string(step) + ": move human right\n");
				}
				else {
					solution.push_back("step " + to_string(step) + ": move human left\n");
				}
				Move(step + 1);
				solution.pop_back();
			}

			// Move human and wolf
			if (HumanIsOnLeft == OnLeft[0]) {
				OnLeft[0] = !OnLeft[0];
				if (IsValid(!HumanIsOnLeft)) {
					if (HumanIsOnLeft) {
						solution.push_back("step " + to_string(step) + ": move human and wolf right\n");
					}
					else {
						solution.push_back("step " + to_string(step) + ": move human and wolf left\n");
					}
					Move(step + 1);
					solution.pop_back();
				}
				OnLeft[0] = !OnLeft[0];
			}
			// Move human and goat
			if (HumanIsOnLeft == OnLeft[1]) {
				OnLeft[1] = !OnLeft[1];
				if (IsValid(!HumanIsOnLeft)) {
					if (HumanIsOnLeft) {
						solution.push_back("step " + to_string(step) + ": move human and goat right\n");
					}
					else {
						solution.push_back("step " + to_string(step) + ": move human and goat left\n");
					}
					Move(step + 1);
					solution.pop_back();
				}
				OnLeft[1] = !OnLeft[1];
			}
			// Move human and cabbage
			if (HumanIsOnLeft == OnLeft[2]) {
				OnLeft[2] = !OnLeft[2];
				if (IsValid(!HumanIsOnLeft)) {
					if (HumanIsOnLeft) {
						solution.push_back("step " + to_string(step) + ": move human and cabbage right\n");
					}
					else {
						solution.push_back("step " + to_string(step) + ": move human and cabbage left\n");
					}
					Move(step + 1);
					solution.pop_back();
				}
				OnLeft[2] = !OnLeft[2];
			}

			// Remove key - not setting to false, because if it's false it's still in the map
			seen.erase(GetKey(HumanIsOnLeft));
		}
		void SolveBoatProblem() {
			Move(0);
		}
};

void BoatSolver() {
	BoatProblem b;
	b.SolveBoatProblem();
}