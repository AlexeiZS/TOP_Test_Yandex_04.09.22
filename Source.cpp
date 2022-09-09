// не доделанная, не сортирует по алфавиту!!!

#include <iostream>
#include <string>
#include <list>

using namespace std;


struct Participant                  
{
	string id;                     
	string nameDiscip;              
	string  scores;              
	string penalties;          

	~Participant(){}
	void clearPart()
   	{
		id.clear();
		nameDiscip.clear();
		scores.clear();
		penalties.clear();
	};

	void showPart()
	{
		cout <<" id: "<< this->id << endl;
		cout <<" nameDiscip: "<< this->nameDiscip << endl;
		cout <<" scores: "<< this->scores << endl;
		cout <<" penalties: "<< this->penalties << endl;
	}
	void setId(const char ch) 
	{
		this->id.push_back(ch);
	}
	void setNameDiscip(const char ch)
	{
		this->nameDiscip.push_back(ch);
	}
	void setScores(const char ch)
	{
		this->scores.push_back(ch);
	}
	void setPenalties(const char ch)
	{
		this->penalties.push_back(ch);
	}
};


struct Disciplines                     
{
	string discip;                      
	list <Participant> array;         
	string max_quantity;                

	void add_discip( const char ch)
	{
		this->discip.push_back(ch);
	}

	void showDisciplines()
	{
		cout << " discip: " << this->discip << endl;
		cout << " max_guantity: " << this->max_quantity << endl;
		for (auto c : this->array)
			c.showPart();
	}

};


int countSimbol(string str) 
{
	int countsimbol = 0;
	for (int i = 0; i < size(str); i++) {
		if (str[i] != ',')
			countsimbol++;
		else break;
	}
	return countsimbol;
}

int countS(string str) 
{
	int count = 0;
	for (int i = 0; i < size(str); i++) {
		if (str[i] == ',')
			count++;
	}
	return ++count;
}

string maxListElem(list <Participant> list, string maxQuantity)
{
	std::list <Participant> :: iterator Iter;
	std::list <Participant> :: iterator maxIter;
	string maxScor;
	Iter = list.begin();
	maxScor = Iter->scores;
	maxIter = Iter;
	Iter++;
	for (; Iter != list.end(); Iter++) {
		if (maxScor == Iter->scores && stoi(maxQuantity) == 1 && list.size() == 2) {
			if (maxIter->penalties > Iter->penalties) {
				maxIter = Iter;
			}
		}
		else if (maxScor < Iter->scores) {
			maxScor = Iter->scores;
			maxIter = Iter;
		}
	}
	
	return maxIter->id;
}
//output conclusion
void conclusion(Disciplines* disArr,int size)
{
    //list <Participant> :: iterator&& iterPart = disArr[i].array.begin();

	for (int i = 0; i < size; i++) { 
		int maxFin = stoi(disArr[i].max_quantity);
		for (int m = 0; m < maxFin; m++)
			cout << maxListElem(disArr[i].array,disArr[i].max_quantity) << endl;
    }
}

int main()
{
	cout << " Input: " << endl;
	int n;      //quanitity disciplines
	cin >> n;
	Disciplines* disArr = new Disciplines [n]; 
	Participant part;
	int countsimbol=0;                  
	string str;

	for (int j = 0; j < n; j++) {
		cin >> str;
	    countsimbol = countSimbol(str);

		for (int i = 0; i < countsimbol; i++)
			disArr[j].add_discip(str[i]);

		disArr[j].max_quantity = str.back();
	}

    int k;         //number paricipant
    int count;     //number of fields (к-во полей)
	cin >> k;

	for (int i = 0; i < k; i++) {
		cin >> str;
		count = countS(str);
		for (int j = 0; j < size(str); j++) {
			if (str[j] != ',') {
				switch (count) {
				case 1: { part.setPenalties(str[j]);
					break;
				}
				case 2: { part.setScores(str[j]);
					break;
				}
				case 3: { part.setNameDiscip(str[j]);
					break;
				}
				case 4: { part.setId(str[j]);
					break;
				}
				}
			}
			else  --count;
		}
		for (int index = 0; index < n; index++) 
		{
			if(part.nameDiscip == disArr[index].discip)
			disArr[index].array.push_back(part);
		}
		part.clearPart();
	}

	cout << " Conclusion: " << endl;
	conclusion(disArr,n);





 

	//-------------------------------------------

	/*for (int i = 0; i < n; i++) {
		cout << endl;
		disArr[i].showDisciplines();
	}*/

	//-------------------------------------------
 
  	

	//TEST
	/*
	    2
		ear_flying, 1
		sun_bathing, 1
		3
		cheburaschka, ear_flying, 11, 100
		dambo, ear_flying, 10, 0
		crocodile_gena, sun_bathing, 11, 10


		*************************************

		1
		ear_flying, 1
		2
		dambo, ear_flying, 7, 234
		cheburaska, ear_flying, 7, 123

		***************************************

		2
		cloud_developer, 2
		cloud_hacker, 3
		5
		anonymus, cloud_hacker, 6, 0
		bjarne_stroustrup, cloud_developer, 6, 1
		julian_assange, cloud_hacker, 5, 100500
		bill_gates, cloud_developer, 3, 1
		guccifer, cloud_hacker, 2, 0


		***************************************

		2
		sun_charning, 2
		racing, 1
		5
		helios, racing, 12, 135
		acacia, sun_charging, 0, 5
		cactus, sun_charging, 0, 1
		ficus, sun_charging, 0, 4
		palm, sun_charging, 0, 3

*/




	return 0;
}









