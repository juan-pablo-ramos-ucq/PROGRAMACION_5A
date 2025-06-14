#include <iostream>
using namespace std;

void EjercicioTres() {
	float* pF = nullptr;
	pF = new float(7.77);

	float vF = 6.66;

	pF = &vF;
	cout << "Cuidado, acabas de causar un memory leak!" << endl;
	cout << endl;
	cout << "Un memory leak es cuando una localidad de memoria dinamica" << endl;
	cout << "no puede ser accedida en absoluto ya que todos sus apuntadores" << endl;
	cout << "dejaron de apuntar a esa localidad. Por ende, se le conoce memory leak" << endl;
	cout << "porque no la puedes liberar, reduciendo la memoria dinamica disponible" << endl;
	cout << "hasta que termine la ejecucion de tu programa." << endl;
	cout << endl;
	cout << "Para evitar memory leaks libera la memoria del apuntador con delete" << endl;
	cout << "antes de cambiar su direccion. Despues asignale la direccion deseada." << endl;
	cout << "Si consideras que el apuntador ahora no sera de utilidad, asginale nullptr." << endl;

	pF = new float(1984);
	float* pF1 = pF;
	delete pF;
	pF = nullptr;

	if (pF == nullptr) {
		cout << endl;
		cout << "La variable pF es igual a nullptr" << endl;
	}
	else if (pF == NULL) {
		cout << endl;
		cout << "La variable pF es igual a NULL" << endl;
	}

	if(!(pF1 == NULL || pF1 == nullptr)) {
		cout << endl;
		cout << "pF1 apunta a una localidad de memoria que no es NULL ni nullptr por lo que potencialmente es basura." << endl;
		cout << "Se recomienda tener cuidado ya que es una localidad de memoria que no le corresponde y puede interferir otro proceso. " << endl;
	}
}