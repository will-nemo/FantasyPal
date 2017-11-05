Breakdown of how it all works:

getTeamScript.txt:
	-ruby on rails script which needs to be run inside a 'rails console' in the ruby terminal window.
	-to run this download a ruby command prompt that also has rails.
	-the script scrapes data off the internet
Team_file:
	-The team file is a result of running the rails script 'getTeamScript.txt
	-The Team file contains all 32 NFL teams stats and players
loadTeams.txt:
	-loadTeams.txt is a file containing the 32 different names of the files which the executable plans 
	on taking in a input.
	-loadTeams.txt is meant to be executed on the same command line as the executable

Draftkings_2.0.exe:
	-The Executable file. The executable parses through all 32 teams files storing all relevant statistics 
	in vectors and then manipulating the data as such
	-A sample command line call would be: Draftkings_2.0.exe < loadTeams.txt > out.txt
	-In this case out.txt is an output file meant to display the results of the run
	-At the point in time Draftkings_2.0.exe parses through all realevent stats and sorts each player from best
	to worst with respect to each statistic. However there are some bugs involved in the YARDS PER GAME stat

out.txt:
	-An output file containing the result of running the executable

Header_CPP_folder:
	-folder containing all related source code headers and cpp files
	
