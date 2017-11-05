#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

//QB class
class Passing
{

public:

	Passing(); //basic constructor
	
	//this constructor takes in all parsed, relevant information	
	Passing(string fn, string ln, string tn, int att, int comp, double per, int yar, double YPA,
		int td, double TPD, int inter, double INTP, int LG, int Sack, int TFL, double PR);

	//set functions for QB name and team name
	void SetFirstName(string fn);	
	void SetLastName(string ln);
	void SetTeamName(string tn);

	//get functions for QB name and team name
	string GetFirstName();								
	string GetLastName();
	string GetTeamName();
	
	//set functions for all QB stats
	void SetAttempts(int attempts);	
	void SetCompletions(int completions);
	void SetCompletionPercentage(double percentage);
	void SetYards(int yards);
	void SetYardsPerAttempt(double YPA);
	void SetTouchdowns(int touchdowns);
	void SetTouchdownPercentage(double TDP);
	void SetInterceptions(int interceptions);
	void SetInterceptionPercentage(double INTP);
	void SetLongestGain(int LongestGain);
	void SetSack(int Sack);
	void SetTackleForLoss(int TFL);
	void SetPasserRating(double PR);

	//set functions for ranking in QB's respective stats
	void SetAttemptsRank(int attemptsRank);
	void SetCompletionsRank(int completionsRank);
	void SetCompletionPercentageRank(int percentageRank);
	void SetYardsRank(int yardsRank);
	void SetYardsPerAttemptRank(int YPARank);
	void SetTouchdownsRank(int touchdownsRank);
	void SetTouchdownPercentageRank(int TDPRank);
	void SetInterceptionsRank(int interceptionsRank);
	void SetInterceptionPercentageRank(int INTPRank);
	void SetLongestGainRank(int LongestGainRank);
	void SetSackRank(int SackRank);
	void SetTackleForLossRank(int TFLRank);
	void SetPasserRatingRank(int PRRank);

	//Get functions for stats relevant to QB
	int GetAttempts();		
	int GetCompletions();
	double GetCompletionPercentage();
	int GetYards();
	double GetYardsPerAttempt();
	int GetTouchdowns();
	double GetTouchdownPercentage();
	int GetInterceptions();
	double GetInterceptionPercentage();
	int GetLongestGain();
	int GetSack();
	int GetTackleForLoss();
	double GetPasserRating();

	//Get functions for QB's ranking in the respective stats
	int GetAttemptsRank();	
	int GetCompletionsRank();
	int GetCompletionPercentageRank();
	int GetYardsRank();
	int GetYardsPerAttemptRank();
	int GetTouchdownsRank();
	int GetTouchdownPercentageRank();
	int GetInterceptionsRank();
	int GetInterceptionPercentageRank();
	int GetLongestGainRank();
	int GetSackRank();
	int GetTackleForLossRank();
	int GetPasserRatingRank();

private:
	//QB relevant stats	
	int attempts, completions, yards, touchdowns, interceptions, LongestGain, sack, TFL;
	double percentage, YPA, TDP, INTP, PasserRating;

	//QB name and team name
	string firstname, lastname, teamname;
	
	//QB ranking stats
	int attemptsRank, completionsRank, yardsRank, touchdownsRank, interceptionsRank, LongestGainRank, sackRank, TFLRank, 
		percentageRank, YPARank, TDPRank, INTPRank, PasserRatingRank;
};