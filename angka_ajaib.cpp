#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <stdlib.h>
using namespace std;

main(){
	string line;
	bool state1, state2;
	int number_of_lines = 0;
    ifstream myfile("input.txt");
    while (myfile.good ())
	{
        getline(myfile, line);
        if (line=="")
        {
            cout << "Number of lines "<<number_of_lines<<endl;
            number_of_lines=0;
        }
        else 
        {
            ++number_of_lines;
        }
        
        if(number_of_lines>1){
        	exit(0);
        	
        	ofstream myfile("output.txt");
			while(myfile.is_open()){
				myfile<<"error";
				myfile.close();	
			}
		}
		else{
			state1=true;
		}
        
	}
	
	if(state1==true){
		int N, i, formula, subn1, subn2;
		
		ifstream myfile("input.txt");
		if(myfile.is_open()){
		while (getline(myfile,line)){
			
			state2 = (line.find_first_not_of( "0123456789" ) == string::npos);

			if(state2==true){
				
				N=atoi(line.data());
			
				if(N>=0&&N<=10000){
					i=100;
				}
				else if(N>10000&&N<=100000){
					i=1000;
				}
				else if(N>100000&&N<=1000000){
					i=10000;
				}
				else if(N>1000000&&N<=10000000){
					i=100000;
				}
				else if(N>10000000&&N<=100000000){
					i=1000000;
				}
				else if(N>100000000&&N<=1000000000){
					i=10000000;
				}
				else if(N>1000000000&&N<=10000000000){
					i=100000000;
				}
				
				formula=(((N/i)+(N%i))*((N/i)+(N%i)));
			
				if(formula==N){
				
					subn1=(N/i);
					subn2=(N%i);
				
					//convert int to string
					string subn1convert;
					ostringstream convertsubn1;	
					convertsubn1 << subn1;	
					subn1convert = convertsubn1.str();
				
					string subn2convert;
					ostringstream convertsubn2;	
					convertsubn2 << subn2;	
					subn2convert = convertsubn2.str();
					
					int Nlen=line.length();
					int subn1len=subn1convert.length();
					int subn2len=subn2convert.length();
					string check1,check2;
	
					check1.append(subn1convert);
					check1.append(subn2convert);

					string afterzero;
					
					if(line!=check1){
						afterzero.append(line,subn1len,(Nlen-subn1len-subn2len));
						afterzero.append(subn2convert);

						if(subn1convert.length()%2==0){
							if(afterzero.length()%2==0){
							cout<<subn1convert<<", "<<"dan "<<afterzero;
							
							ofstream myfile("output.txt");
							
							if(myfile.is_open()){
								myfile<<subn1convert<<", "<<"dan "<<afterzero;
								myfile.close();
							}
							}
						else{
							cout<<"Tidak dapat menulis";
						}
						}
						
					}
					else{
						if(subn1convert.length()%2==0){
							if(subn2convert.length()%2==0){
							cout<<subn1convert<<", "<<"dan "<<subn2convert;
							
							ofstream myfile("output.txt");
							
							if(myfile.is_open()){
								myfile<<subn1convert<<", "<<"dan "<<subn2convert;
								myfile.close();
							}
							}
						else{
							cout<<"Tidak dapat menulis";
						}
						}
					}
									
				}
				else{
					cout<<"Bukan angka ajaib!";
				}
			}
			else{
				ofstream myfile("output.txt");
				while(myfile.is_open()){
					myfile<<"error";
					myfile.close();					
				}
			}
			
		}
		}
	}
	
}
