#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <ios>
#include <iomanip>

const int SIZE = 100;
struct Studentas{
    std::string vardas;
    std::string pavarde;
    int nd[SIZE];
    double egz;
    double med;
    double vid;
    double gal;
};
int nd_skaicius = 0;
int studentu_sk;
Studentas studentai[SIZE];

double findMedian(int intArray[], int length) {
    double median;
    // Sorting algorithm used for effiecieny 
    std::sort(intArray, intArray + length);
    // Calculate the median for odd length intArrays
    median = intArray[(length / 2)];
    // Check if array has an even length
    if (length % 2 == 0) {
        // if even intArray, get next number in intArray and divide by 2
        median = (median + intArray[length / 2 - 1]) / 2;
    }
    // Return the calculated median
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
        std::cout << "\nIvesti studento namu darbu pazymius, viska ivedus, irasyti betkokia raide: ";
        for (int i = 0; i < SIZE; i++) {
            std::cin >> studentai[z].nd[i];
            //patikrinama ar ivestas pazymys priklauso intervalui 1-10
            if (studentai[z].nd[i] < 0 || studentai[z].nd[i] > 10) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "\nKlaida. Iveskite nd pazymi is naujo: ";
                std::cin >> studentai[z].nd[i];
            }
            else if (std::cin.good()) {
                //input worked
                nd_skaicius++;
            }

            else {
                //invalid character
                break;
            }
        }
        //sudedami namu darbu pazymiai vidurkio skaiciavimui
        int nd_sudetis = 0;
        for (int i = 0; i < nd_skaicius; i++) {
            nd_sudetis += studentai[z].nd[i];
        }
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "\nIveskite studento egzamino pazymi: ";
        std::cin >> studentai[z].egz;
        //patikrinama, kad egzamino pazymis butu int tipo ir priklasytu 1-10 intervalui
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
        if (nd_skaicius != 0) {
            studentai[z].vid = nd_sudetis / nd_skaicius; // vidurkio skaiciavimas
        }
        else {
            studentai[z].vid == 0;
        }


        studentai[z].gal = 0.4 * studentai[z].vid + 0.6 * studentai[z].egz;
        studentai[z].med = findMedian(studentai[z].nd, nd_skaicius);

    }
}

    

int main()
{
    duomenu_ivedimas();
    std::cout << std::left << std::setw(15) << "Pavarde" << std::left << std::setw(15) << "Vardas" << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; 
    for (int a = 1; a < studentu_sk + 1; a++)  
        std::cout << std::left << std::setw(15) << studentai[a].pavarde << std::left << std::setw(15) << studentai[a].vardas << std::left << std::setw(20) << studentai[a].gal << std::left << std::setw(20) << studentai[a].med << std::endl;
    for (int i = 0;i < 70;i++) std::cout << "-";
    std::cout << std::endl; 
}
