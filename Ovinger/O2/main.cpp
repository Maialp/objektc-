
#include "std_lib_facilities.h"

// Oppgave 1 a)
void inputAndPrintInteger(){
	int tallet = 0;
	
	cout << "Skriv et tall: ";
	cin >> tallet;

	cout << "Du skrev: " << tallet << '\n';
}

//Oppgave 1 b)
int inputInteger(){
	int tall = 0;

	cout << "Skriv inn et tall: ";
	cin >> tall;

	return tall;
}

//Oppgave 1 c) 
void inputIntegersAndPritSum(){
	int a = inputInteger();
	int b = inputInteger();

	cout << "Summen av tallene er: " << a + b << '\n';
}

//Oppgave 1 d) 
//Jeg valgte å benytte inputInteger() da denne returnerer input-verdien.
//Hadde jeg valgt den andre ville jeg ikke fått ut noen verdier jeg kunne brukt videre, 
//selv om de blir printet til skjerm.
//

//Oppgave 1 e) 
bool isOdd(int x){
	if(x%2 == 1){
		return true;
	}
	else {
		return false;
	}
}

//Oppgave 1 f)
void printHumanReadableTime(int tid){
	int timer = tid/3600;
	int rest = tid - timer*3600;

	int minutter = rest/60;
	int sekunder = tid - timer*3600 - minutter*60;

	cout << timer << " timer, " << minutter << " minutter og " << sekunder  << "sekunder. \n";

}

//-----------------------------------------------------------------------------------------------------
//Oppgave 2a)
void sumAsManyAsYouWant(){
	int antall = 0;
	int sum = 0;
	
	cout << "Hvor mange tall ønsker du å summere? ";
	cin >> antall;

	for (int i = 0; i < antall; ++i){
		int tall = 0;
		cout << "Pluss på: ";
		cin >> tall;

		sum+=tall;
	}
	cout << "Summen av tallene er: "<< sum << '\n';
}	

//Oppgave 2b)
void sumUntilZero(){
	int tall = 1;
	int sum = 0;

	while (tall != 0){
		cout << "Pluss på: ";
		cin >> tall;

		sum+=tall;
	}
	
	cout << "Summen av alle tallene er " << sum << '\n';
	
}

//Oppgave 2c)
//Jeg har brukt en for-løkke i 2a). Her vet jeg på forhånd av løkken hvor mange gnager koden skal kjøre.
//I 3b) ønsker jeg at løkken skal kjøre så lenge noe er sant, uten at antallet ganger er relevant. 
//Derfor brukte jeg en while-løkke. 

//Oppgave 2d)
double inputDouble(){
	double tall = 0.0;

	cout << "Skriv inn et desimaltall: ";
	cin >> tall;

	return tall;
}

//Oppgave 2 e)
void NOKtoEuro(){
	double nok = 0.0;

	cout << "Skriv inn et beløp du ønsker å veksle: ";
	cin >> nok;

	while(nok < 0){
		cout << "Vennigst skriv inn et positivt beløp: ";
		cin >> nok;
	}

	double euro = nok*0.097;

	cout.precision(2);
	cout << nok << "kr tilsvarer "<< fixed << euro << " Euro \n" ;

}

//Oppgave 2 f)
// En double kan være større, men reseverer mer plass i minnet. 
//Dette betyr også at doubble vil ta mer tid å regne med, men siden 
//forskjellen ikke er så stor når man ikke kjører store data, brukes ofte 
//double som defult, da den er mer presis. 

//-----------------------------------------------------------------------------------
//Oppgave 3b) 
void gangetabell(){
	int height = 0;
	int width = 0;

	cout << "Bredde: ";
	cin >> width;

	cout << "Høyde: ";
	cin >> height;

	for (int i = 1; i <= height; i++){
		for(int j = 1; j <= width; ++j){
			cout  << setw(6)<< i << '*' << setw(2)<< j << '=' << setw(3) <<i*j;
		}
		cout << '\n';
	}
}

//-----------------------------------------------------------------------------------
//Oppgave 4a)
double discriminant(double a, double b, double c){
	return b*b - 4*a*c;
}

