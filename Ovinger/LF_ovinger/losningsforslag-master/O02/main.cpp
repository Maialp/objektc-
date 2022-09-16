#include "std_lib_facilities.h"
#include "Graph.h"
#include "AnimationWindow.h"

void inputAndPrintInteger()
{
    int number = 0;
    cout << "Skriv inn et tall: ";
    cin >> number;
    cout << "Du skrev: " << number << '\n';
}

int inputInteger()
{
    int number = 0;
    cout << "Skriv inn et tall: ";
    cin >> number;
    return number;
}

void inputIntegersAndPrintSum()
{
    // Vi bruker inputInteger() her siden den returnerer verdien brukeren skrev inn.
    // inputAndPrintInteger() kan ikke brukes siden den skriver verdien ut til skjerm og returnerer ingenting.
    int firstNumber = inputInteger();
    int secondNumber = inputInteger();
    cout << "Summen av tallene: " << firstNumber + secondNumber << '\n';
}

bool isOdd(int n)
{
    return n % 2;
}

void testIsOdd()
{
    for (int i = 0; i <= 15; ++i)
    {
        if (isOdd(i))
        {
            cout << i << " er et oddetall.\n";
        }
        else
        {
            cout << i << " er et partall.\n";
        }
    }
}

void printHumanReadableTime(int seconds)
{
    int hours = seconds / 3600;
    seconds = seconds % 3600; // Antall sekunder over hele timer
    int minutes = seconds / 60;
    seconds = seconds % 60; // Antall sekunder over hele minutter

    cout << hours << " timer, " << minutes << " minutter og " << seconds << " sekunder.\n";
}
void printHumanReadableTime_V2(int seconds)
{
    // Versjon 2 av denne funksjonen, som skriver ut grammatisk korrekt
    // Kreves ikke for godkjent oving

    int hours = seconds / 3600;
    seconds = seconds % 3600; // Antall sekunder over hele timer
    int minutes = seconds / 60;
    seconds = seconds % 60; // Antall sekunder over hele minutter
    string multiHour;
    string multiMinutes;
    string multiSeconds;
    if (hours != 1)
        multiHour = "r";
    if (minutes != 1)
        multiMinutes = "er";
    if (seconds != 1)
        multiSeconds = "er";

    if (hours > 0)
        cout << hours << " time" << multiHour << ", ";
    if (minutes > 0)
        cout << minutes << " minutt" << multiMinutes << " og ";
    cout << seconds << " sekund" << multiSeconds << ".\n";
}

void testPrintHumanReadableTime()
{
    int nSeconds = inputInteger();
    printHumanReadableTime(nSeconds);
}

void testPrintHumanReadableTime_V2()
{
    int nSeconds = inputInteger();
    printHumanReadableTime_V2(nSeconds);
}

// 2a - for, beste egnet naar antall tall er kjent i forkant av lokken
void inputIntegersUsingForLoopAndPrintSum()
{
    int nTerms = 0;
    cout << "Hvor mange tall vil du summere? ";
    cin >> nTerms;

    int sum = 0;
    int term = 0;
    for (int i = 0; i < nTerms; i++)
    {
        term = inputInteger();
        sum += term;
    }
    cout << "Summen av tallene: " << sum << '\n';
}

// 2b - While, best egnet naar en avslutter med aa angi tallet 0
void inputIntegersUsingWhileLoopAndPrintSum()
{
    cout << "Skriv inn de tallene du vil summere.\n"
            "Skriver du inn 0 avsluttes lokken og summen skrives ut.\n";

    int sum = 0;
    int term = inputInteger();
    while (term != 0)
    {
        sum += term;
        term = inputInteger();
    }

    cout << "Summen av tallene: " << sum << '\n';
}

// 2b - Do-While, alternativ losning
// Merk at do-while lokken er ganske lite brukt og i PPP-boka er den ikke dekket, saa den er ikke
// pensum
void inputIntegersUsingDoWhileLoopAndPrintSum()
{
    cout << "Skriv inn tall du vil summere.\n"
            "Skriver du inn 0 avsluttes lokken og summen skrives ut.\n";

    int sum = 0;
    int term = 0;
    do
    {
        term = inputInteger();
        sum += term;
    } while (term != 0);

    cout << "Summen av tallene: " << sum << '\n';
}

double inputDouble()
{
    double number = 0;
    cout << "Skriv inn et tall: ";
    cin >> number;
    return number;
}

void convertNOKtoEUR()
{
    double nok = -1.0;
    while (nok < 0.0)
        nok = inputDouble();

    double eur = nok / 9.75; // Vekslingskurs kan bestemmes selv
    cout << setprecision(2) << fixed << nok << " NOK er " << eur << " EUR\n";
}

// I convertNOKtoEUR() bruker vi inputDouble() fordi vi ikke er ute etter et heltall,
// men et flyttall (desimaltall). Returtypen til inputDouble() er double, et såkalt
// "double precision floating point number".

