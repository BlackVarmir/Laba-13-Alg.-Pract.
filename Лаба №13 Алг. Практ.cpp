#include <iostream>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Функція для друку матриці
void printMatrix(const vector<vector<double>>& matrix) {
    for (const auto& row : matrix) {
        for (const auto& elem : row) {
            cout << setw(8) << elem << " ";
        }
        cout << endl;
    }
}

// Завдання 1: Поміняти місцями два стовпці
void swapColumns(vector<vector<double>>& A, int k, int p) {
    if (k < 1 || k > A[0].size() || p < 1 || p > A[0].size()) {
        cout << "Помилка: введені номери стовпців некоректні!" << endl;
        return;
    }
    for (int i = 0; i < A.size(); ++i) {
        swap(A[i][k - 1], A[i][p - 1]);
    }
    cout << "Матриця після обміну стовпців " << k << " та " << p << ":" << endl;
    printMatrix(A);
}

// Завдання 2: Середнє максимальне значення рядків з нулем на головній діагоналі
void averageMaxInRowsWithZero(vector<vector<double>>& A) {
    double sumMax = 0;
    int count = 0;

    for (int i = 0; i < A.size(); ++i) {
        if (A[i][i] == 0) { // Перевірка нуля на головній діагоналі
            double maxElem = *max_element(A[i].begin(), A[i].end());
            sumMax += maxElem;
            count++;
        }
    }

    if (count == 0) {
        cout << "Немає рядків з нулем на головній діагоналі." << endl;
    }
    else {
        cout << "Середнє максимальне значення рядків з нулем на головній діагоналі: "
            << sumMax / count << endl;
    }
}

// Завдання 3: Обчислити C = A + A^T
void addTranspose(vector<vector<double>>& A) {
    int n = A.size();
    vector<vector<double>> C(n, vector<double>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            C[i][j] = A[i][j] + A[j][i];
        }
    }

    cout << "Матриця C = A + A^T:" << endl;
    printMatrix(C);
}

// Завдання 4: Різниця між max і min головної діагоналі, робота з бічною діагоналлю
void differenceAndColumn(vector<vector<double>>& A) {
    int n = A.size();
    double maxElem = A[0][0];
    double minElem = A[0][0];
    bool hasZero = false;

    // Обчислення max і min головної діагоналі
    for (int i = 0; i < n; ++i) {
        maxElem = max(maxElem, A[i][i]);
        minElem = min(minElem, A[i][i]);
    }

    // Перевірка нулів на бічній діагоналі
    for (int i = 0; i < n; ++i) {
        if (A[i][n - i - 1] == 0) {
            hasZero = true;
            break;
        }
    }

    cout << "Різниця між найбільшим і найменшим елементом головної діагоналі: "
        << maxElem - minElem << endl;

    if (hasZero) {
        cout << "Виводимо 1-й стовпець матриці:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << A[i][0] << endl;
        }
    }
    else {
        cout << "Виводимо останній стовпець матриці:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << A[i][n - 1] << endl;
        }
    }
}

// Завдання 5: Добуток елементів стовпців з c1 по c2
void productOfColumns(vector<vector<int>>& A, int c1, int c2) {
    if (c1 < 1 || c1 > A[0].size() || c2 < 1 || c2 > A[0].size() || c1 > c2) {
        cout << "Помилка: введені номери стовпців некоректні!" << endl;
        return;
    }

    int product = 1;
    for (int j = c1 - 1; j < c2; ++j) {
        for (int i = 0; i < A.size(); ++i) {
            product *= A[i][j];
        }
    }

    cout << "Добуток елементів стовпців з " << c1 << " по " << c2 << ": "
        << product << endl;
}

// Основна функція
int main() {
    srand(time(0));
    int n, option;

    while (true) {
        cout << "\nМеню:\n";
        cout << "1. Поміняти місцями два стовпці\n";
        cout << "2. Середнє максимальне значення рядків з нулем на головній діагоналі\n";
        cout << "3. Обчислити C = A + A^T\n";
        cout << "4. Робота з головною і бічною діагоналями\n";
        cout << "5. Добуток елементів стовпців з c1 по c2\n";
        cout << "0. Вихід\n";
        cout << "Оберіть опцію: ";
        cin >> option;

        if (option == 0) break;

        cout << "Введіть розмірність матриці n: ";
        cin >> n;

        if (option == 5) {
            // Цілочислова матриця для завдання 5
            vector<vector<int>> A(n, vector<int>(n));
            for (auto& row : A)
                for (auto& elem : row)
                    elem = -5 + rand() % 11; // Випадкові цілі числа [-5, 5]

            int c1, c2;
            cout << "Введіть c1 та c2: ";
            cin >> c1 >> c2;

            productOfColumns(A, c1, c2);
        }
        else {
            // Дійсна матриця для решти завдань
            vector<vector<double>> A(n, vector<double>(n));
            for (auto& row : A)
                for (auto& elem : row)
                    elem = -5 + rand() % 11; // Випадкові дійсні числа [-5, 5]

            cout << "Початкова матриця:\n";
            printMatrix(A);

            switch (option) {
            case 1: {
                int k, p;
                cout << "Введіть номери стовпців k та p: ";
                cin >> k >> p;
                swapColumns(A, k, p);
                break;
            }
            case 2:
                averageMaxInRowsWithZero(A);
                break;
            case 3:
                addTranspose(A);
                break;
            case 4:
                differenceAndColumn(A);
                break;
            default:
                cout << "Невірний вибір!" << endl;
            }
        }
    }

    return 0;
}
