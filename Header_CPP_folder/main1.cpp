#include <string>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "Passing.h"
#include "Rushing.h"
#include "Receiving.h"
#include "Defense.h"

//#include all the header files up here when youre ready SamHap
using namespace std;

void teamCheck(const string teamname, ifstream &filein);					//remove Team names from all vector containers Sam Hap
void removeTeamPasser(vector<Passing *> &passerContainer);					//for ex: teamname "NewEnglandPatriots" would get removed
void removeTeamRunner(vector<Rushing *> &rusherContainer);
void removeTeamReceiver(vector<Receiving *> &receiverContainer);
void removeTeamDefense(vector<Defense *> &defenseContainer);

bool sortPassingAttempts(Passing *a, Passing *b);							//used for std::sort on stat values for Passer Container Hap
bool sortPassingCompletions(Passing *a, Passing *b);
bool sortPassingYards(Passing *a, Passing *b);
bool sortPassingTouchdowns(Passing *a, Passing *b);
bool sortPassingInterceptions(Passing *a, Passing *b);
bool sortPassingLongestGain(Passing *a, Passing *b);
bool sortPassingSack(Passing *a, Passing *b);
bool sortPassingTFL(Passing *a, Passing *b);
bool sortPassingCompletionPercentage(Passing *a, Passing *b);
bool sortPassingYPA(Passing *a, Passing *b);
bool sortPassingTDP(Passing *a, Passing *b);
bool sortPassingINTP(Passing *a, Passing *b);
bool sortPassingPasserRating(Passing *a, Passing *b);

bool sortRushingGames(Rushing *a, Rushing *b);								//used for std::sort on stat values for Rusher Container
bool sortRushingAttempts(Rushing *a, Rushing *b);
bool sortRushingYards(Rushing *a, Rushing *b);
bool sortRushingAvgYardsPerCarry(Rushing *a, Rushing *b);
bool sortRushingYardsPerGame(Rushing *a, Rushing *b);
bool sortRushingLongestGain(Rushing *a, Rushing *b);
bool sortRushingTouchdowns(Rushing *a, Rushing *b);
bool sortRushingFirstDowns(Rushing *a, Rushing *b);

bool sortReceivingGames(Receiving *a, Receiving *b);						//used for std::sort on stat values for Receiving Container
bool sortReceivingReceptions(Receiving *a, Receiving *b);
bool sortReceivingYards(Receiving *a, Receiving *b);
bool sortReceivingAvgYards(Receiving *a, Receiving *b);
bool sortReceivingYPG(Receiving *a, Receiving *b);
bool sortReceivingLongestGain(Receiving *a, Receiving *b);
bool sortReceivingTouchdowns(Receiving *a, Receiving *b);
bool sortReceivingFirstdowns(Receiving *a, Receiving *b);
bool sortReceivingTargets(Receiving *a, Receiving *b);
bool sortReceivingYAC(Receiving *a, Receiving *b);

bool sortDefenseInterceptions(Defense *a, Defense *b);						//used for std::sort on stat values for Defense Container
bool sortDefenseTouchdowns(Defense *a, Defense *b);
bool sortDefenseSoloTack(Defense *a, Defense *b);
bool sortDefenseAssisTack(Defense *a, Defense *b);
bool sortDefenseTotalTack(Defense *a, Defense *b);
bool sortDefenseYardsLoss(Defense *a, Defense *b);



