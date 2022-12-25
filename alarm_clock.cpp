#include <bits/stdc++.h>
using namespace std;
#include <ctime>



set<int> alarm_time;

class alarmclock{

int hh,mm,ss,snooze=0;
public:
 time_t now = time(0);
   // convert now to string form
   string dt = ctime(&now);


int setAlarm(int hour, int minute){
    int ans =0;

    ans+= hour*60;
    ans+= minute;
    cout<<"Alarm is set"<<endl;
    alarm_time.insert(ans);
    return ans;
}

void delete_alarm(int hour, int minute){
    int ans =0;

    ans+= hour*60;
    ans+= minute;
    alarm_time.erase(ans);
    cout<<"Alarm is deleted"<<endl;

}

void display_time(){
     time_t now = time(0);
   // convert now to string form
   string dt = ctime(&now);
   cout << "The local date and time is: " << dt << endl;

}

void display_all_alarms(){
    cout<<" All the alarms are "<<endl;
   for (auto it = alarm_time.begin(); it != alarm_time.end(); ++it)
        cout << ' ' << *it;

        cout<<endl;
    cout << "**************************************************"<<endl;
}

void snooze_alarm(){
    // Find Current time ;
    time_t rawtime;
    tm* timeinfo;
    char buffer [16];
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(buffer,16,"%H%M",timeinfo);
    int current_time = atoi(buffer);
    //cout<<"Current time in UNIX "<<current_time;

    if(snooze>3){
        cout<<"Cannot Snooze"<<endl;
        snooze=0;
    }
    else{
       snooze++;
       int hr = current_time/100;
       int mn = current_time%100;
       alarm_time.insert(hr*60 + mn);
       cout<<"Alarm set for 5 minutes ahead .Snooze ("<<snooze<<")"<<endl;
    }
}


void alarm(){

 // Find Current time ;

       while(true){
             time_t rawtime;
                tm* timeinfo;
                char buffer [16];
                time(&rawtime);
                timeinfo = localtime(&rawtime);
                strftime(buffer,16,"%H%M",timeinfo);
                int current_time = atoi(buffer);
                //cout<<"Current time in UNIX "<<current_time;


                   int hr = current_time/100;
                   int mn = current_time%100;
                   int time = hr*60 + mn;
        if( alarm_time.find(time)!=alarm_time.end()){
             cout<<endl<<"Wake UP !!!!"<<endl<<">>> Press CTRL+C or Close the window to stop the alarm <<<"<<endl;
             break;
        }
       }


}




};



int main(){
    alarmclock a;
    a.display_time();
   cout<< a.setAlarm(19,44)<<endl;
   cout<< a.setAlarm(20,0)<<endl;
   cout<< a.setAlarm(21,0)<<endl;
   cout<< a.setAlarm(22,0)<<endl;
   a.display_all_alarms();
   a.delete_alarm(21,0);
   a.display_all_alarms();
   //a.snooze_alarm();
   //a.display_all_alarms();
   a.alarm();



   ///////////////////////////
   //   for displaying current time in unix

    time_t rawtime;
    tm* timeinfo;
    char buffer [16];

    time(&rawtime);
    timeinfo = localtime(&rawtime);

    strftime(buffer,16,"%H%M",timeinfo);
    int current_time = atoi(buffer);
    cout<<"Current time in UNIX "<<current_time;

    ////////////////////////////////
    return 0;
}
