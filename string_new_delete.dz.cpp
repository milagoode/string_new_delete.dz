//#include <iostream>
//using namespace std;
//
//void removeRow(int**& arr, int& rows, int cols, int rowToRemove) {
//    for (int i = rowToRemove; i < rows - 1; ++i) {
//        for (int j = 0; j < cols; ++j) {
//            arr[i][j] = arr[i + 1][j];
//        }
//    }
//    rows--;
//    cout << "рядок видалено.\n";
//}
//
//void result(int** arr, int rows, int cols) {
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    system("chcp 1251>null");
//    int rows = 4, cols = 4;
//    int rowToRemove;
//    int** arr = new int* [rows];
//    cout << "введіть елементи матриці розміром " << rows << "x" << cols << ":\n";
//    for (int i = 0; i < rows; i++) {
//        arr[i] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            cin >> arr[i][j];
//        }
//    }
//    cout << "введіть номер рядка для видалення (1-" << rows << "): ";
//    cin >> rowToRemove;
//    if (rowToRemove < 1 || rowToRemove > rows) {
//        cout << "помилка\n";
//        for (int i = 0; i < rows; i++) {
//            delete[] arr[i];
//        }
//        delete[] arr;
//        return 0;
//    }
//    rowToRemove--; 
//
//    removeRow(arr, rows, cols, rowToRemove);
//    result(arr, rows, cols);
//
//    for (int i = 0; i < rows; i++) {
//        delete[] arr[i];
//    }
//    delete[] arr;
//
//    return 0;
//}

//#include <iostream>
//using namespace std;
//
//void transMat(int**& arr, int& rows, int& cols) {
//    int** trans = new int* [cols]; 
//    for (int i = 0; i < cols; i++) {
//        trans[i] = new int[rows];
//    }
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            trans[j][i] = arr[i][j];
//        }
//    }
//
//    for (int i = 0; i < rows; i++) {
//        delete[] arr[i];
//    }
//    delete[] arr;
//
//    arr = trans; 
//    swap(rows, cols); 
//}
//
//void result(int** arr, int rows, int cols) {
//    cout << "Матриця:\n";
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j < cols; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//
//int main() {
//    system("chcp 1251>null");
//    int rows, cols;
//
//    cout << "Введіть кількість рядків матриці: ";
//    cin >> rows;
//    cout << "Введіть кількість стовпців матриці: ";
//    cin >> cols;
//
//    int** arr = new int* [rows];
//    cout << "Введіть елементи матриці розміром " << rows << "x" << cols << ":\n";
//    for (int i = 0; i < rows; i++) {
//        arr[i] = new int[cols];
//        for (int j = 0; j < cols; j++) {
//            cin >> arr[i][j];
//        }
//    }
//
//    transMat(arr, rows, cols); 
//    result(arr, rows, cols); 
//
//    for (int i = 0; i < rows; i++) {
//        delete[] arr[i];
//    }
//    delete[] arr;
//
//    return 0;
//}

#include <iostream>
#include <string>
using namespace std;

void input(string*& arr, int& size) {
    string* newArr = new string[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    cout << "введіть ім'я/телефон для запису #" << size + 1 << ": ";
    cin >> newArr[size];
    delete[] arr;
    arr = newArr;
    size++;
}

void output(string* arr, int size) {
    cout << "записи:\n";
    for (int i = 0; i < size; i++) {
        cout << "запис #" << i + 1 << ": " << arr[i] << endl;
    }
}

void name(string* arr, int size, const string& searchName) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchName) {
            cout << "знайдено: " << arr[i] << endl;
            return;
        }
    }
    cout << "не знайдено.\n";
}

void phone(string* arr, int size, const string& searchPhone) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == searchPhone) {
            cout << "знайдено: " << arr[i] << endl;
            return;
        }
    }
    cout << "не знайдено.\n";
}

void update(string* arr, int index, const string& newData) {
    arr[index] = newData;
    cout << "дані оновлено.\n";
}

int main() {
    system("chcp 1251>null");
    string* arr = nullptr;
    int size = 0;
    int choice;

    do {
        cout << "\nМеню:\n";
        cout << "1. ввести дані\n";
        cout << "2. вивести дані\n";
        cout << "3. пошук за ім'ям\n";
        cout << "4. пошук за телефоном\n";
        cout << "5. змінити дані\n";
        cout << "6. вихід\n";
        cout << "виберіть дію: ";
        cin >> choice;

        switch (choice) {
        case 1:
            input(arr, size);
            break;
        case 2:
            output(arr, size);
            break;
        case 3: {
            string searchName;
            cout << "введіть ім'я для пошуку: ";
            cin >> searchName;
            name(arr, size, searchName);
            break;
        }
        case 4: {
            string searchPhone;
            cout << "введіть номер телефону для пошуку: ";
            cin >> searchPhone;
            phone(arr, size, searchPhone);
            break;
        }
        case 5: {
            int index;
            string newData;
            cout << "введіть номер запису (1-" << size << ") для зміни: ";
            cin >> index;
            if (index < 1 || index > size) {
                cout << "помилка: номер запису поза межами.\n";
                break;
            }
            cout << "введіть нові дані: ";
            cin >> newData;
            update(arr, index - 1, newData);
            break;
        }
        case 6:
            cout << "вихід.\n";
            break;
        default:
            cout << "помилка.\n";
        }
    } while (choice != 6);

    delete[] arr;

    return 0;
}
