// LoadingManager.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main()
{
	string sEingabe = "1";
	int Eingabe = 1;
	vector<vector <string>> vDataList;				//1 für out, 2 für in

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
			vector <string> vNewFile;
			vector<vector<string>>::iterator vToDelete;

			cout << "Name der Datei: " << endl;
			getline(cin, sDataName);

			sDataName = sDataName + ".txt";

			// Überprüfen ob die Datei schon existiert
			exData.open(sDataName, ios::in);
			cout << "\n" <<"Momentan geöffnete Dateien: \n";
			vNewFile.push_back(sDataName);
			vNewFile.push_back("in");

			vDataList.push_back(vNewFile);
			vNewFile.erase(vNewFile.begin(), vNewFile.end());

			for (vector<vector<string>>::iterator vi = vDataList.begin(); vi != vDataList.end(); vi++)
			{
				for (vector<string>::iterator vj = vi->begin(); vj != vi->end(); vj++)
				{
					if (vj == vi->end() - 1)
					{
						cout << *vj << "\n";
					}
					else
					{
						cout << *vj << " ";
					}
				}
			}
			
			cout << endl;

			if (!exData)
			{
				cout << "Die Datei existiert nochnicht! Soll eine neue Datei erstellt werden? [Y/N]\n";
				getline(cin, sNewData);

				exData.close();

				cout << "\n" << "Momentan geöffnete Dateien: \n";
				for (vector<vector<string>>::iterator vi = vDataList.begin(); vi != vDataList.end(); vi++)
				{
					vector<string>::iterator vj = find(vi->begin(), vi->end(), sDataName);
					if (vj != vi->end())
					{
						vToDelete = vi;
					}
					else
					{
						cout << sDataName << " konnte nicht aus der Liste entfernt werden! \n";
					}
				}
				vDataList.erase(vToDelete);

				for (vector<vector<string>>::iterator vi = vDataList.begin(); vi != vDataList.end(); vi++)
				{
					for (vector<string>::iterator vj = vi->begin(); vj != vi->end(); vj++)
					{
						if (vj == vi->end() - 1)
						{
							cout << *vj << "\n";
						}
						else
						{
							cout << *vj << " ";
						}
					}
				}

				cout << endl;

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

