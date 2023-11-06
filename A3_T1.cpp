#include <iostream>
using namespace std;
int findsum(int x,int y,int z){
    int sum=(x+y+z);
    return sum;
}
void showsum(int sum){
    cout<<"Sum is : "<<sum<<endl;
}
float findavg(int x,int y,int z){
   float average=float(x)+float(y)+float(z)/3;
   return average;
}
void showavg(float avg){
    cout<<fixed;
    cout.precision(2);
    cout<<"Average is : "<<avg<<endl;
}
int findmax(int x,int y,int z){
    int max=x;
    max=(y>max?y:max);
    max=(z>max?z:max);
    return max;
}
int findmin(int x,int y,int z){
    int min=x;
    min=(y<min?y:min);
    min=(z<min?z:min);
    return min;
}
void showmax(int max){
    cout<<"Max is : "<<max<<endl;
}
void showmin(int min){
    cout<<"Min is : "<<min<<endl;
}
int main(){
    int x,y,z,max,min,sum;
    float avg;
    cout<<"Enter X,Y & Z"<<endl;
    cin>>x>>y>>z;
    sum=findsum(x,y,z);
    avg=findavg(x,y,z);
    max=findmax(x,y,z);
    min=findmin(x,y,z);
    showsum(sum);
    showavg(avg);
    showmax(max);
    showmin(min);
    return 0;
}

