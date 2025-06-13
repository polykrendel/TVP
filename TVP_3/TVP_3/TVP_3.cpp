#include <iostream>
#include <queue>
#include <list>
using namespace std;

class passenger {
public:
    string surname,dest,date;
};

class ticket {
public:
    int flight_num,remain;
    string dest,date;
};

bool findTicket(string& dest, string& date, ticket& tik) {
    return tik.dest == dest && date == tik.date && tik.remain!=0;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    queue<passenger> passengers;
    list<ticket> tickets;

    cout << "Введите количество пассажиров: ";
    int pas_num;
    cin >> pas_num;
    cout << '\n' << "Введите фамилию, пункт назначения и дату для каждого пассажира." << '\n';
    for (int i = 0; i < pas_num; i++) {
        passenger pas;
        cin >> pas.surname >> pas.dest >> pas.date;
        passengers.push(pas);
    }

    cout << '\n' << "Введите количество рейсов: ";
    int flight_kol;
    cin >> flight_kol;
    cout << '\n' << "Введите номер рейса, пункт назначения, дату и количество билетов для каждого рейса." << '\n';
    for (int i = 0; i < flight_kol; i++) {
        ticket tik;
        cin >> tik.flight_num >> tik.dest >> tik.date >> tik.remain;
        tickets.push_back(tik);
    }

    queue<passenger> passengers_2;
    cout << '\n';
    while(!passengers.empty()) {
        passenger curPas = passengers.front();
        bool ticketFound = false;
        for (ticket &tik : tickets) {
            if (findTicket(curPas.dest, curPas.date, tik)) {
                ticketFound = true;
                tik.remain--;
                cout << "Пассажир " << curPas.surname << " получил билет на рейс " << tik.flight_num << '\n';
                break;
            }
        }
        if (ticketFound == true) {
            passengers.pop();
        }
        else {
            cout << "Пассажир " << curPas.surname << " не получил билет на рейс:("<<'\n';
            passengers.pop();
            passengers_2.push(curPas);
        }
    }

    passengers.swap(passengers_2);
}