#include <iostream>     	// for cout, cin
#include <fstream>      	// for ifstream
#include <sstream>      	// for stringstream
#include <filesystem>   	// making inputting files easier
#include <unordered_set>	// containers for the wikiscraper
#include <vector>
#include <queue>
#include <unordered_map>
#include "wikiscraper.h"    // wikiscraper methods

using std::cout;            using std::endl;
using std::ifstream;        using std::stringstream;
using std::string;          using std::vector;
using std::priority_queue;  using std::unordered_map;
using std::unordered_set;   using std::cin;

int main() {
    // a quick working directory fix to allow for easier filename inputs
    auto path = std::filesystem::current_path() / "res/";
    std::filesystem::current_path(path);
    std::string filenames = "Available input files: ";
    for (const auto& entry : std::filesystem::directory_iterator(path)) {
        std::string filename = entry.path().string();
        filename = filename.substr(filename.rfind("/") + 1);
        filenames += filename + ", ";
    }
    // omit last ", ".
    cout << filenames.substr(0, filenames.size() - 2) << "." << endl;

    /* Container to store the found ladders in */
    vector<vector<string>> outputLadders;

    cout << "Enter a file name: ";
    string filename;
    getline(cin, filename);

    /* 
        TODO: Create a filestream from the filename.
        For each pair {start_page, end_page} in the input file,
        retrieve the result of findWikiLadder(start_page, end_page)
        and append that vector to outputLadders.
    */
    // Write code here
    ifstream in(filename, std::ios::in);
    if (!in)
    {
        cout << "cannot open file " << filename << endl;
        exit(EXIT_FAILURE);
    }

    int num;
    in >> num;

    for (int i = 0; i < num; i++)
    {
        string start_page, end_page;
        in >> start_page >> end_page;
        outputLadders.push_back(findWikiLadder(start_page, end_page));
    }

    /*
     * Print out all ladders in outputLadders.
     * We've already implemented this for you!
     */
    // Write code here
    for (auto &words : outputLadders)
    {
        if (!words.empty())
        {
            cout << "====================================" << endl;
            cout << "Start page :\t" << words.at(0) << endl;
            cout << "End page :\t" << words.at(words.size() - 1) << endl;
            cout << "====================================" << endl;
            cout << endl;

            for (int i = 0; i < words.size() - 1;i++)
            {
                cout << "{";
                for (auto it = words.begin(); it <= words.begin() + i;)
                {
                    cout << *it << (++it <= words.begin() + i ? ", " : "");
                }
                cout << "}" << endl;
            }
            cout << endl;

            cout << "Ladder found:" << endl;
            cout << "\t\t";
            for (auto it = words.begin(); it != words.end();)
            {
                cout << *it << (++it != words.end() ? " -> " : "");
            }
            cout << endl;
            cout << endl;
        }
    }

    return 0;
}




