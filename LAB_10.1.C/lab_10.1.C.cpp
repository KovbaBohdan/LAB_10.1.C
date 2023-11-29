#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Count(FILE* f) {
    int k = 0;
    char current, next;
    current = getc(f); // Читаємо перший символ з файлу
    while ((next = getc(f)) != EOF) { // Читаємо наступний символ
        if (current == next) { // Перевіряємо, чи вони однакові
            int consecutive = 2; // Вже маємо два однакових символи
            while ((next = getc(f)) == current && next != EOF) { // Продовжуємо читати і порівнювати
                consecutive++;
                if (consecutive == 4) { // Якщо маємо послідовність з 4 однакових символів
                    k++;
                    break; // Вихід з циклу, знайдено послідовність
                }
            }
        }
        current = next; // Переміщуємось до наступної пари символів
    }
    return k;
}

int main() {
    FILE* f;
    const int LEN = 61;
    char fname[LEN];
    cout << "Enter file name: ";
    cin.getline(fname, LEN);
    if ((f = fopen(fname, "r")) == NULL) {
        cerr << "Error opening file '" << fname << "'" << endl;
        exit(1);
    }

    cout << "File content: " << endl;
    int ch;
    while ((ch = getc(f)) != EOF) {
        cout.put(ch);
    }

    rewind(f); // Переміщаємо позицію файлу на початок

    int consecutiveCount = Count(f);
    cout << "Number of consecutive sequences of 4 characters: " << consecutiveCount << endl;

    fclose(f);
    return 0;
}
