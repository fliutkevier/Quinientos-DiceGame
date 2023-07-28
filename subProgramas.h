#pragma once
#ifndef SUBPROGRAMAS_H_INCLUDED
#define SUBPROGRAMAS_H_INCLUDED

void PosicionamientoXY(int, int);

void MenuPrincipal();
void RecuadroDePantalla();
void FinDeJuego();

int movimientoFlechaAbajo(int);
int movimientoFlechaArriba(int);

void CargarNombre(char[], char[], char[], char[], bool);

void LanzamientoYContadorDeDados(int[], int[]);
void CombinacionesGanadoras(int[], int[], int, int&, int&);

void Partida(char[], char[], int&, bool);

void PantallaGanadora(char[], char[], int, int, bool);

void InterfazDuranteLaPartida(char[], int, int, int, int);

void PantallaEntreTurnos(int, char[], char[], int, int, bool, bool);

void EncontrarMaximaPuntuacion(char[], char[], int&, char[], char[], int);
void MostrarMaximaPuntuacion(char[], char[], int);

#endif // SUBPROGRAMAS_H_INCLUDED
