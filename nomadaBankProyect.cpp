#include <iostream>
#include <string>
#include <limits>
using namespace std;

void titulo ();
void continuarPrograma ();

int main() {

    float saldo = 1000;   
    int opcion = 0.0;
    float monto =0.0;
    float historial[10];  
    int contador = 0;     

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
                cout << "\nSu saldo es: $" << saldo << endl;
                continuarPrograma();
                break;

            case 2:
                cout << "\nMonto a retirar: ";
                cin >> monto;
                if (monto > 0 && monto <= saldo) {
                    saldo = saldo - monto;
                    cout << "Retiro exitoso. Nuevo saldo: $" << saldo << endl;
                    if (contador < 10) {
                        historial[contador] = -monto; // negativo = retiro
                        contador++;
                    }
                } else {
                    cout << "Error: monto invalido o insuficiente." << endl;
                }
                continuarPrograma();
                break;

            case 3:
                cout <<"\nMonto a depositar: ";
                cin >> monto;
                if (monto > 0) {
                    saldo = saldo + monto;
                    cout << "Deposito exitoso. Nuevo saldo: $" << saldo << endl;
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
                            cout << "Deposito: $" << historial[i] << endl;
                        } else {
                            cout << "Retiro: $" << -historial[i] << endl;
                        }
                    }
                }
                continuarPrograma();
                break;

            case 5:
                cout << "Gracias por usar el cajero. Vuelve Pronto" << endl;
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
