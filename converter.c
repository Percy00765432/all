#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void lengthConverter();
void weightConverter();
void temperatureConverter();
void areaConverter();
void volumeConverter();
void speedConverter();
void timeConverter();
void pressureConverter();
void energyConverter();
void dataConverter();
void angleConverter();
void displayMainMenu();

int main() {
    int choice;
    
    do {
        displayMainMenu();
        printf("Enter your choice (0 to exit): ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: lengthConverter(); break;
            case 2: weightConverter(); break;
            case 3: temperatureConverter(); break;
            case 4: areaConverter(); break;
            case 5: volumeConverter(); break;
            case 6: speedConverter(); break;
            case 7: timeConverter(); break;
            case 8: pressureConverter(); break;
            case 9: energyConverter(); break;
            case 10: dataConverter(); break;
            case 11: angleConverter(); break;
            case 0: printf("Thank you for using the unit converter!\n"); break;
            default: printf("Invalid choice! Please try again.\n");
        }
        printf("\n");
    } while(choice != 0);
    
    return 0;
}

void displayMainMenu() {
    printf("\n====== Unit Converter ======\n");
    printf("1.  Length Converter\n");
    printf("2.  Weight/Mass Converter\n");
    printf("3.  Temperature Converter\n");
    printf("4.  Area Converter\n");
    printf("5.  Volume Converter\n");
    printf("6.  Speed Converter\n");
    printf("7.  Time Converter\n");
    printf("8.  Pressure Converter\n");
    printf("9.  Energy Converter\n");
    printf("10. Data Storage Converter\n");
    printf("11. Angle Converter\n");
    printf("0.  Exit\n");
    printf("=================================\n");
}

void lengthConverter() {
    int choice;
    double value;
    
    printf("\n=== Length Converter ===\n");
    printf("1.  Kilometers to Miles\n");
    printf("2.  Miles to Kilometers\n");
    printf("3.  Meters to Feet\n");
    printf("4.  Feet to Meters\n");
    printf("5.  Centimeters to Inches\n");
    printf("6.  Inches to Centimeters\n");
    printf("7.  Yards to Meters\n");
    printf("8.  Meters to Yards\n");
    printf("9.  Millimeters to Inches\n");
    printf("10. Inches to Millimeters\n");
    printf("11. Micrometers to Inches\n");
    printf("12. Nanometers to Inches\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f km = %.4f miles\n", value, value * 0.621371); break;
        case 2: printf("%.4f miles = %.4f km\n", value, value * 1.60934); break;
        case 3: printf("%.4f m = %.4f ft\n", value, value * 3.28084); break;
        case 4: printf("%.4f ft = %.4f m\n", value, value * 0.3048); break;
        case 5: printf("%.4f cm = %.4f inches\n", value, value * 0.393701); break;
        case 6: printf("%.4f inches = %.4f cm\n", value, value * 2.54); break;
        case 7: printf("%.4f yards = %.4f m\n", value, value * 0.9144); break;
        case 8: printf("%.4f m = %.4f yards\n", value, value * 1.09361); break;
        case 9: printf("%.4f mm = %.4f inches\n", value, value * 0.0393701); break;
        case 10: printf("%.4f inches = %.4f mm\n", value, value * 25.4); break;
        case 11: printf("%.4f μm = %.10f inches\n", value, value * 0.0000393701); break;
        case 12: printf("%.4f nm = %.10f inches\n", value, value * 0.0000000393701); break;
        default: printf("Invalid choice!\n");
    }
}

