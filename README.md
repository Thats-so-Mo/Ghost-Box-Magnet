# Bell Ringing Ghost in the Box Magic Trick

The magic trick involves the use of a Wemos D1 Mini (Arduino Programmed), a 5V Electromagnet, and a bell to create the illusion of a ghostly presence. The Electromagnet is strategically attached to the underside of the top of the box, in close proximity to the bell (which is hanging just above the Electromagnet), and is controlled by the Wemos D1 Mini through a MOSFET Power Switch (soldered to D1). When triggered, the Electromagnet activates for 1 second, followed by a 0.5-second pause, causing the bell to sway and, consequently, produce the eerie ring.

To control the bell, the Wemos D1 Mini acts as an access point and creates a web server. By connecting to the device and heading to the IP address 192.168.4.1, a webpage loads which has one button on it in which you gain the ability to control the bell wirelessly, allowing you to turn it on and off remotely. This wireless control enhances the illusion, making it seem as if a ghostly force is responsible for the bell's movement. Its great because in this day and age, a person is always on their phones!!! so its looks more natural than a person holding a random garage remote or something in their hands hahahaha.

One of the spookiest and BEST features of this project is that it's entirely battery-powered, with no external wires coming to or from the box. This adds an extra layer of mystery and allows you to place the haunted box anywhere without the need for visible connections. 

NOTE: This trick, this naughty con, is a two person trick. You need a inside man, a plant, a partner in order to pull it off!

Special thanks to Awais Naeem from embedded-robotics.com for providing the foundation of the code, which was further spookified for this magical Halloween creation by me. 

Perfect for adding an extra layer of spookiness to your Halloween celebrations and other supernatural-themed performances! 🎃👻🔔🕸️💀


## Check out the video for a demonstration
[![Thumbnail of Youtube Video based upon this fantastic and brilliant project](https://i.ibb.co/cXZM1jh/thumbnail.png)](https://www.youtube.com/watch?v=KbHJlr8aNq8)

## Ingredients

Required library:
ESP8266WiFI and ESP8266WebServer Library - Easily Installable through the Arduino Software - Thanks to its creators

 Materials Used:

    Wemos D1 Mini (Arduino programmed) - eBay
    Electromagnet - https://bit.ly/3FBBS0W (NOTE: don't leave it on for greater than a minute or else it will overheat IF theres nothing attached to it) WOoooo Firery Spirit
    MOSFET Power Switch Module - https://bit.ly/47aGjeH
    LiPo Lithium Battery (3.7V @ 2400mAh) - https://bit.ly/3MHneJF
    1N4001 Diode - https://bit.ly/3MgfApa
    TP4056 Li-ion LiPo Battery Charging Board - eBay
    USB Micro BreakOut Board - eBay
    Fabric - Provided by Deep
    Wooden Box
    Bell
    Heat Shrink Tubing
    Paddle Pop Sticks
    Solder
    On/Off SPST Switch

 Tools:

    Clippers
    Pliers
    Fabric Adhesive Spray
    Wood Glue
    Soldering Iron
    SandPaper
    Bhangra Spirit

   and a few other bits and bobs....

## Wiring Diagram

![Wiring Diagram](https://i.ibb.co/mh7Pc0d/Wiring-Diagramv2.png)

## Explaination

Only Three really important sections that I need to explain:

### First one is this:

![1st](https://i.ibb.co/1fYcKDx/1.png)

This is where you can change the the Wireless Access point and/or Password and which pin is the mosfet attached to, to make it easier on yourself. 


### Second Section:

![2st](https://i.ibb.co/h2dsSKN/2.png)

This section is where you adjust the duration of the magnet.


### Third Section:

![3st](https://i.ibb.co/THzbMcW/3.png)

This section creates what you see when you head to the 192.168.4.1, the web servers gui, I chose dark colors so its difficult for anyone but the viewer, you or me, to see the web site head on, so if a person on your right is staring at your phone, all they will see is just a bunch of dark writing and webpage... highly doubting your link to the trick.
