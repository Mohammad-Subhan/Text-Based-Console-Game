// Header Files
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iomanip>
#include <string>

// using standard namespace library
using namespace std;

// Function Prototypes
void StartGame();
void StartMenu();
void Credit();
void ExitGame();
void GameEnd();
void LoadingScreen();
void SelectionMenu();
void CharacterCreation(string);
void CharacterDamage();
void Level1();
void Level2();
void Mansion();
void MansionLawn();
void Move(char map[20][30], int rows, int cols, int playerRow, int playerCol);
void HUD();
void CombatHUD();
void Combat(string);
void Story1();
void Story2();
void ForestLv2();
void RightWay_l2();
void WrongWay_l2();
void Level3();
void ForestLv3();
void CentaurTerritory(string);
void EnemyCreation(string);
void Quest(string);
void Inventory();
void Puzzle(string, string, string);
void GameWin();

// Global variables
const char v_d = 186;
const char h_d = 205;
const char urc = 187;
const char ulc = 201;
const char lrc = 188;
const char llc = 200;
const char Player = 'P';
bool quest;

// Global Struct for Player Items
struct items {

	int key = 0, elixir = 0, wood = 0;
	int machete = 0, spear = 0, halberd = 0, maceChain = 0, mightySword = 0;

	int macheteUse = 0, maceChainUse = 0, halberdUse = 0, mightySwordUse = 0;

}playerItems;

// Global Struct for Player and Creature Stats
struct CharacterStats
{
	string name, type, difficulty;
	int totalHealth, health, heal, damage, minDamage, maxDamage, XP = 0;
	int magic, minMagic, maxMagic;

}player, creature;

// Main Function
int main() {

	// StartMenu Function call
	StartMenu();

	// returns 0 value
	return 0;
}

// Start Menu Function Definition
void StartMenu() {

	char choice; // variable

	system("cls"); // to clear screen

	// prints the Game Name and Menu Options
	cout << "\n\n\t\t\t*****************************************";
	cout << "\n\t\t\t*\tEnchanted Forest Adventure\t*";
	cout << "\n\t\t\t*****************************************";
	cout << "\n\n\n\n\n\t\t\t\t";
	cout << "   1. Start Game\n\t\t\t\t   2. Credits\n\t\t\t\t   3. Exit Game";

	do { // For Error Handling and wrong inputs
		cout << "\n\n\n\n\t\t\t\tEnter (1 - 3) > ";
		cin >> choice;

		if (choice == '1' || choice == '2' || choice == '3')
			break;

		cout << "\t\t\t\tInvalid Input. Enter Again.";

	} while (true);

	// Switch Conditional to perform action according to player Input
	switch (choice) {

	case '1':
		// Start Game Function Call
		StartGame();
		break;

	case '2':
		// Credit Function call
		Credit();
		break;

	case '3':
		// ExitGame function call
		ExitGame();
		break;

	default:
		cout << "\nInvalid Input\n";
		break;
	}
	// ignores the input
	cin.ignore();
}

// Credit Function definition
void Credit() {

	// Displays credits
	system("cls");
	cout << "\n\n\t\t\tThe Game Creators are Mohammad Subhan and Musab\n\n\t\t\t";
	system("pause");

	// StartMenu Function call
	StartMenu();

}

// ExitGame function definition
void ExitGame() {

	char choice;

	system("cls");

	// Loop continues until the user enters correct input
	do {
		cout << "\n\n\t\t\tAre you sure you want to exit? ( Y,y / N,n ) : "; // asking user whether to exit or not
		cin >> choice; // getting input

		if (choice == 'Y' || choice == 'y' || choice == 'N' || choice == 'n')
			break; // if correct input, breaks the loop

		cout << "\n\t\t\t\tInvalid Input. Try Again\n";
	} while (true);

	// If no, call back to start menu 
	if (choice == 'N' || choice == 'n')
		StartMenu();
	else // else exit the program
		exit(0);
}

// EndGame function defintion
void GameEnd() {

	// Displays game over message and returns to start Menu
	system("cls");
	cout << "You Died. Game Over!\n\n";
	cout << R"( ________  ________  _____ ______   _______                   
|\   ____\|\   __  \|\   _ \  _   \|\  ___ \                  
\ \  \___|\ \  \|\  \ \  \\\__\ \  \ \   __/|                 
 \ \  \  __\ \   __  \ \  \\|__| \  \ \  \_|/__               
  \ \  \|\  \ \  \ \  \ \  \    \ \  \ \  \_|\ \              
   \ \_______\ \__\ \__\ \__\    \ \__\ \_______\             
    \|_______|\|__|\|__|\|__|     \|__|\|_______|             
                                                              
                                                              
                                                              
 ________  ___      ___ _______   ________          ___       
|\   __  \|\  \    /  /|\  ___ \ |\   __  \        |\  \      
\ \  \|\  \ \  \  /  / | \   __/|\ \  \|\  \       \ \  \     
 \ \  \\\  \ \  \/  / / \ \  \_|/_\ \   _  _\       \ \  \    
  \ \  \\\  \ \    / /   \ \  \_|\ \ \  \\  \|       \ \__\   
   \ \_______\ \__/ /     \ \_______\ \__\\ _\        \|__|   
    \|_______|\|__|/       \|_______|\|__|\|__|           ___ 
                                                         |\__\
                                                         \|__|
)" << "\n\n";
	system("pause");
	StartMenu();

}

// StartGame function defintion
void StartGame() {

	// after selection menu proceed to level 1
	LoadingScreen();

	SelectionMenu();

	LoadingScreen();

	Level1();

}

// LoadingScreen function definition
void LoadingScreen() {

	srand(time(0)); // for RNG
	char bar1 = 177, bar2 = 219;
	int i;

	system("cls");
	// Displays loading
	cout << "\n\n\n\t\t\t\t     Loading . . .\n" << endl;
	cout << "\t\t  ";

	for (i = 1; i <= 50; i++) {
		cout << bar1;
	}

	cout << "\r\t\t  ";

	for (i = 1; i <= 50; i++) {
		cout << bar2;
		Sleep(rand() % 50);
	}

	system("cls");
	cout << "\n\n\n\t\t\t\t     Complete !\n" << endl;
	cout << "\t\t  ";

	for (i = 1; i <= 50; i++) {
		cout << bar2;
	}

	cout << "\n\n\t\t\t    ";
	system("pause");

}

