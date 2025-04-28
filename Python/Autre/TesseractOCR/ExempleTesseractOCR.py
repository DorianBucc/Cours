from PIL import Image
import pytesseract
import pyperclip
#Image.open('./Test1.PNG')
pytesseract.pytesseract.tesseract_cmd = r'tesseract'
str = pytesseract.image_to_string(Image.open('./Test2.PNG'))
print(str)
pyperclip.copy(str)