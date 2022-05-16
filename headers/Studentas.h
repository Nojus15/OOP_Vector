#pragma once

#include "Validator.h"
#include "Zmogus.h"

#include <iostream>
#include <fstream>
#include "../Vector.h"
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Studentas : public Zmogus
{
private:
    Vector<int> paz;
    int egz;
    double vid;
    double med;
    Validator valid;

    void f(){};

public:
    Studentas();
    Studentas(const Studentas &s);
    Studentas &operator=(const Studentas &s);
    bool operator<(Studentas &s);
    ~Studentas();

    void setEgz(int mark);

    double getMed() const;
    double getVid() const;
    double getEgz() const;

    void enterMarkManually();
    void addMark(int mark);
    int get_popMark();

    void galutinisVid();
    void galutinisMed();
    void calcRez();
};

bool compare(Studentas &a, Studentas &b);
bool isVargsas(Studentas &a);