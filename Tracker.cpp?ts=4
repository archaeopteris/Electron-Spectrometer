//////////////////////////////////////////////////////////////////////////////
// Program name: Tracker													//
// Author: Voskanyan Haik													//
// Created: 01.05.2012														//
// Last Update: 26.02.2013													//
//																			//
// Description: Program calculates the complex trajectory of electron		//
//				beam traveling throught irregular magnetic fields.			//
//																			//
//				Data was used for construction of a mass spectrometer		//
//				for charged particles to separate particles by energy.		//
//																			//
//				Project was done at Alikhanyan National Science Lboratory	//
//				as a Diploma Work for acquiring bachelor's degree.			//
//																			//
// Some constants: q_el = 1.602,176,487e-19 C [A * s];						//
// m_el = 9.109,382,15e-28 gramm = 0.510,998,910 MeV/c^2;					//
// c = 299,792,458 m/s														//
//																			//
// 1 Gauss = e-4 Tesla[kg/s^2*A];											//
// 1 ev = 1.602178963390210e-19 N * m;										//
// 1 MeV = 1.602178963390210e-6 erg (gramm*cm^2/s^2)						//
// 1.5 MeV = 2.40326484803e-6 erg											//
// 2 Mev = 3.2043531307e-6 erg												//
//																			//
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <math.h>
#include <fstream>
#include <ctime>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Function declaration;
double Horda(double E_el, double BInd);
double YPolinom(double E_el);
void Data_Writer();
void PrintLicense();

// Variable Declaration
double B[81][101] = {1.};
double q_el = 1.602176565;
double m_el = 0.510998910;
double Pi = 3.14159265358;
double R, dL, value, Theta = 0., Th = 0., MeanB = 0., L = 0.;
double xi = 0, yi = 0, sigma = 1, Pol;
double P0 = 0.03253166, P1 = -0.1265110, P2 = 0.5912294, P3 = -1.175531;
double P4 = 1.382875, P5 = -1.063879, P6 = 0.5349297, P7 = -0.1688951;
double P8 = 0.03040903, P9 = -0.002379929;
ofstream XYTheta;

//Function to calculate the turn angle;
double Horda(double E_el, double BInd)
{
	// new
	R = (10000 / (BInd * 0.3)) * sqrt(pow((E_el + m_el),2.) - m_el * m_el);
	dL = 2 * R * sin(0.0017453292519943 / 2); //in mm

	return dL;

	/* Old
	R = (sqrt(2 * E_el * 0.51099891) * 10000) / (0.3 * BInd); //in mm
	dL = 2 * R * sin(0.0017453292519943); //in mm

	return dL;
	*/
}

// Prints data about path of electron in a file.
void Data_Writer(int c)
{
	if(c == 2)
	{
		XYTheta << "The turn angle is " << Theta << " Degrees" << endl;
		XYTheta << "X bin number of electron is " << xi << endl;
		XYTheta << "Y bin number is " << yi << endl;
		XYTheta << "Mean Magnetic Field accrose which travels the electron is ";
		XYTheta << MeanB << " Gauss" << endl;
		XYTheta << "Path that electron travels is " << L/10 << " cantimeters";
		XYTheta << endl;
	}
}

double YPolinom(double E_el)
{
	Pol = P0 + (P1 * E_el) + (P2 * pow(E_el,2.)) + (P3 * pow(E_el,3.));
	Pol += (P4 * pow(E_el,4.)) + (P5 * pow(E_el,5.)) + (P6 * pow(E_el,6.));
	Pol += (P7 * pow(E_el,7.)) + (P8 * pow(E_el,8.)) + (P9 * pow(E_el,9.));
	return Pol;
}

void PrintLicense()
{
	cout << "    Tracker  Copyright (C) 2013  Hayk Voskanyan" << endl;
    cout << "    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'." << endl;
	cout << "    This is free software, and you are welcome to redistribute it" << endl;
	cout << "    under certain conditions; type `show c' for details." << endl;
}

