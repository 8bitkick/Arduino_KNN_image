# Arduino_KNN_image
Simple machine vision using KNN on an [Arduino Nano BLE sense](https://store.arduino.cc/usa/nano-33-ble-sense) and a OV767x low-cost VGA camera module.

An Arduino sketch captures image examples which can be imported to the KNN classifier and recognized. A web page that connects to the Arduino using web serial displays a visualization of this using p5js and auto generates Arduino code of the example image data array to paste back into your sketch.

[Video summary here](https://twitter.com/DominicPajak/status/1277466634207162368?s=20). 

![capture](https://raw.githubusercontent.com/8bitkick/Arduino_KNN_image/master/images/capture.gif)


## Prerequisites 
  
  * Install the Arduino KNN library following these [instructions](https://blog.arduino.cc/2020/06/18/simple-machine-learning-with-arduino-knn/)

  * Connect the Arduino and Camera and install the library following these [instructions](https://blog.arduino.cc/2020/06/24/machine-vision-with-low-cost-camera-modules/). 

  
## Usage
  
  * Download this project and unzip it
  
  * Install and open the [Arduino IDE](https://www.arduino.cc/en/main/software) or [Arduino Create](https://create.arduino.cc/projecthub/Arduino_Genuino/getting-started-with-arduino-web-editor-on-various-platforms-4b3e4a?f=1)

  * In the Arduino IDE open the [CameraKNN.ino](https://blog.arduino.cc/2020/06/18/simple-machine-learning-with-arduino-knn/) project file, compile and upload to your board

  * In Google Chrome load index.html in the project folder. The sketch currently relies on Web Serial so is Chrome only at this time.
  
  
### Connect the browser to the board

  * Connect the Chrome browser to the Arduino board by hitting the `Connect to Arduino` button
  
  * The browser will [pop-up with another window to confirm](https://raw.githubusercontent.com/8bitkick/Arduino_KNN_image/master/images/connectSerial.gif) - select the Arduino Nano BLE Sense and press `Connect`
  
### Capture some example images

  * You should see a pixelated view of what your camera is now seeing
  
  * Add a label name in the label field
  
  * Hit the `Capture image` button
  
  * You will see a thumbnail appear, along with some code at the bottom of the sketch
  
  * Capture a few examples of each object

### Classify some objects

  * At the bottom of the webpage there is now some Arduino code containing your image data
  

It should look a bit like this:

```
const int input_size = 3 * 10 * 8;
KNNClassifier myKNN(input_size);
const int number_examples = 1;
const int example_classes[] = {0};
const char* classes[] = {"Apple"};
const float example_images[][input_size] =
{
{0xe7,0xff,0xff,0xff,0xfe,0xff,0xff...
};
```

   * Copy this code and paste into your CameraKNN.ino sketch, replacing the section that says `REPLACE THIS SECTION`

