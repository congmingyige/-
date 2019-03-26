@echo off
setlocal enabledelayedexpansion

::here, test.exe build data, code1.exe,code2.exe test


set build=C:\Users\scientific\Desktop\test\bin\Debug\test.exe
set test1=C:\Users\scientific\Desktop\code1\bin\Debug\code1.exe
set test2=C:\Users\scientific\Desktop\code2\bin\Debug\code2.exe
set addr=C:\Users\scientific\Desktop\test

if not exist %addr% (
	md %addr%
)

for /l %%i in (1,1,1000) do (
	cd %addr%
	%build% >%%i.txt
	%test1% <%%i.txt >output1_%%i.txt
	%test2% <%%i.txt >output2_%%i.txt
	fc output1_%%i.txt output2_%%i.txt >nul && echo >nul  || echo not same %%i
	set /a j=%%i%%100
	if !j! equ 0 (
		echo %%i th
	)
)

pause
