#include "Studentas.h"

#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

Studentas::Studentas(istream& is) : Zmogus(is) {
    for (int i = 0; i < 15; i++)
    {
        int el;
        is >> el;
        nd.push_back(el);
    }
    is >> egz;
}

Studentas::Studentas(const Studentas& studentas) : Zmogus(studentas) {
    for (double paz : studentas.nd)
        nd.push_back(paz);
    egz = studentas.egz;
}

Studentas::Studentas(string vardas, string pavarde, vector<double> nd, double egz) : Zmogus(vardas, pavarde) {
    for (double paz : nd)
        this->nd.push_back(paz);
    this->egz = egz;
}

Studentas::~Studentas() {
    nd.clear();
}

double Studentas::vid() const {
    double sum = 0;
    for (auto p : nd)
        sum += p;
    return sum / nd.size();
}

double Studentas::gal() const {
    return 0.4 * vid() + 0.6 * egz;
}

double Studentas::med() const {
    vector<double> copy = nd;
    sort(copy.begin(), copy.end());

    if (copy.size() % 2 == 0)
    {
        int sum;
        int index = copy.size() / 2;
        sum = copy[index] + copy[index - 1];
        return sum / 2;
    }
    else
    {
        return copy[copy.size() / 2];
    }
}

void Studentas::print(ostream& os) const {
    string paz = "";
    for (auto p : nd)
        paz += to_string(p) + " ";
    os << getVardas() + " " + getPavarde() +
        " " + paz + to_string(egz) << endl;
}

string Studentas::getFullName() {
    return getVardas() + " " + getPavarde();
}

bool compare(Studentas& const left, Studentas& const right);

bool Studentas::operator== (Studentas& studentas) {
    return compare(*this, studentas);
}

bool Studentas::operator!= (Studentas& studentas) {
    return !compare(*this, studentas);
}

bool compare(Studentas& const left, Studentas& const right) {
    if (left.getVardas() != right.getVardas())
        return false;
    if (left.getPavarde() != right.getPavarde())
        return false;
    if (left.getEgz() != right.getEgz())
        return false;
    if (left.getNd().size() != right.getNd().size())
        return false;

    for (int i = 0; i < left.getNd().size(); i++)
        if (left.getNd()[i] != right.getNd()[i])
            return false;

    return true;
}
