#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int Count(FILE* f) {
    int k = 0;
    char current, next;
    current = getc(f); // ������ ������ ������ � �����
    while ((next = getc(f)) != EOF) { // ������ ��������� ������
        if (current == next) { // ����������, �� ���� �������
            int consecutive = 2; // ��� ���� ��� ��������� �������
            while ((next = getc(f)) == current && next != EOF) { // ���������� ������ � ����������
                consecutive++;
                if (consecutive == 4) { // ���� ���� ����������� � 4 ��������� �������
                    k++;
                    break; // ����� � �����, �������� �����������
                }
            }
        }
        current = next; // ����������� �� �������� ���� �������
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

    rewind(f); // ��������� ������� ����� �� �������

    int consecutiveCount = Count(f);
    cout << "Number of consecutive sequences of 4 characters: " << consecutiveCount << endl;

    fclose(f);
    return 0;
}
