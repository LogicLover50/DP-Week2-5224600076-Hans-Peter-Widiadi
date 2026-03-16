@echo off
cd /d "%~dp0"
echo Compiling Task 2...
g++ -std=c++17 main.cpp Card.cpp Deck.cpp Hand.cpp BaseChipScorer.cpp ShopSystem.cpp GameSession.cpp -o task2.exe
echo Running Task 2...
task2.exe
pause