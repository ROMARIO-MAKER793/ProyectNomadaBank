#include <iostream>
#include <string>
#include <limits>
using namespace std;

void titulo ();
void continuarPrograma ();
void retirarDinero (int montoRetirar, int &saldoActual);


int main() {

    int saldo = 0;   
    int opcion = 0.0;
    int monto =0.0;
    int historial[10];  
    int contador = 0;  
    
    titulo ();
    cout << "Dinero disponible en cajero: ";
    cin >> saldo;

    while (saldo % 10 != 0) {
        cout <<"Cantidad inválida, debe ser multiplo de 10"<<endl;
        cout << "Dinero disponible en cajero: ";
        cin >> saldo;
    }

    do {
        titulo();
        cout << "\nBienvenido a Nómada Bank" <<endl<<endl;
        cout << "1. Consultar saldo" << endl;
        cout << "2. Retirar dinero" << endl;
        cout << "3. Depositar dinero" << endl;
        cout << "4. Ver historial" << endl; // +1
        cout << "5. Salir" << endl;
        cout <<endl<< "Digite una Opción: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                cout << "\nSu saldo es: S/." << saldo << endl;
                continuarPrograma();
                break;

            case 2:
                cout << "\nMonto a retirar: ";
                cin >> monto;
                while (saldo % 10 != 0) {
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
                cout <<"\nMonto a depositar: ";
                cin >> monto;
                if (monto > 0) {
                    saldo = saldo + monto;
                    cout << "Deposito exitoso. Nuevo saldo: S/." << saldo << endl;
                    if (contador < 10) {
                        historial[contador] = monto; 
                        contador++;
                    }
                } else {
                    cout << "Error: no se permiten montos negativos." << endl;
                }
                continuarPrograma();
                break;

            case 4:
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
                continuarPrograma();
                break;

            case 5:
                cout << "Gracias por usar el cajero. Vuelve Pronto" << endl<<endl;
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
    cout<<endl<<"Presione la tecla ENTER para continuar... ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

void retirarDinero (int montoRetirar, int &saldoActual) {
    if (montoRetirar > 0 && montoRetirar <= saldoActual) {
        saldoActual = saldoActual - montoRetirar;
        cout << "Retiro exitoso. Nuevo saldo: S/." << saldoActual << endl;   
    } else {
        cout << "Error: monto invalido o insuficiente." << endl;
    }
}