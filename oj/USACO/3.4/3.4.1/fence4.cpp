/*
USACO
3.4.1 - Closed Fences
Geometry
28 Feb, 2014
Courtesy for this code - Ngyuen
(http://www.cppblog.com/jericho/archive/2011/01/19/138837.html)
/*
ID: Labib Rashid
TASK: fence4
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <cmath>

using namespace std;

struct Point{
    double x,y;
};

struct Segment{
    Point start;
    Point end;
};

const double ZERO = 1e-5;

Point points[205], ansb[205], anse[205], person;
int n, now;

inline double crossProduct(Point &p1, Point &p2, Point &p3){
    return (p1.x-p3.x)*(p2.y-p3.y)-(p2.x-p3.x)*(p1.y-p3.y);
}

bool cross1(Point &p1, Point &p2, Point &p3, Point &p4){

    //straddled experiment
    if(crossProduct(p1, p4, p3)*crossProduct(p4, p2, p3)<=0) return false;
    if(crossProduct(p4, p2, p1)*crossProduct(p2, p3, p1)<=0) return false;

    return true;
}

bool cross2(Point &p1, Point &p2, Point &p3, Point &p4){

    //straddled experiment
    if(crossProduct(p1, p4, p3)*crossProduct(p4, p2, p3)<0) return false;
    if(crossProduct(p4, p2, p1)*crossProduct(p2, p3, p1)<0) return false;

    return true;
}

bool can(int k){
    for(int i= k+1; i<n; ++i)
        if(cross1(points[k], points[k+1], points[i], points[i+1]) )
            return false;
    return true;
}

bool same(Point &p1, Point &p2){
    if(fabs(p1.x-p2.x)<=ZERO && fabs(p1.y-p2.y)<=ZERO )
        return true;
    return false;
}

bool check(Point &a, Point &b){

    int i;

    for(i=0; i<n; ++i)
        if(i!=now && cross2(person, a, points[i], points[i+1]) && cross2(person,b, points[i], points[i+1]) )
            return false;

    bool b1=true, b2=true, b3=true;

    Point mid;
    mid.x = (a.x+b.x)/2;
    mid.y = (a.y+b.y)/2;

    for(i=0; i<n; ++i){
        if(i!=now){
            if(b1&&cross2(a, person, points[i], points[i+1]))    b1=false;
            if(b2&&cross2(b, person, points[i], points[i+1]))    b2=false;
            if(b3&&cross2(mid, person, points[i], points[i+1]))    b3=false;
        }
    }

    if(b1||b2||b3)    return true;
    if(same(a,b))    return false;
    if(check(a, mid)) return true;
    if(check(mid, b)) return true;
    return false;
}

int main(){

    int i;

    //ifstream fin("fence4.txt");
    ifstream fin("fence4.in");
    ofstream fout("fence4.out");

    fin>>n;

    fin>>person.x>>person.y;

    for(i=0; i<n; ++i)
        fin>>points[i].x>>points[i].y;
    points[n]= points[0];

    //Q1

    for(i=0; i<n; ++i){
        if(!can(i)){
            fout<<"NOFENCE"<<endl;
            return 0;
        }
    }


    //Q2
    int cnt=0;
    for(i=0; i<n-2; ++i){
        now = i;
        if(check(points[i], points[i+1])){
            ansb[cnt]    = points[i];
            anse[cnt]    = points[i+1];
            cnt++;
        }
    }

    now = n-1;
    if(check(points[0], points[n-1])){
        ansb[cnt] = points[0];
        anse[cnt] = points[n-1];
        cnt++;
    }

    now = n-2;
    if(check(points[n-2], points[n-1])){
        ansb[cnt] = points[n-2];
        anse[cnt] = points[n-1];
        cnt++;
    }



    fout<<cnt<<endl;
    for(i=0; i<cnt; ++i)
        fout<<ansb[i].x<<" "<<ansb[i].y<<" "<<anse[i].x<<" "<<anse[i].y<<endl;

    return 0;
}
