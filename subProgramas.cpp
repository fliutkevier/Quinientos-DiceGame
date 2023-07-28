# include <iostream>
# include <cstdlib>
# include <stdlib.h>
# include <time.h>
# include "subProgramas.h"
# include "rlutil.h"

using namespace std;

void PosicionamientoXY(int posicionX, int posicionY)
{
	rlutil::locate(posicionX, posicionY);
}


void MenuPrincipal()
{
	RecuadroDePantalla();

	PosicionamientoXY(46, 9);
	cout << "BIENVENIDOS A QUINIENTOS" << endl;

	for (int i = 0; i < 24; i++)
	{
		PosicionamientoXY(46 + i, 10);
		cout << (char)205;
	}

	PosicionamientoXY(49, 13);
	cout << "    UN JUGADOR" << endl;
	PosicionamientoXY(49, 14);
	cout << "   DOS JUGADORES" << endl;
	PosicionamientoXY(49, 15);
	cout << "PUNTUACION MAS ALTA" << endl;
	PosicionamientoXY(49, 16);
	cout << "      SALIR" << endl;
}

void RecuadroDePantalla()
{
	for (int i = 0;i < 18;i++) {

		PosicionamientoXY(25, 7 + i);
		cout << (char)219 << endl;
	}

	for (int i = 0;i < 18;i++) {
		PosicionamientoXY(90, 7 + i);
		cout << (char)219 << endl;
	}


	for (int i = 0;i < 50;i++) {
		PosicionamientoXY(33 + i, 26);
		cout << (char)254 << endl;
	}

	for (int i = 0;i < 50;i++) {
		PosicionamientoXY(33 + i, 4);
		cout << (char)254 << endl;
	}
}

void FinDeJuego()
{
	rlutil::cls();
	RecuadroDePantalla();

	PosicionamientoXY(47, 12);
	cout << "HASTA LUEGO..." << endl;
	exit(0);
}

int movimientoFlechaAbajo(int y)
{
	PosicionamientoXY(48, 13 + y);
	cout << " " << endl;

	y++;

	if (y > 3)
	{
		return y = 3;
	}
	else
	{
		return y;
	}
}

int movimientoFlechaArriba(int y)
{
	PosicionamientoXY(48, 13 + y);
	cout << " " << endl;

	y--;

	if (y < 0)
	{
		return y = 0;
	}
	else
	{
		return y;
	}
}

void CargarNombre(char nombreJugador1[], char apellidoJugador1[], char nombreJugador2[], char apellidoJugador2[], bool DosJugadores)
{

	rlutil::cls();
	RecuadroDePantalla();

	PosicionamientoXY(49, 13);
	cout << "INGRESE SU NOMBRE:";
	PosicionamientoXY(53, 14);
	cin >> nombreJugador1;

	PosicionamientoXY(48, 16);
	cout << "INGRESE SU APELLIDO:";
	PosicionamientoXY(52, 17);
	cin >> apellidoJugador1;

	if (DosJugadores)
	{
		rlutil::cls();

		RecuadroDePantalla();

		PosicionamientoXY(39, 13);
		cout << "INGRESE EL NOMBRE DEL SEGUNDO JUGADOR: " << endl;
		PosicionamientoXY(55, 14);
		cin >> nombreJugador2;

		PosicionamientoXY(38, 16);
		cout << "INGRESE EL APELLIDO DEL SEGUNDO JUGADOR: " << endl;
		PosicionamientoXY(54, 17);
		cin >> apellidoJugador2;
	}
}

void LanzamientoYContadorDeDados(int dados[], int contador[])
{
	int i, j;

	PosicionamientoXY(55, 13);
	cout << "DADOS";


	srand(time(NULL));
	for (i = 0; i < 6; i++)
	{
		dados[i] = 1 + rand() % (7 - 1);
		PosicionamientoXY(50 + i * 3, 15);
		cout << dados[i];
	}


	for (i = 0;i < 6;i++)
	{
		contador[i] = 0;
	}


	for (i = 0;i <= 5;i++)
	{
		for (j = 1;j <= 6;j++)
		{
			if (dados[i] == j)
			{
				contador[j - 1]++;
			}
		}
	}

}

