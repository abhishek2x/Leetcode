import pyautogui as pg
import time

print("Script about to start in 2 sec")
time.sleep(2)

for i in range(1, 31):

    pg.hotkey('ctrl', 'n')
    time.sleep(1)
    pg.hotkey('ctrl', 's')
    time.sleep(2)

    name = str(i) + '.cpp'

    pg.typewrite(name +"\n", 0.2)
    time.sleep(2)
