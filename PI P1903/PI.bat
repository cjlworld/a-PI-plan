@echo off
:loop
data.exe > data.txt
std.exe < data.txt > std.txt
test.exe < data.txt > test.txt
fc std.txt test.txt
if not errorlevel 1 goto loop
pause
:end