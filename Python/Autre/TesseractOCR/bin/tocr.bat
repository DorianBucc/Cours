@echo off

@REM if "%1"=="" (
cd %USERPROFILE%\Git\Programme\Python\TesseractOCR

if exist "%USERPROFILE%\Pictures\Screenshots\%1" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1
) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.png" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.png
) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.jpg" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.jpg
) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.jpeg" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.jpeg
) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.pdf" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.pdf
) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.svg" (
    python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.svg
) else (
    echo Erreur
)

@REM ) else (
@REM     if exist "%USERPROFILE%\Pictures\Screenshots\%1" (
@REM     python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1
@REM     ) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.png" (
@REM         python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.png
@REM     ) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.jpg" (
@REM         python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.jpg
@REM     ) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.jpeg" (
@REM         python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.jpeg
@REM     ) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.pdf" (
@REM         python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.pdf
@REM     ) else if exist "%USERPROFILE%\Pictures\Screenshots\%1.svg" (
@REM         python .\TesseractOCR.py %USERPROFILE%\Pictures\Screenshots %1.svg
@REM     ) else (
@REM         echo Erreur
@REM     )
@REM )

pause