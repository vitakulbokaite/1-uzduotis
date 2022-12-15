#pragma once

#include<string>

using namespace std;

class Zmogus {
private:
    string vardas;
    string pavarde;

public:

    Zmogus() : vardas(""), pavarde("") {}
    Zmogus(istream& is);
    Zmogus(const Zmogus& zmogus);
    Zmogus(string vardas, string pavarde) : vardas(vardas), pavarde(pavarde) {};

    inline string getVardas() const { return vardas; }
    inline string getPavarde() const { return pavarde; }

    virtual string getFullName() = 0;
};
