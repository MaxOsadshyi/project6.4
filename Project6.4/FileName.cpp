#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <Windows.h>


using namespace std;

// ������� ��� ��������� �� ���������� ���������� ������ ����������� �������
void createDynamicArray(vector<double>& array, int size) {
    array.resize(size);
    for (int i = 0; i < size; i++) {
        array[i] = static_cast<double>(rand() % 100 - 50);  // ���������� �������� ����� �� -50 �� 49
    }
}

// ������� ��� ��������� ������ �� ����� � ������ ����� � �������������
void printDynamicArrayFormatted(const vector<double>& array) {
    for (int i = 0; i < array.size(); i++) {
        cout  << array[i];
        if (i < array.size() - 1) {
            cout << ' ';
        }
    }
    cout << endl;
}

// ������� ��� ���������� ������� ��'����� �������� ������
double calculateNegativeProduct(const vector<double>& array) {
    double product = 1.0;
    for (double num : array) {
        if (num < 0) {
            product *= num;
        }
    }
    return product;
}



// ������� ��� ���������� ���� ��� �������� �������� ������
double calculateSumOfAllPositives(const vector<double>& array) {
    double sum = 0.0;
    for (double num : array) {
        if (num > 0) {
            sum += num;
        }
    }
    return sum;
}

// ������� ��� ���� ������� ��������� ������ �������� � ����� �� ���������
void reverseOrderOfEvenElements(vector<double>& array) {
    int evenStart = 0;  // ���������� ������ ������� ������� ��������
    int evenEnd = array.size() - 1;  // ���������� ������ ���������� ������� ��������

    while (evenStart < evenEnd) {
        // ��������� ������ ������ ������� � ������� ������
        while (evenStart < array.size() && array[evenStart] - static_cast<int>(array[evenStart]) != 0) {
            evenStart++;
        }

        // ��������� ������ ������ ������� � ���� ������
        while (evenEnd >= 0 && array[evenEnd] - static_cast<int>(array[evenEnd]) != 0) {
            evenEnd--;
        }

        // ̳����� ������ ���� ��������
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
    cout << "������ ������� �������� ������: ";
    cin >> n;

    vector<double> dynamicArray;
    createDynamicArray(dynamicArray, n);

    cout << "������������ �����: ";
    printDynamicArrayFormatted(dynamicArray);

    // �������� 1.1: ������� ��'����� �������� ������
    double negativeProduct = calculateNegativeProduct(dynamicArray);
    cout << "������� ��'����� ��������: " << negativeProduct << endl;

    // �������� 1.2: ���������� ���� ��� �������� ��������
    double sumOfAllPositives = calculateSumOfAllPositives(dynamicArray);
    cout << "���� ��� �������� ��������: " << sumOfAllPositives << endl;

    

    // �������� 2: ���� ������� ��������� ������ �������� �� ���������
    reverseOrderOfEvenElements(dynamicArray);
    cout << "������������� ����� (������� ������� ������ ��������): ";
    printDynamicArrayFormatted(dynamicArray);

    

    return 0;
}
