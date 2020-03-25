#include <iostream>

using namespace std;

class Robot{
private:
	int prevX, prevY;
	int currX, currY;
public:
	Robot(int x, int y): currX(x), currY(y) {}
	void moveX(int moveX) {prevX = currX; currX += moveX;}
	void moveY(int moveY) {prevY = currY; currY += moveY;}
	void printPrevCoord() {cout << "Previous coordinates: " << prevX << "," << prevY << endl;}
	void printCurrCoord() {cout << "Current coordinates: " << currX << "," << currY << endl;}
	void printLastMove() {cout << "Last move: " << (currX - prevX) << "," << (currY - prevY) << endl;}
};

int main(){
	// Initialize a robot
	Robot rbt1(10,10);

	// Move the robot
	rbt1.moveX(1);
	rbt1.moveY(2);

	// Print information
	rbt1.printPrevCoord();
	rbt1.printCurrCoord();

	// Print last move information
	rbt1.printLastMove();

	return 0;
}
