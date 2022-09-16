#include "FileUtils.h"

void writeUserInputToFile()
{
	const string filename{"outputfile.txt"};
	ofstream outFile{filename};
	if (!outFile)
	{
		error("Couldn't open file: ", filename);
	}

	cout << "Write some words, they will be output in the file"
			" \"outputfile.txt\", every word on separate lines."
			" quit exits\n> ";

	for (string word; cin >> word && word != "quit";)
	{
		outFile << word << '\n';
	}
}

void addLineNumbers(const string& filename)
{
	ifstream inFile{filename};
	if (!inFile)
	{
		error("Couldn't open file: ", filename);
	}

	ofstream outFile{filename + ".linum"};
	if (!outFile)
	{
		error("Couldn't open file: ", filename + ".linum");
	}

	int lineNumber = 1;
	for (string line; getline(inFile, line); ++lineNumber)
	{
		outFile << lineNumber << ": " << line << '\n';
	}
}

// losning med vector
void characterStatistics(const string& filename)
{
	ifstream inFile{filename};
	if (!inFile)
	{
		error("Couldn't open file: ", filename);
	}

	vector<int> stats(26); // ev. std::array<int, 26>
	for (unsigned char c; inFile >> c;) {
		if (isalpha(c)) {
			++stats[tolower(c) - 'a'];
		}
	}

	for (char c = 'a'; c <= 'z'; ++c) {
		cout << c << ": " << stats[c - 'a'] << '\t';
		if (c % 3 == 0) {
			cout << '\n';
		}
	}
}

// losning med map
void characterStatisticsV2(const string& filename) {
	map<char, int> charOccurences;

    ifstream inFile{filename};
    if (!inFile) {
        error("Couldn't open file: ", filename);
    }

    for (unsigned char c; inFile >> c;) {
        if (isalpha(c))
		{
			// std::map::operator[] default-initialiserer et element hvis det ikke finnes.
			// Første oppslag vil derfor sette antall til 0
			++charOccurences[tolower(c)];
		}
	}

	// C++ 14 og tidligere
	// for (const auto& c : charOccurences) {
    //     cout << c.first << ": " << c.second << "\t";
	// 	if (c.first % 3 == 0) {
	// 		cout <<'\n';
	// 	}
    // }

	// Med C++ 17 structured bindings
	for (const auto& [letter, count] : charOccurences) {
        cout << letter << ": " << count << "\t";
		if (letter % 3 == 0) {
			cout << '\n';
		}
    }
}
