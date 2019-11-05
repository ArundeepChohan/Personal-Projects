import win32gui
import win32con
import win32api

def click(x,y):
    win32api.SetCursorPos((x,y))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN,x,y,0,0)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP,x,y,0,0)
try:
    hwndMain = win32gui.FindWindow( None,"Mozilla Firefox",)
    print (hwndMain)
    rect = win32gui.GetWindowRect(hwndMain)
    x = rect[0]
    y = rect[1]
    w = rect[2] - x
    h = rect[3] - y
    print ("Window %s:" % win32gui.GetWindowText(hwndMain))
    print ("\tLocation: (%d, %d)" % (x, y))
    print ("\t    Size: (%d, %d)" % (w, h))
    click(x,y)
except:
    print("Window Not Found")

