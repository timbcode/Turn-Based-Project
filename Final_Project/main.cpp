#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Struct used to hold all the characters' attribute values. Two struct objects created, one for each duelist. 
struct
{
    string name;
    string type;
    int health;
    int offense;
    int defense;
    int resource;
    int exp;
} myCharacter, yourCharacter;


//BASE CLASS - Character. Includes functions to set basic values to character objects as well as to perform some basic actions and print updated character attributes (both in combat, and after). 
class Character
{

    void setName(string n)
    {
        myCharacter.name = n;
    }

    void setType(string cT)
    {
        myCharacter.type = cT;
    }
public:
    void setBase()
    {
        myCharacter.health = 1000;
        yourCharacter.health = 1000;
    }

    void rest1()
    {
        myCharacter.resource += 50;
    }

    void rest2()
    {
        yourCharacter.resource += 50;
    }

    void charge()
    {
        myCharacter.offense += myCharacter.offense;
    }

    void block()
    {
        myCharacter.defense += myCharacter.defense;
    }

public:
    void updateValuesInCombat(string nam, int healt, int resourc, string nam2, int healt2, int resourc2)
    {
        if (myCharacter.type == "M")
            cout << nam << " has " << healt << " health and " << resourc << " mana after this round" << endl;
        else
            cout << nam << " has " << healt << " health and " << resourc << " stamina after this round" << endl;
        if (yourCharacter.type == "M")
            cout << nam2 << " has " << healt2 << " health and " << resourc2 << " mana after this round" << endl;
        else
            cout << nam2 << " has" << healt2 << " health and " << resourc2 << " stamina after this round" << endl;

        cout << endl << endl;
    }

    void updateValues(string na, string typ, int hea, string na2, string typ2, int hea2)
    {
        string tip;
        string tip2;

        if (typ == "M")
            tip = "Mage";
        else if (typ == "F")
            tip = "Fighter";
        else if (typ == "T")
            tip = "Tank";
        if (typ2 == "M")
            tip2 = "Mage";
        else if (typ2 == "F")
            tip2 = "Fighter";
        else if (typ2 == "T")
            tip2 = "Tank";

        cout << "At the end of the battle, " << na << " the " << tip << " was left with " << hea << " health and" << na2 << " the " << tip2 << " was left with " << hea2 << " health" << endl;
    }

    void loadFile(int player, string filename)
    {
        string line;
        string delimiter = ",";
        size_t pos = 0;
        string token;
        int count = 0;
        int count2 = player;
        int placeholder;
        ifstream myfile(filename);
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                    token = line.substr(0, pos);
                    if (count == 0 && count2 == 0)
                        myCharacter.name = token;
                    else if (count == 1 && count2 == 0)
                        myCharacter.type = token;
                    else if (count == 0 && count2 == 1)
                        yourCharacter.name = token;
                    else if (count == 1 && count2 == 1)
                        yourCharacter.type = token;
                    line.erase(0, pos + delimiter.length());
                    count++; 
                }
                if (count == 2 && count2 == 0)
                {
                    token = line.substr(0, pos);
                    myCharacter.exp = stoi(token);
                }
                else if (count == 2 && count2 == 1)
                {
                    token = line.substr(0, pos);
                    yourCharacter.exp = stoi(token);
                }
                count = 0;
            }
        }
        else
            cout << "Unable to load file." << endl;

        myfile.close();
    }

    void saveToFile(int play, string fn)
    {
        int g = play;
        ofstream o(fn);
        if (o.is_open())
        {
            if (play == 0)
            {
                o << myCharacter.name << "," << myCharacter.type << "," << myCharacter.exp << endl;
            }
            else
            {
                o << yourCharacter.name << "," << yourCharacter.type << "," << yourCharacter.exp << endl;
            }
        }
        else
            cout << "Unable to load file." << endl;
    }
};

//DERIVED CLASS #1 - Mage. Mage is a Character. Includes functions to set a character objects attributes to that of a basic mage, as well as functions to print mage specific abilities. 
class Mage : public Character
{
public:

    void setStats1()
    {
        Character::setBase();
        myCharacter.offense = 200;
        myCharacter.defense = 10;
        myCharacter.resource = 200;
    }

    void setStats2()
    {
        yourCharacter.offense = 200;
        yourCharacter.defense = 10;
        yourCharacter.resource = 200;
    }

    void printAbilities1()
    {
        if (myCharacter.exp < 1000)
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
        else if (myCharacter.exp >= 1000 && myCharacter.exp < 2000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
        }
        else if (myCharacter.exp >= 2000 && myCharacter.exp < 3000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
            cout << "[3] - Flaming Punch (225 damage, 25 mana)" << endl;
        }
        else if (myCharacter.exp >= 3000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
            cout << "[3] - Flaming Punch (225 damage, 25 mana)" << endl;
            cout << "[4] - Meteor Shower (500 damage, 125 mana)" << endl;
        }

    }

