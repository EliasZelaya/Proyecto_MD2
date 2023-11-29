#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

void menu();
int seleccionarNegativoOPositivo(int limiteInferior, int limiteSuperior);
int procesaResultado(vector<int> numlist, int limiteInferior, int limiteSuperior);
int multiplica(vector<int> numlist);

int main(){
    srand(time(NULL));
    
    menu();

    return 0;
}

void menu(){
    bool condicion = true;
    int opcion, resultado = 0, repeticion = 1000;

    do
    {
        vector<int> numlist;
        double sinCeroPositivo = 0, nulo = 0;

        cout <<"\nElija una opcion: \n";
        cout <<"1- Sin 0\n";
        cout <<"2- Con 0\n";
        cout <<"3- Salir\n";
        cout <<"Respuesta: "; cin >> opcion;

        switch (opcion)
        {
        case 1: {

            for (int j = 0; j < repeticion; j++)
            {
                numlist.clear();

                int limiteSuperior = 14, limiteInferior = 1;
                
                for (int i = 0; i < 4; i++)
                {
                    numlist.insert(numlist.cend(), seleccionarNegativoOPositivo(limiteInferior, limiteSuperior));

                    if (numlist[i] >= 1 && numlist[i] <= 6)
                    {
                        limiteInferior++;
                    }
                    else
                    {
                        limiteSuperior--;
                    }
                }
                resultado = procesaResultado(numlist, 1, 6);

                if (resultado > 0)
                {
                    sinCeroPositivo++;
                }

            }
            cout << "\n\n";
            cout << "Veces que lo ejecuto sin 0: " << repeticion << endl;
            cout << "\tVeces que el resultado fue positivo: " << sinCeroPositivo << endl;
            cout <<"\nProbabilidad de obtener un resultado positivo es de: " << sinCeroPositivo/repeticion << endl;

        }
            break;
        case 2: {

            for (int j = 0; j < repeticion; j++)
            {
                numlist.clear();
                
                int limiteSuperior = 14, limiteInferior = 1;

                for (int i = 0; i < 4; i++)
                {
                    numlist.insert(numlist.cend(), seleccionarNegativoOPositivo(limiteInferior, limiteSuperior));

                    if (numlist[i] >= 1 && numlist[i] <= 6)
                    {
                        limiteInferior++;
                    }
                    else
                    {
                        limiteSuperior--;
                    }
                }
                resultado = procesaResultado(numlist, 0, 5);

                if (resultado == 0)
                {
                    nulo++;
                }
            }
            cout << "\n\n";
            cout << "\nVeces que lo ejecuto con 0: " << repeticion << endl;
            cout << "\tVeces que el resultado fue nulo: " << nulo << endl;
            cout << "\nProbabilidad de obtener un resultado nulo: " << nulo/repeticion << endl;
        }
            break;
        case 3: {
            condicion = false;
            }
            break;
        default: cout <<"Elija una opcion valida";
            break;
        }
    } while (condicion);
}

int seleccionarNegativoOPositivo(int limiteInferior, int limiteSuperior){
    return rand()%limiteSuperior+limiteInferior;
}

int multiplica(vector<int> numlist){
    int resultado = 1;

    for (int i = 0; i < 4; i++)
    {
        resultado *= numlist[i];
    }
    
    return resultado;
}

int procesaResultado(vector<int> numlist, int limiteInferior, int limiteSuperior){
    
    vector<int> numlist2;

    for (int i = 0; i < 4; i++)
    {
        if (numlist[i] >= 0 && numlist[i] <= 6)
        {
            numlist2.insert(numlist2.cend(), rand()%limiteSuperior+limiteInferior);
        }
        else{
            numlist2.insert(numlist2.cend(), rand()%(8)+(-8));
        }

    }
    
    return multiplica(numlist2);
}