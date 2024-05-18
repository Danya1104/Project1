#include <iostream> 
#include <array> 
#include <stdexcept> 
#include <sstream> 

class TDatValue {
public:
    virtual TDatValue* GetCopy() const = 0;
    virtual ~TDatValue() {}
};

class Monom : public TDatValue {
private:
    int coeff;
    std::array<int, 3> degrees;

public:

    Monom(int c = 1, int dx = 0, int dy = 0, int dz = 0) {
        coeff = c;
        degrees = { dx, dy, dz };
        for (int d : degrees) {
            if (d > 10) {
                throw std::invalid_argument("Степень не может быть выше 10");
            }
        }
    }
    TDatValue* GetCopy() const override {
        return new Monom(coeff, degrees[0], degrees[1], degrees[2]);
    }

    void SetCoeff(int c) { coeff = c; }
    int GetCoeff() const { return coeff; }

    void SetDegree(int index, int value) {
        if (index < 0 || index >= 3) {
            throw std::invalid_argument("Недопустимый индекс переменной");
        }
        if (value > 10) {
            throw std::invalid_argument("Степень не может быть выше 10");
        }
        degrees[index] = value;
    }

    int GetDegree(int index) const {
        if (index < 0 || index >= 3) {
            throw std::invalid_argument("Недопустимый индекс переменной");
        }
        return degrees[index];
    }
    Monom& operator=(const Monom& other) {
        if (this != &other) {
            coeff = other.coeff;
            degrees = other.degrees;
        }
        return *this;
    }
    bool operator==(const Monom& other) const {
        return coeff == other.coeff && degrees == other.degrees;
    }

    bool operator<(const Monom& other) const {
        return degrees < other.degrees;
    }
    std::string ToString() const {
        std::ostringstream os;
        os << coeff;
        if (degrees[0] > 0) {
            os << "x^" << degrees[0];
        }
        if (degrees[1] > 0) {
            os << "y^" << degrees[1];
        }
        if (degrees[2] > 0) {
            os << "z^" << degrees[2];
        }
        return os.str();
    }
    friend std::ostream& operator<<(std::ostream& os, const Monom& m) {
        os << m.ToString();
        return os;
    }
};