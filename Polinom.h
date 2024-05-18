#ifndef POLINOM_H
#define POLINOM_H

#include "Monom.h"
#include <list>
#include <iostream>

class Polinom {
private:
    std::list<Monom> monoms;

public:
    Polinom() = default;

    void AddMonom(const Monom& m) {
        monoms.push_back(m);
        monoms.sort();
    }

    void Clear() {
        monoms.clear();
    }

    Polinom operator+(const Polinom& other) const {
        Polinom result;
        auto it1 = monoms.begin();
        auto it2 = other.monoms.begin();

        while (it1 != monoms.end() && it2 != other.monoms.end()) {
            if (*it1 < *it2) {
                result.AddMonom(*it1);
                ++it1;
            }
            else if (*it2 < *it1) {
                result.AddMonom(*it2);
                ++it2;
            }
            else {
                int newCoeff = it1->GetCoeff() + it2->GetCoeff();
                if (newCoeff != 0) {
                    Monom combined(newCoeff, it1->GetDegree(0), it1->GetDegree(1), it1->GetDegree(2));
                    result.AddMonom(combined);
                }
                ++it1;
                ++it2;
            }
        }

        while (it1 != monoms.end()) {
            result.AddMonom(*it1);
            ++it1;
        }

        while (it2 != other.monoms.end()) {
            result.AddMonom(*it2);
            ++it2;
        }

        if (result.monoms.empty()) {
            result.AddMonom(Monom(0, 0, 0, 0));
        }

        return result;
    }

    Polinom& operator-(Polinom& other) {
        auto it1 = monoms.begin();
        auto it2 = other.monoms.begin();

        while (it1 != monoms.end() && it2 != other.monoms.end()) {
            if (*it1 < *it2) {
                ++it1;
            }
            else if (*it2 < *it1) {
                AddMonom(*it2);
                ++it2;
            }
            else {
                int newCoeff = it1->GetCoeff() + it2->GetCoeff();
                if (newCoeff != 0) {
                    it1->SetCoeff(newCoeff);
                    ++it1;
                }
                else {
                    it1 = monoms.erase(it1);
                }
                ++it2;
            }
        }

        while (it2 != other.monoms.end()) {
            AddMonom(*it2);
            ++it2;
        }

        other.Clear();
        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Polinom& p) {
        bool first = true;
        for (const Monom& m : p.monoms) {
            if (!first) {
                os << " + ";
            }
            os << m;
            first = false;
        }
        return os;
    }
};

#endif // POLINOM_H