// SelectionMenu function definition
void SelectionMenu() {

	system("cls");

	char type, diff;

	// asks the user to enter player name
	cout << "\n\n\n\t\t\t=> Enter Player Name: ";
	cin >> player.name;

	// prompts the user to enter player type
	cout << "\n\t\t\t=> Enter Character type (1-3): \n\n";
	cout << "\t\t1. Warrior\n\t\t\tStrength: Physical Strength and Combat Abilities\n\t\t\tWeakness: Limited Magic Spells\n" << endl;
	cout << "\t\t2. Mage\n\t\t\tStrength: Magical Spells\n\t\t\tWeakness: Less Physical Strength and Combat Abilities\n" << endl;
	cout << "\t\t3. Adventurer\n\t\t\tStrength: Versatile in various skills\n\t\t\tWeakness: Balanced stats (neither excel in any nor deficits any)" << endl;

	// for error handling and wrong inputs
	do {
		cout << "\n\t\t\t> ";
		cin >> type;

		if (type == '1' || type == '2' || type == '3')
			break; // if correct input breaks the loop

		cout << "\t\t\tInvalid Input. Enter Again\n";
	} while (true);

	// switch conditional to perform action accordingly
	switch (type) {
	case '1':
		player.type = "Warrior";
		break;
	case '2':
		player.type = "Mage";
		break;
	case '3':
		player.type = "Adventurer";
		break;
	default:
		break;
	}
	cin.ignore();

	// Prompts the user to enter difficulty
	cout << "\n\n\n\t\t\t=> Enter Difficulty (1-3): " << endl;
	cout << "\n\t\t\t1. Easy\n\t\t\t2. Medium\n\t\t\t3. Hard\n";

	// loop for error handling and wrong inputs
	do {
		cout << "\n\t\t\t> ";
		cin >> diff;

		if (diff == '1' || diff == '2' || diff == '3')
			break; // for correct inputs the loop breaks

		cout << "\t\t\tInvalid Input. Enter Again\n";
	} while (true);

	// switch conditional to act accordingly
	switch (diff) {
	case '1':
		player.difficulty = "Easy";
		break;
	case '2':
		player.difficulty = "Medium";
		break;
	case '3':
		player.difficulty = "Hard";
		break;
	default:
		cout << "Invalid Input";
		break;
	}
	cin.ignore();

	cout << "\n\n\t\t\t";
	system("pause");
}

// CharacterCreation function definition
void CharacterCreation(string lvl) {

	// different health for different levels
	if (lvl == "l1") {
		player.health = 100;
		player.totalHealth = 100;
	}
	else if (lvl == "l2") {
		player.health = 200;
		player.totalHealth = 250;
	}
	else if (lvl == "l3") {
		player.health = 300;
		player.totalHealth = 400;
	}
}

// Characterdamage function defintion
void CharacterDamage() {

	// character stats according to character type
	if (player.type == "Warrior") {
		player.minDamage = ((player.XP / 2) + 6);
		player.maxDamage = ((player.XP / 2) + 12);
		player.minMagic = ((player.XP / 2) + 4);
		player.maxMagic = ((player.XP / 2) + 8);
	}
	else if (player.type == "Mage") {
		player.minDamage = ((player.XP / 2) + 4);
		player.maxDamage = ((player.XP / 2) + 8);
		player.minMagic = ((player.XP / 2) + 6);
		player.maxMagic = ((player.XP / 2) + 12);
	}
	else if (player.type == "Adventurer") {
		player.minDamage = ((player.XP / 2) + 5);
		player.maxDamage = ((player.XP / 2) + 10);
		player.minMagic = ((player.XP / 2) + 5);
		player.maxMagic = ((player.XP / 2) + 10);
	}


}

// Level1 function defintion
void Level1() {

	CharacterCreation("l1"); // for character stats updation
	Mansion(); // for start of level1

}

// HUD function defintion
void HUD() {

	system("cls");
	// Displays the player stats
	cout << endl << "Player Name : " << player.name << endl;
	cout << "Player Type : " << player.type << endl;
	cout << "Health : " << player.health << endl;
	cout << "Player XP : " << player.XP << endl;
	cout << "----------------------------------------------------\n" << endl;
}

// CombatHUD function defintion
void CombatHUD() {

	system("cls");

	// displays the player and creature stats during combat
	cout << endl << "Player Name: " << player.name << "\t\t|\tEnemy Name: " << creature.name << endl;
	cout << "Player Type: " << player.type << "\t\t|\tEnemy Type: " << creature.type << endl;
	cout << "Health: " << player.health << "\t\t|\tEnemy Health: " << creature.health << endl;
	cout << "------------------------------------------------------------------------------------------------------\n\n";

}