int main()
{
	PrintLicense();
	cout << endl;

	//Declaration of variables;
	double E_el, BInd = 61., xfrac, yfrac, B1, B2;
	double beta = 0.;
	double y = 0., x = 0., x0;
	double Thetavar[930] = {0.};
	double MeanTheta, Rv = 0., Rm = 0.;
	double dTheta = 0.1, En_rand[1001], Rand, Thk, Nmk, Ex, Yn;
	int x_ = 0, y_ = 0, n = 0, N = 0, i = 0;
	int a, b;
	ofstream Hist, Energy, XYGraph, EXYGraph, Phivar, Track, Colimator1, mag;
	ifstream Magnet;

	//Opening files for data manipulations;
	XYTheta.open ("XYTheta.txt",ios::trunc);
	Colimator1.open ("Colimator1.txt",ios::trunc);
	Hist.open ("Histogram.txt",ios::trunc);
	Energy.open ("Energy.txt",ios::trunc);
	XYGraph.open ("XYGraph.txt",ios::trunc);
	EXYGraph.open ("EXYGraph.txt",ios::trunc);
	Phivar.open ("Thetavar.txt", ios:: trunc);
	Magnet.open ("MagnetIS.txt");
	mag.open ("mag.txt", ios::trunc);

	srand (time(NULL));

	//setting up magnetic induction;
	while (!Magnet.eof())
	{
		Magnet >> a >> b >> value;
		B[a][b] = value;
	}

	/*
	//Create a constant field
	for(i = 0; i <= 82; i++)
	{
		for(int k = 0; k <= 94; k++)
		{
			mag << i << "\t" << k << "\t" << B[k][i] << endl;
		}
	}
	*/


	Theta = 0.1;
	Th = 0.;
	MeanB = 0.;
	L = 0.;
	xi = 0.;

	E_el = 1;

	cout << sqrt(2 * E_el * 0.51099891) << endl;
	cout << sqrt(pow((E_el + m_el),2.) - m_el * m_el) << endl;

	cout << "===========================S T A R T O F P R O G R A M========";
	cout << "==============" << endl;
	cout << "What energy electron do you want? (Energy in MeVs) -> ";
	cin >> E_el;
	Ex = E_el;
	cout << "Please inpute bin number in front of which you puted the isotope";
	cout << "\n(numbers from 0 - 80) -> ";
	cin >> x;
	x0 = x;
	y = 0.;
	yi = y;


	Data_Writer(1);

	XYTheta << setw(4) << "X|" << setw(4) << "Y|" << setw(4) << "Theta|" << endl;

	//Tracking Electron trajectory
	while((x <= 80) && (BInd > 39))
	{
		xi = x;
		yi = y;

		//Geting values of magnetic field for x, y;
		modf(x, &xfrac);
		x_ = xfrac;
		modf(y, &yfrac);
		y_ = yfrac;
		B1 = ((y - y_) * (B[x_][y_+1] - B[x_][y_])) + B[x_][y_];
		B2 = ((y - y_) * (B[x_+1][y_+1] - B[x_+1][y_])) + B[x_+1][y_];
		BInd = ((x - x_) * (B2 - B1)) + B1;

		MeanTheta = Theta + 0.05;
		dL = Horda(E_el,BInd); //dL from point x to x+1 in mm;
		L += dL;
		MeanB += BInd;
		n++;

		R = dL / (4 * sin(0.0017453292519943/2)); //R from point x to x+1;
		Rm += R;

		//Calculating passed way of electron through
		//element of lenght on x and y axises
		x += dL * sin(MeanTheta * 0.0174532925199433); //next x in mm;
		y += dL * cos(MeanTheta * 0.0174532925199433); //next y in mm;

		if(y > 80)
		{
			cout << "Y > 82" << endl;
			break;
		}

		//Printing some data;
		// cout << "x = " << xi << "\ty = " << yi << "\tTheta = " << Theta;
		cout << "\t" << BInd << "\t" << dL << endl;
		XYGraph << xi << "\t" << yi << "\t" << Theta << "\t" << BInd;
		XYGraph << "\t" << R << endl;
		Theta += dTheta;
	}

	MeanB = MeanB / n;

	XYTheta << setw(4) << xi << setw(4) << yi << setw(4) << Theta << setw(4);
	XYTheta << MeanB << endl << endl << endl << endl;

	cout << "Input bin number is " << x0 << endl;
	cout << "The turn angle is " << Theta << " Degrees" << endl;
	cout << "X bin number of electron is " << xi << endl;
	cout << "Y bin number is " << yi << endl;
	cout << "Mean Magnetic Field accrose which travels the electron is ";
	cout << MeanB << " Gauss" << endl;
	cout << "Path that electron travels is " << L/10 << " cantimeters";
	cout << endl << endl << endl;
	cout << "Mean dL is " << L/n << endl;
	cout << "mean R is " << Rm/n << endl;
	Data_Writer(2);

	cout << "If you want to redo computing, please press 'R',";
	cout << "\nOtherwise press any other key..." << endl << endl;
	getchar();
	char Y_N = getchar();
	
	if(tolower(Y_N) == 'r')
		return main();

	cout << endl << "Processing Monte Carlo..." << endl;

	Yn = yi;
	n = 0;
	int kp = 0, Enm, Lam = 0;
	double Fexp, th, xk = 0.;
	double Colim2 = 5.;
	double Colim1 = 5.;
	double ThColim = atan((Colim1 + Colim2)/200.) / 0.0174532925199433;
	double EMean = 0., YMean = 0., ThM = 0., BM = 0.;


	while(N < 100000)
	{
		Rand = (rand() % 601);
		E_el = Ex + 0.3 - (Rand / 1000.);
		Enm = Ex * 10;
		switch(Enm)
		{
			case 10 :
				Rand = (rand() % 35397);
				break;
			case 15 :
				Rand = (rand() % 29152);
				break;
			case 20 :
				Rand = (rand() % 15575);
				break;
			default :
				cout << "Error!" << endl << Enm << endl;
				return main();
		}
	
		Rand = Rand / 1000000.;

		if(Rand <= YPolinom(E_el))
		{
			Energy << E_el << endl;
			N++;
			x = x0;
			y = 0;

			Rand = 25 - (rand() % 51);
			th = Rand / 10.;
			Fexp = exp(-(Rand*Rand/100) / (2 * sigma * sigma));
			Rand = (rand() % 101);

			if((Rand/100) <= Fexp)
			{
				Theta = th;
				BInd = 65.;
				Lam = 0;
				MeanB = 0.;
				//Tracking Electron trajectory
				while((x <= 80) && (BInd > 60))
				{
					xi = x;
					yi = y;

					//Geting values of magnetic field for x, y;
					modf(x, &xfrac);
					x_ = xfrac;
					modf(y, &yfrac);
					y_ = yfrac;
					B1 = ((y - y_) * (B[x_][y_+1] - B[x_][y_])) + B[x_][y_];
					B2 = ((y - y_) * (B[x_+1][y_+1] - B[x_+1][y_])) + B[x_+1][y_];
					BInd = ((x - x_) * (B2 - B1)) + B1;


					dL = Horda(E_el,BInd); //dL from point x to x+1 in mm;
					L += dL;
					MeanB += BInd;
					MeanTheta = Theta + 0.05;
					R = dL / (2 * sin(0.0017453292519943)); //R from x to x+1;

					//Calculating passed way of electron through
					//element of lenght on x and y axises
					x += dL * sin(MeanTheta * 0.0174532925199433);
					y += dL * cos(MeanTheta * 0.0174532925199433);

					Theta += dTheta;
					Lam++;
				}
				
				YMean += y;
				kp ++;
				Theta -= dTheta;

				if((yi >= (Yn - (Colim1))) && (yi <= Yn + (Colim1)))
				{
					y += 10. * tan((90. - Theta) * 0.0174532925199433);
					Colimator1 << E_el << "\t" << th << "\t" << Theta << "\t";
					Colimator1 << yi << "\t" << MeanB/Lam << endl;

					if((y <= Yn + (Colim2/2)) && (y > Yn - (Colim2/2)))
					{
						EMean += E_el;
						n++;
						ThM += Theta;

						Hist << E_el << "\t" << th << "\t" << Theta << "\t";
						Hist << yi << endl;
					}
				}
			}
		}
	}

	cout << "Mean output energy is " << EMean/n << endl;
	cout << "Mean output Y is " << YMean/kp << endl;
	cout << "Mean output Theta is " << ThM / n << endl;
	cout << "Number of passed electrons is " << n << endl;


	XYTheta << endl << "\t\t\t\t\t\t\t------------------End------------------";
	XYTheta << endl << endl;

	XYTheta.close();
	Hist.close();
	Energy.close();
	XYGraph.close();
	EXYGraph.close();
	Phivar.close();
	Colimator1.close();

	//Conditions to close the program or to continue working;
	cout << endl << "=============================E N D O F P R O G R A M==";
	cout << "======================" << endl << "Continue? (Y/N) => ";
	Y_N = getchar();

	if(tolower(Y_N) == 'y')
		return main();
	else
	{
		cout << "End of Program"
		return 0;
	}
}
