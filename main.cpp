#include<bits/stdc++.h>
//ACPC2022
//TposersFTW
#define endl "\n"
#define ll long long
#define ull unsigned long long
#define pb push_back
#define lcm(x,y) x*y/__gcd(x,y)
#define summ(n) (n*(n+1))/2
using namespace std;

struct process{
    int pid;
    int arrivalTime;
    int burstTime;
    int serviceTime=0;
    int waitingTime;
};

int main(){
    struct process p[100];
    queue<process> q;
    cout<<"Enter Number of Processes: ";
    int n,ct=0,av=0;cin>>n;
    for(int i=0;i<n;i++){
        cout<<endl<<"Enter the arrival time of process #"<<i+1<<": ";
        cin>>p[i].arrivalTime;
        cout<<endl<<"Enter the burst time of process #"<<i+1<<": ";
        cin>>p[i].burstTime;
        p[i].pid=i+1;
    }
    p[0].serviceTime=p[0].arrivalTime;
    p[0].waitingTime=p[0].serviceTime-p[0].arrivalTime;
    q.push(p[0]);
    for(int i=1;i<n;i++){
        p[i].serviceTime=p[i-1].serviceTime+p[i-1].burstTime;
        p[i].waitingTime=p[i].serviceTime-p[i].arrivalTime;
        av+=p[i].waitingTime;
        q.push(p[i]);
    }
        for(int i=0;i<n;i++){
        cout<<endl<<"Process #"<<q.front().pid<<" "<<"Arrival Time: "<<q.front().arrivalTime<<" "<<"Burst Time: "<<q.front().burstTime<<" "<<"Waiting Time: "<<q.front().waitingTime;
        q.pop();
    }
    cout<<endl<<"Average Time: "<<av/n;

    return 0;
}
//Test Cases
//3
//0
//3
//1
//5
//2
//4
