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
    cout << "Вы странник отринувший весь свой прошлый жизненный путь, после произошедшего в вашем стране." << "\n" << "И вы решаете начать свою жизнь как путешественник и искатель приключений." << "\n";
    cout << "Покидая выженные до тла места родной страны вы наталкиваете на указатель который предлогает вам выбрать путь для дайнейших приключений." << "\n\n";
    cout << R"(               /---------||----------\
              / Риндел l || Далион r  \
              \----------||-----------/
                         ||
                         ||
                         ||
                         ||
                         ||
                         --)" << "\n";

    string choose_one;

    while (true) {
        cout << "Вы решаете пойти в (l - Риндел, r - Далион): ";
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
            cout << "Неверный ввод. Пожалуйста, попробуйте снова.\n";
        }
    }
}

void Rindel() {
    cout << R"(Добро пожаловать в Риндел некогда "Город Бессмертных", во времена когда эльфы только появились на нашей земле и до того как тьма осквернила его там были источники жизни которые не давали эльфам стареть и они могли жить вечно, но все когда-то заканчиваеться.)" << "\n";
    cout << R"(В попытке пообщаться с местными вы натыкаетесь на местного предводителя, одним своим взглядом он дает вам понять что в этом городе таким как вам не рады. Вы решаете уйти в другой город.)" << "\n";

    this_thread::sleep_for(chrono::seconds(25));

    system("cls");

    Dalion();
}

void Dalion() {
    cout << R"(Добро пожаловать в Далион, некогда бывшая цитадель орков и нынешний неприступный город людей захвативший этот замок, тут царить полный разбой. Так что путник совету выбирать слова если надумаешь наладить общение с местными.)" << "\n";
    cout << R"(Неуспев зайти в город и осмотреть его как следует, как вы почувствовали что кто-то тянется к вам в карман. ЭЙ ГРАБИТЕЛЬ!)" << "\n";
    cout << R"(Это будет великая битва! Жмите на "A" чтоб успеть схватить руку грабителя до того как он вас ограбит!)" << "\n";

    this_thread::sleep_for(chrono::seconds(20));

    competition();

    cout << R"(Не прошло и пяти минут после вашей \"ЛЕГЕНДАРНОЙ СХВАТКИ \" как вы заходите за угол и на вас нападают разбойники. С виду неопрятные, граязные да настолько что еслиб вам понадобилось масло для сковородки можно было бы использовать волосы на голове одного с них. Не долго думая они решили напасть на вас. )" << "\n";

    static int ur_hp = 30; // Жизни игрока
    static int rouge_hp = 45; // Жизни разбойника

    string punch; // переменная для хранения удара игрока

    while (ur_hp > 0 && rouge_hp > 0) { // Цикл битвы игрока с разбойником пока у одного из них не закончится здоровье
        cout << "Ваше здоровье: " << ur_hp << "\nЗдоровье разбойника: " << rouge_hp << "\n";
        cout << "Введите место куда вы желаете ударить бандита (eye): " << "\n";
        cin >> punch;

        int playerRandomNumber = random_num();
        int rougeRandomNumber = random_num();
        int rouge_ran_dam = rouge_damage();

        if (punch == "eye") { // Пишем eye для того чтоб нанести удар, применяется генератор рандомных чисел чтоб выявить игрок/разбойник нанесет удар или промахнется
            if (playerRandomNumber >= 1 && playerRandomNumber <= 35) {
                cout << playerRandomNumber << "\n";
                cout << "Прямое попадание в глаз! Теперь вашему противнику будет сложнее попасть по вам с одним глазом.\n";
                rouge_hp -= 7;

                if (rougeRandomNumber <= 45) {
                    cout << "Кажется вам не хватает скорости, разбойник попадает вам в ухо. Не самое приятное ощущение.\n";
                    ur_hp -= rouge_ran_dam;
                }
                else {
                    cout << "Ловким движением вы уворачиваетесь от удара разбойника. Так держать!\n";
                }
            }
            else {
                cout << "Вы промахнулись.\n";
                if (rougeRandomNumber <= 45) {
                    cout << "Кажется вам не хватает скорости, разбойник попадает вам в ухо. Не самое приятное ощущение.\n";
                    ur_hp -= rouge_ran_dam;
                }
                else {
                    cout << "Ловким движением вы уворачиваетесь от удара разбойника. Так держать!\n";
                }
            }
        }
        else {
            cout << "Неверный выбор.\n";
        }

        if (ur_hp <= 0) {
            cout << "Вы проиграли! На этом ваше путешествие окончено.\n";
            break;
        }
        else if (rouge_hp <= 0) {
            cout << "Вы победили разбойника! После таких сложностей вы решаетесь вернутсья домой к мамочке, ведь там тепло и приятно. Ну эти приключения коту под хвост.\n";
            break;
        }
    }
}

int random_num() { // Генератор случайных чисел от 1 до 100 для выявления удара/промаха
    return rand() % 100 + 1;
}

int rouge_damage() { // Генератор рандомного урона разбойника (У игрока фиксированый урон)
    return rand() % 7 + 1;
}

void displayProgress(int playerProgress, int computerProgress) { // Вывод прогресса мини игры на экран (Код ниже)
    system("cls");

    cout << "Соревнование! Нажимайте на 'A' как можно быстрее!\n";

    cout << "Игрок:    |";
    for (int i = 0; i < playerProgress; ++i) {
        cout << "|";
    }
    cout << "\n";

    cout << "Компьютер:|";
    for (int i = 0; i < computerProgress; ++i) {
        cout << "|";
    }
    cout << "\n";
}

void competition() { // Мини игра в которой нужно на скорость нажимать на клавишу А для того чтоб победить
    
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

        if (_kbhit()) { // Выявляет нажатие клавиши А и ловит ее, после этого добавляется в шкалу прогресса игрока символ "|"
            char key = _getch();
            if (key == 'a' || key == 'A') {
                playerProgress++;
            }
        }

        auto currentTime = chrono::steady_clock::now();
        chrono::milliseconds computerInterval(distr(gen));

        if (currentTime - lastComputerTime >= computerInterval) { // Добавление прогресса для компьютера 
            computerProgress++;
            lastComputerTime = currentTime;
        }

        this_thread::sleep_for(chrono::milliseconds(100)); // Значение скорости нажатия клавиши А у компьютера
    }

    displayProgress(playerProgress, computerProgress);
    this_thread::sleep_for(chrono::seconds(3));

    if (playerProgress >= MAX_PROGRESS) { // Выводим текст при победе/поражении

        cout << "Вы победили! Грабитель испугался и убежал, оставив вам награбленное.\n";
    }
    else {
        cout << "Вас ограбили! Грабитель смог вырваться и убежал.\n";
    }
}
