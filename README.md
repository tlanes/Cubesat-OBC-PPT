# Cubesat-OBC-PPT
-Simulating i2c protocol between two arduinos for **Cubesat PPT ACS**

  **MASTER - OBC**
    -Can send commands A - H via serial input from user
  **SLAVE - PPT**
    -Receives commands from OBC and switches to determine which LED to blink. ACKs to the OBC whether fire was successful.

### !! TO-DO TODAY !!
- [ ] write the `wait(deg)`
- [ ] number switch schematic
- [ ] pseudo-code `firstFire(pin1,pin2)`
- [ ] psuedo-code `lastFire(pin1,pin2)`
- [ ] pseudo-code `minShock(dir)`

### FUTURE TASKS
- switch from A - H commands to incorporate a 17 LED prototype (igniter * 8, capacitor * 1, anode * 8)
- enable alternate comm. protocol (SPI, serial (UART), CAN)
- build the GUI
- Functions needed
### ROLL
    -minShock(bool direction)
    {find which pair of thrusters has the lowest shock counter}
    -firstFire(optimum pair)
    {3 switches activated}
    -wait(degrees to rotate)
    {calcuate time to rotate based on known inertial characteristics}
    -lastFire(opposite optimum pair)
    {3 switches activated}
### PITCH
### YAW


