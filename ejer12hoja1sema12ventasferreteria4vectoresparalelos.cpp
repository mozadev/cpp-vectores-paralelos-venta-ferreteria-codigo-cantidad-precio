
#include "stdafx.h"
#include<iostream>
#include<conio.h>
#include <stdlib.h>
#include<time.h>

using namespace std;
using namespace System;
void IngresoDatos(int *N, int *Codigo, int *Cantidad, float *Unitario, float *Ptotal)
{
	for (int i = 0; i < *N; i++)
	{
		cout << "Ingrese codigo No" << i + 1 << ":"; cin >> Codigo[i];
		cout << "Ingrese cantidad No" << i + 1 << ":"; cin >> Cantidad[i];
		cout << "Ingrese precio unitario No" << i + 1 << ":"; cin >> Unitario[i];
		Ptotal[i] = Cantidad[i] * Unitario[i];
		cout << endl;

	}
}
void ImprmirirDatos(int *N, int *Codigo, int *Cantidad, float *Unitario, float *Ptotal)
{
	cout << "REPORTE DE DATOS" << endl << endl;
	cout << "N°" << "\t" << "CODIGO" << "\t" << "CANT." << "\t" << "P_U" << "\t" << "P_TOTAL" << endl;
	for (int i = 0; i < *N; i++)
		cout << i + 1 << "\t" << Codigo[i] << "\t" << Cantidad[i] << "\t" << Unitario[i] << "\t" << Ptotal[i] << endl;
}
float TotalVenta(int *N, float *Ptotal)
{
	float Suma = 0;
	for (int i = 0; i < *N; i++)
		Suma = Suma + Ptotal[i];
	return Suma;
}
float MayorVenta(int *N, float *Ptotal)
{
	float Mayor = Ptotal[0];
	for (int i = 1; i < *N; i++)
		if (Mayor < Ptotal[i])
			Mayor = Ptotal[i];
	return Mayor;
}
int MasCaro(int *N, float *Unitario, int *Codigo)
{
	float Mayor = Unitario[0];
	int Cod = Codigo[0];
	for (int i = 1; i < *N; i++)
		if (Mayor < Unitario[i])
		{
			Mayor = Unitario[i];
			Cod = Codigo[i];
		}
	return Cod;
}

int main()
{
	int N;
	int *Codigo, *Cantidad;
	float *Unitario, *Ptotal;
	cout << "Ingrese N:"; cin >> N;
	Codigo = new int[N];
	Cantidad = new int[N];
	Unitario = new float[N];
	Ptotal = new float[N];
	IngresoDatos(&N, Codigo, Cantidad, Unitario, Ptotal);
	ImprmirirDatos(&N, Codigo, Cantidad, Unitario, Ptotal);
	cout << "Total ventas es:" << TotalVenta(&N, Ptotal) << endl;
	cout << "El mayor ingreso es:" << MayorVenta(&N, Ptotal) << endl;
	cout << "El el producto mas caro :" << MasCaro(&N, Unitario, Codigo) << endl;
	delete[] Codigo;
	delete[] Cantidad;
	delete[] Unitario;
	delete[] Ptotal;
	_getch();
}