#include<iostream>

using namespace std;

class Location {
private:
	int x;
	int y;
public:
	Location(int x, int y) {
		// This Keyword mean Pointer in C++.
		// So we need to use -> reference then . reference.
		this->x = x;
		this->y = y;
		// ... And we can know local variable is called first, and member variable is second.
	}

	// We can just implement in class, and out of class.
	// Like header file`s method / function implementing.
	void showLocation() {
		cout << "X: " << x << " Y: " << y << endl;
	}
	void initLocation();
	// Operator overloading is like below.
	Location operator+(Location &p) {
		return Location(x + p.x, y + p.y);
	}
	Location operator-(Location &p) {
		return Location(x - p.x, y - p.y);
	}
};

void Location::initLocation() {
	this->x = 0;
	this->y = 0;
}

int main() {
	// Constructor used like below.
	// not using new, but just simply call ().
	Location p1(2, 3);
	Location p2(4, 1);
	Location add = p1 + p2;
	add.showLocation();
	p1 = p2;
	p1.showLocation();
	p2.showLocation();
	return 0;
}