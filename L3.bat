@echo off
setlocal enabledelayedexpansion

set addr1=".\basic"
set addr2=".\"

for /l %%i in (1,1,21) do (
    echo %%i
    set /a ind+=1
    set num=00%%i
    set num=!num:~-3!
    echo d | xcopy %addr1% %addr2%\L3!num! /e /y
)

pause