// Combat function function defintion
void Combat(string name) {

	char choice;

	// for creating enemy accordingly
	EnemyCreation(name);

	// loop to iterate the same commands
	do {

		CombatHUD();

		// Displays user the actions and gets input
		cout << "Enter:\n";
		cout << "1. Attack\n2. Use Magic Spell\n3. Defend\n4. Use Machete\n5. Use Spear\n6. Use Halberd\n7. Use Mace Chain\n8. Use Mighty Sword\n";
		cout << "\nEnter (1 - 8)\n> ";
		cin >> choice;
		cout << endl;

		// for error handling and edge cases
		while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5' && choice != '6' && choice != '7' && choice != '8') {
			cout << "\nInvalid Input.Enter Again\n> ";
			cin >> choice;
			cout << endl;
		}

		// conditional if-else to perform accordingly
		if (choice == '1') {

			// calculating player and creature damage randomly but in a specific range
			player.damage = ((rand() % (player.maxDamage - player.minDamage)) + player.minDamage);
			creature.damage = ((rand() % (creature.maxDamage - creature.minDamage)) + creature.minDamage);

			// displays the player attack
			cout << "You opt to Attack.\n";
			cout << "Attacking . . .\n\n";
			Sleep(750);
			cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

			// decrements the creature health and checks if less than 0
			creature.health -= player.damage;
			if (creature.health <= 0)
				creature.health = 0;

			// if creature health equals 0, creature dies and returns back to the game map
			if (creature.health == 0) {
				cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
				system("pause");
				return;
			}

			system("pause");
			CombatHUD();

			// displays the creature attack
			cout << creature.name << " attacking ...\n\n";
			Sleep(1000);

			// decrements the player health and check if it is less than 0
			player.health -= creature.damage;
			if (player.health <= 0)
				player.health = 0;

			cout << creature.name << " dealt " << creature.damage << " damage to you.\nYour health is " << player.health << " HP.\n\n";

			// if player health equals 0, game ends
			if (player.health == 0) {
				system("cls");
				cout << "You Died!\n\n";
				system("pause");
				GameEnd();
			}

			system("pause");

		}
		else if (choice == '2') {

			// calculating player and creature damage randomly but in a specific range
			player.damage = ((rand() % (player.maxMagic - player.minMagic)) + player.minMagic);
			creature.damage = ((rand() % (creature.maxDamage - creature.minDamage)) + creature.minDamage);

			cout << "You opt to use Magic Spell.\n";

			// chooses random spell just for fun
			int r = rand() % 3;
			if (r == 0)
				cout << "\nAbracadabra! . . .\n\n";
			if (r == 1)
				cout << "\nHocus Pocus! . . .\n\n";
			if (r == 2)
				cout << "\nWingardium Leviosa! . . .\n\n";

			Sleep(750);
			cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

			creature.health -= player.damage;
			if (creature.health <= 0)
				creature.health = 0;

			if (creature.health == 0) {
				cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
				system("pause");
				return;
			}

			system("pause");
			CombatHUD();

			cout << creature.name << " attacking ...\n\n";
			Sleep(500);

			player.health -= creature.damage;
			if (player.health <= 0)
				player.health = 0;

			cout << creature.name << " dealt " << creature.damage << " damage to you.\nYour health is " << player.health << " HP.\n\n";

			if (player.health == 0) {
				system("cls");
				cout << "You Died!\n\n";
				system("pause");
				GameEnd();
			}

			system("pause");

		}
		else if (choice == '3') {

			// displays the player defend action
			cout << "You opt to defend\nDefending . . .\n\n";
			Sleep(750);

			// RNG for random action whether to make the defend succesful or fail
			int r = rand() % 2;
			if (r == 0) {
				// if it fails, the creature deals damage.
				creature.damage = ((rand() % (creature.maxDamage - creature.minDamage)) + creature.minDamage);
				player.health -= creature.damage;

				if (player.health <= 0)
					player.health = 0;

				cout << creature.name << " is not impressed by your Defend\nHe dealt " << creature.damage << " damage to you.\n\n";

				if (player.health == 0) {
					system("cls");
					cout << "You Died!\n\n";
					system("pause");
					GameEnd();
				}
			}
			else {
				// else the defend is successful and health regained
				player.heal = rand() % 5 + 1;
				player.health += player.heal;

				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "Your defend was successful. You gained " << player.heal << " Hp.\n\n";
			}
			system("pause");
		}
		else if (choice == '4') {
			if (playerItems.machete <= 0) { // displays message when no machete
				cout << "You dont have Machete\n\n";
			}
			else {
				player.damage = ((rand() % ((player.maxDamage) - (player.minDamage))) + player.minDamage + 5);
				creature.health -= player.damage;
				cout << "You opt to use Machete.\n";
				playerItems.macheteUse += 1;

				if (playerItems.macheteUse == 5)
					playerItems.machete = 0;

				cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

				if (creature.health <= 0)
					creature.health = 0;

				if (creature.health == 0) {
					cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
					system("pause");
					return;
				}
			}

			system("pause");
		}
		else if (choice == '5') {

			if (playerItems.spear <= 0) {
				cout << "You dont have Spear\n\n";
			}
			else {
				player.damage = ((rand() % (player.maxDamage - player.minDamage)) + player.minDamage + 5);
				creature.health -= player.damage;
				cout << "You opt to use Spear.\n";

				playerItems.spear -= 1;
				if (playerItems.spear < 0)
					playerItems.spear = 0;

				cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

				if (creature.health <= 0)
					creature.health = 0;

				if (creature.health == 0) {
					cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
					system("pause");
					return;
				}
			}

			system("pause");

		}
		else if (choice == '6') {

			if (playerItems.halberd <= 0) {
				cout << "You dont have a Halberd\n\n";
			}
			else {
				player.damage = ((rand() % (player.maxDamage - player.minDamage + 10)) + player.minDamage + 10);
				creature.health -= player.damage;
				cout << "You opt to use Halberd.\n";

				playerItems.halberdUse += 1;
				if (playerItems.halberdUse == 5)
					playerItems.halberd = 0;

				cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

				if (creature.health <= 0)
					creature.health = 0;

				if (creature.health == 0) {
					cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
					system("pause");
					return;
				}
			}
			system("pause");
		}
		else if (choice == '7') {

			if (playerItems.maceChain <= 0) {
				cout << "You dont have a Mace Chain\n\n";
			}
			else {
				player.damage = ((rand() % (player.maxDamage - player.minDamage)) + player.minDamage + 10);
				creature.health -= player.damage;
				cout << "You opt to use MaceChain.\n";

				playerItems.maceChainUse += 1;
				if (playerItems.maceChainUse == 5)
					playerItems.maceChain = 0;

				cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

				if (creature.health <= 0)
					creature.health = 0;

				if (creature.health == 0) {
					cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
					system("pause");
					return;
				}
			}
			system("pause");


		}
		else if (choice == '8') {

			if (playerItems.mightySword <= 0) {
				cout << "You dont have the Mighty Sword\n\n";
			}
			else {
				player.damage = ((rand() % ((player.maxDamage) - (player.minDamage))) + player.minDamage + 20);
				creature.health -= player.damage;
				cout << "You opt to use Mighty Sword.\n";

				playerItems.mightySwordUse += 1;
				if (playerItems.mightySwordUse == 5)
					playerItems.mightySword = 0;

				cout << "You dealt " << player.damage << " damage to " << creature.name << ".\n\n";

				if (creature.health <= 0)
					creature.health = 0;

				if (creature.health == 0) {
					cout << "Congratulations! You defeated the " << creature.name << " successfully.\n\n";
					system("pause");
					return;
				}
			}
			system("pause");
		}
		else {
			cout << "\nInvalid Input\n\n";
			system("pause");
		}
	} while (true);
}

// EnemyCreation function defintion
void EnemyCreation(string name) {

	if (name == "Goblin") {
		creature.name = "Goblin";
		creature.type = "Creature";
		creature.health = 30;
		creature.totalHealth = 30;
	}
	else if (name == "Aragog") {
		creature.name = "Aragog";
		creature.type = "Creature";
		creature.health = 50;
		creature.totalHealth = 50;
	}
	else if (name == "Gothmog") {
		creature.name = "Gothmog";
		creature.type = "Monster";
		creature.health = 70;
		creature.totalHealth = 70;
	}
	else if (name == "Gollum") {
		creature.name = "Gollum";
		creature.type = "Creature";
		creature.health = 90;
		creature.totalHealth = 90;
	}
	else if (name == "Chimera") {
		creature.name = "Chimera";
		creature.type = "Creature";
		creature.health = 110;
		creature.totalHealth = 110;
	}
	else if (name == "Nocturna") {
		creature.name = "Nocturna";
		creature.type = "Monster";
		creature.health = 130;
		creature.totalHealth = 130;
	}
	else if (name == "Wendigo") {
		creature.name = "Wendigo";
		creature.type = "Creature";
		creature.health = 150;
		creature.totalHealth = 150;
	}
	else if (name == "Alguran") {
		creature.name = "Alguran";
		creature.type = "Monster";
		creature.health = 190;
		creature.totalHealth = 190;
	}
	else if (name == "Bolg") {
		creature.name = "Bolg";
		creature.type = "Creature";
		creature.health = 170;
		creature.totalHealth = 170;
	}

	if (player.difficulty == "Easy") {
		creature.minDamage = ((player.XP / 2) + 2);
		creature.maxDamage = ((player.XP / 2) + 5);
	}
	else if (player.difficulty == "Medium") {
		creature.minDamage = ((player.XP / 2) + 3);
		creature.maxDamage = ((player.XP / 2) + 8);
	}
	else if (player.difficulty == "Hard") {
		creature.minDamage = ((player.XP / 2) + 4);
		creature.maxDamage = ((player.XP / 2) + 9);
	}
}

// Mansion function defintion
void Mansion() {

	char move;
	int steps = 0;
	bool key = false;
	bool door = false;
	int scroll = 0;
	bool goblin = true;

	const int rows = 20;
	const int cols = 30;

	char Map[30][30] = {
		{ ulc, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 203, h_d, h_d, h_d, h_d, h_d, h_d, 203, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, urc },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 204, h_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 204, h_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 204, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 185, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', 204, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 185 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 202 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'D' },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 203 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', 204, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 185 },
		{ 204, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 185, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', v_d, ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ llc, h_d, 202, h_d, 202, h_d, h_d, h_d, h_d, h_d, h_d, 202, h_d, h_d, h_d, h_d, h_d, h_d, 202, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, lrc },
	};

	int playerCol = 0;
	int playerRow = 0;


	playerRow = 3;
	playerCol = 1;

	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nS : Ancient Scroll\nM : Machete\nE : Elixir\nK : Key\nD : Door\nG : Goblin\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}


		if (Map[playerRow][playerCol] != ' ') {

			if (Map[playerRow][playerCol] == 'S') {
				HUD();
				scroll++;
				if (scroll == 1) {
					Map[14][24] = 'M';
					Map[9][2] = 'E';
				}
				Story1();
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'D') {

				HUD();
				if (key == true) {
					cout << "Mansion Lawn\n\n";
					system("pause");
					MansionLawn();
				}
				else {
					cout << "The Door is locked. The key [ K ] of the door\nis kept by the goblin [ G ]. Defeat him to get\nthe Key.\n\n";
					cout << R"(            __________
           |  __  __  |
           | |  ||  | |
           | |  ||  | |
           | |__||__| |
           |  __  __()|
           | |  ||  | |
           | |  ||  | |
           | |  ||  | |
           | |  ||  | |
           | |__||__| |
           |__________|)" << "\n\n";
					door = true;
					system("pause");
				}
			}
			else if (Map[playerRow][playerCol] == 'K') {
				HUD();
				cout << "You Got the Key.\n\n";
				cout << R"(          .---.
         /    |\________________
        | ()  | ________   _   _)
         \    |/        | | | |
          `---'         "-" |_|)" << "\n\n";
				playerItems.key = 1;
				key = true;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'M') {
				HUD();
				Map[14][24] = ' ';
				cout << "You got a Machete.\n\n";
				cout << R"(   _,---,_
 /'_______`\
