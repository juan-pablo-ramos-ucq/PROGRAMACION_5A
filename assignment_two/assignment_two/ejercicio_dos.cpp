/*
Ejercicio de estructuras y parámetros por referencia

Juan Pablo Ramos Escalona | Ingenieria en Software y Sistemas Computacionales | 47523

La r en el identificador significa Rect, la p parameter y b boolean.
*/
#include <iostream>
#include "ejercicio_dos.h"
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
		xF = 0;
		yF = 0;
		this->xO = xO;
		this->yO = yO;
		this->width = width;
		this->height = height;
	}

	Rect(double width, double height) : Rect(0, 0, width, height) {

	}
};

/*Juan Pablo Ramos Escalona | Ingenieria en Software y Sistemas Computacionales | 47523 */
void EjercicioDos() {
	Rect rectOne(5, 6, 0.5, 0.6);
	Rect rectTwo(5.1, 5.6, 0.2, 0.3);

	double xF1, yF1, xF2, yF2;

	if (CheckRect(rectOne, xF1, yF1) && CheckRect(rectTwo, xF2, yF2)) {
		//initializing final edge point of each struct
		rectOne.xF = xF1;
		rectOne.yF = yF1;
		rectTwo.xF = xF2;
		rectTwo.yF = yF2;

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

bool CheckRect(Rect& rP, double &xF, double &yF) {
	bool bReturn = false;

	/* checks if the attrbutes of Rect are positive or cero. No need to check xF and yF since they are a consecuence
	of the other attributes */
	if (rP.xO >= 0 && rP.yO >= 0 && rP.height >= 0 && rP.width >= 0) {
		bReturn = true;
		xF = rP.xO + rP.width;
		yF = rP.yO + rP.height;
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

/*
Resources:
https://www.desmos.com/calculator/h8io03mmwg
https://stackoverflow.com/questions/1185923/structure-prototype
*/