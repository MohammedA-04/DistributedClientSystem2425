// Design C to analyse sensor data and determine any weather alets
// Take tmp, humidty, pressure as inputs and return alert code

// Task
#include <stdio.h>

int check(float tmp, float humd, float ps)
{
    if (tmp > 30.0 && humd > 80.0)
    {
        // High tmp and humd alert
        return 1;
    }
    else if (ps < 950.0)
    {
        // Low Atmos
        return 2;
    }

    // everything is ok
    return 0;
}

int main()
{
    int checker = check(30.0, 79.0, 949.0);

    switch (checker)
    {
    case 1:
        printf("Alert Code 1: high tmp and humid");
        break;
    case 2:
        printf("Alert Code 2: low atmos ps");
        break;
    case 0:
        printf("Alert Code 0: everything is ok");
        break;
    default:
        printf("Invalid alert code");
    }

    return 0;
}