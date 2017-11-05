#include "Rushing.h" // include Rushing class 


Rushing::Rushing() //default constructor set to empty 
{
	firstname = "empty";
	lastname = "empty";
	teamname = "empty";
}

Rushing::Rushing(string fn, string ln, string tn, int game, int att,
	int yar, double YPC, double YPG, int LG, int td, int fd) //constructor to set all rushing stats
{
	firstname = fn;
	lastname = ln;
	teamname = tn;
	SetGames(game);
	SetAttempts(att);
	SetYards(yar);
	SetAverageYardsPerCarry(YPC);
	SetYardsPerGame(YPG);
	SetLongestGain(LG);
	SetTouchdowns(td);
	SetFirstDowns(fd);
}



void Rushing::SetFirstName(string fn) // set first name of rusher 
{
	firstname = fn;
}

void Rushing::SetLastName(string ln) // set last name of rusher 
{
	lastname = ln;
}

void Rushing::SetTeamName(string tn) // set team name of rusher 
{
	teamname = tn;
}

string Rushing::GetTeamName() // get team name of rusher 
{
	return teamname;
}

string Rushing::GetFirstName() // get first name of rusher 
{
	return firstname;
}

string Rushing::GetLastName() // get last name of rusher 
{
	return lastname;
}


void Rushing::SetGames(int gm) // set games played 
{
	games = gm;
}

void Rushing::SetAttempts(int att) // set number of attempts 
{
	attempts = att;
}

void Rushing::SetYards(int yd) // set number of rushing yards
{
	yards = yd;
}

void Rushing::SetAverageYardsPerCarry(double YPC) // set yards per carry 
{
	AvgYPC = YPC;
}


void Rushing::SetYardsPerGame(double YPG) // set yards per game
{
	YPG = YPG;
}

void Rushing::SetLongestGain(int LG) // set rusher longest gain 
{
	LongestGain = LG;
}

void Rushing::SetTouchdowns(int td) // set number of touchdowns 
{
	touchdowns = td;
}


void Rushing::SetFirstDowns(int fd) // set number of first downs gained 
{
	firstdowns = fd;
}

int Rushing::GetGames() // get number of games played
{
	return games;
}

int Rushing::GetAttempts() // get number of rushing attempts
{
	return attempts;
}

int Rushing::GetYards() // get number of yards gained by rusher 
{
	return yards;
}

double Rushing::GetAverageYardsPerCarry() // get average yards per rushing attempt 
{
	return AvgYPC;
}

double Rushing::GetYardsPerGame() // get average yards per game 
{
	return YPG;
}

int Rushing::GetLongestGain() // get rushers longest gain 
{
	return LongestGain;
}

int Rushing::GetTouchdowns() // get total number of touchdowns 
{
	return touchdowns;
}

int Rushing::GetFirstDowns() // get first downs 
{
	return firstdowns;
}


void Rushing::SetGamesRank(int rank) // set number of games rank 
{
	gamesRank = rank;
}

void Rushing::SetAttemptsRank(int rank) // set number of attempts rank 
{
	attemptsRank = rank;
}

void Rushing::SetYardsRank(int rank) // set number of yards rank 
{
	yardsRank = rank;
}

void Rushing::SetAverageYardsPerCarryRank(int rank) // set average yards per carry rank 
{
	AvgYPCRank = rank;
}

void Rushing::SetYardsPerGameRank(int rank) // set yards per game rank 
{
	YPGRank = rank;
}

void Rushing::SetLongestGainRank(int rank) // set longest gain rank 
{
	LongestGainRank = rank;
}

void Rushing::SetTouchdownsRank(int rank) // set number of touchdowns rank 
{
	touchdownsRank = rank;
}

void Rushing::SetFirstDownsRank(int rank) // set number of first downs rank 
{
	firstdownsRank = rank;
}

int Rushing::GetGamesRank() // get number of games rank 
{
	return gamesRank;
}

int Rushing::GetAttemptsRank() // get number of attempts rank 
{
	return attemptsRank;
}

int Rushing::GetYardsRank() // get number of yards rank 
{
	return yardsRank;
}

int Rushing::GetAverageYardsPerCarryRank() // get average yards per carry rank 
{
	return AvgYPCRank;
}

int Rushing::GetYardsPerGameRank() // get yards per game rank 
{
	return YPGRank;
}

int Rushing::GetLongestGainRank() // get rushers longest game rank 
{
	return LongestGainRank;
}

int Rushing::GetTouchdownsRank() // get number of touchdowns rank 
{
	return touchdownsRank;
}

int Rushing::GetFirstDownsRank() // get number of first downs gained rank
{
	return firstdownsRank;
}