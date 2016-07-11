#include "stdafx.h"

//Convert String to Filename
string cData::convertToFilename(string* p_sName, eDatatype datatype)
{
	switch (datatype)
	{
	case txt:
		return *p_sName + "txt";
		break;
	default:
		cout << "Fehler in cData::convertToFilename(string* sName, eDatatype datatype): datatype existiert nicht!\n";
		return 0;
		break;
	}
}
void cData::writeToList(string* p_sName, eFiletype filetype)
{
	vector<string> vListElement;
	vListElement.push_back(*p_sName);
	switch (filetype)
	{
	case in:
		vListElement.push_back("in");
		break;
	case off:
		vListElement.push_back("out");
		break;
	default:
		cout << "Fehler in cData::writeToList(string* sName, eFiletype filetype): filetype exitiert nicht!\n";
	}

	vDataList.push_back(vListElement);
}

void cData::eraseFromList(string* p_sName)
{
	vector<vector<string>>::iterator vToDelete;

	for (vector<vector<string>>::iterator vi = vDataList.begin(); vi != vDataList.end(); vi++)
	{
		vector<string>::iterator vj = find(vi->begin(), vi->end(), *p_sName);
		if (vj != vi->end())
		{
			vToDelete = vi;
		}
	}

	vDataList.erase(vToDelete);
}

//Opens File without checking if it already exists
void cData::simpOpen(string* p_sName, eFiletype filetype, eDatatype datatype)
{
	
	string sFilename = convertToFilename(p_sName, datatype);
	cout << "Öffne Datei ....\n";
	switch (filetype)
	{
	case in:
	{
		fFile.open(sFilename, ios::in);
		writeToList(p_sName, filetype);
		break;
	}
	case off:
	{
		fFile.open(sFilename, ios::out);
		writeToList(p_sName, filetype);
		break;
	}
	default:
		cout << "Fehler in cData::simpOpen(string* sName, eFiletype filetype, eDatatype datatype): filetype existiert nicht!\n";
		break;
	}

}