void weightConverter() {
    int choice;
    double value;
    
    printf("\n=== Weight/Mass Converter ===\n");
    printf("1.  Kilograms to Pounds\n");
    printf("2.  Pounds to Kilograms\n");
    printf("3.  Grams to Ounces\n");
    printf("4.  Ounces to Grams\n");
    printf("5.  Tonnes to Pounds\n");
    printf("6.  Pounds to Tonnes\n");
    printf("7.  Milligrams to Ounces\n");
    printf("8.  Ounces to Milligrams\n");
    printf("9.  Stone to Kilograms\n");
    printf("10. Kilograms to Stone\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f kg = %.4f lbs\n", value, value * 2.20462); break;
        case 2: printf("%.4f lbs = %.4f kg\n", value, value * 0.453592); break;
        case 3: printf("%.4f g = %.4f oz\n", value, value * 0.035274); break;
        case 4: printf("%.4f oz = %.4f g\n", value, value * 28.3495); break;
        case 5: printf("%.4f tonnes = %.4f lbs\n", value, value * 2204.62); break;
        case 6: printf("%.4f lbs = %.4f tonnes\n", value, value * 0.000453592); break;
        case 7: printf("%.4f mg = %.8f oz\n", value, value * 0.000035274); break;
        case 8: printf("%.4f oz = %.4f mg\n", value, value * 28349.5); break;
        case 9: printf("%.4f stone = %.4f kg\n", value, value * 6.35029); break;
        case 10: printf("%.4f kg = %.4f stone\n", value, value * 0.157473); break;
        default: printf("Invalid choice!\n");
    }
}

void temperatureConverter() {
    int choice;
    double value;
    
    printf("\n=== Temperature Converter ===\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("3. Celsius to Kelvin\n");
    printf("4. Kelvin to Celsius\n");
    printf("5. Fahrenheit to Kelvin\n");
    printf("6. Kelvin to Fahrenheit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.2f°C = %.2f°F\n", value, (value * 9/5) + 32); break;
        case 2: printf("%.2f°F = %.2f°C\n", value, (value - 32) * 5/9); break;
        case 3: printf("%.2f°C = %.2f K\n", value, value + 273.15); break;
        case 4: printf("%.2f K = %.2f°C\n", value, value - 273.15); break;
        case 5: printf("%.2f°F = %.2f K\n", value, ((value - 32) * 5/9) + 273.15); break;
        case 6: printf("%.2f K = %.2f°F\n", value, ((value - 273.15) * 9/5) + 32); break;
        default: printf("Invalid choice!\n");
    }
}

void areaConverter() {
    int choice;
    double value;
    
    printf("\n=== Area Converter ===\n");
    printf("1.  Square Meters to Square Feet\n");
    printf("2.  Square Feet to Square Meters\n");
    printf("3.  Square Kilometers to Square Miles\n");
    printf("4.  Square Miles to Square Kilometers\n");
    printf("5.  Hectares to Acres\n");
    printf("6.  Acres to Hectares\n");
    printf("7.  Square Centimeters to Square Inches\n");
    printf("8.  Square Inches to Square Centimeters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f m² = %.4f ft²\n", value, value * 10.7639); break;
        case 2: printf("%.4f ft² = %.4f m²\n", value, value * 0.092903); break;
        case 3: printf("%.4f km² = %.4f mi²\n", value, value * 0.386102); break;
        case 4: printf("%.4f mi² = %.4f km²\n", value, value * 2.58999); break;
        case 5: printf("%.4f hectares = %.4f acres\n", value, value * 2.47105); break;
        case 6: printf("%.4f acres = %.4f hectares\n", value, value * 0.404686); break;
        case 7: printf("%.4f cm² = %.4f in²\n", value, value * 0.155); break;
        case 8: printf("%.4f in² = %.4f cm²\n", value, value * 6.4516); break;
        default: printf("Invalid choice!\n");
    }
}