void CombinacionesGanadoras(int dados[], int contDados[], int cantidad, int& puntos, int& puntosTotales)
{
	int contTrioX = 0, mayorDado = 0, contEscalera = 0, cara;
	int i, x;
	bool banSumaDados = false, banTrioX = false, banSextetoX = false;
	puntos = 0;

	for (i = 0;i <= 5;i++)
	{
		// ESCALERA
		if (contDados[i] == 1)
		{
			contEscalera++;
		}
		if (contDados[i] > 2 && contDados[i] < 6)
		{
			// TRIOX
			banTrioX = true;
			if (contDados[i] == 3)
			{
				puntos = (i + 1) * 10;
				cara = i + 1;
				contTrioX++;

				if (contTrioX == 2)
				{
					mayorDado = dados[0];
					for (x = 1;x <= 5;x++)
					{
						if (dados[x] > mayorDado)
						{
							mayorDado = dados[x];
						}
					}
					cara = mayorDado;
					puntos = mayorDado * 10;
				}
			}
			else
			{
				cara = i + 1;
				puntos = (i + 1) * 10;
			}
		}
		else
		{
			// Suma de Dados
			if (contDados[i] == 2 && banTrioX == false)
			{
				puntos = 0;
				for (x = 0;x <= 5;x++)
				{
					puntos += dados[x];
				}
				banSumaDados = true;
			}
			else
			{
				// SextetoX
				if (i < 5)
				{
					if (contDados[i] == 6)
					{
						banSextetoX = true;
						puntos = (i + 1) * 50;
						cara = i + 1;
					}
				}
				else
				{
					// SEXTETO 6
					if (contDados[i] == 6)
					{
						PosicionamientoXY(43, 17);
						cout << "SEXTETO 6 " << (char)173 << (char)173;
						PosicionamientoXY(43, 18);
						cout << "PERDISTE LOS PUNTOS DE LA RONDA!!";
						PosicionamientoXY(65, 17);
						cout << "PUNTOS: " << puntos;
					}
				}
			}
		}
	}
	if (contEscalera == 6)
	{
		puntosTotales = 500;
		PosicionamientoXY(43, 17);
		cout << (char)173 << "ESCALERA! ";
	}
	else
	{
		if (banTrioX)
		{
			PosicionamientoXY(43, 17);
			cout << "TRIO " << cara;
			PosicionamientoXY(65, 17);
			cout << "PUNTOS: " << puntos;
		}
		else
		{
			if (banSextetoX)
			{
				PosicionamientoXY(43, 17);
				cout << "SEXTETO " << cara;
				PosicionamientoXY(65, 17);
				cout << "PUNTOS: " << puntos;
			}
			else
			{
				if (banSumaDados)
				{
					PosicionamientoXY(43, 17);
					cout << "SUMA DE DADOS";
					PosicionamientoXY(65, 17);
					cout << "PUNTOS: " << puntos;
				}
			}
		}
	}
}


