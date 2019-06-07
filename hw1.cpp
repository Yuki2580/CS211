/**********
Yuki Tagawa
CS211
hw1
Designing a Directory of Restaurant
*******/

//Library
#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

//Defining Struct
struct Restaurant
{
  string name;         //restaurant name
  string address;      //restaurant street name
  string city;         //restaurant city
  string state;        //restaurant state
  int zipcode;         //restaurant zip code
  string type;         //type of food served
  string website;      //restaurant website
  float rating;        //restaurant rating, a number from 1 to 5
  int reviewers;       //number of reviewers
};


//prototype
void addListing(vector<Restaurant> &, const string, const string, const string, const string, const int, const string, const string);
void displayAll(const vector<Restaurant>);
void rate(vector<Restaurant> &, const string, const float);
bool removeData(vector<Restaurant> &, const string);
void findByName(const vector<Restaurant>, const string);
void findByCriteria(const vector<Restaurant>, const string, const string);
void findTopRated(const vector<Restaurant>, const string);


int main()
{
  int y=0;
  float n;
  string x, name2, name3, name4, name5, city2, city3, city4, address2, state2, type2, type3, website2;
  int zipcode2; 
  vector<Restaurant> restaurants;
  ifstream inputFile;

  inputFile.open("RestaurantsTrans.txt");
  while(inputFile>>x)                //Loop for finding each command
    {
      if(x=="AddListing")            //case of AddListing
	{
	  inputFile>>name2>>address2>>city2>>state2>>zipcode2>>type2>>website2;
	  addListing(restaurants, name2, address2, city2, state2, zipcode2, type2, website2);
	}  
      else if(x=="DisplayAll")       //case of DisplayAll
	{
	  displayAll(restaurants);         //call function
	}
      else if(x=="Rate")             //case of Rate
	{
	  inputFile>>name3>>n;
	  rate(restaurants, name3, n);     // call function
	}
      else if(x=="FindByName")       //case of FindByName
	{
	  inputFile>>name5;
	  cout<<"FindByName " <<name5<<endl;
	  findByName(restaurants, name5);           //call function
	}
      else if(x=="RemoveListing")    //case of RemoveListing
	{
	  inputFile>>name4;
	  if(!(removeData(restaurants, name4)))      //call function
	    {
	      cout<<"RemoveListing "<<name4<<endl;
	      cout<<"No such restaurant exists"<<endl<<endl;
	    }
	}
      else if(x=="FindByCriteria")   //case of FindByCriteria
	{
	  inputFile>>type3>>city3;
          cout<<"FindByCriteria "<<type3<<" "<<city3<<endl;
	  findByCriteria(restaurants, type3, city3);     //call function
	}
      else if(x=="FindTopRated")     //case of FindTopRated
	{
	  inputFile>>city4;
	  cout<<"FindTopRated "<<city4<<endl;
	  findTopRated(restaurants, city4);    //call function
	}
    }
  inputFile.close();
  
  return 0;
}


//header

void addListing(vector<Restaurant> &s, const string name2, const string address2, const string city2, const string state2, const int zipcode2, const string type2, const string website2)
{
  Restaurant temp;
  temp.name=name2;
  temp.address=address2;
  temp.city=city2;
  temp.state=state2;
  temp.zipcode=zipcode2;
  temp.type=type2;
  temp.website=website2;
  s.push_back(temp);
}
  

void displayAll(const vector<Restaurant> s)
{
  cout << "Restauraunt" << setw(10) << "City" << setw(13) << "Type" << setw(13) << "Rating" << setw(11) << "Reviewers" <<endl;
  cout<<"-------------------------------------------------------------"<<endl;

  //adjusting the look of table
  for(int i=0, t=0, p=0, o=0, l=0; i<s.size(); i++)
    {
      p=s[i].name.size()-6;
      t=s[i].city.size()-7;
      o=s[i].type.size()-7;
      if(p==1&&t==-2)     //this statement for "Joe's"
	{
	  cout<<s[i].name<<setw(18-p+t+2)<<s[i].city<<setw(13+o-t)<<s[i].type<<setprecision(2)<<fixed<<setw(8-o)<<s[i].rating<<setw(8)<<s[i].reviewers<<endl;
	}
      else
	{
	  cout<<s[i].name<<setw(18-p+t)<<s[i].city<<setw(13+o-t)<<s[i].type<<setprecision(2)<<fixed<<setw(8-o)<<s[i].rating<<setw(8)<<s[i].reviewers<<endl;
	}
      t=0;
      p=0;
    }
  cout<<endl;
}


