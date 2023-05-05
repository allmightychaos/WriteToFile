#include <iostream>
#include <fstream>

using namespace std;

void writeFile(std::ifstream& infile, std::ofstream& outfile) {
    string line;
    if (getline(infile, line)) {
        outfile << line;
    }
    while (getline(infile, line)) {
        outfile << '\n' << line;
    }
}

void getFile(string inputPath, string outputPath) {
    ifstream infile(inputPath);
    if (!infile) {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }
    if (infile.peek() == ifstream::traits_type::eof()) {
        cerr << "Error: Input file is empty!" << endl;
        return;
    }

    ofstream outfile(outputPath);
    if (!outfile) {
        cerr << "Error: Unable to open output file!" << endl;
        return;
    }

    writeFile(infile, outfile);

    infile.close();
    outfile.close();
}

int main() {
    system("clear");

    string inputPath = "";
    string outputPath = "";
    getFile(inputPath, outputPath);

    return 0;
}