void Partida(char nombreMayorPuntaje[], char apellidoMayorPuntaje[], int& puntuacionMaxima, bool dosJugadores)
{
	const int cantidadCaracteres = 16, cantDados = 6, lanzamientos = 3, puntajeGanador = 500;
	char vNombre[cantidadCaracteres], vApellido[cantidadCaracteres], vNombre2[cantidadCaracteres], vApellido2[cantidadCaracteres];

	int numRonda = 0, numLanzamiento = 0, valorDeDados[cantDados], contDadosIguales[cantDados];
	int puntosLanzamientos, lanzamientoMaximo, puntosTotales = 0, puntosTotales2 = 0, puntosLanzamientos2 = 0;

	bool banSexteto6 = false, banSiguienteJugador = false, banTerminarJuego = false, banGanoConEscalera = false;

	if (!dosJugadores)
	{
		CargarNombre(vNombre, vApellido, vNombre2, vApellido2, dosJugadores);

		while (puntosTotales < puntajeGanador)
		{

			rlutil::cls();
			RecuadroDePantalla();
			int numLanzamiento = 0;
			bool banSexteto6 = false;
			numRonda++;
			lanzamientoMaximo = 0;


			for (int i = 0;i < lanzamientos;i++)
			{
				rlutil::cls();
				RecuadroDePantalla();
				numLanzamiento++;
				puntosLanzamientos = 0;

				LanzamientoYContadorDeDados(valorDeDados, contDadosIguales);

				CombinacionesGanadoras(valorDeDados, contDadosIguales, cantDados, puntosLanzamientos, puntosTotales);

				if (puntosLanzamientos == 0)
				{
					banSexteto6 = true;
				}
				if (banSexteto6)
				{
					lanzamientoMaximo = 0;
				}
				else if (puntosLanzamientos > lanzamientoMaximo)
				{
					lanzamientoMaximo = puntosLanzamientos;
				}

				InterfazDuranteLaPartida(vNombre, numRonda, numLanzamiento, lanzamientoMaximo, puntosTotales);

				if (puntosTotales >= puntajeGanador)
				{
					banGanoConEscalera = true;
					PosicionamientoXY(41, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA CONTINUAR...");
					EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre, vApellido, puntosTotales);
					PantallaGanadora(vNombre, vApellido, numRonda, puntosTotales, dosJugadores);
					break;
				}
				else
				{
					PosicionamientoXY(36, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA LANZAR LOS DADOS...");
				}


			}

			puntosTotales += lanzamientoMaximo;

			if (puntosTotales < puntajeGanador)
			{
				PantallaEntreTurnos(numRonda,vNombre,vNombre2,puntosTotales,puntosTotales2,banSiguienteJugador,dosJugadores);
			}


		}

		if (!banGanoConEscalera)
		{
			PantallaGanadora(vNombre, vApellido, numRonda, puntosTotales, dosJugadores);
		}

		EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre, vApellido, puntosTotales);
	}
	//DOS JUGADORES
	else
	{
		CargarNombre(vNombre, vApellido, vNombre2, vApellido2, dosJugadores);

		numRonda = 0;
		banSiguienteJugador = false;
		puntosTotales = 0;
		puntosTotales2 = 0;
		banTerminarJuego = false;
		banGanoConEscalera = false;


		while (puntosTotales < puntajeGanador && puntosTotales2 < puntajeGanador)
		{
			rlutil::cls();
			RecuadroDePantalla();
			numRonda++;
			banSexteto6 = false;
			numLanzamiento = 0;
			banSiguienteJugador = false;
			banTerminarJuego = false;
			lanzamientoMaximo = 0;

			for (int i = 0;i < lanzamientos;i++)
			{
				rlutil::cls();
				RecuadroDePantalla();
				numLanzamiento++;
				puntosLanzamientos = 0;

				LanzamientoYContadorDeDados(valorDeDados, contDadosIguales);

				CombinacionesGanadoras(valorDeDados, contDadosIguales, cantDados, puntosLanzamientos, puntosTotales);

				if (puntosLanzamientos == 0)
				{
					banSexteto6 = true;
				}
				if (banSexteto6)
				{
					lanzamientoMaximo = 0;
				}
				else if (puntosLanzamientos > lanzamientoMaximo)
				{
					lanzamientoMaximo = puntosLanzamientos;
				}

				InterfazDuranteLaPartida(vNombre, numRonda, numLanzamiento, lanzamientoMaximo, puntosTotales);

				if (puntosTotales >= puntajeGanador)
				{
					banGanoConEscalera = true;
					PosicionamientoXY(41, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA CONTINUAR...");
					EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre, vApellido, puntosTotales);
					PantallaGanadora(vNombre, vApellido, numRonda, puntosTotales, dosJugadores);

					banTerminarJuego = true;

					break;
				}
				else
				{
					PosicionamientoXY(36, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA LANZAR LOS DADOS...");
				}


			}

			if (banTerminarJuego)
			{
				break;
			}

			puntosTotales += lanzamientoMaximo;

			if (puntosTotales >= puntajeGanador)
			{
				EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre, vApellido, puntosTotales);

				if (!banGanoConEscalera)
				{
					PantallaGanadora(vNombre, vApellido, numRonda, puntosTotales, dosJugadores);
				}

				break;
			}


			//SIGUIENTE JUGADOR
			numLanzamiento = 0;
			banSexteto6 = false;
			lanzamientoMaximo = 0;
			PantallaEntreTurnos(numRonda, vNombre, vNombre2, puntosTotales, puntosTotales2, banSiguienteJugador, dosJugadores);


			for (int x = 0;x < lanzamientos;x++)
			{
				rlutil::cls();
				RecuadroDePantalla();
				numLanzamiento++;
				puntosLanzamientos2 = 0;

				LanzamientoYContadorDeDados(valorDeDados, contDadosIguales);

				CombinacionesGanadoras(valorDeDados, contDadosIguales, cantDados, puntosLanzamientos2, puntosTotales2);

				if (puntosLanzamientos2 == 0)
				{
					banSexteto6 = true;
				}
				if (banSexteto6)
				{
					lanzamientoMaximo = 0;
				}
				else if (puntosLanzamientos2 > lanzamientoMaximo)
				{
					lanzamientoMaximo = puntosLanzamientos2;
				}

				InterfazDuranteLaPartida(vNombre2, numRonda, numLanzamiento, lanzamientoMaximo, puntosTotales2);

				if (puntosTotales2 >= puntajeGanador)
				{
					banGanoConEscalera = true;
					PosicionamientoXY(41, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA CONTINUAR...");
					EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre2, vApellido2, puntosTotales2);
					PantallaGanadora(vNombre2, vApellido2, numRonda, puntosTotales2, dosJugadores);

					banTerminarJuego = true;
					break;
				}
				else
				{
					PosicionamientoXY(36, 25);
					rlutil::anykey("PULSE CUALQUIER TECLA PARA LANZAR LOS DADOS...");
				}


			}

			if (banTerminarJuego)
			{
				break;
			}

			puntosTotales2 += lanzamientoMaximo;

			if (puntosTotales2 >= puntajeGanador)
			{
				EncontrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, vNombre2, vApellido2, puntosTotales2);

				if (!banGanoConEscalera)
				{
					PantallaGanadora(vNombre2, vApellido2, numRonda, puntosTotales2, dosJugadores);
				}

				break;
			}

			banSiguienteJugador = true;
			PantallaEntreTurnos(numRonda, vNombre, vNombre2, puntosTotales, puntosTotales2, banSiguienteJugador, dosJugadores);
		}
	}
}