(/'       `\|___________----------"""""""------,
 \#########||______                          /'
  ^^^^^^^^^||      """"""-----_____        /'
            \                      """--_/')" << "\n\n";
				playerItems.machete += 1;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'E') {
				HUD();
				Map[9][2] = ' ';
				cout << "You got Elixir (health potion).\n\n";
				cout << R"(      _____
     `.___,'
      (___)
      <   >
       ) (
      /`-.\
     /     \
    / _    _\
   :,' `-.' `:
   |         |
   :         ;
    \       /
     `.___.'    )" << "\n\n";
				playerItems.elixir += 1;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'G') {
				HUD();
				cout << "You Encountered a Goblin. Defeat him to get the Key\n\n";
				cout << R"(             ,      ,
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \)" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Goblin");
				player.XP += 10;
				goblin = false;
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}

		steps++;

		if (steps == 4) {
			HUD();
			cout << "Get to the Ancient Scroll [ S ]\n\n";
			cout << R"(         _______________
    ()==(              (@==()
         '______________'|
           |             |
           |             |
         __)_____________|
    ()==(               (@==()
         '--------------')" << "\n\n";
			Map[6][26] = 'S';
			system("pause");
		}
		if (door) {
			if (goblin)
				Map[17][3] = 'G';
			else
				Map[17][3] = ' ';

			if (!key)
				Map[18][3] = 'K';
			else
				Map[18][3] = ' ';
		}
	} while (true);

}

// Move function defintion
void Move(char map[20][30], int rows, int cols, int playerRow, int playerCol) {

	for (int i = 0; i < rows; ++i) {

		for (int j = 0; j < cols; ++j) {

			if (i == playerRow && j == playerCol)
				cout << Player;
			else
				cout << map[i][j];

		}
		std::cout << '\n';
	}
}

// MansionLawn function defintion
void MansionLawn() {

	char move;

	const int rows = 20;
	const int cols = 30;

	char Map[20][30] = {
		{ ulc, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, urc },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 202, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 203, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'T', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ 204, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, 185 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'Q', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', h_d, 202 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'G', ' ', 'E' },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', h_d, 203 },
		{ v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d },
		{ llc, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, lrc },
	};

	// Initial player position
	int playerRow = 3;
	int playerCol = 0;

	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nT : Talking Tree\nA : Aragog\nQ : Quest\nG : Gothmog\nE : Exit\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}

		if (Map[playerRow][playerCol] != ' ') {

			if (Map[playerRow][playerCol] == 'E') {
				system("cls");
				cout << "\n\nCongratulations " << player.name << "! You passed Level 1 Succesfully\n";
				cout << "\nPress any key to move to Level 2";
				_getch();
				LoadingScreen();
				Level2();
			}
			else if (Map[playerRow][playerCol] == 'T') {
				HUD();
				Story2();
			}
			else if (Map[playerRow][playerCol] == 'A') {
				HUD();
				cout << "You Encountered Aragog (a giant Spider). Defeat him to move forward\n\n";
				cout << R"(              (
               )
              (
        /\  .-"""-.  /\
       //\\/  ,,,  \//\\
       |/\| ,;;;;;, |/\|
       //\\\;-"""-;///\\
      //  \/   .   \/  \\
     (| ,-_| \ | / |_-, |)
       //`__\.-.-./__`\\
      // /.-(() ())-.\ \\
     (\ |)   '---'   (| /)
      ` (|           |) `
        \)           (/)" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Aragog");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';
			}
			else if (Map[playerRow][playerCol] == 'Q') {
				HUD();
				cout << "You Encountered a Quest. Guess the word using the hint.\n\n";
				system("pause");
				quest = false;
				Quest("l1");

				if (quest) {
					HUD();
					cout << "\nYou got Elixir (health potion)\n\n";
					playerItems.elixir += 1;
				}
				else {
					HUD();
					cout << "\nYou failed to guess the word. Press any key to move on\n\n";
				}
				Map[playerRow][playerCol] = ' ';
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'G') {
				HUD();
				cout << "You encountered a Gothmog (an Orc). Defeat him to get to the Mansion Gate\n\n";
				cout << R"(                         __,='`````'=/__
                          '//  (o) \(o) \ `'         _,-,
                          //|     ,_)   (`\      ,-'`_,-\
                        ,-~~~\  `,===,  /-,      \==```` \__
                       /        `----'     `\     \       \/
                    ,-`                  ,   \  ,.-\       \
                   /      ,               \,-`\`_,-`\_,..--'\
                  ,`    ,/,              ,>,   )     \--`````\
                  (      `\`---'`  `-,-'`_,<   \      \_,.--'`
                   `.      `--. _,-'`_,-`  |    \
                    [`-.___   <`_,-'`------(    /
                    (`` _,-\   \ --`````````|--`
                     >-`_,-`\,-` ,          |
                   <`_,'     ,  /\          /
                    `  \/\,-/ `/  \/`\_/V\_/
                       (  ._. )    ( .__. )
                       |      |    |      |
                        \,---_|    |_---./
                        ooOO(_)    (_)OOoo)" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Gothmog");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

				HUD();
				cout << "You got Gothmog's Mace Chain (a weapon)\n\n";
				playerItems.maceChain += 1;
				system("pause");
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}

	} while (true);

}

// Story1 function defintion
void Story1() {

	cout << R"(
   __________________________________________________________________
 /:  \                                                               \
||< > |                                                               |
| \__/_______________________________________________________________/
|                                                                  |
|                  THE ENCHANTED FOREST ADVENTURE                  |
|                                                                  |)" << endl;
	cout << "|      Hi " << player.name << "!Welcome to the Enchanted Forest \n";
	cout << R"(|      Adventure Game. You will have several goals throughout      |
|      your journey which will be guided to you later.             |
|      For now your goal is to get out of the mansion through      |
|      the door [ D ] and collect the items [ E , M ] scattered    |
|      throughout the mansion.                                     |
|                                                                  |
|  ________________________________________________________________|_
|/`--_                                                               \
||[ ]||                                                               |
 \===/_______________________________________________________________/)" << "\n\n";

}

// Story2 function defintion
void Story2() {

	cout << player.name << ":    Hey! Who are you?\n\n";
	cout << "Celestria:    Don't worry " << player.name << ". My name is Celestria and I am a Talking Tree.\n\n";
	cout << player.name << ":    What do you want from me?\n\n";
	cout << "Celestria:    I dont want anything from you. I am here to guide you for your journey\n           from now onwards\n\n";
	cout << player.name << ":    Oh!\n\n";
	cout << "Celestria:    So listen carefully. You are here to uncover the Hidden Treasure. But be\n           ";
	cout << "careful, it is guarded by a Centaur. You have to defeat him to get the treasure.\n\n";
	cout << player.name << ":    Oh! That's it?\n\n";
	cout << "Celestria:    Dont be overconfident. He is much stronger than your'e expecting. To\n           ";
	cout << "defeat him, you must have the Mighty Sword. But still be careful, a MONSTER is busy\n           ";
	cout << "trying his best to get the sword out of the rock but only a true legend can take it\n           ";
	cout << "out. First you have to defeat him to get the Mighty Sword\n\n";
	cout << player.name << ":    Got it Man!\n\n";
	cout << "Celestria:    Appreciated and on your way you will encounter various creatures. On\n           ";
	cout << "deafeating them your Exprience will be increased and hence damage. Moreover, many\n           ";
	cout << "Puzzles / Riddles will appear and answer them wisely as if answered right you will\n           ";
	cout << "be awarded several valuable items or some tips.\n\n";
	cout << player.name << ":    Done.\n\n";
	cout << "Celestria:    Okay so that's it. Remember my words and Best of Luck for your Journey\n\n";
	cout << player.name << ":    Ok Byee\n\n";

	system("pause");

}

// Level2 function defintion
void Level2() {

	CharacterCreation("l2");
	ForestLv2();

}

// ForestLv2 function defintion
void ForestLv2() {

	char move;
	char rightWay;
	int r;

	const int rows = 20;
	const int cols = 30;

	char Map[20][30] = {
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', ' ', 'G', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A' },
		{ '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', 'N', ' ', ' ', ' ', ' ', 'Q', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'B' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
	};

	// Initial player position
	int playerRow = 0;
	int playerCol = 9;


	r = rand() % 2;

	if (r == 0)
		rightWay = 'A';
	else
		rightWay = 'B';


	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nG : Gollum\nN : NPC\nQ : Quest\nA : Way (A)\nB : Way (B)\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}

		if (Map[playerRow][playerCol] != ' ') {

			if (Map[playerRow][playerCol] == 'G') {
				HUD();
				cout << "You encountered Gollum (a creature). Defeat him to move forward.\n\n";
				cout << R"(                     _..
                    .'   `",
                   ;        \
            .---._; ^,       ;
         .-'      ;{ :  .-. ._;
    .--""          \*'   o/ o/
   /   ,  /         :    _`";
  ;     \;          `.   `"+'
  |      }    /    _.'T"--"\
  :     /   .'.--""-,_ \    ;
   \   /   /_         `,\   ;
    : /   /  `-.,_      \`.  :
    |;   {     .' `-     ; `, \
    : \  `;   {  `-,__..-'   \ `}+=,
     : \  ;    `.   `,        `-,\"
     ! |\ `;     \}?\|}
  .-'  | \ ;
.'}/ i.'  \ `,                           
``''-'    /   \
         /J|/{/
           `')" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Gollum");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

				HUD();
				cout << "You got Gollum's 5 Spears (a weapon)\n\n";
				playerItems.spear += 5;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'Q') {
				HUD();
				cout << "You Encountered a Quest. Guess the word using the hint.\n\n";
				system("pause");
				quest = false;
				Quest("l2");
				if (quest) {
					HUD();
					cout << "\nThe right way is Way '" << rightWay << "'.\n\n";
				}
				else {
					HUD();
					cout << "\nYou failed to guess the word. Press any key to move on\n\n";
				}
				Map[playerRow][playerCol] = ' ';
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'N') {
				HUD();
				cout << "\nThere is a Two Way ahead. One way leads you to a cliff from\nwhich you'll fall and die. Other way is safe to move on\n";
				cout << "\nYou will encounter a Quest ahead in which if you solve the\npuzzle successfully, you'll be guided the right and safe\npath otherwise you will have to guess by your own.\n\n";
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'A') {
				if (rightWay == 'A')
					RightWay_l2();
				else
					WrongWay_l2();
			}
			else if (Map[playerRow][playerCol] == 'B') {
				if (rightWay == 'B')
					RightWay_l2();
				else
					WrongWay_l2();
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}

	} while (true);
}

