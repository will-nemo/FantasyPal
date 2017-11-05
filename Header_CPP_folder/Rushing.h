#include <iostream> // for input/output
#include <iomanip> //input output manipulators
#include <vector> // for creating vectors
#include <string> // for creating strings 
using namespace std;

class Rushing
{
public:
	Rushing(); //default constructor
	Rushing(string fn, string ln, string tn, int game, int att,
		int yar, double YPC, double YPG, int LG, int td, int fd); //constructor for included stats

	void SetFirstName(string fn); //set first name of rusher					
	void SetLastName(string ln); //set last name of rusher
	void SetTeamName(string tn); //set name of team rusher plays for

	string GetFirstName(); //return first name
	string GetLastName(); //return last name
	string GetTeamName(); //return team name

	void SetGames(int games);	//set number of games played		
	void SetAttempts(int attempts); //set number of rushing attempts
	void SetYards(int yards); //set rushing yards
	void SetAverageYardsPerCarry(double AvgYPC); //set average yard per carry
	void SetYardsPerGame(double YPG); //set yards per game
	void SetLongestGain(int LongestGain); // set rushers longest gain
	void SetTouchdowns(int touchdowns); // set number of touchdowns
	void SetFirstDowns(int firstdowns); //set number of first downs gained

	int GetGames(); // get number of games
	int GetAttempts(); // get number of attempts
	int GetYards(); // get number of yards
	double GetAverageYardsPerCarry(); // get rusher average yard per carry
	double GetYardsPerGame(); //get yards per game
	int GetLongestGain(); // get longest gain
	int GetTouchdowns(); //get number of touchdowns
	int GetFirstDowns(); // get number of first downs obtained 

				/* Rank vs other players in league */
	void SetGamesRank(int ); // set number of games rank 		
	void SetAttemptsRank(int ); //set number of attempts rank
	void SetYardsRank(int ); // set total number of yards rank
	void SetAverageYardsPerCarryRank(int ); // set average yards per carry rank
	void SetYardsPerGameRank(int ); //set yards per game rank
	void SetLongestGainRank(int ); // set longest game rank
	void SetTouchdownsRank(int ); //set touchdowns rank
	void SetFirstDownsRank(int ); // set number of first downs gained rank

	int GetGamesRank(); // get number of games played rank
	int GetAttemptsRank(); // get number of rushing attempts rank
	int GetYardsRank(); // get number of total yards rank 
	int GetAverageYardsPerCarryRank(); // get average yards per carry rank 
	int GetYardsPerGameRank(); // get yards per game rank
	int GetLongestGainRank(); // get longest gain rank 
	int GetTouchdownsRank(); // get number of touchdowns rank 
	int GetFirstDownsRank(); // get number of first downs rank 





private: // private variables
	int games, attempts, yards, LongestGain, touchdowns, firstdowns; 
	double AvgYPC, YPG; 
	string firstname, lastname, teamname;

	int gamesRank, attemptsRank, yardsRank, LongestGainRank, touchdownsRank, firstdownsRank, AvgYPCRank, YPGRank;
};