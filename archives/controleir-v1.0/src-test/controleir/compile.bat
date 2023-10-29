@echo off
g++ -o Controleir.exe main.cpp Action.cpp Application.cpp Outils.cpp OutilsData.cpp Telecommande.cpp
if %errorlevel% neq 0 (
    echo Compilation failed.
) else (
    echo Compilation successful.
)