// RightWay_l2 function defintion
void RightWay_l2() {

	char move;

	const int rows = 20;
	const int cols = 30;

	char Map[20][30] = {
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', ' ', ' ', 'C', ' ', ' ', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', v_d, 219 },
		{ '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', v_d, 219 },
		{ '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', 201, h_d, 187 },
		{ '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'N', ' ', 'S', v_d },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', 200, h_d, 188 },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', v_d, 219 },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', v_d, 219 },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
	};

	// Initial player position
	int playerRow = 7;
	int playerCol = 0;

	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nC : Chimera\nN : Nocturna\nS : Mighty Sword\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}

		if (Map[playerRow][playerCol] != ' ') {

			if (Map[playerRow][playerCol] == 'C') {
				HUD();
				cout << "You encountered Chimera (double headed creature). Defeat him to move forward.\n\n";
				cout << R"(                                              ,w.
                                              ,YWMMw  ,M  ,
                         _.---.._   __..---._.'MMMMMw,wMWmW,
                    _.-""        """           YP"WMMMMMMMMMb,
                 .-' __.'                   .'     MMMMW^WMMMM;
     _,        .'.-'"; `,       /`     .--""      :MMM[==MWMW^;
  ,mM^"     ,-'.'   /   ;      ;      /   ,       MMMMb_wMW"  @\
 ,MM:.    .'.-'   .'     ;     `\    ;     `,     MMMMMMMW `"=./`-,
 WMMm__,-'.'     /      _.\      F"""-+,,   ;_,_.dMMMMMMMM[,_ / `=_}
 "^MP__.-'    ,-' _.--""   `-,   ;       \  ; ;MMMMMMMMMMW^``; __|
            /   .'            ; ;         )  )`{  \ `"^W^`,   \  :
           /  .'             /  (       .'  /     Ww._     `.  `"
          /  Y,              `,  `-,=,_{   ;      MMMP`""-,  `-._.-,
         (--, )                `,_ / `) \/"")      ^"      `-, -;"\:
          `"""                    `"""   `"'                  `---" )" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Chimera");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

			}
			else if (Map[playerRow][playerCol] == 'N') {
				HUD();
				cout << "You encountered Nocturna (snake-haired creature). Defeat her to get to the Sword.\n\n";
				cout << R"(                  ,--.
          ,--.  .--,`) )  .--,
       .--,`) \( (` /,--./ (`
      ( ( ,--.  ) )\ /`) ).--,-.
       ;.__`) )/ /) ) ( (( (`_) )
      ( (  / /( (.' "-.) )) )__.'-,
     _,--.( ( /`         `,/ ,--,) )
    ( (``) \,` ==.    .==  \( (`,-;
     ;-,( (_) ~6~ \  / ~6~ (_) )_) )
    ( (_ \_ (      )(      )__/___.'
    '.__,-,\ \     ''     /\ ,-.
       ( (_/ /\    __    /\ \_) )
        '._.'  \  \__/  /  '._.'
            .--`\      /`--.
                 '----' )" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Nocturna");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

				HUD();
				cout << "You got Elixir as a reward.\n\n";
				playerItems.elixir += 1;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'S') {
				HUD();
				cout << "Congratulations " << player.name << "! You now have the Mighty Sword.\n\n";
				cout << R"(                )         
                  (           
                '    }      
              (    '      
             '      (   
              )  |    ) 
            '   /|\    `
           )   / | \  ` )   
          {    | | |  {   
         }     | | |  .
          '    | | |    )
         (    /| | |\    .
          .  / | | | \  (
        }    \ \ | / /  .        
         (    \ `-' /    }
         '    / ,-. \    ' 
          }  / / | \ \  }
         '   \ | | | /   } 
          (   \| | |/  (
            )  | | |  )
            .  | | |  '
               J | L
         /|    J_|_L    |\
         \ \___/ o \___/ /
          \_____ _ _____/
                |-|
                |-|
                |-|
               ,'-'.
               '---')" << "\n\n";
				playerItems.mightySword += 1;
				cout << "\nPress any key to move to Level 3\n\n";
				_getch();
				LoadingScreen();
				Level3();
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}

	} while (true);
}

// WrongWay_l2 function defintion
void WrongWay_l2() {
	HUD();
	cout << "You entered the wrong way. You died as you fell of the cliff";
	system("pause");
	GameEnd();
}

// Level3 function defintion
void Level3() {

	CharacterCreation("l3");
	ForestLv3();

}

// ForestLv3 function defintion
void ForestLv3() {

	char move;
	bool boat = false;
	int wood = 0;

	const int rows = 20;
	const int cols = 30;

	char Map[20][30] = {
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', ' ', 'S', ' ', ' ', ' ', ' ', '^', '^', '^', '^', 'T', 'T', 'T', '^', '^' },
		{ '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', 'T', 'T', 'T', '^', '^' },
		{ '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', 'T', 'T', 'T', '^', '^' },
		{ '^', '^', '^', '^', '^', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', 'W', ' ', ' ', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ' },
		{ ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~' },
		{ '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ' },
		{ ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ', '~', ' ', ' ' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', 'K', 'K', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', 187, ' ', ' ', 201, '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '~', ' ', '~', ' ', '~', ' ', '~', ' ', 186, ' ', ' ', 186, '~', ' ', '~', ' ', '~', ' ', '~', ' ' },
		{ ' ', '~', ' ', '~', ' ', '~', ' ', '~', 186, ' ', ' ', 186, ' ', '~', ' ', '~', ' ', '~', ' ', '~' },
	};

	// Initial player position
	int playerRow = 0;
	int playerCol = 10;


	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nS : Smurf\nW : Wendigo\nT : Woods / Trees\nK : Sentry Knights\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}

		if (playerRow == 15 && playerCol == 0)
			CentaurTerritory("bypass");
		else if (playerRow == 19)
			CentaurTerritory("bridge");

		if (Map[playerRow][playerCol] != ' ' || (!boat && (playerRow >= 8 && playerRow <= 11))) {

			if (Map[playerRow][playerCol] == 'W') {
				HUD();
				cout << "You encountered Wendigo (a werewolf). Defeat him to get to the Trees\n";
				cout << R"(                        ,     ,
                        |\---/|
                       /  , , |
                  __.-'|  / \ /
         __ ___.-'        ._O|
      .-'  '        :      _/
     / ,    .        .     |
    :  ;    :        :   _/
    |  |   .'     __:   /
    |  :   /'----'| \  |
    \  |\  |      | /| |
     '.'| /       || \ |
     | /|.'       '.l \\_
     || ||             '-'
     '-''-')" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Wendigo");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

			}
			else if (Map[playerRow][playerCol] == 'T') {
				HUD();
				cout << "You got a wood\n\n";
				system("pause");
				Map[playerRow][playerCol] = ' ';
				wood += 1;
			}
			else if (playerRow >= 8 && playerRow <= 11) {
				if (boat)
					continue;
				else {
					if (move == 'w')
						playerRow += 1;
					else if (move == 's')
						playerRow -= 1;
					else if (move == 'a')
						playerCol += 1;
					else if (move == 'd')
						playerCol -= 1;
				}
			}
			else if (Map[playerRow][playerCol] == 'S') {

				if (wood >= 4) {
					HUD();
					cout << "Bumble: Thanks for the wood. Please wait a few seconds i'll make a boat for you\n";
					cout << "\nBuilding Boat . . .";
					Sleep(2000);
					HUD();
					cout << "You got the Boat\n\n";
					system("pause");
					boat = true;
				}
				else
				{
					HUD();
					cout << "You encountered Bumble (a friendly smurf).\n\n";
					cout << R"(    ____
   (__  '.
    /_____)
   ()@ @ )))
    'C ,()(()
    ,.'_'.' \
 __/ )    (--'
'._./|____|
     (_.._)
     _|| ||_
    (__.).__))" << "\n\n";
					system("pause");

					HUD();
					cout << player.name << " : Hi, who are you?\n\n";
					cout << "Smurf : Hi, I am Bumble. I am here to tell you somthing.\n\n";
					cout << player.name << " : What?\n\n";
					cout << "Bumble : Listen ... There is a river ahead and to cross that river you have to take\n         a boat. Do you own any?\n\n";
					cout << player.name << " : Nah ... Now what\n\n";
					cout << "Bumble : Not a problem. I'll build one for you ... umm ... (interrupts)\n\n";
					cout << player.name << " : Thats good. Please build me one\n\n";
					cout << "Bumble : You interrupted me. There's a problem. I don't have any woods left and the way\n";
					cout << "         to the woods have been blocked by Wendigo.\n\n";
					cout << player.name << " : Who's this Wendigo?\n\n";
					cout << "Bumble : Wendigo is a Werewolf. He's dont allowing me take any woods and so my bussiness\n";
					cout << "         of making boats is ruined. You would have to kill Wendigo and bring me at least 4 woods\n";
					cout << "         and I'll build you a boat.\n\n";
					cout << player.name << " : Okay Bumble. Wait here and I go deal with Wendigo\n\n";
					cout << "Bumble : Good Luck\n\n";
					system("pause");
				}
			}
			else if (Map[playerRow][playerCol] == 'K') {
				HUD();
				cout << "You encountered Sentry Knights. They gaurd the bridge to the Centaur Territory.\n";
				cout << "They will provide you with a Riddle.If solved correctly they'll allow you to\n";
				cout << "pass throught the bridge otherwise you'd have to take a bypass leading to the\n";
				cout << "territory. But be careful, the bypass is guarded by a CREATURE. You will have to\n";
				cout << "defeat him to move forward.\n\n";
				cout << R"(  ,               {}
 / \, | ,        .--.
|    =|= >      /.--.\
 \ /` | `       |====|
  `   |         |`::`|  
      |     .-;`\..../`;_.-^-._
     /\\/  /  |...::..|`   :   `|
     |:'\ |   /'''::''|   .:.   |
      \ /\;-,/\   ::  |..:::::..|
      |\ <` >  >._::_.| ':::::' |
      | `""`  /   ^^  |   ':'   |
      |       |       \    :    /
      |       |        \   :   / 
      |       |___/\___|`-.:.-`
      |        \_ || _/    `
      |        <_ >< _>
      |        |  ||  |
      |        |  ||  |
      |       _\.:||:./_
      |      /____/\____\)" << "\n\n";
				system("pause");

				HUD();
				cout << "Guess the word using the hint.\n\n";
				system("pause");
				quest = false;
				Quest("l3");

				if (quest) {
					HUD();
					cout << "\nYou are Free to go from the bridge\n\n";
					Map[16][9] = ' ';
					Map[16][10] = ' ';
				}
				else {
					HUD();
					cout << "\nYou failed to guess the word. Press any key to move on\n\n";
					Map[17][9] = h_d;
					Map[17][10] = h_d;
					Map[16][9] = h_d;
					Map[16][10] = h_d;
				}
				system("pause");
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}
	} while (true);
}

// CentaurTerritory function defintion
void CentaurTerritory(string way) {

	char move;

	int playerRow;
	int playerCol;
	const int rows = 20;
	const int cols = 30;

	char Map[20][30] = {
		{ '~', ' ', '~', ' ', '~', ' ', '~', ' ', '~', v_d, ' ', ' ', v_d, ' ', '~', ' ', '~', ' ', '~', ' ', '~' },
		{ ' ', '~', ' ', '~', ' ', '~', ' ', '~', ' ', v_d, ' ', ' ', v_d, '~', ' ', '~', ' ', '~', ' ', '~', ' ' },
		{ h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, v_d, ' ', ' ', v_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', lrc, ' ', ' ', llc, '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', ' ', ' ', ' ', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', ' ', 239, ' ', ' ', 239, ' ', '^', '^', '^', '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', ulc, h_d, h_d, h_d, 219, ' ', ' ', 219, h_d, h_d, h_d, urc, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', 218, 196, ' ', 196, 191, ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', 179, ' ', ' ', ' ', 179, ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', 179, ' ', 'T', ' ', 179, ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', v_d, ' ', ' ', ' ', 179, ' ', ' ', ' ', 179, ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', 202, ' ', ' ', ' ', 192, 196, 196, 196, 217, ' ', ' ', v_d, '^', '^', '^', '^' },
		{ ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', 203, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', v_d, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', llc, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, h_d, lrc, '^', '^', '^', '^' },
		{ '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^', '^' },
	};

	if (way == "bridge") {
		playerRow = 0;
		playerCol = 10;
		Map[16][5] = v_d;
	}
	else if (way == "bypass") {
		playerRow = 16;
		playerCol = 0;
	}


	do {

		HUD();
		Move(Map, rows, cols, playerRow, playerCol);

		cout << "\nKey:\n\nP : Player\nA : Alguran\nB : Bolg\nT : Treasure\n";
		cout << "\nControls:\n\nMovement : W A S D\nInventory : I\nUse Elixir : E\nUse DragonFire Draught : F\n\n> ";
		move = _getch();

		if (move == 'w')
			playerRow = playerRow - 1;
		else if (move == 's')
			playerRow = playerRow + 1;
		else if (move == 'd')
			playerCol = playerCol + 1;
		else if (move == 'a')
			playerCol = playerCol - 1;
		else if (move == 'i')
			Inventory();
		else if (move == 'e') {
			HUD();
			if (playerItems.elixir > 0) {
				player.heal = rand() % (((player.XP / 2) - (player.XP / 2 - 5)) + (player.XP / 2 - 5));

				player.health += player.heal;
				playerItems.elixir -= 1;
				if (playerItems.elixir < 0)
					playerItems.elixir = 0;
				if (player.health > player.totalHealth)
					player.health = player.totalHealth;

				cout << "You opt to use Elixir.\nYour health is increased by " << player.heal << " Hp.Your Current Health is " << player.health << " Hp.\n\n";
			}
			else {
				cout << "You dont have Elixir.\n\n";
			}
			system("pause");
		}
		else if (move == 'f') {
			HUD();
			cout << "DragonFire Drought\n";
			system("pause");
		}

		if (Map[playerRow][playerCol] != ' ') {

			if (Map[playerRow][playerCol] == 'B') {
				HUD();
				cout << "You encountered Bolg (an Orc). Defeat him to get to the Centaur's Territory.\n\n";
				cout << R"(                         __,='`````'=/__
                          '//  (o) \(o) \ `'         _,-,
                          //|     ,_)   (`\      ,-'`_,-\
                        ,-~~~\   ,===,  /-,      \==```` \__
                       /        `----'     `\     \       \/
                    ,-`                  ,   \  ,.-\       \
                   /      ,               \,-`\`_,-`\_,..--'\
                  ,`    ,/,              ,>,   )     \--`````\
                  (      `\`---'`  `-,-'`_,<   \      \_,.--'`
                   `.      `--. _,-'`_,-`  |    \
                    [`-.___   <`_,-'`------(    /
                    (`` _,-\   \ --`````````|--`
                     >-`_,-`\,-` ,          |
                   <`_,'     ,  /\          /
                    `  \/\,-/ `/  \/`\_/V\_/
                       (  ._. )    ( .__. )
                       |      |    |      |
                        \,---_|    |_---./
                        ooOO(_)    (_)OOoo)" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Bolg");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

				HUD();
				cout << "You got Bolg's Halberd (a weapon)\n\n";
				playerItems.halberd += 1;
				system("pause");
			}
			else if (Map[playerRow][playerCol] == 'A') {
				HUD();
				cout << "You encountered Alguran (a centaur). Defeat him to get to the Treasure.\n\n";
				cout << R"(                   |__
   --==/////////////[})))==*
                     |\ '          ,|
                       `\`\      //|'                           ,|
                         \ `\  //,/'                          -~ |
         )           _-~~~\  |/ / |'                       _-~  /  ,
        )(          /'  )  | \ / /'                     _-~   _/_-~|
       (( )         ;  /`  ' )/ /''                 _ -~     _-~ ,/'
       ) )(         `~~\   `\\/'/|'           __--~~__--\ _-~  _/,
      ((___)          / ~~    \ /~      __--~~  --~~  __/~  _-~ /
        | |          |    )   | '      /        __--~~  \-~~ _-~
         \(\    __--(   _/    |'\     /     --~~   __--~' _-~ ~|
         (  ((~~   __-~        \~\   /     ___---~~  ~~\~~__--~
         `~~\~~~~~~   `\-~      \~\ /           __--~~~'~~/
                       ;\ __--~  ~-/      ~~~~~__\__---~~.,,,
                       ;;;;;;;;'  /      ---~~~/__-----_;;;;;;;;,,
                      ;;;;;;;'   /      ----~~/          \ `;;;;;;;;;;;;,
                      ;;;;'     (      ---~~/         `:::|  `;;;;;;;;;;;;;;.
                      |'  _      `----~~~~'      /      `:|    ;;;;;;;'  `;;'
                ______/\/~    |                 /        /       `;;;;;   `;
              /~;;.____/;;'  /          ___----(   `;;;/          ;;;"
             / //  _;______;'------~~~~~    |;;/\    /           ;;
            //  \ \                        / ,|  \;;,\            `
           (<_    \ \                    /',/-----'  _>
            \_|     \\_                 //~;~~~~~~~~~
                     \_|               (,~~             
                                        \~\
                                         ~~)" << "\n\n";
				system("pause");

				CharacterDamage();
				Combat("Alguran");
				player.XP += 10;
				Map[playerRow][playerCol] = ' ';

			}
			else if (Map[playerRow][playerCol] == 'T') {
				HUD();
				cout << "YOU GOT THE TREASUE ... CONGRATULATIONS !!\n\n";
				cout << R"(                                                                                  
                                                                        
                          ,.=""_;=..                                                 
                       ,-"_,=""     `"=.,                  
                       "=._o`"-._       �`"=.
                           `"=._o`"=._      _`"=._                     
                                :=._o "=._."_.-="'"=.
                         __.--" , ; `"=._o." ,-"""-._ ". 
                      ._"  ,. .` ` `` ,  `"-._"-._   ". '
                      |o`"=._` , "` `; .". ,  "-._"-._; ;              
                      | ;`-.o`"=._; ." ` '`."\` . "-._ /
                      |o;    `"-.o`"=._``  '` " ,__.--o;   
                      | ;     (#) `-.o `"=.`_.--"_o.-; ;
                      |o;._    "      `".o|o_.--"    ;o;
                       "=._o--._        ; | ;        ; ;
                            "=._o--._   ;o|o;     _._;o;
                                 "=._o._; | ;_.--"o.--"
                                      "=.o|o_.--""
)" << "\n\n";
				system("pause");
				GameWin();
			}
			else if (move == 'w')
				playerRow += 1;
			else if (move == 's')
				playerRow -= 1;
			else if (move == 'a')
				playerCol += 1;
			else if (move == 'd')
				playerCol -= 1;
		}
	} while (true);
}

