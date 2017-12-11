//////////////////////////////////////////////////////////////////////////
// Program name: Histogrammer											//
// Author: Voskanyan Haik												//
// Created: 01.05.2012													//
//																		//
// Description: Program creates histograms based on external data		//
//				imported from electron_Distribution.txt					//
//																		//
// This program is wintended to run in CERN's ROOT Data Analyzing		//
// Environment.															//
// Thought there is a way to integrate ROOT in your prefered IDE		//
//																		//
//////////////////////////////////////////////////////////////////////////


//Headers declaration
#include "Riostream.h"
#include "iostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "fstream.h"
#include "string.h"
#include "TH1.h"
#include "TF1.h"
#include "TMath.h"
#include "time.h"

void main()
{
	//Declaration of variables
	double E, Th, Th0, Y;
	int i = 0;
	ifstream f;

	f.open("electron_Distribution.txt");

	if (f.fail())
		return 1;

	//Creating Canvas
	TCanvas *c1 = new TCanvas("Graph","Graph",8000,80,1900,1080);
	c1->SetGrid();

	//Creating histogram
	TH1F *h2 = new TH1F("Histogram","Energy Distribution",10000,0,2.3);

	//Filling histogram
	while (!f.eof())
	{
		f >> E >> Th0 >> Th >> Y;
		h2->Fill(E);
		i++;
	}

	f.close();

	//Drawing options
	h2->Draw("E19");
	h2->GetXaxis()->SetTitle("E (MeV)");
	h2->GetYaxis()->SetTitle("N");
	h2->GetYaxis()->SetTitleFont(61);
	h2->Draw("E19");

	//Fitting in range
	h2->Fit("gaus","","",1.7,2.2);
}

//Various operations on histogram
/*
double Binnum = h1->FindBin(E);
double Binval = h1->GetBinContent(Binnum);
cout << Binval << endl;
*/