int main()
{
	string filename;
	string player_type[20];
	ifstream filein;

	string Position;
	string firstname, lastname, teamname;
	string garbage, choice, pause, endTeamName;
	int attempts, completions, yards, yards_adder, touchdowns, interceptions,
		LongestGain, sack, TFL, firstdowns, games, receptions, targets, YAC, soloTac, assTac, totTac;
	double percentage, YPA, TDP, INTP, PasserRating, avgYPC, YPG, average, specialCase, defsack, yardsLoss;
	char comma, letter;
	int loopcount = 0;
	int endInput = 0;

	vector<Passing *> passerContainer;				//create a vector to hold pointers to a Passing object Hap
	vector<Rushing *> rusherContainer;				//create a vector to hold pointers to a Rushing object
	vector<Receiving *> receiverContainer;			//create a vector to hold pointers to a Receiving object
	vector<Defense *> defenseContainer;				//""


	do{

		//cout << "Enter in the name of the text file (.txt):\n";
		cin >> filename;

		filein.open(filename);

		if (filein.is_open())
		{
			//cout << "The file is opened " << endl;
			teamname = filename;

			//cout << "this is the teamname " << teamname << endl;

			for (int i = 0; i < 15; i++)
				getline(filein, garbage);

			do{
				Passing *pas = new Passing;					//create a new Passing object and name it ptr *pas
				 
				getline(filein, garbage, '-');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				getline(filein, firstname, ' ');
				getline(filein, lastname, '\n');

				//cin >> garbage;

				getline(filein, garbage, '\'');						//getline up to '     *for some reason apostrophe is '\'' lol*  SamHap
				filein >> attempts;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> completions;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> percentage;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> yards;

				if (filein.peek() == ','){			//sometimes there's a comma for QB's who don't ride the bench Hap
					filein >> comma;

					yards = yards * 1000;				//to account for comma 
					filein >> yards_adder;				//to get read of total yards number after comma
					yards = yards + yards_adder;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> YPA;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> touchdowns;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> TDP;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> interceptions;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> INTP;
				getline(filein, garbage, '\n');


				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '\''){									//if a QB does not rush for a TD on LongestGain
					getline(filein, garbage, '\'');
					filein >> LongestGain;
				}
				else
					filein >> LongestGain;

				if (filein.peek() == 't')				//if a QB rushes for a TD on their longestGain
					filein >> letter;					//a 't' will appear proceeding the amount of yards they gained

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> sack;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> TFL;
				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> PasserRating;

					//	cout << "This is firstname " << firstname << endl;				//Test Statements Sam Hap
					//	cout << "This is lastname " << lastname << endl;
					//	cout << "this is garbage " << garbage << endl;
					//	cout << "This is attempts " << attempts << endl;
					//	cout << "this is completions " << completions << endl;
					//	cout << "this is percentage " << percentage << endl;
					//	cout << "this is yards " << yards << endl;
					//	cout << "this is yards per attempts " << YPA << endl;
					//	cout << "this is touchdowns " << touchdowns << endl;
					//	cout << "this is TDP " << TDP << endl;
					//	cout << "this is interceptions " << interceptions << endl;
					//	cout << "this is INTP " << INTP << endl;
					//	cout << "this is longest gain " << LongestGain << endl;
					//	cout << "this is sack " << sack << endl;
					//	cout << "this is TFL " << TFL << endl;
					//	cout << "this is PasserRating " << PasserRating << endl;

				pas->SetFirstName(firstname);
				pas->SetLastName(lastname);
				pas->SetTeamName(teamname);
				pas->SetAttempts(attempts);
				pas->SetCompletions(completions);
				pas->SetCompletionPercentage(percentage);
				pas->SetYards(yards);
				pas->SetYardsPerAttempt(YPA);
				pas->SetTouchdowns(touchdowns);
				pas->SetTouchdownPercentage(TDP);
				pas->SetInterceptions(interceptions);
				pas->SetInterceptionPercentage(INTP);
				pas->SetLongestGain(LongestGain);
				pas->SetSack(sack);
				pas->SetTackleForLoss(TFL);
				pas->SetPasserRating(PasserRating);

				passerContainer.push_back(pas);			//thow the pointer to the passer obj in the vector

			} while ((firstname != "Buffalo\n") && (firstname != "Miami\n") && (firstname != "New") && (firstname != "NY") && (firstname != "Baltimore\n")
				&& (firstname != "Cincinnati\n") && (firstname != "Cleveland\n") && (firstname != "Pittsburgh\n") && (firstname != "Houston\n")
				&& (firstname != "Indianapolis\n") && (firstname != "Jacksonville\n") && (firstname != "Tennessee\n") && (firstname != "Denver\n")
				&& (firstname != "Kansas") && (firstname != "LA") && (firstname != "Oakland\n") && (firstname != "Dallas\n")
				&& (firstname != "Philadelphia\n") && (firstname != "Washington\n") && (firstname != "Chicago\n") && (firstname != "Detroit\n")
				&& (firstname != "Green") && (firstname != "Minnesota\n") && (firstname != "Atlanta\n") && (firstname != "Carolina\n")
				&& (firstname != "Tampa") && (firstname != "Arizona\n") && (firstname != "Los") && (firstname != "Seattle\n")
				&& (firstname != "San"));

			if ((firstname == "New") || (firstname == "NY") || (firstname == "Kansas") || (firstname == "Green")
				|| (firstname == "Tampa") || (firstname == "Los") || (firstname == "LA") || (firstname == "San")){
				getline(filein, garbage);				//Due the the fact the New England patriots spans 3 lines
				getline(filein, garbage);				//additional getline statements are needed
				getline(filein, garbage);
			}
			else if ((firstname == "Cleveland\n") || (firstname == "Tennessee\n") || (firstname == "Seattle\n")
				|| (firstname == "Buffalo\n") || (firstname == "Washington\n") || (firstname == "Arizona\n")){
				getline(filein, garbage);
			}

		//	cout << "we left the loop !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! " << endl;

			for (int i = 0; i < 26; i++){									//collect garbage until next type of player (rb, wr, or def)
				getline(filein, garbage);
				//cout << "this is garbage " << garbage << endl;
			}

			do{
				Rushing *rush = new Rushing;				//create new Rushing object ptr

				getline(filein, garbage, '-');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				getline(filein, firstname, ' ');
				getline(filein, lastname, '\n');
				getline(filein, garbage, '\'');

				if ((garbage == "  - \"--\"\n  - ") || (firstname == "Buffalo\n") || (firstname == "Miami\n") || (firstname == "New")
					|| (firstname == "Baltimore\n") || (firstname == "Cincinnati\n") || (firstname == "Cleveland\n") || (firstname == "Pittsburgh\n")
					|| (firstname == "Houston\n") || (firstname == "Indianapolis\n") || (firstname == "Jacksonville\n") || (firstname == "Tennessee\n")
					|| (firstname == "Denver\n") || (firstname == "Kansas") || (firstname == "LA") || (firstname == "Oakland\n")
					|| (firstname == "Dallas\n") || (firstname == "Philadelphia\n") || (firstname == "Washington\n") || (firstname == "Chicago\n")
					|| (firstname == "Detroit\n") || (firstname == "Minnesota\n") || (firstname == "Atlanta\n") || (firstname == "Carolina\n")
					|| (firstname == "Arizona\n") || (firstname == "Seattle\n"))
				{																//if the player has not played in a game the expected variable is
					games = 0;													//not an integer but a string, this will remove "--" for games played
					filein >> attempts;											//and replace it with a 0
				}
				else{
					filein >> games;

					getline(filein, garbage, '\n');
					getline(filein, garbage, '\'');
					filein >> attempts;
				}

			//	cout << "inside rushing " << endl;
			//	cin >> Position;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> yards;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> yards;
				}

				if (filein.peek() == ','){							//sometimes there's a comma for RB's who don't ride the bench
					filein >> comma;

					yards = yards * 1000;							//to account for comma 
					filein >> yards_adder;							//to get read of total yards number after comma
					yards = yards + yards_adder;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> avgYPC;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> avgYPC;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes

					if (filein.peek() == 45)						//if a running back has not played in a game there will be a "--" instead of 0
						YPG = 0;									//ascii 45 is -
					else
						filein >> YPG;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> YPG;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> LongestGain;
				}
				else if (filein.peek() == '\''){					//if a RB does not rush for a TD on LongestGain
					getline(filein, garbage, '\'');
					filein >> LongestGain;
				}
				else
					filein >> LongestGain;							//a RB whos longest gain isn't a TD has no ' or " preceeding it

				if (filein.peek() == 't')				//if a RB rushes for a TD on their longestGain
					filein >> letter;					//a 't' will appear proceeding the amount of yards they gained

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> touchdowns;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> firstdowns;

				//	cout << "this is firstname " << firstname << endl;
				//	cout << "this is lastname " << lastname << endl;
				//	cout << "This is games played " << games << endl;
				//	cout << "this is attempts " << attempts << endl;
				//	cout << "this is yards " << yards << endl;
				//	cout << "this is avgYPC " << avgYPC << endl;
				//	cout << "this is YPG " << YPG << endl;
				//	cout << "this is longest gain " << LongestGain << endl;
				//	cout << "this is touchdowns " << touchdowns << endl;
				//	cout << "this is firstdowns " << firstdowns << endl;

				rush->SetFirstName(firstname);						//Set all relevant stats
				rush->SetLastName(lastname);
				rush->SetTeamName(teamname);
				rush->SetGames(games);
				rush->SetAttempts(attempts);
				rush->SetYards(yards);
				rush->SetAverageYardsPerCarry(avgYPC);
				rush->SetYardsPerGame(YPG);
				rush->SetLongestGain(LongestGain);
				rush->SetTouchdowns(touchdowns);
				rush->SetFirstDowns(firstdowns);

				rusherContainer.push_back(rush);					//add pointer to container

				for (int i = 0; i < 6; i++)
					getline(filein, garbage);

			} while ((firstname != "Buffalo\n") && (firstname != "Miami\n") && (firstname != "New") && (firstname != "NY") && (firstname != "Baltimore\n")
				&& (firstname != "Cincinnati\n") && (firstname != "Cleveland\n") && (firstname != "Pittsburgh\n") && (firstname != "Houston\n")
				&& (firstname != "Indianapolis\n") && (firstname != "Jacksonville\n") && (firstname != "Tennessee\n") && (firstname != "Denver\n")
				&& (firstname != "Kansas") && (firstname != "LA") && (firstname != "Oakland\n") && (firstname != "Dallas\n")
				&& (firstname != "Philadelphia\n") && (firstname != "Washington\n") && (firstname != "Chicago\n") && (firstname != "Detroit\n")
				&& (firstname != "Green") && (firstname != "Minnesota\n") && (firstname != "Atlanta\n") && (firstname != "Carolina\n")
				&& (firstname != "Tampa") && (firstname != "Arizona\n") && (firstname != "Los") && (firstname != "Seattle\n") && (firstname != "San"));

			//cout << "out of the second loop !!^69699669696969!! " << endl;
			//cin >> garbage;

			if ((firstname == "Los")){
				for (int i = 0; i < 8; i++)							//Extra garbage lines are needed for Los angeles												
					getline(filein, garbage);
			}

			for (int i = 0; i < 28; i++){
				getline(filein, garbage);
				//cout << "this is garbage inside for loop " << garbage << endl;
			}

			do{
				Receiving *rec = new Receiving;				//create a new Receiving obj ptr

				getline(filein, garbage, '-');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				getline(filein, firstname, ' ');
				getline(filein, lastname, '\n');
				getline(filein, garbage, '\'');

				if ((garbage == "  - \"--\"\n  - ") || (firstname == "Buffalo\n") || (firstname == "Miami\n") || (firstname == "New")
					|| (firstname == "Baltimore\n") || (firstname == "Cincinnati\n") || (firstname == "Cleveland\n") || (firstname == "Pittsburgh\n")
					|| (firstname == "Houston\n") || (firstname == "Indianapolis\n") || (firstname == "Jacksonville\n") || (firstname == "Tennessee\n")
					|| (firstname == "Denver\n") || (firstname == "Kansas") || (firstname == "LA") || (firstname == "Oakland\n")
					|| (firstname == "Dallas\n") || (firstname == "Philadelphia\n") || (firstname == "Washington\n") || (firstname == "Chicago\n")
					|| (firstname == "Detroit\n") || (firstname == "Minnesota\n") || (firstname == "Atlanta\n") || (firstname == "Carolina\n")
					|| (firstname == "Arizona\n") || (firstname == "Seattle\n"))
				{																//if the player has not played in a game the expected variable is
					games = 0;													//not an integer but a string, this will remove "--" for games played
					filein >> receptions;										//and replace it with a 0
				}
				else
				{
					filein >> games;
					getline(filein, garbage, '\n');
					getline(filein, garbage, '\'');
					filein >> receptions;
				}

				//cout << "inside recievers " << endl;
				//cin >> Position;



				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes WR's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> yards;
				}
				else
				{
					getline(filein, garbage, '\'');
					filein >> yards;
					if (filein.peek() == ','){							//sometimes there's a comma in yards for WR's who don't ride the bench
						filein >> comma;

						yards = yards * 1000;							//to account for comma 
						filein >> yards_adder;							//to get read of total yards number after comma
						yards = yards + yards_adder;
					}
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes WR's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> average;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> average;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes WR's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes

					if (filein.peek() == 45)						//if a running back has not played in a game there will be a "--" instead of 0
						YPG = 0;									//ascii 45 is -
					else
						filein >> YPG;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> YPG;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> LongestGain;
				}
				else if (filein.peek() == '\''){									//if a WR does not rush for a TD on LongestGain
					getline(filein, garbage, '\'');
					filein >> LongestGain;
				}
				else
					filein >> LongestGain;

				if (filein.peek() == 't')				//if a WR rushes for a TD on their longestGain
					filein >> letter;					//a 't' will appear proceeding the amount of yards they gained


				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> touchdowns;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> firstdowns;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> targets;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');

				if (filein.peek() == '"'){							//sometimes RB's are so bad they rush for negative yards
					getline(filein, garbage, '"');					//so instead of the usual format it changes
					filein >> YAC;
				}
				else{
					getline(filein, garbage, '\'');
					filein >> YAC;
					if (filein.peek() == ','){							//sometimes there's a comma in yards for WR's who don't ride the bench
						filein >> comma;

						YAC = YAC * 1000;							//to account for comma 
						filein >> yards_adder;							//to get read of total yards number after comma
						YAC = YAC + yards_adder;
					}
				}


				rec->SetFirstName(firstname);
				rec->SetLastName(lastname);
				rec->SetTeamName(teamname);
				rec->SetGames(games);
				rec->SetReceptions(receptions);
				rec->SetYards(yards);
				rec->SetAverageYards(average);
				rec->SetYardsPerGame(YPG);
				rec->SetLongestGain(LongestGain);
				rec->SetTouchdowns(touchdowns);
				rec->SetFirstDowns(firstdowns);
				rec->SetTargets(targets);
				rec->SetYardsAfterCatch(YAC);

				receiverContainer.push_back(rec);					//add pointer to container

					//	cout << "this is firstname " << firstname << endl;
					//	cout << "this is lastname " << lastname << endl;
					//	cout << "this is games " << games << endl;
					//	cout << "this is receptions " << receptions << endl;
					//	cout << "this is yards " << yards << endl;
					//	cout << "this is average " << average << endl;
					//	cout << "this is  YPG " << YPG << endl;
					//	cout << "this is longest gain " << LongestGain << endl;
					//	cout << "this is touchdowns " << touchdowns << endl;
					//	cout << "this is firstdowns " << firstdowns << endl;
					//	cout << "this is targets " << targets << endl;
					//	cout << "this is YAC " << YAC << endl;

				for (int i = 0; i < 4; i++)
					getline(filein, garbage);

			} while ((firstname != "Buffalo\n") && (firstname != "Miami\n") && (firstname != "New") && (firstname != "NY") && (firstname != "Baltimore\n")
				&& (firstname != "Cincinnati\n") && (firstname != "Cleveland\n") && (firstname != "Pittsburgh\n") && (firstname != "Houston\n")
				&& (firstname != "Indianapolis\n") && (firstname != "Jacksonville\n") && (firstname != "Tennessee\n") && (firstname != "Denver\n")
				&& (firstname != "Kansas") && (firstname != "LA") && (firstname != "Oakland\n") && (firstname != "Dallas\n")
				&& (firstname != "Philadelphia\n") && (firstname != "Washington\n") && (firstname != "Chicago\n") && (firstname != "Detroit\n")
				&& (firstname != "Green") && (firstname != "Minnesota\n") && (firstname != "Atlanta\n") && (firstname != "Carolina\n")
				&& (firstname != "Tampa") && (firstname != "Arizona\n") && (firstname != "Los") && (firstname != "Seattle\n") && (firstname != "San"));

			//cout << "END of the third loop !!!!!!!!!!!!!!!!!!! YAHOHAOH" << endl;

			teamCheck(teamname, filein);

			//cout << "this is team name " << teamname << endl;
			//cout << "inside defence " << endl;


			do{
				Defense *def = new Defense;					//create a new Defense obj ptr

				getline(filein, garbage, '-');
				getline(filein, garbage, '-');
				getline(filein, garbage, ' ');
				getline(filein, firstname, ' ');
				getline(filein, lastname, '\n');
				getline(filein, garbage, '\'');
				filein >> interceptions;


			//	cin >> Position;

				getline(filein, garbage);					//get newline
				getline(filein, garbage);					//we dont care about defensive touchdowns
				getline(filein, garbage);					//we dont care about average yards
				getline(filein, garbage);					//we dont care about longest gain

				getline(filein, garbage, '\'');
				filein >> touchdowns;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> soloTac;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> assTac;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> totTac;

				if (filein.peek() == ','){							//will usually be > 1000 for whole team stats				
					filein >> comma;

					totTac = totTac * 1000;							//to account for comma 
					filein >> yards_adder;							//to get read of total yards number after comma
					totTac = totTac + yards_adder;
				}

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> defsack;

				getline(filein, garbage, '\n');
				getline(filein, garbage, '\'');
				filein >> yardsLoss;
				
				//		cout << "this is firstname " << firstname << endl;
				//		cout << "this is lastname " << lastname << endl;
				//		cout << "this is interceptions " << interceptions << endl;
					//	cout << "this is touchdowns " << touchdowns << endl;
				//		cout << "this is solo tackles " << soloTac << endl;
				//		cout << "this is assisted tackles " << assTac << endl;
				//		cout << "this is total tackles " << totTac << endl;
				//		cout << "this is defensive sack " << defsack << endl;
				//		cout << "this is yards loss " << yardsLoss << endl;

				def->SetFirstName(firstname);
				def->SetLastName(lastname);
				def->SetTeamName(teamname);
				def->SetInterceptions(interceptions);
				def->SetTouchdowns(touchdowns);
				def->SetSoloTackles(soloTac);
				def->SetAssistedTackles(assTac);
				def->SetTotalTackles(totTac);
				def->SetTackleForLossYds(yardsLoss);

				defenseContainer.push_back(def);						//add defense object to the container

				for (int i = 0; i < 4; i++)
					getline(filein, garbage);

			} while ((firstname != "Buffalo\n") && (firstname != "TeamTeam\n") && (firstname != "New") && (firstname != "NY") && (firstname != "Baltimore\n")
				&& (firstname != "Cincinnati\n") && (firstname != "Cleveland\n") && (firstname != "Pittsburgh\n") && (firstname != "Houston\n")
				&& (firstname != "Indianapolis\n") && (firstname != "Jacksonville\n") && (firstname != "LA") && (firstname != "Oakland\n")
				&& (firstname != "Washington\n") && (firstname != "Chicago\n") && (firstname != "Detroit\n") && (firstname != "Minnesota\n")
				&& (firstname != "Atlanta\n") && (firstname != "Carolina\n") && (firstname != "Tampa") && (firstname != "Seattle\n")
				&& (firstname != "Miami\n") && (firstname != "Tennessee\n") && (firstname != "Denver\n") && (firstname != "Kansas")
				&& (firstname != "Dallas\n") && (firstname != "Philadelphia\n") && (firstname != "Green") && (firstname != "Arizona\n")
				&& (firstname != "San"));


			filein.close();

			//cout << "We made it through the " << teamname << " roster, fuck yeah br0 " << endl;



			/*
			cout << "\nThese are the Quarterbacks for the " << teamname << endl;

			for (unsigned int i = 0; i < passerContainer.size(); i++){
				cout << passerContainer[i]->GetFirstName();
				cout << passerContainer[i]->GetLastName();
				cout << endl;
			}

			cout << "\nThese are the rushers for the " << teamname << endl;

			for (unsigned int i = 0; i < rusherContainer.size(); i++){
				cout << rusherContainer[i]->GetFirstName();
				cout << rusherContainer[i]->GetLastName();
				cout << endl;
			}

			cout << "\nThese are the recievers for the " << teamname << endl;

			for (unsigned int i = 0; i < receiverContainer.size(); i++){
				cout << receiverContainer[i]->GetFirstName();
				cout << receiverContainer[i]->GetLastName();
				cout << endl;
			}

			cout << "\nThese are the defensive players for the " << teamname << endl;

			for (unsigned int i = 0; i < defenseContainer.size(); i++){
				cout << defenseContainer[i]->GetFirstName();
				cout << defenseContainer[i]->GetLastName();
				cout << endl;
			}*/
		}
		

		endInput = 1;

		if (teamname == "washingtonRedskins.txt")
			endInput = 0;


	} while (endInput == 1);

	//cout << "DONE" << endl;
	//cout << "Gathered all the data " << endl;



	//***********************************************TESTING PASSER CONTAINER REMOVE****************************


	//	for (int i = 0; i < passerContainer.size(); i++)						
	//	{
	//		cout << "This is passerContainer[" << i << "] and this is the name of the player " << passerContainer[i]->GetFirstName() << endl;
	//	}

	//cout << "testing the remove teamname fucntion " << endl;
	removeTeamPasser(passerContainer);
	//cout << "remove team test over" << endl;

	//	for (int i = 0; i < passerContainer.size(); i++)
	//	{
	//		cout << "This is passerContainer[" << i << "] and this is the name of the player " << passerContainer[i]->GetFirstName() << endl;
	//	}

	//***********************************************TESTING RUSHER CONTAINER REMOVE****************************
	//	for (int i = 0; i < rusherContainer.size(); i++)
	//	{
	//		cout << "This is rusherContainer[" << i << "] and this is the name of the player " << rusherContainer[i]->GetFirstName() << endl;
	//	}

