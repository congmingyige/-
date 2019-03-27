@echo off
setlocal enabledelayedexpansion

::here, build test data, correct result, and test the output of several exe


set build="../data/bin/Debug/data.exe"
set correct="../code/bin/Debug/code.exe"
set test1="../code1.exe"
set test2="../code2.exe"
set test3="../code3.exe"
set test4="../code4.exe"
set test5="../code5.exe"
set test6="../code6.exe"
set test7="../code7.exe"
set test8="../code8.exe"
set test9="../code9.exe"
set addr="C:\Users\scientific\Desktop\±à³ÌÌâÄ¿\L3015_²âÊÔ\result"

if not exist %addr% (
	md %addr%
)

for /l %%i in (1,1,1000) do (
	cd %addr%
	%build% >data_%%i.txt
	%correct% <data_%%i.txt >correct_%%i.txt

	%test1% <data_%%i.txt >test1_%%i.txt
	fc test1_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 1 not same %%i

	%test2% <data_%%i.txt >test2_%%i.txt
	fc test2_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 2 not same %%i

	%test3% <data_%%i.txt >test3_%%i.txt
	fc test3_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 3 not same %%i

	%test4% <data_%%i.txt >test4_%%i.txt
	fc test4_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 4 not same %%i

	%test5% <data_%%i.txt >test5_%%i.txt
	rem fc test5_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 5 not same %%i

	%test6% <data_%%i.txt >test6_%%i.txt
	rem fc test6_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 6 not same %%i

	%test7% <data_%%i.txt >test7_%%i.txt
	fc test7_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 7 not same %%i

	%test8% <data_%%i.txt >test8_%%i.txt
	fc test8_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 8 not same %%i

	%test9% <data_%%i.txt >test9_%%i.txt
	fc test9_%%i.txt correct_%%i.txt >nul && echo >nul  || echo 9 not same %%i

	set /a j=%%i%%1
	if !j! equ 0 (
		echo %%i th
	)
)

pause
