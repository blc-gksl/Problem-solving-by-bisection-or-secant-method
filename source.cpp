#include<iostream>
#include<string> //using string library to read lines and find n value of matrix in reading file
#include<cmath> 
using namespace std;

class MYclass{
	private:
	int n;
	double liv,hiv,tolerance;
	double *storagevector;
    public:
    // take the private(here could be protected too) value by Matrix constructor
    MYclass (int x,double y,double z,double t,double *u) : n(x), liv(y),hiv(z),tolerance(t),storagevector(u) {};
    // line 15 to 26 find the value of ordinat by getting apsis' value (Number), in f(x)=y form ,place x find y
    double findvalue(double Number){
	double result=0;
	for(int i=n-1;i>-1;i--){
	 double value=1.0;
		for(int j=i;j>0;j--){
			value*=Number;
		}
		value*=storagevector[n-i-1];
		result+=value;
	}
	return result;
	}
//	line 28 to 55 bisection method
	double bisection(){
// in almost all function to get the real value of liv and hiv first create some variables()liv2 and liv3 here
		double liv2=liv;
		double hiv2=hiv;
		double midpoint2 = (liv2 + hiv2)/2; // form midpoint that used in bisection method
		double midpointresult2 = findvalue(midpoint2);
		double livresult2 = findvalue(liv2);
		double hivresult2 = findvalue(hiv2);
		int count2=1; //because first iteration is done count start from 1 instead of zero
		while(abs(midpointresult2)>tolerance){ //iterate function to get result that close enough to the idel result
		// 
			if((livresult2>0 && midpointresult2<0) || (livresult2<0 && midpointresult2>0)){
			hiv2 = midpoint2; //if midpoint result and hiv result have the same sign update hiv with midpoint,
			                  //in other situation change update liv with midpoint
			}
			else liv2 = midpoint2;
		midpoint2 = (liv2 + hiv2)/2;
		midpointresult2 = findvalue(midpoint2);
		livresult2 = findvalue(liv2);
		hivresult2 = findvalue(hiv2);
		count2++;
		if(count2>16){
	    	break;
		}
		
	}
	return midpoint2;
}
    // line 57 to 80 the same functon (bisection method) as above but that return iteration number of the method
	int bisectioniteration(){
		double liv3=liv;
		double hiv3=hiv;
		double midpoint3 = (liv3 + hiv3)/2;
		double midpointresult3 = findvalue(midpoint3);
		double livresult3 = findvalue(liv3);
		double hivresult3 = findvalue(hiv3);
		int count = 1;
		while(abs(midpointresult3)>tolerance){
			if((livresult3>0 && midpointresult3<0) || (livresult3<0 && midpointresult3>0)){
			hiv3 = midpoint3;
			}
			else liv3 = midpoint3;
		midpoint3 = (liv3 + hiv3)/2;
		midpointresult3 = findvalue(midpoint3);
		livresult3 = findvalue(liv3);
		hivresult3 = findvalue(hiv3);
	    count++;
	    if(count>16){
	    	break;
		}
	}
	return count;
}
   // line 82 to 103 secant method
    double secant(){
   	double liv4=liv;//again first assign some variables instead of liv and hiv
	double hiv4=hiv;
	double livresult4 = findvalue(liv4);
	double hivresult4 = findvalue(hiv4);
   	double root = (liv4 * hivresult4 - hiv4*livresult4) /(hivresult4 - livresult4);//secant method equation
   	double rootresult = findvalue(root);
   	int count4 = 1;
   	while(abs(rootresult)>tolerance){ // get the value that closest to desired value
   		liv4=hiv4;
   		hiv4=root;
   		livresult4 = findvalue(liv4);
	    hivresult4 = findvalue(hiv4);
   	    root = (liv4 * hivresult4 - hiv4*livresult4) /(hivresult4 - livresult4);// make secant calculations
   	    rootresult = findvalue(root);
		count4++;
	    if(count4>16){
	    	break;
		}	
	   }
   	return root; //return the root
}
// line 105 to 126  the same functon (secant method) as above but that return iteration number of the method
   int secantiteration(){
   	double liv5=liv;
	double hiv5=hiv;
	double livresult5 = findvalue(liv5);
	double hivresult5 = findvalue(hiv5);
   	double root2 = (liv5 * hivresult5 - hiv5*livresult5) /(hivresult5 - livresult5);
   	double rootresult2 = findvalue(root2);
   	int count3 = 1;
   	while(abs(rootresult2)>tolerance){
   		liv5=hiv5;
   		hiv5=root2;
   		livresult5 = findvalue(liv5);
	    hivresult5 = findvalue(hiv5);
   	    root2 = (liv5 * hivresult5 - hiv5*livresult5) /(hivresult5 - livresult5);
   	    rootresult2 = findvalue(root2);
		count3++;
	    if(count3>16){
	    	break;
		}	
	   }
   	return count3;
}
// line 128 to 164 hybrid method
	double hybrid(){
 	    double liv6=liv;//again assign some variables instead of liv and hiv because liv and hiv will be used again
		double hiv6=hiv;
		double midpoint6 = (liv6 + hiv6)/2;
		double midpointresult6 = findvalue(midpoint6);
		double livresult6 = findvalue(liv6);
		double hivresult6 = findvalue(hiv6);
		int count6=1;
		while(abs(midpointresult6)>tolerance){
			if((livresult6>0 && midpointresult6<0) || (livresult6<0 && midpointresult6>0)){
			hiv6 = midpoint6;
			}
			else liv6 = midpoint6;
		midpoint6 = (liv6 + hiv6)/2;
		midpointresult6 = findvalue(midpoint6);
		livresult6 = findvalue(liv6);
		hivresult6 = findvalue(hiv6);
		count6++;
		if(count6==2){ // for the first two iterations bisection method is used (line 136 to 148)
	    	break;
}  }
    double root6=midpoint6; //line 149 and 150 change value of result of bisection method with correponding vaalues in secant method
    double rootresult6=midpointresult6;
    while(abs(rootresult6)>tolerance){
   		liv6=hiv6;
   		hiv6=root6;
   		livresult6 = findvalue(liv6);
	    hivresult6 = findvalue(hiv6);
   	    root6 = (liv6 * hivresult6 - hiv6*livresult6) /(hivresult6 - livresult6);
   	    rootresult6 = findvalue(root6);
		count6++;
	    if(count6>16){ // for the other iterations secant method is used (line 151 to 162)
	    	break;
		}	
	   }
	   return root6;
}
// line 166 to 202  the same functon (hybrid method) as above but that return iteration number of the method
int hybriditeration(){
 	    double liv6=liv;
		double hiv6=hiv;
		double midpoint6 = (liv6 + hiv6)/2;
		double midpointresult6 = findvalue(midpoint6);
		double livresult6 = findvalue(liv6);
		double hivresult6 = findvalue(hiv6);
		int count6=1;
		while(abs(midpointresult6)>tolerance){
			if((livresult6>0 && midpointresult6<0) || (livresult6<0 && midpointresult6>0)){
			hiv6 = midpoint6;
			}
			else liv6 = midpoint6;
		midpoint6 = (liv6 + hiv6)/2;
		midpointresult6 = findvalue(midpoint6);
		livresult6 = findvalue(liv6);
		hivresult6 = findvalue(hiv6);
		count6++;
		if(count6==2){
	    	break;
}  }
    double root6=midpoint6;
    double rootresult6=midpointresult6;
    while(abs(rootresult6)>tolerance){
   		liv6=hiv6;
   		hiv6=root6;
   		livresult6 = findvalue(liv6);
	    hivresult6 = findvalue(hiv6);
   	    root6 = (liv6 * hivresult6 - hiv6*livresult6) /(hivresult6 - livresult6);
   	    rootresult6 = findvalue(root6);
		count6++;
	    if(count6>16){
	    	break;
		}	
	   }
	   return count6;
}
};