    void printAbilities2()
    {
        if (yourCharacter.exp < 1000)
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
        else if (yourCharacter.exp >= 1000 && yourCharacter.exp < 2000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
        }
        else if (yourCharacter.exp >= 2000 && yourCharacter.exp < 3000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
            cout << "[3] - Flaming Punch (225 damage, 25 mana)" << endl;
        }
        else if (yourCharacter.exp >= 3000)
        {
            cout << "[1] - Fireball (200 damage, 50 mana)" << endl;
            cout << "[2] - Fireblast (300 damage, 75 mana)" << endl;
            cout << "[3] - Flaming Punch (225 damage, 25 mana)" << endl;
            cout << "[4] - Meteor Shower (500 damage, 125 mana)" << endl;
        }
    }

    void printDefenseOptions()
    {
        cout << "Available Defense/Healing options : " << endl;
        cout << "[1] - Block (increase defense for this turn for 50 mana)" << endl;
        cout << "[2] - Heal (recover 200 missing health)" << endl;
        cout << "[3] - Rest (recover 75 mana)" << endl;
    }
};

//DERIVED CLASS #2  - Fight. Fighter is a Character. Includes functions to set a character objects attributes to that of a basic fighter, as well as functions to print fighter specific abilities. 
class Fighter : public Character
{
public:
    void setStats1()
    {
        Character::setBase();
        myCharacter.offense = 100;
        myCharacter.defense = 50;
        myCharacter.resource = 100;
    }

    void setStats2()
    {
        yourCharacter.offense = 100;
        yourCharacter.defense = 50;
        yourCharacter.resource = 100;
    }

    void printAbilities1()
    {
        if (myCharacter.exp < 1000)
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
        else if (myCharacter.exp >= 1000 && myCharacter.exp < 2000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
        }
        else if (myCharacter.exp >= 2000 && myCharacter.exp < 3000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
            cout << "[3] - Shank (200 damage, 25 stamina)" << endl;
        }
        else if (myCharacter.exp >= 3000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
            cout << "[3] - Sacred Sword (200 damage, 25 stamina)" << endl;
            cout << "[4] - Blade Dance (350 damage, 55 stamina)" << endl;
        }
    }

    void printAbilities2()
    {
        if (yourCharacter.exp < 1000)
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
        else if (yourCharacter.exp >= 1000 && yourCharacter.exp < 2000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
        }
        else if (yourCharacter.exp >= 2000 && yourCharacter.exp < 3000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
            cout << "[3] - Shank (200 damage, 25 stamina)" << endl;
        }
        else if (yourCharacter.exp >= 3000)
        {
            cout << "[1] - Uppercut (125 damage, 20 stamina)" << endl;
            cout << "[2] - Orbital Kick (150 damage, 30 stamina)" << endl;
            cout << "[3] - Sacred Sword (200 damage, 25 stamina)" << endl;
            cout << "[4] - Blade Dance (350 damage, 55 stamina)" << endl;
        }
    }

    void printDefenseOptions()
    {
        cout << "Available Defense/Healing options : " << endl;
        cout << "[1] - Block (increase defense for this turn for 50 stamina)" << endl;
        cout << "[2] - Heal (recover 200 missing health)" << endl;
        cout << "[3] - Rest (recover 75 stamina)" << endl;
    }
};

//DERIVED CLASS 3 - Tank. Tank is a Character. Includes functions to set a character objects attributes to that of a basic tank, as well as functions to print tank specific abilities. 
class Tank : public Character
{
public:
    void setStats1()
    {
        myCharacter.health = 1500;
        myCharacter.offense = 50;
        myCharacter.defense = 100;
        myCharacter.resource = 500;
    }

    void setStats2()
    {
        yourCharacter.health = 1500;
        yourCharacter.offense = 50;
        yourCharacter.defense = 100;
        yourCharacter.resource = 500;
    }

    void printAbilities1()
    {
        if (myCharacter.exp < 1000)
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
        else if (myCharacter.exp >= 1000 && myCharacter.exp < 2000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
        }
        else if (myCharacter.exp >= 2000 && myCharacter.exp < 3000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
            cout << "[3] - Counter Helix (Deal the same damage you take for 1 turn, 100 stamina)" << endl;
        }
        else if (myCharacter.exp >= 3000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
            cout << "[3] - Counter Helix (Deal the same damage you take for 1 turn, 100 stamina)" << endl;
            cout << "[4] - Borrowed Time (Heal for the damage you would have taken, 0 stamina, Can only be used once per 5 turns)" << endl;
        }
    }

    void printAbilities2()
    {
        if (yourCharacter.exp < 1000)
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
        else if (yourCharacter.exp >= 1000 && yourCharacter.exp < 2000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
        }
        else if (yourCharacter.exp >= 2000 && yourCharacter.exp < 3000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
            cout << "[3] - Counter Helix (Deal the same damage you take for 1 turn, 100 stamina)" << endl;
        }
        else if (yourCharacter.exp >= 3000)
        {
            cout << "[1] - Bulwark (75 damage, 50 stamina, also reduce incoming damage by 25)" << endl;
            cout << "[2] - Crimson Gaurd (100 damage, 75 stamina)" << endl;
            cout << "[3] - Counter Helix (Deal the same damage you take for 1 turn, 100 stamina)" << endl;
            cout << "[4] - Borrowed Time (Heal for the damage you would have taken, 0 stamina, Can only be used once per 5 turns)" << endl;
        }
    }

