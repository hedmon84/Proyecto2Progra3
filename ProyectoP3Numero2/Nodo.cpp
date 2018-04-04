#include "Nodo.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#pragma warning(disable : 4996)
using namespace std;



	 Nodo::Nodo()
{
}


void Nodo::NodoLinea(Node *& primerNodo, int val) 
{
	node newVector = new Node();
	newVector->valor = val;
	newVector->derecha = 0;
	newVector->abajo = 0;

	if (primerNodo == 0) {
		primerNodo = newVector;
		return;
	} else {
		node tmp = primerNodo;

		while (tmp->derecha) {
			tmp = tmp->derecha;
		}

		tmp->derecha = newVector;
	}
}

void Nodo::CrearNodo(Node *& nodo, int val)
{
	node newNode = new Node();
	newNode->valor = val;
	newNode->abajo = 0;
	nodo = newNode;
}

void Nodo::CearMatriz(Node *& matriz, int val, int rowCount) {

	if (rowCount == 0) {
		NodoLinea(matriz, val);
	} else {
		node tmp = matriz, nodeBefore = 0;
		int row = 1;

		while (row < rowCount) {
			tmp = tmp->abajo;
			row++;
		}

		while (tmp->abajo != 0) {
			nodeBefore = tmp;
			tmp = tmp->derecha;
		}
		CrearNodo(tmp->abajo, val);

		if(nodeBefore != 0)
			nodeBefore->abajo->derecha = tmp->abajo;

	}

}

bool Nodo::Dimenciones(string file)
{
	ifstream fileMatrix(file);
	int valorTemp = 0, filas = 0, columnas = 0;
	string line;
	vector<int> contadorColumnas;

	while (getline(fileMatrix, line)) {
		stringstream values(line);
		while (values >> valorTemp) {
			columnas++;
		}
		contadorColumnas.push_back(columnas);
		columnas = 0;
		filas++;
	}
	fileMatrix.close();


	for (int i = 0; i < contadorColumnas.size(); i++)
	{
		for (int j = 0; j < contadorColumnas.size(); j++)
		{
			if (contadorColumnas[i] != contadorColumnas[j])
				return false;
		}
	}

	/*if (filas > 1 && contadorColumnas[0] == 1)
		return false;*/

	return true;

}

void Nodo::ImprimirM(Node *& matrix)
{

	node tmp = matrix;
	node head = tmp;
	while (tmp != 0) {

		while (tmp != 0) {
			cout << tmp->valor << '\t';
			tmp = tmp->derecha;
		}
		cout << endl;
		tmp = head->abajo;
		head = tmp;
	}

}

void Nodo::GuardarD(int valor)
{


	cout << "Respuesta Agregada en arhivos personales \n\n\n\n\n ";

	ofstream writer("Determinante.txt" );

	writer << "La determinante de la matriz es: " << valor << '\n';
	writer.close();

}

node Nodo::CargarArchivo()
{
	string fileName;
	int menu = 0;

	cout << "Ingrese el nombre del archivo de la matriz: ";
	cin >> fileName;


	ifstream matrixFromFile(fileName);

	while (!matrixFromFile) {
		cout << "Archivo no encontrado, Ingrese de nuevo el nombre (Ingrese -1 para regresar al menu): ";
		cin >> fileName;

		if (fileName == "-1") {
			cout << "\nEntendido, regresando al menu principal\n";
			return 0;

		}
		matrixFromFile.open(fileName);
	}

	if (Dimenciones(fileName ) == false) { //verificar que las columnas de cada fila de la matriz tengan el mismo tamaño
		cout << "Error: La Matriz es irregular, una columna de una fila no es igual que las demas(Asegurese que las columnas de cada fila tengan el mismo tamaño)" << endl;
		return 0;
	}

	node newMatrix = 0;
	string line;
	int value = 0, rowCounter = 0;

	while (getline(matrixFromFile, line)) { //Por cada linea
		stringstream linestream(line);

		while (linestream >> value) { //Por cada valor en la linea
			CearMatriz(newMatrix, value, rowCounter);
		}
		rowCounter++;
	}

	matrixFromFile.close();
	cout << " Matriz Correcta\n";
	return newMatrix;
}

void Nodo::salvarArchivo(Node *&matrix) {
	string fileName;

	cout << "***Respuesta Agregada en arhivos personales**** ";
	ofstream Escribir("Respuesta.txt", ios::app);

	node tmp = matrix;
	node head = tmp;
	while (tmp != 0) {

		while (tmp != 0) {
			Escribir << tmp->valor << ' ';
			tmp = tmp->derecha;
		}
		Escribir << endl;
		tmp = head->abajo;
		head = tmp;
	}
	Escribir.close();
}


