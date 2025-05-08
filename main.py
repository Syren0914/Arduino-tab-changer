import serial
import time
import pyautogui

ser = serial.Serial('COM4', 9600)  # Replace COM4 with your actual port
time.sleep(2)  # wait for Arduino to reboot

last_trigger = 0

while True:
    if ser.in_waiting:
        line = ser.readline().decode('utf-8').strip()
        print(f"Arduino: {line}")
        if "DETECTED" in line and (time.time() - last_trigger > 5):
            pyautogui.hotkey('alt', 'tab')  # or 'alt', 'tab' to switch apps
            last_trigger = time.time()