// Quest function defintion
void Quest(string lvl) {

	int r = rand() % 5;
	string word[5], riddle[5];

	if (lvl == "l1") {
		riddle[0] = "Which word in the dictionary is spelled incorrectly?";
		word[0] = "incorecctly";
		riddle[1] = "What has many words but never speaks?";
		word[1] = "book";
		riddle[2] = "What has keys but can't open locks and space but no rooms?";
		word[2] = "keyboard";
		riddle[3] = "It is always in front of you but can't be seen";
		word[3] = "future";
		riddle[4] = "The poor have me; the rich lacks me. Eat me and you will die.";
		word[4] = "nothing";

		if (r == 0)
			Puzzle(riddle[0], word[0], lvl);
		else if (r == 1)
			Puzzle(riddle[1], word[1], lvl);
		else if (r == 2)
			Puzzle(riddle[2], word[2], lvl);
		else if (r == 3)
			Puzzle(riddle[3], word[3], lvl);
		else if (r == 4)
			Puzzle(riddle[4], word[4], lvl);
	}
	else if (lvl == "l2") {
		riddle[0] = "The more you take, the more you leave behind.";
		word[0] = "footprint";
		riddle[1] = "It is tall when It is young, and short when it is old";
		word[1] = "candle";
		riddle[2] = "What has a head and a tail, but no body or legs?";
		word[2] = "coin";
		riddle[3] = "What is full of holes but still holds water?";
		word[3] = "sponge";
		riddle[4] = "I crawl on the ground, without a sound,\nIn the forest, I'm often found.\nWith many legs and armor too,\nwho am I, in this adventure for you?";
		word[4] = "caterpillar";

		if (r == 0)
			Puzzle(riddle[0], word[0], lvl);
		else if (r == 1)
			Puzzle(riddle[1], word[1], lvl);
		else if (r == 2)
			Puzzle(riddle[2], word[2], lvl);
		else if (r == 3)
			Puzzle(riddle[3], word[3], lvl);
		else if (r == 4)
			Puzzle(riddle[4], word[4], lvl);
	}
	else if (lvl == "l3") {
		riddle[0] = "What building has the most stories?";
		word[0] = "library";
		riddle[1] = "Break it and it gets better; set it and it�s harder to break";
		word[1] = "record";
		riddle[2] = "What begins with an E but only has one letter in it?";
		word[2] = "envelope";
		riddle[3] = "It touches the earth and it touches the sky, but if it touches you, you are likely to die.";
		word[3] = "lightning";
		riddle[4] = "What begins with T ends with T and has T in it?";
		word[4] = "teapot";

		if (r == 0)
			Puzzle(riddle[0], word[0], lvl);
		else if (r == 1)
			Puzzle(riddle[1], word[1], lvl);
		else if (r == 2)
			Puzzle(riddle[2], word[2], lvl);
		else if (r == 3)
			Puzzle(riddle[3], word[3], lvl);
		else if (r == 4)
			Puzzle(riddle[4], word[4], lvl);
	}
	else
		cout << "Error";

}