void InterfazDuranteLaPartida(char nombre[], int numRonda, int lanzamiento, int puntosRonda, int puntosPartida)
{
	RecuadroDePantalla();

	int i;

	PosicionamientoXY(49, 8);
	cout << "TURNO DE " << nombre;

	for (i = 0; i < 42;i++)
	{
		PosicionamientoXY(37 + i, 9);
		cout << (char)205;
	}

	PosicionamientoXY(42, 11);
	cout << "RONDA N" << (char)248 << numRonda;

	PosicionamientoXY(63, 11);
	cout << "LANZAMIENTO N" << (char)248 << lanzamiento;

	for (i = 0; i < 42;i++)
	{
		PosicionamientoXY(37 + i, 21);
		cout << (char)205;
	}

	PosicionamientoXY(30, 23);
	cout << "PUNTOS DE LA RONDA: " << puntosRonda;

	PosicionamientoXY(65, 23);
	cout << "PUNTOS TOTALES: " << puntosPartida << endl;
}


void PantallaEntreTurnos(int numRonda, char Nombre[], char Nombre2[], int puntosTotales, int puntosTotales2, bool banSiguienteJugador, bool DosJugadores)
{
	if (!DosJugadores) {

		rlutil::cls();
		RecuadroDePantalla();

		PosicionamientoXY(54, 10);
		cout << "RONDA N" << (char)248 << numRonda;

		PosicionamientoXY(46, 12);
		cout << "NOMBRE DEL JUGADOR: " << Nombre;

		PosicionamientoXY(47, 15);
		cout << "PUNTAJE TOTAL: " << puntosTotales << " PUNTOS.";

		PosicionamientoXY(34, 25);
		rlutil::anykey("PULSE CUALQUIER TECLA PARA LA SIGUIENTE RONDA...");

	}
	else {

		rlutil::cls();
		RecuadroDePantalla();

		PosicionamientoXY(53, 10);
		cout << "RONDA N" << (char)248 << numRonda << endl;

		if (!banSiguienteJugador)
		{
			PosicionamientoXY(47, 12);
			cout << "PROXIMO TURNO: " << Nombre2 << endl;
		}
		else
		{
			PosicionamientoXY(47, 12);
			cout << "PROXIMO TURNO: " << Nombre << endl;
		}

		PosicionamientoXY(44, 15);
		cout << "PUNTAJE DE " << Nombre << ": " << puntosTotales << " PUNTOS." << endl;
		PosicionamientoXY(44, 17);
		cout << "PUNTAJE DE " << Nombre2 << ": " << puntosTotales2 << " PUNTOS." << endl;
		PosicionamientoXY(31, 25);
		rlutil::anykey("PULSE CUALQUIER TECLA PARA EL SIGUIENTE JUGADOR...");

	}
}

