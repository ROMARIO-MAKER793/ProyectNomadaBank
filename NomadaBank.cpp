#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
using namespace std;

void titulo ();
int saldoActual (int cant20, int cant50, int cant100);
void continuarPrograma ();
void menuPrincipal ();
int retirarDinero(int montoRetirar, int& cant20, int& cant50, int& cant100);

int main() {
    setlocale(LC_ALL, "es_ES.UTF-8");
    system("clear");
    titulo ();

    int billetes20soles = 0, billetes50soles = 0, billetes100soles = 0, montoActual = 0;
    int montoRetirar = 0, montoDepositar = 0;
    cout <<setw(50)<<endl<<"CONFIGURACION INICIAL"<<endl<<endl;
    cout << "Digite la cantidad de billetes de cada valor que hay en el cajero"<<endl;
    cout <<endl<<"Billetes de 20 soles: ";
    cin >> billetes20soles;
    cout <<endl<<"Billetes de 50 soles: ";
    cin >> billetes50soles;
    cout <<endl<<"Billetes de 100 soles: ";
    cin >> billetes100soles;

    montoActual = saldoActual(billetes20soles, billetes50soles, billetes100soles);

    cout<<endl<<"SALDO ACTUAL: "<<montoActual<<" SOLES"<<endl<<endl;
    cout<<"PRESIONE LA TECLA ENTER PARA CONTINUAR ";
    continuarPrograma();

    bool salir = false;
    int opcionPantalla = 1;
    do
    {
        switch (opcionPantalla)
        {
        case 1:
            titulo();
            menuPrincipal();
            cout<<endl<<"Elija una opcion de 1 a 4: ";
            cin>>opcionPantalla;
            if (opcionPantalla == 4) salir = true;
            else opcionPantalla++;
            break;
        
        case 2: //Opcion 1: Consultar Saldo
            titulo();
            cout<<"CONSULTAR SALDO"<<endl<<endl;
            cout<<"El saldo actual en el cajero es "<<montoActual<<" soles"<<endl<<endl;
            cout<<"1. Menú Principal"<<setw(30)<<"2. Salir"<<endl<<endl;
            cout<<"Elige una opción para continuar: ";
            cin>>opcionPantalla;
            if (opcionPantalla == 2) salir = true;
            break;
        
        case 3: //Opcion 2: Retirar Dinero
            titulo();
            cout<<"RETIRAR DINERO"<<endl<<endl;
            cout<<"Digite el monto de dinero que desea retirar: ";
            cin>>montoRetirar;

            cout<<"1. Menú Principal"<<setw(30)<<"2. Salir"<<endl<<endl;
            cout<<"Elige una opción para continuar: ";
            cin>>opcionPantalla;
            if (opcionPantalla == 2) salir = true;
            break;

        case 4: //Opcion 3: Depositar Dinero
            titulo();

            cout<<"1. Menú Principal"<<setw(30)<<"2. Salir"<<endl<<endl;
            cout<<"Elige una opción para continuar: ";
            cin>>opcionPantalla;
            if (opcionPantalla == 2) salir = true;
            break;

        default:
            break;
        }


        /* code */
    } while (salir == false);

    cout<<endl;
    

    return 0;
};

void titulo () {
    system ("clear");
    cout << "========================================================================================================"<<endl;
    const char* logo = R"(
        ███╗   ██╗ ██████╗ ███╗   ███╗ █████╗ ██████╗  █████╗     ██████╗  █████╗ ███╗   ██╗██╗  ██╗
        ████╗  ██║██╔═══██╗████╗ ████║██╔══██╗██╔══██╗██╔══██╗    ██╔══██╗██╔══██╗████╗  ██║██║ ██╔╝
        ██╔██╗ ██║██║   ██║██╔████╔██║███████║██║  ██║███████║    ██████╔╝███████║██╔██╗ ██║█████╔╝ 
        ██║╚██╗██║██║   ██║██║╚██╔╝██║██╔══██║██║  ██║██╔══██║    ██╔══██╗██╔══██║██║╚██╗██║██╔═██╗ 
        ██║ ╚████║╚██████╔╝██║ ╚═╝ ██║██║  ██║██████╔╝██║  ██║    ██████╔╝██║  ██║██║ ╚████║██║  ██╗
        ╚═╝  ╚═══╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═════╝ ╚═╝  ╚═╝    ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═══╝╚═╝  ╚═╝
    )";

    cout << logo <<endl;
    cout << "========================================================================================================"<<endl;

};

int saldoActual (int cant20, int cant50, int cant100) {
    int cantidadInicial = 20*cant20 + 50*cant50 + 100*cant100;
    return cantidadInicial;
};

void continuarPrograma ()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void menuPrincipal () {
    cout<<"¿Que operación desea hacer?"<<endl<<endl;
    cout<<"Elija una Opcion: "<<endl<<endl;
    cout<<"1. Consultar Saldo"<<endl;
    cout<<"2. Retirar Dinero"<<endl;
    cout<<"3. Depositar Dinero"<<endl;
    cout<<"4. Salir"<<endl;
}

int retirarDinero(int montoRetirar, int& cant20, int& cant50, int& cant100 ) {
    if (montoRetirar >= 100) {
        
    }
}

