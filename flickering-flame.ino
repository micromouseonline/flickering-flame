/***********************************************************************
 * Created by Peter Harrison on 26/1/2018.
 * Copyright (c) 2018 Peter Harrison
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without l> imitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 * IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
 * CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
 * TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 **************************************************************************/

// analogWrite is available on  pins 3, 5, 6, 9, 10, and 11
class Flame
{
  public:
    void setup(int pin, int alpha = 20, int delay = 100);
    void flicker();

  private:
    int _pin;
    int _brightness = 0;  // soft start
    int _oldBrightness = 0;
    int _updateDelay;
    unsigned long _nextUpdate;
    int _alpha; // filter coefficient (0..100). Low means slow changes
};


void Flame::setup(int pin, int alpha, int delay) {
  constrain(alpha, 0, 100);
  _pin = pin;
  _alpha = alpha;
  _updateDelay = delay;
  // random first upate to prevent multiple flames looking synchronous
  _nextUpdate  = millis() + random(_updateDelay);
}

void Flame::flicker() {
  if (millis() >= _nextUpdate) {
    _nextUpdate += _updateDelay; 
    _brightness = random(0, 255);
    // low pass filter the brightness changes
    _brightness = (_alpha * _brightness + (100 - _alpha) * _oldBrightness) / 100;
    _oldBrightness = _brightness;
    analogWrite(_pin, _brightness);
  }
}

Flame flame10;
Flame flame11;
Flame flame3;
Flame flame5;
Flame flame6;

void setup() {
  flame10.setup(10,15);
  flame11.setup(11,10);
  flame3.setup(3,20);
  flame5.setup(5,50);
  flame6.setup(6,30);
}

// the loop function runs over and over again forever
void loop() {
  flame10.flicker();
  flame11.flicker();
  flame3.flicker();
  flame5.flicker();
  flame6.flicker();
}