void rate(vector <Restaurant> &e, const string p, const float a)
{
  bool target;
  float sum;
  
  //checking invalid or valid for rating 
  if(a>0&&a<6)
    {
      for(int x=0; x<e.size(); x++)
	{
	  if(p==e[x].name)
	    {
	      sum=e[x].rating*e[x].reviewers;
	      sum+=a;
	      e[x].reviewers+=1;
	      e[x].rating=sum/e[x].reviewers;
	      target=true;
	      break;
	    }
	  else
	    target=false;
	}
    }
  else if(a<=0 || a>=6) //rating shoud be from 1 to 5
    {
      cout<<"Rate "<<p<<" "<<a<<endl;
      cout << "Rating should be a number from 1 to 5"<<endl<<endl;
    }
  if(target==false&&a>0&&a<6) //not finding restaurant
    {
      cout<<"Rate "<<p<<" "<<a<<endl;
      cout << "The restaurant is not in the list"<<endl<<endl;
    }
}

bool removeData(vector <Restaurant> &e, const string g)
{
  bool target;
  for(int i=0; i<e.size(); i++)
    {
      if(g==e[i].name) //searching the restaurant then delete
	{
	  e.erase(e.begin()+i);
	  target = true;
	  return target;
	}
      else 
	target=false;
    }
  return target;
    
}


void findByName(const vector<Restaurant> q, const string h)
{
  int p=0;
  int o;
  for(int i=0; i<q.size(); i++)  //searching restaurants by their name
    {
      o=q[i].name.find(h, 0);
      if(o!=-1)
      {
	p++;
	cout<<q[i].name<<", "<<q[i].type<<endl;
	cout<<q[i].address<<", "<<q[i].city<<", "<<q[i].state<<", "<<q[i].zipcode<<endl;
	cout<<q[i].website<<endl;
	cout<<"rating: "<<q[i].rating<<" ("<<q[i].reviewers<<" reviews)"<<endl<<endl;
      }
    }
  if(p==0)
    {
      cout<<"There is no restaurants"<<endl<<endl;
    }
}  
      
void findByCriteria(const vector<Restaurant> q, const string b, const string d)
{
  int p=0;
  int o;
  int u;
  for(int i=0; i<q.size(); i++)  //seaching by the criteria
    {
      o=q[i].type.find(b, 0);
      u=q[i].city.find(d, 0);
      if(u==0 && o==0)
	{
	  p++;
	  cout<<q[i].name<<", "<<endl;
	  cout<<q[i].address<<", "<<q[i].city<<", "<<q[i].state<<", "<<q[i].zipcode<<endl;
	  cout<<q[i].website<<endl;
	  cout<<"rating: "<<q[i].rating<<" ("<<q[i].reviewers<<" reviews)"<<endl<<endl;
       	}
    }
  if(p==0)
    {
      cout <<"There is no restaurants"<<endl<<endl;;
    }
}


void findTopRated(const vector<Restaurant> q, const string r)
{
  int u;
  int y=0;
  int z=-1;
  for(int i=0; i<q.size(); i++)   //searching by top rating
    {
      u=q[i].city.find(r, 0);
      if(u==0)
        {
	  if(y<q[i].rating)
	    {
	      z=i;
	      y=q[i].rating;
	    }
        }
      	 
    }
  if(z>=0)
    {
      cout<<q[z].name<<" "<<q[z].type<<endl;
      cout<<q[z].address<<", "<<q[z].city<<" "<<q[z].state<<" "<<q[z].zipcode<<endl;
      cout<<q[z].website<<endl;
      cout<<"rating: "<<q[z].rating<<" ("<<q[z].reviewers<<" reviews)"<<endl<<endl;
    }
  else
    {
      cout<<"There is no restaurants"<<endl<<endl;
    }

}
