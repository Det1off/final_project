#pragma once

#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <chrono>
#include <thread>
#include <random>
#include <Windows.h>
#include <ctime>
using namespace std;

void start_location();
void Rindel();
void Dalion();
void displayProgress(int playerProgress, int computerProgress);
void competition();
int random_num();
int rouge_damage();

void start_location() {
    cout << "�� �������� ���������� ���� ���� ������� ��������� ����, ����� ������������� � ����� ������." << "\n" << "� �� ������� ������ ���� ����� ��� �������������� � �������� �����������." << "\n";
    cout << "������� �������� �� ��� ����� ������ ������ �� ������������ �� ��������� ������� ���������� ��� ������� ���� ��� ��������� �����������." << "\n\n";
    cout << R"(               /---------||----------\
              / ������ l || ������ r  \
              \----------||-----------/
                         ||
                         ||
                         ||
                         ||
                         ||
                         --)" << "\n";

    string choose_one;

    while (true) {
        cout << "�� ������� ����� � (l - ������, r - ������): ";
        cin >> choose_one;
        cout << "\n";

        if (choose_one == "l") {
            system("cls");
            Rindel();
            break;
        }
        else if (choose_one == "r") {
            system("cls");
            Dalion();
            break;
        }
        else {
            cout << "�������� ����. ����������, ���������� �����.\n";
        }
    }
}

void Rindel() {
    cout << R"(����� ���������� � ������ ������� "����� �����������", �� ������� ����� ����� ������ ��������� �� ����� ����� � �� ���� ��� ���� ���������� ��� ��� ���� ��������� ����� ������� �� ������ ������ ������� � ��� ����� ���� �����, �� ��� �����-�� ��������������.)" << "\n";
    cout << R"(� ������� ���������� � �������� �� ����������� �� �������� ������������, ����� ����� �������� �� ���� ��� ������ ��� � ���� ������ ����� ��� ��� �� ����. �� ������� ���� � ������ �����.)" << "\n";

    this_thread::sleep_for(chrono::seconds(25));

    system("cls");

    Dalion();
}

void Dalion() {
    cout << R"(����� ���������� � ������, ������� ������ �������� ����� � �������� ������������ ����� ����� ����������� ���� �����, ��� ������ ������ ������. ��� ��� ������ ������ �������� ����� ���� ��������� �������� ������� � ��������.)" << "\n";
    cout << R"(������� ����� � ����� � ��������� ��� ��� �������, ��� �� ������������� ��� ���-�� ������� � ��� � ������. �� ���������!)" << "\n";
    cout << R"(��� ����� ������� �����! ����� �� "A" ���� ������ �������� ���� ��������� �� ���� ��� �� ��� �������!)" << "\n";

    this_thread::sleep_for(chrono::seconds(20));

    competition();

    cout << R"(�� ������ � ���� ����� ����� ����� \"����������� ������� \" ��� �� �������� �� ���� � �� ��� �������� ����������. � ���� ����������, �������� �� ��������� ��� ����� ��� ������������ ����� ��� ���������� ����� ���� �� ������������ ������ �� ������ ������ � ���. �� ����� ����� ��� ������ ������� �� ���. )" << "\n";

    static int ur_hp = 30; // ����� ������
    static int rouge_hp = 45; // ����� ����������

    string punch; // ���������� ��� �������� ����� ������

    while (ur_hp > 0 && rouge_hp > 0) { // ���� ����� ������ � ����������� ���� � ������ �� ��� �� ���������� ��������
        cout << "���� ��������: " << ur_hp << "\n�������� ����������: " << rouge_hp << "\n";
        cout << "������� ����� ���� �� ������� ������� ������� (eye): " << "\n";
        cin >> punch;

        int playerRandomNumber = random_num();
        int rougeRandomNumber = random_num();
        int rouge_ran_dam = rouge_damage();

        if (punch == "eye") { // ����� eye ��� ���� ���� ������� ����, ����������� ��������� ��������� ����� ���� ������� �����/��������� ������� ���� ��� �����������
            if (playerRandomNumber >= 1 && playerRandomNumber <= 35) {
                cout << playerRandomNumber << "\n";
                cout << "������ ��������� � ����! ������ ������ ���������� ����� ������� ������� �� ��� � ����� ������.\n";
                rouge_hp -= 7;

                if (rougeRandomNumber <= 45) {
                    cout << "������� ��� �� ������� ��������, ��������� �������� ��� � ���. �� ����� �������� ��������.\n";
                    ur_hp -= rouge_ran_dam;
                }
                else {
                    cout << "������ ��������� �� �������������� �� ����� ����������. ��� �������!\n";
                }
            }
            else {
                cout << "�� ������������.\n";
                if (rougeRandomNumber <= 45) {
                    cout << "������� ��� �� ������� ��������, ��������� �������� ��� � ���. �� ����� �������� ��������.\n";
                    ur_hp -= rouge_ran_dam;
                }
                else {
                    cout << "������ ��������� �� �������������� �� ����� ����������. ��� �������!\n";
                }
            }
        }
        else {
            cout << "�������� �����.\n";
        }

        if (ur_hp <= 0) {
            cout << "�� ���������! �� ���� ���� ����������� ��������.\n";
            break;
        }
        else if (rouge_hp <= 0) {
            cout << "�� �������� ����������! ����� ����� ���������� �� ��������� ��������� ����� � �������, ���� ��� ����� � �������. �� ��� ����������� ���� ��� �����.\n";
            break;
        }
    }
}

