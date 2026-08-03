#include<iostream>
using namespace std ;
int main()
{
	int fiveth,thousand,fivehnd,hundred,fifty,twenty,ten,one,amount,total_amount;
	cout<<"Enter the amount = ";
	cin>>amount;
	total_amount=amount;
	fiveth=amount/5000;
	amount=amount%5000;
	thousand=amount/1000;
	amount=amount%1000;
	fivehnd=amount/500;
	amount=amount%500;
	hundred=amount/100;
	amount=amount%100;
	fifty=amount/50;
	amount=amount%50;
	twenty=amount/20;
	amount=amount%20;
	ten=amount/10;
	amount=amount%10;
	one=amount/1;
	amount=amount%1;
	cout<< "the total amount is="  <<total_amount <<" \n Five thousand = "<<fiveth<<" \n thousand = "<<thousand<<" \n five hundred ="<<fivehnd<<" \n hundred = "<<hundred<<"\n fifty ="<<fifty
	<<" \n fifty ="<<fifty<<" \n twenty ="<<twenty<<" \n ten ="<<ten<<" \n one ="<<one;
	      return 0;
	
	
	

	return 0; 
}