void volumeConverter() {
    int choice;
    double value;
    
    printf("\n=== Volume Converter ===\n");
    printf("1.  Liters to Gallons (US)\n");
    printf("2.  Gallons (US) to Liters\n");
    printf("3.  Milliliters to Fluid Ounces (US)\n");
    printf("4.  Fluid Ounces (US) to Milliliters\n");
    printf("5.  Cubic Meters to Cubic Feet\n");
    printf("6.  Cubic Feet to Cubic Meters\n");
    printf("7.  Cubic Centimeters to Cubic Inches\n");
    printf("8.  Cubic Inches to Cubic Centimeters\n");
    printf("9.  Liters to Imperial Gallons\n");
    printf("10. Imperial Gallons to Liters\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f L = %.4f gal (US)\n", value, value * 0.264172); break;
        case 2: printf("%.4f gal (US) = %.4f L\n", value, value * 3.78541); break;
        case 3: printf("%.4f mL = %.4f fl oz (US)\n", value, value * 0.033814); break;
        case 4: printf("%.4f fl oz (US) = %.4f mL\n", value, value * 29.5735); break;
        case 5: printf("%.4f m³ = %.4f ft³\n", value, value * 35.3147); break;
        case 6: printf("%.4f ft³ = %.4f m³\n", value, value * 0.0283168); break;
        case 7: printf("%.4f cm³ = %.4f in³\n", value, value * 0.0610237); break;
        case 8: printf("%.4f in³ = %.4f cm³\n", value, value * 16.3871); break;
        case 9: printf("%.4f L = %.4f gal (UK)\n", value, value * 0.219969); break;
        case 10: printf("%.4f gal (UK) = %.4f L\n", value, value * 4.54609); break;
        default: printf("Invalid choice!\n");
    }
}

void speedConverter() {
    int choice;
    double value;
    
    printf("\n=== Speed Converter ===\n");
    printf("1. Kilometers per Hour to Miles per Hour\n");
    printf("2. Miles per Hour to Kilometers per Hour\n");
    printf("3. Meters per Second to Miles per Hour\n");
    printf("4. Miles per Hour to Meters per Second\n");
    printf("5. Knots to Miles per Hour\n");
    printf("6. Miles per Hour to Knots\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f km/h = %.4f mph\n", value, value * 0.621371); break;
        case 2: printf("%.4f mph = %.4f km/h\n", value, value * 1.60934); break;
        case 3: printf("%.4f m/s = %.4f mph\n", value, value * 2.23694); break;
        case 4: printf("%.4f mph = %.4f m/s\n", value, value * 0.44704); break;
        case 5: printf("%.4f knots = %.4f mph\n", value, value * 1.15078); break;
        case 6: printf("%.4f mph = %.4f knots\n", value, value * 0.868976); break;
        default: printf("Invalid choice!\n");
    }
}

void timeConverter() {
    int choice;
    double value;
    
    printf("\n=== Time Converter ===\n");
    printf("1. Hours to Minutes\n");
    printf("2. Minutes to Hours\n");
    printf("3. Days to Hours\n");
    printf("4. Hours to Days\n");
    printf("5. Weeks to Days\n");
    printf("6. Days to Weeks\n");
    printf("7. Years to Days\n");
    printf("8. Days to Years\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f hours = %.4f minutes\n", value, value * 60); break;
        case 2: printf("%.4f minutes = %.4f hours\n", value, value / 60); break;
        case 3: printf("%.4f days = %.4f hours\n", value, value * 24); break;
        case 4: printf("%.4f hours = %.4f days\n", value, value / 24); break;
        case 5: printf("%.4f weeks = %.4f days\n", value, value * 7); break;
        case 6: printf("%.4f days = %.4f weeks\n", value, value / 7); break;
        case 7: printf("%.4f years = %.4f days\n", value, value * 365.242); break;
        case 8: printf("%.4f days = %.4f years\n", value, value / 365.242); break;
        default: printf("Invalid choice!\n");
    }
}

void pressureConverter() {
    int choice;
    double value;
    
    printf("\n=== Pressure Converter ===\n");
    printf("1. Pascal to Atmosphere\n");
    printf("2. Atmosphere to Pascal\n");
    printf("3. Bar to Pascal\n");
    printf("4. Pascal to Bar\n");
    printf("5. PSI to Pascal\n");
    printf("6. Pascal to PSI\n");
    printf("7. Torr to Pascal\n");
    printf("8. Pascal to Torr\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f Pa = %.8f atm\n", value, value / 101325); break;
        case 2: printf("%.4f atm = %.4f Pa\n", value, value * 101325); break;
        case 3: printf("%.4f bar = %.4f Pa\n", value, value * 100000); break;
        case 4: printf("%.4f Pa = %.8f bar\n", value, value / 100000); break;
        case 5: printf("%.4f PSI = %.4f Pa\n", value, value * 6894.76); break;
        case 6: printf("%.4f Pa = %.8f PSI\n", value, value / 6894.76); break;
        case 7: printf("%.4f Torr = %.4f Pa\n", value, value * 133.322); break;
        case 8: printf("%.4f Pa = %.8f Torr\n", value, value / 133.322); break;
        default: printf("Invalid choice!\n");
    }
}