//	cout << "testing the remove teamname fucntion " << endl;
	removeTeamRunner(rusherContainer);
//	cout << "remove team test over" << endl;

	//	for (int i = 0; i < rusherContainer.size(); i++)
	//	{
	//		cout << "This is rusherContainer[" << i << "] and this is the name of the player " << rusherContainer[i]->GetFirstName() << endl;
	//	}
	//***********************************************TESTING RECEIVER CONTAINER REMOVE****************************

	//	for (int i = 0; i < receiverContainer.size(); i++)
	//	{
	//		cout << "This is receiverContainer[" << i << "] and this is the name of the player " << receiverContainer[i]->GetFirstName() << endl;
	//	}

//	cout << "testing the remove teamname fucntion " << endl;
	removeTeamReceiver(receiverContainer);
//	cout << "remove team test over" << endl;

	//	for (int i = 0; i < receiverContainer.size(); i++)
	//	{
	//		cout << "This is receiverContainer[" << i << "] and this is the name of the player " << receiverContainer[i]->GetFirstName() << endl;
	//	}

	//***********************************************TESTING DEFENSE CONTAINER REMOVE****************************
	//	for (int i = 0; i < defenseContainer.size(); i++)
	//	{
	//		cout << "This is defenseContainer[" << i << "] and this is the name of the player " << defenseContainer[i]->GetFirstName() << endl;
	//	}

//	cout << "testing the remove teamname fucntion " << endl;
	removeTeamDefense(defenseContainer);
//	cout << "remove team test over" << endl;

	//	for (int i = 0; i < defenseContainer.size(); i++)
	//	{
	//		cout << "This is defenseContainer[" << i << "] and this is the name of the player " << defenseContainer[i]->GetFirstName() << endl;
	//	}
	

	//*************************************************SORTING QB STATS FROM BEST TO WORST **********************************************
//	cout << "testing the sort by order of QB completions in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingCompletions);		//sort Completions from best to worst 
//	cout << "sort complete" << endl;														//calls a function "sortPassingCompletions"

