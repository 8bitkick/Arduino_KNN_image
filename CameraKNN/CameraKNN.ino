/*
  Image KNN
*/

#include <Arduino_OV767X.h>
#include <Arduino_KNN.h>

// Example image data
//
// REPLACE THIS SECTION WITH THE CODE FROM THE WEB COMPANION
///////////////////////////////////////////////////////////////////
const int input_size = 3 * 10 * 8;
KNNClassifier myKNN(input_size);
const int number_examples = 12;
const char* class_labels[] = {"Apple","Ginger beer","None"};
const int example_classes[] = {0,0,0,0,1,1,1,1};
const float example_images[][input_size] =
{
{0xe1,0xff,0xf5,0xf8,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xef,0xff,0xff,0xff,0xff,0xff,0xde,0xaf,0x91,0xe6,0xa7,0xa1,0xff,0xe4,0xdf,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0xff,0xff,0xff,0xff,0xdb,0xe1,0x46,0x1f,0xf9,0x47,0x38,0xff,0x56,0x3a,0xff,0xd5,0xc4,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xec,0xff,0xff,0xff,0xf9,0xcf,0xb3,0x00,0x03,0xdc,0x08,0x05,0xf8,0x1c,0x10,0xff,0x82,0x6a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xfa,0xd8,0xa6,0x03,0x06,0xd2,0x0e,0x0b,0xe4,0x15,0x13,0xff,0xa9,0x99,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe0,0xb1,0x18,0x10,0xd2,0x1c,0x14,0xee,0x3b,0x2b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0xa9,0x19,0x0e,0xb2,0x11,0x18,0xeb,0x8b,0x85,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xe1,0xf3,0xff,0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xec,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0xc1,0xaf,0xf6,0x8e,0x34,0xff,0x80,0x49,0xff,0x75,0x5a,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc1,0x49,0x3a,0xd2,0x2e,0x00,0xde,0x0f,0x06,0xff,0x1f,0x0e,0xff,0xbb,0xa9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xff,0xff,0xb6,0x43,0x4a,0xd1,0x2f,0x0f,0xd9,0x1a,0x0c,0xf5,0x22,0x12,0xff,0xec,0xe3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf3,0xf8,0xff,0x9d,0x5e,0x70,0xc4,0x28,0x18,0xdc,0x28,0x13,0xf5,0x61,0x55,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xff,0xff,0xec,0xf5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xe1,0xff,0xfc,0xf7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xeb,0xff,0xff,0xff,0xff,0xff,0xb7,0x7f,0x8a,0xbe,0x56,0x39,0xe5,0x69,0x36,0xfd,0xa1,0x8b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf2,0xff,0xff,0xff,0xff,0xff,0x60,0x00,0x0f,0x8c,0x18,0x10,0xe6,0x74,0x46,0xff,0x69,0x3f,0xff,0xa9,0x7a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xea,0xff,0xff,0xff,0xea,0xd7,0x35,0x04,0x11,0x4b,0x00,0x10,0xac,0x1e,0x1a,0xf5,0x48,0x28,0xff,0x58,0x32,0xff,0xf9,0xe9,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xff,0xff,0xff,0xff,0xd9,0x47,0x23,0x16,0x5d,0x10,0x15,0xa4,0x0d,0x12,0xbe,0x0f,0x18,0xdc,0x23,0x1b,0xff,0xe5,0xd7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x83,0x32,0x12,0x8c,0x13,0x1b,0xb9,0x25,0x25,0xd2,0x2f,0x28,0xde,0x4c,0x41,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x98,0x4a,0x39,0xa6,0x1b,0x23,0xc2,0x1e,0x26,0xdd,0x3a,0x37,0xff,0xd2,0xcc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x98,0x8a,0x9e,0x6f,0x36,0x5a,0x93,0x42,0x60,0xd8,0xa8,0xb5,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xfc,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xce,0xc8,0xc9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf4,0xba,0xb3,0xee,0x9e,0x9a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfe,0xc8,0xcc,0xe3,0x2d,0x27,0xda,0x27,0x19,0xe8,0x4e,0x47,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc0,0x3a,0x48,0xd2,0x15,0x10,0xbf,0x0f,0x0a,0xbe,0x07,0x08,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xc4,0x36,0x40,0xc1,0x0e,0x15,0xb2,0x07,0x0b,0xac,0x00,0x06,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf6,0x8c,0x8d,0xd4,0x27,0x22,0xcc,0x1f,0x17,0xb5,0x10,0x14,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xd8,0xd8,0xc1,0x21,0x26,0xcb,0x21,0x19,0xae,0x14,0x17,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xfe,0xbb,0x8b,0x9c,0xa9,0x57,0x69,0xbe,0x62,0x6e},
{0xc9,0xed,0xd8,0x70,0x71,0x6c,0x63,0x56,0x41,0x7b,0x5e,0x47,0x9a,0x86,0x67,0xec,0xe9,0xd8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf8,0xeb,0xf3,0xff,0xff,0xff,0x7b,0x8a,0x7a,0x83,0x88,0x64,0x98,0x9d,0x73,0xaf,0xb0,0x82,0xfb,0xfa,0xeb,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xf3,0xf8,0xff,0xff,0xff,0x6c,0x94,0x72,0x4d,0x5e,0x47,0x81,0x94,0x73,0x8f,0x99,0x7b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf1,0xeb,0xf1,0xff,0xff,0xff,0x6d,0x9a,0x73,0x6e,0x85,0x5e,0x88,0x91,0x78,0x9d,0xa5,0x84,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x80,0x9a,0x7d,0x8a,0x9d,0x75,0xae,0xbc,0x93,0xbe,0xcd,0x9d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x2b,0xa4,0x56,0x00,0x89,0x23,0x17,0x99,0x34,0x4a,0xd1,0x5d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x69,0x8a,0x91,0x15,0x49,0x44,0x1a,0x53,0x45,0x5f,0x8a,0x7e,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xfd,0xff,0x8c,0x8a,0x73,0x8e,0x83,0x6a,0x8b,0x7a,0x5e,0x96,0x88,0x66,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x9d,0xaa,0x8d,0xa2,0xa5,0x83,0xa7,0xa9,0x82,0xac,0xa8,0x7d,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x8c,0xa6,0x83,0x70,0x80,0x6c,0x91,0xa5,0x82,0x96,0xa0,0x84,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x92,0xbd,0x89,0x94,0x9f,0x82,0x95,0x9e,0x86,0xa6,0xaf,0x91,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfc,0xff,0xff,0xa3,0xbb,0x94,0xac,0xbe,0x97,0xba,0xc7,0x9f,0xc9,0xd6,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0xff,0xff,0x85,0xec,0x91,0x87,0xea,0x8e,0x92,0xed,0x93,0x8d,0xe1,0x8a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x22,0x64,0x4c,0x00,0x4b,0x2b,0x01,0x52,0x29,0x59,0x99,0x7a,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0x60,0x77,0x59,0x7a,0x64,0x57,0xab,0x9d,0x80,0xc9,0xc7,0xa3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x97,0x96,0x76,0xbd,0xb8,0x92,0xd2,0xd1,0xac,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x7e,0x90,0x74,0xab,0xb5,0x96,0xdf,0xe2,0xd2,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xfd,0xff,0xff,0xff,0xff,0x92,0x9b,0x80,0xac,0xb4,0x96,0xea,0xed,0xdd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x9f,0xb8,0x8b,0xba,0xd1,0xa0,0xf1,0xff,0xdd,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xe3,0xff,0xff,0x00,0x4b,0x25,0x10,0x6f,0x32,0x89,0xd0,0x97,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xac,0xb6,0xc3,0xc1,0xc9,0xd3,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff},
{0xe4,0xfe,0xf2,0xf9,0xf7,0xff,0x65,0x67,0x60,0x75,0x6c,0x61,0x81,0x7b,0x62,0x90,0x79,0x66,0x99,0x85,0x6b,0xff,0xff,0xff,0xff,0xff,0xff,0xf9,0xf4,0xfc,0xff,0xff,0xff,0xee,0xe7,0xfa,0x79,0x86,0x74,0x72,0x92,0x6e,0x94,0xa4,0x7f,0xb5,0xbd,0x96,0xc7,0xd0,0xab,0xff,0xff,0xff,0xff,0xff,0xff,0xfb,0xf7,0xff,0xff,0xff,0xff,0xef,0xf2,0xfe,0x4f,0x62,0x57,0x59,0x60,0x5a,0x6a,0x71,0x63,0x86,0x8c,0x7a,0xad,0xaf,0xa7,0xff,0xff,0xff,0xff,0xff,0xff,0xf5,0xec,0xfb,0xff,0xff,0xff,0xed,0xf2,0xff,0x5a,0x75,0x60,0x6b,0x73,0x66,0x79,0x82,0x73,0x85,0x8b,0x77,0xbf,0xbf,0xb7,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xf0,0xf3,0xff,0x70,0x89,0x71,0x95,0xa5,0x87,0xa1,0xae,0x8e,0xb9,0xc7,0xa0,0xe4,0xea,0xd8,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xfb,0xff,0x6d,0xb6,0x78,0x8f,0xc2,0x8b,0x95,0xc7,0x8d,0xb3,0xe1,0xa4,0xb4,0xe4,0xa6,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xee,0xff,0xff,0x2b,0x9d,0x57,0x0d,0x93,0x39,0x00,0x86,0x2e,0x1d,0xad,0x47,0x5b,0xca,0x7b,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0x62,0x76,0x8e,0x1d,0x46,0x51,0x10,0x46,0x43,0x31,0x5e,0x5f,0xbb,0xce,0xd9,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff}
};
///////////////////////////////////////////////////////////////////
// END SECTION

