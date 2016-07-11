// LoadingManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	string sEingabe = "1";
	int Eingabe = 1;

	while (Eingabe != 0)
	{
		cout << "Filemanager 0.1" << endl;
		cout << "Datei erstellen -> [1]" << endl;
		cout << "Datei laden -> [2]" << endl;
		cout << "Beenden -> [0]" << endl;

		getline(cin, sEingabe); 

		Eingabe = stoi(sEingabe);


		switch (Eingabe)
		{
		case 1:
		{
			fstream exData;
			string sDataName;
			string sNewData;

			cout << "Name der Datei: " << endl;
			getline(cin, sDataName);

			sDataName = sDataName + ".txt";

			// Überprüfen ob die Datei schon existiert
			exData.open(sDataName, ios::in);
			if (!exData)
			{
				cout << "Die Datei existiert nochnicht! Soll eine neue Datei erstellt werden? [Y/N]\n";
				getline(cin, sNewData);

				exData.close();

				if (sNewData == "Y" || sNewData == "y")
				{
					exData.open(sDataName, ios::out | ios::app);
					if (!exData)
					{
						cout << "Die Datei " << sDataName << " konnte nicht geladen werden!" << endl;
					}
					else
					{
						cout << sDataName << " wird geöffnet!" << endl;
					}
					exData.close();
					cout << sDataName << " wurde geschlossen!" << endl;
				}
				else
				{
					cout << "Es wird keine neue Datei erstellt!\n";
				}
			}
			else
			{
				exData.close();
				cout << "Soll diese Datei überschrieben werden? [Y/N]\n";

				getline(cin, sNewData);

				if (sNewData == "Y" || sNewData == "y")
				{
					exData.open(sDataName, ios::out | ios::app);
					if (!exData)
					{
						cout << "Die Datei " << sDataName << " konnte nicht geladen werden!" << endl;
					}
					else
					{
						cout << sDataName << " wird geöffnet!" << endl;
					}
					exData.close();
					cout << sDataName << " wurde geschlossen!" << endl;
				}
				else
				{
					cout << "Die Datei wird nicht überschrieben!\n";
				}
			}
		}
		case 0:
		{
			cout << "Programm wird beendet" << endl;
		}
		}

	}
    return 0;
}

