#include <iostream>
#include "Polinom.h"
#include <locale>

using namespace std;

void PrintMenu() {
    cout << "\nМеню:" << endl;
    cout << "1. Ввод первого полинома" << endl;
    cout << "2. Вывод первого полинома" << endl;
    cout << "3. Ввод второго полинома" << endl;
    cout << "4. Вывод второго полинома" << endl;
    cout << "5. Простое сложение" << endl;
    cout << "6. Сложение слиянием" << endl;
    cout << "7. Очистить первый полином" << endl;
    cout << "8. Очистить второй полином" << endl;
}

void AddMonomToPolinom(Polinom& polinom) {
    int coeff, dx, dy, dz;
    cout << "Введите коэффициент монома: ";
    cin >> coeff;
    cout << "Введите степень x: ";
    cin >> dx;
    cout << "Введите степень y: ";
    cin >> dy;
    cout << "Введите степень z: ";
    cin >> dz;

    try {
        if (dx > 10 || dy > 10 || dz > 10) {
            throw invalid_argument("Степень не может быть больше 10");
        }

        Monom newMonom(coeff, dx, dy, dz);
        polinom.AddMonom(newMonom);
        cout << "Моном добавлен." << endl;
    }
    catch (const invalid_argument& e) {
        cout << "Ошибка: " << e.what() << endl;
    }
}

void OutputPolinom(const Polinom& polinom) {
    cout << "Полином: " << polinom << endl;
}

void ClearPolinom(Polinom& polinom) {
    polinom.Clear();
    cout << "Полином очищен." << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    Polinom polinom1;
    Polinom polinom2;

    int choice = 0;

    while (choice != 9) {
        PrintMenu();
        cout << "Выберите действие: ";
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
                polinom1 - polinom2;  // Используем оператор, который объединяет полиномы и очищает polinom2
                cout << "Результат сложения: " << polinom1 << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Ошибка: " << e.what() << endl;
            }
            break;
        case 6:
            try {
                Polinom result = polinom1 + polinom2;
                cout << "Результат сложения: " << result << endl;
            }
            catch (const invalid_argument& e) {
                cout << "Ошибка: " << e.what() << endl;
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
                cout << "Неверный выбор, попробуйте снова." << endl;
            }
            break;
        }
    }

    return 0;
}