//Oppgave 4b) 
void printRealRoots(double a, double b, double c){
	double root = discriminant(a,b,c);
	
	#include <math.h>
	if (root > 0){
		double x1 = (-b + sqrt(root))/(2*a);
		double x2 = (-b - sqrt(root))/(2*a);
		cout << "De reelle røttene er: " << x1 << " og "<< x2 << '\n';
	}
	else if (root == 0){
		double x = -b/(2*a);
		cout << "Du har et fullstedig kvadrat med x = "<< x << '\n';
	}
	else{
		cout << "Ligningen har ingen reelle løsninger. \n";
	}
}

//Oppgave 4c) 
void solveQuadraticEquation(){
	double a = 0;
	double b = 0;
	double c = 0;

	cout << "Skriv inn parameter a: ";
	cin >> a;
	cout << "Skriv inn parameter b: ";
	cin >> b;
	cout << "Skriv inn parameter c: ";
	cin >> c;

	printRealRoots(a,b,c);
}


//-----------------------------------------------------------------------------------
//Oppgave 5 
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"

void pythagoras(){
	using namespace Graph_lib;

	int h = 500;
	int w = 500;
	Simple_window win{Point{100,100}, w, h, "Pythagoras"};

	Polygon rightTriangle;
	rightTriangle.add(Point{200,300});
	rightTriangle.add(Point{350,300});
	rightTriangle.add(Point{200,200});
	rightTriangle.set_fill_color(Color::dark_gray);
	rightTriangle.set_color(Color::black);
	win.attach(rightTriangle);

	Polygon squareA;
	squareA.add(Point{200,300});
	squareA.add(Point{200,200});
	squareA.add(Point{100,200});
	squareA.add(Point{100,300});
	squareA.set_fill_color(Color::red);
	squareA.set_color(Color::dark_red);
	win.attach(squareA);

	Polygon squareB;
	squareB.add(Point{200,300});
	squareB.add(Point{200,450});
	squareB.add(Point{350,450});
	squareB.add(Point{350,300});
	squareB.set_fill_color(Color::blue);
	squareB.set_color(Color::dark_blue);
	win.attach(squareB);

	Polygon squareC;
	squareC.add(Point{350,300});
	squareC.add(Point{450,150});
	squareC.add(Point{300,50});
	squareC.add(Point{200,200});
	squareC.set_fill_color(Color::yellow);
	squareC.set_color(Color::dark_yellow);
	win.attach(squareC);

	win.wait_for_button();
}


//-----------------------------------------------------------------------------------
//Oppgave 6 a) 

vector<int> calculateBalance(double saldo, int rent, int years){
 	vector<int> rents(years);
	rents[0] = saldo;
	for(int i = 1; i <= years; ++i){
		rents[i] = saldo = (saldo)*(1+(rent/100.));
	}
	return rents;
}

//Oppgave 6 b) 
void printBalance(){
	int a = 0, b = 0, c = 0;

	cout << "Skriv inn din nåværende saldo: ";
	cin >> a;

	cout << "Skriv inn renten på kontoen din: ";
	cin >> b;

	cout << "Hvor mange år ønsker du å sjekke saldo? ";
	cin >> c;

	vector<int> balance = calculateBalance(a,b,c);

	cout << "År: " << setw(13) << "Saldo: \n";

	for(int i = 0; i <= c; ++i){
		cout << setw(3)<< i << setw(10) << balance[i] << '\n';
	}
}


int main()
{


// 	Menysystem:
	
	cout << "Velg funskjon: \n";
	cout << "0) Avslutt \n";
	cout << "1) Summér to tall \n";
	cout << "2) Summér flere tall \n";
	cout << "3) Konverter NOK til EURO \n";
	cout << "4) Skriv ut gangetabell-tabell \n";
	cout << "5) Løs en andregradsligning på formen a*x*x + b*x + c = 0 \n";
	cout << "6) Tegn Pythagoras sitt teorem \n";
	cout << "7) Sjekk konsekvensene av din rente \n";

	
	int valg = -1;
	cin >> valg;


	switch (valg){
	case 0:
		cout << "Avslutter \n";
		break;
	case 1:
		inputIntegersAndPritSum();
		break;
	case 2:
		sumAsManyAsYouWant();
		break;
	case 3:
		NOKtoEuro();
		break;
	case 4:
		gangetabell();
		break;
	case 5:
		solveQuadraticEquation();
		break;
	case 6:
		pythagoras();
		break;
	case 7:
		printBalance();
		break;
	default:
		break;
	} 


}