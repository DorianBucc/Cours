from PIL import Image
import pytesseract
import sys
import pyperclip

if(len(sys.argv) < 3):
    print("Minimum 1 argument")
else:
    str = pytesseract.image_to_string(Image.open(sys.argv[1]+"\\"+sys.argv[2]))
    print(str)
    pyperclip.copy(str)