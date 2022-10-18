#include "buffer.h"


void bufer_nusk(std::string read_vardas, std::string write_vardas) {
    vector<std::string> splited;
    string eil;
    stringstream my_buffer;

    auto start = std::chrono::high_resolution_clock::now(); auto st = start;
    std::ifstream open_f(read_vardas);
    my_buffer << open_f.rdbuf();
    open_f.close();
    std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    cout << "Failo nuskaitymas į buferį užtruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    while (my_buffer) {
        if (!my_buffer.eof()) {
            std::getline(my_buffer, eil);
            splited.push_back(eil);
        }
        else break;
    }
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    std::cout << "Buferio padalijimas į eilučių vektorių užtruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    std::string outputas = "";
    for (std::string& a : splited) (a.compare(*splited.rbegin()) != 0) ? outputas += a + "\n" : outputas += a;
    splited.clear();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    cout << "Eilučių vektoriiaus konvertavimas į vieną eilutę užtruko: " << diff.count() << " s\n";

    start = std::chrono::high_resolution_clock::now();
    ofstream out_f(write_vardas);
    out_f << outputas;
    out_f.close();
    diff = std::chrono::high_resolution_clock::now() - start; // Skirtumas (s)
    cout << "Failo įrašymas per vieną eilutę užtruko: " << diff.count() << " s\n";

    diff = std::chrono::high_resolution_clock::now() - st; // Skirtumas (s)
    std::cout << "Visas sugaištas laikas: " << diff.count() << " s\n\n";

}