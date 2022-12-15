#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

#include "Zmogus.h"

using namespace std;

class Studentas : public Zmogus {
private:
    vector<double> nd;
    double egz;

public:

    Studentas() : egz(0) {}

    Studentas(istream& is);

    Studentas(const Studentas& studentas);

    Studentas(string vardas, string pavarde, vector<double> nd, double egz);

    ~Studentas();

    double vid() const;

    double gal() const;

    double med() const;

    inline vector<double> getNd() const { return nd; }

    inline double getEgz() const { return egz; }

    void print(ostream& os) const;

    string getFullName() override;

    bool operator == (Studentas& studentas);
    bool operator != (Studentas& studentas);
};
