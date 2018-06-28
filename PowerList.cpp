
#include <boost/filesystem.hpp>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

int main (int argc, char** argv) {
  
    std::string tmp_str;
    std::ofstream ListFile(argv[2]);
    if(!ListFile.is_open()) {
        std::cout<<"\n\nError creating out list !\n\n";
        exit(-2);
    }
    
    for ( boost::filesystem::recursive_directory_iterator end, dir(argv[1]);
         dir != end; ++dir ) {
        if(!is_directory(*dir)) {
            tmp_str = "/";
            tmp_str.append(canonical(*dir).string());
            std::size_t found=tmp_str.find_last_of("\"");
            tmp_str=tmp_str.substr(1,found);
            ListFile << tmp_str << "\n";
            //std::cout << tmp_str << "\n";
            //std::cout << canonical(*dir) << "\n";  // full path
            //std::cout << dir->path().filename() << "\n"; // just last bit
        }
    }
    
    ListFile.close();
    return 0;
    
}







