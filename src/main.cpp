// Include list
#include <fstream>
#include <sstream>
#include <iostream>

#include "absscene.h"
#include "scenes.h"

void retreive_file(struct SCN * scn, std::ifstream& ifs);

int main() {
    // Get all scenes from the scene folder
    // Place the scene inside a list
    std::ifstream file;
    for(int i = 0; i < NUM_OF_SCENES; i++) {
        retreive_file(&SCN[i], file);
    }

    return 0;
}

void retreive_file(struct SCN *scn, std::ifstream& ifs) {

    ifs.clear();
    std::string fileName(scn->addr);

    ifs.open(scn->addr);

    if(!ifs.is_open()) {
        std::cout << "No Such File Exists" << "\n";
    } else {
        std::cout << ifs.rdbuf();
    }
        
}