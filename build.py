import os
import sys
if len(sys.argv) < 2:#build compiler and runtime
    print("Building all")
    print("Building 1")
    os.system("g++ ./Source/runtime.cpp -o ./build/runtime")
    print("1/2")
    print("Building 2")
    os.system("g++ ./Source/compiler.cpp -o ./build/compiler")
    print("2/2")
elif len(sys.argv) == 2:#build compiler OR runtime
    os.system(f"g++ ./Source/{sys.argv[1]}.cpp -o ./build/{sys.argv[1]}")
elif len(sys.argv) >= 2:#build executable dicrectly
    code=""
    print("Parsing into bytecode...")
    with open(sys.argv[1],"r") as infile:#Create bytecode and compile c++ file
        infile = infile.readlines()
        for line in infile:#Parser
            linesplt = line.strip("\n").split(" ")
            match linesplt[0]:
                case "IN":
                    code+=f"9A {linesplt[1][1]}{linesplt[1][0]} {linesplt[2]} "
                case "PRINT":
                    code+=f"9B {linesplt[1][1]}{linesplt[1][0]} "
                case "JMP":
                    code+=f"9E {linesplt[1][1]}{linesplt[1][0]} {f'{linesplt[2]} ' if len(linesplt) == 3 else ''}"
                case "ADD":
                    code+=f"9C {linesplt[1][1]}{linesplt[1][0]} {linesplt[2][1]}{linesplt[2][0]} "
                case "SUB":
                    code+=f"9D {linesplt[1][1]}{linesplt[1][0]} {linesplt[2][1]}{linesplt[2][0]} "
                case "MUL":
                    code+=f"9F {linesplt[1][1]}{linesplt[1][0]} {linesplt[2][1]}{linesplt[2][0]} "
                case "DIV":
                    code+=f"AA {linesplt[1][1]}{linesplt[1][0]} {linesplt[2][1]}{linesplt[2][0]} "
        with open("source/runtime-direct.cpp","r") as runtimefile:#Compiler
            open("tempfile.cpp","w").close()
            with open("tempfile.cpp","a") as tempfile:
                runtime = runtimefile.readlines()
                for line2 in runtime:
                    if line2 == f'''        std::string line = "";\n''':
                        tempfile.write(f'''        std::string line = "{code}";\n''')
                    else:
                        tempfile.write(line2)
    print("Finished parsing into bytecode\nCompiling exe...")
    os.system(f"g++ tempfile.cpp -o {'a.exe' if not len(sys.argv) == 3 else sys.argv[2]}")
    print("Finished compilation to exe\nCleaning up...")
    os.remove("tempfile.cpp")