unsigned long timer;
const bool DEBUG = false;
const int HEIGHT = 240;
const int WIDTH = 320;
const int BLOCK_SIZE = 30;
float input[input_size];
const int bytesPerFrame = HEIGHT * WIDTH * 2;
byte camdata[HEIGHT * WIDTH * 2]; // QVGA: 320x240 X 2 bytes per pixel (RGB565)

void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!Camera.begin(QVGA, RGB565, 1)) {
    Serial.println("Failed to initialize camera!");
    while (1);
  }

// Add KNN examples
  for (size_t i = 0; i < number_examples; i++) {
      myKNN.addExample(example_images[i], example_classes[i]);
}



  // Optionally, enable the test pattern for testing
  // Camera.testPattern();
}

void loop() {

  Camera.readFrame(camdata);

  const int frame_height = HEIGHT / BLOCK_SIZE;
  const int frame_width = WIDTH / BLOCK_SIZE;

  // get max value to normalize with
  uint16_t col_max[3] = {0};
  uint16_t col_min[3] = {255 * 255};

  uint16_t rgb_frame[frame_height][frame_width][3] = { 0 };

  for (size_t i = 0; i < bytesPerFrame; i += 2) {

    // Convert from RGB565 to 24-bit RGB
    const uint8_t high = camdata[i];
    const uint8_t low  = camdata[i + 1];
    const uint16_t pixel = (high << 8) | low;

    const uint8_t red =   (pixel & 0b1111100000000000) >> 11;
    const uint8_t green = (pixel & 0b0000011111100000) >> 6;
    const uint8_t blue =  (pixel & 0b0000000000011111);

    // Downsample
    const size_t j = i / 2;
    const uint16_t x = j % WIDTH;
    const uint16_t y = floor(j / WIDTH);
    const uint8_t block_x = floor(x / BLOCK_SIZE);
    const uint8_t block_y = floor(y / BLOCK_SIZE);

    rgb_frame[block_y][block_x][0] += red;
    rgb_frame[block_y][block_x][1] += green;
    rgb_frame[block_y][block_x][2] += blue;

  }

  // Get normalization range (start at 1 because issues with lhs of image)
  for (int y = 0; y < HEIGHT / BLOCK_SIZE; y++) {
    for (int x = 1; x < WIDTH / BLOCK_SIZE; x++) {
      for (int c = 0; c < 3; c++) {
        col_max[0] = max(col_max[0], rgb_frame[y][x][c]);
        col_min[0] = min(col_min[0], rgb_frame[y][x][c]);
      }
    }
  }

  Serial.print("Image starts: ");
  Serial.print(WIDTH / BLOCK_SIZE);
  Serial.print(",");
  Serial.print(HEIGHT / BLOCK_SIZE);
  Serial.print(",");
  Serial.println("RGB");

  int inputPtr = 0;

  // Output to serial viewer
  for (int y = 0; y < HEIGHT / BLOCK_SIZE; y++) {
    for (int x = 0; x < WIDTH / BLOCK_SIZE; x++) {
      Serial.print("p ");
      for (int c = 0; c < 3; c++) {
        int p = map(rgb_frame[y][x][c], col_min[0], col_max[0], 0, 360);
        if (p > 255) {
          p = 255;
        }
        Serial.print(p);
        input[inputPtr++] = p;
        Serial.print(",");
      }
      Serial.println("");
    }
  }

  Serial.print("Time: ");
  timer = micros();
  int classification = myKNN.classify(input, 1); // classify input with K=3
  Serial.println(micros() - timer); //prints time since program started


  float confidence = myKNN.confidence();
  // print the classification and confidence
  Serial.print("Classification: ");
  Serial.println(class_labels[classification]);

  // since there are 2 examples close to the input and K = 3,
  // expect the confidence to be: 2/3 = ~0.67
  Serial.print("Confidence: ");
  Serial.println(confidence);

}