//	for (int i = 0; i < passerContainer.size(); i++)					//display QB name
//	{
//		cout << i <<", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : completions = " << passerContainer[i]->GetCompletions() << endl;
//	}

	int QB_rank = 1;

	for (int i = 0; i < passerContainer.size() -1; i++)					//offset the rank by 1, ex: passerContainer[0] = rank 1, not rank 0 
	{
		if (passerContainer[i]->GetCompletions() == passerContainer[i + 1]->GetCompletions())
			passerContainer[i]->SetCompletionsRank(QB_rank);
		else
		{
			passerContainer[i]->SetCompletionsRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetCompletionsRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)					//final output
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : completions Rank = " << passerContainer[i]->GetCompletionsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;



	
//	cout << "testing the sort by order of QB attempts in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingAttempts);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : attempts = " << passerContainer[i]->GetAttempts() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetAttempts() == passerContainer[i + 1]->GetAttempts())
			passerContainer[i]->SetAttemptsRank(QB_rank);
		else
		{
			passerContainer[i]->SetAttemptsRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetAttemptsRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : attempts Rank = " << passerContainer[i]->GetAttemptsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of QB yards in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingYards);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Yards = " << passerContainer[i]->GetYards() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetYards() == passerContainer[i + 1]->GetYards())
			passerContainer[i]->SetYardsRank(QB_rank);
		else
		{
			passerContainer[i]->SetYardsRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetYardsRank(QB_rank);
	}
/*
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
			<< " : yards Rank = " << passerContainer[i]->GetYardsRank() << endl;
	}

	cout << endl << endl;
	cout << endl << endl;
	*/

//	cout << "testing the sort by order of QB touchdowns in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingTouchdowns);
//	cout << "sort complete" << endl;
	/*
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
			<< " : touchdowns = " << passerContainer[i]->GetTouchdowns() << endl;
	}
	*/
	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetTouchdowns() == passerContainer[i + 1]->GetTouchdowns())
			passerContainer[i]->SetTouchdownsRank(QB_rank);
		else
		{
			passerContainer[i]->SetTouchdownsRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetTouchdownsRank(QB_rank);
	}
	/*
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
			<< " : touchdowns Rank = " << passerContainer[i]->GetTouchdownsRank() << endl;
	}
	
	cout << endl << endl;
	cout << endl << endl;
	*/

