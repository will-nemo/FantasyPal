#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Receiving
{

public:
	//Default Constructor - WL
	Receiving();
	//Constructor - WL				
	Receiving(string fn, string ln, string tn, int game, int rec, int yar,
		double avg, int YPG, int LG, int td, int fd, int tar, int YAC);

	
	//set and get functions for name - WL
	void SetFirstName(string fn);
	void SetLastName(string ln);
	void SetTeamName(string tn);

	string GetFirstName();
	string GetLastName();
	string GetTeamName();


	void SetGames(int games);
	
	//Set functions for all relevant stats - WL

	void SetReceptions(int receptions);
	void SetYards(int yards);
	void SetAverageYards(double average);
	void SetYardsPerGame(double YPG);
	void SetLongestGain(int LongestGain);
	void SetTouchdowns(int touchdowns);
	void SetFirstDowns(int FirstDown);
	void SetTargets(int targets);
	void SetYardsAfterCatch(int YAC);

	int GetGames();
	int GetReceptions();
	int GetYards();
	double GetAverageYards();
	double GetYardsPerGame();
	int GetLongestGain();
	int GetTouchdowns();
	int GetFirstDowns();
	int GetTargets();
	int GetYardsAfterCatch();
				
												//set and get functions for all RANKS for WR stats - WL
	void SetGamesRank(int );								
	void SetReceptionsRank(int );
	void SetYardsRank(int );
	void SetAverageYardsRank(int );
	void SetYardsPerGameRank(int );
	void SetLongestGainRank(int );
	void SetTouchdownsRank(int );
	void SetFirstDownsRank(int );
	void SetTargetsRank(int targets);
	void SetYardsAfterCatchRank(int );

	int GetGamesRank();
	int GetReceptionsRank();
	int GetYardsRank();
	int GetAverageYardsRank();
	int GetYardsPerGameRank();
	int GetLongestGainRank();
	int GetTouchdownsRank();
	int GetFirstDownsRank();
	int GetTargetsRank();
	int GetYardsAfterCatchRank();


private:
	int games, receptions, yards, LongestGain, touchdowns, FirstDown, targets, YAC;
	double average, YPG;
	int gamesRank, receptionsRank, yardsRank, LongestGainRank, touchdownsRank, FirstDownRank, targetsRank, YACRank, averageRank, YPGRank;

	string firstname, lastname, teamname;
};