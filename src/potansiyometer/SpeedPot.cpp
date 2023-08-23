#include "SpeedPot.h"
#include <Arduino.h>

#define NUM_READ 5

void swap(int &a, int &b)
{
        int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{   
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

float calculateMedianMean(int arr[], int size)
{
    quickSort(arr, 0, size - 1);

    // Sıralanmış diziyi yazdırabilirsiniz (isteğe bağlı)
    /*
     Serial.print("Sıralanmış Dizi: ");
    for (int i = 0; i < size; i++) {
        Serial.print(arr[i]);
        Serial.print(" ");
    }
    Serial.println(); 
    */

    float median;
    if (size % 2 == 0) {
        median = (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    } else {
        median = arr[size / 2];
    }

    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    float mean = static_cast<float>(sum) / size;

    return mean;
}

float readPotVaules()
{
   int readings[NUM_READ];
    for (int i = 0; i < NUM_READ; i++) {
        readings[i] = analogRead(POTANS_PIN);
        delayMicroseconds(300);  // Okuma aralığını ayarlayabilirsiniz
    }

    float average = calculateMedianMean(readings, NUM_READ);
    return average;
}
