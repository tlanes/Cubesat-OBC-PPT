# Cubesat-OBC-PPT
-------------------------- 
    """ 
    simulating i2c protocol between two computers for Cubesat PPT ACS ...
        MASTER - OBC  
            Can send commands A - H via serial input from user
        SLAVE - PPT
            Receives commands from OBC and switches to determine 
            which LED to blink. ACKs to the OBC whether fire was 
            successful. 
    """


*FUTURE TASKS
    - switch from A - H commands to incorporate a 17 LED prototype (igniter * 8 capacitor * 1, anode * 8)
    - enable alternate comm. protocol (SPI, serial (UART), CAN)
    - build the GUI
    - 
