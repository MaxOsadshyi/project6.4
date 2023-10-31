#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>


using namespace std;

// Функція для створення та заповнення динамічного масиву випадковими числами
void createDynamicArray(vector<double>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = static_cast<double>(rand() % 100 - 50);  // Генерувати випадкові числа від -50 до 49
    }
}

// Функція для виведення масиву на екран у вигляді рядка з форматуванням
void printDynamicArrayFormatted(const vector<double>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout  << array[i];
        if (i < array.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

// Функція для обчислення добутку від'ємних елементів масиву
double calculateNegativeProduct(const vector<double>& array) {
    double product = 1.0;
    for (double num : array) {
        if (num < 0) {
            product *= num;
        }
    }
    return product;
}



// Функція для обчислення суми всіх додатних елементів масиву
double calculateSumOfAllPositives(const vector<double>& array) {
    double sum = 0.0;
    for (double num : array) {
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

// Функція для зміни порядку розміщення парних елементів в масиві на зворотний
void reverseOrderOfEvenElements(vector<double>& array) {
    int evenStart = 0;  // Початковий індекс першого парного елементу
    int evenEnd = array.size() - 1;  // Початковий індекс останнього парного елементу

    while (evenStart < evenEnd) {
        // Знаходимо перший парний елемент з початку масиву
        while (evenStart < array.size() && array[evenStart] - static_cast<int>(array[evenStart]) != 0) {
            evenStart++;
        }

        // Знаходимо перший парний елемент з кінця масиву
        while (evenEnd >= 0 && array[evenEnd] - static_cast<int>(array[evenEnd]) != 0) {
            evenEnd--;
        }

        // Міняємо місцями парні елементи
        if (evenStart < evenEnd) {
            swap(array[evenStart], array[evenEnd]);
        }

        evenStart++;
        evenEnd--;
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Введіть кількість елементів масиву: ";
    cin >> n;

    vector<double> dynamicArray;
    createDynamicArray(dynamicArray, n);

    cout << "Згенерований масив: ";
    printDynamicArrayFormatted(dynamicArray);

    // Завдання 1.1: Добуток від'ємних елементів масиву
    double negativeProduct = calculateNegativeProduct(dynamicArray);
    cout << "Добуток від'ємних елементів: " << negativeProduct << endl;

    // Завдання 1.2: Обчислення суми всіх додатних елементів
    double sumOfAllPositives = calculateSumOfAllPositives(dynamicArray);
    cout << "Сума всіх додатних елементів: " << sumOfAllPositives << endl;

    

    // Завдання 2: Зміна порядку розміщення парних елементів на зворотний
    reverseOrderOfEvenElements(dynamicArray);
    cout << "Модифікований масив (змінений порядок парних елементів): ";
    printDynamicArrayFormatted(dynamicArray);

    

    return 0;
}