void printMultiplicationTable()
// setw() brukes her for å gjøre bredden av hver kolonne lik, slik at tall fra samme
// kolonne blir vist rett over hverandre (også når antall siffer i tallene er ulike).
{
    int height = 0;
    int width = 0;
    cout << "Hoyde: ";
    cin >> height;
    cout << "Bredde: ";
    cin >> width;
    for (int x = 1; x <= height; x++)
    {
        for (int y = 1; y <= width; y++)
        {
            cout << setw(8) << x * y;
        }
        cout << '\n';
    }
}

double discriminant(double a, double b, double c)
{
    return pow(b, 2.0) - 4.0 * a * c;
}

void printRealRoots(double a, double b, double c)
{
    double d = discriminant(a, b, c);
    if (d > 0.0)
    {
        double firstSolution = (-b + sqrt(d)) / (2.0 * a);
        double secondSolution = (-b - sqrt(d)) / (2.0 * a);
        cout << "Losning 1: " << firstSolution << '\n';
        cout << "Losning 2: " << secondSolution << '\n';
    }
    else if (d == 0.0)
    {
        double solution = -b / (2.0 * a);
        cout << "Losning: " << solution << '\n';
    }
    else /* (d < 0.0) */
    {
        cout << "Ingen reelle losinger.\n";
    }
}

void solveQuadraticEquations()
{
    double a = 0.0;
    double b = 0.0;
    double c = 0.0;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;
    cout << "C: ";
    cin >> c;
    printRealRoots(a, b, c);
}

void pythagoras()
{
    using namespace Graph_lib;

    AnimationWindow win{100,100, 400, 400, "Pythagoras"};

    Point init{170,250};
	int a = 60;
	int b = 100;

    Point point1{init.x, init.y};
	Point point2{init.x + a, init.y};
	Point point3{init.x, init.y - b};
	win.draw_triangle(point1, point2, point3, Color::black);

    win.draw_quad(point3, point2, Point{init.x + a + b, init.y - a}, Point{init.x + b, init.y - a - b}, Color::yellow);

	win.draw_quad(point2, point1, Point{init.x, init.y + a}, Point{init.x + a, init.y + a},  Color::red);

	win.draw_quad(point1, point3, Point{init.x - b, init.y - b}, Point{init.x - b, init.y},  Color::white);


	win.wait_for_close();
    
}

vector<int> calculateBalance(int amount, int rate, int years)
{
    vector<int> balanceVec;
    for (int i = 0; i <= years; i++)
    {
        balanceVec.push_back(amount * pow((1 + static_cast<double>(rate) / 100), i));
    }

    /* Alternativt
    vector<int> balanceVec{years + 1};
    for (int i = 0; i <= years; i++){
        balanceVec[i] = amount * pow((1 + static_cast<double>(rate)/100), i);
    }
    */
    return balanceVec;
}

void printBalance(vector<int> balanceVec)
{
    cout << setw(4) << "Ar:" << setw(7) << "Saldo:" << '\n';
    for (unsigned int i = 0; i < balanceVec.size(); i++)
    {
        cout << setw(3) << i << setw(7) << balanceVec[i] << '\n';
    }
}

int main()
{

    int choice = -1;
    while (choice != 0)
    {
        cout << "0) Avslutt \n"
             << "1) Summer to tall\n"
             << "2) Test oddetallsfunksjonen\n"
             << "3) Konverter sekunder\n"
             << "4) Summer flere tall (for)\n"
             << "5) Summer flere tall (while)\n"
             << "6) Summer flere tall (do-while)\n"
             << "7) Konverter NOK til EURO\n"
             << "8) Skriv ut gangetabell\n"
             << "9) Los kvadratiske ligninger\n"
             << "10) Pythagoras\n"
             << "11) Regn ut renter\n";
        cout << "Angi valg (0-11): ";

        cin >> choice;
        cout << '\n';
        switch (choice)
        {
        case 0:
            break;
        case 1:
            inputIntegersAndPrintSum();
            break;
        case 2:
            testIsOdd();
            break;
        case 3:
            testPrintHumanReadableTime();
            // testPrintHumanReadableTime_V2();
            break;
        case 4:
            inputIntegersUsingForLoopAndPrintSum();
            break;
        case 5:
            inputIntegersUsingWhileLoopAndPrintSum();
            break;
        case 6:
            inputIntegersUsingDoWhileLoopAndPrintSum();
            break;
        case 7:
            convertNOKtoEUR();
            break;
        case 8:
            printMultiplicationTable();
            break;
        case 9:
            solveQuadraticEquations();
            break;
        case 10:
            pythagoras();
            break;
        case 11:
        {
            // Maa opprette et skop med { og }. Man kan ikke definere nye variabler i en vanlig switch-case
            vector<int> moneyVec = calculateBalance(10'000, 5, 10);
            printBalance(moneyVec);
            // Alternativt uten skop:
            // printBalance(calculateBalance(10'000, 5, 10));
            break;
        }
        default:
            cout << "Ugyldig valg\n";
        }
        cout << '\n';
    }
}
