import sensor, image, time
from pyb import LED, UART

# UART 3, and baudrate for the communication Open MV and Arduino
uart = UART(3, 38400)

red_led   = LED(1)
green_led = LED(2)
blue_led  = LED(3)

sensor.reset()
sensor.set_pixformat(sensor.RGB565)
sensor.set_framesize(sensor.QVGA)
#sensor.skip_frames(time = 2000)
sensor.set_auto_gain(False)
clock = time.clock()

def leds_off():
    red_led.off()
    green_led.off()
    blue_led.off()

while(True):
    clock.tick()
    img = sensor.snapshot()
    img.lens_corr(1.8) #
    qr_detected = False

    for code in img.find_qrcodes(): #
        qr_detected = True
        img.draw_rectangle(code.rect(), color = (255, 0, 0))
        qr = code.payload()
        print(qr)   # Si detecta un codigo qe, imprime
        if(qr=="ELEVA123"):
            green_led.on()
            print("UP123")
            uart.write("H")
            time.sleep(4)
            leds_off()

        elif(qr=="DESCIENDE123"):
            green_led.on()
            print("DOWN123")
            uart.write("I")
            time.sleep(4)
            leds_off()

        elif(qr=="ELEVA100"):
            blue_led.on()
            print("UP100")
            uart.write("J")
            time.sleep(4)
            leds_off()

        elif(qr=="DESCIENDE100"):
            blue_led.on()
            print("DOWN100")
            uart.write("K")
            time.sleep(4)
            leds_off()

        elif(qr=="ESQUIVA020"):
            red_led.on()
            print("UP020")
            uart.write("L")
            time.sleep(4)
            leds_off()

        elif(qr=="DESCIENDE020"):
            red_led.on()
            print("DOWN20")
            uart.write("M")
            time.sleep(4)
            leds_off()

        elif(qr=="ESQUIVA003"):
            green_led.on()
            print("UP003")
            uart.write("N")
            time.sleep(4)
            leds_off()

        elif(qr=="DESCIENDE003"):
            green_led.on()
            print("UP003")
            uart.write("O")
            time.sleep(4)
            leds_off()

        elif(qr=="ELEVA023"):
            blue_led.on()
            print("UP023")
            uart.write("P")
            time.sleep(4)
            leds_off()

        elif(qr=="DESCIENDE023"):
            blue_led.on()
            print("DOWN023")
            uart.write("Q")
            time.sleep(4)
            leds_off()

    if not qr_detected:
        # Envía una señal al Arduino cuando no se detecta ningún código QR
        #uart.write("O")
       # time.sleep(1)
        leds_off()