void energyConverter() {
    int choice;
    double value;
    
    printf("\n=== Energy Converter ===\n");
    printf("1. Joules to Calories\n");
    printf("2. Calories to Joules\n");
    printf("3. Kilowatt-hours to Joules\n");
    printf("4. Joules to Kilowatt-hours\n");
    printf("5. Electron Volts to Joules\n");
    printf("6. Joules to Electron Volts\n");
    printf("7. BTU to Joules\n");
    printf("8. Joules to BTU\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f J = %.4f cal\n", value, value / 4.184); break;
        case 2: printf("%.4f cal = %.4f J\n", value, value * 4.184); break;
        case 3: printf("%.4f kWh = %.4f J\n", value, value * 3600000); break;
        case 4: printf("%.4f J = %.8f kWh\n", value, value / 3600000); break;
        case 5: printf("%.4f eV = %.8e J\n", value, value * 1.602176634e-19); break;
        case 6: printf("%.4f J = %.4e eV\n", value, value / 1.602176634e-19); break;
        case 7: printf("%.4f BTU = %.4f J\n", value, value * 1055.06); break;
        case 8: printf("%.4f J = %.8f BTU\n", value, value / 1055.06); break;
        default: printf("Invalid choice!\n");
    }
}

void dataConverter() {
    int choice;
    double value;
    
    printf("\n=== Data Storage Converter ===\n");
    printf("1. Bytes to Kilobytes\n");
    printf("2. Kilobytes to Megabytes\n");
    printf("3. Megabytes to Gigabytes\n");
    printf("4. Gigabytes to Terabytes\n");
    printf("5. Bits to Bytes\n");
    printf("6. Bytes to Bits\n");
    printf("7. Megabits to Megabytes\n");
    printf("8. Megabytes to Megabits\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f B = %.8f KB\n", value, value / 1024); break;
        case 2: printf("%.4f KB = %.8f MB\n", value, value / 1024); break;
        case 3: printf("%.4f MB = %.8f GB\n", value, value / 1024); break;
        case 4: printf("%.4f GB = %.8f TB\n", value, value / 1024); break;
        case 5: printf("%.4f bits = %.8f bytes\n", value, value / 8); break;
        case 6: printf("%.4f bytes = %.4f bits\n", value, value * 8); break;
        case 7: printf("%.4f Mb = %.8f MB\n", value, value / 8); break;
        case 8: printf("%.4f MB = %.4f Mb\n", value, value * 8); break;
        default: printf("Invalid choice!\n");
    }
}

void angleConverter() {
    int choice;
    double value;
    
    printf("\n=== Angle Converter ===\n");
    printf("1. Degrees to Radians\n");
    printf("2. Radians to Degrees\n");
    printf("3. Degrees to Gradians\n");
    printf("4. Gradians to Degrees\n");
    printf("5. Radians to Gradians\n");
    printf("6. Gradians to Radians\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    printf("Enter the value: ");
    scanf("%lf", &value);
    
    switch(choice) {
        case 1: printf("%.4f degrees = %.4f radians\n", value, value * M_PI / 180); break;
        case 2: printf("%.4f radians = %.4f degrees\n", value, value * 180 / M_PI); break;
        case 3: printf("%.4f degrees = %.4f gradians\n", value, value * 400 / 360); break;
        case 4: printf("%.4f gradians = %.4f degrees\n", value, value * 360 / 400); break;
        case 5: printf("%.4f radians = %.4f gradians\n", value, value * 200 / M_PI); break;
        case 6: printf("%.4f gradians = %.4f radians\n", value, value * M_PI / 200); break;
        default: printf("Invalid choice!\n");
    }
}