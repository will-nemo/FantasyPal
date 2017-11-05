#include "Passing.h"

//basic constructor
Passing::Passing()
{
	firstname = "empty";
	lastname = "empty";
	teamname = "empty";
}

//constructor for parsed information
Passing::Passing(string fn, string ln, string tn, int att, int comp, double per, int yar, double YPA,
	int td, double TDP, int inter, double INTP, int LG, int sack, int TFL, double PR)
{
	SetFirstName(fn); 
	SetLastName(ln);
	SetTeamName(tn);
	SetAttempts(att);
	SetCompletions(comp);
	SetCompletionPercentage(per);
	SetYards(yar);
	SetYardsPerAttempt(YPA);
	SetTouchdowns(td);
	SetTouchdownPercentage(TDP);
	SetInterceptions(inter);
	SetInterceptionPercentage(INTP);
	SetLongestGain(LG);
	SetSack(sack);
	SetTackleForLoss(TFL);
	SetPasserRating(PR);
}

//set name functions
void Passing::SetFirstName(string fn)
{
	firstname = fn;
}

void Passing::SetLastName(string ln)
{
	lastname = ln;
}

void Passing::SetTeamName(string tn)
{
	teamname = tn;
}

//get name functions
string Passing::GetTeamName()
{
	return teamname;
}

string Passing::GetFirstName()
{
	return firstname;
}

string Passing::GetLastName()
{
	return lastname;
}


//set stat functions
void Passing::SetAttempts(int att)
{
	attempts = att;
}

void Passing::SetCompletions(int comp)
{
	completions = comp;
}

void Passing::SetCompletionPercentage(double per)
{
	percentage = per;
}

void Passing::SetYards(int yar)
{
	yards = yar;
}

void Passing::SetYardsPerAttempt(double yardsperatt)
{
	YPA = yardsperatt;
}

void Passing::SetTouchdowns(int td)
{
	touchdowns = td;
}

void Passing::SetTouchdownPercentage(double tdp)
{
	TDP = tdp;
}

void Passing::SetInterceptions(int inter)
{
	interceptions = inter;
}

void Passing::SetInterceptionPercentage(double intper)
{
	INTP = intper;
}

void Passing::SetLongestGain(int LG)
{
	LongestGain = LG;
}

void Passing::SetSack(int Sack)
{
	sack = Sack;
}

void Passing::SetTackleForLoss(int tfl)
{
	TFL = tfl;
}

void Passing::SetPasserRating(double PR)
{
	PasserRating = PR;
}

//get stat functions
int Passing::GetAttempts()
{
	return attempts;
}

int Passing::GetCompletions()
{
	return completions;
}

double Passing::GetCompletionPercentage()
{
	return percentage;
}

int Passing::GetYards()
{
	return yards;
}

double Passing::GetYardsPerAttempt()
{
	return YPA;
}

int Passing::GetTouchdowns()
{
	return touchdowns;
}

double Passing::GetTouchdownPercentage()
{
	return TDP;
}

int Passing::GetInterceptions()
{
	return interceptions;
}

double Passing::GetInterceptionPercentage()
{
	return INTP;
}

int Passing::GetLongestGain()
{
	return LongestGain;
}

int Passing::GetSack()
{
	return sack;
}

int Passing::GetTackleForLoss()
{
	return TFL;
}

double Passing::GetPasserRating()
{
	return PasserRating;
}

//set ranking functions
void Passing::SetAttemptsRank(int attRank)
{
	attemptsRank = attRank;
}

void Passing::SetCompletionsRank(int compRank)
{
	completionsRank = compRank;
}

void Passing::SetCompletionPercentageRank(int perRank)
{
	percentageRank = perRank;
}

void Passing::SetYardsRank(int yarRank)
{
	yardsRank = yarRank;
}

void Passing::SetYardsPerAttemptRank(int YardsPerAttRank)
{
	YPARank = YardsPerAttRank;
}

void Passing::SetTouchdownsRank(int tdRank)
{
	touchdownsRank = tdRank;
}

void Passing::SetTouchdownPercentageRank(int TouchdownPerRank)
{
	TDPRank = TouchdownPerRank;
}

void Passing::SetInterceptionsRank(int interRank)
{
	interceptionsRank = interRank;
}

void Passing::SetInterceptionPercentageRank(int InterPerRank)
{
	INTPRank = InterPerRank;
}

void Passing::SetLongestGainRank(int LGRank)
{
	LongestGainRank = LGRank;
}

void Passing::SetSackRank(int SackRank)
{
	sackRank = SackRank;
}

void Passing::SetTackleForLossRank(int TFL)
{
	TFLRank = TFL;
}

void Passing::SetPasserRatingRank(int PRRank)
{
	PasserRatingRank = PRRank;
}

//get rankings functions
int Passing::GetAttemptsRank()
{
	return attemptsRank;
}

int Passing::GetCompletionsRank()
{
	return completionsRank;
}

int Passing::GetCompletionPercentageRank()
{
	return percentageRank;
}

int Passing::GetYardsRank()
{
	return yardsRank;
}

int Passing::GetYardsPerAttemptRank()
{
	return YPARank;
}

int Passing::GetTouchdownsRank()
{
	return touchdownsRank;
}

int Passing::GetTouchdownPercentageRank()
{
	return TDPRank;
}

int Passing::GetInterceptionsRank()
{
	return interceptionsRank;
}

int Passing::GetInterceptionPercentageRank()
{
	return INTPRank;
}

int Passing::GetLongestGainRank()
{
	return LongestGainRank;
}

int Passing::GetSackRank()
{
	return sackRank;
}

int Passing::GetTackleForLossRank()
{
	return TFLRank;
}

int Passing::GetPasserRatingRank()
{
	return PasserRatingRank;
}