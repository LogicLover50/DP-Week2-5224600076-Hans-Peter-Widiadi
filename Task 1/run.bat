@echo off
cd /d "%~dp0"
echo Compiling Task 1...
g++ -std=c++17 main.cpp FixedInputGenerator.cpp RandomInputGenerator.cpp DirectScoringRule.cpp BaseRewardRule.cpp BonusRewardRule.cpp ShopSystem.cpp RunSession.cpp -o task1.exe
echo Running Task 1...
task1.exe
pause