#ifndef  FILE_H
#define  FILE_H
#include <sstream>
#include <fstream>
#include "vector.h"
#include "pair.h"

std::string get_path() {
    std::string path;
    do {
        std::cout << "Enter the file path:";
        std::cin >> path;
        std::ifstream in(path);
        if (!in.is_open()) {
            std::cout << "Ooops.....Something went wrong......" << std::endl;
        }
        else {
            in.close();
            return path;
        }
    } while (true);
}


vector<vector<pair<int, int>>> parseAdjacencyList(const std::string& filename, int &n) {
    std::ifstream file(filename);
    vector<vector<pair<int, int>>> graph;

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string index;
        std::getline(iss, index, ':');

        vector<pair<int, int>> current;
        std::string pairStr;

        while (std::getline(iss, pairStr, ')')) {
            if (pairStr.empty()) continue; 

            size_t pos = pairStr.find('(');
            if (pos != std::string::npos) {
                std::string numbers = pairStr.substr(pos + 1);
                std::istringstream numStream(numbers);
                int first, second;


                if (numStream >> first) {
                    numStream.ignore(); 
                    if (numStream >> second) {
                        current.push_back({ first ,second });
                    }
                }
            }
        }
        n++;
        graph.push_back(current);
    }

    file.close();
    return graph;
}


void writeResultsToFile(const vector<int>& dist, const vector<int>& up, const std::string& filename) {
    std::ofstream outFile(filename);

    outFile << "Distances:" << std::endl;
    for (size_t i = 0; i < dist.size(); ++i) {
        outFile << "dist[" << i << "] = " << dist[i] << std::endl;
    }

    outFile << "Paths (up):" << std::endl;
    for (size_t i = 0; i < up.size(); ++i) {
        outFile << "up[" << i << "] = " << up[i] << std::endl;
    }

    outFile.close();
}

#endif 