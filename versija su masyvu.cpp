#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

const int SIZE = 100;
  struct {
      std::string vardas;
      std::string pavarde;
      int nd[SIZE];
      double egz;
  }studentas;
  double vid;
  double gal;
  int nd_skaicius = 0;

void duomenu_ivedimas(){
  std::cout << "Iveskite studento varda: " ;
  std::cin >> studentas.vardas;
  std::cout << "\nIveskite studento pavarde: " ;
  std::cin >> studentas.pavarde;
    std::cin.clear();
  std::cin.ignore(10000, '\n');
  std::cout << "\nIvesti studento namu darbu pazymius, viska ivedus, irasyti betkokia raide: " ;
  for(int i = 0; i < SIZE; i++){
      std::cin >> studentas.nd[i];
      //patikrinama ar ivestas pazymys priklauso intervalui 1-10
      if (studentas.nd[i] < 0 || studentas.nd[i] > 10) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nKlaida. Iveskite nd pazymi is naujo: ";
        std::cin>>studentas.nd[i];
      }
      else if(std::cin.good()){
          //input worked
          nd_skaicius++;
      }
          
      else{
          //invalid character
          break;
      }
  }
  //sudedami namu darbu pazymiai vidurkio skaiciavimui
  int nd_sudetis = 0;
  for (int i = 0 ; i < nd_skaicius; i++){
      nd_sudetis+=studentas.nd[i];
  }
  std::cin.clear();
  std::cin.ignore(10000, '\n');
  std::cout << "\nIveskite studento egzamino pazymi: " ;
  std::cin >> studentas.egz;
  //patikrinama, kad egzamino pazymis butu int tipo ir priklasytu 1-10 intervalui
  while(1)
    {
    if(std::cin.fail() || studentas.egz < 0 || studentas.egz > 10)
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        std::cout<<"\nKlaida. Iveskite egzamino pazymi is naujo: ";
        std::cin>>studentas.egz;
    }
    if(!std::cin.fail())
        break;
    }
    if (nd_skaicius != 0 ){
  vid = nd_sudetis/nd_skaicius; // vidurkio skaiciavimas
    }
    else {
        vid == 0; 
        }

  gal = 0.4*vid+0.6*studentas.egz; //galutinis pazymys
    }
    //medianos skaiciavimas
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
    
int main()
{
    int choice;
    do {
        std::cout << "0.Baigti duomenu ivedima\n1.Ivesti studento duomenis\n";
        std::cin >> choice;
        
        switch(choice){
            case 0:
            std:: cout << "Pavardė    Vardas      Galutinis (Vid.)  Galutinis (Med.)\n" << "------------------------------------------------------\n" << studentas.pavarde << "   " << studentas.vardas << "          " << gal << "                 " << findMedian(studentas.nd, nd_skaicius);
                return 0;
            case 1:
            duomenu_ivedimas();
            break;
        }
    }
    while (choice != 0);
}
            
