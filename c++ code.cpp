#include <iostream>
using namespace std;


int main()
{

	// welcome message
	cout << "\n\t\t\t\t <<<<<WELCOME_TO_CALCULATE_THE_COMBUCTION_EQUATION_PROGRAM>>>>> \n\n";
	// get values from user
	cout << "please select the number of fuel & it value \"by w.t.\" : \n\n";
	cout << "\t[1]C   [2]S   [3]H2   [4]CO   [5]O2   [6]CH4   [7]C2H4   [8]C2H2   [9]C3H8   [10]C4H10   [11]C5H12   [12]C2H6 \n"; 
	cout << "\n\t << PRESS \"0\" WHEN YOU END >> \n\n";
	float  C = 0, S = 0, H2 = 0, CO = 0, O2 = 0, CH4 = 0, C2H4 = 0, C2H2 = 0, C3H8 = 0, C4H10 = 0, C5H12 = 0, C2H6 = 0; //percent_fuel
	string fuel_[] = { "C", "S", "H2", "CO", "O2", "CH4", "C2H4", "C2H2", "C3H8", "C4H10", "C5H12", "C2H6" };
	float ffr[] = { C , S , H2 , CO , O2 , CH4 , C2H4 , C2H2 , C3H8 , C4H10 , C5H12 , C2H6 };

	int i;
	cin >> i;
	for (i; i >= 1 && i <= 12;)
	{
		cout << "  " << fuel_[i - 1] << " : ", cin >> ffr[i - 1], cout << endl;
		cin >> i;
	}
	
	// do callculaction
	float O2_wt = 8 * ffr[2] + ffr[1] + (8 * ffr[0] / 3) + (4 * ffr[3] / 7) + 4 * ffr[5] + (24 * ffr[6] / 7) + (40 * ffr[7] / 13) + (40 * ffr[8] / 11) + (26 * ffr[9] / 7) + (32 * ffr[10] / 9) + (56 * ffr[11] / 15);
	O2_wt = (O2_wt - ffr[4]) / 100; //Kg
	float Air_wt = (O2_wt * 100 / 23); //Kg
	float O2_vol = ffr[2] + 2 * ffr[1] + 2 * ffr[0] + ffr[3] + 4 * ffr[5] + 6 * ffr[6] + 5 * ffr[7] + 10 * ffr[8] + 13 * ffr[9] + 16 * ffr[10] + 7 * ffr[11];
	O2_vol = (0.5 * O2_vol - ffr[4]) / 100; //m^3
	float Air_vol = (O2_vol * 100 / 21); //m^3
	
		// output the w.t. of O2 req.
		cout << "\n\n The wight of Oxygen required : <<< " << O2_wt << " >>>" << endl;
		// output the w.t. of Air req.
		cout << " The wight of Air required : <<< " << Air_wt << " >>>" << endl;

		// output the vol. of O2 req.
		cout << "\n\n The Volume of Oxygen required : <<< " << O2_vol << " >>>" << endl;
		// output the vol. of Air req.
		cout << " The Volume of Air required : <<< " << Air_vol << " >>>" << endl;




	return 0;

}
