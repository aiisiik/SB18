#include <iostream>
#include <string.h>
#include "SB18.h"

class Player {
public:
    Player() : name("Player"), points(0) {}
    Player(std::string _name, int _points = 0) : name(_name), points(_points) {}
    std::string GetName() { return name; }
    bool SetName(std::string NewName) {
        if (NewName != "") {
            name = NewName;
            return true;
        }
        return false;
    }
    int GetPoints() { return points; }
    void SetPoints(int NewPoints) { points = NewPoints; }
    void AddPoints(int NewPoints) { points += NewPoints; }
    void Print() { std::cout << name << "\t" << points << std::endl; }
private:
    std::string name;
    int points;

};

int main()
{
    //init
    int PlayersCount;
    std::cout << "Players count: ";
    std::cin >> PlayersCount;
    Player* p = new Player[PlayersCount];

    //input
    std::string NameIn;
    int PointIn;
    for (int i = 0; i < PlayersCount; i++) {
        std::cout << "Player #" << i << " name: ";
        std::cin >> NameIn;
        p[i].SetName(NameIn);
        std::cout << "Player #" << i << " points: ";
        std::cin >> PointIn;
        p[i].SetPoints(PointIn);
    }

    //sort
    Player pt; //temporary
    for (int i = 0; i < PlayersCount; i++) {
        for (int j = i + 1;j < PlayersCount; j++) {
            if (p[i].GetPoints() < p[j].GetPoints()) {
                pt = p[i];
                p[i] = p[j];
                p[j] = pt;
            }
        }
    }

    //print
    std::cout << "Players list:" << std::endl;
    for (int i = 0; i < PlayersCount; i++) {
        p[i].Print();
    }

    //cleanup
    delete[] p;
    p = nullptr;
}
