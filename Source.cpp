#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<vector>

using namespace std;

class Character {
public:
    int health;
    int lvl;
    string name;

    Character(const string& n, int h) : name(n), health(h) {
        srand(time(nullptr));
        lvl = rand() % 10 + 1;
    }

    void display() const {
        cout << "Name: " << name << ", Health: " << health << ", Level: " << lvl << endl;
    }
};

void attack(Character& attacker, Character& target) 
{
    int damage = rand() % attacker.lvl + 1; 
    target.health -= damage;
    cout << attacker.name << " attacks " << target.name << " with " << damage << " damage." << endl;
}

void heal(Character& player) {
    int healing = rand() % 20 + 10; 
    player.health += healing;
    cout << player.name << " heals for " << healing << " health." << endl;
}

void battle(Character& player, Character& enemy) {
    cout << "Battle begins!" << endl;
    while (player.health > 0 && enemy.health > 0) {
        cout << "Player's Turn: (1) Attack, (2) Heal, (3) Escape: ";
        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            attack(player, enemy);
            break;
        case 2:
            heal(player);
            break;
        case 3:
            cout << "Player flees from battle!" << endl;
            return;
        default:
            cout << "Invalid choice. Player skips turn." << endl;
        }

        if (enemy.health <= 0) {
            cout << "Enemy defeated!" << endl;
            return;
        }

       
        attack(enemy, player);
        if (player.health <= 0) {
            cout << "Player defeated!" << endl;
            return;
        }
    }
}

int main() {
    Character player("Strelok", 20);
    Character enemy("Mutant", 25);

    player.display();
    enemy.display();

    battle(player, enemy);

    return 0;
}






















//#include<iostream>
//#include <fstream>
//#include<string>
//#include<cstdlib>
//#include<ctime>
//#include<vector>
//
//using namespace std;
//
//class Character {
//	 string name;
//	int health;
//	int lvl;
//	string inventory;
//public:
//	Character(string n, int h) : name(n), health(h)
//	{
//		srand(time(NULL));
//		lvl = rand() % 10 + 1;
//
//		string items[] = { "sword", "katana", "potion_hp", "potion_mana", "shield" };
//		int numIt = sizeof(items) / sizeof(items[0]);
//
//		inventory = "";
//
//		for (int i = 0; i < 3; i++) {
//			int randIndex = rand() % numIt;
//
//			inventory += items[randIndex] + ", ";
//		}
//
//		inventory = inventory.substr(0, inventory.length() - 2);
//
//
//	}
//
//	friend ostream& operator<<(ostream& os, const Character& c)
//	{
//		os << "Name: " << c.name << "< Health:  " << c.health<< ", Level: " << c.lvl << ", Inventory : " << c.inventory;
//		return os;
//	}
//
//	friend bool operator == (const Character& c1, const Character& c2)
//	{
//		return c1.name == c2.name && c1.health == c2.health && c1.lvl == c2.lvl &&
//			c1.inventory == c2.inventory;
//	}
//
//	void saveToFile(const string& filename) const {
//		ofstream file(filename);
//		if (file.is_open())
//		{
//			file << name << "\n";
//			file << health << "\n";
//			file << lvl << "\n";
//			file << inventory << "\n";
//			file.close();
//		}
//		else
//		{
//			cerr << "Can`t open file :(" << endl;
//		}
//	}
//
//	void loadFromFile(const string& filename)  {
//		ifstream file(filename);
//		if (file.is_open())
//		{
//			getline(file, name);
//			file >> health;
//			file >> lvl;
//			getline(file >> ws, inventory);
//			file.close();
//			
//		}
//		else
//		{
//			cerr << "Can`t open " << endl;
//		}
//	}
//
//};
//
//class Location
//{
//	string name;
//	string description;
//	bool hasQuest;
//	bool hasEnemies;
//
//public:
//	//конструктор з параметрами
//
//	vector<Location> locs = {
//		//Location("Forest", "Mystery place", true, true),
//		//Location("Castle", "Creepy castle", false, true)
//	};
//
//};
//
//class Map
//{
//	vector<Location> locs;
//
//public:
//	void addLocation(const Location& location)
//	{
//		locs.push_back(location);
//	}
//	void displayMap() const
//	{
//		//Виведення локацій
//	}
//};
//
//
//void main()
//{
//	srand(time(nullptr));
//
//	Map gameMap;
//
//	vector<Location> location;
//
//	for (const Location& loc : location)
//	{
//		gameMap.addLocation(loc);
//	}
//
//	gameMap.displayMap();
//
//	Character p1("Strelok", 50);
//	Character p2("Sydorovich", 40);
//
//	cout << "Strelok 1:" << p1 << endl;
//	cout << "Sydorovich 2:" << p2 << endl;
//
//	p1.saveToFile("player1.txt");
//
//	Character loadCharacter("Nome", 0);
//
//	loadCharacter.loadFromFile("player.txt");
//
//	cout << "Loaded player: " << loadCharacter << endl;
//
//}