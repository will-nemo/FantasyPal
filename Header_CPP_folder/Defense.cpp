#include "Defense.h"

Defense::Defense()	//default constructor all are set to "empty"
{
	firstname = "empty";
	lastname = "empty";
	teamname = "empty";
}

Defense::Defense(string fn, string ln, string tn, int interc, int td, int soloTac, int assisTac, int totTac, int ydsLoss)
{
	firstname = fn;
	lastname = ln;
	teamname = tn;
	interceptions = interc;
	touchdowns = td;
	soloTackles = soloTac;
	assistedTackles = assisTac;
	totalTackles = totTac;
	yardsLoss = ydsLoss;
}

//######### Set functions for defence class#########
void Defense::SetFirstName(string fn) // set function for first name
{
	firstname = fn;
}

void Defense::SetLastName(string ln) //set last name
{
	lastname = ln;
}

void Defense::SetTeamName(string tn) // set team name
{
	teamname = tn;
}


//########## Get functions for defence class ########
string Defense::GetFirstName() // get first name
{
	return firstname;
}

string Defense::GetLastName() //get last name
{
	return lastname;
}

string Defense::GetTeamName() //get team name
{
	return teamname;
}


//########## Set functions for defence stats ########

void Defense::SetInterceptions(int interc) // set number of interceptions
{
	interceptions = interc;
}

void Defense::SetTouchdowns(int tds)	//set number of touchdowns
{
	touchdowns = tds;
}

void Defense::SetSoloTackles(int soloTac)	// set number of solo tackles
{
	soloTackles = soloTac;
}

void Defense::SetAssistedTackles(int assisTac)	//set number of assisted tackles
{
	assistedTackles = assisTac;
}

void Defense::SetTotalTackles(int totTac)	//set number of total tackles
{
	totalTackles = totTac;
}

void Defense::SetTackleForLossYds(int ydsLoss) // set number of yards lost due to tackles
{
	yardsLoss = ydsLoss;
}


//###### get functions for defensive stats ####
int Defense::GetInterceptions()		// get interceptions
{
	return interceptions;
}

int Defense::GetTouchdowns() // get number of touchdowns
{
	return touchdowns;
}

int Defense::GetSoloTackles() //get number of solo tackels
{
	return soloTackles;
}

int Defense::GetAssistedTackles() //get number of assited tackles
{
	return assistedTackles;
}

int Defense::GetTotalTackles() // get number of total tackels
{
	return totalTackles;
}

int Defense::GetTackleForLossYds() // get number of total yards lost due to tackle
{
	return yardsLoss;
}


//######## set functions for rank #######
void Defense::SetInterceptionsRank(int rank) //set function for interception rank
{
	interceptionsRank = rank;
}

void Defense::SetTouchdownsRank(int rank) //set touchdown rank
{
	touchdownsRank = rank;
}

void Defense::SetSoloTacklesRank(int rank) // set solo tackle rank
{
	soloTacklesRank = rank;
}

void Defense::SetAssistedTacklesRank(int rank) // set assited tackles rank
{
	assistedTacklesRank = rank;
}

void Defense::SetTotalTacklesRank(int rank) //set total tackel rank
{
	totalTacklesRank = rank;
}

void Defense::SetTackleForLossYdsRank(int rank) // set tackle for loss of yards rank
{
	yardsLossRank = rank;
}



//######## Get functions for rank ########
int Defense::GetInterceptionsRank() //accessor function for interceptions rank
{
	return interceptionsRank;
}

int Defense::GetTouchdownsRank() //get touchdown rank
{
	return touchdownsRank;
}

int Defense::GetSoloTacklesRank() // get solo tackle rank
{
	return soloTacklesRank;
}

int Defense::GetAssistedTacklesRank() // get assited tackles rank
{
	return assistedTacklesRank;
}

int Defense::GetTotalTacklesRank() // get total tackle rank
{
	return totalTacklesRank;
}

int Defense::GetTackleForLossYdsRank() //get tackle for loss of yards rank
{
	return yardsLossRank;
}