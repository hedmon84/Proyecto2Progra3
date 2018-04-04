#include "Matriz.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#pragma warning(disable : 4996)

using namespace std;

Matriz::Matriz()
{
}




void Matriz::AgregarMatriz() {

	cout << "\n SUMA \n";

	node matriz1 = Nodo::CargarArchivo();

	if (matriz1 == 0) {
		return;
	}
	cout << "\n\ Matriz 1\n" << endl;
	Nodo::ImprimirM(matriz1);

	node matriz2 = Nodo::CargarArchivo();

	if (matriz2 == 0) {
		return;
	}

	cout << "\n\t Matriz  2 \n" << endl;
	Nodo::ImprimirM(matriz2);

	if (Dimenciones_Matricez(matriz1, matriz2) == false) {
		return;
	}

	node newMatrix = 0;
	node tmpA = matriz1, tmpB = matriz2, tmpC = matriz1;

	int columnsMatrixA = Matriz::get_columna(matriz1);
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matriz1 = tmpA;
		matriz2 = tmpB;
		while (count < columnsMatrixA) {
			Nodo::CearMatriz(newMatrix, matriz1->valor + matriz2->valor, rowCounter);
			matriz1 = matriz1->derecha;
			matriz2 = matriz2->derecha;
			count++;
		}

		tmpA = tmpA->abajo;
		tmpB = tmpB->abajo;

		rowCounter++;
		count = 0;
		tmpC = tmpC->abajo;
	}

	
	Nodo::salvarArchivo(newMatrix);
	cout << "\n\***** Puede ver su archivo en su carpeta Personal  de Respuestas*****\n" << endl;

	delete newMatrix, matriz1, matriz2;
	cout << endl;
}

void Matriz::SacarMatriz() {
	cout << "\n  RESTA\n";

	//Pedir la primera matriz
	node matrix1 = Nodo::CargarArchivo();

	if (matrix1 == 0) {
		return;
	}
	cout << "\n\ Matriz 1\n" << endl;
	Nodo::ImprimirM(matrix1);

	node matriz2 = Nodo::CargarArchivo();

	if (matriz2 == 0) {
		return;
	}

	cout << "\n\ Matriz 2\n" << endl;
	Nodo::ImprimirM(matriz2);

	if (Dimenciones_Matricez(matrix1, matriz2) == false) { //verificar que as matrices tengan el mismo tamaño n x n
		return;
	}

	node newMatrix = 0;
	node tmpA = matrix1, tmpB = matriz2, tmpC = matrix1;
	int columnsMatrixA = Matriz::get_columna(matrix1);
	
	int count = 0, rowCounter = 0;
	while (tmpC != 0) {
		matrix1 = tmpA;
		matriz2 = tmpB;
		while (count < columnsMatrixA) {
			Nodo::CearMatriz(newMatrix, matrix1->valor - matriz2->valor, rowCounter);
			matrix1 = matrix1->derecha;
			matriz2 = matriz2->derecha;
			count++;
		}
		tmpA = tmpA->abajo;
		tmpB = tmpB->abajo;

		rowCounter++;
		count = 0;
		tmpC = tmpC->abajo;
	}



	Nodo::salvarArchivo(newMatrix);
	cout << "\n\ Puede ver su archivo en su carpeta Personal  de Respuestas\n" << endl;
	

}

void Matriz::Multiplicar() {
	cout << "\n MULTIPLICACION \n";

	node matriz1 = Nodo::CargarArchivo();

	if (matriz1 == 0) {
		return;
	}
	cout << "\n\tImprimiendo Primera Matriz\n" << endl;
	Nodo::ImprimirM(matriz1);

	node matriz2 = Nodo::CargarArchivo();

	if (matriz2 == 0) {
		return;
	}

	cout << "\n\tImprimiendo Segunda  Matriz\n" << endl;
	Nodo::ImprimirM(matriz2);

	int columnsMatrixA = Matriz::get_columna(matriz1);
	int rowsMatrixA = Matriz::get_Filas(matriz1);
	int columnsMatrixB = Matriz::get_columna(matriz2);
	int rowsMatrixB = Matriz::get_Filas(matriz2);

	if (columnsMatrixA != rowsMatrixB) {
		cout << "Error: No se puede hacer la multiplicion de estas matrices! Las columnas de la primera matriz tienen que ser iguales a las filas de la segunda matriz\n";
		return;
	}

	int rowCounter = 0;

	node newMatrix = 0;
	node tmpA = matriz1, tmpB = matriz2, tmpC = matriz1;

	node helperTmpA = tmpA, helperTmpB = tmpB;
	while (tmpC != 0) {

		tmpA = helperTmpA;
		tmpB = helperTmpB;
		int contador = 0;

		while (contador < columnsMatrixB) {
			int resultado = 0;

			while (tmpA != 0) {
				resultado += tmpA->valor * tmpB->valor;
				tmpA = tmpA->derecha;
				tmpB = tmpB->abajo;
			}

			Nodo::CearMatriz(newMatrix, resultado, rowCounter);
			tmpA = helperTmpA;
			helperTmpB = helperTmpB->derecha;
			tmpB = helperTmpB;
			contador++;
			resultado = 0;
		}

		helperTmpA = helperTmpA->abajo;
		helperTmpB = matriz2;
		tmpC = tmpC->abajo;
		rowCounter++;
	}



	Nodo::salvarArchivo(newMatrix);
	cout << "\n\ Puede ver su archivo en su carpeta Personal  de Respuestas\n" << endl;
	
}

