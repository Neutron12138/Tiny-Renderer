g++ -finput-charset=UTF-8 -fexec-charset=gbk -shared ^
    "../src/TR.cpp" -o "TR.dll" ^
    -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -lgdi32 -lglew32