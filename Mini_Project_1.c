#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<conio.h>
#include<unistd.h>

double toRadians(double inRadians);
double maxHeight(double initialVelocity, double launchAngle);
double projectileRange(double initialVelocity, double sinLaunchAngle, double cosLaunchAngle);
double projectileTime(double initialVelocity, double sinLaunchAngle);
double trajectoryValue(double tanLaunchAngle, double initialVelocity, double cosLaunchAngle);

#define ACC_GRAV 9.81
#define PI 3.14159265

int main() {
    
    double launchAngle, initialVelocity, trajectory, timeOfFlight, maximumHeight, range, sinLaunchAngle, cosLaunchAngle, tanLaunchAngle;
    
    printf("Please Enter Angle of Projection(In degrees) : ");
    scanf("%lf", &launchAngle);

    sleep(2);
    
    printf("Please Enter Initial Velocity(In m/s) : ");
    scanf("%lf", &initialVelocity);
    
    
    sinLaunchAngle = sin(toRadians(launchAngle));
    
    cosLaunchAngle = cos(toRadians(launchAngle));
    
    tanLaunchAngle = tan(toRadians(launchAngle));
    
    maximumHeight = maxHeight(initialVelocity, sinLaunchAngle);
    
    range = projectileRange(initialVelocity, sinLaunchAngle, cosLaunchAngle);
    
    timeOfFlight = projectileTime(initialVelocity, sinLaunchAngle);
    
    trajectory = trajectoryValue(tanLaunchAngle, initialVelocity, cosLaunchAngle);

    system("cls"); 


    printf("Computing launch angle...\n");
    sleep(3);    
    printf("The Launch Angle is : %.2lf degrees\n", launchAngle);
    sleep(3);
    
    printf("Computing Maximum height..\n");
    sleep(3);    
    printf("The Maximum Height is : %.2lf meters\n", maximumHeight);
    sleep(3);
    
    printf("Computing projectile range...\n");
    sleep(3);    
    printf("The Projectile Range is : %.2lf meters\n", range);
    sleep(3);

    printf("Computing Time of flight...\n");
    sleep(3);    
    printf("The Projectile Time of Flight is : %.2lf seconds\n", timeOfFlight);
    sleep(3);
    
    printf("Equating the final trajectory path...\n");
    sleep(3);    
    printf("The Final Trajectory of Path is y = x * %0.2lf - %0.2lfx^2 \n", tanLaunchAngle, ACC_GRAV/(2 * pow(initialVelocity, 2) * pow(cosLaunchAngle, 2)));
     sleep(3);
}

double toRadians(double inLaunchAngleDegrees) {
    
    return inLaunchAngleDegrees * (PI / 180);
}

double maxHeight(double initialVelocity, double sinLaunchAngle) {
    
    return pow((initialVelocity * sinLaunchAngle), 2) / (2 * ACC_GRAV);
}

double projectileRange(double initialVelocity, double sinLaunchAngle, double cosLaunchAngle) {
    
    return ((pow(initialVelocity, 2)) * 2 *  sinLaunchAngle * cosLaunchAngle) / ACC_GRAV;
}

double projectileTime(double initialVelocity, double sinLaunchAngle) {
    
    return (2 * initialVelocity * sinLaunchAngle) / ACC_GRAV; 
}

double trajectoryValue(double tanLaunchAngle, double initialVelocity, double cosLaunchAngle) {
    return (tanLaunchAngle - (ACC_GRAV / 2 * (pow(initialVelocity, 2)) * (pow(cosLaunchAngle, 2))));
}
