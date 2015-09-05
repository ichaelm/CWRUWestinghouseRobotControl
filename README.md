# CWRU Westinghouse Robot Control

This repository is for all of the design work we do to get the Westinghouse robot operational again, especially the arduino code.

If you want to get started editing the arduino code, download the editor [here](https://www.arduino.cc/en/Main/Software) and open the .ino file in this repository.

If you want to download the files in this repository without worrying about git, click the "Download ZIP" button in the lower right. If you do want to use the revision control system git, follow an online tutorial. The easiest way is with [github desktop](https://help.github.com/desktop/guides/getting-started/setting-up-github-desktop/).

This readme document serves as a general outline of the entire control system.

### General Design:

         Radio transmitter
                | |
                | |
                | |
                | |
          Radio Reciever
                | |
                | |
              Arduino
          ____| | | |____
         |  ____| |____  |
         | |           | |
        Motor         Motor
      Controller    Controller
       __| |__       __| |__
      |       |     |       |
    Motor   Motor Motor   Motor
  
### Parts:
  
  * Radio transmitter/reciever: http://www.hobbypartz.com/79p-gt2-blue.html
  * Arduino: whichever one we can find
  * Motor controller (belongs to Rhys): http://www.andymark.com/Talon-p/am-talon-discontinued.htm

