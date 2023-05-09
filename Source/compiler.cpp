#include <iostream>
#include <fstream>
#include <string>
int main( int argc, char *argv[] )
{
      if (argc >= 2)
   {
      char *outname;
      if (argc >= 3){
        outname = argv[2];
      } else {
        outname = "a.max";
      }
      std::ifstream filein (argv[1]);
      std::ofstream fileout (outname);
      if (filein.is_open())
        {
          std::string line;
          while (std::getline(filein, line))
            {
                if (line.substr(0,2) =="IN"){
                  fileout << "9A ";
                  if (line.substr(3,2) == "A1"){
                    fileout << "1A "<< line.substr(6, line.length()-6) << " ";
                  } else if (line.substr(3,2) == "B1"){
                    fileout << "1B "<< line.substr(6, line.length()-6) << " ";
                  } else if (line.substr(3,2) == "C1"){
                    if (line.substr(6,1) == "T"){
                      fileout << "1C TT ";
                    } else if (line.substr(6,1) == "F"){
                      fileout << "1C FF ";}
                  } else if (line.substr(3,2) == "A2"){
                    fileout << "2A "<< line.substr(6, line.length()-5) << " ";
                  } else if (line.substr(3,2) == "B2"){
                    fileout << "2B "<< line.substr(6, line.length()-5) << " ";
                  } else if (line.substr(3,2) == "C2"){
                    if (line.substr(6,1) == "T"){
                      fileout << "2C TT ";
                    } else if (line.substr(6,1) == "F"){
                      fileout << "2C FF ";}
                  }
                  }
                if (line.substr(0,5) == "PRINT"){
                  fileout << "9B ";
                  if (line.substr(6,2) == "A1"){
                    fileout << "1A ";
                  } else if (line.substr(6,2) == "B1"){
                    fileout << "1B ";
                  } else if (line.substr(6,2) == "C1"){
                    fileout << "1C ";
                  } else if (line.substr(6,2) == "A2"){
                    fileout << "2A ";
                  } else if (line.substr(6,2) == "B2"){
                    fileout << "2B ";
                  } else if (line.substr(6,2) == "C2"){
                    fileout << "2C ";
                  }
                }
                if (line.substr(0,3) == "ADD"){
                  fileout << "9C ";
                  if (line.substr(4,2) == "A1"){
                    fileout << "1A ";
                  } else if (line.substr(4,2) == "B1"){
                    fileout << "1B ";
                  } else if (line.substr(4,2) == "C1"){
                    fileout << "1C ";
                  } else if (line.substr(4,2) == "A2"){
                    fileout << "2A ";
                  } else if (line.substr(4,2) == "B2"){
                    fileout << "2B ";
                  } else if (line.substr(4,2) == "C2"){
                    fileout << "2C ";
                  }
                  if (line.substr(6,2) == "A1"){
                    fileout << "1A ";
                  } else if (line.substr(6,2) == "B1"){
                    fileout << "1B ";
                  } else if (line.substr(6,2) == "C1"){
                    fileout << "1C ";
                  } else if (line.substr(6,2) == "A2"){
                    fileout << "2A ";
                  } else if (line.substr(6,2) == "B2"){
                    fileout << "2B ";
                  } else if (line.substr(6,2) == "C2"){
                    fileout << "2C ";
                  }
                }
                if (line.substr(0,3) == "JMP"){
                  fileout << "9E ";
                  if (line.substr(4,2) == "A1"){
                    fileout << "1A ";
                  } else if (line.substr(4,2) == "A2"){
                    fileout << "2A ";
                  } else {
                    std::cout << "ERROR: Invalid jump label" << std::endl;
                  }
                  if (line.substr(7,1) == ">"){
                    fileout << "> ";
                  } else if (line.substr(7,1) == "<"){
                    fileout << "< ";
                  } else if (line.substr(7,1) == "="){
                    fileout << "= ";
                  } else {
                    std::cout << "ERROR: Invalid condition" << std::endl;
                  }
                }
          }
        }
   }
}