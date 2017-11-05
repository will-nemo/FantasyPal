/*
Jordan Camejo
Header file for defensive players
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

class Defense
{

public:
	// constroctors
	Defense();																	
	Defense(string fn, string ln, string tn, int interc, int td, int soloTac, int assisTac, int totTac, int ydsLoss);


	//set functions for first, last, and team names
	void SetFirstName(string fn);							
	void SetLastName(string ln);
	void SetTeamName(string tn);


	//get functions for names and associated team name
	string GetFirstName();
	string GetLastName();
	string GetTeamName();


	//set functions for defensive stats  
	void SetInterceptions(int interc);						
	void SetTouchdowns(int tds);
	void SetSoloTackles(int soloTac);
	void SetAssistedTackles(int assisTac);
	void SetTotalTackles(int totTac);
	void SetTackleForLossYds(int ydsLoss);

	//set functions for rank
	void SetInterceptionsRank(int);
	void SetTouchdownsRank(int);
	void SetSoloTacklesRank(int);
	void SetAssistedTacklesRank(int);
	void SetTotalTacklesRank(int);
	void SetTackleForLossYdsRank(int);


	//get functions for stats
	int GetInterceptions();
	int GetTouchdowns();
	int GetSoloTackles();
	int GetAssistedTackles();
	int GetTotalTackles();
	int GetTackleForLossYds();
	// get functions for stat ranks
	int GetInterceptionsRank();
	int GetTouchdownsRank();
	int GetSoloTacklesRank();
	int GetAssistedTacklesRank();
	int GetTotalTacklesRank();
	int GetTackleForLossYdsRank();

private:
	string firstname, lastname, teamname;
	int interceptions, touchdowns, soloTackles, assistedTackles, totalTackles, yardsLoss;
	int interceptionsRank, touchdownsRank, soloTacklesRank, assistedTacklesRank, totalTacklesRank, yardsLossRank;
};
