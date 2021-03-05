#include <iostream>
using namespace std;

class Car {
public:
    string name = "";
    int speed = 0;
    int maxSpeed = 0;
    int accel = 0;
    int x = 0;
    bool cta = false;
    bool win = false;

    Car() {
        x = 0;
        accel = 1 + rand() % 10;
        speed = 0;
        maxSpeed = 250 + rand() % 151;
        string colors[6] = {
                "Красный", "Жёлтый", "Зелёный", "Оранжевый", "Синий", "текущая"
        };
        string names[4] = {
                "Феррари", "Ламборгини", "БМВ", "Лада"
        };

        name = colors[rand() % 6] + " " + names[rand() % 4];
    }

    void print() {
        cout << ": " << "Имя: " << name << ", Максимальная скорость: " << maxSpeed  << ", Ускорение: " << accel << endl;
    }

    void Move() {
        speed += accel;
        if (speed > maxSpeed)
        {
            speed = maxSpeed;
        }
        x += speed;
    }
};

int main() {
    srand(time(0));
    //setlocale(LC_ALL, "rus");
    Car cars[10];
    for (int i = 0; i < 10; ++i) {
        cout << i + 1;
        cars[i].print();
    }
    int ct = 0;
    int l = 901 + (rand() % 99); // задать длину трассы
    cout << "Длинна трассы = " << l << endl;
    cout << "Делайте ставки!" << endl;  // Сделать возможность сделать ставку на победителя
    do
    {
        cout << "Введите число от 1 до 10: ";
        cin >> ct;
    } while (!(ct > 0 && ct < 11));
    cars[ct - 1].cta = true;
    bool f;
    do
    {
        f = true;
        for (int i = 0; i < 10; ++i)
        {
            cars[i].Move();
            if (cars[i].x >= l && cars[i].win == false)
            {
                bool k = true;
                for (int j = 0; j < 10; ++j) {
                    if (cars[j].win == true)
                    {
                        k = false;
                    }
                }
                cout << "машина с номером " << i + 1 << " под названием " << cars[i].name << " преодолела финишную черту." << endl;
                cars[i].win = true;
                if (k and cars[i].cta == true)
                {
                    cout << "ПОЗДРАВЛЯЮ!!!" << endl;
                }
            }
            if (cars[i].win == false)
                {
                    f = false;
                }
        }
    } while (!f);

    // симулировать гонку с увеличением скорости и координаты
    // вывести порядок, в котором машины приедут
    system("pause");

    return 0;
}