// Inventory function defintion
void Inventory() {

	system("cls");

	cout << "\n\tPlayer Inventory\n\n";

	if (playerItems.key > 0)
		cout << "Key : " << playerItems.key << endl;
	if (playerItems.elixir > 0)
		cout << "Elixir : " << playerItems.elixir << endl;
	if (playerItems.machete > 0)
		cout << "Machete : " << playerItems.machete << endl;
	if (playerItems.halberd > 0)
		cout << "Halberd : " << playerItems.halberd << endl;
	if (playerItems.maceChain > 0)
		cout << "Mace Chain : " << playerItems.maceChain << endl;
	if (playerItems.spear > 0)
		cout << "Spears : " << playerItems.spear << endl;
	if (playerItems.wood > 0)
		cout << "Wood : " << playerItems.wood << endl;

	cout << endl;
	system("pause");
}

// Puzzle function defintion
void Puzzle(string riddle, string word, string lvl) {

	char alphabet;
	string guess;
	bool present;
	bool repeat;
	int tries = 0;

	for (int a = 0; a < word.size(); a++) {
		guess += '-';
	}

	if (player.difficulty == "Easy")
		tries = 5;
	else if (player.difficulty == "Medium")
		tries = 4;
	else if (player.difficulty == "Hard")
		tries = 3;

	while (true) {
		system("cls");
		cout << "Tries : " << tries << "\n\n";

		cout << "Hint : " << riddle << "\n";

		if (tries <= 0) {
			cout << "\nYou ran out of tries\n\n";
			quest = false;
			break;
		}
		else if (guess == word) {
			cout << "\nYou guessed the word correctly. Congratulations!\n\n";
			quest = true;
			break;
		}

		cout << "\nWord : " << guess << "\n\nGuess > ";
		cin >> alphabet;

		present = false;
		repeat = false;

		for (int i = 0; i < word.size(); i++) {
			if (alphabet == guess[i]) {
				repeat = true;
				present = true;
				break;
			}
			if (alphabet == word[i]) {
				present = true;
				guess[i] = alphabet;
			}
		}
		if (!present) {
			tries -= 1;
			cout << "\nYou failed to guess. you have " << tries << " tries left.\n\n";
			system("pause");
		}
		else if (repeat) {
			cout << "\nAlphabet already present\n\n";
			system("pause");
		}
	}

	system("pause");

}

