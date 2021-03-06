#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
#include <string>
#include <exception>
#include <iomanip>
#include <algorithm>

using namespace std;

class Date {
public:
	Date (int y, int m, int d){
		if (m < 1 || m > 12)
			throw 1;
		if (d < 1 || d > 31)
			throw 2;
		year = y;
		month = m;
		day = d;
	}
	int GetYear() const{
		return year;
	};
	int GetMonth() const{
		return month;
	}
	int GetDay() const{
		return day;
	}
private:
int year, month, day;
};

bool operator<(const Date& lhs, const Date& rhs)
{
	return ((lhs.GetYear() * 372) + (lhs.GetMonth() * 31) + lhs.GetDay()) < ((rhs.GetYear() * 372) + (rhs.GetMonth() * 31) + rhs.GetDay());    
}

class Database {
public:
	void PrintDb(map <Date, set <string>> & db){
		for ( const auto & m : db){
			cout << m.second.size() << endl;
		}
	}
		// map <Date, string> events;
	void AddEvent(const Date& date, const string& event){
		db[date].insert(event);
		// PrintDb(db);
	}
  bool DeleteEvent(const Date& date, const string& event){
	  if (db.count(date) > 0){
		  for (const auto &ev : db[date]){
			  if (ev == event){
				  db[date].erase(ev);
				  return true;
			  }
		  }
	  }
	  return false;
  }
  int  DeleteDate(const Date& date){
		int count_event = 0;
		for (const auto &item : db[date]){
			// for (const auto &i : item){
				count_event ++;
			// }
		}	
		db.erase(date);
		return count_event;
}

  void Find(const Date& date){
		vector <string> ev;
		// cout << ">>" << db.count(date) << "<<" << endl;
		
		if (db.count(date) > 0){
			for (const auto & i : db[date])
			{
				ev.push_back(i);
			}
		}
		sort(ev.begin(), ev.end());
		for (const auto & i : ev){
			cout << i << endl;
		}
  }
	
	void Print() const{
		for (const auto & dat : db){
		// Date date = dat.first;
			for (const auto & i : dat.second){
				cout << setw(4) << setfill('0') << dat.first.GetYear();
				cout << "-";
				cout <<setw(2) << setfill('0')  << dat.first.GetMonth();
				cout << "-";
				cout <<setw(2) << setfill('0') << dat.first.GetDay() << " ";
				cout << i << endl;
			}
		}
	}
private:
	map<Date, set<string>> db;
};

void SaveDate(string &year, string &month, string &day, const string &date){
	for (int i = 0; i < date.length(); ++i){
		if (date[0] == '-' || date[0] == '+')
		{
			year.push_back(date[0]);
			i++;
		}
		while (date[i] != '-')
		{
				year.push_back(date[i]);
				// cout << year[j];
				i++;
		}
		// cout << year << "\n";
		i++;
		// f = true;
		while (date[i] != '-'){
			month.push_back(date[i]);
			// cout << month[j];
			i++;
		}
		i++;
		while (i < date.length()){
				day.push_back(date[i]);
				i++;
		}
	}
}

void ExForBrack(string &year, string &month, string &day){

}

bool CheckDate(string & date){
	// Date dat;
	bool flag = false;
	string year, month, day;
	// stringstream yy(year);
	int y = 0, m = 0 ,d = 0;
	SaveDate(year, month, day, date);
			// stringstream intValy(year);
			// intValy >> y;
	ExForBrack(year, month, day);
	try {
		// cout << year << " " << y << endl;
		y = stoi(year);
		m = stoi(month);
		d = stoi(day);

		if (year[0] == '-' || year[0] == '+')
		{
			if (year.length() == to_string(y).length() + 1)
				;
			else
				cout << "Wrong date format: " << date << endl;
		}
		else if (year.length() != to_string(y).length()){
			cout << "Wrong date format: " << date << endl;
		}
		if (month[0] == '+')
		{
			if (month.length() == to_string(m).length() + 1)
				;
			else
				cout << "Wrong date format: " << date << endl;
		}
		else if (month.length() != to_string(m).length()){
			cout << "Wrong date format: " << date << endl;
		}	
		if (day[0] == '+'){
			if (day.length() == to_string(d).length() + 1)
				;
			else
				cout << "Wrong date format: " << date << endl;
		}
		else if (day.length() != to_string(d).length())
			cout << "Wrong date format: " << date << endl;
		// yy >> y1;
		// cout << year << " " << y << endl;
	}catch(const invalid_argument& e){
		cout << "Wrong date format: " << date << endl;
		flag = true;
	}
	if (flag == false){
		try{
			Date(y, m, d);
		} catch (const int f){
			if (f == 1){
				cout << "Month value is invalid: " << m << endl;
			}
			else 
				cout << "Day value is invalid: " << d << endl;
			flag = true;
		}
	}
	return flag;
}

int main() {
	Database db;
	string command, move, event;
	int d1 = 0, m = 0, y = 0;
	string date;
	while (getline(cin, command)) {
			// cout << "="<< command.length() << "=" << endl;
			int cot = count(begin(command), end(command), ' ');
			// cout << "="<< cot << "=" <<endl;
			stringstream ss(command);
			ss >> move;
			ss >> date;
			// cout << date << endl;
			ss >> event;
			// cout << ">>" << event << "<<" << endl;
			if (CheckDate(date) == false){
				string year, month, day;
				SaveDate(year, month, day, date);
				y = stoi(year);
				m = stoi(month);
				d1 = stoi(day);
			}
			else
			{
				// continue;
				exit(1);
			}
			Date d(y, m, d1);
			if (command.length() > 0)
			{
				if (move == "Add"){
				db.AddEvent(d, event);
				}
				else if (move == "Del" && cot == 2){
					if (db.DeleteEvent(d, event))
						cout << "Deleted successfully" << endl;
					else{
						cout << "Event not found" << endl;
					}
				}
				else if (move == "Find" && date.length() != 0){
					// cout << d.GetMonth();
					db.Find(d);
				}
				else if (move == "Del" && cot == 1)
				{
					cout << "Deleted " << db.DeleteDate(d) << " events" << endl;
				}
				else if (move == "Print")
				{
					db.Print();
				}
			}
  	}
	return 0;
}