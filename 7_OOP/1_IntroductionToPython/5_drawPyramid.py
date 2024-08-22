import pyautogui
import time

# Get the number of rows for the pyramid from the user
n = int(input("Enter the number of rows for the pyramid: "))

# Optional: Add a delay to allow you to switch to the desired drawing area
time.sleep(5)


for i in range(1, n + 1):
    
    spaces = ' ' * (n - i)
    stars = '*' * (2 * i - 1)

    # Type the current row using pyautogui
    pyautogui.typewrite(spaces + stars)
    
    # Press 'Enter' to move to the next line
    pyautogui.press('enter')
