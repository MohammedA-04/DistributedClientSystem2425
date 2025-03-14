#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to determine alert code in two.c
int check(float tmp, float humd, float ps)
{
    if (tmp > 30.0 && humd > 80.0)
    {
        return 1; // High temp & humidity alert
    }
    else if (ps < 950.0)
    {
        return 2; // Low atmospheric pressure alert
    }
    return 0; // Everything is OK
}

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Generate random sensor values
    float tmp = (rand() % 50) + 10;  // Temp: 10 to 59 °C (0 -> 49 be -> 1 to 59)
    float humd = (rand() % 100) + 1; // Humidity: 1 to 100% (0 -> 99 be 1 -> 100)
    float ps = (rand() % 100) + 900; // Pressure: 900 to 999 hPa (0 to 99 -> 900 -> 999)

    // rand() % N {res: 0 to n^-1} -> + base_value -> shifts so 0 to 49 it woudl be 10 to 59

    // Get alert code
    int alertCode = check(tmp, humd, ps);

    // Open file for writing
    FILE *file = fopen("sensor_data.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data to file
    fprintf(file, "Temperature: %.2f°C\n", tmp);
    fprintf(file, "Humidity: %.2f%%\n", humd);
    fprintf(file, "Pressure: %.2f hPa\n", ps);
    fprintf(file, "Alert Code: %d\n", alertCode);

    // Close file
    fclose(file);

    // Print confirmation
    printf("Sensor data saved to sensor_data.txt\n");

    return 0;
}
