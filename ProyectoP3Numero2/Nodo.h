#pragma once
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

typedef struct Node {

	int valor;
	Node *derecha;
	Node *abajo;
} *node;



class Nodo
{
public:
	Nodo();


	static void NodoLinea(Node *& primerNodo, int data);
	static void CrearNodo(Node *&nodo, int data);
	static node CargarArchivo();
	static void salvarArchivo(Node *& matriz);
	static void CearMatriz(Node *& matriz, int data, int fila);
	static bool Dimenciones(std::string file);
	static void ImprimirM(Node *&matriz);
	static void GuardarD(int data);

};

