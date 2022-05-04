# Taranis-Poti-Switch-Mod
!!! This project shoud not be implementet like this. Someone needs to change stuff in the code because i can't figure it out (don't have the time)" !!!
!!! This project is work in progress !!! use with caution !!!

The x9d has a 5th potentiometer input on the lower PCB
The easyest thing woud be to just wire up a potentiometer or a 3 position switch with two resistors (see folder "resistor-switch" for schematic)

or you can go crazy and use a arduino micro to emulate the potentiometer. Then you can connect whatever you want to the arduino (in my case 2x 3-pos switches and one pushbutton) and use some if-statements to define the "position" of the "potentiometer". This can be done by generating a high-frequenzy PWM and a condensator to get a steady voltage. By changing the duty cicle you can change the voltage.

## ToDo:
1. Change timer1 to timer4 to get a even higher PPWM frequenzy. Then ther isn't the need for a large condensator to filter the signal and it shoud be more stable.
2. Redefine the size of the condensator depending on the final PWM frequenzy
3. Clean up code for easyer modification

## Important Information:
1. For Taranis x9d: The maximum Volgage for the potentiometer input is 3V! The Arduino can output more then that. So never use 100% duty cicle! Find max duty cicle with osziloskop or multimeter!

## Wiring
### Power
There is no elegant way to get Power for the arduino. You have to solder a cable to a leg of a mosfet to get Battery-Voltage. Make shure that the arduino can handle it. Especially if you use a 3s lipo

<p align="center">
  <img src="https://github.com/Jens-Si/Taranis-Poti-Switch-Mod/blob/main/pics/x9dwitharduino.jpg" width="550" title="old and new PCB">
  <br /> Power = yellow wire
</p>

### Poti-Signal
The output signal is generatet on PIN9 (timer1). Together with a GND wire it can be soldert to the 5th potentiometer input, or any other potentiometer input. Make shure to add the condensator. For the 5th poti input you can solder the condensator together with the wires onto the pad.
The most upper one is GND, middle is the Signale.

<p align="center">
  <img src="https://github.com/Jens-Si/Taranis-Poti-Switch-Mod/blob/main/pics/x9dpoti5input.jpg" width="550" title="old and new PCB">
  <br /> Power = yellow wire
</p>

### Add a Switch
To add a switch you use a standart pull-up or pull-down schematic. I used the arduino pin next to the pin i want as the switch input to get the pull-up Voltage by setting the pin to HIGH. This can be done for 2 position or 3 position switches.
Of yourse you can add many more things to the arduino. But i think most of us will stay with switches...

--PIC-- pullup/pulldown

<p align="center">
  <img src="https://github.com/Jens-Si/Taranis-Poti-Switch-Mod/blob/main/pics/x9darduinores.jpg" width="550" title="old and new PCB">
  <br /> Power = 10k 0805 Resistors for pull-up
</p>
