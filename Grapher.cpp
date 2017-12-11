//////////////////////////////////////////////////////////////////////////
// Program name: Graph													//
// Author: Voskanyan Haik												//
//																		//
// Description: Program reads data from file electron_Distribution.txt	//
//				and creats Graphs.										//
//																		//
// This program is wintended to run in CERN's ROOT Data Analyzing		//
// Environment.															//
// Although there is a way to integrate ROOT in to your prefered IDE	//
//																		//
//////////////////////////////////////////////////////////////////////////


//Headers Declaration
#include "Riostream.h"
#include "iostream.h"
#include "TFile.h"
#include "TH1F.h"
#include "fstream.h"
#include "string.h"
#include "TH1.h"
#include "TF1.h"
#include "TMath.h"
#include "iomanip.h"



void main()
{
	//Declaration of variables
	double E, Th0, Th, Y;
	int i = 0;
	ifstream f1;
	f1.open("File.txt");

	//Creating Canvas
	TCanvas *c1 = new TCanvas("Graph","Graph",8000,80,1920,1080);
	c1->SetGrid(); //seting a grid on Canvas

	//Creating Graphic
	TGraph *Gr = new TGraph();

	//Filling graph with data
	while (!f1.eof())
	{
		f1 >> E >> Th0 >> Th >> Y;
		Gr->SetPoint(i,E,Th);
		i++;
	}
	
	f1.close();

	//Seting up graphic
	Gr->SetMarkerStyle(20);
	Gr->SetMarkerColor(20);
	Gr->SetLineColor(2);
	Gr->SetMarkerSize(2);


	//visualising graphics;
	Gr->Draw("AP*");
	Gr->GetXaxis()->SetTitle("X-Axis");
	Gr->GetYaxis()->SetTitle("Y-Axis");
	Gr->GetYaxis()->SetTitleFont(61);
	Gr->Draw("AP*");

	gSystem->Unload("Graph.C");
}
