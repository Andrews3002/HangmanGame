#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>

using namespace std;



int main ()
{
	ifstream File;
	char guessWord[50], guess, prevguess[50], guesses[50];
	string words[30], categories[30], category, wordpool[30], usedwords[30], wordDisplay, currWord, rematch, wordholder, name, guessW;
	int count, count2 = 0, randomnum, size, count3, errors, count4 = -1, score = 0, count5, count6 = -1;
	bool used, correct, solved, exitsolved, categExist, exhausted;
	
	
	
	File.open("words.txt");
	
	if (File.is_open() != true){
		cout << "Error opening words file...... aborting" << endl;
		exit(1);
	}
	
// ENTERS ALL THE DATA FROM THE FILE INTO AN ARRAY FOR WORDS AND AN ARRAY FOR CATEGORIES.
	for (int i=0; i<=24; i++){
		File>>words[i];
		File>>categories[i];
	}
	
	
	rematch = "yes";
	
	cout << "Enter your name: ";
	getline(cin, name);
	cout << endl;
	
	while (rematch == "yes"){	
	
		categExist = false;
		count = -1;
		count4 = -1;
		exitsolved = false;
		errors = 0;
		used = true;
		exhausted = false;
		count5 = 0;
	
	
		while (categExist == false){
			cout << endl;
			cout << "						HANGMAN																				" << endl;
			cout << "===============================================================================================================" << endl;
			cout << "categories to chose from: science, animal, food, country, insect, palindrome, spice, feelings, cooking, reptile" << endl << endl;
	
			cout << "Enter a category: ";
			cin >> category;
			cout << endl;
	
	
	
// FINDS THE WORDS ASSOSSIATED TO YOUR CATEGORY AND MAKES AN ARRAY OF THOSE WORDS IN A WORD POOL
			for (int i=0; i<=24; i++){
		
				if(categories[i] == category){
					count++;
					wordpool[count] = words[i];
				}
		
			}
			
			if (count == -1)
			{
				cout << "error,... "<< category << " is not a category" << endl;
				categExist = false;
			}
			else
			{
				categExist = true;
			}
			
		}
		
		
		
		// ENSURE THAT WORDS IN THE WORD POOL ARE NOT REPEATED
		
		for (int i=0; i<=count; i++){
			for(int o=0; o<count2; o++){
				if (wordpool[i] != usedwords[o]){
					exhausted = false;
				}
				else
				{
					exhausted = true;
					break;
				}
			}
			if (exhausted == false){
				break;
			}
		}
			
		if (exhausted == true){
			cout << "There are no words left in this category to guess, please select another....." << endl << endl;
			continue;
		}
		
		
		while (used == true){
			
			randomnum = rand() %(count+1);
			
			for (int o = 0; o<= count2; o++){
				if (wordpool[randomnum] == usedwords[o])
				{
					used = true;
					break;
				}
				else
				{
					used = false;
				} 
			}
		}	
		
	
 
// CONVERTS THE WORD IN THE WORDPOOL TO A CHARACTER ARRAY OF LOWERCASE LETTERS
		
		wordholder = wordpool[randomnum];
		usedwords[count2] =	wordholder;
		count2++;
		currWord = wordpool[randomnum];
 		wordDisplay = currWord;
 		size = currWord.length();
 
 		for (int i=0; i<size; i++){
 	
 			guessWord[i] = currWord[i];
 			if((guessWord[i] < 'a') && (guessWord[i] > 'z')){
 				guessWord[i] = guessWord[i] + 32;
	 		}
 		}	
 			
		guessWord[size] = NULL;
 
// USES THE CHAR ARRAY OF LOWERCASE LETTERS TO CREATE THE WORD DISPLAYED ON THE MONITOR WITH "R,S,T,L,N,E" BEING ITS ONLY SHOWN LETTERS
		for (int i=0; i<size; i++){
			if(guessWord[i] == 'r'){
				wordDisplay[i] = 'R';	
			} 
			else if(guessWord[i] == 's'){
				wordDisplay[i] = 'S';	
			}
			else if(guessWord[i] == 't'){
				wordDisplay[i] = 'T';	
			}
			else if(guessWord[i] == 'l'){
				wordDisplay[i] = 'L';	
			}
			else if(guessWord[i] == 'n'){
				wordDisplay[i] = 'N';	
			}
			else if(guessWord[i] == 'e'){
				wordDisplay[i] = 'E';	
			}
			else 
			{
				wordDisplay[i] = '_';
			}	
		}

// THE DISPLAY OF THE HANGMAN GAME ITSELF WITH ALL ITS FUNCTIONALITIES
		
		cout << endl;
		cout << "Try to fill in the blank spaces" << endl;
	
		while (errors <= 6){
		
			if (errors == 6){
			cout <<  
			" ____   " << endl <<
			" |   O	 " << endl <<
			" |  -|- " << endl <<
	 		"_|_ | | " << endl;
			}
			else if (errors == 5){
			cout << 
			" ____  " << endl <<
			" |   O	" << endl <<
			" |  -|-" << endl <<
	 		"_|_ |  " << endl;
			}
			else if (errors == 4){
			cout <<  
			" ____  " << endl <<
			" |   O	" << endl <<
			" |  -|-" << endl <<
	 		"_|_    " << endl;
			}
			else if (errors == 3){
			cout <<  
			" ____  " << endl <<
			" |   O	" << endl <<
			" |  -| " << endl <<
	 		"_|_    " << endl;
			}
			else if (errors == 2){
			cout <<  
			" ____  " << endl <<
			" |   O	" << endl <<
			" |   | " << endl <<
	 		"_|_    " << endl;
			}
			else if (errors == 1){
			cout <<  
			" ____  " << endl <<
			" |   O " << endl <<
			" |     " << endl <<
	 		"_|_    " << endl;
			}
			else if (errors == 0){
			cout << 
			" ____  " << endl <<
			" |     " << endl <<
			" |     " << endl <<
	 		"_|_    " << endl;
			}
			
			cout << endl;
			cout << wordDisplay << endl; 
			
			cout << endl;
		
			cout << "you have guessed: ";
			for (int o=0; o<=count4; o++){
			cout << guesses[o] << " ";
			}
			cout << endl << endl;
		
			
			if (exitsolved == true){
				cout << endl;
				cout << "Congadulations! " << name << " you have solved the word. Your score is: " << score << endl;
				cout << endl;
				cout << "enter 'yes' if you would like to play again and 'no' if not: ";
				cin >> rematch;
				
				for (int o=0; o<=count4; o++){
					guesses[o] = NULL;
				}
		
				break;
				
			}
			else if (errors == 6){
				score = score-2;
				cout << endl;
				cout << "Sorry " << name << ", you have failed to solve the word. Your score is: " << score << endl;
				cout << "The word was : " << guessWord << endl;
				cout << endl;
				cout << "enter 'yes' if you would like to play again and 'no' if not: ";
				cin >> rematch;
				
				for (int o=0; o<=count4; o++){
					guesses[o] = NULL;
				}
		
				break;
				
				
			}
			
			cout << "OPTIONAL: You can enter '#' to attempt guessing the entire word at the risk of losing more points" << endl;
			cout << endl;
			cout << "			Lives: " << 6-errors << "				score: " << score << endl << endl;
			cout << "Guess a letter: ";
			cin >> guess;
		
			if (guess != '#'){
				count4++;
				guesses[count4] = guess;
			}
			else if (guess == '#')
			{
				cout << "Enter word: ";
				cin>> guessW;
				cout << endl;
				
				if(guessW == currWord){
					
					for (int i=0; i<=size; i++){
						if(wordDisplay[i] == '_'){
							count5++;
						}
					}
					
					if (count5 >= 2){
						score = score+4;
					}
					else
					{
						score = score + 2;	
					}
			
					exitsolved = true;
					
					wordDisplay = currWord;
					
					for (int i=0; i<size; i++){
						
						if (wordDisplay[i] == 'r') 
						{
							wordDisplay[i] = 'R';
						}
						else if (wordDisplay[i] == 's') 
						{
							wordDisplay[i] = 'S';
						}
						else if (wordDisplay[i] == 't') 
						{
							wordDisplay[i] = 'T';
						}
						else if (wordDisplay[i] == 'l') 
						{
							wordDisplay[i] = 'L';
						}
						else if (wordDisplay[i] == 'n') 
						{
							wordDisplay[i] = 'N';
						}
						else if (wordDisplay[i] == 'e') 
						{
							wordDisplay[i] = 'E';
						}
					}
					
					continue;
				}
				else
				{
					cout << endl << "The word you guessed was wrong try again" << endl << endl;
					if(errors == 3){
						errors = errors + 3;
					}
					else if (errors == 4)
					{
						errors = errors + 2;
					}
					else if (errors == 5){
						errors = errors + 1;
					}
					else
					{
						errors = errors + 2;
					}
					
					continue;
				}
			}
			
			correct = false;
			solved = true;
		
			for (int o=0; o<size; o++){
				if ((guess == wordDisplay[o]) || (guess-32 == wordDisplay[o])){
					cout << "This letter is already shown" << endl << endl;
					correct = true;
					break;
				}	
			}
			
			for (int o=0; o<count4; o++){
				if (guesses[o] == guess){
					cout << "You have already guessed this letter" << endl << endl;
					correct = true;
					count4--;
					break;
				}	
			}
		
			for (int i=0; i<size; i++){
				if ((guess == guessWord[i]) && (guess != 'r') && (guess != 's') && (guess != 't') && (guess != 'l') && (guess != 'n') && (guess != 'e'))
				{
					wordDisplay[i] = guess;
					score++;
					correct = true;
				}
			}
		
			if (correct == false){
				cout << "wrong guess try again" << endl << endl;
				errors++;
			}
		
			for (int o=0; o<size; o++){
				if (wordDisplay[o] == '_'){
					solved = false;
					exitsolved = false;
					break;
				}
				else
				{
					exitsolved = true;
				}
			}	
		}
		
	
		
	}
	
	File.close();

	return 0;	
	
}
	

