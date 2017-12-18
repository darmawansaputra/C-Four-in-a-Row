#include <iostream>
using namespace std;

char winner = ' ';
char map[13][19] = {
	{"[=^=^=^=^=^=^=^=]"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"<=#=#=#=#=#=#=#=>"},
	{"| | | | | | | | |"},
	{"(=%=%=%=%=%=%=%=)"}
};
//M, then K
char currentTurn = 'M';

bool isEnd();
void printMap();
bool fillMap(int selected);

main() {
	//Variable to store user input column
	int selected;
	
	while(!isEnd()) {
		//Clear screen
		system("cls");
		
		//print current map
		printMap();
		
		//Ouput and input
		cout<<"Giliran pemain ";
		if(currentTurn == 'M')
			cout<<"Merah";
		else
			cout<<"Kuning";
		cout<<endl;
		
		while(1) {
			cout<<"Masukkan kolom: ";
			cin>>selected;
			
			if(fillMap(selected))
				break;
				
			cout<<"\nInput kolom yang anda masukkan tidak valid!\n";
		}
		
		//Change current turn to another player
		currentTurn = currentTurn == 'M' ? 'K' : 'M';
	}
	
	//Clear screen and print map
	system("cls");
	printMap();
	
	//Who is the winner guys?
	cout<<"\n\n=== Selamat Pemenangnya adalah pemain ";
	if(winner == 'M')
		cout<<"Merah";
	else
		cout<<"Kuning";
	cout<<" ===";
}

//Implement of printMap() function
void printMap() {
	for(int i = 0; i < 13; i++) {
		for(int j = 0; j < 19; j++){
			char t = map[i][j];
			
			if(t == '=')
				cout<<char(205);
			else if(t == '|')
				cout<<char(186);
			else if(t == '#')
				cout<<char(206);
			else if(t == '^')
				cout<<char(203);
			else if(t == '<')
				cout<<char(204);
			else if(t == '>')
				cout<<char(185);
			else if(t == '%')
				cout<<char(202);
			else if(t == '[')
				cout<<char(201);
			else if(t == ']')
				cout<<char(187);
			else if(t == '(')
				cout<<char(200);
			else if(t == ')')
				cout<<char(188);
			else
				cout<<t;
		}
		cout<<endl;
	}
}

//Implement of fillMap() function
bool fillMap(int s) {
	//If out of range or column is full
	if(s < 1 || s > 8 || map[1][s * 2 - 1] != ' ')
		return false;
		
	//You can fill map now!!
	for(int i = 11; i >= 1; i-=2) {
		if(map[i][s * 2 - 1] == ' ') {
			map[i][s * 2 - 1] = currentTurn;
			break;
		}
	}
	
	return true;
}

//Implement of isEnd() function
bool isEnd() {
	int count;
	char symbol;
	bool status = false;
	
	//Checking process
	for(int i = 1; i <= 11; i+=2) {
		for(int j = 1; j <= 15; j+=2) {
			//Reset count variable
			count = 1;
			
			//If cell is space
			if(map[i][j] == ' ')
				continue;
			
			//Assign the symbol to variable
			symbol = map[i][j];
			
			//Horizontal right style
			for(int k = j + 2; k <= 15; k+=2) {
				//If not same
				if(map[i][k] != symbol)
					break;	

				count++; //Increment the count variable
			}
			
			//Check the winner with horizontal right style solving
			if(count >= 4) {
				winner = symbol;
				break;
			}
		}
		
		if(winner != ' ')
			break;
	}
	
	//Ternary operation
	return winner == ' ' ? false : true;
}
