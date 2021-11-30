#include<iostream>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<utility>
using namespace std;
typedef long long ll;

ll omellete(ll &egg){
    ll stu =  egg/2;
	egg = egg%2;
	return stu;
}
ll shake(ll &bar){
    ll stu =  bar/3;
	bar = bar%3;
	return stu;
}
ll cake(ll &egg, ll &bar){
    ll stu =  min(egg,bar);
	egg -= stu;
	bar -= stu;
	return stu;
}
int main() {
	// your code goes here
	ll t; cin>>t;
	while(t--)
	{
	    ll egg,bar,n,p1,p2,p3,price=0,x;
	    cin>>n>>egg>>bar>>p1>>p2>>p3;
		ll temp=n;
	    multimap<int, char>m;
	    m.insert(pair<int, char> (p1,'o'));
		m.insert(pair<int, char> (p2,'s'));
	    m.insert(pair<int, char> (p3,'c'));
	    for(auto itr=m.begin(); itr !=m.end(); itr++)
	    {
	        if(temp>0){
	        if(itr->second=='o' && egg>=2){
				x = omellete(egg);
				temp -= x;
				if(temp==0){
					price += x*(itr->first);
					break;
				}
				else if(temp<0){
					price += n*(itr->first);
					break;
				}
				else
				  price += x*(itr->first);
				  n = temp;
			}
			else if(itr->second=='s' && bar>=3){
				x = shake(bar);
				temp -= x;
				if(temp==0){
					price += x*(itr->first);
					break;
				}
				else if(temp<0){
					price += n*(itr->first);
					break;
				}
				else
				  price += x*(itr->first);
				  n = temp;
			}
			else if(itr->second=='c' && (egg>=1 && bar>=1)){
				x = cake(egg,bar);
				temp -= x;
				if(temp==0){
					price += x*(itr->first);
					break;
				}
				else if(temp<0){
					price += n*(itr->first);
					break;
				}
				else
				  price += x*(itr->first);
				  n = temp;
			}
		
	    }
		}
		if(!temp <= 0){
			cout<<"-1"<<endl;
		}
		else  
		  cout<<price<<endl;
	    
	
	}
	return 0;
}
