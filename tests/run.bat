set filename=base
g++ -finput-charset=UTF-8 -fexec-charset=gbk ^
    "../src/Main.cpp" "%filename%.cpp" "TR.dll" -o "%filename%.exe" ^
    -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -lgdi32 -lglew32
"%filename%.exe"