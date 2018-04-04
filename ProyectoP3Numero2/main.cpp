
#include <iostream>
#include <string>
#include "Matriz.h"
using namespace std;


int main() {
	int menu = 0;

	string fileName, punto = ".";

	do {
		cout << "\n1. Sumar matrices\n2. Restar matrices\n3. Multiplicar Matrices\n4. Sacar Determinante\n5. Cambiar la extension del archivo\n6. Salir\nIngrese lo que quiere hacer: ";
		cin >> menu;


		switch (menu) {

		case 1:
			
			system("cls");
			Matriz::AgregarMatriz();
			break;
		case 2:
			
			system("cls");
			Matriz::SacarMatriz();
			break;
		case 3:
			
			system("cls");
			Matriz::Multiplicar();
			break;
		case 4:
			//Determinante
			system("cls");
			Matriz::Determinante();
			break;

		case 5:
			cout << "\nIngrese la nueva extension (sin el punto .) [La extension actual es: "  << "]: ";
			cin >> fileName;
		
			cout << "\nExtension cambiada, ahora durante la ejecucion del programa todos los archivos a leer o a guardar se escribiran con esta nueva extension \""+ punto + fileName+ "\"!\n\n";
			break;

		}

		
	} while (menu != 6);


}




