import time

import cv2
import mss
import numpy
from pprint import pprint
import mouse
try:
    from PIL import Image
except ImportError:
    import Image 
import pytesseract
import re
pytesseract.pytesseract.tesseract_cmd = r'C:\Program Files\Tesseract-OCR\tesseract.exe'
x = 0
y = 0
w = 300
h = 300
custom_oem_psm_config = r'--psm 6'
rows,cols = (9, 9) 
arr = [[0]*cols]*rows
with mss.mss() as sct:
    while True:
        # Press "q" to quit
        if cv2.waitKey(25) & 0xFF == ord("q"):
            cv2.destroyAllWindows()
            break
        
        x,y = mouse.get_position()[0],mouse.get_position()[1]
        #print(x,y)
        monitor = {"top": y, "left": x, "width": w, "height": h}
        
        # Get raw pixels from the screen, save it to a Numpy array
        img = numpy.array(sct.grab(monitor),dtype=numpy.uint8)
        img = cv2.cvtColor(img, cv2.COLOR_BGR2RGB)
        for i in range(rows):
            for j in range(cols):
                #print(i,j)
                h1=int((h/rows)*i)
                h2=int((h/rows)*(i+1))
                w1=int((w/cols)*j)
                w2=int((w/cols)*(j+1))
                #print(w1,w2,h1,h2)
                crop_img=img[w1:w2,h1:h2]
                text = pytesseract.image_to_string(crop_img,config=custom_oem_psm_config )
                #print(text)

                number = re.search(r'\d',text)
                if number:
                    #print('First number found = {}'.format(number.group()))
                    print(type(number.group()))
                    arr[i][j]=int(number.group())
                    print(arr[i][j])
                else:
                    #print('0')
                    arr[i][j]= 0
        pprint(arr)       
        #cv2.imshow("OpenCV/Numpy normal", img)

        

 


