#include "Rectangle.h"
#include "RectangleSolver.h"
#include "Cell.h"
#include "../Common.h"
/*
	Problem: given coordinates for n rectangles, where rectangles can overlap,
	calculate the area and perimeter of the overall shape.
*/
vector<float> verticalLines;
vector<float> horizontalLines;
vector<vector<bool>> cellMap;

bool rectangleEquals(float a, float b) {
	return abs(a - b) < 0.0001;
}

// Two helper functions that returns an int representing the row/col index
// from a given float. This will help us translate between the artificial 
// axis values to something regular
int getVerticalCellIndex(float x) {
	for (int i = 0; i < verticalLines.size(); i++) {
		if (rectangleEquals(verticalLines[i], x)) {
			return i;
		}
	}
	return -1;
}
int getHorizontalCellIndex(float x) {
	for (int i = 0; i < horizontalLines.size(); i++) {
		if (rectangleEquals(horizontalLines[i], x)) {
			return i;
		}
	}
	return -1;
}
void SolveRectangleHelper(vector<Rectangle*> rectangles) {
	/*
		Initializing the row and col vectors.
		We push a 0 and 100 (100 being our large "upper bound")
		so that we can handle perimeter on the edges.
	*/
	verticalLines.push_back(0);
	horizontalLines.push_back(0);
	verticalLines.push_back(100);
	horizontalLines.push_back(100);
	// Push all the left/right/top/bottom values into the above arrays
	for (int i = 0; i < rectangles.size(); i++) {
		verticalLines.push_back(rectangles[i]->left);
		verticalLines.push_back(rectangles[i]->right);
		horizontalLines.push_back(rectangles[i]->top);
		horizontalLines.push_back(rectangles[i]->bottom);
	}
	// Normalize by sorting them
	sort(verticalLines.begin(), verticalLines.end());
	sort(horizontalLines.begin(), horizontalLines.end());


	//printf("x index = %d, y index = %d\n", getVerticalCellIndex(3.1, verticalLines), getHorizontalCellIndex(4.3, horizontalLines));
	
	// Now initialize the cellMap with all falses
	for (int row = 0; row < horizontalLines.size(); row++) {
		vector<bool> tempRow;
		for (int col = 0; col < verticalLines.size(); col++) {
			tempRow.push_back(false);
		}
		cellMap.push_back(tempRow);
	}

	// and loop through each cell, marking "true" if it is part of a rectangle
	for (int i = 0; i < rectangles.size(); i++) {
		for (int row = getHorizontalCellIndex(rectangles[i]->top); row < getHorizontalCellIndex(rectangles[i]->bottom); row++) {
			for (int col = getVerticalCellIndex(rectangles[i]->left); col < getVerticalCellIndex(rectangles[i]->right); col++) {
				cellMap[row][col] = true;
			}
		}
	}
	float area = 0;
	float perimeter = 0;

	for (int row = 0; row < horizontalLines.size(); row++) {
		for (int col = 0; col < verticalLines.size(); col++) {
			if (cellMap[row][col] == false) {
				continue;
			}
			float width = verticalLines[col + 1] - verticalLines[col];
			float height = horizontalLines[row + 1] - horizontalLines[row];
			area += width * height;

			if (cellMap[row - 1][col] == false) {
				perimeter += width;
			}
			if (cellMap[row + 1][col] == false) {
				perimeter += width;
			}
			if (cellMap[row][col - 1] == false) {
				perimeter += height;
			}
			if (cellMap[row][col + 1] == false) {
				perimeter += height;
			}
		}
	}
	printf("area = %f, perimeter = %f\n", area, perimeter);


}

void SolveRectangles() {
	vector<Rectangle*> rectangles;
	// check email for drawing ("rectangle area perimeter problem")
	rectangles.push_back(new Rectangle(2.5, 5.6, 3.3, 5.2));
	rectangles.push_back(new Rectangle(1.2, 3.1, 4.3, 8.2));

	SolveRectangleHelper(rectangles);

}