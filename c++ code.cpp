#include <iostream>
using namespace std;

string fuel_[] = { "C", "S", "H2", "CO", "O2", "CH4", "C2H4", "C2H2", "C3H8", "C4H10", "C5H12", "C2H6" };
float  C, S, H2, CO, O2, CH4, C2H4, C2H2, C3H8, C4H10, C5H12, C2H6; //percent_fuel
float  ffr[] = { C, S, H2, CO, O2, CH4, C2H4, C2H2, C3H8, C4H10, C5H12, C2H6 };
float  O2_wt;
float  Air_wt;
float  O2_vol;
float  Air_vol;
bool   quant;

bool quantity() {

	while (true) {
		int q = 0;
		cin >> q;
		switch (q) {
		case 1:
			return true; break;   // for weight decision //
		case 2:
			return false; break;  // for volume decision //
		default:
			cout << "\t \" wrong value: Enter value between range \" " << endl;
		}
	}
}

void getInput() {

	for (int i = 1; i > 0 && i < 13; i++) // remove values and set them as default //
	{
		ffr[i] = 0;
	}
	float NumOfFuel;
	int IndexTurn;
	while (true) {

		// get values from user
		cin >> NumOfFuel;
		IndexTurn = NumOfFuel;
		if (fmod((NumOfFuel * 2), 2) == 0 && NumOfFuel >= 1 && NumOfFuel <= 12) // decimal number NOT ALLOWED
			cout << "  " << fuel_[IndexTurn - 1] << " : ", cin >> ffr[IndexTurn - 1], cout << endl;
		else if (NumOfFuel == 0) // END Setting Values
			break;
		else
			cout << "\t \" wrong value: Enter value between range \" " << endl;
	}
}

void calculate() {

	// do calculations
	if (quant)  // equal true
	{
		O2_wt = 8 * ffr[2] + ffr[1] + (8 * ffr[0] / 3) + (4 * ffr[3] / 7) + 4 * ffr[5] + (24 * ffr[6] / 7) + (40 * ffr[7] / 13) + (40 * ffr[8] / 11) + (26 * ffr[9] / 7) + (32 * ffr[10] / 9) + (56 * ffr[11] / 15);
		// Subtract the required oxygen from the existing oxygen 
		O2_wt -= ffr[4]; //Kg
		Air_wt = (O2_wt * 100 / 23); //Kg
	}
	else         // equal false
	{
		O2_vol = (ffr[2] + 2 * ffr[1] + 2 * ffr[0] + ffr[3] + 4 * ffr[5] + 6 * ffr[6] + 5 * ffr[7] + 10 * ffr[8] + 13 * ffr[9] + 16 * ffr[10] + 7 * ffr[11]) * 0.5;
		// Subtract the required oxygen from the existing oxygen
		O2_vol -= ffr[4]; //m^3
		Air_vol = (O2_vol * 100 / 21); //m^3
	}
}

void displayOutput() {

	if (quant)  // equal true
	{
		// output the w.t. of O2 req.
		cout << "\n\n The weight of Oxygen required : " << O2_wt << " kg" << endl;
		// output the w.t. of Air req.
		cout << " The weight of Air required : " << Air_wt << " kg" << endl;
	}
	else        // equal false
	{
		// output the vol. of O2 req.
		cout << "\n\n The Volume of Oxygen required : " << O2_vol << " m3" << endl;
		// output the vol. of Air req.
		cout << " The Volume of Air required : " << Air_vol << " m3" << endl;
	}
}

int main()
{
	// welcome message
	cout << "\n\t\t\t\t <<<<<WELCOME_TO_CALCULATE_THE_COMBUCTION_EQUATION_PROGRAM>>>>> \n\n";
	cout << "  Choose type of input quantity \n" << "\t\t\t [1] Weight \t\t [2] Volume" << endl;
	quant=quantity();
	cout << "please select the number of fuel & it value By \"w.t.\" or \"vol.\" : \n\n";
	cout << "\t[1]C   [2]S   [3]H2   [4]CO   [5]O2   [6]CH4   [7]C2H4   [8]C2H2   [9]C3H8   [10]C4H10   [11]C5H12   [12]C2H6 \n";
	cout << "\n\t << PRESS \"0\" WHEN YOU END >> \n\n";
	getInput();
	calculate();
	displayOutput();

	return main();
}
