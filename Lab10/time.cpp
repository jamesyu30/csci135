/*
Author: James Yu
Course: CSCI-135
Instructor: Tong Yi
Assignment: Lab 10A

time class
*/
//
#include <iostream>
using namespace std;

class Time { 
public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time){
    return time.h * 60 + time.m;
}

int minutesUntil(Time earlier, Time later){
    return (later.h - earlier.h ) * 60 + (later.m - earlier.m);
}

Time addMinutes(Time time0, int min){
    Time newTime;
    if (min > 60){
        newTime.h = time0.h + min/60;
        newTime.m = time0.m + min % 60;
    }else{
        newTime.h = time0.h;
        newTime.m = time0.m + min;
    }

    //adjusting for minutes going over 60
    if (newTime.m > 59){
        newTime.h  = newTime.h + newTime.m/60;
        newTime.m = newTime.m % 60;
    }
    return newTime;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie { 
public: 
    string title;
    Genre genre;     // only one genre per movie
    int duration;    // in minutes
};

class TimeSlot { 
public: 
    Movie movie;     // what movie
    Time startTime;  // when it starts
};

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

void printTimeSlot(TimeSlot ts){
    Time start = ts.startTime;
    Time end;
    string g;

    end = addMinutes(start, ts.movie.duration);

    switch (ts.movie.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }

    cout << ts.movie.title << " " << g << " (" << ts.movie.duration << " min) [starts at " << start.h << ":" << start.m << ", ends by " << end.h << ":" << end.m << "]" << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie){
    //start time of next movie
    Time end;
    end = addMinutes(ts.startTime, ts.movie.duration);

    TimeSlot next = {nextMovie, end};
    return next;
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2){
    //ts2 is later
    if (minutesUntil(ts1.startTime, ts2.startTime) > 0){
        if (ts1.movie.duration > minutesUntil(ts1.startTime, ts2.startTime)){
            return true;
        }else{
            return false;
        }
    }else{
        if (ts2.movie.duration > minutesUntil(ts2.startTime, ts1.startTime)){
            return true;
        }else{
            return false;
        }
    }
}

int main(){
    
}