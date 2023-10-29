@echo off
g++ -o exe/ControleirBeta.exe src/application/ControleMain.cpp src/arduino/*.cpp src/fichier/*.cpp src/outils/*.cpp src/telecommande/*.cpp
if %errorlevel% neq 0 (
    echo Compilation failed.
) else (
    echo Compilation successful.
)
