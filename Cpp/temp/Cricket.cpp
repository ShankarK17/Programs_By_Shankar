#include <iostream>
#include <string>

using namespace std;

class Cricket{
	protected: 
		string name;
		int matches;
		string format;
	public:
		Cricket(string name, int matches, string format){
			this->name = name; //this keyword refers to this current object being refer to
			this->matches = matches; // using (->) with 'this' to indicate particualr member being addressed
			this->format = format;
			cout << "\n-----------Player Stats------------\n";
			cout << "Player name: " << this->name << "\n";
			cout << "No of Innings: " << this->matches << "\n";
			cout << "Format: " << this->format << "\n";

		}
		virtual void displayStats() = 0; //Pure virtual function makes the class abstract means , an object of this can't 
						  //be initialized it just serves as blueprint/base for the derived classes.
		~
};

class Batsman : virtual public Cricket{
	protected:
		int total_runs;
		int best_score;
		int not_outs;
	public:
		Batsman(string bat_name, int no_matches, string pformat, int runs, int highest_score, int no)
			: Cricket(bat_name, no_matches, pformat){
			total_runs = runs;
			best_score = highest_score;
			not_outs = no;
		}
		double cal_avg(){
			double avg = total_runs / (matches - not_outs);
			return avg;
		}	
		void displayStats(){
			cout << "Total Runs: " << total_runs << "\n";
			cout << "Best Score: " << best_score << "\n";
			cout << "Average Runs: " << cal_avg() << "\n";
		}
};

class Bowler : virtual public Cricket{
	protected:
		int total_wickets;
		int run_concede;
		double over_bowled;
	public:
		Bowler(string bal_name, int b_matches, string b_format, int wickets, int run_given, int ob)
			: Cricket(bal_name, b_matches, b_format){
			total_wickets = wickets;
			run_concede = run_given;
			over_bowled = ob;
		}	
		double eco_rate(){
			double er = run_concede / over_bowled;
			return er;
		}		
		void displayStats(){
			cout << "Total Wickets: " << total_wickets << "\n";
			cout << "Run Conceded: " << run_concede << "\n";
			cout << "Economy Rate: " << eco_rate() << "\n";
		}
};

class AllRounder: public Batsman, public Bowler{ //multiple inheritance as class Allrounder inherit from classes Batman & Bowler
	public:
		AllRounder(string al_name, int al_matches, string al_format, int al_runs, int al_score, int al_no,
			       	int al_wicket, int al_rc, int al_ob) 
			: Cricket(al_name, al_matches, al_format), 
			  Batsman(al_name, al_matches, al_format, al_runs, al_score, al_no),
			  Bowler(al_name, al_matches, al_format, al_wicket, al_rc, al_ob){}
		void displayStats(){
			Batsman::displayStats();
			Bowler::displayStats();
		}
};

int main(){
	string name, format;
	int innings, runs, highest, notOuts, wickets, conceded_runs;
	double overs;
	cout << "Enter player name: ";
	std::getline(cin, name);
	cout << "Enter Format: ";
	cin >> format;
	cout << "Enter Innings, Runs, Best, Not Outs, Wickets, Runs Conceded, Overs: ";
	cin >> innings >> runs >> highest >> notOuts >> wickets >> conceded_runs >> overs; 
	AllRounder ar1(name, innings, format, runs, highest, notOuts, wickets, conceded_runs, overs);
	ar1.displayStats();
	return 0;
}



		


