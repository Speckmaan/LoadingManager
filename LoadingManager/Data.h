#ifndef DATA_H
#define DATA_H
#pragma once

//Forward declerations

//Headers needed
#include <vector>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class cData
{
private:
	fstream fFile;									//File object
	string sFilename;								//Filename

	vector<vector<string>> vDataList;				//List of all open fstream objects (1. Name, 2. in or out)

	enum eFiletype									//Filetype (Input/Output)
	{
		off,
		in
	};

	enum eDatatype
	{
		txt
	};

	void simpOpen(string* p_sName, eFiletype filetype, eDatatype datatype);

	void writeToList(string* p_sName, eFiletype filetype);
	void eraseFromList(string* p_sName);

	string convertToFilename(string* p_sName, eDatatype datatyp);

public:
};

#endif