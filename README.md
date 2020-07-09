# Arduino_KNN_image (beta)
Simple machine vision project using KNN on an [Arduino Nano BLE sense](https://store.arduino.cc/usa/nano-33-ble-sense) and a OV767x low-cost VGA camera module.

An Arduino sketch captures image examples which can be imported to the KNN classifier and recognized. A web page that connects to the Arduino using web serial displays a visualization of this using p5js and auto generates Arduino code of the example image data array to paste back into your sketch.

[Video summary here](https://twitter.com/DominicPajak/status/1277466634207162368?s=20). 

![capture](https://raw.githubusercontent.com/8bitkick/Arduino_KNN_image/master/images/capture.gif)


KNN is a classical machine learning algorithm which is easy to understand so a nice introduction to the topic.

There are more powerful ML methods for image recognition on Arduino Nano BLE Sense including the TensorFlow Lite Micro person detection example which we will explore in a later article.


## Prerequisites 
  
  * Install the Arduino KNN library following these [instructions](https://blog.arduino.cc/2020/06/18/simple-machine-learning-with-arduino-knn/)

  * Connect the Arduino and Camera and install the library following these [instructions](https://blog.arduino.cc/2020/06/24/machine-vision-with-low-cost-camera-modules/). 

  
## Usage
  
  * Download this project and unzip it
  
  * Install and open the [Arduino IDE](https://www.arduino.cc/en/main/software) or [Arduino Create](https://create.arduino.cc/projecthub/Arduino_Genuino/getting-started-with-arduino-web-editor-on-various-platforms-4b3e4a?f=1)

  * In the Arduino IDE open the [CameraKNN.ino](https://github.com/8bitkick/Arduino_KNN_image/blob/master/CameraKNN/CameraKNN.ino) sketch, compile and upload to your board

  * In Google Chrome load index.html in the project folder. The sketch currently relies on Web Serial so is Chrome only at this time.
  
  
### Connect the browser to the board

  * Connect the Chrome browser to the Arduino board by hitting the `Connect to Arduino` button
  
  * The browser will [pop-up with another window to confirm](https://raw.githubusercontent.com/8bitkick/Arduino_KNN_image/master/images/connectSerial.gif) - select the Arduino Nano BLE Sense and press `Connect`
  
### Capture some example images of objects

  * You should see a pixelated view of what your camera is now seeing
  
  * Add a label name in the label field
  
  * Hit the `Capture image` button
  
  * You will see a thumbnail appear, along with some code at the bottom of the sketch
  
  * Capture a few examples of each object

### Classify some images

  * At the bottom of the webpage there is a console that now shows some Arduino code containing your image data
  

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

   * Copy this code from the web console
   * Open the Arduino IDE
   * Paste into your CameraKNN.ino sketch, replacing the section that says `REPLACE THIS SECTION`
   * Compile and upload this code to your Arduino board
   * Reload your webpage, and reconnect to the Arduino board using serial
   * The webpage should show the Arduino image viewer and classifier output
   * Congratulations! Your Arduino is doing some image classification!
   
![classifying](https://raw.githubusercontent.com/8bitkick/Arduino_KNN_image/master/images/classifying.gif)

### Todo

* Mark 1 - Add button to download image code

* Mark 2 - Add example image data to flash memory instead :)

