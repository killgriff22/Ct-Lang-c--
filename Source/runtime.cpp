//import the nessecary stuff to open and read a file
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
std::vector<std::string> split (std::string s, std::string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    std::string token;
    std::vector<std::string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != std::string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
int main( int argc, char *argv[] )
{
    int ARegister1=0;
    std::string BRegister1="";
    bool CRegister1 = false;
    int ARegister2=0;
    std::string BRegister2="";
    bool CRegister2 = false;
      if (argc >= 2)
   {
      std::ifstream filein (argv[1]);
      if (filein.is_open()){
        std::string line;
        std::getline(filein,line);
        std::vector<std::string> codes = split(line, " ");
        std::string code;
        int lines=0;
        for (int i=0; i < codes.size();i++){
            code = codes[i];
            if (code == "9A"){//Set Variable
                i++;
                code = codes[i];
                if (code == "1A"){
                    i++;
                    code = codes[i];
                    ARegister1 = std::stoi(code);
                } else if (code == "1B"){
                    i++;
                    code = codes[i];
                    BRegister1 = code;
                } else if (code == "1C"){
                    i++;
                    code = codes[i];
                    if (code == "TT"){
                        CRegister1 = true;
                    } else if (code == "FF") {
                        CRegister1 = false;
                    }
                } else if (code == "2A"){
                    i++;
                    code = codes[i];
                    ARegister2 = std::stoi(code);
                } else if (code == "2B"){
                    i++;
                    code = codes[i];
                    BRegister2 = code;
                } else if (code == "2C"){
                    i++;
                    code = codes[i];
                    if (code == "TT"){
                        CRegister2 = true;
                    } else if (code == "FF") {
                        CRegister2 = false;
                    }
                }
            } else if (code == "9B"){//Printing
                i++;
                code = codes[i];
                if (code == "1A"){
                    std::cout << ARegister1 << std::endl;
                } else if (code == "1B"){
                    std::cout << BRegister1 << std::endl;
                } else if (code == "1C"){
                    std::cout << CRegister1 << std::endl;
                } else if (code == "2A"){
                    std::cout << ARegister2 << std::endl;
                } else if (code == "2B"){
                    std::cout << BRegister2 << std::endl;
                } else if (code == "2C"){
                    std::cout << CRegister2 << std::endl;
                }
            } else if (code == "9C"){//Addition
                i++;
                code=codes[i];
                if (code == "1A"){
                    i++;
                    code = codes[i];
                    if (code == "1A"){
                        ARegister1 = ARegister1 + ARegister1;
                    } else if (code == "2A"){
                        ARegister1 = ARegister1 + ARegister2;
                    } else if (code == "1B"){
                        ARegister1 = ARegister1 + std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister1 = ARegister1 + std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister1 = ARegister1 + CRegister1;
                    } else if (code == "2C"){
                        ARegister1 = ARegister1 + CRegister2;
                    }
                } else if (code == "2A"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        ARegister2 = ARegister2 + ARegister1;
                    } else if (code == "2A"){
                        ARegister2 = ARegister2 + ARegister2;
                    } else if (code == "1B"){
                        ARegister2 = ARegister2 + std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister2 = ARegister2 + std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister2 = ARegister2 + CRegister1;
                    } else if (code == "2C"){
                        ARegister2 = ARegister2 + CRegister2;
                    }
                } else if (code == "1B"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        BRegister1 = BRegister1+std::to_string(ARegister1);
                    } else if (code == "2A"){
                        BRegister1 = BRegister1+std::to_string(ARegister2);
                    } else if (code == "1B"){
                        BRegister1 = BRegister1+std::to_string(std::stoi(BRegister1));
                    } else if (code == "2B"){
                        BRegister1 = BRegister1+std::to_string(std::stoi(BRegister2));
                    } else if (code == "1C"){
                        BRegister1 = BRegister1 + std::to_string(CRegister1);
                    } else if (code == "2C"){
                        BRegister1 = BRegister1 + std::to_string(CRegister2);
                    }
                } else if (code == "2B"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        BRegister2 = BRegister2+std::to_string(ARegister1);
                    } else if (code == "2A"){
                        BRegister2 = BRegister2+std::to_string(ARegister2);
                    } else if (code == "1B"){
                        BRegister2 = BRegister2+std::to_string(std::stoi(BRegister1));
                    } else if (code == "2B"){
                        BRegister2 = BRegister2+std::to_string(std::stoi(BRegister2));
                    } else if (code == "1C"){
                        BRegister2 = BRegister2 + std::to_string(CRegister1);
                    } else if (code == "2C"){
                        BRegister2 = BRegister2 + std::to_string(CRegister2);
                    }
                } else {
                    std::cout << "ERROR CANNOT ADD " << i << std::endl;
                }
            } else if (code == "9E"){//Jumping
                
                i++;
                code=codes[i];
                if (code == "1A"){
                    if (codes[i+1] == "<"){
                        i++;
                        if (ARegister1 < ARegister2){
                            i=std::stoi(BRegister1);
                        }
                    } else if (codes[i+1] == ">"){
                        i++;
                        if (ARegister1 > ARegister2){
                            i=std::stoi(BRegister1);
                        }
                    } else if (codes[i+1] == "="){
                        i++;
                        if (ARegister1 == ARegister2){
                            i=std::stoi(BRegister1);
                        }
                    } else {
                        i=ARegister1;
                    }
                } else if (code == "2A"){
                    if (codes[i+1] == "<"){
                        i++;
                        if (ARegister2 < ARegister1){
                            i=std::stoi(BRegister2);
                        }
                    } else if (codes[i+1] == ">"){
                        i++;
                        if (ARegister2 > ARegister1){
                            i=std::stoi(BRegister2);
                        }
                    } else if (codes[i+1] == "="){
                        i++;
                        if (ARegister2 == ARegister1){
                            i=std::stoi(BRegister2);
                        }
                    } else {
                        i=ARegister2;
                    }
                } else {
                    std::cout << "ERROR CANNOT JUMP " << i << std::endl;
                }
            } else if (code == "9D"){//Subtraction
                i++;
                code=codes[i];
                if (code == "1A"){
                    i++;
                    code = codes[i];
                    if (code == "1A"){
                        ARegister1 = ARegister1 - ARegister1;
                    } else if (code == "2A"){
                        ARegister1 = ARegister1 - ARegister2;
                    } else if (code == "1B"){
                        ARegister1 = ARegister1 - std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister1 = ARegister1 - std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister1 = ARegister1 - CRegister1;
                    } else if (code == "2C"){
                        ARegister1 = ARegister1 - CRegister2;
                    }
                } else if (code == "2A"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        ARegister2 = ARegister2 - ARegister1;
                    } else if (code == "2A"){
                        ARegister2 = ARegister2 - ARegister2;
                    } else if (code == "1B"){
                        ARegister2 = ARegister2 - std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister2 = ARegister2 - std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister2 = ARegister2 - CRegister1;
                    } else if (code == "2C"){
                        ARegister2 = ARegister2 - CRegister2;
                    }
                } else {
                    std::cout << "ERROR CANNOT SUBTRACT " << i << std::endl;
                }
            } else if (code == "9F"){//Multiplication
                i++;
                code=codes[i];
                if (code == "1A"){
                    i++;
                    code = codes[i];
                    if (code == "1A"){
                        ARegister1 = ARegister1 * ARegister1;
                    } else if (code == "2A"){
                        ARegister1 = ARegister1 * ARegister2;
                    } else if (code == "1B"){
                        ARegister1 = ARegister1 * std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister1 = ARegister1 * std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister1 = ARegister1 * CRegister1;
                    } else if (code == "2C"){
                        ARegister1 = ARegister1 * CRegister2;
                    }
                } else if (code == "2A"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        ARegister2 = ARegister2 * ARegister1;
                    } else if (code == "2A"){
                        ARegister2 = ARegister2 * ARegister2;
                    } else if (code == "1B"){
                        ARegister2 = ARegister2 * std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister2 = ARegister2 * std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister2 = ARegister2 * CRegister1;
                    } else if (code == "2C"){
                        ARegister2 = ARegister2 * CRegister2;
                    }
                } else {
                    std::cout << "ERROR CANNOT MULTIPLY " << i << std::endl;
                }
            } else if (code == "AA"){//Division
                i++;
                code=codes[i];
                if (code == "1A"){
                    i++;
                    code = codes[i];
                    if (code == "1A"){
                        ARegister1 = ARegister1 / ARegister1;
                    } else if (code == "2A"){
                        ARegister1 = ARegister1 / ARegister2;
                    } else if (code == "1B"){
                        ARegister1 = ARegister1 / std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister1 = ARegister1 / std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister1 = ARegister1 / CRegister1;
                    } else if (code == "2C"){
                        ARegister1 = ARegister1 / CRegister2;
                    }
                } else if (code == "2A"){
                    i++;
                    code=codes[i];
                    if (code == "1A"){
                        ARegister2 = ARegister2 / ARegister1;
                    } else if (code == "2A"){
                        ARegister2 = ARegister2 / ARegister2;
                    } else if (code == "1B"){
                        ARegister2 = ARegister2 / std::stoi(BRegister1);
                    } else if (code == "2B"){
                        ARegister2 = ARegister2 / std::stoi(BRegister2);
                    } else if (code == "1C"){
                        ARegister2 = ARegister2 / CRegister1;
                    } else if (code == "2C"){
                        ARegister2 = ARegister2 / CRegister2;
                    }
                } else {
                    std::cout << "ERROR CANNOT SUBTRACT " << i << std::endl;
                }
            }
        }
      }
    }
}