int random_num() { // ��������� ��������� ����� �� 1 �� 100 ��� ��������� �����/�������
    return rand() % 100 + 1;
}

int rouge_damage() { // ��������� ���������� ����� ���������� (� ������ ������������ ����)
    return rand() % 7 + 1;
}

void displayProgress(int playerProgress, int computerProgress) { // ����� ��������� ���� ���� �� ����� (��� ����)
    system("cls");

    cout << "������������! ��������� �� 'A' ��� ����� �������!\n";

    cout << "�����:    |";
    for (int i = 0; i < playerProgress; ++i) {
        cout << "|";
    }
    cout << "\n";

    cout << "���������:|";
    for (int i = 0; i < computerProgress; ++i) {
        cout << "|";
    }
    cout << "\n";
}

void competition() { // ���� ���� � ������� ����� �� �������� �������� �� ������� � ��� ���� ���� ��������
    
    int playerProgress = 0;
    int computerProgress = 0;

    auto startTime = chrono::steady_clock::now();
    auto lastComputerTime = startTime;
    const int MAX_PROGRESS = 30;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(50, 150);

    while (playerProgress < MAX_PROGRESS && computerProgress < MAX_PROGRESS) {

        displayProgress(playerProgress, computerProgress);

        if (_kbhit()) { // �������� ������� ������� � � ����� ��, ����� ����� ����������� � ����� ��������� ������ ������ "|"
            char key = _getch();
            if (key == 'a' || key == 'A') {
                playerProgress++;
            }
        }

        auto currentTime = chrono::steady_clock::now();
        chrono::milliseconds computerInterval(distr(gen));

        if (currentTime - lastComputerTime >= computerInterval) { // ���������� ��������� ��� ���������� 
            computerProgress++;
            lastComputerTime = currentTime;
        }

        this_thread::sleep_for(chrono::milliseconds(100)); // �������� �������� ������� ������� � � ����������
    }

    displayProgress(playerProgress, computerProgress);
    this_thread::sleep_for(chrono::seconds(3));

    if (playerProgress >= MAX_PROGRESS) { // ������� ����� ��� ������/���������

        cout << "�� ��������! ��������� ��������� � ������, ������� ��� ������������.\n";
    }
    else {
        cout << "��� ��������! ��������� ���� ��������� � ������.\n";
    }
}
