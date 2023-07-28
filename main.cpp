# include <iostream>
# include <cstdlib>
# include <stdlib.h>
# include <time.h>
# include "subProgramas.h"
# include "rlutil.h"

using namespace std;

int main()
{
    rlutil::setBackgroundColor(rlutil::LIGHTCYAN);
    rlutil::setColor(rlutil::BLACK);
    rlutil::saveDefaultColor();


    const int cantidadCaracteres = 16;

    char nombreMayorPuntaje[cantidadCaracteres], apellidoMayorPuntaje[cantidadCaracteres];

    int puntuacionMaxima = 0;

    int y = 0;

    rlutil::hidecursor();

    do
    {
        rlutil::cls();

        MenuPrincipal();

        PosicionamientoXY(48, 13 + y);
        cout << (char)175 << endl;


        switch (rlutil::getkey())
        {
        case 14:
            y = movimientoFlechaArriba(y);
            break;
        case 15:
            y = movimientoFlechaAbajo(y);
            break;
        case 1:

            switch (y)
            {
            case 0:

                Partida(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, false);

                break;
            case 1:

                Partida(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima, true);

                break;
            case 2:

                MostrarMaximaPuntuacion(nombreMayorPuntaje, apellidoMayorPuntaje, puntuacionMaxima);

                break;

            case 3:

                FinDeJuego();

                break;

            default:
                break;
            }
            break;
        default:
            break;
        }



    } while (true);

    return 0;
}
