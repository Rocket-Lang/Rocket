#include <string>
#include <ctime>
#include <chrono>


//gets the current time
time_t now(){

    time_t time_now;

    //gets the current time
    time_now = time(NULL);

    //returns current time
    return time_now;

}


//gets the minutes to wait and sleeps
void wait_min(int time_min){

    //sleep for input minutes
    int time_secs = time_min / 60;

    std::this_thread::sleep_for(std::chrono::seconds(time_secs));


}


//get the seconds to wait and sleeps
void wait_secs(int time_secs){

    //sleep for input seconds
    std::this_thread::sleep_for(std::chrono::seconds(time_secs));


}


//get the hours to wait and sleeps
void wait_hours(int time_hours){

    //sleep for input hours
    std:this_threa::sleep_for(std::chrono::seconds(time_hours));


}


//stores time types
enum{
    Nano,
    Micro,
    Milli,
    Second,
    Minute,
    Hour,
    Day

}