// GameWin function defintion
void GameWin() {

	system("cls");
	cout << endl << "You Win !" << endl << endl;
	cout << R"(  ___    ___ ________  ___  ___                        
 |\  \  /  /|\   __  \|\  \|\  \                       
 \ \  \/  / | \  \|\  \ \  \\\  \                      
  \ \    / / \ \  \\\  \ \  \\\  \                     
   \/  /  /   \ \  \\\  \ \  \\\  \                    
 __/  / /      \ \_______\ \_______\                   
|\___/ /        \|_______|\|_______|                   
\|___|/                                                
                                                       
                                                       
 ___       __   ________  ________           ___       
|\  \     |\  \|\   __  \|\   ___  \        |\  \      
\ \  \    \ \  \ \  \|\  \ \  \\ \  \       \ \  \     
 \ \  \  __\ \  \ \  \\\  \ \  \\ \  \       \ \  \    
  \ \  \|\__\_\  \ \  \\\  \ \  \\ \  \       \ \__\   
   \ \____________\ \_______\ \__\\ \__\       \|__|   
    \|____________|\|_______|\|__| \|__|           ___ 
                                                  |\__\
                                                  \|__|)" << "\n\n";
	cout << "\nPress any key to continue to main Menu." << endl << endl;
	system("pause");
	StartMenu();

}