#include <iostream>
using namespace std;

struct Rect {
	//these constitute the initial edge point
	double xO;
	double yO;

	//use of the diagonally opposite corner of (x0, y0) for simplicity. These cooRdinates are the final edge point
	double xF;
	double yF;

	//displacement to the final edge point
	double height;
	double width;

	//we reused the parametrized constructor in multiple instances
	Rect() : Rect(0, 0, 0, 0) {

	}

	Rect(double xO, double yO, double width, double height) {
		//calculating the final edge point where the rect ends
		xF = xO + width;
		yF = yO + height;

		this->xO = xO;
		this->yO = yO;
		this->width = width;
		this->height = height;
	}

	Rect(double width, double height) : Rect(0, 0, width, height) {

	}
};

bool CheckRect(Rect& rP) {
	bool bReturn = false;

	/* checks if the attrbutes of Rect are positive or cero. No need to check xF and yF since they are a consecuence
	of the other attributes */
	if (rP.xO >= 0 && rP.yO >= 0 && rP.height >= 0 && rP.width >= 0) {
		bReturn = true;
	}
	else {
		cout << "Invalid coordinates or dimensions." << endl;
	}

	return bReturn;
}

bool CheckOverlap(Rect& rpOne, Rect& rpTwo) {
	bool bReturn = false;

	//checking if any of the edge points of rect_two overlaps horizontally with rect_one and vice versa.
	if (((rpTwo.xO >= rpOne.xO && rpTwo.xO <= rpOne.xF) || (rpTwo.xF >= rpOne.xO && rpTwo.xF <= rpOne.xF))
		|| ((rpOne.xO >= rpTwo.xO && rpOne.xO <= rpTwo.xF) || (rpOne.xF >= rpTwo.xO && rpOne.xF <= rpTwo.xF))) {

		//checking if any of the edge points of rect_two overlaps vertically with rect_one and vice versa.
		if (((rpTwo.yO >= rpOne.yO && rpTwo.yO <= rpOne.yF) || (rpTwo.yF >= rpOne.yO && rpTwo.yF <= rpOne.yF))
			|| ((rpOne.yO >= rpTwo.yO && rpOne.yO <= rpTwo.yF) || (rpOne.yF >= rpTwo.yO && rpOne.yF <= rpTwo.yF))) {
			bReturn = true;
		}
	}

	return bReturn;
}

void PrintRect(Rect& rP) {
	cout << "   - xO: " << rP.xO << endl;
	cout << "   - yO: " << rP.yO << endl;


	cout << "   - xF: " << rP.xF << endl;
	cout << "   - yF: " << rP.yF << endl;

	cout << "   - width: " << rP.width << endl;
	cout << "   - height: " << rP.height << endl;
}

void EjercicioDos() {
	Rect rectOne(10.3, 10.5, 0.2, 0.2);
	Rect rectTwo(10, 10, 1, 1);

	if (CheckRect(rectOne) && CheckRect(rectTwo)) {
		cout << "Rect One: " << endl;
		PrintRect(rectOne);

		cout << endl;

		cout << "Rect Two: " << endl;
		PrintRect(rectTwo);

		cout << endl;

		string bReturn = (CheckOverlap(rectOne, rectTwo) == true) ? "Yes" : "No";
		cout << "Rect one and two overlap? " << bReturn << endl;
	}
}

/*
Resources:
https://www.desmos.com/calculator/h8io03mmwg
https://stackoverflow.com/questions/1185923/structure-prototype
*/