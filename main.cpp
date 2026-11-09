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

void meniu() {
    cout << "\n========== DVIRACIU PARDUOTUVE ==========\n";
    cout << "1. Perziureti visas uzsakymo prekes\n";
    cout << "2. Perziureti pasirinktos kategorijos prekes\n";
    cout << "3. Perziureti viso uzsakymo sumas\n";
    cout << "4. Perziureti sumas pagal kategorijas\n";
    cout << "5. Parodyti visa uzsakymo ataskaita\n";
    cout << "6. Issaugoti ataskaita i faila\n";
    cout << "7. Iseiti\n";
    cout << "Pasirinkite: ";
}

bool nuskaityti(string kategorija[], string pavadinimas[], double kaina[], int kiekis[], int &n) {
    ifstream in("uzsakymas.txt");

    if (!in) {
        cout << "Nepavyko atidaryti uzsakymas.txt failo!\n";
        return false;
    }

    if (!(in >> n)) {
        cout << "Nepavyko nuskaityti prekiu irasu skaiciaus!\n";
        in.close();
        return false;
    }

    in.ignore(1000, '\n');

    if (n < 1 || n > 100) {
        cout << "Prekiu irasu skaicius turi buti nuo 1 iki 100!\n";
        in.close();
        return false;
    }

    for (int i = 0; i < n; i++) {
        if (!getline(in, kategorija[i], ';') || !getline(in, pavadinimas[i], ';')) {
            cout << "Nepavyko nuskaityti " << i + 1 << " prekes duomenu!\n";
            in.close();
            return false;
        }

        if (kategorija[i] != "Dviraciai" && kategorija[i] != "Dalys" && kategorija[i] != "Aksesuarai") {
            cout << i + 1 << " prekes kategorija netinkama!\n";
            in.close();
            return false;
        }

        if (!(in >> kaina[i])) {
            cout << i + 1 << " prekes kaina netinkama!\n";
            in.close();
            return false;
        }

        if (kaina[i] <= 0) {
            cout << i + 1 << " prekes kaina turi buti didesne uz 0!\n";
            in.close();
            return false;
        }

        in.ignore(1000, ';');

        if (!(in >> kiekis[i])) {
            cout << i + 1 << " prekes kiekis turi buti teigiamas sveikasis skaicius!\n";
            in.close();
            return false;
        }

        if (kiekis[i] <= 0) {
            cout << i + 1 << " prekes kiekis turi buti didesnis uz 0!\n";
            in.close();
            return false;
        }

        in.ignore(1000, '\n');
    }

    in.close();
    return true;
}
