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
