#include "main.h"
#include "speech_commands_model.h"  // Generated by STM32Cube.AI
#include "ai_platform.h"
#include "arm_math.h"

#include "audio_input.h"  // Hypothetical library
#include "timing.h"       // Hypothetical library

int main(void)
{
    HAL_Init();

    SystemClock_Config();

    MX_GPIO_Init();
    MX_I2S_Init();

    ai_handle network = AI_HANDLE_NULL;
    ai_error err = ai_speech_commands_model_create(&network, NULL);
    if (err.type != AI_ERROR_NONE) {
        // Handle error
    }

    if (!ai_speech_commands_model_init(network, NULL)) {
        // Handle error
    }

    ai_i32 input_size = ai_speech_commands_model_inputs_size(network, NULL);
    ai_i32 output_size = ai_speech_commands_model_outputs_size(network, NULL);

    int16_t input_data[input_size];
    int8_t output_data[output_size];

    uint32_t start_time, end_time, inference_time;

    while (1)
    {
        capture_audio(input_data, input_size);

        start_time = get_system_time();

        ai_speech_commands_model_run(network, input_data, output_data);

        end_time = get_system_time();
        inference_time = end_time - start_time;

        int predicted_label = -1;
        int8_t max_score = INT8_MIN;
        for (int i = 0; i < output_size; i++) {
            if (output_data[i] > max_score) {
                max_score = output_data[i];
                predicted_label = i;
            }
        }

        printf("Inference Time: %lu ms, Predicted Label: %d\n", inference_time, predicted_label);

        HAL_Delay(1000);
    }
}