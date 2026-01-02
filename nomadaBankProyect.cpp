#include <iostream>
#include <string>
#include <limits>
#include <thread>
#include <chrono>
using namespace std;

void titulo ();
void continuarPrograma ();
void retirarDinero (int montoRetirar, int &saldoActual);
void depositarDinero (int montoDepositar, int &saldoActual);
void movimientos (int contador, int historial[]);


int main() {

    int saldo = 0;   
    int opcion = 0;
    int monto =0;
    int historial[10];  
    int contador = 0;  
    
    titulo ();
    do
    {
        cout << "Dinero disponible en cajero: ";
        if (!(cin >> saldo))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente de nuevo." << endl;
            continue;
        }

        if (saldo < 0)
        {
            cout << "El saldo no puede ser negativo." << endl;
            continue;
        }

        if (saldo % 10 != 0)
        {
            cout << "Cantidad inválida, debe ser múltiplo de 10." << endl;
            continue;
        }

        break;
    } while (true);

    do {
        titulo();
        //cout << "\nBienvenido a Nómada Bank" <<endl<<endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Ver historial" << endl; // +1
        cout << "5. Salir" << endl;
        cout <<endl<< "Digite una Opción: ";
         if (!(cin >> opcion))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente de nuevo." << endl;
            continue;
        }

        switch(opcion) {
            case 1:
                titulo();
                cout << "\nSu saldo es: S/." << saldo << endl;
                continuarPrograma();
                break;

            case 2:
                titulo();
                cout << "\nMonto a retirar: ";
                            if (!(cin >> monto))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Intente de nuevo." << endl;
                continue;
            }
                while (monto % 10 != 0) {
                    cout <<"Cantidad inválida, debe ser multiplo de 10"<<endl;
                    cout << "Monto a retirar: ";
                    cin >> monto;
                }
                retirarDinero(monto, saldo);
                if (contador < 10) {
                historial[contador] = -monto; // negativo = retiro
                contador++;
                }            
                continuarPrograma();
                break;

            case 3:
                titulo();
                cout <<"\nMonto a depositar: ";
            if (!(cin >> monto))
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Entrada inválida. Intente de nuevo." << endl;
                continue;
            }
                while (monto % 10 != 0) {
                    cout <<"Cantidad inválida, debe ser multiplo de 10"<<endl;
                    cout << "Monto a depositar: ";
                    cin >> monto;
                }
                depositarDinero (monto, saldo);
                if (contador < 10) {
                    historial[contador] = monto; 
                    contador++;
                }                
                continuarPrograma();
                break;

            case 4:
                titulo();
                movimientos(contador, historial);
                continuarPrograma();
                break;

            case 5:
                titulo();
                cout <<endl<< "Gracias por usar el cajero. Vuelve Pronto" << endl;
                cout<<endl<<"--------------------------"<<endl;
                for(int i = 3; i >= 0; i--) {
                    this_thread::sleep_for(chrono::seconds(1));
                    cout <<"\rSaliendo en "<< i <<" "<< flush; // flush asegura que se impriman los numeros al instante
                }
                cout<<endl<<endl;
                break;

            default:
                cout << "Opcion incorrecta." << endl;
        }

    } while(opcion != 5);


    return 0;
}

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

}

void continuarPrograma ()
{
    cout<<endl<<"--------------------------"<<endl;
    for(int i = 5; i >= 0; i--) {
        this_thread::sleep_for(chrono::seconds(1));
        cout <<"\rContinuando en "<< i <<" "<< flush; // flush asegura que se impriman los numeros al instante
    }
    //cout<<endl<<"Presione la tecla ENTER para continuar ";
    //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    //cin.get();


}

void retirarDinero (int montoRetirar, int &saldoActual) {
    if (montoRetirar > 0 && montoRetirar <= saldoActual) {
        saldoActual = saldoActual - montoRetirar;
        cout << "Retiro exitoso. Nuevo saldo: S/." << saldoActual << endl;   
    } else {
        cout << "Error: monto invalido o insuficiente." << endl;
    }
}

void depositarDinero (int montoDepositar, int &saldoActual) {
    if (montoDepositar > 0) {
        saldoActual = saldoActual + montoDepositar;
        cout << "Deposito exitoso. Nuevo saldo: S/." << saldoActual << endl;     
    } else {
        cout << "Error: no se permiten montos negativos." << endl;
    }
}

void movimientos (int contador, int historial[]) {
    cout << "\nHistorial de operaciones:" << endl;
    if (contador == 0) {
        cout << "No hay operaciones registradas." << endl;
    } else {
        for (int i = 0; i < contador; i++) {
            if (historial[i] > 0) {
                cout << "Deposito: S/." << historial[i] << endl;
            } else {
                cout << "Retiro: S/." << -historial[i] << endl;
            }
        }
    }
}