//	cout << "testing the sort by order of QB interceptions in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingInterceptions);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : interceptions = " << passerContainer[i]->GetInterceptions() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetInterceptions() == passerContainer[i + 1]->GetInterceptions())
			passerContainer[i]->SetInterceptionsRank(QB_rank);
		else
		{
			passerContainer[i]->SetInterceptionsRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetInterceptionsRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : interceptions Rank = " << passerContainer[i]->GetInterceptionsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;



//	cout << "testing the sort by order of QB Longest Gain in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingLongestGain);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Longest Gain = " << passerContainer[i]->GetLongestGain() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetLongestGain() == passerContainer[i + 1]->GetLongestGain())
			passerContainer[i]->SetLongestGainRank(QB_rank);
		else
		{
			passerContainer[i]->SetLongestGainRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetLongestGainRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Longest Gain Rank = " << passerContainer[i]->GetLongestGainRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;



//	cout << "testing the sort by order of QB Sacks in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingSack);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Sacks = " << passerContainer[i]->GetSack() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetSack() == passerContainer[i + 1]->GetSack())
			passerContainer[i]->SetSackRank(QB_rank);
		else
		{
			passerContainer[i]->SetSackRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetSackRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Sacks Rank = " << passerContainer[i]->GetSackRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;



//	cout << "testing the sort by order of QB Tackle For loss in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingTFL);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Tackle For loss = " << passerContainer[i]->GetTackleForLoss() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetTackleForLoss() == passerContainer[i + 1]->GetTackleForLoss())
			passerContainer[i]->SetTackleForLossRank(QB_rank);
		else
		{
			passerContainer[i]->SetTackleForLossRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetTackleForLossRank(QB_rank);
	}
/*
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
			<< " : Tackle For loss Rank = " << passerContainer[i]->GetTackleForLossRank() << endl;
	}

	cout << endl << endl;
	cout << endl << endl;
*/

//	cout << "testing the sort by order of QB Completion Percentage in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingCompletionPercentage);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Completion Percentage = " << passerContainer[i]->GetCompletionPercentage() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetCompletionPercentage() == passerContainer[i + 1]->GetCompletionPercentage())
			passerContainer[i]->SetCompletionPercentageRank(QB_rank);
		else
		{
			passerContainer[i]->SetCompletionPercentageRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetCompletionPercentageRank(QB_rank);
	}
	/*
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
			<< " : Completion Percentage Rank = " << passerContainer[i]->GetCompletionPercentageRank() << endl;
	}

	cout << endl << endl;
	cout << endl << endl;
*/


//	cout << "testing the sort by order of QB YPA in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingYPA);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : YPA = " << passerContainer[i]->GetYardsPerAttempt() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetYardsPerAttempt() == passerContainer[i + 1]->GetYardsPerAttempt())
			passerContainer[i]->SetYardsPerAttemptRank(QB_rank);
		else
		{
			passerContainer[i]->SetYardsPerAttemptRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetYardsPerAttemptRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : YPA Rank = " << passerContainer[i]->GetYardsPerAttemptRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;




//	cout << "testing the sort by order of QB touchdown percntage in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingTDP);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : touchdown percntage = " << passerContainer[i]->GetTouchdownPercentage() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetTouchdownPercentage() == passerContainer[i + 1]->GetTouchdownPercentage())
			passerContainer[i]->SetTouchdownPercentageRank(QB_rank);
		else
		{
			passerContainer[i]->SetTouchdownPercentageRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetTouchdownPercentageRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : touchdown percntage Rank = " << passerContainer[i]->GetTouchdownPercentageRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;




//	cout << "testing the sort by order of QB interception percntage in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingINTP);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : interception percntage = " << passerContainer[i]->GetInterceptionPercentage() << endl;
//	}

	QB_rank = 1;

	
	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetInterceptionPercentage() == passerContainer[i + 1]->GetInterceptionPercentage())
			passerContainer[i]->SetInterceptionPercentageRank(QB_rank);
		else
		{
			passerContainer[i]->SetInterceptionPercentageRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetInterceptionPercentageRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : interception percntage Rank = " << passerContainer[i]->GetInterceptionPercentageRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;




//	cout << "testing the sort by order of QB Passer Rating in decending order " << endl;
	std::sort(passerContainer.begin(), passerContainer.end(), sortPassingPasserRating);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Passer Rating = " << passerContainer[i]->GetPasserRating() << endl;
//	}

	QB_rank = 1;

	for (int i = 0; i < passerContainer.size()-1; i++)
	{
		if (passerContainer[i]->GetPasserRating() == passerContainer[i + 1]->GetPasserRating())
			passerContainer[i]->SetPasserRatingRank(QB_rank);
		else
		{
			passerContainer[i]->SetPasserRatingRank(QB_rank);
			QB_rank++;
		}

		if (i == passerContainer.size() - 2)
			passerContainer[i + 1]->SetPasserRatingRank(QB_rank);
	}

//	for (int i = 0; i < passerContainer.size(); i++)
//	{
//		cout << i << ", This is qb name : " << passerContainer[i]->GetFirstName() << " " << passerContainer[i]->GetLastName()
//			<< " : Passer Rating Rank = " << passerContainer[i]->GetPasserRatingRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


	
	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << passerContainer[i]->GetFirstName() << '\t' << passerContainer[i]->GetLastName() << '\t';
		cout << passerContainer[i]->GetAttempts() << '\t';
		cout << passerContainer[i]->GetCompletions() << '\t';
		cout << passerContainer[i]->GetYards() << '\t';
		cout << passerContainer[i]->GetTouchdowns() << '\t';
		cout << passerContainer[i]->GetInterceptions() << '\t';
		cout << passerContainer[i]->GetLongestGain() << '\t';
		cout << passerContainer[i]->GetSackRank() << '\t';
		cout << passerContainer[i]->GetTackleForLoss() << '\t';
		cout << passerContainer[i]->GetCompletionPercentage() << '\t';
		cout << passerContainer[i]->GetYardsPerAttempt() << '\t';
		cout << passerContainer[i]->GetTouchdownPercentage() << '\t';
		cout << passerContainer[i]->GetInterceptionPercentage() << '\t';
		cout << passerContainer[i]->GetPasserRating() << endl;

		//cout << endl << endl;
	}





	for (int i = 0; i < passerContainer.size(); i++)
	{
		cout << passerContainer[i]->GetFirstName() << '\t' << passerContainer[i]->GetLastName() << '\t';
		cout << passerContainer[i]->GetAttemptsRank() << '\t';
		cout << passerContainer[i]->GetCompletionsRank() << '\t';
		cout << passerContainer[i]->GetYardsRank() << '\t';
		cout << passerContainer[i]->GetTouchdownsRank() << '\t';
		cout << passerContainer[i]->GetInterceptionsRank() << '\t';
		cout << passerContainer[i]->GetLongestGainRank() << '\t';
		cout << passerContainer[i]->GetSackRank() << '\t';
		cout << passerContainer[i]->GetTackleForLossRank() << '\t';
		cout << passerContainer[i]->GetCompletionPercentageRank() << '\t';
		cout << passerContainer[i]->GetYardsPerAttemptRank() << '\t';
		cout << passerContainer[i]->GetTouchdownPercentageRank() << '\t';
		cout << passerContainer[i]->GetInterceptionPercentageRank() << '\t';
		cout << passerContainer[i]->GetPasserRatingRank() << endl;

		//cout << endl << endl;
	}
	
	

	//cout << "DONE WITH QB's *********************" << endl;



	//*************************************************SORTING RB STATS FROM BEST TO WORST **********************************************
//	cout << "testing the sort by order of RB games in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingGames);			//sort Games from best to worst 
//	cout << "sort complete" << endl;														//calls a function "sortRushingGames"

//	for (int i = 0; i < rusherContainer.size(); i++)					//display RB name
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : games = " << rusherContainer[i]->GetGames() << endl;
//	}

	int RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)					//offset the rank by 1, ex: rusherContainer[0] = rank 1, not rank 0 
	{
		if (rusherContainer[i]->GetGames() == rusherContainer[i + 1]->GetGames())
			rusherContainer[i]->SetGamesRank(RB_rank);
		else
		{
			rusherContainer[i]->SetGamesRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetGamesRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)					//final output
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : games Rank = " << rusherContainer[i]->GetGamesRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB attempts in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingAttempts);			
//	cout << "sort complete" << endl;														

//	for (int i = 0; i < rusherContainer.size(); i++)					
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : attempts = " << rusherContainer[i]->GetAttempts() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)					
	{
		if (rusherContainer[i]->GetAttempts() == rusherContainer[i + 1]->GetAttempts())
			rusherContainer[i]->SetAttemptsRank(RB_rank);
		else
		{
			rusherContainer[i]->SetAttemptsRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetAttemptsRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)					
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : attempts Rank = " << rusherContainer[i]->GetAttemptsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB yards in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingYards);			
//	cout << "sort complete" << endl;														

//	for (int i = 0; i < rusherContainer.size(); i++)					
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : yards = " << rusherContainer[i]->GetYards() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)					
	{
		if (rusherContainer[i]->GetYards() == rusherContainer[i + 1]->GetYards())
			rusherContainer[i]->SetYardsRank(RB_rank);
		else
		{
			rusherContainer[i]->SetYardsRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetYardsRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)					
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : yards Rank = " << rusherContainer[i]->GetYardsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB LongestGain in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingLongestGain);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : LongestGain = " << rusherContainer[i]->GetLongestGain() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)
	{
		if (rusherContainer[i]->GetLongestGain() == rusherContainer[i + 1]->GetLongestGain())
			rusherContainer[i]->SetLongestGainRank(RB_rank);
		else
		{
			rusherContainer[i]->SetLongestGainRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetLongestGainRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : LongestGain Rank = " << rusherContainer[i]->GetLongestGainRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB touchdowns in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingTouchdowns);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : touchdowns = " << rusherContainer[i]->GetTouchdowns() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)
	{
		if (rusherContainer[i]->GetTouchdowns() == rusherContainer[i + 1]->GetTouchdowns())
			rusherContainer[i]->SetTouchdownsRank(RB_rank);
		else
		{
			rusherContainer[i]->SetTouchdownsRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetTouchdownsRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : touchdowns Rank = " << rusherContainer[i]->GetTouchdownsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB first Downs in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingFirstDowns);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : first Downs = " << rusherContainer[i]->GetFirstDowns() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)
	{
		if (rusherContainer[i]->GetFirstDowns() == rusherContainer[i + 1]->GetFirstDowns())
			rusherContainer[i]->SetFirstDownsRank(RB_rank);
		else
		{
			rusherContainer[i]->SetFirstDownsRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetFirstDownsRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : first Downs Rank = " << rusherContainer[i]->GetFirstDownsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of RB avgYPC in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingAvgYardsPerCarry);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : AVG YPC = " << rusherContainer[i]->GetAverageYardsPerCarry() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)
	{
		if (rusherContainer[i]->GetAverageYardsPerCarry() == rusherContainer[i + 1]->GetAverageYardsPerCarry())
			rusherContainer[i]->SetAverageYardsPerCarryRank(RB_rank);
		else
		{
			rusherContainer[i]->SetAverageYardsPerCarryRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetAverageYardsPerCarryRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : AVG YPC Rank = " << rusherContainer[i]->GetAverageYardsPerCarryRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of RB YPG in decending order " << endl;
	std::sort(rusherContainer.begin(), rusherContainer.end(), sortRushingYardsPerGame);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : YPG = " << rusherContainer[i]->GetYardsPerGame() << endl;
//	}

	RB_rank = 1;

	for (int i = 0; i < rusherContainer.size()-1; i++)
	{
		if (rusherContainer[i]->GetYardsPerGame() == rusherContainer[i + 1]->GetYardsPerGame())
			rusherContainer[i]->SetYardsPerGameRank(RB_rank);
		else
		{
			rusherContainer[i]->SetYardsPerGameRank(RB_rank);
			RB_rank++;
		}

		if (i == rusherContainer.size() - 2)
			rusherContainer[i + 1]->SetYardsPerGameRank(RB_rank);
	}

//	for (int i = 0; i < rusherContainer.size(); i++)
//	{
//		cout << i << ", This is rb name : " << rusherContainer[i]->GetFirstName() << " " << rusherContainer[i]->GetLastName()
//			<< " : YPG Rank = " << rusherContainer[i]->GetYardsPerGameRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

	
	for (int i = 0; i < rusherContainer.size(); i++)
	{
		cout << rusherContainer[i]->GetFirstName() << '\t' << rusherContainer[i]->GetLastName() << '\t';
		cout << rusherContainer[i]->GetAttempts() << '\t';
		cout << rusherContainer[i]->GetYards() << '\t';
		cout << rusherContainer[i]->GetLongestGain() << '\t';
		cout << rusherContainer[i]->GetTouchdowns() << '\t';
		cout << rusherContainer[i]->GetFirstDowns() << '\t';
		cout << rusherContainer[i]->GetAverageYardsPerCarry() << '\t';
		cout << "\N" << endl;
	}
	



	
	for (int i = 0; i < rusherContainer.size(); i++)
	{
		cout << rusherContainer[i]->GetFirstName() << '\t' << rusherContainer[i]->GetLastName() << '\t';
		cout << rusherContainer[i]->GetAttemptsRank() << '\t';
		cout << rusherContainer[i]->GetYardsRank() << '\t';
		cout << rusherContainer[i]->GetLongestGainRank() << '\t';
		cout << rusherContainer[i]->GetTouchdownsRank() << '\t';
		cout << rusherContainer[i]->GetFirstDownsRank() << '\t';
		cout << rusherContainer[i]->GetAverageYardsPerCarryRank() << '\t';
		cout << rusherContainer[i]->GetYardsPerGameRank() << endl;
	}
	
	//***************************************SORTING WR STATS FROM BEST TO WORST******************************

//	cout << "testing the sort by order of WR games in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingGames);			//sort Games from best to worst 
//	cout << "sort complete" << endl;														//calls a function "sortReceivingGames"

//	for (int i = 0; i < receiverContainer.size(); i++)					//display RB name
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : games = " << receiverContainer[i]->GetGames() << endl;
//	}

	int WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)					//offset the rank by 1, ex: receiverContainer[0] = rank 1, not rank 0 
	{
		if (receiverContainer[i]->GetGames() == receiverContainer[i + 1]->GetGames())
			receiverContainer[i]->SetGamesRank(WR_rank);
		else
		{
			receiverContainer[i]->SetGamesRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetGamesRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)					//final output
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : games Rank = " << receiverContainer[i]->GetGamesRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl; 


//	cout << "testing the sort by order of WR receptions in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingReceptions);			
//	cout << "sort complete" << endl;														

//	for (int i = 0; i < receiverContainer.size(); i++)					
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : receptions = " << receiverContainer[i]->GetReceptions() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)					 
	{
		if (receiverContainer[i]->GetReceptions() == receiverContainer[i + 1]->GetReceptions())
			receiverContainer[i]->SetReceptionsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetReceptionsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetReceptionsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)					
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : receptions Rank = " << receiverContainer[i]->GetReceptionsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of WR yards in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingYards);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : yards = " << receiverContainer[i]->GetYards() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetYards() == receiverContainer[i + 1]->GetYards())
			receiverContainer[i]->SetYardsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetYardsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetYardsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : yards Rank = " << receiverContainer[i]->GetYardsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;


//	cout << "testing the sort by order of WR average yards in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingAvgYards);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : avg yards = " << receiverContainer[i]->GetAverageYards() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetAverageYards() == receiverContainer[i + 1]->GetAverageYards())
			receiverContainer[i]->SetAverageYardsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetAverageYardsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetAverageYardsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : avg yards Rank = " << receiverContainer[i]->GetAverageYardsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR ypg in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingYPG);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : ypg = " << receiverContainer[i]->GetYardsPerGame() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetYardsPerGame() == receiverContainer[i + 1]->GetYardsPerGame())
			receiverContainer[i]->SetYardsPerGameRank(WR_rank);
		else
		{
			receiverContainer[i]->SetYardsPerGameRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetYardsPerGameRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : ypg Rank = " << receiverContainer[i]->GetYardsPerGameRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR ypg in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingLongestGain);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : longest Gain = " << receiverContainer[i]->GetLongestGain() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetLongestGain() == receiverContainer[i + 1]->GetLongestGain())
			receiverContainer[i]->SetLongestGainRank(WR_rank);
		else
		{
			receiverContainer[i]->SetLongestGainRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetLongestGainRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : longest Gain Rank = " << receiverContainer[i]->GetLongestGainRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR touchdowns in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingTouchdowns);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : touchdowns = " << receiverContainer[i]->GetTouchdowns() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetTouchdowns() == receiverContainer[i + 1]->GetTouchdowns())
			receiverContainer[i]->SetTouchdownsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetTouchdownsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetTouchdownsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : touchdowns Rank = " << receiverContainer[i]->GetTouchdownsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR firstdowns in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingFirstdowns);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : firstdowns = " << receiverContainer[i]->GetFirstDowns() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetFirstDowns() == receiverContainer[i + 1]->GetFirstDowns())
			receiverContainer[i]->SetFirstDownsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetFirstDownsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetFirstDownsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : firstdowns Rank = " << receiverContainer[i]->GetFirstDownsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR targets in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingTargets);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : targers = " << receiverContainer[i]->GetTargets() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetTargets() == receiverContainer[i + 1]->GetTargets())
			receiverContainer[i]->SetTargetsRank(WR_rank);
		else
		{
			receiverContainer[i]->SetTargetsRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetTargetsRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : targets Rank = " << receiverContainer[i]->GetTargetsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of WR YAC in decending order " << endl;
	std::sort(receiverContainer.begin(), receiverContainer.end(), sortReceivingYAC);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : YAC = " << receiverContainer[i]->GetYardsAfterCatch() << endl;
//	}

	WR_rank = 1;

	for (int i = 0; i < receiverContainer.size()-1; i++)
	{
		if (receiverContainer[i]->GetYardsAfterCatch() == receiverContainer[i + 1]->GetYardsAfterCatch())
			receiverContainer[i]->SetYardsAfterCatchRank(WR_rank);
		else
		{
			receiverContainer[i]->SetYardsAfterCatchRank(WR_rank);
			WR_rank++;
		}

		if (i == receiverContainer.size() - 2)
			receiverContainer[i + 1]->SetYardsAfterCatchRank(WR_rank);
	}

//	for (int i = 0; i < receiverContainer.size(); i++)
//	{
//		cout << i << ", This is WR name : " << receiverContainer[i]->GetFirstName() << " " << receiverContainer[i]->GetLastName()
//			<< " : yac Rank = " << receiverContainer[i]->GetYardsAfterCatchRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

	
	for (int i = 0; i < receiverContainer.size(); i++)
	{
		cout << receiverContainer[i]->GetFirstName() << '\t' << receiverContainer[i]->GetLastName() << '\t';
		cout << receiverContainer[i]->GetGames() << '\t';
		cout << receiverContainer[i]->GetReceptions() << '\t';
		cout << receiverContainer[i]->GetYards() << '\t';
		cout << receiverContainer[i]->GetAverageYards() << '\t';
		cout << "0" << '\t';
		cout << receiverContainer[i]->GetLongestGain() << '\t';
		cout << receiverContainer[i]->GetTouchdowns() << '\t';
		cout << receiverContainer[i]->GetFirstDowns() << '\t';
		cout << receiverContainer[i]->GetTargets() << '\t';
		cout << receiverContainer[i]->GetYardsAfterCatch() << endl;
	}


	
	for (int i = 0; i < receiverContainer.size(); i++)
	{
		cout << receiverContainer[i]->GetFirstName() << '\t' << receiverContainer[i]->GetLastName() << '\t';
		cout << receiverContainer[i]->GetGamesRank() << '\t';
		cout << receiverContainer[i]->GetReceptionsRank() << '\t';
		cout << receiverContainer[i]->GetYardsRank() << '\t';
		cout << receiverContainer[i]->GetAverageYardsRank() << '\t';
		cout << receiverContainer[i]->GetYardsPerGameRank() << '\t';
		cout << receiverContainer[i]->GetLongestGainRank() << '\t';
		cout << receiverContainer[i]->GetTouchdownsRank() << '\t';
		cout << receiverContainer[i]->GetFirstDownsRank() << '\t';
		cout << receiverContainer[i]->GetTargetsRank() << '\t';
		cout << receiverContainer[i]->GetYardsAfterCatchRank() << endl;
	}
	

	
	//*************************SORTING DEFENSIVE STATS FROM BEST TO WORST***********************

//	cout << "testing the sort by order of Defense interceptions in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseInterceptions);			//sort interceptions from best to worst 
//	cout << "sort complete" << endl;														//calls a function "sortDefenseInterceptions"

//	for (int i = 0; i < defenseContainer.size(); i++)					//display defensive player name
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : interceptions = " << defenseContainer[i]->GetInterceptions() << endl;
//	}

	int Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)					//offset the rank by 1, ex: receiverContainer[0] = rank 1, not rank 0 
	{
		if (defenseContainer[i]->GetInterceptions() == defenseContainer[i + 1]->GetInterceptions())
			defenseContainer[i]->SetInterceptionsRank(Def_rank);
		else
		{
			defenseContainer[i]->SetInterceptionsRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetInterceptionsRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)					//final output
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : interceptions Rank = " << defenseContainer[i]->GetInterceptionsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of Defense touchdowns in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseTouchdowns);			
//	cout << "sort complete" << endl;														

//	for (int i = 0; i < defenseContainer.size(); i++)					
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : touchdowns = " << defenseContainer[i]->GetTouchdowns() << endl;
//	}

	Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)					
	{
		if (defenseContainer[i]->GetTouchdowns() == defenseContainer[i + 1]->GetTouchdowns())
			defenseContainer[i]->SetTouchdownsRank(Def_rank);
		else
		{
			defenseContainer[i]->SetTouchdownsRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetTouchdownsRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)					
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : touchdowns Rank = " << defenseContainer[i]->GetTouchdownsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of Defense solo Tackles in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseSoloTack);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : solo tack = " << defenseContainer[i]->GetSoloTackles() << endl;
//	}

	Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)
	{
		if (defenseContainer[i]->GetSoloTackles() == defenseContainer[i + 1]->GetSoloTackles())
			defenseContainer[i]->SetSoloTacklesRank(Def_rank);
		else
		{
			defenseContainer[i]->SetSoloTacklesRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetSoloTacklesRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : solo Tack Rank = " << defenseContainer[i]->GetSoloTacklesRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of Defense assisted tack in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseAssisTack);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : assis tack = " << defenseContainer[i]->GetAssistedTackles() << endl;
//	}

	Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)
	{
		if (defenseContainer[i]->GetAssistedTackles() == defenseContainer[i + 1]->GetAssistedTackles())
			defenseContainer[i]->SetAssistedTacklesRank(Def_rank);
		else
		{
			defenseContainer[i]->SetAssistedTacklesRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetAssistedTacklesRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : assisted tack Rank = " << defenseContainer[i]->GetAssistedTacklesRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of Defense total tackles in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseTotalTack);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : total tack = " << defenseContainer[i]->GetTotalTackles() << endl;
//	}

	Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)
	{
		if (defenseContainer[i]->GetTotalTackles() == defenseContainer[i + 1]->GetTotalTackles())
			defenseContainer[i]->SetTotalTacklesRank(Def_rank);
		else
		{
			defenseContainer[i]->SetTotalTacklesRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetTotalTacklesRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : total tack Rank = " << defenseContainer[i]->GetTotalTacklesRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

//	cout << "testing the sort by order of Defense touchdowns in decending order " << endl;
	std::sort(defenseContainer.begin(), defenseContainer.end(), sortDefenseTouchdowns);
//	cout << "sort complete" << endl;

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : yards lost = " << defenseContainer[i]->GetTackleForLossYds() << endl;
//	}

	Def_rank = 1;

	for (int i = 0; i < defenseContainer.size()-1; i++)
	{
		if (defenseContainer[i]->GetTackleForLossYds() == defenseContainer[i + 1]->GetTackleForLossYds())
			defenseContainer[i]->SetTackleForLossYdsRank(Def_rank);
		else
		{
			defenseContainer[i]->SetTackleForLossYdsRank(Def_rank);
			Def_rank++;
		}

		if (i == defenseContainer.size() - 2)
			defenseContainer[i + 1]->SetTackleForLossYdsRank(Def_rank);
	}

//	for (int i = 0; i < defenseContainer.size(); i++)
//	{
//		cout << i << ", This is defense name : " << defenseContainer[i]->GetFirstName() << " " << defenseContainer[i]->GetLastName()
//			<< " : tfl yards Rank = " << defenseContainer[i]->GetTackleForLossYdsRank() << endl;
//	}

//	cout << endl << endl;
//	cout << endl << endl;

	for (int i = 0; i < defenseContainer.size(); i++)
	{
		cout << defenseContainer[i]->GetFirstName() << '\t' << defenseContainer[i]->GetLastName() << '\t';
		cout << defenseContainer[i]->GetInterceptions() << '\t';
		cout << defenseContainer[i]->GetTouchdowns() << '\t';
		cout << defenseContainer[i]->GetSoloTackles() << '\t';
		cout << defenseContainer[i]->GetAssistedTackles() << '\t';
		cout << defenseContainer[i]->GetTotalTackles() << '\t';
		cout << defenseContainer[i]->GetTackleForLossYds() << endl;
	}



	
	for (int i = 0; i < defenseContainer.size(); i++)
	{
		cout << defenseContainer[i]->GetFirstName() << '\t' << defenseContainer[i]->GetLastName() << '\t';
		cout << defenseContainer[i]->GetInterceptionsRank() << '\t';
		cout << defenseContainer[i]->GetTouchdownsRank() << '\t';
		cout << defenseContainer[i]->GetSoloTacklesRank() << '\t';
		cout << defenseContainer[i]->GetAssistedTacklesRank() << '\t';
		cout << defenseContainer[i]->GetTotalTacklesRank() << '\t';
		cout << defenseContainer[i]->GetTackleForLossYdsRank() << endl;
	}
	
	

	//outputting to file








	return 0;
}













//*************************PASSING CONTAINERS SORT FUNCTIONS*********************************
bool sortPassingCompletions(Passing *a, Passing *b)
{
	return a->GetCompletions() > b->GetCompletions();
}

bool sortPassingAttempts(Passing *a, Passing *b)
{
	return a->GetAttempts() > b->GetAttempts();
}

bool sortPassingYards(Passing *a, Passing *b)
{
	return a->GetYards() > b->GetYards();
}

bool sortPassingTouchdowns(Passing *a, Passing *b)
{
	return a->GetTouchdowns() > b->GetTouchdowns();
}

bool sortPassingInterceptions(Passing *a, Passing *b)
{
	return a->GetInterceptions() > b->GetInterceptions();
}

bool sortPassingLongestGain(Passing *a, Passing *b)
{
	return a->GetLongestGain() > b->GetLongestGain();
}

bool sortPassingSack(Passing *a, Passing *b)
{
	return a->GetSack() > b->GetSack();
}

bool sortPassingTFL(Passing *a, Passing *b)
{
	return a->GetTackleForLoss() > b->GetTackleForLoss();
}

bool sortPassingCompletionPercentage(Passing *a, Passing *b)
{
	return a->GetCompletionPercentage() > b->GetCompletionPercentage();
}

bool sortPassingYPA(Passing *a, Passing *b)
{
	return a->GetYardsPerAttempt() > b->GetYardsPerAttempt();
}

bool sortPassingTDP(Passing *a, Passing *b)
{
	return a->GetTouchdownPercentage() > b->GetTouchdownPercentage();
}

bool sortPassingINTP(Passing *a, Passing *b)
{
	return a->GetInterceptionPercentage() > b->GetInterceptionPercentage();
}

bool sortPassingPasserRating(Passing *a, Passing *b)
{
	return a->GetPasserRating() > b->GetPasserRating();
}

//***********************************************RUSHING CONTAINERS SORT FUNCTIONS************************************
bool sortRushingGames(Rushing *a, Rushing *b)
{
	return a->GetGames() > b->GetGames();
}

bool sortRushingAttempts(Rushing *a, Rushing *b)
{
	return a->GetAttempts() > b->GetAttempts();
}

bool sortRushingYards(Rushing *a, Rushing *b)
{
	return a->GetYards() > b->GetYards();
}

bool sortRushingAvgYardsPerCarry(Rushing *a, Rushing *b)
{
	return a->GetAverageYardsPerCarry() > b->GetAverageYardsPerCarry();
}

bool sortRushingYardsPerGame(Rushing *a, Rushing *b)
{
	return a->GetYardsPerGame() > b->GetYardsPerGame();
}

bool sortRushingLongestGain(Rushing *a, Rushing *b)
{
	return a->GetLongestGain() > b->GetLongestGain();
}

bool sortRushingTouchdowns(Rushing *a, Rushing *b)
{
	return a->GetTouchdowns() > b->GetTouchdowns();
}

bool sortRushingFirstDowns(Rushing *a, Rushing *b)
{
	return a->GetFirstDowns() > b->GetFirstDowns();
}

//**************************************************************RECEIVING CONTAINER SORT FUNCTIONS**********************
bool sortReceivingGames(Receiving *a, Receiving *b)
{
	return a->GetGames() > b->GetGames();
}

bool sortReceivingReceptions(Receiving *a, Receiving *b)
{
	return a->GetReceptions() > b->GetReceptions();
}

bool sortReceivingYards(Receiving *a, Receiving *b)
{
	return a->GetYards() > b->GetYards();
}

bool sortReceivingAvgYards(Receiving *a, Receiving *b)
{
	return a->GetAverageYards() > b->GetAverageYards();
}

bool sortReceivingYPG(Receiving *a, Receiving *b)
{
	return a->GetYardsPerGame() > b->GetYardsPerGame();
}

bool sortReceivingLongestGain(Receiving *a, Receiving *b)
{
	return a->GetLongestGain() > b->GetLongestGain();
}

bool sortReceivingTouchdowns(Receiving *a, Receiving *b)
{
	return a->GetTouchdowns() > b->GetTouchdowns();
}

bool sortReceivingFirstdowns(Receiving *a, Receiving *b)
{
	return a->GetFirstDowns() > b->GetFirstDowns();
}

bool sortReceivingTargets(Receiving *a, Receiving *b)
{
	return a->GetTargets() > b->GetTargets();
}

bool sortReceivingYAC(Receiving *a, Receiving *b)
{
	return a->GetYardsAfterCatch() > b->GetYardsAfterCatch();
}

//*******************************************DEFENSE CONTAINER SORT FUNCTIONS**********************************
bool sortDefenseInterceptions(Defense *a, Defense *b)
{
	return a->GetInterceptions() > b->GetInterceptions();
}

bool sortDefenseTouchdowns(Defense *a, Defense *b)
{
	return a->GetTouchdowns() > b->GetTouchdowns();
}

bool sortDefenseSoloTack(Defense *a, Defense *b)
{
	return a->GetSoloTackles() > b->GetSoloTackles();
}

bool sortDefenseAssisTack(Defense *a, Defense *b)
{
	return a->GetAssistedTackles() > b->GetAssistedTackles();
}

bool sortDefenseTotalTack(Defense *a, Defense *b)
{
	return a->GetTotalTackles() > b->GetTotalTackles();
}

bool sortDefenseYardsLoss(Defense *a, Defense *b)
{
	return a->GetTackleForLossYds() > b->GetTackleForLossYds();
}




//*****************************************SUPPORTING FUNCTIONS TO HELP WITH ADDING PLAYERS FROM TEXT FILE**********************


void teamCheck(const string teamname, ifstream &filein)
{
	string garbage; 

	if (teamname == "buffaloBills.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage  " << garbage << endl;
		}
	}
	else if (teamname == "miamiDolphins.txt")
	{
		for (int i = 0; i < 434; i++){
			getline(filein, garbage);
			//cout << "this is garbage  " << garbage << endl;
		}
	}
	else if (teamname == "newEnglandPatriots.txt")
	{
		for (int i = 0; i < 434; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "newYorkJets.txt")
	{
		for (int i = 0; i < 504; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "baltimoreRavens.txt")
	{
		for (int i = 0; i < 518; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "cincinnatiBengals.txt")
	{
		for (int i = 0; i < 476; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "clevelandBrowns.txt")
	{
		for (int i = 0; i < 434; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "pittsburghSteelers.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "houstonTexans.txt")
	{
		for (int i = 0; i < 476; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "indianapolisColts.txt")
	{
		for (int i = 0; i < 462; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "jacksonvilleJaguars.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "tennesseeTitans.txt")
	{
		for (int i = 0; i < 434; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "denverBroncos.txt")
	{
		for (int i = 0; i < 420; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "kansasCityChiefs.txt")
	{
		for (int i = 0; i < 476; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "sanDiegoChargers.txt")
	{
		for (int i = 0; i < 504; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "oaklandRaiders.txt")
	{
		for (int i = 0; i < 504; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "dallasCowboys.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "newYorkGiants.txt")
	{
		for (int i = 0; i < 462; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "philadelphiaEagles.txt")
	{
		for (int i = 0; i < 462; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "washingtonRedskins.txt")
	{
		for (int i = 0; i < 420; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "chicagoBears.txt")
	{
		for (int i = 0; i < 364; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "detroitLions.txt")
	{
		for (int i = 0; i < 392; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "greenBayPackers.txt")
	{
		for (int i = 0; i < 336; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "minnesotaVikings.txt")
	{
		for (int i = 0; i < 350; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "atlantaFalcons.txt")				//left off here
	{
		for (int i = 0; i < 476; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "carolinaPanthers.txt")
	{
		for (int i = 0; i < 476; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "newOrleansSaints.txt")
	{
		for (int i = 0; i < 364; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "tampaBayBuccaneers.txt")
	{
		for (int i = 0; i < 350; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "arizonaCardinals.txt")
	{
		for (int i = 0; i < 462; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "losAngelesRams.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "sanFrancisco49ers.txt")
	{
		for (int i = 0; i < 448; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
	else if (teamname == "seattleSeahawks.txt")
	{
		for (int i = 0; i < 378; i++){
			getline(filein, garbage);
			//cout << "this is garbage " << garbage << endl;
		}
	}
}



//******************************************REMOVE THE TEAMNAME FROM THE VECTOR, DO NOT CARE ABOUT TEAM STATS ONLY PLAYER***************
void removeTeamPasser(vector<Passing *> &passerContainer)
{
	for (int i = 0; i < passerContainer.size(); i++)
	{
		if ((passerContainer[i]->GetFirstName() == "Arizona\n") || (passerContainer[i]->GetFirstName() == "Atlanta\n") 
			|| (passerContainer[i]->GetFirstName() == "Baltimore\n") || (passerContainer[i]->GetFirstName() == "Buffalo\n")
			|| (passerContainer[i]->GetFirstName() == "Carolina\n") || (passerContainer[i]->GetFirstName() == "Chicago\n") 
			|| (passerContainer[i]->GetFirstName() == "Cincinnati\n") || (passerContainer[i]->GetFirstName() == "Cleveland\n") 
			|| (passerContainer[i]->GetFirstName() == "Dallas\n") || (passerContainer[i]->GetFirstName() == "Denver\n") 
			|| (passerContainer[i]->GetFirstName() == "Detroit\n") || (passerContainer[i]->GetFirstName() == "Green") 
			|| (passerContainer[i]->GetFirstName() == "Houston\n") || (passerContainer[i]->GetFirstName() == "Indianapolis\n") 
			|| (passerContainer[i]->GetFirstName() == "Jacksonville\n") || (passerContainer[i]->GetFirstName() == "Pittsburgh\n") 
			|| (passerContainer[i]->GetFirstName() == "Kansas") || (passerContainer[i]->GetFirstName() == "LA") 
			|| (passerContainer[i]->GetFirstName() == "Miami\n") || (passerContainer[i]->GetFirstName() == "Minnesota\n") 
			|| (passerContainer[i]->GetFirstName() == "New") || (passerContainer[i]->GetFirstName() == "NY") 
			|| (passerContainer[i]->GetFirstName() == "Oakland\n") || (passerContainer[i]->GetFirstName() == "Philadelphia\n")
			|| (passerContainer[i]->GetFirstName() == "San") || (passerContainer[i]->GetFirstName() == "Seattle\n") 
			|| (passerContainer[i]->GetFirstName() == "Tampa") || (passerContainer[i]->GetFirstName() == "Tennessee\n") 
			|| (passerContainer[i]->GetFirstName() == "Washington\n"))
		{
			passerContainer.erase(passerContainer.begin() + i);
		}
	}
}

void removeTeamRunner(vector<Rushing *> &rusherContainer)
{
	for (int i = 0; i < rusherContainer.size(); i++)
	{
		if ((rusherContainer[i]->GetFirstName() == "Arizona\n") || (rusherContainer[i]->GetFirstName() == "Atlanta\n")
			|| (rusherContainer[i]->GetFirstName() == "Baltimore\n") || (rusherContainer[i]->GetFirstName() == "Buffalo\n")
			|| (rusherContainer[i]->GetFirstName() == "Carolina\n") || (rusherContainer[i]->GetFirstName() == "Chicago\n")
			|| (rusherContainer[i]->GetFirstName() == "Cincinnati\n") || (rusherContainer[i]->GetFirstName() == "Cleveland\n")
			|| (rusherContainer[i]->GetFirstName() == "Dallas\n") || (rusherContainer[i]->GetFirstName() == "Denver\n")
			|| (rusherContainer[i]->GetFirstName() == "Detroit\n") || (rusherContainer[i]->GetFirstName() == "Green")
			|| (rusherContainer[i]->GetFirstName() == "Houston\n") || (rusherContainer[i]->GetFirstName() == "Indianapolis\n")
			|| (rusherContainer[i]->GetFirstName() == "Jacksonville\n") || (rusherContainer[i]->GetFirstName() == "Pittsburgh\n")
			|| (rusherContainer[i]->GetFirstName() == "Kansas") || (rusherContainer[i]->GetFirstName() == "LA")
			|| (rusherContainer[i]->GetFirstName() == "Miami\n") || (rusherContainer[i]->GetFirstName() == "Minnesota\n")
			|| (rusherContainer[i]->GetFirstName() == "New") || (rusherContainer[i]->GetFirstName() == "NY")
			|| (rusherContainer[i]->GetFirstName() == "Oakland\n") || (rusherContainer[i]->GetFirstName() == "Philadelphia\n")
			|| (rusherContainer[i]->GetFirstName() == "San") || (rusherContainer[i]->GetFirstName() == "Seattle\n")
			|| (rusherContainer[i]->GetFirstName() == "Tampa") || (rusherContainer[i]->GetFirstName() == "Tennessee\n")
			|| (rusherContainer[i]->GetFirstName() == "Washington\n"))
		{
			rusherContainer.erase(rusherContainer.begin() + i);
		}
	}
}

void removeTeamReceiver(vector<Receiving *> &receiverContainer)
{
	for (int i = 0; i < receiverContainer.size(); i++)
	{
		if ((receiverContainer[i]->GetFirstName() == "Arizona\n") || (receiverContainer[i]->GetFirstName() == "Atlanta\n")
			|| (receiverContainer[i]->GetFirstName() == "Baltimore\n") || (receiverContainer[i]->GetFirstName() == "Buffalo\n")
			|| (receiverContainer[i]->GetFirstName() == "Carolina\n") || (receiverContainer[i]->GetFirstName() == "Chicago\n")
			|| (receiverContainer[i]->GetFirstName() == "Cincinnati\n") || (receiverContainer[i]->GetFirstName() == "Cleveland\n")
			|| (receiverContainer[i]->GetFirstName() == "Dallas\n") || (receiverContainer[i]->GetFirstName() == "Denver\n")
			|| (receiverContainer[i]->GetFirstName() == "Detroit\n") || (receiverContainer[i]->GetFirstName() == "Green")
			|| (receiverContainer[i]->GetFirstName() == "Houston\n") || (receiverContainer[i]->GetFirstName() == "Indianapolis\n")
			|| (receiverContainer[i]->GetFirstName() == "Jacksonville\n") || (receiverContainer[i]->GetFirstName() == "Pittsburgh\n")
			|| (receiverContainer[i]->GetFirstName() == "Kansas") || (receiverContainer[i]->GetFirstName() == "LA")
			|| (receiverContainer[i]->GetFirstName() == "Miami\n") || (receiverContainer[i]->GetFirstName() == "Minnesota\n")
			|| (receiverContainer[i]->GetFirstName() == "New") || (receiverContainer[i]->GetFirstName() == "NY")
			|| (receiverContainer[i]->GetFirstName() == "Oakland\n") || (receiverContainer[i]->GetFirstName() == "Philadelphia\n")
			|| (receiverContainer[i]->GetFirstName() == "San") || (receiverContainer[i]->GetFirstName() == "Seattle\n")
			|| (receiverContainer[i]->GetFirstName() == "Tampa") || (receiverContainer[i]->GetFirstName() == "Tennessee\n")
			|| (receiverContainer[i]->GetFirstName() == "Washington\n"))
		{
			receiverContainer.erase(receiverContainer.begin() + i);
		}
	}
}

void removeTeamDefense(vector<Defense *> &defenseContainer)
{
	for (int i = 0; i < defenseContainer.size(); i++)
	{
		if ((defenseContainer[i]->GetFirstName() == "Arizona\n") || (defenseContainer[i]->GetFirstName() == "Atlanta\n")
			|| (defenseContainer[i]->GetFirstName() == "Baltimore\n") || (defenseContainer[i]->GetFirstName() == "Buffalo\n")
			|| (defenseContainer[i]->GetFirstName() == "Carolina\n") || (defenseContainer[i]->GetFirstName() == "Chicago\n")
			|| (defenseContainer[i]->GetFirstName() == "Cincinnati\n") || (defenseContainer[i]->GetFirstName() == "Cleveland\n")
			|| (defenseContainer[i]->GetFirstName() == "Dallas\n") || (defenseContainer[i]->GetFirstName() == "Denver\n")
			|| (defenseContainer[i]->GetFirstName() == "Detroit\n") || (defenseContainer[i]->GetFirstName() == "Green")
			|| (defenseContainer[i]->GetFirstName() == "Houston\n") || (defenseContainer[i]->GetFirstName() == "Indianapolis\n")
			|| (defenseContainer[i]->GetFirstName() == "Jacksonville\n") || (defenseContainer[i]->GetFirstName() == "Pittsburgh\n")
			|| (defenseContainer[i]->GetFirstName() == "Kansas") || (defenseContainer[i]->GetFirstName() == "LA")
			|| (defenseContainer[i]->GetFirstName() == "Miami\n") || (defenseContainer[i]->GetFirstName() == "Minnesota\n")
			|| (defenseContainer[i]->GetFirstName() == "New") || (defenseContainer[i]->GetFirstName() == "NY")
			|| (defenseContainer[i]->GetFirstName() == "Oakland\n") || (defenseContainer[i]->GetFirstName() == "Philadelphia\n")
			|| (defenseContainer[i]->GetFirstName() == "San") || (defenseContainer[i]->GetFirstName() == "Seattle\n")
			|| (defenseContainer[i]->GetFirstName() == "Tampa") || (defenseContainer[i]->GetFirstName() == "Tennessee\n")
			|| (defenseContainer[i]->GetFirstName() == "Washington\n") || (defenseContainer[i]->GetFirstName() == " \n")
			|| (defenseContainer[i]->GetFirstName() == "Opponents\n") || (defenseContainer[i]->GetFirstName() == "Tackles\n")
			|| (defenseContainer[i]->GetFirstName() == "TeamTeam\n") || (defenseContainer[i]->GetFirstName() == " \" \"\n"))
		{
			defenseContainer.erase(defenseContainer.begin() + i);
		}
	}
}
