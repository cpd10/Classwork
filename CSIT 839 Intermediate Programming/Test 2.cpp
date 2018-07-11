#include<iostream>
#include<string>
#include<ctime>
#include<iomanip>
using namespace std;
int main()
{
	string states[120] = { "Afghanistan", "Albania", "Algeria", "Angola", "Armenia", 
		"Austria", "Bangladesh", "Barbados", "Belgium", "Belize", "Bolivia", "Bosnia and Herzegovina", " Botswana", " Bulgaria", 
		"Cambodia", "Chile", "Colombia", "Congo", "Costa Rica", "Croatia", "Cuba", "Cyprus", 
		"Czech Republic", "Denmark", "Dominican Republic", "East Timor", "Ecuador", "Egypt", "El Salvador", "Eritrea", "Estonia", 
		"Ethiopia", "Finland", "Georgia", "Ghana", "Grenada", "Guatemala", "Guinea", "Guyana", "Haiti", "Honduras", "Hungary", 
		"Iceland", "India", "Indonesia", "Iran", "Iraq", "Ireland", "Jamaica", "Jordan", "Kazakhstan", "Kenya", "Korea, North", 
		"Korea, South", "Kosovo", "Kuwait", "Kyrgyzstan", "Laos", "Latvia", "Lebanon", "Liberia", "Libya", "Lithuania", "Macedonia", 
		"Madagascar", "Malaysia", "Moldova", "Mongolia", "Montenegro", "Morocco", "Mozambique", "Myanmar", "Namibia", "Nepal", "New Zealand", 
		"Nicaragua", "Nigeria", "Norway", "Oman", "Pakistan", "Panama", "Paraguay", "Peru", "Philippines", "Poland", "Portugal", "Qatar", 
		"Romania", "Rwanda", "Saudi Arabia", "Senegal", "Serbia", "Sierra Leone", "Singapore", "Slovakia", "Somalia", "South Africa", 
		"Sri Lanka", "Sudan", "Sweden", "Switzerland", "Syria", "Taiwan", "Tajikistan", "Tanzania", "Thailand", "Tunisia", "Turkey", 
		"Turkmenistan", "Uganda", "Ukraine", "United Arab Emirates", "Uruguay", "Uzbekistan", "Venezuela", "Vietnam", "Zambia", "Zimbabwe"};

		string capitals[120] = { "Kabul", "Tirana", "Algiers", "Luanda", "Yerevan", "Vienna", "Dhaka", "Bridgetown", "Brussels", "Belmopan", 
			"Sucre", "Sarajevo", "Gaborone", "Sofia", "Phnom Penh", "Santiago", "Santafe de Bogota", "Kinshasa", "San Jose", "Zagreb", 
			"Havana", "Lefkosia", "Prague", "Copenhagen", "Santo Domingo", "Dili", "Quito", "Cairo", "San Salvador", "Asmara", "Tallinn", 
			"Addis Ababa", "Helsinki", "Tbilisi", "Accra", "St. Georges", "Guatemala City", "Conakry", "Georgetown", "Port-au-Prince", 
			"Tegucigalpa", "Budapest", "Reykjavik", "New Delhi", "Jakarta", "Tehran", "Baghdad", "Dublin", "Kingston", "Amman", "Astana", 
			"Nairobi", "Pyongyang", "Seoul", "Pristina", "Kuwait", "Bishkek", "Vientiane", "Riga", "Beirut", "Monrovia", "Tripoli", "Vilnius", 
			"Skopje", "Antananarivo", "Kuala Lumpur", "Chisinau", "Ulaan Baatar", "Podgorica", "Rabat", "Maputo", "Rangoon", "Windhoek", "Kathmandu", 
			"Wellington", "Managua", "Abuja", "Oslo", "Muscat", "Islamabad", "Panama City", "Asuncion", "Lima", "Manila", "Warsaw", "Lisbon", "Doha", 
			"Bucharest", "Kigali", "Riyadh", "Dakar", "Belgrade", "Freetown", "Singapore", "Bratislava", "Mogadishu", "Pretoria", "Colombo", "Khartoum", 
			"Stockholm", "Bern", "Damascus", "Taipei", "Dushanbe", "Dodoma", "Bangkok", "Tunis", "Ankara", "Ashgabat", "Kampala", "Kiev", "Abu Dhabi", 
			"Montevideo", "Tashkent", "Caracas", "Hanoi", "Lusaka", "Harare" };
		
		int indexes[10], i, loop = 0, right = 0, wrong = 0, number = 1;
		string answer;
		bool correct;
		srand((unsigned)time(0));
		cout << "Enter " << '"' << "quit" << '"' << " to exit quiz:" << endl << endl;
		while (loop < 10)
		{
			i = rand() % 121;
			indexes[loop] = i;

			for (int j = 0; j < loop; j++)
				while (i == indexes[j])
				{
					i = rand() % 10;
					indexes[loop] = i;
				}
					
			cout << number << ". What is the capital of " << states[i] << "? ";
			cin >> answer;
			if (answer == "quit")
				break;
			else if (answer == capitals[i])
			{
				cout << "   Correct!" << endl << endl;
				right++;
			}
			
			else
			{
				while (wrong < 2)
				{
					cout << "   Incorrect! Try again: ";
					cin >> answer;
					correct = false;
					wrong++;
					if (answer == capitals[i])
					{
						cout << "   Correct!" << endl << endl;
						right++;
						correct = true;
						break;
					}
				}
				if (correct == false)
					cout << "   Incorrect! The capital of " << states[i] << " is " << capitals[i] << "." << endl << endl;
			}
			wrong = 0;
			number++;
			loop++;
		}

		cout << "\nScore: " << fixed << setprecision(1) << float(right) / loop * 100 << "%";

		cout << endl << endl;
		system("pause");
		return 0;
}