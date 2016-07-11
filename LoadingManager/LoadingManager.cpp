// LoadingManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	int Eingabe = 1;
	while (Eingabe != 0)
	{
		cout << "Filemanager 0.1" << endl;
		cout << "Datei erstellen -> [1]" << endl;
		cout << "Beenden -> [0]" << endl;

		cin >> Eingabe;

		switch (Eingabe)
		{
		case 1:
		{
			fstream exData;
			string sDataName;

			cout << "Name der Datei: " << endl;
			getline(cin, sDataName);

			exData.open(sDataName, ios::in | ios::out | ios::app);
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
		case 0:
		{
			cout << "Programm wird beendet" << endl;
		}
		}

	}
    return 0;
}

