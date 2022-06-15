/* CPSC 1620 - 2022.01 - Assignment 1
   Chandra shekar suryadevara
 */

#include <iostream>
using namespace std;

int main() 

{
  int cents,toonics,loonics,quarters,dimes,nickels;
  int t,l,q,d,n,round;
  cout << "Enter an amount in cents ";
  cin >> cents;
  round=((cents + 5/2) / 5) * 5;
  if (round>=1)
    cout << round << " cents:" << endl;
  toonics=200 ;

  
  t=round%200;
  loonics=100 ;
  l=t%100;
  quarters=25 ;
  q=l%25;
  dimes = 10;
  d=q%10;
  nickels =5 ;
  n=d%5;
  
  if (round/toonics==1 )
   cout << round/toonics << " toonie"<< endl;
   else if (round/toonics>1)
   cout << round/toonics << " toonies"<< endl;

    if (t/loonics==1)
     cout << t/loonics << " loonie"<< endl;
     else if (t/loonics>1)
     cout << t/loonics << " lonnies"<< endl;

   if (l/quarters==1)
     cout << l/quarters << " quarter" << endl;
     else if (l/quarters>1)
     cout << l/quarters <<" quarters" <<endl;

 if (q/dimes==1)
   cout << q/dimes << " dime" <<endl;
   else if( q/dimes>1)
   cout << q/dimes << " dimes" << endl;


if (d/nickels==1)
cout << d/nickels << " nickel" << endl;
else if (d/nickels>1)
   cout << d/nickels << " nickels" << endl;

if (round == 0)  
cout <<"No change.";

 








  return 0;
}