    void printDefenseOptions()
    {
        cout << "Available Defense/Healing options : " << endl;
        cout << "[1] - Block (increase defense for this turn for 50 stamina)" << endl;
        cout << "[2] - Heal (recover 200 missing health)" << endl;
        cout << "[3] - Rest (recover 75 stamina)" << endl;
    }
};


int main()
{
    string n;
    string q;
    Character c;
    Mage m;
    Fighter f;
    Tank t;
    int x = 1;

    //Prompts user to choose what they would like to do (before a fight begins).
    cout << "Welcome to the game player 1! Please choose an option: " << endl << endl;
    cout << "[L] - Load character" << endl << "[C] - Create character" << endl << "[X] - Exit game" << endl << endl;
    cin >> n;

    while (n != "L" && n != "C" && n != "X" && n != "l" && n != "c" && n != "x")
    {
        cout << "Please choose a valid option: " << endl;
        cout << "[L] - Load character" << endl << "[C] - Create character" << endl << "[X] - Exit game" << endl << endl;
        cin >> n;
    } 
    if ((n == "L" || n == "C" || n == "X" || n == "l" || n == "c" || n == "x"))
    {
        if (n == "L" || n == "l") //Loads a character from a file upon recieving the filename from user input. Assigns values from the file to the character object. 
        {
            string filen;
            cout << endl << "Please enter the filename :" << endl;
            cin >> filen;
            m.Character::loadFile(0,filen); 
            if (myCharacter.type == "M" || myCharacter.type == "m")
                m.setStats1();
            if (myCharacter.type == "F" || myCharacter.type == "f")
                f.setStats1();
            if (myCharacter.type == "T" || myCharacter.type == "t")
                t.setStats1();
            if(myCharacter.type == "M" || myCharacter.type == "m")
                cout << endl << myCharacter.name << " the Mage is ready to duel!" << endl;
            else if(myCharacter.type == "F" || myCharacter.type == "f")
                cout << endl << myCharacter.name << " the Fighter is ready to duel!" << endl;
            else if (myCharacter.type == "T" || myCharacter.type == "t")
                cout << endl << myCharacter.name << " the Tank is ready to duel!" << endl;

            cout << "---------------------------------------------------------------" << endl << endl;
            cout << endl;
        }
        if (n == "C" || n == "c") //Prompts user input for several questions pertaining to the creation of a new character, and assigns the values given to the character object.
        {
            string name;
            string characterType;
            string characterType2;

            cout << endl;
            cout << "Pick a name for your character!" << endl;
            cin >> name;
            myCharacter.name = name;
            cout << endl;
            cout << "Pick a class type: [M] - Mage  [F] - Fighter  [T] - Tank " << endl;
            cout << endl;
            cin >> characterType;
            while (characterType != "M" && characterType != "F" && characterType != "T" && characterType != "m" && characterType != "f" && characterType != "t")
            {
                cout << "Please choose a valid option: " << endl;
                cout << "Pick a class type: [M] - Mage  [F] - Fighter  [T] - Tank " << endl;
                cin >> characterType;
            }
            if(characterType == "M" || characterType == "m" || characterType == "F" || characterType == "f" || characterType == "T" || characterType == "t")
            {
                myCharacter.type = characterType;
                if (characterType == "M" || characterType == "m")
                {
                    characterType2 = "Mage";
                    m.setStats1();
                    myCharacter.exp = 0;
                }
                if (characterType == "F" || characterType == "f")
                {
                    characterType2 = "Fighter";
                    f.setStats1();
                    myCharacter.exp = 0;
                }
                if (characterType == "T" || characterType == "t")
                {
                    characterType2 = "Tank";
                    t.setStats1();
                    myCharacter.exp = 0;
                }
            }
            cout << endl << myCharacter.name << " the " << characterType2 << " is ready to duel!" << endl;
            cout << endl;
            cout << "---------------------------------------------------------------" << endl << endl;
        }
        if (n == "X" || n == "x") //Exits the program.
            exit(0);

        //Provides the same options given to the first player, to the second as well. 
        cout << "Welcome to the game player 2! Please choose an option as well: " << endl << endl;
        cout << "[L] - Load character" << endl << "[C] - Create character" << endl << "[X] - Exit game" << endl << endl;
        cin >> n;
        while (n != "L" && n != "C" && n != "X" && n != "l" && n != "c" && n != "x")
        {
            cout << "Please choose a valid option: " << endl;
            cout << "[L] - Load character" << endl << "[C] - Create character" << endl << "[X] - Exit game" << endl << endl;
            cin >> n;
        }
        if (n == "L" || n == "l" || n == "C" || n == "c" || n == "X" || n == "x")
        {
            if (n == "L" || n == "l")
            {
                string filen;
                cout << endl << "Please enter the filename :" << endl;
                cin >> filen;
                m.Character::loadFile(1, filen);
                if (yourCharacter.type == "M" || yourCharacter.type == "m")
                    m.setStats2();
                if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    f.setStats2();
                if (yourCharacter.type == "T" || yourCharacter.type == "t")
                    t.setStats2();
                if (yourCharacter.type == "M" || yourCharacter.type == "m")
                    cout << endl << yourCharacter.name << " the Mage is ready to duel!" << endl;
                else if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    cout << endl << yourCharacter.name << " the Fighter is ready to duel!" << endl;
                else if (yourCharacter.type == "T" || yourCharacter.type == "t")
                    cout << endl << yourCharacter.name << " the Tank is ready to duel!" << endl;
                cout << endl;

                cout << "---------------------------------------------------------------" << endl << endl;
            }
            if (n == "C" || n == "c")
            {
                string name2;
                string characterType3;
                string characterType4;

                cout << endl;
                cout << "Pick a name for your character!" << endl;
                cin >> name2;
                yourCharacter.name = name2;
                cout << endl;
                cout << "Pick a class type: [M] - Mage  [F] - Fighter  [T] - Tank " << endl;
                cout << endl;
                cin >> characterType3;
                while (characterType3 != "M" && characterType3 != "F" && characterType3 != "T" && characterType3 != "m" && characterType3 != "f" && characterType3 != "t")
                {
                    cout << "Please choose a valid option: " << endl;
                    cout << "Pick a class type: [M] - Mage  [F] - Fighter  [T] - Tank " << endl;
                    cout << endl;
                    cin >> characterType3;
                }
                if(characterType3 == "M" || characterType3 == "F" || characterType3 == "T" || characterType3 == "m" || characterType3 == "f" || characterType3 == "t")
                {
                    yourCharacter.type = characterType3;
                    if (characterType3 == "M" || characterType3 == "m")
                    {
                        characterType4 = "Mage";
                        m.setStats2();
                    }
                    if (characterType3 == "F" || characterType3 == "f")
                    {
                        characterType4 = "Fighter";
                        f.setStats2();
                    }
                    if (characterType3 == "T" || characterType3 == "t")
                    {
                        characterType4 = "Tank";
                        t.setStats2();
                    }
                }
                cout << endl << yourCharacter.name << " the " << characterType4 << " is ready to duel!" << endl;
                cout << endl;
                cout << "---------------------------------------------------------------" << endl;
            }
            if (n == "X" || n == "x")
                exit(0);
        }

    }
    //---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    //Fight begins: 

    string duelOption1;
    string duelOption2;
    string abilityOption1;
    string abilityOption2;
    string defenseOption1;
    string defenseOption2;
    cout << endl << "The duel has begun...";
    do
    {
        //Player 1 is given the first turn and is given choices for their first move. 
        cout << " What would " << myCharacter.name << " like to do?" << endl << endl;
        cout << "[A] - Attack  [D] - Defend  [F] - Flee  [S] - Save files  [L] - Load files  [X] - Exit the game" << endl;
        cout << endl;
        cin >> duelOption1;
        while (duelOption1 != "A" && duelOption1 != "D" && duelOption1 != "F" && duelOption1 != "S" && duelOption1 != "L" && duelOption1 != "X" && duelOption1 != "a" && duelOption1 != "d" && duelOption1 != "f" && duelOption1 != "s" && duelOption1 != "l" && duelOption1 != "x")
        {
            cout << "Please choose a valid option: " << endl;
            cout << "[A] - Attack  [D] - Defend  [F] - Flee  [S] - Save files  [L] - Load files  [X] - Exit the game" << endl;
            cout << endl;
            cin >> duelOption1;
        }
        while (duelOption1 == "L" || duelOption1 == "l")
        {
            cout << "Unable to load character in the middle of a duel. Please choose another option: " << endl;
            cin >> duelOption1;
        }
        if(duelOption1 == "A" || duelOption1 == "D" || duelOption1 == "F" || duelOption1 == "S" || duelOption1 == "L" || duelOption1 == "X" || duelOption1 == "a" || duelOption1 == "d" || duelOption1 == "f" || duelOption1 == "s" || duelOption1 == "l" || duelOption1 == "x")
        {
            if (duelOption1 == "A" || duelOption1 == "a") //If player 1 chooses to attack, and has enough resource to perform the lowest cost attack for their character type, they are provided with available abilities to choose from (based on their characters experience). 
            {
                cout << endl << myCharacter.name << " has chosen to attack! " << endl;
                if (myCharacter.type == "M" || myCharacter.type == "m")
                {
                    if (myCharacter.resource < 25)
                    {
                        cout << "Not enough mana to use an ability - forced to rest" << endl;
                        m.Character::rest1();
                        abilityOption1 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl;
                        m.printAbilities1();
                        cout << endl;
                        cin >> abilityOption1;
                    }
                }
                else if (myCharacter.type == "F" || myCharacter.type == "f")
                {
                    if (myCharacter.resource < 20)
                    {
                        cout << "Not enough stamina to use an ability - forced to rest" << endl;
                        f.Character::rest1();
                        abilityOption1 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl;
                        f.printAbilities1();
                        cout << endl;
                        cin >> abilityOption1;
                    }
                }
                else if (myCharacter.type == "T" || myCharacter.type == "t")
                {
                    if (myCharacter.resource < 50)
                    {
                        cout << "Not enough stamina to use an ability - forced to rest" << endl;
                        t.Character::rest1();
                        abilityOption1 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl;
                        t.printAbilities1();
                        cout << endl;
                        cin >> abilityOption1;
                    }
                }
                while (abilityOption1 != "0" && abilityOption1 != "1" && abilityOption1 != "2" && abilityOption1 != "3" && abilityOption1 != "4")
                {
                    cout << "Please pick a valid option: " << endl;
                    cin >> abilityOption1;
                }
                if (abilityOption1 == "0")
                {
                    myCharacter.offense = 0;
                }
                else if (abilityOption1 == "1")
                {
                    if (myCharacter.type == "M" || myCharacter.type == "m")
                    {
                        cout << endl << myCharacter.name << " selected Fireball" << endl;
                        myCharacter.resource -= 50;
                        myCharacter.offense = 200;
                    }
                    if (myCharacter.type == "F" || myCharacter.type == "f")
                    {
                        cout << endl << myCharacter.name << " selected Uppercut" << endl;
                        myCharacter.resource -= 20;
                        myCharacter.offense = 125;
                    }
                    if (myCharacter.type == "T" || myCharacter.type == "t")
                    {
                        cout << endl << myCharacter.name << " selected Bulwark" << endl;
                        myCharacter.resource -= 50;
                        myCharacter.defense += 25;
                        myCharacter.offense = 75;
                    }
                }
                else if (abilityOption1 == "2")
                {
                    if (myCharacter.exp < 1000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption1;
                    }
                    else
                    {
                        if (myCharacter.type == "M" || myCharacter.type == "m")
                        {
                            cout << endl << myCharacter.name << " selected Fireblast" << endl;
                            myCharacter.resource -= 75;
                            myCharacter.offense = 300;
                        }
                        if (myCharacter.type == "F" || myCharacter.type == "f")
                        {
                            cout << endl << myCharacter.name << " selected Orbital kick" << endl;
                            myCharacter.resource -= 30;
                            myCharacter.offense = 150;
                        }
                        if (myCharacter.type == "T" || myCharacter.type == "t")
                        {
                            cout << endl << myCharacter.name << " selected Crimson Gaurd" << endl;
                            myCharacter.resource -= 75;
                            myCharacter.offense = 100;
                        }
                    }
                }
                else if (abilityOption1 == "3")
                {
                    if (myCharacter.exp < 2000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption1;
                    }
                    else
                    {
                        if (myCharacter.type == "M" || myCharacter.type == "m")
                        {
                            cout << endl << myCharacter.name << " selected Flaming Punch" << endl;
                            myCharacter.resource -= 25;
                            myCharacter.offense = 225;
                        }
                        if (myCharacter.type == "F" || myCharacter.type == "f")
                        {
                            cout << endl << myCharacter.name << " selected Sacred Sword" << endl;
                            myCharacter.resource -= 25;
                            myCharacter.offense = 200;
                        }
                        if (myCharacter.type == "T" || myCharacter.type == "t")
                        {
                            cout << endl << myCharacter.name << " Counter Helix" << endl;
                            myCharacter.resource -= 100;
                        }
                    }
                }
                else if (abilityOption1 == "4")
                {
                    if (myCharacter.exp < 3000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption1;
                    }
                    else
                    {
                        if (myCharacter.type == "M" || myCharacter.type == "m")
                        {
                            cout << endl << myCharacter.name << " selected Meteor Shower!!" << endl;
                            myCharacter.resource -= 125;
                            myCharacter.offense = 500;
                        }
                        if (myCharacter.type == "F" || myCharacter.type == "f")
                        {
                            cout << endl << myCharacter.name << " selected Blade Dance!!" << endl;
                            myCharacter.resource -= 55;
                            myCharacter.offense = 350;
                        }
                        if (myCharacter.type == "T" || myCharacter.type == "t")
                        {
                            cout << endl << myCharacter.name << " selected Borrowed Time!!" << endl;

                        }
                    }
                }


            }
            if (duelOption1 == "D" || duelOption1 == "d") //If the player chooses to defend on this turn, they are provided with 3 defense options to choose from. 
            {
                cout << endl;
                if (myCharacter.type == "M" || myCharacter.type == "m")
                    m.printDefenseOptions();
                else if (myCharacter.type == "F" || myCharacter.type == "f")
                    f.printDefenseOptions();
                else if (myCharacter.type == "T" || myCharacter.type == "t")
                    t.printDefenseOptions();
                cin >> defenseOption1;
                if (defenseOption1 == "1")
                {
                    if (myCharacter.type == "M" || myCharacter.type == "m")
                    {
                        if (myCharacter.resource < 75)
                        {
                            cout << "Not enough mana to block - forced to rest" << endl;
                            m.Character::rest1();
                        }
                        else
                        {
                            myCharacter.defense += myCharacter.defense;
                            myCharacter.resource -= 75;
                            cout << myCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                    else if (myCharacter.type == "F" || myCharacter.type == "f")
                    {
                        if (myCharacter.resource < 50)
                        {
                            cout << "Not enough stamina to block - forced to rest" << endl;
                            f.Character::rest1();
                        }
                        else
                        {
                            myCharacter.defense += myCharacter.defense;
                            myCharacter.resource -= 50;
                            cout << myCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                    else if (myCharacter.type == "T" || myCharacter.type == "t")
                    {
                        if (myCharacter.resource < 50)
                        {
                            cout << "Not enough stamina to block - forced to rest" << endl;
                            t.Character::rest1();
                        }
                        else
                        {
                            myCharacter.defense += myCharacter.defense;
                            myCharacter.resource -= 50;
                            cout << myCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                }
                else if (defenseOption1 == "2")
                {
                    if (myCharacter.health <= 800)
                    {
                        myCharacter.health += 200;
                        cout << myCharacter.name << " was given a potion and healed 200 health." << endl;
                    }
                    else
                    {
                        myCharacter.health = 1000;
                        cout << myCharacter.name << " was given a potion and healed to full!" << endl;
                    }
                }
                else if (defenseOption1 == "3")
                {
                    if (myCharacter.type == "M" || myCharacter.type == "m")
                    {
                        myCharacter.resource += 50;
                        cout << myCharacter.name << " rested and restored 50 mana" << endl;
                    }
                    if (myCharacter.type == "F" || myCharacter.type == "f")
                    {
                        myCharacter.resource += 50;
                        cout << myCharacter.name << " rested and restored 50 stamina" << endl;
                    }
                    if (myCharacter.type == "T" || myCharacter.type == "t")
                    {
                        myCharacter.resource += 100;
                        cout << myCharacter.name << " rested and restored 50 stamina" << endl;
                    }
                }


            }
            if (duelOption1 == "F" || duelOption1 == "f") //If the player chooses to flee the duel, they will forfeit and their opponent will be declared victor (and given exp for winning the duel).
            {
                cout << myCharacter.name << " has fled the duel! " << yourCharacter.name << " has won!" << endl;
                yourCharacter.exp += 500;
                break;
            }
            if (duelOption1 == "S" || duelOption1 == "s") //Saves player 1's character attributes at their current state onto a txt file (player is prompted to input filename for character to be saved onto).
            {
               string filn;
                cout << "Filename to load character to: " << endl;
                cin >> filn;
                m.saveToFile(0, filn); 
            }
            if (duelOption1 == "X" || duelOption1 == "x") //Exits the program. 
                exit(0);
        }

        //Same options provided to player 1 are provided to player 2. 
        cout << endl << "What would " << yourCharacter.name << " like to do?" << endl << endl;
        cout << "[A] - Attack  [D] - Defend  [F] - Flee  [S] - Save files  [L] - Load files  [X] - Exit the game" << endl;
        cout << endl;
        cin >> duelOption2;
        while (duelOption2 != "A" && duelOption2 != "D" && duelOption2 != "F" && duelOption2 != "S" && duelOption2 != "L" && duelOption2 != "X" && duelOption2 != "a" && duelOption2 != "d" && duelOption2 != "f" && duelOption2 != "s" && duelOption2 != "l" && duelOption2 != "x")
        {
            cout << "Please choose a valid option: " << endl;
            cin >> duelOption2;
        }
        while (duelOption2 == "L" || duelOption2 == "l")
        {
            cout << "Unable to load character in the middle of a duel. Please choose another option: " << endl;
            cin >> duelOption2;
        }
        if(duelOption2 == "A" || duelOption2 == "D" || duelOption2 == "F" || duelOption2 == "S" || duelOption2 == "L" || duelOption2 == "X" || duelOption2 == "a" || duelOption2 == "d" || duelOption2 == "f" || duelOption2 == "s" || duelOption2 == "l" || duelOption2 == "x")
        {
            if (duelOption2 == "A" || duelOption2 == "a")
            {
                cout << endl << yourCharacter.name << " has chosen to attack!" << endl;
                if (yourCharacter.type == "M" || yourCharacter.type == "m")
                {
                    if (yourCharacter.resource < 25)
                    {
                        cout << "Not enough mana to use an ability - forced to rest" << endl;
                        m.Character::rest2();
                        abilityOption2 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl << endl;
                        m.printAbilities2();
                        cout << endl;
                        cin >> abilityOption2;
                    }
                }
                else if (yourCharacter.type == "F" || yourCharacter.type == "f")
                {
                    if (yourCharacter.resource < 20)
                    {
                        cout << "Not enough stamina to use an ability - forced to rest" << endl;
                        f.Character::rest2();
                        abilityOption2 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl;
                        f.printAbilities2();
                        cout << endl;
                        cin >> abilityOption2;
                    }
                }
                else if (yourCharacter.type == "T" || yourCharacter.type == "t")
                {
                    if (yourCharacter.resource < 50)
                    {
                        cout << "Not enough stamina to use an ability - forced to rest" << endl;
                        t.Character::rest2();
                        abilityOption2 = "0";
                    }
                    else
                    {
                        cout << "Available abilities: " << endl;
                        t.printAbilities2();
                        cout << endl;
                        cin >> abilityOption2;
                    }
                }
                while (abilityOption2 != "0" && abilityOption2 != "1" && abilityOption2 != "2" && abilityOption2 != "3" && abilityOption2 != "4")
                {
                    cout << "Please choose a valid option: ";
                    cin >> abilityOption2;
                }
                if (abilityOption2 == "0")
                {
                    yourCharacter.offense = 0;
                }
                else if (abilityOption2 == "1")
                {
                    if (yourCharacter.type == "M" || yourCharacter.type == "m")
                    {
                        cout << endl << yourCharacter.name << " selected Fireball" << endl;
                        yourCharacter.resource -= 50;
                        yourCharacter.offense = 200;
                    }
                    if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    {
                        cout << endl << yourCharacter.name << " selected Uppercut" << endl;
                        yourCharacter.resource -= 20;
                        yourCharacter.offense = 125;
                    }
                    if (yourCharacter.type == "T" || yourCharacter.type == "t")
                    {
                        cout << endl << yourCharacter.name << " selected Bulwark" << endl;
                        yourCharacter.resource -= 50;
                        yourCharacter.defense += 25;
                        yourCharacter.offense = 75;
                    }
                }
                else if (abilityOption2 == "2")
                {
                    if (yourCharacter.exp < 1000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption2;
                    }
                    else 
                    {
                        if (yourCharacter.type == "M" || yourCharacter.type == "m")
                        {
                            cout << endl << yourCharacter.name << " selected Fireblast" << endl;
                            yourCharacter.resource -= 75;
                            yourCharacter.offense = 300;
                        }
                        if (yourCharacter.type == "F" || yourCharacter.type == "f")
                        {
                            cout << endl << yourCharacter.name << " selected Orbital kick" << endl;
                            yourCharacter.resource -= 30;
                            yourCharacter.offense = 150;
                        }
                        if (yourCharacter.type == "T" || yourCharacter.type == "t")
                        {
                            cout << endl << yourCharacter.name << " selected Crimson Gaurd" << endl;
                            yourCharacter.resource -= 75;
                            yourCharacter.offense = 100;
                        }
                    }
                }
                else if (abilityOption2 == "3")
                {
                    if (yourCharacter.exp < 2000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption2;
                    }
                    else
                    {
                        if (yourCharacter.type == "M" || yourCharacter.type == "m")
                        {
                            cout << endl << yourCharacter.name << " selected Flaming Punch" << endl;
                            yourCharacter.resource -= 25;
                            yourCharacter.offense = 225;
                        }
                        if (yourCharacter.type == "F" || yourCharacter.type == "f")
                        {
                            cout << endl << yourCharacter.name << " selected Sacred Sword" << endl;
                            yourCharacter.resource -= 25;
                            yourCharacter.offense = 200;
                        }
                        if (yourCharacter.type == "T" || yourCharacter.type == "t")
                        {
                            cout << endl << yourCharacter.name << " Counter Helix" << endl;
                            yourCharacter.resource -= 100;
                        }
                    }
                }
                else if (abilityOption2 == "4")
                {
                    if (yourCharacter.exp < 3000)
                    {
                        cout << "Not high enough level for this ability, please choose another: " << endl;
                        cin >> abilityOption2;
                    }
                    else
                    {
                        if (yourCharacter.type == "M" || yourCharacter.type == "m")
                        {
                            cout << endl << yourCharacter.name << " selected Meteor Shower!!" << endl;
                            yourCharacter.resource -= 125;
                            yourCharacter.offense = 500;
                        }
                        if (yourCharacter.type == "F" || yourCharacter.type == "f")
                        {
                            cout << endl << yourCharacter.name << " selected Blade Dance!!" << endl;
                            yourCharacter.resource -= 55;
                            yourCharacter.offense = 350;
                        }
                        if (yourCharacter.type == "T" || yourCharacter.type == "t")
                        {
                            cout << endl << yourCharacter.name << " selected Borrowed Time!!" << endl;

                        }
                    }
                }
            }

            if (duelOption2 == "D" || duelOption2 == "d")
            {
                cout << endl;
                if (yourCharacter.type == "M" || yourCharacter.type == "m")
                    m.printDefenseOptions();
                else if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    f.printDefenseOptions();
                else if (yourCharacter.type == "T" || yourCharacter.type == "f")
                    t.printDefenseOptions();
                cin >> defenseOption2;
                if (defenseOption2 == "1")
                {
                    if (yourCharacter.type == "M" || myCharacter.type == "m")
                    {
                        if (yourCharacter.resource < 75)
                        {
                            cout << "Not enough mana to block - forced to rest" << endl;
                            m.Character::rest2();
                        }
                        else
                        {
                            yourCharacter.defense += yourCharacter.defense;
                            yourCharacter.resource -= 75;
                            cout << yourCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                    else if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    {
                        if (yourCharacter.resource < 50)
                        {
                            cout << "Not enough stamina to block - forced to rest" << endl;
                            f.Character::rest2();
                        }
                        else
                        {
                            yourCharacter.defense += yourCharacter.defense;
                            yourCharacter.resource -= 50;
                            cout << yourCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                    else if (yourCharacter.type == "T" || yourCharacter.type == "t")
                    {
                        if (yourCharacter.resource < 50)
                        {
                            cout << "Not enough stamina to block - forced to rest" << endl;
                            t.Character::rest2();
                        }
                        else
                        {
                            yourCharacter.defense += yourCharacter.defense;
                            yourCharacter.resource -= 50;
                            cout << yourCharacter.name << " is bracing for the next attack." << endl;
                        }
                    }
                }
                else if (defenseOption2 == "2")
                {
                    if (yourCharacter.health <= 800)
                    {
                        yourCharacter.health += 200;
                        cout << yourCharacter.name << " was given a potion and healed 200 health." << endl;
                    }
                    else
                    {
                        yourCharacter.health = 1000;
                        cout << yourCharacter.name << " was given a potion and healed to full!" << endl;
                    }
                }
                else if (defenseOption2 == "3")
                {
                    if (yourCharacter.type == "M" || yourCharacter.type == "m")
                    {
                        yourCharacter.resource += 50;
                        cout << yourCharacter.name << " rested and restored 50 mana" << endl;
                    }
                    if (yourCharacter.type == "F" || yourCharacter.type == "f")
                    {
                        yourCharacter.resource += 50;
                        cout << yourCharacter.name << " rested and restored 50 stamina" << endl;
                    }
                    if (yourCharacter.type == "T" || yourCharacter.type == "t")
                    {
                        yourCharacter.resource += 100;
                        cout << yourCharacter.name << " rested and restored 50 stamina" << endl;
                    }
                }


            }
            if (duelOption2 == "F" || duelOption2 == "f")
            {
                cout << yourCharacter.name << " has fled the duel! " << myCharacter.name << " has won!" << endl;
                myCharacter.exp += 500;
                break;
            }
            if (duelOption2 == "S" || duelOption2 == "s")
            {
                string filn2;
                cout << "Filename to load character to: " << endl;
                cin >> filn2;
                m.saveToFile(1, filn2);
            }
            if (duelOption2 == "X" || duelOption2 == "x")
                exit(0);
        }




        if (duelOption1 == "A" || duelOption1 == "a")
        {
            if (yourCharacter.type != "T" && yourCharacter.type != "t")
                yourCharacter.health -= (myCharacter.offense - yourCharacter.defense);
            else if (yourCharacter.type == "T" || yourCharacter.type == "t")
            {
                if (abilityOption2 == "1")
                {
                    yourCharacter.health -= (myCharacter.offense - yourCharacter.defense);
                    yourCharacter.defense -= 25;
                }
                else if (abilityOption2 == "2")
                {
                    yourCharacter.health -= (myCharacter.offense - yourCharacter.defense);
                }
                else if (abilityOption2 == "3")
                {
                    yourCharacter.health -= (myCharacter.offense - yourCharacter.defense);
                    myCharacter.health -= (myCharacter.offense - yourCharacter.defense);
                }
                else if (abilityOption2 == "4")
                {
                    yourCharacter.health += (myCharacter.offense - yourCharacter.defense);
                    if (yourCharacter.health > 1500)
                        yourCharacter.health = 1500;
                }
            }
        }
        if (duelOption2 == "A" || duelOption2 == "a")
        {
            if (myCharacter.type != "T" && myCharacter.type != "t")
                myCharacter.health -= (yourCharacter.offense - myCharacter.defense);
            else if (yourCharacter.type == "T" || yourCharacter.type == "t")
            {
                if (abilityOption1 == "1")
                {
                    myCharacter.health -= (yourCharacter.offense - myCharacter.defense);
                    myCharacter.defense -= 25;
                }
                else if (abilityOption1 == "2")
                {
                    myCharacter.health -= (yourCharacter.offense - myCharacter.defense);
                }
                else if (abilityOption1 == "3")
                {
                    myCharacter.health -= (yourCharacter.offense - myCharacter.defense);
                    yourCharacter.health -= (yourCharacter.offense - myCharacter.defense);
                }
                else if (abilityOption1 == "4")
                {
                    myCharacter.health += (yourCharacter.offense - myCharacter.defense);
                    if (myCharacter.health > 1500)
                        myCharacter.health = 1500;
                }
            }
        }


        //Prints an update of each players character at the end of each turn/round.
        cout << endl << "Turn " << x << " has ended. Here is an update on our duelists: " << endl << endl;
        m.Character::updateValuesInCombat(myCharacter.name, myCharacter.health, myCharacter.resource, yourCharacter.name, yourCharacter.health, yourCharacter.resource);

        x++;

    } while (myCharacter.health > 0 && yourCharacter.health > 0); //Continues the duel until one duelist falls below 0 health.

    //If any duelist falls below 0 health, their health is adjusted to 0. 
    if (myCharacter.health < 0)
        myCharacter.health = 0;
    if (yourCharacter.health < 0)
        yourCharacter.health = 0;

    //Provides a quick summary of the duel aftermath - HP of each duelist. 
    m.Character::updateValues(myCharacter.name, myCharacter.type, myCharacter.health, yourCharacter.name, yourCharacter.type, yourCharacter.health);
    cout << endl << endl << endl << endl << endl;

    //Declares the winner of the duel based on which character has 0 health remaining after the duel. 
    if (myCharacter.health == 0 && yourCharacter.health > 0)
        cout << yourCharacter.name << " is the winner of the duel!" << endl;
    else if (myCharacter.health > 0 && yourCharacter.health == 0)
        cout << myCharacter.name << " is the winner of the duel!" << endl;
    else if (myCharacter.health == 0 && yourCharacter.health == 0)
        cout << "Both " << myCharacter.name << " and " << yourCharacter.name << " ended the duel with 0 health.. there is no winner for this duel" << endl;






}