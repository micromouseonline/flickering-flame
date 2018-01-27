# flickering-flame
Simple flickering flame effect class for Arduino

Control one or more LEDs using analogWrite() on any Arduino. The LED changes brightness randomly. That alone would not look much like a flame but a simple exponential low pass filter enhances the effect greatly.

There are two parameters that change the impression the LED gives

- The low pass filter uses a value, alpha, to determine the weighting given to the new brightness. A small value of alpha means that the brightness will change more slowly. In the limit, alpha=0 would prevent any change and the LED would stay off. Make alpha 100 to change brightness immediately.
- The update interval also affects the flicker rate. There is not much point updating them too frequently but you can experiment with different combinations of frequency and filter coefficient. Each LED has its own update frequency. Even if a collection of channels all share the same value, the initialisation makes sure they do not all update together so that a collection will not look synchronised.

Set up an array of several LEDs and you get a fire effect. give them dfferent filter values so that there are some that change frequently and some that change slowly. Choose a combination of yellow and RED LEDs to suit or white and red LEDs with a coloured diffuser.

You can see a crude demonstration at https://youtu.be/DHceQaXWeAw. Here four white LEDs and one red LED are placed in a row and then covered with a cut up yellow party balloon. It looks better than it sounds.
