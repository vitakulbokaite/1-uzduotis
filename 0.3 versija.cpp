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
#include <chrono>

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

void generuoti_failus(std::string filename, int duomenu_kiekis) {
    std::default_random_engine randomGenerator(time(0));
    std::uniform_int_distribution<int> atsitiktinisPaz(1, 10);
    std::ofstream failas(filename);
    failas << std::left << std::setw(15) << "Vardas" << std::left << std::setw(15) << "Pavarde";
    for (int i = 0; i < 15; i++) {
        std::string nd = "ND" + std::to_string(i + 1);
        failas << std::left << std::setw(15) << nd;
    }

    failas << std::left << std::setw(15) << "Egz" << std::endl;
    for (int j = 0; j < duomenu_kiekis; j++) {
        std::string vardas = "Vardas" + std::to_string(j + 1);
        std::string pavarde = "Pavarde" + std::to_string(j + 1);
        failas << std::left << std::setw(15) << vardas << std::left << std::setw(15) << pavarde;
        for (int i = 0; i < 15; i++) {
            int nd_paz = atsitiktinisPaz(randomGenerator);
            failas << std::left << std::setw(15) << nd_paz;
        }
        int egz_paz = atsitiktinisPaz(randomGenerator);
        failas << std::left << std::setw(15) << egz_paz;
        failas << std::endl;
    }
}

int suskaiciuoti_eilutes_faile(std::string filename) {
    int count = 0;
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        if (!line.empty()) {
            count++;
        }

    } return count;
}

void isvedimas_i_faila(std::string filename, std::vector<Studentas> stud) {
    std::ofstream f(filename);
    f << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Galutinis (vid.)" << std::endl;
    for (int i = 0;i < 70;i++) f << "-";
    f << std::endl;
    for (int a = 0; a < stud.size(); a++)
        f << std::left << std::setw(15) << stud[a].pavarde << std::left << std::setw(15) << stud[a].vardas << std::left << std::setw(20) << stud[a].gal << std::endl;
    for (int i = 0;i < 70;i++) f << "-";
    f << std::endl;
}

void rusiavimas(std::vector<Studentas> s) {
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::vector<Studentas> vargsiukai;
    std::vector<Studentas> galvociai;
    for (int i = 0; i < s.size(); i++) {
        if (s[i].gal > 5) {
            galvociai.push_back(s[i]);
        }
        else {
            vargsiukai.push_back(s[i]);
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo rusiavimas uztruko: " << diff.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    st = start;
    isvedimas_i_faila("vargsiukai.txt", vargsiukai);
    isvedimas_i_faila("galvociai.txt", galvociai);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Surusiuotu failu isvedimas uztruko: " << diff.count() << " s\n\n";
}

std::vector<Studentas> duomenu_ivedimas_is_failo(std::string filename, int duomenu_kiekis) {
    duomenu_kiekis = suskaiciuoti_eilutes_faile(filename);
    std::vector<Studentas> st;
    std::ifstream file(filename);
    std::string line;
    getline(file, line);
    for (int i = 0; i < duomenu_kiekis - 1; i++) {
        Studentas studentas;
        file >> studentas.vardas >> studentas.pavarde;
        for (int j = 0; j < 15; j++) {
            int nd;
            file >> nd;
            studentas.nd.push_back(nd);
        }

        int nd_skaicius = 15;
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

        file >> studentas.egz;
        studentas.gal = 0.4 * studentas.vid + 0.6 * studentas.egz;
        st.push_back(studentas);
        file.ignore();
    }

    return st;
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


        studentas.gal = 0.4 * studentas.vid + 0.6 * studentas.egz; //galutinis pazymys
        studentas.med = findMedian(studentas.nd); //mediana
        s.push_back(studentas);
    } return s;
}

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    auto st = start;
    std::vector <Studentas> stud;
    generuoti_failus("testas1000.txt", 1000);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 1000 irasu generavimas uztruko: " << diff.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    st = start;
    //generuoti_failus("testas1000000.txt", 1000000);
    //generuoti_failus("testas10000000.txt", 10000000);
    stud = duomenu_ivedimas_is_failo("testas1000.txt", 0);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 1000 irasu ivedimas uztruko: " << diff.count() << " s\n";
    rusiavimas(stud);


    start = std::chrono::high_resolution_clock::now();
    st = start;
    generuoti_failus("testas10000.txt", 10000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 10000 irasu generavimas uztruko: " << diff.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    st = start;
    stud = duomenu_ivedimas_is_failo("testas10000.txt", 0);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 10000 irasu ivedimas uztruko: " << diff.count() << " s\n";
    rusiavimas(stud);

    start = std::chrono::high_resolution_clock::now();
    st = start;
    generuoti_failus("testas100000.txt", 100000);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 100000 irasu generavimas uztruko: " << diff.count() << " s\n";
    start = std::chrono::high_resolution_clock::now();
    st = start;
    stud = duomenu_ivedimas_is_failo("testas100000.txt", 0);
    end = std::chrono::high_resolution_clock::now();
    diff = end - start; // Skirtumas (s)
    std::cout << "Failo is 100000 irasu ivedimas uztruko: " << diff.count() << " s\n";
    rusiavimas(stud);
}