int main(int argc, char *argv[]){
   //First check if there are needed number of inputs
  if(argc<6){
   cout<<"ERROR type 1: Not enough command line arguments"<<endl; // check if there are enough input
   return 0;   
}
  else{
// assign lover initial value,higher initial value, tolerance,coefficients(for coefficients a dynamic array is used)
   double liv = atof(argv[1]);
   double hiv = atof(argv[2]);
   double tolerance = atof(argv[3]);
   int n =argc;
   n-=4;
   double *storagevector =new double[n] ;
   for(int i=0;i<n;i++){
   	//used atof function from <cmath> library to assign coefficients into proper places
   	storagevector[i]= atof(argv[i+4]); 
   }
   //using first and second to find what if lower and higher initial values give different sign outputs
   double first,second;
   MYclass class1(n,liv,hiv,tolerance,storagevector); //form the main class
   first  = class1.findvalue(liv);
   second = class1.findvalue(hiv);
   
   // beginning bisection
   cout<<"Bisection Method:"<<endl;
   if(first*second<0){ //check initial values' outputs for bisection method
   	int maincount = class1.bisectioniteration(); // decide iteration numbers
   	if(maincount<16){
   	double mainresult = class1.bisection();
   	  cout<<"The root : "<<mainresult<<endl;
	  cout<<"Number of iteration required for the method to converge : "<<maincount<<endl;  	
}
  else{
  	// Error type 3 and type 2 show what if there is a problem with iteration number or initial guesses' output
   	cout<<"ERROR type 3: The number of iterations exceeded the threshold."<<endl;
   } }
   else{
   	cout<<"ERROR type 2: Sign of initial guesses are the same"<<endl;
   }
   // finish bisection
   cout<<endl;
   // Start secant
   cout<<"Secant Method:"<<endl;
   	int maincount2 = class1.secantiteration(); // decide iteration numbers
   	if(maincount2<16){
   	double mainresult2 = class1.secant();
   	  cout<<"The root : "<<mainresult2<<endl;
	  cout<<"Number of iteration required for the method to converge : "<<maincount2<<endl;  	
}
  else{
   	cout<<"ERROR type 3: The number of iterations exceeded the threshold."<<endl;
   }
   // finish secant
   cout<<endl;
   //start hybrid
   cout<<"Hybrid Method:"<<endl;
   if(first*second<0){  //due to using bisection method check if initial guesses have different sign
   	int maincount3 = class1.hybriditeration(); //decide number of iteration and set a threshold
   	if(maincount3<16){
   	double mainresult3 = class1.hybrid();
   	  cout<<"The root : "<<mainresult3<<endl;
	  cout<<"Number of iteration required for the method to converge : "<<maincount3<<endl;  	
}
  else{
   	cout<<"ERROR type 3: The number of iterations exceeded the threshold."<<endl;
   } }
   else{
   	cout<<"ERROR type 2: Sign of initial guesses are the same"<<endl;
   }
   //finish hybrid
   delete[] storagevector;  // deteling dynamic memory
}
    return 0;
}
