#include <iostream>
using namespace std;

int main()
{

	// welcome message
	cout << "\n\t\t\t\t <<<<<WELCOME_TO_CALCULATE_THE_COMBUCTION_EQUATION_PROGRAM>>>>> \n\n";
	// get values from user
	cout << "please select the number of fuel & it value \"by w.t.\" : \n\n";
	cout << "\t1<C   2<S   3<H2   4<CO   5<O2   6<CH4   7<C2H4   8<C2H2   9<C3H8   10<C4H10   11<C5H12   12<C2H6 \n";

	cout << "\n\t << PRESS \"0\" WHEN YOU END >> \n\n";
	float  C = 0, S = 0, H2 = 0, CO = 0, O2 = 0, CH4 = 0, C2H4 = 0, C2H2 = 0, C3H8 = 0, C4H10 = 0, C5H12 = 0, C2H6 = 0; //percent_fuel
	string fuel_[] = { "C", "S", "H2", "CO", "O2", "CH4", "C2H4", "C2H2", "C3H8", "C4H10", "C5H12", "C2H6" };
	float ffr[] = { C = 0 , S = 0 , H2 = 0 , CO = 0 , O2 = 0, CH4 = 0, C2H4 = 0, C2H2 = 0, C3H8 = 0, C4H10 = 0, C5H12 = 0, C2H6 = 0 };


	int i;
	cin >> i;
	for (i; i >= 1 && i <= 12;)
	{

		cout << fuel_[i - 1] << " : ", cin >> ffr[i - 1], cout << endl;
		cin >> i;
	}



	// do callculaction
	float O2_x = (((ffr[0] / 100) * 8 / 3) + 8 * (ffr[2] / 100) + (ffr[1] / 100)) - (ffr[4] / 100);  //KG
	float Air_x = (O2_x * 100 / 23);  //KG
	// output the w.t. of O2 req.
	cout << "\n\n The wight of Oxygen required : <<< " << O2_x << " >>>" << endl;
	// output the w.t. of Air req.
	cout << " The wight of Air required : <<< " << Air_x << " >>>" << endl;



	return 0;

}
