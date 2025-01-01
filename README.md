# ML Benchmark
 
ML benchmark test for the STM32 embedding device.

## **1. Overview**

**Overview:**  
Benchmark the performance of a speech command recognition model on an STM32 microcontroller by evaluating metrics such as inference latency, memory usage, and power consumption.

**Key Steps:**

1. **Model Preparation and Conversion**
2. **Setting Up the STM32 Environment**
3. **Deploying the Model to STM32**
4. **Implementing the Benchmark Test**
5. **Running and Analyzing the Benchmark**

---

## **2. Prerequisites**

- **Hardware:**
  - An STM32 development board (e.g., STM32H7 series for higher performance).
  - A microphone or pre-recorded audio samples for testing.

- **Software:**
  - **Development Tools:**
    - [STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)
    - [STM32Cube.AI](https://www.st.com/en/development-tools/stm32cubeai.html) (for model conversion)
  - **Libraries:**
    - TensorFlow Lite for Microcontrollers
  - **Other Tools:**
    - Python 3.x environment
    - Git

---

## **3. Model Preparation and Conversion**

### **a. Convert the Model to TensorFlow Lite**

Convert trained TensorFlow model to TensorFlow Lite (TFLite) format with optimizations suitable for embedded devices.

### **c. Validate the TFLite Model**

With the aid of ValidatTFModel.py

## **4. Setting Up the STM32 Environment**

### **a. Install STM32CubeIDE and STM32Cube.AI**

1. **STM32CubeIDE:**
   - install from [STMicroelectronics](https://www.st.com/en/development-tools/stm32cubeide.html).

2. **STM32Cube.AI:**
   - Install STM32Cube.AI plugin within STM32CubeIDE

## **5. Deploying the Model to STM32**

### **a. Convert TFLite Model to C Code Using STM32Cube.AI**

1. **Launch STM32Cube.AI:**
   - STM32CubeIDE and navigate to **`STM32Cube.AI`** perspective.

2. **Import the TFLite Model:**
   - Select `speech_commands_model.tflite` file.

3. **Generate the C Code:**
   - STM32Cube.AI will generate optimized C code.

### **b. Create a New STM32 Project**

1. **New Project:**
   - In STM32CubeIDE, new project for specific STM32 board created.

2. **Generated Model Code:**
   - Add the generated C files from STM32Cube.AI.

3. **Peripherals:**
   - Necessary peripherals (e.g., ADC, I2S) for audio input.

4. **The Model:**
   - Generated API to load the model and perform inference.

---

## **6. Implementing the Benchmark Test**

### **a. The Inference Code**

Main application that captures audio data, preprocesses it as required by the model, runs inference, and records performance metrics. The code in runner.c


### **b. Performance Metrics**

1. **Inference Latency:**
   - Measure the time taken to perform a single inference.

2. **Memory Usage:**
   - RAM and Flash usage ot the model within the STM32's constraints.

3. **Power Consumption:**
   - ST-Link's power profiling or external power measurement hardware to assess power usage during inference.

## **7. Running and Analyzing the Benchmark**

### **a. Flash the Firmware**

1. **Build:**
   - In STM32CubeIDE, build project to generate the firmware binary.

2. **Flash to STM32:**
   - Connect STM32 board and flash the firmware.

### **b. Execute the Benchmark**

1. **The Firmware:**
   - Reset or power cycle the STM32 board to start running the benchmark.

2. **Output:**
   - A serial terminal (e.g., PuTTY, Tera Term) to view the printed inference times and predicted labels.

### **c. Analyze Data**

- **Inference Latency:**
  - The average, minimum, and maximum inference times from the serial output.

- **Memory Usage:**
  - Compiled binary size and runtime memory usage.

- **Power Consumption:**
  - The power usage data collected during inference operations.

**Example Serial Output:**

```
Inference Time: 15 ms, Predicted Label: 3
Inference Time: 14 ms, Predicted Label: 7
Inference Time: 16 ms, Predicted Label: 2
...
```

---

## **8. Optimizing Performance**

- **Model Quantization:**
  - The model uses quantized weights and activations to reduce memory footprint and increase inference speed.

- **Model Pruning:**
  - Remove redundant neurons or layers to streamline the model.

- **Hardware Acceleration:**
  - STM32's DSP extensions or hardware accelerators.


**References:**

- [TensorFlow Lite for Microcontrollers](https://www.tensorflow.org/lite/microcontrollers)
- [STM32Cube.AI Documentation](https://www.st.com/content/st_com/en/products/development-tools/software-development-tools/stm32-software-development-tools/stm32-software-development-tools.html#documentation)
- [STM32CubeIDE User Manual](https://www.st.com/resource/en/user_manual/um2627-stm32cubeide-stm32-ide-stmicroelectronics.pdf)