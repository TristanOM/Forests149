#define _USE_MATH_DEFINES

#include <iostream>
#include <vector>
#include <string>
#include<cmath>

using namespace std;

//calculate anlges based on quadrant with respect to x and y
//either breadth first or by quadrant?
//take angle of center point and use it to find the angle to both sides
//use -tan(opposite/adjacent)

class Angle{//store the two angles made by looking at a tree
	public:
		Angle(){bottom =0, top =0;}
		Angle(double B, double T);
		//public:
		bool isObscure(double b, double s );
		double getDegree();

	private:
		double bottom;
		double top;
		double bangle;
};

Angle::Angle(double B, double S){
	bottom = B - S;
	top = B + S;
	bangle = B;
	//cout << bottom << top;
}

double Angle::getDegree(){
	return abs(top - abs(top-bottom));
	//return bottom*2;
}

bool Angle::isObscure(double Big, double Small){
	bool r = false;
	if(Big > bangle){
		if(Big - Small <= top + 0.01)
			r = true;
	}
	else if( Big < bangle){
		if( Big +Small >= bottom - 0.01)
			r = true;
	}
	else{//if Big =bangle
		r = true;
	}
		return r;
}

int check(double D, double X, double Y){
	vector<Angle> q1;
	double opposite = D/2;
	double hypotenuse;
	double Bangle, Sangle;
	int count = 0;
	bool isVisible = true;

	int a =1, b =1;
	int line = 1;
	double xx, yy;//these are the points to check each quad
	for(int i =0; i<4;i++){
		q1.clear();
		if(q1.empty())
			cout << "vector is empty" << endl;

		if ( i ==0){//1st quad
			xx = X;
			yy = Y;
		}
		else if(i ==1){//2nd quad
			xx = 1-X;
		}
		else if(i == 2){//3rd quad
			xx = X;
			yy = 1-Y;
		}
		else if( i == 3){//4th quad
			xx = X - 1;
		}

		while(line < 15){

			hypotenuse = sqrt(pow(abs(a - xx),2) + pow(abs(b - yy),2));//get distance 2 point
			Bangle = atan(abs(b - yy)/abs(a - xx));
			Bangle = (Bangle*360)/(2*M_PI);
			Sangle = atan(opposite/hypotenuse);
			Sangle = ((Sangle *360)/ (2*M_PI));
		
			for(int i=0; i < line-1; i++){
				if(q1[i].isObscure(Bangle, Sangle)){
					isVisible = false;
					i = line;
				}
				else
					isVisible = true;
			}
			if(isVisible){
				count = count +1;
			}

			q1.push_back(Angle(Bangle, Sangle));//add to qi add every tree to q 
			
			if(a == line && b == 1){
			line = line++;
			b = line;
			a = 1;
			}
			else if(a < b){
				a = a ++;
			}
			else if(b <a){
			b = b-1;
			}
			else if (a == b){
			b = b-1;
			}
		}
	}
	
	return count;
}

int main(){
	bool stillInput = true;
	double diameter, x, y;
	
	if(diameter == 0
		&& x == 0 && y == 0){
		stillInput = false;
	}

while(stillInput){
	cin >> diameter >> x >> y;
	
	if(diameter == 0
		&& x == 0 && y == 0){
		stillInput = false;
	}
	else;
	cout << check(diameter, x ,y);
}
}