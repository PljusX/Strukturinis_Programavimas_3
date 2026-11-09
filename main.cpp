#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

void meniu();
bool nuskaityti(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int &n);
double eilutesSuma(double kaina, int kiekis);
double nuolaida(double suma, int kiekis);
double kategorijosSuma(string kategorija[], double kaina[], int kiekis[], int n, string pasirinkta);
void spausdintiPreke(string kategorija, string pavadinimas, double kaina, int kiekis);
void visosPrekes(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int n);
void pasirinktaKategorija(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int n);
void uzsakymoSumos(double kaina[], int kiekis[], int n);
void ataskaita(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int n);
void issaugoti(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int n);

int main() {
    string kategorija[100];
    string pavadinimas[100];
    double kaina[100];
    int kiekis[100];

    int n = 0;
    int pasirinkimas;
    bool veikia = true;

    if (nuskaityti(kategorija, pavadinimas, kaina, kiekis, n) == false) {
        return 1;
    }

    cout << "Duomenys nuskaityti sekmingai!\n";

    while (veikia == true) {
        meniu();

        if (!(cin >> pasirinkimas)) {
            cout << "Iveskite skaiciu nuo 1 iki 7!\n";
            cin.clear();
            cin.ignore(69, '\n');
        }
        else if (pasirinkimas == 1) {
            visosPrekes(kategorija, pavadinimas, kaina, kiekis, n);
        }
        else if (pasirinkimas == 2) {
            pasirinktaKategorija(kategorija, pavadinimas, kaina, kiekis, n);
        }
        else if (pasirinkimas == 3) {
            uzsakymoSumos(kaina, kiekis, n);
        }
        else if (pasirinkimas == 4) {
            cout << fixed << setprecision(2);
            cout << "\nDviraciai: " << kategorijosSuma(kategorija, kaina, kiekis, n, "Dviraciai") << " Eur\n";
            cout << "Dalys: " << kategorijosSuma(kategorija, kaina, kiekis, n, "Dalys") << " Eur\n";
            cout << "Aksesuarai: " << kategorijosSuma(kategorija, kaina, kiekis, n, "Aksesuarai") << " Eur\n";
        }
        else if (pasirinkimas == 5) {
            ataskaita(kategorija, pavadinimas, kaina, kiekis, n);
        }
        else if (pasirinkimas == 6) {
            issaugoti(kategorija, pavadinimas, kaina, kiekis, n);
        }
        else if (pasirinkimas == 7) {
            veikia = false;
            cout << "Programa baigta.\n";
        }
        else {
            cout << "Neteisingas pasirinkimas! Ivesk skaiciu nuo 1 iki 7.\n";
        }
    }

    return 0;
}
