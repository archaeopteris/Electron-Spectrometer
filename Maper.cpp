//////////////////////////////////////////////////////////////////////////
// Program name: Maper													//
// Author: Voskanyan Haik												//
// Date created: December.2012											//
//																		//
// Description: Program creats LEGO Plot of the magnetic field,			//
// using data from gaussmeter. Map represents magnetic field			//
// in the middle of gap betwean two magnets.							//
//																		//
// This program is written for CERN's ROOT Data Analyzing Environment	//
// Thought there is a way to integrate ROOT in your prefered IDE		//
//																		//
//////////////////////////////////////////////////////////////////////////

// Header declaration

#include "Riostream.h"
#include "iostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "fstream.h"
#include "string.h"
#include "TH1.h"
#include "TF1.h"
#include "TMath.h"

// Declaration of global variables
double BValue[80][100] = {0.}; //Array for storing Magnetic induction values;
double a, b, value;
int x = 0, y = 0;

void main()
{
	//Creating Canvas for LEGO Plot
	TCanvas *c = new TCanvas("2DGraph","Magnetic Field Maping",0,0,1920,1080);
	TGraph2D *Gr = new TGraph2D();

	//Opening file MagnetIS.txt.txt;
	ifstream f;
	f.open("MagnetIS.txt");

	if(f.fail())
	{
		cout << endl << "Failed to open your file." << endl;
		return 1;
	}

	int i = 0;

	//Reading data from a file;
	while (!f.eof())
	{
		f >> x >> y >> value;
		Gr->SetPoint(i,x,y,value); //Filling Graph with values
		i++;
	}
	f.close();

	//Seting up graph style;
	gStyle->SetPalette(1);
	//visualising graphic;
	Gr->Draw("surf1");
}
