#pragma once
#include "Nodo.h"


class Matriz
{
public:
	Matriz();

	static void AgregarMatriz();
	static void SacarMatriz();
	static void Multiplicar();
	static void Determinante();
	static int get_columna(Node*& matrix);
	static int get_Filas(Node *& matrix);
	static bool Dimenciones_Matricez(Node *& a, Node *&b);
	static int get_Det2(Node *&m);
	static int get_Det3(Node *&m);
	
};

