#include <iostream>
#include "Polinom.h"
#include <locale>

using namespace std;

void PrintMenu() {
    cout << "\n����:" << endl;
    cout << "1. ���� ������� ��������" << endl;
    cout << "2. ����� ������� ��������" << endl;
    cout << "3. ���� ������� ��������" << endl;
    cout << "4. ����� ������� ��������" << endl;
    cout << "5. ������� ��������" << endl;
    cout << "6. �������� ��������" << endl;
    cout << "7. �������� ������ �������" << endl;
    cout << "8. �������� ������ �������" << endl;
}

void AddMonomToPolinom(Polinom& polinom) {
    int coeff, dx, dy, dz;
    cout << "������� ����������� ������: ";
    cin >> coeff;
    cout << "������� ������� x: ";
    cin >> dx;
    cout << "������� ������� y: ";
    cin >> dy;
    cout << "������� ������� z: ";
    cin >> dz;

    try {
        if (dx > 10 || dy > 10 || dz > 10) {
            throw invalid_argument("������� �� ����� ���� ������ 10");
        }

        Monom newMonom(coeff, dx, dy, dz);
        polinom.AddMonom(newMonom);
        cout << "����� ��������." << endl;
    }
    catch (const invalid_argument& e) {
        cout << "������: " << e.what() << endl;
    }
}

void OutputPolinom(const Polinom& polinom) {
    cout << "�������: " << polinom << endl;
}

void ClearPolinom(Polinom& polinom) {
    polinom.Clear();
    cout << "������� ������." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Polinom polinom1;
    Polinom polinom2;

    int choice = 0;

    while (choice != 9) {
        PrintMenu();
        cout << "�������� ��������: ";
        cin >> choice;

        switch (choice) {
        case 1:
            AddMonomToPolinom(polinom1);
            break;
        case 2:
            OutputPolinom(polinom1);
            break;
        case 3:
            AddMonomToPolinom(polinom2);
            break;
        case 4:
            OutputPolinom(polinom2);
            break;
        case 5:
            try {
                polinom1 - polinom2;  // ���������� ��������, ������� ���������� �������� � ������� polinom2
                cout << "��������� ��������: " << polinom1 << endl;
            }
            catch (const invalid_argument& e) {
                cout << "������: " << e.what() << endl;
            }
            break;
        case 6:
            try {
                Polinom result = polinom1 + polinom2;
                cout << "��������� ��������: " << result << endl;
            }
            catch (const invalid_argument& e) {
                cout << "������: " << e.what() << endl;
            }
            break;
        case 7:
            ClearPolinom(polinom1);
            break;
        case 8:
            ClearPolinom(polinom2);
            break;
        default:
            if (choice != 9) {
                cout << "�������� �����, ���������� �����." << endl;
            }
            break;
        }
    }

    return 0;
}
