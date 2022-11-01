#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <ios>
#include <random>
#include <ctime>
#include <fstream>

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

std::vector <Studentas> duomenu_ivedimas() {
    std::vector<Studentas> s;
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
        Studentas studentas;
        std::cout << "Iveskite " << z << " studento varda : ";
        std::cin >> studentas.vardas;
        std::cout << "\nIveskite " << z << " studento pavarde: ";
        std::cin >> studentas.pavarde;
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
                studentas.nd.push_back(nd_paz);
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
                studentas.nd.push_back(pazymys);
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
            nd_sudetis += studentas.nd[i];
        }
        if (nd_skaicius != 0) {
            studentas.vid = nd_sudetis / nd_skaicius; // vidurkio skaiciavimas
        }
        else {
            studentas.vid == 0;
        }

        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nAr egzamino pazymi sugeneruoti atsitiktinai? T/N ";
        std::cin >> tn_egz;
        if (tn_egz == 'T' || tn_egz == 't') {
            int egz_paz = atsitiktinisPaz(randomGenerator);
            std::cout << "\nEgzamino pazymys: " << egz_paz << "\n";
            studentas.egz = egz_paz;
        }
        else if (tn_egz == 'N' || tn_egz == 'n') {
            std::cout << "\nIveskite " << z << " studento egzamino pazymi : ";
            std::cin >> studentas.egz;
            //patikrinama, kad egzamino pazymis butu int tipo ir priklausytu 1-10 intervalui
            while (1)
            {
                if (std::cin.fail() || studentas.egz < 0 || studentas.egz > 10)
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cout << "\nKlaida. Iveskite egzamino pazymi is naujo: ";
                    std::cin >> studentas.egz;
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


        studentas.gal = 0.4 * studentas.vid + 0.6 * studentas.egz; //galutinis pazymys is vidurkio
        studentas.med = findMedian(studentas.nd) * 0.4 + 0.6 * studentas.egz; //is medianos
        s.push_back(studentas);
    } return s;
}

int main()
{
    std::vector <Studentas> stud;
    stud = duomenu_ivedimas();
    std::cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; 
    for (int a = 0; a < studentu_sk; a++)  
        std::cout << std::left << std::setw(15) << stud[a].pavarde << std::left << std::setw(15) << stud[a].vardas << std::left << std::setw(20) << stud[a].gal << std::left << std::setw(20) << stud[a].med << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; 
}