void PantallaGanadora(char nombre[], char apellido[], int cantRondas, int puntosTotales, bool DosJugadores)
{
	rlutil::cls();
	RecuadroDePantalla();

	PosicionamientoXY(43, 12);
	cout << (char)173 << (char)173 << (char)173 << "FELICIDADES GANASTE LA PARTIDA" << endl;
	PosicionamientoXY(50, 13);
	cout << nombre << " " << apellido << "!!!";

	PosicionamientoXY(47, 15);
	cout << "PUNTAJE TOTAL: " << puntosTotales << " PUNTOS.";

	if (DosJugadores)
	{
		PosicionamientoXY(47, 17);
		cout << "LLEVO UN TOTAL DE  " << cantRondas << " RONDAS.";
	}

	PosicionamientoXY(41, 25);
	rlutil::anykey("PULSE CUALQUIER TECLA PARA SALIR...");
}

void EncontrarMaximaPuntuacion(char nombreMaximo[], char apellidoMaximo[], int& puntuacionMaxima, char nombre[], char apellido[], int puntosTotales)
{
	if (puntosTotales > puntuacionMaxima)
	{
		puntuacionMaxima = puntosTotales;

		for (int i = 0; i < 16; i++)
		{
			nombreMaximo[i] = nombre[i];
			apellidoMaximo[i] = apellido[i];
		}
	}
}

void MostrarMaximaPuntuacion(char nombreMaximo[], char apellidoMaximo[], int puntaje)
{
	rlutil::cls();
	RecuadroDePantalla();

	if (puntaje == 0)
	{
		PosicionamientoXY(47, 12);
		cout << "NO HAY MAYOR PUNTAJE";
	}
	else
	{
		PosicionamientoXY(43, 12);
		cout << "EL PUNTAJE MAS ALTO ES: " << puntaje;
		PosicionamientoXY(41, 15);
		cout << "LE PERTENECE A " << nombreMaximo << " " << apellidoMaximo;
	}

	PosicionamientoXY(41, 25);
	rlutil::anykey("PRESIONE CUALQUIER TECLA PARA SALIR...");
}
