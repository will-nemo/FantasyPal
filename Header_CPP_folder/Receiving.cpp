#include "Receiving.h"

//class default constructor - WL
Receiving::Receiving()
{
		firstname = "empty";
		lastname = "empty";
		teamname = "empty";
}

Receiving::Receiving(string fn, string ln, string tn, int game, int rec, int yar, double avg, int YPG,
	int LG, int td, int fd, int tar, int YAC)
{
	firstname = fn;
	lastname = ln;
	teamname = tn;
	SetGames(game);
	SetReceptions(rec);
	SetYards(yar);
	SetAverageYards(avg);
	SetYardsPerGame(YPG);
	SetLongestGain(LG);
	SetTouchdowns(td);
	SetFirstDowns(fd);
	SetTargets(tar);
	SetYardsAfterCatch(YAC);
}

//-------- Name/Team Relevant functions - WL

void Receiving::SetFirstName(string fn)
{
	firstname = fn;
}

void Receiving::SetLastName(string ln)
{
	lastname = ln;
}

void Receiving::SetTeamName(string tn)
{
	teamname = tn;
}

string Receiving::GetTeamName()
{
	return teamname;
}

string Receiving::GetFirstName()
{
	return firstname;
}

string Receiving::GetLastName()
{
	return lastname;
}

//-------All stat relevant functions - WL

void Receiving::SetGames(int gm)
{
	games = gm;
}

void Receiving::SetReceptions(int rec)
{
	receptions = rec;
}

void Receiving::SetYards(int yd)
{
	yards = yd;
}

void Receiving::SetAverageYards(double avg)
{
	average = avg;
}

void Receiving::SetYardsPerGame(double YPG)
{
	YPG = YPG;
}

void Receiving::SetLongestGain(int LG)
{
	LongestGain = LG;
}

void Receiving::SetTouchdowns(int td)
{
	touchdowns = td;
}

void Receiving::SetFirstDowns(int fd)
{
	FirstDown = fd;
}

void Receiving::SetTargets(int tar)
{
	targets = tar;
}

void Receiving::SetYardsAfterCatch(int yardsAfterCatch)
{
	YAC = yardsAfterCatch;
}

int Receiving::GetGames()
{
	return games;
}

int Receiving::GetReceptions()
{
	return receptions;
}

int Receiving::GetYards()
{
	return yards;
}

double Receiving::GetAverageYards()
{
	return average;
}

double Receiving::GetYardsPerGame()
{
	return YPG;
}

int Receiving::GetLongestGain()
{
	return LongestGain;
}

int Receiving::GetTouchdowns()
{
	return touchdowns;
}

int Receiving::GetFirstDowns()
{
	return FirstDown;
}

int Receiving::GetTargets()
{
	return targets;
}

int Receiving::GetYardsAfterCatch()
{
	return YAC;
}

// --------- all state ranking functions -- WL
void Receiving::SetGamesRank(int rank)
{
	gamesRank = rank;
}

void Receiving::SetReceptionsRank(int rank)
{
	receptionsRank = rank;
}

void Receiving::SetYardsRank(int rank)
{
	yardsRank = rank;
}

void Receiving::SetAverageYardsRank(int rank)
{
	averageRank = rank;
}

void Receiving::SetYardsPerGameRank(int rank)
{
	YPGRank = rank;
}

void Receiving::SetLongestGainRank(int rank)
{
	LongestGainRank = rank;
}

void Receiving::SetTouchdownsRank(int rank)
{
	touchdownsRank = rank;
}

void Receiving::SetFirstDownsRank(int rank)
{
	FirstDownRank = rank;
}

void Receiving::SetTargetsRank(int rank)
{
	targetsRank = rank;
}

void Receiving::SetYardsAfterCatchRank(int rank)
{
	YACRank = rank;
}

int Receiving::GetGamesRank()
{
	return gamesRank;
}

int Receiving::GetReceptionsRank()
{
	return receptionsRank;
}

int Receiving::GetYardsRank()
{
	return yardsRank;
}

int Receiving::GetAverageYardsRank()
{
	return averageRank;
}

int Receiving::GetYardsPerGameRank()
{
	return YPGRank;
}

int Receiving::GetLongestGainRank()
{
	return LongestGainRank;
}

int Receiving::GetTouchdownsRank()
{
	return touchdownsRank;
}

int Receiving::GetFirstDownsRank()
{
	return FirstDownRank;
}

int Receiving::GetTargetsRank()
{
	return targetsRank;
}

int Receiving::GetYardsAfterCatchRank()
{
	return YACRank;
}