void Matriz::Determinante() {
	cout << "\n DETERMINANTE DE MATRIZ \n";

	node matriz1 = Nodo::CargarArchivo();

	if (matriz1 == 0) 
		return;

	int columns = Matriz::get_columna(matriz1);
	int rows = Matriz::get_Filas(matriz1);

	if (rows != columns) {
		cout << "\nLa matriz es irregular, las filas y columnas tienen que ser iguales (1 x 1, 2 x 2, 3 x 3)\n";
		return;
	}

	if (rows >= 4 || columns >= 4) {
		cout << "\nLa matriz tiene que ser : 1 x 1, 2 x 2, 3 x 3, no mayor a eso(en este proyecto)\n";
		return;
	}

	node tmp = matriz1; 

	int determinant = ((rows != 1) ? ((rows == 2) ? get_Det2(matriz1) : get_Det3(matriz1)) : tmp->valor); //Dependiendo del tamaño de la matriz, se llamara a su funcion respectiva


	cout << "La determinante es: " << determinant << endl;
	Nodo::GuardarD(determinant);

}

int Matriz::get_columna(Node*& matrix)
{
	node tmp = matrix;
	int count = 0;

	while (tmp != 0) {
		tmp = tmp->derecha;
		count++;
	}

	return count;
}

int Matriz::get_Filas(Node *&matrix) {

	node tmp = matrix;
	int count = 0;

	while (tmp != 0) {
		tmp = tmp->abajo;
		count++;
	}

	return count;
}

bool Matriz::Dimenciones_Matricez(Node *& A, Node *& B)
{
	int columnsMatrixA = Matriz::get_columna(A);
	int rowsMatrixA = Matriz::get_Filas(A);

	int columnsMatrixB = Matriz::get_columna(B);
	int rowsMatrixB = Matriz::get_Filas(B);


	if (columnsMatrixA != columnsMatrixB || rowsMatrixA != rowsMatrixB) {
		cout << "\nError: Las dimensiones de las matrices no son iguales (En suma o resta de matrices las dos matrices tienen que tener las mismas dimensiones)\n" << endl;
		return false;
	}
	return true;
}

int Matriz::get_Det2(Node *& matrix)
{
	node tmp = matrix;
	node helper = tmp;
	int x1, x2, y1, y2;

	x1 = tmp->valor;
	x2 = tmp->abajo->derecha->valor;
	y1 = tmp->derecha->valor;
	y2 = tmp->abajo->valor;
	
	return (x1 * x2) - (y1 * y2);

}

int Matriz::get_Det3(Node *& matrix)
{
	node tmp = matrix;
	node helper = tmp;

	int a11, a12, a13;
	int a21, a22, a23;
	int a31, a32, a33;

	a11 = tmp->valor;
	a12 = tmp->derecha->valor;
	a13 = tmp->derecha->derecha->valor;
	a21 = tmp->abajo->valor;
	a22 = tmp->abajo->derecha->valor;
	a23 = tmp->abajo->derecha->derecha->valor;
	a31 = tmp->abajo->abajo->valor;
	a32 = tmp->abajo->abajo->derecha->valor;
	a33 = tmp->abajo->abajo->derecha->derecha->valor;

	return ((a11 * a22 * a33) + (a12 * a23 * a31) + (a21*a32*a13)) - ((a13 * a22 * a31) + (a12 * a21 * a33) + (a23 * a32 * a11));


}

