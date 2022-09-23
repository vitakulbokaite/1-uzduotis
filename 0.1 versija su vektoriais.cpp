
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <random>
#include <ctime>

const int SIZE = 100;
struct Studentas {
    std::string vardas;
    std::string pavarde;
    std::vector<int> nd;
    double egz;
    double vid;
    double gal;
    double med;
};
int nd_skaicius;
int pazymys;
int studentu_sk;
Studentas studentai[SIZE];
char tn_nd;
char tn_egz;

//medianos skaiciavimas
double findMedian(std::vector<int> v) {
    double median;
    // Sorting algoritmas
    std::sort(v.begin(), v.end());
    // Mediana skaiciuojama nelyginio skaiciaus vektoriui
    median = v[(v.size() / 2)];
    // Patikrinama ar vektorius lyginis
    if (v.size() % 2 == 0) {
        // Jei lyginis, paimti sekanti skaiciu ir padalinti is 2
        median = (median + v[v.size() / 2 - 1]) / 2;
    }
    // Grazinama suskaiciuota mediana
    return median;
}

void duomenu_ivedimas() {
    std::cout << "Iveskite studentu skaiciu: ";
    std::cin >> studentu_sk;
    //Patikrinama ar valid input
    while (1) {
        if (std::cin.fail() || studentu_sk < 0)
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Klaida. Iveskite teisinga studentu skaiciu: ";
            std::cin >> studentu_sk;
        }
        else {
            //input worked
            break;
        }

    }
    for (int z = 1; z < studentu_sk + 1; z++) {
        std::cout << "Iveskite " << z << " studento varda : ";
        std::cin >> studentai[z].vardas;
        std::cout << "\nIveskite " << z << " studento pavarde: ";
        std::cin >> studentai[z].pavarde;
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "\nKiek namu darbu pazymiu suvesite: ";
        std::cin >> nd_skaicius;
        std::cout << "\nAr pazymius sugeneruoti atsitiktinai? T/N ";
        std::cin >> tn_nd;
        std::default_random_engine randomGenerator(time(0));
        std::uniform_int_distribution<int> atsitiktinisPaz(1, 10);
        if (tn_nd == 'T' || tn_nd == 't') {
            for (int b = 1; b < nd_skaicius + 1; b++) {
                int nd_paz = atsitiktinisPaz(randomGenerator);
                std::cout << b << " pazymys: " << nd_paz << "\n";
                studentai[z].nd.push_back(nd_paz);
            }
        }
        else if (tn_nd == 'N' || tn_nd == 'n') {

            for (int j = 1; j < nd_skaicius + 1; j++) {
                std::cout << "Iveskite " << j << " pazymi: ";
                std::cin >> pazymys;
                //patikrinama ar ivestas pazymys priklauso intervalui 1-10
                if (pazymys < 0 || pazymys > 10) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nKlaida. Iveskite nd pazymi is naujo: ";
                    std::cin >> pazymys;
                }
                studentai[z].nd.push_back(pazymys);
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nKlaida. Iveskite pasirinkima (T/N) is naujo: ";
            std::cin >> tn_nd;
        }


            //sudedami namu darbu pazymiai vidurkio skaiciavimui
            int nd_sudetis = 0;
            for (int i = 0; i < nd_skaicius; i++) {
                nd_sudetis += studentai[z].nd[i];
            }
            if (nd_skaicius != 0) {
                studentai[z].vid = nd_sudetis / nd_skaicius; // vidurkio skaiciavimas
            }
            else {
                studentai[z].vid == 0;
            }
        
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nAr egzamino pazymi sugeneruoti atsitiktinai? T/N ";
        std::cin >> tn_egz;
        if (tn_egz == 'T' || tn_egz == 't') {
            int egz_paz = atsitiktinisPaz(randomGenerator);
            std::cout << "\nEgzamino pazymys: " << egz_paz << "\n";
            studentai[z].egz = egz_paz;
        }
        else if (tn_egz == 'N' || tn_egz == 'n') {
            std::cout << "\nIveskite " << z << " studento egzamino pazymi : ";
            std::cin >> studentai[z].egz;
            //patikrinama, kad egzamino pazymis butu int tipo ir priklausytu 1-10 intervalui
            while (1)
            {
                if (std::cin.fail() || studentai[z].egz < 0 || studentai[z].egz > 10)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nKlaida. Iveskite egzamino pazymi is naujo: ";
                    std::cin >> studentai[z].egz;
                }
                if (!std::cin.fail())
                    break;
            }
        }
        else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nKlaida. Iveskite pasirinkima (T/N) is naujo: ";
            std::cin >> tn_egz;
        }


        studentai[z].gal = 0.4 * studentai[z].vid + 0.6 * studentai[z].egz; //galutinis pazymys
        studentai[z].med = findMedian(studentai[z].nd); //mediana

    }
}

int main()
{
    duomenu_ivedimas();
    /*std::cout << "Pavarde    Vardas      Galutinis (Vid.)  Galutinis (Med.)\n" << "---------------------------------------------------------\n";
    for (int a = 1; a < studentu_sk + 1; a++) {
        std::cout << std::fixed << std::setprecision(2) << studentai[a].vardas << "         " << studentai[a].pavarde <<"         " << studentai[a].gal<< "          " << studentai[a].med << "\n";
    }*/
    std::cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; // 50 - kadangi sudaro visa setw() pločių sumą
    for (int a = 1; a < studentu_sk + 1; a++)  //grupė tai arba Jūsų masyvas ar vektorius
        std::cout << std::left << std::setw(15) << studentai[a].pavarde << std::left << std::setw(15) << studentai[a].vardas << std::left << std::setw(20) << studentai[a].gal << std::left << std::setw(20) << studentai[a].med << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; // 50 - kadangi sudaro visa setw() pločių sumą, lentelės pabaiga
}
