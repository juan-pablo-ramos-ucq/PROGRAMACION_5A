/* 
Ejercicio de arrays y arrays como parámetros 

Juan Pablo Ramos Escalona | Ingenieria en Software y Sistemas Computacionales | 47523 

La a o A en el identificador significa array y la p parameter.
*/
#include <iostream>
#include "ejercicio_uno.h"
using namespace std;


/*Juan Pablo Ramos Escalona | Ingenieria en Software y Sistemas Computacionales | 47523 */
void Ejercicio_uno() {
	bool aBool[5];
	SetA(aBool, 5); //se inicializa a indices pares false e impares true

	cout << "Indices pares false e impares true: ";
	PrintA(aBool, 5);


	int aInt[10];

	cout << "int array initialized from 0 to 9: ";
	SetA(aInt, 10); //setA tiene adentro in PrintA intermedio; no es necesario imprimir aqui.

	cout << "Despues de hacer modulo con dos al int array: ";
	PrintA(aInt, 10); /*Imprimir despues que finaliza setA.Ver definicion de setA para entender los 
	prints*/

	cout << endl;

	cout << "------ Memory addresses of int array ------" << endl;
	PrintMemory(aInt, 10);
}

/* Sobrecarga de metodos */
void SetA(bool pABool[], int aSize) {
	/*
	shift cambia de verdadero a falso y viceversa en cada iteracion.
	Después de cambiar un elemento con el valor dinamico de shift,
	se invierte el shift para preparse para la siguiente iteracion.

	Se usa el ! para que entre por primera vez al if y pueda operar de
	manera automata la condición.
	*/
	bool shift = false;
	for (int i = 0; i < aSize; i++) {
		if (!shift) {
			pABool[i] = shift;
			shift = true;
			continue;
		}
		pABool[i] = shift;
		shift = false;
	}
}

void SetA(int pAInt[], int aSize) {
	//inicializar del 0 al 9
	for (int i = 0; i < aSize; i++) {
		pAInt[i] = i;
	}

	//imprimir la inicializacion del 0 al 9
	PrintA(pAInt, aSize);

	//re-inicializar reemplazando los pares con false e impares con true
	for (int i = 0; i < aSize; i++) {
		pAInt[i] = pAInt[i] % 2;
	}

	//nota: el efecto de re-inicializar se imprimira en el main
}

/* Templates */
template <typename T>
void PrintA(T pABool[], int aSize) {
	cout << "["; /*de primera instancia, imprime [ antes de imprimir todos los
	elementos del arreglo*/
	for (int i = 0; i < aSize; i++) {
		if (i < (aSize - 1)) /* checa si el elemento no es el ultimo */ {
			cout << *(pABool + i) << ", "; /*si es asi, ocupan comas para separar a su contiguo derecho*/
		}
		else {
			cout << *(pABool + i); /* si no es asi, es el ulitmo, y no tiene contiguo derecho por lo
			que no ocupa coma y solo debe imprimirse */
		}
	}
	cout << "]"; /*despues de imprimir todo los elementos del arreglo, cierra con ]*/
	cout << endl;
}

void PrintMemory(int pAInt[], int aSize) {
	int* aux = pAInt;
	cout << "{"; /*de primera instancia, imprime { antes de imprimir todos los elementos del arreglo*/
	for (int i = 0; i < aSize; i++) {
		if (i < (aSize - 1)) /* checa si el elemento no es el ultimo */ {
			/*si es asi, ocupan comas para separar a su contiguo derecho*/
			cout << aux + i << ": " << *(aux + i) << ", " << endl;
		}
		else {
			/* si no es asi, es el ulitmo, y no tiene contiguo derecho por lo
			que no ocupa coma y solo debe imprimirse al final } */
			cout << aux + i << ": " << *(aux + i) << "}" << endl;
		}
	}
}

/* Recursos:
https://cplusplus.com/forum/general/6755/
*/